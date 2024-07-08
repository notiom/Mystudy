using System;
namespace Drived
{
    class Boss : Enemy
    {
        private int attack;
        public Boss(int attack,int hp,int speed)
        {
            this.attack = attack;
            this.hp = hp;
            this.speed = speed;
        }
        public void Skill()
        {
            Console.WriteLine("Boss Skill");
        }

        public void Print()
        {
            Console.WriteLine("HP : " + hp);
            Console.WriteLine("Speed : " + speed);
            
        }

        public override void Move()
        {
            // 重写
            Console.WriteLine("Boss Move");
        }

        public new void Notice()
        {
            // 重写
            // 使用new方法重写
            Console.WriteLine("Boss Notice");
        }
    }
}
