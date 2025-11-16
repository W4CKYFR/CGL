#include "cgl.hpp"
#include <iostream>
#define MA_NO_ENCODING                          
#define MA_NO_WAV_ENCODE          
#define MA_NO_FLAC                
#define MA_NO_FLAC_PLUGIN         
#define MA_NO_DITHER                   
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"




namespace cgl {
	static ma_engine gEngine;

	Audio::Audio() {
		if (ma_engine_init(NULL, &gEngine) != MA_SUCCESS) {
			std::cerr << "Failed to initialize audio engine" << std::endl;
			ready = false;
		}
		else {
			ready = true;
		}
	}

	Audio::~Audio() {
		ma_engine_uninit(&gEngine);
	}

	bool Audio::isReady() const {
		return ready;
	}

	Sound::Sound(const std::string& file) {
		if (ma_sound_init_from_file(&gEngine, file.c_str(), MA_SOUND_FLAG_DECODE, NULL, NULL, &sound) != MA_SUCCESS) {
			std::cerr << "Failed to load sound: " << file << std::endl;
		}
	}

	Sound::~Sound() {
		ma_sound_uninit(&sound);
	}

	void Sound::Play() {
		ma_sound_start(&sound);
	}

	void Sound::SetVolume(float volume) {
		ma_sound_set_volume(&sound, volume);
	}

	void Sound::SetPitch(float pitch) {
		ma_sound_set_pitch(&sound, pitch);
	}

	Music::Music(const std::string& filepath) {
		if (ma_sound_init_from_file(&gEngine, filepath.c_str(), MA_SOUND_FLAG_STREAM, NULL, NULL, &music) != MA_SUCCESS) {
			std::cerr << "Failed to load music: " << filepath << std::endl;
		}
	}

	Music::~Music() {
		ma_sound_uninit(&music);
	}

	void Music::Play() {
		ma_sound_start(&music);
	}

	void Music::Stop() {
		ma_sound_stop(&music);
		ma_sound_seek_to_pcm_frame(&music, 0);
	}

	void Music::SetVolume(float volume) {
		ma_sound_set_volume(&music, volume);
	}

	void Music::SetPitch(float pitch) {
		ma_sound_set_pitch(&music, pitch);
	}

	void Music::SetLooping(bool IsLooping) {
		ma_sound_set_looping(&music, IsLooping);
	}
	
}
