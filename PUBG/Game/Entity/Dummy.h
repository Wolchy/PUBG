#pragma once

class Dummy {
public:
	float velX = 0.0f, velY = 0.0f, velZ = 0.0f;
	float posX = 0.0f, posY = 0.0f, posZ = 0.0f;

	Dummy();

	virtual void update();
};