#include "S-ATS.hpp"

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
		cout << "-                      *****           *      ********* *****                      -" << endl;
		cout << "-                      ** **          ***     ********* ** **                      -" << endl;
		cout << "-                      **            ** **       ***    **                         -" << endl;
		cout << "-                      *****  ***   **   **      ***    *****                      -" << endl;
		cout << "-                         **  ***  *********     ***       **                      -" << endl;
		cout << "-                      ** **      ***     ***    ***    ** **                      -" << endl;
		cout << "-                      *****     ***       ***   ***    *****                      -" << endl;
		cout << "------------------------------------------------------------------------------------" << endl;
*/

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
	string pause {};
	system("CLS");
	
	printHeader();
	cout << endl;
	cout << "Thank you for using Simon's Applicant Tracking System! (c) Simon Plieseis 2019" << endl;
	getline (cin, pause);
	system("CLS");
}

void updateDetails(vector <Applicant> candidates, int i)
{
	string input {};
	
	cout << "What do you want to update? " << endl;
	getline (cin, input);
	getline (cin, input);
	if (input == "First Name")
		cout << "First Name updated." << endl;
	else
		cout << "Else" << endl;
	getline (cin, input);
}

void details(vector <Applicant> candidates, int i)
{
	string input{};
	system("CLS");
	printHeader();
	cout << endl;
	cout << "------------------------------Candidate Details-------------------------------------" << endl << endl;
	cout << "First Name:    " << candidates.at(i).getFirstName() << endl;
	cout << "Last Name:     " << candidates.at(i).getLastName() << endl;
	cout << "Job Title:     " << candidates.at(i).getJobTitle() << endl;
	cout << "Location:      " << candidates.at(i).getLocation() << endl;
	cout << "Phone Number:  " << candidates.at(i).getPhoneNumber() << endl;
	cout << "Email Address: " << candidates.at(i).getEmail() << endl;
	getline (cin, input);
	if (input == "u")
		updateDetails(candidates, i -1);
	system("CLS");
}


void printList(vector <Applicant> candidates)
{
	int i {1};
	int index {};
	string input {};
	string pause {};
	string firstName {};
	string lastName {};
	string jobTitle {};

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
		cout << "Enter Candidate Index for Details: "; //protect against wrong input (out of bounce)
		getline (cin, input);
		if (isdigit(input[0]))
		{
			index = stoi(input);
			if (index > 0 && index <= candidates.size())
				details(candidates, index - 1);
			else
				cout << "Please enter a valid Index!" << endl;
		}
		else
			cout << "Please enter a valid Index!" << endl;
	}
	else
	{
		cout << "List is empty! - Add candidates first, thank you!\n";
		getline (cin, pause);
		system("CLS");
	}
}

//void updateCandidate(vector <Applicant> candidates)
//{
//	system("CLS");
//	printHeader();
//	cout << endl;
//	cout << "--------------------------------Update a Candidate----------------------------------" << endl << endl;
//	printList(candidates);
//}

void listCandidates(vector <Applicant> candidates)
{
	system("CLS");
	printHeader();
	cout << endl;
	cout << "-------------------------------------Candidates-------------------------------------" << endl << endl;
	printList(candidates);
}

Applicant newCandidate(void)
{
	system("CLS");
	string input;
	Applicant newCandidate;
	
	printHeader();
	cout << endl;
	cout << "------------------------------New Candidate-----------------------------------------" << endl << endl;
	cout << "First Name: ";
	getline (cin, input);
	newCandidate.setFirstName(input);
	cout << "Last Name: ";
	getline (cin, input);
	newCandidate.setLastName(input);
	cout << "Job Title: ";
	getline (cin, input);
	newCandidate.setJobTitle(input);
	cout << "Location: ";
	getline (cin, input);
	newCandidate.setLocation(input);
	cout << "Phone Number: ";
	getline (cin, input);
	newCandidate.setPhoneNumber(input);
	cout << "Email: ";
	getline (cin, input);
	newCandidate.setEmail(input);
	cout << "\nNew Candidate: " << newCandidate.getFirstName() << " "<< newCandidate.getLastName() << " successfully created.\n";
	getline (cin, input);
	system("CLS");
	return (newCandidate);
}

int main()
{
	string input;
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

		cout << " N - New Applicant \tL - List Applicants \tS - Search" << endl;
		cout << " Z - Clear screen \tD - Delete List \tI - Imprint \t\t Q - Quit " << endl;
		cout << "------------------------------------------------------------------------------------" << endl;
		cout << endl;
		cout << "What do you wanna do?: ";
		getline (cin, input);
		cout << endl;
		
		if (input == "I" || input == "i")
			imprint();
		else if (input == "N" || input == "n")
		{
			Applicant newApplicant;
			newApplicant = newCandidate();
			candidates.push_back(newApplicant);
		}
		else if (input == "L" || input == "l")
			listCandidates(candidates);
		else if (input == "D" || input == "d")
		{
			candidates.clear();
			system("CLS");
		}
		else if (input == "Z" || input == "z")
			system("CLS");
		else if (input == "Q" || input == "q")
			cout << "Thank you for using S-ATS! See you soon!" << endl;
		else
		{
			cout << "Please enter a valid input  [N, U, L, S, Z, D, I, Q]" << endl;
			getline (cin, input);
			system("CLS");			
		}
	} while (input != "Q" && input != "q");
	return (0);
}