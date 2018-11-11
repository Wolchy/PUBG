#pragma once

#include <iostream>

class Item {
public:
	std::string		id = "null";		//Custom ID
	std::string		name = "null";		//Name
	std::string		type = "null";		//Is it armor, weapon, or ammo
	int				size = 0;			//How many in stack
};

class Armor : public Item {
public:
	int				hp = 0;				//How much hp does the armor have
	int				protection = 0;		//How much does it protect
};

class Weapon : public Item {
public:
	std::string		w_class = "null";	//Scar, ak, kar98, pan, C H A I N S A W, ect
	int				melee = 0;			//How much melee damage does it do
	int				range = 0;			//How far can it reach
};

class Gun : public Weapon {
public:
	int				accuracy = 0;		//How good can you stand still
	std::string		ammo_type = "null"; //How type of ammo does it use
};

class Ammo : public Item {
public:
	std::string		a_type = "null";	//7.62, 5.56, 9mm, bolt, ect
	int weight = 0;						//How thicc is the bullet
	int speed = 0;						//How fast is the bullet
};