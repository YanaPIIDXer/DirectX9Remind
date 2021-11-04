#ifndef TEAPOTACTOR_H
#define TEAPOTACTOR_H

#include "GameFramework/Actor.h"

// ティーポットアクター
class TeapotActor : public Actor
{
public:

	// コンストラクタ
	TeapotActor(Scene* pInScene);

	// デストラクタ
	virtual ~TeapotActor();

private:
};

#endif		// #ifndef TEAPOTACTOR_H
