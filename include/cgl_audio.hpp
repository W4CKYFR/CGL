#include <iostream>
#include "miniaudio.h"

namespace cgl {
	class Audio {
	public:
		Audio();
		~Audio();

		bool isReady() const;

	private:
		bool ready = false;
	};

	class Sound {
	public:
		Sound(const std::string& file);
		~Sound();
		void Play();
		void SetVolume(float volume);
		void SetPitch(float pitch);
	private:
		ma_sound sound;
	};

	class Music {
	public:
		Music(const std::string& file);
		~Music();
		void Play();
		void Stop();
		void SetVolume(float volume);
		void SetPitch(float pitch);
		void SetLooping(bool IsLooping);
	private:
		ma_sound music;
	};

}