#include "Dummy.h"

Dummy::Dummy()
{
}

void Dummy::update()
{
	posX += velX;
	posY += velY;
	posZ += velZ;
}
