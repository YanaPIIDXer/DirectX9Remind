#ifndef SHADER_H
#define SHADER_H

#include <functional>

typedef std::function<void(LPDIRECT3DDEVICE9, LPD3DXEFFECT)> RenderCallback;

// シェーダ基底クラス
class Shader
{
public:

	// コンストラクタ
	Shader(const RenderCallback &onRenderCallback, const TCHAR* pInFilePath, const char *pInTechniqueName);

	// デストラクタ
	virtual ~Shader() = 0;

	// 読み込み
	bool Load();

	// 描画
	void Render(LPDIRECT3DDEVICE9 pDevice);

	// 有効か？
	bool IsValid() const { return (pEffect != nullptr); }

protected:

	// 読み込みが完了した
	virtual void OnLoad(LPD3DXEFFECT pEffect) = 0;

	// 描画前の処理
	virtual void PreRender(LPDIRECT3DDEVICE9 pDevice, LPD3DXEFFECT pEffect) = 0;

private:

	// 描画コールバック
	RenderCallback onRender;

	// ファイルパス
	const TCHAR* pFilePath;

	// テクニック名
	const char* pTechniqueName;

	// エフェクト
	LPD3DXEFFECT pEffect;

	// テクニック
	D3DXHANDLE technique;
};

#endif		// #ifndef SHADER_H
