#pragma once

#include "cmathutils.h"
#include "Component.h"

compDef(Rigidbody)

	vec3 velocity, force;
	float drag, mass;

	Rigidbody() : velocity(vec3Zero()),
				  force(vec3Zero()),
				  drag(0), mass(1) { }

	void addForce(vec3 const &a_force) {  force = force + a_force;  }

compEndDef