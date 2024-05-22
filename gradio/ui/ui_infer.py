import os, sys
sys.path.append('/home/yanxiaole/Aigc/SyncTalk')
import argparse
import gradio as gr
from nerf_triplane.provider import NeRFDataset
from nerf_triplane.utils import *
from nerf_triplane.network import NeRFNetwork

from scripts.compose import compose
try:
    torch.backends.cuda.matmul.allow_tf32 = False
    torch.backends.cudnn.allow_tf32 = False
except AttributeError as e:
    print('Info. This pytorch version is not support with tf32.')
    
class AttrDict(dict):
    def __getattr__(self, key):
        try:
            # 尝试将键转换为字符串，以支持数字键
            key = str(key) if isinstance(key, int) else key
            return self[key]
        except KeyError:
            raise AttributeError(f"'AttrDict' object has no attribute '{key}'")

    def __setattr__(self, key, value):
        # 将键转换为字符串，以支持数字键
        key = str(key) if isinstance(key, int) else key
        self[key] = value

def dict_to_attrdict(d):
    attr_dict = AttrDict()
    for key, value in d.items():
        # 将所有键转换为字符串，以支持数字键
        attr_dict[str(key)] = value
    return attr_dict

class MyPredict(object):
    def __init__(self):
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
            'torso': False,
            'is_compose': False,
            'origin_mp4': ''
            }
        
        self.keys = [
                    'aud',
                    'asr_model',
                    'O',
                    'torso',
                    'portrait',
                    'test',
                    'test_train',
                    'path',
                    'workspace',
                    'is_compose',
                    'origin_mp4'
                    ]
        self.result_path = None  #工作空间的结果
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
            
            if(self.opt['aud'] == None or os.path.exists(self.opt['aud']) is False):
                #说明路径不存在，报错
                print(f"找不到音频npy文件路径 {self.opt['aud']}")
                raise FileNotFoundError
            self.opt = dict_to_attrdict(self.opt)
            try:
                self.run()   
                pass                
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
        output_path_folder = os.path.join(self.opt.get('workspace'),'results')
        for file in os.listdir(output_path_folder):
            if 'audio' in file:
                self.result_path = os.path.join(output_path_folder, file) 
                break    
        print(self.result_path)                    
        if self.result_path is not None and len(self.result_path) > 0 and os.path.exists(self.result_path): # good output
            if(self.opt.get('is_compose')):
                print("执行头部贴回!")
                origin_mp4 = self.opt.get('origin_mp4')
                if origin_mp4 is not None and len(origin_mp4) > 0 and os.path.exists(origin_mp4): # good output
                    self.result_path = compose(origin_mp4,self.result_path)
                else:
                    print("未找到原始图片路径，无法贴回!")
            else:
                print("不执行头部贴回!")
            print(f"成功生成 {self.result_path}!")
            video_gr = gr.update(visible=True, value=self.result_path)
        else:
            print(f"生成失败!")
            video_gr = gr.update(visible=True, value=self.result_path)          
        return video_gr, info_gr
    
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
                
def infer_goback():
    return gr.update(visible=True), gr.update(visible=False)   
def synctalk_infer(tab_main,tab_infer):
    sep_line = "-" * 40
    infer_obj = MyPredict()
    print(sep_line)
    with gr.Blocks(analytics_enabled=False) as synctalk_interface:
        gr.Markdown("<div align='center'> <h2> SyncTalk: infer </span> </h2> </div>")     
        
        with gr.Row():
            with gr.Column(variant='panel'):
                with gr.Tabs(elem_id="driven_audio"):
                    with gr.TabItem('Upload audio'):
                        with gr.Column(variant='panel'):
                            #从本上传要推理的音频
                            aud = gr.FileExplorer(glob="/*.wav", file_count='single', root_dir = '/home/yanxiaole/Aigc/SyncTalk/data/test_audio/',label='load .wav file to predict',interactive=True)

                with gr.Tabs(elem_id="checkbox"):
                    with gr.TabItem('path'):
                        with gr.Column(variant='panel'):
                            ckpt_info_box = gr.Textbox(value="Please select \"datasets\" and \"workspace\" under the checkpoint folder ", interactive=False, visible=True, show_label=False)
                                         
                            path = gr.FileExplorer(glob = "/**", ignore_glob= "/*.*",file_count='multiple', root_dir = '/home/yanxiaole/Aigc/SyncTalk/data/',label='data path directory',interactive=True)
                            workspace = gr.FileExplorer(glob = "/**", ignore_glob= "/*.*", file_count='multiple',root_dir = '/home/yanxiaole/Aigc/SyncTalk/MyWorkspace/', label='torso model ckpt path or directory',interactive=True)
                            origin_mp4 = gr.FileExplorer(glob="*.mp4", file_count='single', root_dir = '/home/yanxiaole/Aigc/SyncTalk/data/',label='load origin .mp4 file to generate',interactive=True)
            with gr.Column(variant='panel'): 
                with gr.Tabs(elem_id="checkbox"):
                    with gr.TabItem('Parameters Settings'):
                        with gr.Column(variant='panel'):
                            
                            asr_model = gr.Radio(['deepspeech', 'hubert', 'ave'], value='ave', label='asr_model', info="the method of audio extraction")
                            is_compose = gr.Checkbox(value = False,label = 'is_compose',info = "Whether or not to put the head back")
                            Oi = gr.Checkbox(label='O', value = True, info="equals --fp16 --cuda_ray --exp_eye",interactive=False) # 不允许该值被修改  
                            torso = gr.Checkbox(label='torso', value = True,info="fix head and train torso",interactive=True) # 不允许该值被修改    
                            test = gr.Checkbox(label='test', value = True,info="test mode (load model and test dataset)",interactive=False) # 不允许该值被修改 
                            test_train = gr.Checkbox(label='test_train', value = True,info="test mode (load model and train dataset)",interactive=False) # 不允许该值被修改 
                            portrait = gr.Checkbox(label='portrait', value = True,info="portrait",interactive=False) # 不允许该值被修改 
                            inferback = gr.Button('GoBack', elem_id="goback", variant='primary')
                            submit = gr.Button('Generate', elem_id="generate", variant='primary')
                        with gr.Column(variant='compact'):
                            with gr.Tabs(elem_id="genearted_video"):
                                    info_box = gr.Textbox(label="Error", interactive=False, visible=False)
                                    gen_video = gr.Video(label="Generated video", format="mp4", visible=True)
               
        fn = infer_obj.grinit
        inferback.click(fn = infer_goback,inputs = [],outputs=[tab_main, tab_infer])
        submit.click(
                    fn=fn, 
                    inputs = [
                            aud,
                            asr_model,
                            Oi,
                            torso,
                            portrait,
                            test,
                            test_train,
                            path,
                            workspace,
                            is_compose,
                            origin_mp4
                            ],
                    outputs=[
                        gen_video,
                        info_box,
                    ],
                    )

    print(sep_line)
    print("Gradio Infer page is constructed.")
    print(sep_line)
