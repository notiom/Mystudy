using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Security.AccessControl;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using TankGame.Properties;

namespace TankGame
{
	public partial class Form1 : Form
	{
		private Thread t;
		private static Graphics windowG;
		private static Bitmap tempBmp;
		public Form1()
		{
			InitializeComponent();
			this.StartPosition = FormStartPosition.CenterScreen;

			// 阻塞
			// 普通方法只能通过对象来调用，但是静态方法可以通过类调用
			// 线程只能使用静态方法
			windowG = CreateGraphics();

			// 临时的画布
			tempBmp = new Bitmap(450, 450);
			Graphics bmpG = Graphics.FromImage(tempBmp);
			GameFrameWork.g = bmpG;
			t = new Thread(new ThreadStart(GameMainThread));
			t.Start();
		}

		private static void GameMainThread()
		{
			// GameFrameWork

			GameFrameWork.Start();
			int timeSleep = 1000 / 60;
			while(true)
			{
				GameFrameWork.g.Clear(Color.Black);
				GameFrameWork.Update();

				windowG.DrawImage(tempBmp, 0, 0);
				Thread.Sleep(timeSleep);
			}


		}

		private void Form1_Paint(object sender, PaintEventArgs e)
		{
			#region 怎么绘制线和字符串以及图像
			/*
			Graphics g = this.CreateGraphics();

			Pen p = new Pen(Color.Black);
			g.DrawLine(p, new Point(0, 0), new Point(100, 100));
			g.DrawString("www.baidu.com",
				new Font("Arial", 20),
				new SolidBrush(Color.Blue),
				new Point(200,200));
			Image image = Resources.Boss;	

			g.DrawImage(image, new Point(200,200));

			Bitmap bm = Resources.Star1;
			bm.MakeTransparent(Color.Black);

			g.DrawImage(bm, 150, 150);
			*/
			#endregion

		}

		private void Form1_FormClosed(object sender, FormClosedEventArgs e)
		{
			t.Abort();
		}

		private void Form1_KeyDown(object sender, KeyEventArgs e)
		{
			GameObjectManager.KeyDown(e);
		}

		private void Form1_KeyUp(object sender, KeyEventArgs e)
		{
			GameObjectManager.KeyUp(e);
		}
	}
}

