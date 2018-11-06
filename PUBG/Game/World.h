#pragma once

#include <vector>
#include <ctime>

#include "Entity/Dummy.h"

class World {
public:
	int PLAYERS_ON_STARTUP = 4, players_ig = 0, TIMER_xd = 60, TIMER_XD = 10;
	std::string STATE = "IDLE", STATE_IDLE = "IDLE", STATE_WAITING = "WAITING", STATE_TIMER = "TIMING",
		STATE_BR = "BATTLE", STATE_WINNER = "WINNER";
	time_t timerxd, timerXD;



	std::vector<Dummy*> players;

	World();

	void update();
	bool playerJoin(Dummy * _player);
};