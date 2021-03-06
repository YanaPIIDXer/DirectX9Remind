#ifndef ACTOR_H
#define ACTOR_H

#include <vector>

class Scene;
class Component;

// アクタークラス
class Actor
{
public:

	// コンストラクタ
	Actor(Scene* pInScene);

	// デストラクタ
	virtual ~Actor() = 0;

	// 更新
	void Update(LPDIRECT3DDEVICE9 pDevice);

	// 描画
	void Render(LPDIRECT3DDEVICE9 pDevice);

	// 座標を取得
	const D3DXVECTOR3& GetPosition() const { return position; }

	// 座標を設定
	void SetPosition(const D3DXVECTOR3& inPosition) { position = inPosition; }

	// 回転（オイラー角）を取得
	const D3DXVECTOR3& GetEulerAngle() const { return eulerAngle; }

	// 角度（オイラー角）を設定
	void SetEulerAngle(const D3DXVECTOR3& inEulerAngle) { eulerAngle = inEulerAngle; }

	// 拡縮を取得
	const D3DXVECTOR3& GetScale() const { return scale; }

	// 拡縮を設定
	void SetScale(const D3DXVECTOR3& inScale) { scale = inScale; }

	// 姿勢行列を取得
	D3DXMATRIX GetTransformMatrix() const;

	// 破棄.
	void Destroy()
	{
		bIsDestroyed = true;
		OnDestroyed();
	}

	// 破棄されているか？
	bool IsDestroyed() const { return bIsDestroyed; }

	// 所属シーンを取得
	Scene *GetScene() const { return pScene; }

protected:

	// コンポーネント追加
	void AddComponent(Component* pComponent);

	// 毎フレームの処理
	virtual void Tick() {}

	// 破棄された
	virtual void OnDestroyed() {}

private:
	
	// 所属シーン
	Scene* pScene;

	// 座標
	D3DXVECTOR3 position;

	// 回転
	D3DXVECTOR3 eulerAngle;
	
	// 拡縮
	D3DXVECTOR3 scale;

	// 破棄されているか？
	bool bIsDestroyed;

	// コンポーネントリスト
	std::vector<Component*> components;
};

#endif		// #ifndef ACTOR_H
