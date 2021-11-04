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
	for (auto it = actorList.begin(); it != actorList.end(); ++it)
	{
		delete (*it);
	}
	releaseNextScene();
}

// �X�V
void Scene::Update(LPDIRECT3DDEVICE9 pDevice)
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
			pActor->Update(pDevice);
			++it;
		}
	}

	Tick();
}

// �`��
void Scene::Render(LPDIRECT3DDEVICE9 pDevice)
{
	for (auto it = actorList.begin(); it != actorList.end(); ++it)
	{
		(*it)->Render(pDevice);
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
