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

	// ���C�g��o�^
	int RegisterLight(const D3DLIGHT9& light)
	{
		int index = lights.size();
		lights.push_back(light);
		return index;
	}

	// ���C�g���X�V
	void UpdateLight(int index, const D3DLIGHT9& light)
	{
		lights[index] = light;
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

	// ���C�g���X�g
	std::vector<D3DLIGHT9> lights;


	// ���̃V�[�������
	void releaseNextScene();
};

#endif		// #ifndef SCENE_H
