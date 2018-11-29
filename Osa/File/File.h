#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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

class SimpleFile {	//Mostly made for easier lua incorperation
public:
	bool isGood(std::string path);
	std::string read(std::string path);
	bool writeString(std::string path, std::string contents, bool append);
};