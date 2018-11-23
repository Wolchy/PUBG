#include "TestScreen.h"

TestScreen::TestScreen() : Screen::Screen("testScreen"){}

void TestScreen::update(Osa osa) {
	if (console) {
		console = false;
		std::string consoleBuffer;
		std::getline(std::cin, consoleBuffer);

		//osa.lua.exec(consoleBuffer);

		SplitString ss;
		std::vector<std::string> s = ss.split(consoleBuffer, " ");
		if (s[0] == "server")
			osa.setServer(true);
		else if (s[0] == "init") {
			network.init(osa);
			init = true;
		}
		else if (s[0] == "ping") {
			network.refreshPing(network.ip);
		}
		else if (s[0] == "stress") {
			for (int i = 0; i < std::stoi(s[1]); i++)
				network.sendMessage(std::to_string(i), network.ip);
			std::cout << "Done Sending Packets" << std::endl;
			network.sendMessage("done", network.ip);
		}
		else if (s[0] == "test") {
			network.sendMessage("BIGGESTBOI", network.ip);
			network.sendMessage("widdle", network.ip);
			network.sendMessage("none", network.ip);
		}
		else {
			network.sendMessage(consoleBuffer, network.ip);
		}
	}
	if (init)
		network.update();
}

void TestScreen::render(Osa osa) {

}

void TestScreen::keyUp(Osa osa, SDL_Keycode key) {
	if (key == SDLK_BACKQUOTE)
		console = true;
}
