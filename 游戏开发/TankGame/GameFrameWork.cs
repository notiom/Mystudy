using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TankGame
{
	enum GameState
	{
		Running,
		GameOver
	}
	internal class GameFrameWork
	{
		public static Graphics g;
		private static GameState gamestate = GameState.Running;
		public static void Start()
		{
			SoundManager.InitSound();
			GameObjectManager.Start();
			GameObjectManager.CreateMap();
			GameObjectManager.createMyTank();
			SoundManager.PlayStart();
		}

		public static void Update()
		{
			// FPS
			if(gamestate == GameState.Running) 
			{
				GameObjectManager.Update();
			}
			else if(gamestate == GameState.GameOver)
			{
				GameOverUpdate();
			}
		}

		public static void ChangeToGameOver()
		{
			gamestate = GameState.GameOver;
			SoundManager.PlayStart();
		}

		private static void GameOverUpdate()
		{
			Properties.Resources.GameOver.MakeTransparent(Color.Black);
			int x = 450 / 2 - Properties.Resources.GameOver.Width / 2;
			int y = 450 / 2 - Properties.Resources.GameOver.Height / 2;
			g.DrawImage(Properties.Resources.GameOver,x,y);
		}

	}
}
