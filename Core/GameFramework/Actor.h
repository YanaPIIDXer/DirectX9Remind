#ifndef ACTOR_H
#define ACTOR_H

class Scene;

// �A�N�^�[�N���X
class Actor
{
public:

	// �R���X�g���N�^
	Actor(Scene* pInScene);

	// �f�X�g���N�^
	virtual ~Actor() = 0;

private:
	
	// �����V�[��
	Scene* pScene;
};

#endif		// #ifndef ACTOR_H
