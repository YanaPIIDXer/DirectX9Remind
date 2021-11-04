#ifndef SCENE_H
#define SCENE_H

#include <vector>

class Actor;

// �V�[���N���X
class Scene
{
public:

	// �R���X�g���N�^
	Scene();

	// �f�X�g���N�^
	virtual ~Scene() = 0;

	// ���̃V�[�������݂��邩�H
	bool HasNextScene() const { return (pNextScene != nullptr); }

	// �V�[���J�n
	virtual void BeginScene() = 0;

	// �X�V
	void Update(LPDIRECT3DDEVICE9 pDevice);

	// �`��
	void Render(LPDIRECT3DDEVICE9 pDevice);

	// ���̃V�[�������
	Scene* SweepNextScene()
	{
		Scene* pScene = pNextScene;
		pNextScene = nullptr;
		return pScene;
	}

	// �A�N�^�[��o�^
	void RegisterActor(Actor* pActor)
	{
		actorList.push_back(pActor);
	}

protected:

	// ���̃V�[�����Z�b�g
	void SetNextScene(Scene* pScene);

	// ���t���[���̏���
	virtual void Tick() = 0;

private:

	// ���̃V�[��
	Scene* pNextScene;

	// �A�N�^�[���X�g
	std::vector<Actor*> actorList;


	// ���̃V�[�������
	void releaseNextScene();
};

#endif		// #ifndef SCENE_H
