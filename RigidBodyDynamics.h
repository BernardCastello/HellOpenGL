#pragma once
#include"SystemDef.h"

sysDef(RigidbodyDynamics)

bool init() { return true; }
bool term() { return true; }

bool condition(Entity *e)
{
	return e->active && e->rigidbody && e->transform;
}

void update(Entity *e)
{
	auto &pos = e->transform->position();
	float dt = core(Time).getDeltaTime();
	auto &vel = e->rigidbody->velocity;
	auto force = e->rigidbody->force;
	

}

sysEndDef