#ifndef SCENE_H
#define SCENE_H

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
	
	// ���̃V�[�������
	Scene* SweepNextScene()
	{
		Scene* pScene = pNextScene;
		pNextScene = nullptr;
		return pScene;
	}

protected:

	// ���̃V�[�����Z�b�g
	void setNextScene(Scene* pScene);

private:

	// ���̃V�[��
	Scene* pNextScene;


	// ���̃V�[�������
	void releaseNextScene();
};

#endif		// #ifndef SCENE_H
