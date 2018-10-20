#include <iostream>
#include <Windows.h>

int main(int argc, char* argv[]) {
	//ShowWindow(GetConsoleWindow(), SW_HIDE); //DEBUG MODE IS ON SO THATS A BIG NONO

	for (int i = 1; i < argc; ++i) {
		std::string arg = argv[i];

		if ((arg == "-s") || (arg == "-server")) {
			std::cout << "Setting it to server mode!" << std::endl;
		}
		if ((arg == "-c") || (arg == "-console")) {
			ShowWindow(GetConsoleWindow(), SW_SHOW);
		}
	}

	return 1;
}