using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TankGame.Properties;

namespace TankGame
{
	internal class EnemyTank : Movething
	{
		private int attackSpeed = 60;
		private Random r = new Random();
		private int CountChange = 0; // 每60帧主动改变一次方向
		public EnemyTank(int x, int y, int speed, List<Bitmap> bmp,Direction dir = Direction.Down)
		{
			// 传递数组时必须传入上下左右图像的照片
			IsMoving = true;
			this.X = x;
			this.Y = y;
			this.Speed = speed;
			this.Dir = dir;
			BitmapUp = bmp[0];
			BitmapDown = bmp[1];
			BitmapLeft = bmp[2];
			BitmapRight = bmp[3];
		}

		public override void Update()
		{
			// 重写父类方法后如果还想用，需要base
			// 移动检查,看是否有超出边界或者碰撞
			CountChange++;
			MoveCheck();
			if (CountChange == 60)
			{
				ChangeDircetion();
				CountChange = 0;
			}
			Move();
			if(attackSpeed % 30 == 0)
			{
				Attack();
				attackSpeed = 0;
			}
			attackSpeed++;
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
					// 撞墙就改变方向
					ChangeDircetion();
					return;
				}
			}
			else if (Dir == Direction.Down)
			{
				if (Y + Speed + Height > 450)
				{
					ChangeDircetion();
					return;
				}
			}
			else if (Dir == Direction.Left)
			{
				if (X - Speed < 0)
				{
					ChangeDircetion();
					return;
				}
			}
			else if (Dir == Direction.Right)
			{
				if (X + Speed + Width > 450)
				{
					ChangeDircetion();
					return;
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
				ChangeDircetion();
				return;
			}
			if (GameObjectManager.IsCollidedSteel(rect) != null)
			{
				ChangeDircetion();
				return;
			}
			if (GameObjectManager.boss != null && GameObjectManager.IsCollidedBoss(rect))
			{
				ChangeDircetion();
				return;
			}
			#endregion
		}

		private void ChangeDircetion()
		{
			Dir = (Direction)r.Next(0, 4);
			MoveCheck();
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

		private void Attack()
		{
			int x = this.X;
			int y = this.Y;

			switch (Dir)
			{
				case Direction.Up:
					y -= Height;
					x += Width / 2 - Resources.BulletDown.Width / 2; // 对子弹的长度做矫正
					break;
				case Direction.Down:
					y += Height;
					x += Width / 2 - Resources.BulletDown.Width / 2;
					break;
				case Direction.Left:
					x -= Width;
					y += Height / 2 - Resources.BulletDown.Height / 2;
					break;
				case Direction.Right:
					x += Width;
					y += Height / 2 - Resources.BulletDown.Height / 2;
					break;
			}
			GameObjectManager.CreateBullet(x, y, TankBullet.EnemyTank, Dir);
		}
	}
}
