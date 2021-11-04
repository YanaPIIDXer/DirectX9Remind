#ifndef TEAPOTCOMPONENT_H
#define TEAPOTCOMPONENT_H

#include "GameFramework/Component.h"

// ティーポット描画Component
class TeapotComponent : public Component
{
public:

	// コンストラクタ
	TeapotComponent(Actor* pInParent);

	// デストラクタ
	virtual ~TeapotComponent();

	// 更新
	// こいつ自信は何もしない
	virtual void Update(LPDIRECT3DDEVICE9 pDevice) override {}

	// 描画
	virtual void Render(LPDIRECT3DDEVICE9 pDevice) override;

private:
	// メッシュ
	LPD3DXMESH pMesh;

	// マテリアル
	D3DMATERIAL9 material;
};

#endif		// #ifndef TEAPOTCOMPONENT_H
