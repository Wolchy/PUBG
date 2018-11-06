#pragma once

#include <vector>

#include <SDL_net.h>

class Network {
public:

	Network();

	void init();
	void update();

	void sendMessage(std::string _message);
	void server_sendMessage(int clientID, std::string _message);
};