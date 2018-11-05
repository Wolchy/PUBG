#pragma once

#include <vector>

#include "Entity/Dummy.h"

class World {
public:
	std::vector<Dummy*> players;

	World();

	void update();
};