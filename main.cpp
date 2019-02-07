#include <iostream>
#include <vector>
#include <string>
#include "Applicant.class.hpp"

using namespace std;

void printHeader()
{
	
		cout << "------------------------------------------------------------------------------------" << endl;
		cout << "-                      *****          ***     ********* *****                      -" << endl;
		cout << "-                      **            ** **    ********* **                         -" << endl;
		cout << "-                      *****  ***   *******      ***    *****                      -" << endl;
		cout << "-                         **       ***   ***     ***       **                      -" << endl;
		cout << "-                      *****      ***     ***    ***    *****                      -" << endl;
		cout << "------------------------------------------------------------------------------------" << endl;

/*		cout << "------------------------------------------------------------------------------------" << endl;
		cout << "-----------------------     --------   ----         ----     -----------------------" << endl;
		cout << "-----------------------   ---------  -  ------   -------   -------------------------" << endl;
		cout << "-----------------------     -   --       -----   -------     -----------------------" << endl;
		cout << "-------------------------   -----   ---   ----   ---------   -----------------------" << endl;
		cout << "-----------------------     ----           ---   -------     -----------------------" << endl;
		cout << "------------------------------------------------------------------------------------" << endl;
*/
}

void imprint()
{
	char pause {};
	system("CLS");
	
	printHeader();
	cout << endl;
	cout << "Thank you for using Simon's Applicant Tracking System! (c) Simon Plieseis 2019" << endl;
	cin >> pause;
	system("CLS");
}

void details(vector <Applicant> candidates, int i)
{
	string pause{};
	system("CLS");
	printHeader();
	cout << endl;
	cout << "------------------------------Candidate Details-------------------------------------" << endl << endl;
	cout << "First Name:    " << candidates.at(i - 1).getFirstName() << endl;
	cout << "Last Name:     " << candidates.at(i - 1).getLastName() << endl;
	cout << "Job Title:     " << candidates.at(i - 1).getJobTitle() << endl;
	cout << "Location:      " << candidates.at(i - 1).getLocation() << endl;
	cout << "Phone Number:  " << candidates.at(i - 1).getPhoneNumber() << endl;
	cout << "Email Address: " << candidates.at(i - 1).getEmail() << endl;
	cin >> pause;
	system("CLS");
}

void listCandidates(vector <Applicant> candidates)
{
	int i {1};
	int input {};
	string pause {};
	string firstName {};
	string lastName {};
	string jobTitle {};

	system("CLS");
	printHeader();
	cout << endl;
	cout << "-------------------------------------Candidates-------------------------------------" << endl << endl;
	if (candidates.size() != 0)
	{
		cout << "Index\t|First Name     |Last Name      |Job Title" << endl;
		for(auto applicant: candidates)
		{
			firstName = applicant.getFirstName();
			lastName = applicant.getLastName();
			jobTitle = applicant.getJobTitle();
			firstName.resize(15, ' ');
			lastName.resize(15, ' ');
			jobTitle.resize(18, ' ');
			cout << i++ << "\t|" << firstName << "|" << lastName << "|" << jobTitle << endl;
		}
		cout << endl;
		cout << "Enter Candidate Index for Details: ";
		cin >> input;
		details(candidates, input);
	}
	else
	{
		cout << "List is empty! - Add candidates first, thank you!\n";
		cin >> pause;
		system("CLS");
	}
}

Applicant newCandidate(void)
{
	system("CLS");
	string input;
	Applicant newCandidate;
	cout << "First Name: ";
	cin >> input;
	newCandidate.setFirstName(input);
	cout << "Last Name: ";
	cin >> input;
	newCandidate.setLastName(input);
	cout << "Job Title: ";
	cin >> input;
	newCandidate.setJobTitle(input);
	cout << "Location: ";
	cin >> input;
	newCandidate.setLocation(input);
	cout << "Phone Number: ";
	cin >> input;
	newCandidate.setPhoneNumber(input);
	cout << "Email: ";
	cin >> input;
	newCandidate.setEmail(input);
	cout << "New Candidate: " << newCandidate.getFirstName() << " "<< newCandidate.getLastName() << " successfully created.\n";
	cin >> input;
	system("CLS");
	return (newCandidate);
}

int main()
{
	char input;
	vector <Applicant> candidates {};
	do
	{
		printHeader();
		
/*		cout << "------------------------------------------------------------------------------------" << endl;
		cout << "-----------------------*****--------***----*********----*****-----------------------" << endl;
		cout << "-----------------------***---------**-**------***-------***-------------------------" << endl;
		cout << "-----------------------*****-***--*******-----***-------*****-----------------------" << endl;
		cout << "-------------------------***-----***---***----***---------***-----------------------" << endl;
		cout << "-----------------------*****----***********---***-------*****-----------------------" << endl;
		cout << "------------------------------------------------------------------------------------" << endl;*/

		cout << " N - New Applicant \tU - Update Applicant \tL - List Applicants \t S - Search" << endl;
		cout << " Z - Clear screen \tD - Delete List \tI - Imprint \t\t Q - Quit " << endl;
		cout << "------------------------------------------------------------------------------------" << endl;
		cout << endl;
		cout << "What do you wanna do?: ";
		cin >> input;
		cout << endl;
		
		if (input == 'I' || input == 'i')
			imprint();
		else if (input == 'N' || input == 'n')
		{
			Applicant newApplicant;
			newApplicant = newCandidate();
			candidates.push_back(newApplicant);
		}
		else if (input == 'L' || input == 'l')
			listCandidates(candidates);
		else if (input == 'D' || input == 'd')
		{
			candidates.clear();
			system("CLS");
		}
		else if (input == 'Z' || input == 'z')
			system("CLS");
		else if (input == 'Q' || input == 'q')
			cout << "Thank you for using S-ATS! See you soon!" << endl;
		else
			cout << "Please enter a valid input  [N, U, L, S, Z, D, I, Q]" << endl;
	} while (input != 'q' && input != 'Q');
	return (0);
}