#pragma once

#include <sol.hpp>

class Osa;
class Network;

class Lua {
public:
	sol::state lua;

	Lua();

	void loadOsa(Osa* osa);
	void loadNetwork();
	void loadUtil();
	void loadFileSystem();
	void loadGraphics();

	void exec(std::string commad);
};