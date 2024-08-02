using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TankGame.Properties;

namespace TankGame
{
	enum TankBullet
	{ 
		// 枚举类型判断是谁发出的子弹
		MyTank,
		EnemyTank
	}
	internal class Bullet : Movething
	{
		public TankBullet Tag { get; set; }
		public bool IsDestory { get; set; }
		public Bullet(int x, int y, int speed,TankBullet tag,Direction dir = Direction.Up)
		{
			IsDestory = false;
			IsMoving = true;
			this.Speed = speed;
			this.Dir = dir;
			this.Tag = tag;
			BitmapDown = Resources.BulletDown;
			BitmapUp = Resources.BulletUp;
			BitmapRight = Resources.BulletRight;
			BitmapLeft = Resources.BulletLeft;
			this.X = x;
			this.Y = y;
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
			// 子弹的移动不需要预判，只有真正的超出或者碰撞才要移除
			#region
			if (Dir == Direction.Up)
			{
				if (Y < 0)
				{
					// 撞墙就销毁子弹
					IsDestory = true;
					return;
				}
			}
			else if (Dir == Direction.Down)
			{
				if (Y > 450)
				{
					IsDestory = true;
					return;
				}
			}
			else if (Dir == Direction.Left)
			{
				if (X < 0)
				{
					IsDestory = true;
					return;
				}
			}
			else if (Dir == Direction.Right)
			{
				if (X > 450)
				{
					IsDestory = true;
					return;
				}
			}
			#endregion
			// 检查有没有和其他元素发生碰撞
			// 这个位置应该是未来的位置而不是当前的位置
			#region
			Rectangle rect = GetRectangle();
			rect.X = X + Width / 2 - 1; // 因为x的坐标应该是在左上角，判断碰撞应该是判断中心位置
			rect.Y = Y + Height / 2 - 1;
			rect.Height = 2;
			rect.Width = 2;
			// 计算爆炸中心点的位置
			int xExplosion = this.X + Width / 2;
			int yExplosion = this.Y + Height / 2;
			NotMovething wall = null;
			if ((wall = GameObjectManager.IsCollidedWall(rect)) != null)
			{
				SoundManager.PlayBlast();
				IsDestory = true;
				GameObjectManager.DestoryWall(wall);
				GameObjectManager.createExplosion(xExplosion,yExplosion);
				return;
			}
			if (GameObjectManager.IsCollidedSteel(rect) != null)
			{
				IsDestory = true;
				GameObjectManager.createExplosion(xExplosion, yExplosion);
				return;
			}
			if (GameObjectManager.boss != null && (GameObjectManager.IsCollidedBoss(rect)))
			{
				SoundManager.PlayBlast();
				IsDestory = true;
				GameObjectManager.createExplosion(xExplosion, yExplosion);
				// 销毁boss
				  GameObjectManager.boss = null;
				return;
			}

			if(Tag == TankBullet.MyTank)
			{
				EnemyTank tank = null;
				// 如果是我们的子弹
				if((tank = GameObjectManager.IsCollidedEnemyTank(rect)) != null)
				{
					IsDestory = true;
					SoundManager.PlayBlast();
					GameObjectManager.KillEnemyTankCount++;
					GameObjectManager.createExplosion(xExplosion, yExplosion);
					GameObjectManager.DestoryEnemyTank(tank);
					return;
				}
			}
			else if(Tag == TankBullet.EnemyTank)
			{
				MyTank tank = null;
				// 如果是敌人的子弹
				if (!GameObjectManager.myTankIsDestory && (tank = GameObjectManager.IsCollidedMyTank(rect)) != null)
				{
					SoundManager.PlayHit();
					IsDestory = true;
					GameObjectManager.createExplosion(xExplosion, yExplosion);
					GameObjectManager.DestoryMyTank(tank);
					return;
				}
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
	}
}
