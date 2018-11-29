#include "File.h"

File::File(std::string _path) {
	path = _path;
}

std::string File::getPath() {
	return path;
}

bool File::isGood() {
	std::fstream out(path);
	return out.good();
}

std::string File::read() {
	std::ifstream _temp1(path);
	if (_temp1.is_open()) {
		std::stringstream _temp2;
		_temp2 << _temp1.rdbuf();
		return _temp2.str();
	}
	return NULL;
}

bool File::writeString(std::string content, bool app) {
	std::ofstream in;
	if (app)
		in.open(path, std::ios::app);
	else
		in.open(path);
	if (!in) {
		std::cout << "ofstream error: connot open file!" << std::endl;
		return false;
	}
	if (in.is_open())
		in << content;
	in.close();
	return true;
}

bool SimpleFile::isGood(std::string path)
{
	std::fstream out(path);
	return out.good();
}

std::string SimpleFile::read(std::string path){
	std::ifstream _temp1(path);
	if (_temp1.is_open()) {
		std::stringstream _temp2;
		_temp2 << _temp1.rdbuf();
		return _temp2.str();
	}
	return NULL;
}

bool SimpleFile::writeString(std::string path, std::string contents, bool append)
{
	std::ofstream in;
	if (append)
		in.open(path, std::ios::app);
	else
		in.open(path);
	if (!in) {
		std::cout << "ofstream error: connot open file!" << std::endl;
		return false;
	}
	if (in.is_open())
		in << contents;
	in.close();
	return true;
}
