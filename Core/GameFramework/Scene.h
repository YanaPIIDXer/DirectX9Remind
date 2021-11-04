#ifndef SCENE_H
#define SCENE_H

// シーンクラス
class Scene
{
public:

	// コンストラクタ
	Scene();

	// デストラクタ
	virtual ~Scene() = 0;

	// 次のシーンが存在するか？
	bool HasNextScene() const { return (pNextScene != nullptr); }
	
	// 次のシーンを回収
	Scene* SweepNextScene()
	{
		Scene* pScene = pNextScene;
		pNextScene = nullptr;
		return pScene;
	}

protected:

	// 次のシーンをセット
	void setNextScene(Scene* pScene);

private:

	// 次のシーン
	Scene* pNextScene;


	// 次のシーンを解放
	void releaseNextScene();
};

#endif		// #ifndef SCENE_H
