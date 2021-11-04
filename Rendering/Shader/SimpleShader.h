#ifndef SIMPLESHADER_H
#define SIMPLESHADER_H

#include "Rendering/Shader.h"

// シンプルなShader
class SimpleShader : public Shader
{
public:

	// コンストラクタ
	SimpleShader(const RenderCallback &onRenderCallback);

	// デストラクタ
	virtual ~SimpleShader();

	// ワールド行列を設定
	void SetWorldMatrix(const D3DXMATRIX& mInWorld) { mWorld = mInWorld; }

	// カメラの座標を設定
	void SetCameraPosition(const D3DXVECTOR3& position);

protected:

	// 読み込まれた
	virtual void OnLoad(LPD3DXEFFECT pEffect) override;

	// 描画前の処理
	virtual void PreRender(LPDIRECT3DDEVICE9 pDevice, LPD3DXEFFECT pEffect) override;

private:

	// ワールド行列
	D3DXMATRIX mWorld;

	// World View Projection Matrix
	D3DXHANDLE mWVP;

	// World Inverse Transpose Matrix
	D3DXHANDLE mWIT;

	// カメラの座標・ハンドラ
	D3DXVECTOR3 cameraPos;
	D3DXHANDLE cameraPosHandle;

};

#endif		// #ifndef SIMPLESHADER_H
