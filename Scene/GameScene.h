#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "GameFramework/Scene.h"

// �Q�[���V�[��
class GameScene : public Scene
{
public:

	// �R���X�g���N�^
	GameScene();

	// �f�X�g���N�^
	virtual ~GameScene();

	// �V�[���J�n
	virtual void BeginScene() override;

protected:

	// ���t���[���̏���
	virtual void Tick() override;
};

#endif		// #ifndef GAMESCENE_H
