#pragma once

class GameNode;

class SceneManager : public SingletonBase<SceneManager>
{
private:
	static GameNode* currentScene;

	map<string, GameNode*> sceneList;

public:
	void Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	GameNode* AddScene(string sceneName, GameNode* scene);

	void ChangeScene(string sceneName);

};