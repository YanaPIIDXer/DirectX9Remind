#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "GameFramework/Scene.h"

// ゲームシーン
class GameScene : public Scene
{
public:

	// コンストラクタ
	GameScene();

	// デストラクタ
	virtual ~GameScene();

	// シーン開始
	virtual void BeginScene() override;

protected:

	// 毎フレームの処理
	virtual void Tick() override;
};

#endif		// #ifndef GAMESCENE_H
