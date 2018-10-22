#pragma once

#include <iostream>
#include <Windows.h>

class FileSystem {
public:
	void createDir(std::string path);
	void deleteDir(std::string path);
	void createFile(std::string path);
	void deleteFile(std::string path);
};