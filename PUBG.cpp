#include <iostream>
#include <Windows.h>

#include "Osa/Osa.h"

int main(int argc, char* argv[]) {
	//ShowWindow(GetConsoleWindow(), SW_HIDE); //DEBUG MODE IS ON SO THATS A BIG NONO

	Osa osa;

	for (int i = 1; i < argc; ++i) {
		std::string arg = argv[i];

		if ((arg == "-s") || (arg == "-server")) {
			std::cout << "Setting it to server mode!" << std::endl;
		}
		if ((arg == "-c") || (arg == "-console")) {
			ShowWindow(GetConsoleWindow(), SW_SHOW);
		}
	}

	if (!osa.init("PUBG", 1280, 720)){
		ShowWindow(GetConsoleWindow(), SW_SHOW);
		system("pause");
	}

	while (osa.isRunning())
		osa.loop();

	return 1;
}