#pragma once
#include "Core.h"
#include "Entity.h"



coreDef(Factory)

std::vector<Entity> m_entities;
std::vector<Entity> m_entitiesRemove;
std::vector<Entity> m_entitiesAdd;


Entity *newEntity()
{
	m_entitiesAdd.push_back(Entity(-1));
	return &m_entitiesAdd.back();
}

bool step()
{
	for (int i = 0; i < m_entitiesRemove.size(); ++i)
	{
		auto e = &m_entitiesRemove[i];
		entityFree(e);
	}
	auto newEntity = m_entitiesAdd.begin();
	for (auto entity = m_entities.begin(); entity != m_entities.end() &&
									 newEntity != m_entitiesAdd.end(); entity++)
		if (!entity->active)
		{
			newEntity->factoryIndex = entity->factoryIndex;
			*entity = *newEntity;
			newEntity++;
		}
	
	while (newEntity != m_entitiesAdd.end())
	{
		newEntity->factoryIndex = m_entities.size();
		m_entities.push_back(*newEntity);
		newEntity++;
	}

	m_entitiesAdd.clear();
	m_entitiesRemove.clear();
	return true;
}

bool init() { return true; }
bool term() { return true; }




public:

	std::vector<Entity> &getEntities() { return m_entities; }

	void FreeEntity(Entity *e)
	{
		entityFree(e);
	}

	Entity *MakeTriangle()
	{
		Entity *e = newEntity();

		compMake(e, rigidbody, Rigidbody);
		compMake(e, transform, Transform);
		compMake(e, render, Render);
	
		e->transform->position().x = core(Window).width() / 2;
		e->transform->position().y = core(Window).height() / 2;
	
		e->render->mesh = "Triangle";
		e->render->shader = "Flat";
		
		return e;
	}



coreEndDef