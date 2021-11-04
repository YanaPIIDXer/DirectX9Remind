#ifndef TEAPOTCOMPONENT_H
#define TEAPOTCOMPONENT_H

#include "GameFramework/Component.h"
#include "Rendering/Shader/SimpleShader.h"

// ティーポット描画Component
class TeapotComponent : public Component
{
public:

	// コンストラクタ
	TeapotComponent(Actor* pInParent);

	// デストラクタ
	virtual ~TeapotComponent();

	// 更新
	virtual void Update(LPDIRECT3DDEVICE9 pDevice) override;

	// 描画
	virtual void Render(LPDIRECT3DDEVICE9 pDevice) override;

	// カメラの座標を設定
	void SetCameraPosition(const D3DXVECTOR3& position);

private:
	// メッシュ
	LPD3DXMESH pMesh;

	// マテリアル
	D3DMATERIAL9 material;

	// シェーダ
	SimpleShader shader;


	// Shaderによる描画
	void postRender(LPDIRECT3DDEVICE9 pDevice, LPD3DXEFFECT pEffect);
};

#endif		// #ifndef TEAPOTCOMPONENT_H
