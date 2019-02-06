#include "Applicant.class.hpp"

Applicant::Applicant()
{
}

Applicant::~Applicant()
{
}

void Applicant::setFirstName(std::string str)
{
	this->_firstName = str;
	return ;
}

void Applicant::setLastName(std::string str)
{
	this->_lastName = str;
	return ;
}

std::string Applicant::getFirstName(void)
{
	return (this->_firstName);
}

std::string Applicant::getLastName(void)
{
	return (this->_lastName);
}