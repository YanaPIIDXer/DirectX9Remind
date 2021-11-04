#ifndef COMPONENT_H
#define COMPONENT_H

class Actor;

// �R���|�[�l���g�N���X
class Component
{
public:

	// �R���X�g���N�^
	Component(Actor* pInParent);

	// �f�X�g���N�^
	virtual ~Component() = 0;

	// �X�V
	virtual void Update() = 0;

	// �`��
	virtual void Render() {}

protected:

	// �e���擾
	Actor* GetParent() { return pParent; }

private:

	// �e
	Actor* pParent;
};

#endif		// #ifndef COMPONENT_H
