using System;

namespace prority
{
    class Customer
    {
        private string name;
        private string address;
        private int age;
        // private string createTime;

        //属性
        public int Age
        {
            get
            {
                return age;
            }
            set // value参数
            {
                age = value;
            }
        }

        public string Name
        {
            get
            {
                return name;
            }
            set
            {
                name = value;
            }
        }

        public string Address
        {
            //可以简写
            get;set;
        }

        public string CreateTime
        {
            // 可以简写
            // 属性可以不用定义
            get;set;
        }

    }
}
