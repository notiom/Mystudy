import argparse
import sys
sys.path.append('/home/yanxiaole/Aigc/SyncTalk')
from ui.ui_main import myui

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--port", type=int, default=8460) 
    parser.add_argument("--server", type=str, default='0.0.0.0') 
    args = parser.parse_args()
    myui(server = args.server,port = args.port)