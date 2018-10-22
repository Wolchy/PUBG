#pragma once

#include <iostream>
#include <fstream>
#include <string>

class File {
public:
	File(std::string _path);

	std::string getPath();
	bool isGood();
	std::string read();
	bool writeString(std::string contents, bool append);

private:
	std::string path;
};