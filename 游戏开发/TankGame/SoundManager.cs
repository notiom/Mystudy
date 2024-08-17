using System;
using System.Collections.Generic;
using System.Linq;
using System.Media;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using TankGame.Properties;

namespace TankGame
{
	internal class SoundManager
	{
		private static SoundPlayer startPlayer = new SoundPlayer();
		private static SoundPlayer addPlayer = new SoundPlayer();
		private static SoundPlayer blastPlayer = new SoundPlayer();
		private static SoundPlayer firePlayer = new SoundPlayer();
		private static SoundPlayer hitPlayer = new SoundPlayer();

		public static void InitSound()
		{
			startPlayer.Stream = Resources.start;
			addPlayer.Stream = Resources.add;
			blastPlayer.Stream = Resources.blast;
			firePlayer.Stream = Resources.fire;
			hitPlayer.Stream = Resources.hit;
		}

		public static void PlayStart()
		{
			Thread start = new Thread(new ParameterizedThreadStart(Play));
			start.Start(startPlayer);
		}

		public static void PlayAdd()
		{
			Thread add = new Thread(new ParameterizedThreadStart(Play));
			add.Start(addPlayer);
		}

		public static void PlayBlast()
		{
			Thread blast = new Thread(new ParameterizedThreadStart(Play));
			blast.Start(blastPlayer);
		}

		public static void PlayFire()
		{
			Thread fire = new Thread(new ParameterizedThreadStart(Play));
			fire.Start(firePlayer);
		}

		public static void PlayHit()
		{
			Thread hit = new Thread(new ParameterizedThreadStart(Play));
			hit.Start(hitPlayer);
		}


		private static void Play(object player)
		{
			SoundPlayer soundPlayer = player as SoundPlayer;
			soundPlayer?.Play();
		}
	}
}
