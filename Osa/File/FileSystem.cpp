#include "FileSystem.h"

void FileSystem::createDir(std::string _path) {
	CreateDirectory((LPCWSTR)_path.c_str(), NULL);
}

void FileSystem::deleteDir(std::string _path) {
	RemoveDirectory((LPCWSTR)_path.c_str());
}

void FileSystem::createFile(std::string _path) {
	CreateFile((LPCWSTR)_path.c_str(), NULL, NULL, NULL, NULL, NULL, NULL);
}

void FileSystem::deleteFile(std::string _path) {
	DeleteFile((LPCWSTR)_path.c_str());
}