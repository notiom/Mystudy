using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using TankGame.Properties;

namespace TankGame
{
	internal class MyTank : Movething
	{
		public bool IsDestory { get; set; }
		public int Hp {  get; set; }

		public MyTank(int x,int y,int speed,Direction dir = Direction.Up)
		{
			IsMoving = false;
			this.X = x;
			this.Y = y;
			this.Speed = speed;
			this.Dir = dir;
			BitmapDown = Resources.MyTankDown;
			BitmapUp = Resources.MyTankUp;
			BitmapRight = Resources.MyTankRight;
			BitmapLeft = Resources.MyTankLeft;
			IsDestory = false;
			Hp = 5;
		}
		public override void Update()
		{
			// 重写父类方法后如果还想用，需要base
			// 移动检查,看是否有超出边界或者碰撞
			MoveCheck();
			Move();
			base.Update();
		}
		internal void MoveCheck()
		{
			// 检查有没有超出窗体边界
			#region
			if (Dir == Direction.Up)
			{
				if (Y - Speed < 0)
				{
					IsMoving = false; return;
				}
			}
			else if (Dir == Direction.Down)
			{
				if (Y + Speed + Height > 450)
				{
					IsMoving = false; return;
				}
			}
			else if (Dir == Direction.Left)
			{
				if (X - Speed < 0)
				{
					IsMoving = false; return;
				}
			}
			else if (Dir == Direction.Right)
			{
				if (X + Speed + Width > 450)
				{
					IsMoving = false; return;
				}
			}
			#endregion
			// 检查有没有和其他元素发生碰撞
			// 这个位置应该是未来的位置而不是当前的位置
			#region
			Rectangle rect = GetRectangle();
			switch (Dir)
			{
				case Direction.Up:
					rect.Y -= Speed;
					break;
				case Direction.Down:
					rect.Y += Speed;
					break;
				case Direction.Left:
					rect.X -= Speed;
					break;
				case Direction.Right:
					rect.X += Speed;
					break;
			}
			if (GameObjectManager.IsCollidedWall(rect) != null)
			{
				IsMoving = false;
				return;
			}
			if (GameObjectManager.IsCollidedSteel(rect) != null)
			{
				IsMoving = false;
				return;
			}
			if (GameObjectManager.boss != null && GameObjectManager.IsCollidedBoss(rect))
			{
				IsMoving = false;
				return;
			}
			#endregion
		}

		private void Move()
		{
			if (IsMoving == false) return;
			switch (Dir)
			{
				case Direction.Up:
					Y -= Speed;
					break;
				case Direction.Down:
					Y += Speed;
					break;
				case Direction.Left:
					X -= Speed;
					break;
				case Direction.Right:
					X += Speed;
					break;
			}
		}

		public void KeyDown(KeyEventArgs args)
		{
			// 消息中间站
			// 多线程资源共享解决方案
			switch(args.KeyCode)
			{
				case Keys.W:
					Dir = Direction.Up;
					IsMoving = true;
					break;
				case Keys.S:
					Dir = Direction.Down;
					IsMoving = true;
					break;
				case Keys.A:
					Dir = Direction.Left;
					IsMoving = true;
					break;
				case Keys.D:
					Dir = Direction.Right;
					IsMoving = true;
					break;
				case Keys.Space:
					// 发射子弹
					Attack();
					break;
			}
		}
		private void Attack()
		{
			SoundManager.PlayFire();
			int x = this.X;
			int y = this.Y;

			switch (Dir)
			{
				case Direction.Up:
					// y -= Height;
					y -= Height / 2 - Resources.BulletDown.Height / 2;
					x += Width / 2 - Resources.BulletDown.Width / 2; // 对子弹的长度做矫正
					break;
				case Direction.Down:
					// y += Height;
					y += Height / 2 - Resources.BulletDown.Height / 2;
					x += Width / 2 - Resources.BulletDown.Width / 2;
					break;
				case Direction.Left:
					// x -= Width;
					x -= Width / 2 - Resources.BulletDown.Width / 2;
					y += Height / 2 - Resources.BulletDown.Height / 2;
					break;
				case Direction.Right:
					// x += Width;
					x += Width / 2 - Resources.BulletDown.Width / 2;
					y += Height / 2 - Resources.BulletDown.Height / 2;
					break;
			}
			GameObjectManager.CreateBullet(x,y,TankBullet.MyTank,Dir);
		}

		public void KeyUp(KeyEventArgs args)
		{
			// 消息中间站
			switch (args.KeyCode)
			{
				case Keys.W:
					IsMoving = false;
					break;
				case Keys.S:
					IsMoving = false;
					break;
				case Keys.A:
					IsMoving = false;
					break;
				case Keys.D:
					IsMoving = false;
					break;
			}
		}
	}
}
