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

};

#endif		// #ifndef SIMPLESHADER_H
