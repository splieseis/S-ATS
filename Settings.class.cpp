#include "S-ATS.hpp"

Settings::Settings()
{
}

Settings::~Settings()
{
}

/* Setters */

void Settings::setProgramWidth(int width)
{
	this->_PROGRAM_WIDTH = width;
	return ;
}

void Settings::setLineChar(char c)
{
	this->_LINE_CHAR = c;
	return ;
}

void Settings::setEncryption(bool stage)
{
	if (stage == true)
		this->_ENCRYPTION = true;
	else 
		this->_ENCRYPTION = false;
	return ;
}

void Settings::setFilename(string name)
{
	this->_FILENAME = name;
	return ;
}

/* Getters */

int Settings::getProgramWidth(void)
{
	return (this->_PROGRAM_WIDTH);
}

char Settings::getLineChar(void)
{
	return (this->_LINE_CHAR);
}

bool Settings::getEncryption(void)
{
	return (this->_ENCRYPTION);
}

string Settings::getFilename(void)
{
	return (this->_FILENAME);
}