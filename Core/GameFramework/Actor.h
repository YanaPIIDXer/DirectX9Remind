#ifndef ACTOR_H
#define ACTOR_H

class Scene;

// アクタークラス
class Actor
{
public:

	// コンストラクタ
	Actor(Scene* pInScene, const D3DXVECTOR3 &inPosition = D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		const D3DXVECTOR3 &inEulerAngle = D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	// デストラクタ
	virtual ~Actor() = 0;

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

private:
	
	// 所属シーン
	Scene* pScene;

	// 座標
	D3DXVECTOR3 position;

	// 回転
	D3DXVECTOR3 eulerAngle;
	
	// 拡縮
	D3DXVECTOR3 scale;
};

#endif		// #ifndef ACTOR_H
