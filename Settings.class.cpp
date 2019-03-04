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
	this->_ENCRYPTION = stage;
	return ;
}

void Settings::setFilename(string name)
{
	this->_FILENAME = name;
	return ;
}

void Settings::setCsvDelimiter(char c)
{
	this->_CSV_DELIMITER = c;
	return ;
}

void Settings::setVersionControl(bool stage)
{
	this->_VERSION_CONTROL = stage;
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

char Settings::getCsvDelimiter(void)
{
	return (this->_CSV_DELIMITER);
}

bool Settings::getVersionControl(void)
{
	return (this->_VERSION_CONTROL);
}