
#pragma once

#include "Transform.h"
#include "Rigidbody.h"
#include "Render.h"

#define entityFree(e)  do { \
						compFree(e, transform); \
						compFree(e, rigidbody); \
						compFree(e, render); \
						e->active = false; \
						} while (0)


struct Entity
{
	bool active;
	int factoryIndex;
	Transform *transform;
	Rigidbody *rigidbody;
	Render    *render;

	Entity(int UID) : factoryIndex(UID), active(true),
		transform(0),
		rigidbody(0),
		render(0) { }
};