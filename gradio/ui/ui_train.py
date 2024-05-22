import os, sys
sys.path.append('/home/yanxiaole/Aigc/SyncTalk')
import argparse
import gradio as gr
from nerf_triplane.provider import NeRFDataset
from nerf_triplane.utils import *
from nerf_triplane.network import NeRFNetwork
from ui.ui_infer import dict_to_attrdict
try:
    torch.backends.cuda.matmul.allow_tf32 = False
    torch.backends.cudnn.allow_tf32 = False
except AttributeError as e:
    print('Info. This pytorch version is not support with tf32.')

class MyTrainer(object):
    def __init__(self):
        self.device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
        self.metrics = [PSNRMeter(), LPIPSMeter(device=self.device), LMDMeter(backend='fan')]
        self.opt = {
            'path': None,
            'O': False,  
            'test': False,
            'test_train': False,
            'data_range': [0, -1],
            'workspace': 'workspace',
            'seed': 0,
            'iters': 0,
            'lr': 1e-2,
            'lr_net': 1e-3,
            'ckpt': 'latest',
            'num_rays': 4096 * 16,
            'cuda_ray': False,
            'max_steps': 16,
            'num_steps': 16,
            'upsample_steps': 0,
            'update_extra_interval': 16,
            'max_ray_batch': 4096,   #### -------------原来值为4096
            'warmup_step': 10000,
            'amb_aud_loss': 1,
            'amb_eye_loss': 1,
            'unc_loss': 1,
            'lambda_amb': 1e-4,
            'fp16': False,
            'bg_img': '',
            'fbg': False,
            'exp_eye': False,
            'fix_eye': -1,
            'smooth_eye': False,
            'torso_shrink': 0.8,
            'color_space': 'srgb',
            'preload': 0,
            'bound': 1,
            'scale': 4,
            'offset': [0, 0, 0],
            'dt_gamma': 1/256,
            'min_near': 0.05,
            'density_thresh': 10,
            'density_thresh_torso': 0.01,
            'patch_size': 1,
            'init_lips': False,
            'finetune_lips': False,
            'smooth_lips': False,
            'torso': False,
            'head_ckpt': '',
            'gui': False,
            'W': 450,
            'H': 450,
            'radius': 3.35,
            'fovy': 21.24,
            'max_spp': 1,
            'att': 2,
            'aud': '',
            'emb': False,
            'ind_dim': 4,
            'ind_num': 20000,
            'ind_dim_torso': 8,
            'amb_dim': 2,
            'part': False,
            'part2': False,
            'train_camera': False,
            'smooth_path': False,
            'smooth_path_window': 7,
            'asr': False,
            'asr_wav': '',
            'asr_play': False,
            'asr_model': 'deepspeech',
            'asr_save_feats': False,
            'fps': 50,
            'l': 10,
            'm': 50,
            'r': 10,
            'bs_area': 'upper',
            'portrait': False,
            'au45': False,
            'pyramid_loss':0,
            'torso': False
            }
        
        self.keys = [
                    'path',
                    'workspace',
                    'head_ckpt',
                    'train_model',
                    'asr_model',
                    'seed',
                    'bs_area',
                    'O',
                    'cuda_ray',
                    'finetune_lips',
                    'portrait',
                    'torso',    
                    'test',
                    'test_train',                 
                    'smooth_path',
                    'smooth_eye',
                    'smooth_lips',
                    'au45',
                    'iters',
                    'lr',
                    'lr_net',
                    'warmup_step',
                    'ind_dim_torso',
                    'pyramid_loss',
                    'lambda_amb',
                    'patch_size',
                    'fps',
                    'max_steps'
                    ]
        self.result_path = None  #工作空间的结果
        self.output_path = None  #最终结果
    def grinit(self, *args):
        info = ""
        print(f"args {args}")
        try: # 去运行
            for key_index in range(len(self.keys)):
                self.opt[self.keys[key_index]] = args[key_index]
                
            if(isinstance(self.opt['path'],str) is False):
                self.opt['path'] = self.opt['path'][0]
                    
            if(self.opt['path'] == None or os.path.exists(self.opt['path']) is False):
                #说明路径不存在，报错
                print(f"找不到输入数据集路径 {self.opt['path']}")
                raise FileNotFoundError
                
            if(isinstance(self.opt['workspace'],str) is False):
                self.opt['workspace'] = self.opt['workspace'][0]
                    
            if(self.opt['workspace'] == None or os.path.exists(self.opt['workspace']) is False):
                #说明路径不存在，报错
                print(f"找不到工作空间路径 {self.opt['workspace']}")
                raise FileNotFoundError
            # 判断训练模式
            if(self.opt['train_model'] == 0):
                self.opt['finetune_lips'] = False
                self.opt['patch_size'] = 1
                self.opt['torso'] = False
                self.opt['head_ckpt'] = ''
            elif(self.opt['train_model'] == 1):
                self.opt['finetune_lips'] = True
                self.opt['patch_size'] = self.opt['patch_size'] if self.opt['patch_size'] !=1 else 32
                self.opt['torso'] = False
                self.opt['head_ckpt'] = ''
            else:
                self.opt['finetune_lips'] = False
                self.opt['patch_size'] = 1
                self.opt['torso'] = True
                if(self.opt['head_ckpt'] == ''):
                    # 在这种模式下必须要传入头部训练权重
                    raise FileNotFoundError
            del self.opt['train_model']                        
            self.opt = dict_to_attrdict(self.opt)
            try:
                self.run()                   
            except Exception as e:
                # 运行推理错误
                content = f"{e}"
                info = f"Inference ERROR: {content}"
        except Exception as e:
            if info == "": 
                # 网页ui错误
                content = f"{e}"
                info = f"WebUI ERROR: {content}"
        
        # output part
        if len(info) > 0 :
            # errors    
            print(info)
            info_gr = gr.update(visible=True, value=info)
        else: 
            # no errors
            info_gr = gr.update(visible=False, value=info)
        
        return info_gr
    
    def run(self):
        opt = self.opt
        if opt.O:
            opt.fp16 = True
            opt.exp_eye = True

        opt.cuda_ray = True
        # assert opt.cuda_ray, "Only support CUDA ray mode."

        if opt.patch_size > 1:
            # assert opt.patch_size > 16, "patch_size should > 16 to run LPIPS loss."
            assert opt.num_rays % (opt.patch_size ** 2) == 0, "patch_size ** 2 should be dividable by num_rays."
        
        # if opt.finetune_lips:
        #     # do not update density grid in finetune stage
        #     opt.update_extra_interval = 1e9
        
        print(opt)
        
        seed_everything(opt.seed)

        device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')

        model = NeRFNetwork(opt)

        # manually load state dict for head
        if opt.torso and opt.head_ckpt != '':
            
            model_dict = torch.load(opt.head_ckpt, map_location='cpu')['model']

            missing_keys, unexpected_keys = model.load_state_dict(model_dict, strict=False)

            if len(missing_keys) > 0:
                print(f"[WARN] missing keys: {missing_keys}")
            if len(unexpected_keys) > 0:
                print(f"[WARN] unexpected keys: {unexpected_keys}")   

            # freeze these keys
            for k, v in model.named_parameters():
                if k in model_dict:
                    print(f'[INFO] freeze {k}, {v.shape}')
                    v.requires_grad = False

        
        # print(model)

        # criterion = torch.nn.MSELoss(reduction='none')
        criterion = torch.nn.L1Loss(reduction='none')


        if opt.test:
            
            if opt.gui:
                metrics = [] # use no metric in GUI for faster initialization...
            else:
                # metrics = [PSNRMeter(), LPIPSMeter(device=device)]
                metrics = [PSNRMeter(), LPIPSMeter(device=device), LMDMeter(backend='fan')]

            trainer = Trainer('ngp', opt, model, device=device, workspace=opt.workspace, criterion=criterion, fp16=opt.fp16, metrics=metrics, use_checkpoint=opt.ckpt)

            if opt.test_train:
                test_set = NeRFDataset(opt, device=device, type='train')
                # a manual fix to test on the training dataset
                test_set.training = False 
                test_set.num_rays = -1
                test_loader = test_set.dataloader()
            else:
                test_loader = NeRFDataset(opt, device=device, type='test').dataloader()


            # temp fix: for update_extra_states
            model.aud_features = test_loader._data.auds
            model.eye_areas = test_loader._data.eye_area

            if opt.gui:
                from nerf_triplane.gui import NeRFGUI
                # we still need test_loader to provide audio features for testing.
                with NeRFGUI(opt, trainer, test_loader) as gui:
                    gui.render()

            else:
                ### test and save video (fast)  
                trainer.test(test_loader)

                ### evaluate metrics (slow)
                if test_loader.has_gt:
                    trainer.evaluate(test_loader)



        else:

            optimizer = lambda model: torch.optim.AdamW(model.get_params(opt.lr, opt.lr_net), betas=(0, 0.99), eps=1e-8)

            train_loader = NeRFDataset(opt, device=device, type='train').dataloader()

            assert len(train_loader) < opt.ind_num, f"[ERROR] dataset too many frames: {len(train_loader)}, please increase --ind_num to this number!"

            # temp fix: for update_extra_states
            model.aud_features = train_loader._data.auds
            model.eye_area = train_loader._data.eye_area
            model.poses = train_loader._data.poses

            # decay to 0.1 * init_lr at last iter step
            if opt.finetune_lips:
                scheduler = lambda optimizer: optim.lr_scheduler.LambdaLR(optimizer, lambda iter: 0.05 ** (iter / opt.iters))
            else:
                scheduler = lambda optimizer: optim.lr_scheduler.LambdaLR(optimizer, lambda iter: 0.5 ** (iter / opt.iters))

            metrics = [PSNRMeter(), LPIPSMeter(device=device),LMDMeter(backend='fan')]

            eval_interval = max(1, int(5000 / len(train_loader)))
            trainer = Trainer('ngp', opt, model, device=device, workspace=opt.workspace, optimizer=optimizer, criterion=criterion, ema_decay=0.95, fp16=opt.fp16, lr_scheduler=scheduler, scheduler_update_every_step=True, metrics=metrics, use_checkpoint=opt.ckpt, eval_interval=eval_interval)
            with open(os.path.join(opt.workspace, 'opt.txt'), 'a') as f:
                f.write(str(opt))
            if opt.gui:
                with NeRFGUI(opt, trainer, train_loader) as gui:
                    gui.render()
            
            else:
                valid_loader = NeRFDataset(opt, device=device, type='val', downscale=1).dataloader()

                max_epochs = np.ceil(opt.iters / len(train_loader)).astype(np.int32)
                print(f'[INFO] max_epoch = {max_epochs}')
                trainer.train(train_loader, valid_loader, max_epochs)

                # free some mem
                del train_loader, valid_loader
                torch.cuda.empty_cache()

                # also test
                test_loader = NeRFDataset(opt, device=device, type='test').dataloader()
                
                if test_loader.has_gt:
                    trainer.evaluate(test_loader) # blender has gt, so evaluate it.

                trainer.test(test_loader)
def train_model_update_checkboxes(train_model_selection, finetune_lips, torso, patch_size, portrait):
    if train_model_selection == 0:  # head
        return (False, False, 1, False)  # 所有复选框都未勾选
    elif train_model_selection == 1:  # finetune_lips
        return (True, False, 32, False)  # 只有finetune_lips勾选
    elif train_model_selection == 2:  # torso_head
        return (False, True, 1, False)  # torso 勾选
    elif train_model_selection == 3: 
        return (False, False, 1, True)
    else:
        return (finetune_lips,torso, patch_size,portrait)  # 保持当前状态

def train_goback():
    return gr.update(visible=True), gr.update(visible=False)   
def synctalk_train(tab_main,tab_train):
    '''
    ui_train
    '''
    sep_line = "-" * 40
    train_obj = MyTrainer()
    print(sep_line)
    with gr.Blocks(analytics_enabled=False) as synctalk_train:
        gr.Markdown("<div align='center'> <h2> SyncTalk: train </span> </h2> </div>")     
        # 1. 选择文件夹路径的训练参数选择
        with gr.Row():
            with gr.Column(variant='panel'):
                with gr.Tabs(elem_id="checkbox"):
                    with gr.TabItem('file path'):
                        with gr.Column(variant='panel'):
                            ckpt_info_box = gr.Textbox(value="Please select \"datasets\" and \"workspace\" under the checkpoint folder ", interactive=False, visible=True, show_label=False)                           
                            path = gr.FileExplorer(glob = "/**", ignore_glob= "/*.*",file_count='multiple', root_dir = '/home/yanxiaole/Aigc/SyncTalk/data',label='data path directory',interactive=True)
                            workspace = gr.FileExplorer(glob = "/**", ignore_glob= "/*.*", file_count='multiple',root_dir = '/home/yanxiaole/Aigc/SyncTalk/MyWorkspace', label='torso model ckpt path or directory',interactive=True)
                            head_ckpt = gr.FileExplorer(glob = "/**/**/*.pth", file_count='single',root_dir = '/home/yanxiaole/Aigc/SyncTalk/MyWorkspace', label='head model',interactive=True) 
                            # 选择训练的模式，0位头部训练, 1为嘴唇微调, 2为驱干训练, 3为头部贴回
                            train_model = gr.Radio([0, 1, 2, 3], value = 0, label='train_model', info="0 = head, 1 = finetune_lips, 2 = torso_head ,3 = portrait")
                            asr_model = gr.Radio(['deepspeech', 'hubert', "ave"], value='ave', label='asr_model', info="the method of audio extraction")
                            trainback = gr.Button('GoBack', elem_id="goback", variant='primary')
        # 2. checkbox的参数
            with gr.Column(variant='panel'): 
                with gr.Tabs(elem_id="checkbox"):
                    with gr.TabItem('Parameters Settings 1'):
                        with gr.Column(variant='panel'):
                            #--------------------------radio
                            seed = gr.Radio([0, 42, 1024],value = 42, label = "seed")
                            bs_area = gr.Radio(["upper", "eye"],value = "upper", label = "bs_area -(extra)") 
                            #--------------------------checkbox(训练核心参数)
                            Oi = gr.Checkbox(label='O', value = True, info="equals --fp16 --cuda_ray --exp_eye",interactive=False) # 不允许该值被修改  
                            cuda_ray = gr.Checkbox(label='cuda_ray *', value = False, info="use CUDA raymarching instead of pytorch") 
                            
                            # 待改变参数
                            finetune_lips = gr.Checkbox(label='finetune_lips', value = False,info="use LPIPS and landmarks to fine tune lips region")
                            portrait = gr.Checkbox(label='portrait -(extra)', value = False,info="only render face")
                            torso = gr.Checkbox(label='torso', value = False,info="fix head and train torso",interactive = True) # 训练躯干    
                            test = gr.Checkbox(label='test', value = False,info="test mode (load model and test dataset)",interactive=True) # 加入该变量等于测试模型
                            test_train = gr.Checkbox(label='test_train', value = False,info="test mode (load model and train dataset)",interactive=False) # 不允许该值被修改 
                            
                            #可以变好的参数                  
                            smooth_path = gr.Checkbox(label='smooth_path *(best)', value = False, info="brute-force smooth camera pose trajectory with a window size")
                            smooth_eye = gr.Checkbox(label='smooth_eye * ', value = False, info="smooth the eye area sequence")
                            smooth_lips = gr.Checkbox(label='smooth_lips * ', value = False, info="smooth the enc_a in a exponential decay way...(time is long long)")
                            
                            # 未测试参数
                            au45 = smooth_lips = gr.Checkbox(label='au45 -(extra)', value = False, info="use openface au45")
    
            with gr.Column(variant='compact'):
                with gr.Tabs(elem_id="checkbox"):
                    with gr.TabItem('Parameters Settings 2'):
                         with gr.Column(variant='panel'):
                            # --------------------------slider的参数（会变好的参数）
                            iters = gr.Slider(minimum=0, maximum=5e6, step=1e5, label="iters", value=1e5, info='0 - 5000000')
                            lr = gr.Slider(minimum=0, maximum=1, step=1e-3, label="lr", value=1e-2, info='0 - 1')
                            lr_net = gr.Slider(minimum=0, maximum=1, step=1e-3, label="lr_net", value=1e-3, info='0 - 1')
                            warmup_step = gr.Slider(minimum=0, maximum=1e5, step=1e3, label="warm_up", value=1e4, info='0 - 100000(warm up steps)')
                            ind_dim_torso = gr.Slider(minimum=0, maximum=64, step=8, label="ind_dim_torso", value=8, info='individual code dim, 0 to turn off')
                            pyramid_loss = gr.Slider(minimum=0, maximum=1, step=1e-3, label="pyramid_loss -(extra)", value=0, info="use perceptual loss")
                            max_steps = gr.Slider(minimum=16, maximum=80, step=16, label="max_steps *", value=16, info="max num steps sampled per ray (only valid when using --cuda_ray")
                            
                            # 测试未变好的参数
                            lambda_amb = gr.Slider(minimum=0, maximum=1, step=1e-3, label="lambda_amb", value=1e-4, info='lambda for ambient loss')
                            patch_size = gr.Slider(minimum=0, maximum=64, step=16, label="patch_size", value=1, info='[experimental] render patches in training, so as to apply LPIPS loss. 1 means disabled, use [64, 32, 16] to enable')
                            fps = gr.Slider(minimum=0, maximum=50, step=1, label="fps", value=50,interactive=True)
                            submit = gr.Button('Train', elem_id="train", variant='primary')
                            # 改变函数的返回情况
                            train_model.change(fn=train_model_update_checkboxes, inputs=[train_model, finetune_lips, torso,patch_size,portrait], outputs=[finetune_lips, torso,patch_size,portrait])
                            info_box = gr.Textbox(label="Error", interactive=False, visible=False)
               
        fn = train_obj.grinit
        trainback.click(fn = train_goback,inputs = [],outputs=[tab_main,tab_train])
        submit.click(
                    fn=fn, 
                    inputs = [
                            path,
                            workspace,
                            head_ckpt,
                            train_model,
                            asr_model,
                            seed,
                            bs_area,
                            Oi,
                            cuda_ray,
                            finetune_lips,
                            portrait,
                            torso,    
                            test,
                            test_train,                 
                            smooth_path,
                            smooth_eye,
                            smooth_lips,
                            au45,
                            iters,
                            lr,
                            lr_net,
                            warmup_step,
                            ind_dim_torso,
                            pyramid_loss,
                            lambda_amb,
                            patch_size,
                            fps,
                            max_steps
                            ],
                    outputs=[
                        info_box,
                    ],
                    )
    print(sep_line)
    print("Gradio Train page is constructed.")
    print(sep_line)
