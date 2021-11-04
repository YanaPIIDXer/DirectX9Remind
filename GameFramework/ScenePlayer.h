#ifndef SCENEPLAYER_H
#define SCENEPLAYER_H

#include <memory>

class Scene;

// シーン再生クラス
class ScenePlayer
{
public:

	// コンストラクタ
	ScenePlayer(Scene* pInitialScene);

	// デストラクタ
	~ScenePlayer();

	// 更新
	void Update();

	// 描画
	void Render();

private:
	// 現在のシーン
	std::shared_ptr<Scene> pCurrentScene;

	// 以前のシーン
	// Scene::Update()内でシーンを切り替えた時、
	// 関数実行中のシーンインスタンスが解体されるのを防ぐ為のもの
	std::shared_ptr<Scene> pPrevScene;
};

#endif		// #ifndef SCENEPLAYER_H
