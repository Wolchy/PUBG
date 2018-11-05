#include "World.h"

World::World()
{
}

void World::update()
{
	for (Dummy* d : players) {
		d->update();
	}
}
