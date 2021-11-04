#include "stdafx.h"
#include "Scene.h"

// �R���X�g���N�^
Scene::Scene()
	: pNextScene(nullptr)
{
}

// �f�X�g���N�^
Scene::~Scene()
{
	releaseNextScene();
}

// �X�V
void Scene::Update()
{
}

// �`��
void Scene::Render(LPDIRECT3DDEVICE9 pDevice)
{
}


// ���̃V�[�����Z�b�g
void Scene::setNextScene(Scene* pScene)
{
	releaseNextScene();		// �������ɃZ�b�g����Ă����ꍇ�͉��
	pNextScene = pScene;
}

// ���̃V�[�������
void Scene::releaseNextScene()
{
	if (pNextScene != nullptr)
	{
		delete pNextScene;
		pNextScene = nullptr;
	}
}
