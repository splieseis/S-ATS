#include "Applicant.class.hpp"

Applicant::Applicant()
{
}

Applicant::~Applicant()
{
}

/* Setters */

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

void Applicant::setJobTitle(std::string str)
{
	this->_jobTitle = str;
	return ;
}

void Applicant::setLocation(std::string str)
{
	this->_location = str;
	return ;
}

void Applicant::setPhoneNumber(std::string str)
{
	this->_phoneNumber = str;
	return ;
}

void Applicant::setEmail(std::string str)
{
	this->_email = str;
	return ;
}

/* Getters */

std::string Applicant::getFirstName(void)
{
	return (this->_firstName);
}

std::string Applicant::getLastName(void)
{
	return (this->_lastName);
}

std::string Applicant::getJobTitle(void)
{
	return (this->_jobTitle);
}

std::string Applicant::getLocation(void)
{
	return (this->_location);
}

std::string Applicant::getPhoneNumber(void)
{
	return (this->_phoneNumber);
}

std::string Applicant::getEmail(void)
{
	return (this->_email);
}