using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TankGame.Properties;

namespace TankGame
{
	internal class Explosion : GameObject
	{
		public bool IsDestory { get; set; }
		private int playSpeed = 2; // 每2帧播放一次
		private int playCount = -1;
		int index = 0;
		private Bitmap[] bitArray = new Bitmap[]
		{
			Resources.EXP1,
			Resources.EXP2,
			Resources.EXP3,
			Resources.EXP4,
			Resources.EXP5
		};
		public Explosion(int x,int y)
		{
			foreach (Bitmap bmp in bitArray)
			{ 
				bmp.MakeTransparent(Color.Black);
			}
			this.X = x - bitArray[0].Width / 2; // 设置图片的x，y坐标
			this.Y = y - bitArray[0].Height / 2;
			IsDestory = false;
		}
		protected override Image GetImage()
		{

			return bitArray[index];
		}

		public override void Update() 
		{
			playCount++;
			index = playCount / playSpeed; 
			if (playCount == (playSpeed * 5) - 1) IsDestory = true; // 在要爆炸的前一帧将其销毁
			base.Update();
		}
	}
}
