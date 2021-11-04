#ifndef ACTOR_H
#define ACTOR_H

class Scene;

// �A�N�^�[�N���X
class Actor
{
public:

	// �R���X�g���N�^
	Actor(Scene* pInScene, const D3DXVECTOR3 &inPosition = D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		const D3DXVECTOR3 &inEulerAngle = D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	// �f�X�g���N�^
	virtual ~Actor() = 0;

	// �X�V
	virtual void Update() = 0;

	// �`��
	void Render();

	// ���W���擾
	const D3DXVECTOR3& GetPosition() const { return position; }

	// ���W��ݒ�
	void SetPosition(const D3DXVECTOR3& inPosition) { position = inPosition; }

	// ��]�i�I�C���[�p�j���擾
	const D3DXVECTOR3& GetEulerAngle() const { return eulerAngle; }

	// �p�x�i�I�C���[�p�j��ݒ�
	void SetEulerAngle(const D3DXVECTOR3& inEulerAngle) { eulerAngle = inEulerAngle; }

	// �g�k���擾
	const D3DXVECTOR3& GetScale() const { return scale; }

	// �g�k��ݒ�
	void SetScale(const D3DXVECTOR3& inScale) { scale = inScale; }

	// �j��.
	void Destroy()
	{
		bIsDestroyed = true;
		OnDestroyed();
	}

	// �j������Ă��邩�H
	bool IsDestroyed() const { return bIsDestroyed; }

protected:

	// �j�����ꂽ
	virtual void OnDestroyed() {}

private:
	
	// �����V�[��
	Scene* pScene;

	// ���W
	D3DXVECTOR3 position;

	// ��]
	D3DXVECTOR3 eulerAngle;
	
	// �g�k
	D3DXVECTOR3 scale;

	// �j������Ă��邩�H
	bool bIsDestroyed;
};

#endif		// #ifndef ACTOR_H