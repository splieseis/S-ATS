#ifndef APPLICANT_CLASS_HPP
# define APPLICANT_CLASS_HPP
# include <string>

class Applicant
{
public:
	Applicant();
	~Applicant();
	void setFirstName(std::string);
	void setLastName(std::string);
	void setJobTitle(std::string);
	void setLocation(std::string);
	void setPhoneNumber(std::string);
	void setEmail(std::string);

	std::string getFirstName(void);
	std::string getLastName(void);
	std::string getJobTitle(void);
	std::string getLocation(void);
	std::string getPhoneNumber(void);
	std::string getEmail(void);
	
private:
	std::string _firstName;
	std::string _lastName;
	std::string _jobTitle;
	std::string _location;
	std::string _phoneNumber;
	std::string _email;
};

#endif // APPLICANT_HPP
