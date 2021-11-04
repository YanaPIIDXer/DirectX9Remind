#ifndef SCENEPLAYER_H
#define SCENEPLAYER_H

#include <memory>

class Scene;

// �V�[���Đ��N���X
class ScenePlayer
{
public:

	// �R���X�g���N�^
	ScenePlayer(Scene* pInitialScene);

	// �f�X�g���N�^
	~ScenePlayer();

	// �X�V
	void Update();

	// �`��
	void Render();

private:
	// ���݂̃V�[��
	std::shared_ptr<Scene> pCurrentScene;

	// �ȑO�̃V�[��
	// Scene::Update()���ŃV�[����؂�ւ������A
	// �֐����s���̃V�[���C���X�^���X����̂����̂�h���ׂ̂���
	std::shared_ptr<Scene> pPrevScene;
};

#endif		// #ifndef SCENEPLAYER_H
