#ifndef ACTOR_H
#define ACTOR_H

class Scene;

// アクタークラス
class Actor
{
public:

	// コンストラクタ
	Actor(Scene* pInScene);

	// デストラクタ
	virtual ~Actor() = 0;

private:
	
	// 所属シーン
	Scene* pScene;
};

#endif		// #ifndef ACTOR_H
