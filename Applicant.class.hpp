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

	std::string getFirstName(void);
	std::string getLastName(void);
	
private:
	std::string _firstName;
	std::string _lastName;
};

#endif // APPLICANT_HPP
