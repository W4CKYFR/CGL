#include <iostream>
#include <vector>
#include <AL/al.h>
#include <AL/alc.h>

namespace cgl {
	class Audio {
	public:
		Audio();
		~Audio();

		bool isReady() const;

	private:
		ALCdevice* device = nullptr;
		ALCcontext* context = nullptr;
		bool ready = false;
	};

	class Sound {
	public:
		Sound(const std::string& file);
		~Sound();
		void Play();
		void SetVolume(ALfloat volume);
		void SetPitch(ALfloat pitch);
		ALfloat GetVolume() const;
		ALfloat GetPitch() const;
	private:
		ALuint buffer = 0;
		ALuint source = 0;
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
		ALuint source = 0;
	};

}
