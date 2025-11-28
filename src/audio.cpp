#include "cgl.hpp"
#include <iostream>
#include <AL/al.h>
#include <AL/alc.h>
#include <vorbis/vorbisfile.h>

namespace cgl {
	Audio::Audio() {
		device = alcOpenDevice(nullptr);
		if (!device) return;

		context = alcCreateContext(device, nullptr);
		if (!context) {
			alcCloseDevice(device);
			return;
		}

		alcMakeContextCurrent(context);
		ready = true;
	}

	Audio::~Audio() {
		if (context) alcDestroyContext(context);
		if (device) alcCloseDevice(device);
	}

	bool Audio::isReady() const {
		return ready;
	}

	Sound::Sound(const std::string& file) {
		alGenBuffers(1, &buffer);

		const int bufferSize = 16384;
		std::vector<char> pcmBuffer(bufferSize);

		OggVorbis_File oggFile;
		if (ov_fopen(file.c_str(), &oggFile) < 0) {
			std::cerr << "OGG file not found or doesn't exist." << std::endl;
			return;
		}

		vorbis_info* info = ov_info(&oggFile, -1);
		int channels = info->channels;
		int sampleRate = info->rate;

		std::vector<short> pcmData;
		int bitstream;
		long samplesRead;

		do {
			samplesRead = ov_read(&oggFile, pcmBuffer.data(), bufferSize, 0, 2, 1, &bitstream);
			if (samplesRead > 0) {
				pcmData.insert(pcmData.end(),
					reinterpret_cast<short*>(pcmBuffer.data()),
					reinterpret_cast<short*>(pcmBuffer.data()) + samplesRead / 2);
			}
		} while (samplesRead > 0);

		ALenum format = (channels == 1) ? AL_FORMAT_MONO16 : AL_FORMAT_STEREO16;
		alBufferData(buffer, format, pcmData.data(), pcmData.size() * sizeof(short), sampleRate);

		alGenSources(1, &source);
		alSourcei(source, AL_BUFFER, buffer);

		ov_clear(&oggFile);
	}

	Sound::~Sound() {
		alSourceStop(source);
		alDeleteBuffers(1, &buffer);
		alDeleteSources(1, &source);
	}

	void Sound::Play() {
		alSourcePlay(source);
	}

	void Sound::SetVolume(ALfloat volume) {
		alSourcef(source, AL_GAIN, volume);
	}

	void Sound::SetPitch(ALfloat pitch) {
		alSourcef(source, AL_PITCH, pitch);
	}

	ALfloat Sound::GetVolume() const{
		ALfloat volume = 0.0f;
		alGetSourcef(source, AL_GAIN, &volume);
		return volume;
	}

	ALfloat Sound::GetPitch() const {
		ALfloat pitch = 0.0f;
		alGetSourcef(source, AL_PITCH, &pitch);
		return pitch;
	}


}