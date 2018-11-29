#include "Lua.h"

#include "../Osa.h"

#include "../Network/Network.h"

#include "../Util/SplitString.h"

#include "../File/File.h"
#include "../File/FileSystem.h"

#include "../Graphics/Texture.h"
#include "../Graphics/Shader.h"

Lua::Lua() {
	lua.open_libraries();
}

void Lua::loadOsa(Osa* osa) {
	lua.set_function("osa_exit", &Osa::exit, osa);
	lua.set_function("osa_getScreenWidth", &Osa::getScreenWidth, osa);
	lua.set_function("osa_getScreenHeight", &Osa::getScreenHeight, osa);
	lua.set_function("osa_getDelta", &Osa::getDelta, osa);
	lua.set_function("osa_getFPS", &Osa::getFPS, osa);
	lua.set_function("osa_isRunning", &Osa::isRunning, osa);
	lua.set_function("osa_isServer", &Osa::isServer, osa);
	lua.set_function("osa_loop", &Osa::loop, osa);
	lua.set_function("osa_update", &Osa::update, osa);
	lua.set_function("osa_render", &Osa::render, osa);
	lua.set_function("osa_setServer", &Osa::setServer, osa);
	lua.set_function("osa_getVersion", &Osa::getVersion, osa);
	lua.set_function("osa_getOsa", &Osa::getOsa, osa);
}

void Lua::loadNetwork() {
	lua.new_usertype<Network>("Network",
		"init", &Network::init,
		"update", &Network::update,
		"sendMessage", &Network::sendMessage,
		"allocPacket", &Network::allocPacket,
		"refreshIP", &Network::refreshIP,
		"refreshPing", &Network::refreshPing,
		"isIPRegistered", &Network::isIPRegistered,
		"getIPLoc", &Network::getIPLoc,
		"kickIP", &Network::kickIP,
		"getIP", &Network::getIP,
		"getPing", &Network::getPing,
		"setServerName", &Network::setServerName,
		"getServerName", &Network::getServerName,
		"setServerPort", &Network::setServerPort,
		"getServerPort", &Network::getServerPort,
		"setIsServer", &Network::setIsServer,
		"getIsServer", &Network::getIsServer,
		"getPacketSize", &Network::getPacketSize,
		"setPacketAmt", &Network::setPacketAmt,
		"getPacketAmt", &Network::getPacketAmt,
		"setDebugMode", &Network::setDebugMode,
		"getDebugMode", &Network::getDebugMode,
		"setMaxClients", &Network::setMaxClients,
		"getMaxClients", &Network::getMaxClients,
		"getClientCount", &Network::getClientCount,
		"getTotalPacketsSent", &Network::getTotalPacketsSent,
		"getTotalPacketsRecv", &Network::getTotalPacketsRecv,
		"getTotalBitsSent", &Network::getTotalBitsSent,
		"getTotalBitsRecv", &Network::getTotalBitsRecv,
		"getTimedPacketsSent", &Network::getTimedPacketsSent,
		"getTimedPacketsRecv", &Network::getTimedPacketsRecv,
		"getTimedBitsSent", &Network::getTimedBitsSent,
		"getTimedBitsRecv", &Network::getTimedBitsRecv,
		"getDataFromClientMessage", &Network::getDataFromClientMessage,
		"getIPFromClientMessage", &Network::getIPFromClientMessage);
}

void Lua::loadUtil() {
	SplitString ss;
	lua.set_function("util_splitString", &SplitString::split, ss);
}

void Lua::loadFileSystem() {
	SimpleFile sf;
	lua.set_function("file_isGood", &SimpleFile::isGood, sf);
	lua.set_function("file_read", &SimpleFile::read, sf);
	lua.set_function("file_writeString", &SimpleFile::writeString, sf);
	FileSystem fs;
	lua.set_function("file_createDir", &FileSystem::createDir, fs);
	lua.set_function("file_createFile", &FileSystem::createFile, fs);
	lua.set_function("file_deleteDir", &FileSystem::deleteDir, fs);
	lua.set_function("file_deleteFile", &FileSystem::deleteFile, fs);
}

void Lua::loadGraphics() {
	lua.new_usertype<Texture, std::string>("Texture",
		"getID", &Texture::getID,
		"getWidth", &Texture::getWidth,
		"getHeight", &Texture::getHeight);
	lua.new_usertype<Shader, std::string, std::string, bool>("Shader",
		"use", &Shader::use,
		"setBool", &Shader::setBool,
		"setInt", &Shader::setInt,
		"setFloat", &Shader::setFloat,
		"setMat4", &Shader::setMat4,
		"getID", &Shader::getID);
}

void Lua::exec(std::string command) {
	lua.script(command);
}
