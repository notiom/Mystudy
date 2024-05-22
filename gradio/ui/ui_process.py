'''
数据预处理
'''
import sys,os
sys.path.append('/home/yanxiaole/Aigc/SyncTalk')
import gradio as gr
from scripts import cropvideo

class MyProcess(object):
    def __init__(self):
        self.result_path = None
    def grinit(self, *args):
        pass
    def run(self):
        if self.result_path is not None and len(self.result_path) > 0 and os.path.exists(self.result_path): # good output
            print(f"裁剪已完成,开始进行数据task预处理!")
            try:
                cmd = f'python data_utils/process.py ' + self.result_path
                os.system(cmd)
            except Exception as e:
                print(e)
                print(f"数据预处理失败失败!")
                raise e
        else:
            print(f"裁剪失败!")
            raise TypeError 
        print("数据处理结束!")    
    def crop_video(self,inputFile):
        self.result_path = cropvideo.process_video(inputFile)
        return self.result_path
    
        
def process_goback():
    return gr.update(visible=True), gr.update(visible=False)
def synctalk_process(tab_main, tab_process):
    sep_line = "-" * 40
    print(sep_line)
    process_obj = MyProcess()
    with gr.Blocks(analytics_enabled=False) as synctalk_process:
        gr.Markdown("<div align='center'> <h2> SyncTalk: process </span> </h2> </div>") 
        with gr.Row():
            with gr.Column(variant='panel'):
                with gr.TabItem('upload video'):
                    with gr.Column(variant='panel'):
                        #本地上传要预处理的原视频
                        video_client=gr.Video(sources="upload",label='upload video',format='mp4',interactive=True)
                        vc_button=gr.Button("本地crop_video",variant='primary') 
                with gr.Row():       
                    with gr.TabItem('server video'):
                        with gr.Column(variant='panel'):
                            #服务器上传
                            video_server=gr.FileExplorer(glob="**/*.mp4",value='',file_count='single',root_dir='/home/weiyubin/process/video/',label='load .mp4 file to train',interactive=True)
                            vs_button=gr.Button("服务器crop_video", variant='primary')       
            with gr.Column(variant='panel'):
                data_task = gr.Button('task', elem_id="task", variant='primary') 
                processback = gr.Button('GoBack',elem_id='goback',variant='primary') 
                gen_video = gr.Video(label="Generated video", format="mp4", visible=True)
                vs_button.click(process_obj.crop_video,inputs=[video_server],outputs=[gen_video],queue=True)
                #输出的视频路径与输入在同一个路径下/home/weiyubin/process/video/，名字为
                vc_button.click(process_obj.crop_video,inputs=[video_client],outputs=[gen_video],queue=True)
                data_task.click(process_obj.run)
                processback.click(fn = process_goback,inputs = [],outputs=[tab_main, tab_process])
                
    print(sep_line)
    print("Gradio Process page is constructed.")
    print(sep_line)