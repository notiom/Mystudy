// 委托可用于协同开发
// 在程序中预留好位置之后补齐功能
using System;
using System.Collections;

namespace Program
{
    class Program
    {
        //委托，预留出未开发的位置
        delegate void OnDeiDelegate();

        static void play(OnDeiDelegate onDie) 
        {
            Console.WriteLine("开始游戏!");
            Console.WriteLine("做任务!");
            Console.WriteLine("玩家战斗!");
            Console.WriteLine("玩家死亡!");
            if(onDie != null) onDie();
        }

        //正在开发的功能
        static void ShowDieUI()
        {
            Console.WriteLine("Game Over!");
            Console.WriteLine("返回主菜单!");
        }

        static void Main(string[] args)
        {
            // 定义委托并赋值
            play(null);
        }
    }
}
