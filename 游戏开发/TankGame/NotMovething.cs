using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TankGame
{
	internal class NotMovething : GameObject
	{
		private Image img;
		public Image Img 
		{ 
			get
			{
				return img;
			} 
			set
			{
				img = value;
				Width = img.Width;
				Height = img.Height;
			}
		}
		public NotMovething(int x,int y, Image img)
		{
			this.Img = img;
			this.X = x;
			this.Y = y;

		}

		protected override Image GetImage()
		{
			return Img;
		}


	}
}
