#ifndef SHADER_H
#define SHADER_H

#include <functional>

// シェーダ基底クラス
class Shader
{
public:

	// コンストラクタ
	Shader(const std::function<void(LPD3DXEFFECT)> &onRenderCallback);

	// デストラクタ
	virtual ~Shader() = 0;

	// 読み込み
	bool Load(const TCHAR* pFilePath, const char *pTechniqueName);

	// 描画
	void Render();

	// 有効か？
	bool IsValid() const { return (pEffect != nullptr); }

protected:

	// 読み込みが完了した
	virtual void OnLoad(LPD3DXEFFECT pEffect) = 0;

	// 描画前の処理
	virtual void PreRender(LPD3DXEFFECT pEffect) = 0;

private:

	// 描画コールバック
	std::function<void(LPD3DXEFFECT)> onRender;

	// エフェクト
	LPD3DXEFFECT pEffect;

	// テクニック
	D3DXHANDLE technique;
};

#endif		// #ifndef SHADER_H
