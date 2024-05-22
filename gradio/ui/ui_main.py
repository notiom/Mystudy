'''
ui_main实现的功能为tab1,主接口
'''

import os, sys
import argparse
import gradio as gr
sys.path.append('/home/yanxiaole/Aigc/SyncTalk')

from ui.ui_process import synctalk_process
from ui.ui_train import synctalk_train
from ui.ui_infer import synctalk_infer
from scripts.compose import compose

class SwitchTab:
    @staticmethod
    def switch_to_tab1():
        return gr.update(visible=False), gr.update(visible=True), gr.update(visible=False),gr.update(visible=False)
    @staticmethod
    def switch_to_tab2():
        return gr.update(visible=False), gr.update(visible=False), gr.update(visible=True),gr.update(visible=False)
    @staticmethod
    def switch_to_tab3():
        return gr.update(visible=False), gr.update(visible=False), gr.update(visible=False),gr.update(visible=True)

def one_click_generation(aud,mp4_path,cuda_idx = 0):
    info = ""
    result_path = None
    filename = mp4_path.split('/')[-1].split('.')[0] #取出文件名
    workspace = os.path.join('/home/yanxiaole/Aigc/SyncTalk/MyWorkspace/',filename)
    data_path = os.path.join('/home/yanxiaole/Aigc/SyncTalk/data/',filename)
    if(os.path.exists(workspace) == False):
        os.makedirs(workspace)
    if(os.path.exists(data_path) == False):
        os.makedirs(data_path)
        
    print('[INFO] ===== 开始生成,请耐心等待！=====')
    # 数据处理部分
    try:
        cmd_process = f'python scripts/cropvideo.py ' + mp4_path
        os.system(cmd_process)
        cmd_task = f'CUDA_VISIBLE_DEVICES={cuda_idx} python data_utils/process.py {data_path}/{filename}.mp4 --asr ave'
        os.system(cmd_task)
        print('[INFO] ===== 数据处理完成！=====')
    except Exception as e:
        print(e)
        content = f"{e}"
        info = f"Process ERROR: {content}"
        print(f'[ERROR] ===== 数据处理失败！=====')
        raise e
    # 数据训练部分
    try:
        print('[INFO] ===== 开始训练！=====')
        
        cmd_train1 = f'CUDA_VISIBLE_DEVICES={cuda_idx} python main.py {data_path} --workspace {workspace} -O --portrait --iters 60000 --asr_model ave' 
        cmd_train2 = f'CUDA_VISIBLE_DEVICES={cuda_idx} python main.py {data_path} --workspace {workspace} -O --portrait --iters 100000 --finetune_lips --patch_size 64 --asr_model ave'
        os.system(cmd_train1)
        os.system(cmd_train2)
        
        print('[INFO] ===== 训练完成!=====')
    except Exception as e:
        print(e)
        content = f"{e}"
        info = f"Train ERROR: {content}"
        print(f'[ERROR] ===== 训练失败！=====')
        raise e
    # 数据推理部分
    try:
        print('[INFO] ===== 开始推理！=====')
        cmd_infer = f'CUDA_VISIBLE_DEVICES={cuda_idx} python main.py {data_path} --workspace {workspace} -O --test --test_train --asr_model ave  --portrait --aud {aud}'
        os.system(cmd_infer)
        output_folder = os.path.join(workspace,'results')
        for file in os.listdir(output_folder):
            if 'audio' in file:
                result_path = os.path.join(output_folder, file) 
                break    
        print('[INFO] ===== 推理头部成功！=====') 
        pass
    
    except Exception as e:
        print(e)
        content = f"{e}"
        info = f"Infer ERROR: {content}"
        print(f'[ERROR] ===== 推理失败！=====')
        raise e
    
    # output part
    if len(info) > 0 :
        # errors    
        print(info)
        info_gr = gr.update(visible=True, value=info)
    else: 
        # no errors
        info_gr = gr.update(visible=False, value=info)
        
    # 头部贴回部分
    print('[INFO] ===== 开始头部贴回！=====')
    if result_path is not None and len(result_path) > 0: # good output
        if mp4_path is not None and len(mp4_path) > 0 and os.path.exists(mp4_path): # good output
            result_path = compose(mp4_path,result_path)
        else:
            print("未找到原始图片路径，无法贴回!")
                
        print(f'[INFO] ===== 生成成功！===== {result_path}!')
        video_gr = gr.update(visible=True, value=result_path)
    else:
        print(f"生成失败!")
        video_gr = gr.update(visible=True, value=result_path) 
            
    print(f'生成成功 {result_path}!')                  
    return video_gr, info_gr
                   
def myui(server = '0.0.0.0',port = 8560):
    with gr.Blocks() as demo:
        with gr.Tabs() as tabs:
            myswitch = SwitchTab()
            with gr.TabItem("main") as tab_main:
                with gr.Column(variant='panel'):
                    #从本上传要推理的音频
                    aud = gr.FileExplorer(glob="/*.wav", file_count='single', root_dir = '/home/yanxiaole/Aigc/SyncTalk/data/test_audio/',label='load .wav file to generate',interactive=True)
                    
                with gr.Column(variant='panel'):        
                    mp4_path = gr.FileExplorer(glob="*.mp4", file_count='single', root_dir = '/home/yanxiaole/Aigc/SyncTalk/data/',label='load .mp4 file to generate',interactive=True)
                    
                with gr.Row(variant='panel'): 
                    tab1_button = gr.Button("Process",elem_id="process", variant='primary')
                    tab2_button = gr.Button("Train",elem_id="train", variant='primary')
                    tab3_button = gr.Button("Infer",elem_id="infer", variant='primary')
                        
                with gr.Column(variant='panel'): 
                    generate_button = gr.Button("One-click generation",elem_id="generate", variant='primary')
                
                with gr.Column(variant='panel'): 
                    info_box = gr.Textbox(label="Error", interactive=False, visible=False)
                    gen_video = gr.Video(label="Generated video", format="mp4", visible=True)
            with gr.TabItem("process", visible= False) as tab_process:
                synctalk_process(tab_main, tab_process) # 按钮按下process时显示数据处理页面
            with gr.TabItem("train", visible = False) as tab_train:
                synctalk_train(tab_main,tab_train) # 按钮按下train时显示数据训练页面
            with gr.TabItem("infer", visible = False) as tab_infer:
                synctalk_infer(tab_main,tab_infer) # 按钮按下infer时显示数据推理页面
        
        generate_button.click(fn = one_click_generation,inputs = [aud,mp4_path],outputs = [info_box,gen_video])
        tab1_button.click(fn=myswitch.switch_to_tab1, inputs=[], outputs=[tab_main, tab_process, tab_train, tab_infer])
        tab2_button.click(fn=myswitch.switch_to_tab2, inputs=[], outputs=[tab_main, tab_process, tab_train, tab_infer])
        tab3_button.click(fn=myswitch.switch_to_tab3, inputs=[], outputs=[tab_main, tab_process, tab_train, tab_infer])

    demo.queue()
    demo.launch(server_name=server, server_port=port)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--port", type=int, default=None) 
    parser.add_argument("--server", type=str, default='0.0.0.0') 
    args = parser.parse_args()
    myui(server = args.server,port = args.port)

