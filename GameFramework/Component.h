#ifndef COMPONENT_H
#define COMPONENT_H

class Actor;

// コンポーネントクラス
class Component
{
public:

	// コンストラクタ
	Component(Actor* pInParent);

	// デストラクタ
	virtual ~Component() = 0;

	// 初期化
	virtual void Initialize() {}

	// 更新
	virtual void Update(LPDIRECT3DDEVICE9 pDevice) = 0;

	// 描画
	virtual void Render(LPDIRECT3DDEVICE9 pDevice) {}

protected:

	// 親を取得
	Actor* GetParent() { return pParent; }

private:

	// 親
	Actor* pParent;
};

#endif		// #ifndef COMPONENT_H
