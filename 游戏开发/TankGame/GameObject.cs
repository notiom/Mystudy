using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TankGame
{
	internal abstract class GameObject
	{
		public int X { get; set; }
		public int Y { get; set; }

		// 每个图片都有的高宽属性
		public int Width { get; set; }
		public int Height { get; set; }
		protected abstract Image GetImage();
		public virtual void DrawSelf()
		{
			Graphics g = GameFrameWork.g;

			g.DrawImage(GetImage(),X,Y);
		}

		public virtual void Update()
		{
			DrawSelf();
		}

		public Rectangle GetRectangle()
		{
			Rectangle rectangle = new Rectangle(X,Y,Width,Height);
			return rectangle;
		}

	}
}
