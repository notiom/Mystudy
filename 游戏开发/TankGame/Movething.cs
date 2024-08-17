using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TankGame
{
	enum Direction
	{
		Up,
		Down,
		Left,
		Right
	}
	internal class Movething : GameObject
	{
		private Object _lock = new object();
		public Bitmap BitmapUp {  get; set; }
		public Bitmap BitmapDown { get; set; }
		public Bitmap BitmapLeft { get; set; }
		public Bitmap BitmapRight { get; set; }

		public bool IsMoving { get; set; }
		public int Speed { get; set; }

		public Direction Dir { get; set; }

		protected override Image GetImage()
		{
			Bitmap bitmap = null;
			switch (Dir)
			{
				case Direction.Up:
					bitmap = BitmapUp;
					break;
				case Direction.Down:
					bitmap = BitmapDown;
					break;
				case Direction.Left:
					bitmap = BitmapLeft;
					break;
				case Direction.Right:
					bitmap = BitmapRight;
					break;
			}
			lock (_lock)
			{
				Width = bitmap.Width;
				Height = bitmap.Height;
				bitmap.MakeTransparent(Color.Black);
				return bitmap;
			}
		}

		public override void DrawSelf()
		{
			lock (_lock)
			{
				base.DrawSelf();
			}
		}
	}
}
