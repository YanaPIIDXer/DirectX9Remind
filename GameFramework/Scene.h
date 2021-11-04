#ifndef SCENE_H
#define SCENE_H

#include <vector>

class Actor;

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

	// シーン開始
	virtual void BeginScene() = 0;

	// 更新
	void Update(LPDIRECT3DDEVICE9 pDevice);

	// 描画
	void Render(LPDIRECT3DDEVICE9 pDevice);

	// 次のシーンを回収
	Scene* SweepNextScene()
	{
		Scene* pScene = pNextScene;
		pNextScene = nullptr;
		return pScene;
	}

	// アクターを登録
	void RegisterActor(Actor* pActor)
	{
		actorList.push_back(pActor);
	}

	// ライトを登録
	int RegisterLight(const D3DLIGHT9& light)
	{
		int index = lights.size();
		lights.push_back(light);
		return index;
	}

	// ライトを更新
	void UpdateLight(int index, const D3DLIGHT9& light)
	{
		lights[index] = light;
	}

protected:

	// 次のシーンをセット
	void SetNextScene(Scene* pScene);

	// 毎フレームの処理
	virtual void Tick() = 0;

private:

	// 次のシーン
	Scene* pNextScene;

	// アクターリスト
	std::vector<Actor*> actorList;

	// ライトリスト
	std::vector<D3DLIGHT9> lights;


	// 次のシーンを解放
	void releaseNextScene();
};

#endif		// #ifndef SCENE_H
