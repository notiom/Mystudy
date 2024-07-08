using System;
namespace Drived
{
    class Enemy
    {
        protected int hp;
        protected int speed;

        public void AI()
        {
            Console.WriteLine("AI");
        }

        public virtual void Move()
        {
            Console.WriteLine("Move");
        }

        public void Notice()
        {
            Console.WriteLine("Notice");
        }
    }
}
