using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Drawing;
using System.Drawing.Text;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using TankGame.Properties;

namespace TankGame
{
	internal class GameObjectManager
	{
		// notmovething
		private static List<NotMovething> walllist = new List<NotMovething>();
		private static List<NotMovething> steellist = new List<NotMovething>();
		private static List<Explosion> explist = new List<Explosion>(); // 管理爆炸效果的集合
		public static NotMovething boss;
		// movething
		private static MyTank mytank;
		private static List<EnemyTank> enemytanklist = new List<EnemyTank>();
		private static List<Bullet> bulletlist = new List<Bullet>();
		private static List<Bullet> bullettemplist = new List<Bullet>(); // 创建一个临时的bulletlist


		public static bool myTankIsDestory = false;
		private static int enemyBornSpeed = 120; //每60帧生成一个敌人
		private static int enemyBornCount = 120; //当前帧数记录

		public static int KillEnemyTankCount { get; set; } = 0; // 记录击杀的坦克
		private static Point[] points = new Point[3];
		private static List<List<int>> WallMap = new List<List<int>>
		{
			// 上
			new List<int> {1, 1, 5},
			new List<int> {3, 1, 5},
			new List<int> {5, 1, 4},
			new List<int> {7, 1, 3},
			new List<int> {9, 1, 4},
			new List<int> {11, 1, 5},
			new List<int> {13, 1, 5},
			// 中
			new List<int> {2, 7, 1},
			new List<int> {3, 7, 1},
			new List<int> {4, 7, 1},
			new List<int> {6, 7, 1},
			new List<int> {7, 6, 2},
			new List<int> {8, 7, 1},
			new List<int> {10, 7, 1},
			new List<int> {11, 7, 1},
			new List<int> {12, 7, 1},
			// 下
			new List<int> {1, 9, 5},
			new List<int> {3, 9, 5},
			new List<int> {5, 9, 3},
			new List<int> {9, 9, 3},
			new List<int> {6, 10, 1},
			new List<int> {7, 10, 2},
			new List<int> {8, 10, 1},
			// Boss
			new List<int> {11, 9, 5},
			new List<int> {13, 9, 5},
			new List<int> {6, 13, 2},
			new List<int> {8, 13, 2},
			new List<int> {7, 13, 1}
		};
		private static List<List<int>> steelMap = new List<List<int>>
		{
			new List<int> {7, 5, 1},
			new List<int> {0, 7, 1},
			new List<int> {14, 7, 1}
		};

		private static List<List<Bitmap>> enemyMap = new List<List<Bitmap>>
		{
			new List<Bitmap> {Resources.YellowUp,Resources.YellowDown, Resources.YellowLeft, Resources.YellowRight},
			new List<Bitmap> {Resources.GreenUp,Resources.GreenDown, Resources.GreenLeft,Resources.GreenRight},
			new List<Bitmap> {Resources.QuickUp,Resources.QuickDown,Resources.QuickLeft,Resources.QuickRight},
			new List<Bitmap> {Resources.SlowUp, Resources.SlowDown, Resources.SlowLeft, Resources.SlowRight}
		};

		// 初始化敌人的出生点
		public static void Start()
		{
			// 敌人固定出生在这三个位置
			// 1.
			points[0].X = 0;
			points[0].Y = 0;
			// 2.
			points[1].X =7 * 30;
			points[1].Y = 0;
			// 3.
			points[2].X = 14 * 30;
			points[2].Y = 0;
		}

		public static void Update()
		{
			foreach (NotMovething nm in walllist)
			{
				nm.Update();
			}
			foreach (NotMovething nm in steellist)
			{
				nm.Update();
			}

			foreach(EnemyTank tank in enemytanklist)
			{
				// 敌人坦克的移动
				tank.Update();
			}
			// 一定要先使集合确定，再去遍历这个集合

			DestoryBullet();

			foreach(Bullet bullet in bullettemplist)
			{
				bulletlist.Add(bullet);
			}
			bullettemplist.Clear(); // 要将列表清空的

			foreach (Bullet bullet in bulletlist)
			{
				// 子弹的移动
				bullet.Update();
			}
			// 销毁爆炸效果
			DestoryExp();
			foreach (Explosion exp in explist)
			{
				// 爆炸效果绘制
				exp.Update();
			}
			if(!myTankIsDestory)
			{
				mytank.Update();
			}
			if(boss != null)
			{
				boss.Update();
			}
			EnemyBorn();
			// 判断游戏是否结束
			isGameOver();
			// 绘制击杀坦克数量的UI
			killTankUI();
			// 绘制我方坦克的hp
			MyTankHpUI();
		}

		private static void isGameOver()
		{
			// 如果自身坦克爆炸或者（boss销毁 && 击杀50辆坦克）
			
			if(myTankIsDestory || (boss == null && KillEnemyTankCount == 10))
			{
				GameFrameWork.ChangeToGameOver();
			}
		}

		private static void killTankUI()
		{
			Graphics g = GameFrameWork.g;
			string killCountText = KillEnemyTankCount.ToString();
			killCountText = "Kill : " + killCountText;
			Font font = new Font("Arial", 10);
			Brush brush = Brushes.Red;
			g.DrawString(killCountText, font, new SolidBrush(Color.Orange), new Point(405,10));
		}

		private static void MyTankHpUI()
		{
			Graphics g = GameFrameWork.g;
			string mytankhp = mytank.Hp.ToString();
			mytankhp = "HP : " + mytankhp;
			Font font = new Font("Arial", 10);
			g.DrawString(mytankhp, font, new SolidBrush(Color.Red), new Point(10, 10));
		}

		// 生成敌人
		private static void EnemyBorn()
		{
			enemyBornCount++;
			if (enemyBornCount < enemyBornSpeed) return;
			// 生成敌人的代码
			// 播放声音
			SoundManager.PlayAdd();
			Random rd = new Random();
			int index = rd.Next(0, 3); // 生成的随机数就表示0 1 2 
			Point postion = points[index];
			int num = rd.Next(1, 5); //生成的随机数 1 2 3 4
			CreateEnemyTank(postion.X,postion.Y,num);
			enemyBornCount = 0;
		}


		// 1 - 4号坦克
		private static void CreateEnemyTank(int x,int y,int num,int speed = 2)
		{
			// num参数用来判断生成几号坦克
			if (num == 3) speed = 4; //快坦克
			else if (num == 4) speed = 1; //慢坦克
			else speed = 2;
			EnemyTank tank = new EnemyTank(x, y, speed, enemyMap[num - 1]);
			enemytanklist.Add(tank);
		}

		// 生成子弹
		public static void CreateBullet(int x,int y,TankBullet tag,Direction dir)
		{
			Bullet bullet = new Bullet(x, y, 5, tag, dir);
			bullettemplist.Add(bullet);
		}

		//销毁子弹
		private static void DestoryBullet()
		{
			List<Bullet> needToDestory = new List<Bullet>();
			foreach(Bullet bullet in bulletlist)
			{
				if(bullet.IsDestory == true)
				{
					needToDestory.Add(bullet);
				}
			}

			foreach(Bullet bullet in needToDestory)
			{
				bulletlist.Remove(bullet);
			}
		}
		// 销毁爆炸效果
		private static void DestoryExp()
		{
			List<Explosion> needToDestory = new List<Explosion>();
			foreach (Explosion exp in explist)
			{
				if (exp.IsDestory == true)
				{
					needToDestory.Add(exp);
				}
			}
			foreach (Explosion exp in needToDestory)
			{
				explist.Remove(exp);
			}
		}

		public static void DestoryWall(NotMovething wall)
		{
			// 由于销毁的位置是在子弹的循环里面，所以不会发生冲突
			walllist.Remove(wall);
		}
		// 销毁敌人的坦克
		public static void DestoryEnemyTank(EnemyTank tank)
		{
			enemytanklist.Remove(tank);
		}
		// 检查我们的坦克是否应该被销毁
		public static void DestoryMyTank(MyTank tank)
		{
			tank.Hp--;
			if(tank.Hp == 0)
			{
				myTankIsDestory = true;
				mytank = null;
				// createMyTank();
				// myTankIsDestory = false;
			}
		}

		// 是否和敌人的坦克发生碰撞
		public static EnemyTank IsCollidedEnemyTank(Rectangle rt)
		{
			foreach(EnemyTank enemytank in enemytanklist)
			{
				if(enemytank.GetRectangle().IntersectsWith(rt))
				{
					return enemytank;
				}
			}
			return null;
		}
		// 是否和我的坦克发生碰撞
		public static MyTank IsCollidedMyTank(Rectangle rt)
		{

			if (mytank.GetRectangle().IntersectsWith(rt))
			{
				return mytank;
			}
			return null;
		}


		// 是否与墙体发生碰撞
		public static NotMovething IsCollidedWall(Rectangle rt)
		{
			foreach (NotMovething wall in walllist)
			{
				if (wall.GetRectangle().IntersectsWith(rt))
				{
					// 是否传入的物体和墙体发生了碰撞
					// 发生碰撞就把墙返回
					return wall;
				}
			}
			return null;
		}

		// 是否与钢铁发生碰撞
		public static NotMovething IsCollidedSteel(Rectangle rt)
		{
			foreach (NotMovething wall in steellist)
			{
				if (wall.GetRectangle().IntersectsWith(rt))
				{
					// 是否传入的物体和墙体发生了碰撞
					// 发生碰撞就把墙返回
					return wall;
				}
			}
			return null;
		}

		// 是否与boss发生碰撞
		public static bool IsCollidedBoss(Rectangle rt)
		{
			return boss.GetRectangle().IntersectsWith(rt);
		}

		public static void CreateMap()
		{
			// 创建红墙
			foreach (var item in WallMap)
			{
				createWall(item[0], item[1], item[2], Resources.wall, walllist);
			}
			// 创建钢铁墙
			foreach (var item in steelMap)
			{
				createWall(item[0], item[1], item[2], Resources.steel, steellist);
			}
			// 创建Boss
			createBoss(7, 14,Resources.Boss);
		}

		// 创建爆炸效果
		public static void createExplosion(int x,int y)
		{
			Explosion exp = new Explosion(x,y);
			explist.Add(exp);
		}
		public static void createMyTank()
		{
			int x = 5 * 30;
			int y = 14 * 30;
			int speed = 3;
			mytank = new MyTank(x, y, speed);
		}
		
		private static void createBoss(int x,int y,Image img)
		{
			int xPosition = x * 30;
			int yPosition = y * 30;
			boss = new NotMovething(xPosition, yPosition,img);
		}

		private static void createWall(int x,int y,int count, Image img,List<NotMovething> list)
		{
			// count表示从当前位置开始需要创建多少个墙
			int xPosition = x * 30;
			int yPosition = y * 30;
			for(int i = yPosition; i < yPosition + count * 30; i+=15)
			{
				// 创建出来两个位置
				// i XPosition i xPosition + 15
				NotMovething wall1 = new NotMovething(xPosition,i,img);
				NotMovething wall2 = new NotMovething(xPosition + 15, i, img);
				list.Add(wall1);
				list.Add(wall2);
			}
		}

		public static void KeyDown(KeyEventArgs args)
		{
			// 消息中间站
			// 如果坦克被销毁就不用调用回调函数了
			if (myTankIsDestory) return;
			mytank.KeyDown(args);
		}

		public static void KeyUp(KeyEventArgs args)
		{
			// 消息中间站
			if (myTankIsDestory) return;
			mytank.KeyUp(args);
		}
	}
}
