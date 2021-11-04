#include "stdafx.h"
#include "Scene.h"
#include "Actor.h"

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
	auto it = actorList.begin();
	while (it != actorList.end())
	{
		auto* pActor = *it;
		if (pActor->IsDestroyed())
		{
			delete pActor;
			it = actorList.erase(it);
		}
		else
		{
			pActor->Update();
			++it;
		}
	}
}

// �`��
void Scene::Render(LPDIRECT3DDEVICE9 pDevice)
{
	for (auto it = actorList.begin(); it != actorList.end(); ++it)
	{
		(*it)->Render();
	}
}


// ���̃V�[�����Z�b�g
void Scene::SetNextScene(Scene* pScene)
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
