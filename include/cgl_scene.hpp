#pragma once

namespace cgl {
	class Scene {
	public:
		Scene();
		void OnLoad();
		void OnUnload();
	};
	class SceneManager {
		Scene* currentScene = nullptr;
	public:
		template<typename T>
		void SetScene(T* newScene) {
			if (currentScene) currentScene->OnUnload();
			currentScene = newScene;
			if (currentScene) currentScene->OnLoad();
		}

		Scene* Current() { return currentScene; }
	};
}