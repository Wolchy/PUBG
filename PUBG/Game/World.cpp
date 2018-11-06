#include "World.h"

World::World()
{

}

void World::update()
{
	if (STATE == STATE_WAITING) {
		if (players_ig >= PLAYERS_ON_STARTUP - 1) {
			STATE = STATE_TIMER;
			timerxd = time(0);
		}
	}
	else if (STATE == STATE_TIMER) {
		if (difftime(time(0), timerxd) >= TIMER_xd)
			STATE = STATE_BR;
	}
	else if (STATE == STATE_BR) {
		if (players_ig < 2) {
			STATE = STATE_WINNER;
			timerXD = time(0);
		}
	}
	else if (STATE == STATE_WINNER) {
		if (difftime(time(0), timerXD) >= TIMER_XD)
			STATE = STATE_IDLE;
	}
}

bool World::playerJoin(Dummy * _player)
{
	if (STATE == STATE_TIMER || STATE == STATE_WAITING) {
		if (_player != NULL) {
			players.push_back(_player);
			players_ig++;
			return true;
		}
	}

	return false;
}
