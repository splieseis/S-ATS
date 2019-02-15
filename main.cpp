#include "S-ATS.hpp"

using namespace std;

void printLine(char c)
{
	int i;
	for (i = 0; i < PROGRAM_WIDTH; i++)
		cout << c;
	cout << endl;
}

void printHeader()
{
	printLine(' ');
	cout << center("*****         ***     *********  *****", PROGRAM_WIDTH)<< endl;
	cout << center("**           ** **    *********  **   ", PROGRAM_WIDTH)<< endl;
	cout << center("*****  ***  *******      ***     *****", PROGRAM_WIDTH)<< endl;
	cout << center("   **      ***   ***     ***        **", PROGRAM_WIDTH)<< endl;
	cout << center("*****     ***     ***    ***     *****", PROGRAM_WIDTH)<< endl;
	printLine(' ');
	
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
}

void imprint()
{
	string pause {};
	clearScreen();
	
	printHeader();
	printLine(DEFAULT_LINE_CHAR);
	cout << center("Imprint", PROGRAM_WIDTH) << endl;
	printLine(DEFAULT_LINE_CHAR);
	cout << endl;
	cout << "Thank you for using Simon's Applicant Tracking System! (c) Simon Plieseis 2019" << endl;
	getline (cin, pause);
	clearScreen();
}

void updateDetails(vector <Applicant> &candidates, int i)
{
	string input {};
	
	clearScreen();
	printHeader();
	printLine(DEFAULT_LINE_CHAR);
	cout << center("Update Candidate Details", PROGRAM_WIDTH) << endl;
	printLine(DEFAULT_LINE_CHAR);
	cout << endl;
	printDetails(candidates, i);
	cout << endl;
	cout << "What do you want to update? ";
	getline (cin, input);
	if (input == "First Name" || input == "first name" || input == "First name")
	{
		cout << "\nCurrent First Name: " << candidates.at(i).getFirstName() << "-> New First Name: ";
		getline(cin, input);
		candidates.at(i).setFirstName(input);
		cout << "\nFirst Name succefully updated to " << candidates.at(i).getFirstName() << ". " << endl;
	}
	else if (input == "Last Name" || input == "last name" || input == "Last name")
	{
		cout << "\nCurrent Last Name: " << candidates.at(i).getLastName() << "-> New Last Name: ";
		getline(cin, input);
		candidates.at(i).setLastName(input);
		cout << "\nLast Name succefully updated to " << candidates.at(i).getLastName() << ". " << endl;
	}
	else if (input == "Job Title" || input == "job title" || input == "Job title")
	{
		cout << "\nCurrent Job Title: " << candidates.at(i).getJobTitle() << "-> New Job Title: ";
		getline(cin, input);
		candidates.at(i).setJobTitle(input);
		cout << "\nJob Title succefully updated to " << candidates.at(i).getJobTitle() << ". " << endl;
	}
	else if (input == "Location" || input == "location")
	{
		cout << "\nCurrent Location: " << candidates.at(i).getLocation() << "-> New Location: ";
		getline(cin, input);
		candidates.at(i).setLocation(input);
		cout << "\nLocation succefully updated to " << candidates.at(i).getLocation() << ". " << endl;
	}
	else if (input == "Phone Number" || input == "phone number" || input == "Phone number" || input == "phone")
	{
		cout << "\nCurrent Phone Number: " << candidates.at(i).getPhoneNumber() << "-> New Phone Number: ";
		getline(cin, input);
		candidates.at(i).setPhoneNumber(input);
		cout << "\nPhone Number succefully updated to " << candidates.at(i).getPhoneNumber() << ". " << endl;
	}
	else if (input == "Email" || input == "email" || input == "Email address" || input == "email address")
	{
		cout << "\nCurrent Email Address: " << candidates.at(i).getEmail() << "-> New Email Address: ";
		getline(cin, input);
		candidates.at(i).setEmail(input);
		cout << "\nEmail succefully updated to " << candidates.at(i).getEmail() << ". " << endl;
	}
	else if (input == "Q" || input == "q")
	{
		clearScreen();
		return;
	}
	else
	{
		cout << "Please enter a valid field: [ First Name, Last Name, Job Title, Location, Phone number, Email ]" << endl;
		getline(cin, input);
		clearScreen();
		updateDetails(candidates, i);
	}
	cout << "\nDo you want to update anything else? Y/N ";
	getline (cin, input);
	if (input == "Y" || input == "y" || input == "Yes" || input == "yes")
		updateDetails(candidates, i);
	clearScreen();
}

string center(string input, int width) { 
    return (string((width - input.length()) / 2, ' ') + input);
}

void printDetails(vector <Applicant> &candidates, int i)
{
	cout << "First Name:    " << candidates.at(i).getFirstName() << endl;
	cout << "Last Name:     " << candidates.at(i).getLastName() << endl;
	cout << "Job Title:     " << candidates.at(i).getJobTitle() << endl;
	cout << "Location:      " << candidates.at(i).getLocation() << endl;
	cout << "Phone Number:  " << candidates.at(i).getPhoneNumber() << endl;
	cout << "Email Address: " << candidates.at(i).getEmail() << endl;
}

void details(vector <Applicant> &candidates, int i)
{
	string input{};
	clearScreen();
	printHeader();
	printLine(DEFAULT_LINE_CHAR);
	cout << center("Candidate Details", PROGRAM_WIDTH) << endl;
	printLine(DEFAULT_LINE_CHAR);
	cout << endl;
	printDetails(candidates, i);
	cout << endl;
	cout << "U - Update \tQ - Quit" << endl;
	getline (cin, input);
	if (input == "u" || input == "U")
		updateDetails(candidates, i);
	else if (input == "q" || input == "Q")
		clearScreen();
	else
	{
		cout << "Please enter valid input: [ U, Q ]";
		getline (cin, input);
		clearScreen();
		details(candidates, i);
	}
}

void printList(vector <Applicant> &candidates)
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
		cout << "Enter Candidate Index for Details: ";
		getline (cin, input);
		if (isdigit(input[0]))
		{
			index = stoi(input);
			if (index > 0 && index <= static_cast<int>(candidates.size()))
				details(candidates, index - 1);
			else
			{
				cout << "\nPlease enter a valid Index!" << endl;
				getline (cin, pause);
				cout << "TEST " << pause[0];
				cin >> pause;
				if (pause[0] != 27)
					listCandidates(candidates);
			}
		}
		else if (input[0] == 'q' || input[0] == 'Q')
			clearScreen();
		else
		{
			cout << "\nPlease enter a valid Index!" << endl;
			getline (cin, pause);
			cout << "TEST " << pause[0];
			if (pause[0] != 27)
				listCandidates(candidates);
		}
	}
	else
	{
		cout << "List is empty! - Add candidates first, thank you!\n";
		getline (cin, pause);
		clearScreen();
	}
}

void listCandidates(vector <Applicant> &candidates)
{
	clearScreen();
	printHeader();
	printLine(DEFAULT_LINE_CHAR);
	cout << center("Candidates", PROGRAM_WIDTH) << endl;
//	cout << "D - Details\tU - Update\tQ - Quit" << endl;
	printLine(DEFAULT_LINE_CHAR);
	cout << endl;
	printList(candidates);
}

Applicant newCandidate(void)
{
	clearScreen();
	string input;
	Applicant newCandidate;

	printHeader();
	printLine(DEFAULT_LINE_CHAR);
	cout << center("New Candidate", PROGRAM_WIDTH) << endl;
	printLine(DEFAULT_LINE_CHAR);
	cout << endl;
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
	clearScreen();
	return (newCandidate);
}

//void preferences(void)
//{
//	cout << "pref";
//	PROGRAM_WIDTH = 120;
//	return ;
//}

void search(vector <Applicant> candidates)
{
	string search {};
	vector <int> results;
	int i {0};
	string firstName {};
	string lastName {};
	string jobTitle {};
	string location {};
	string phone {};
	string email {};
	
	clearScreen();
	printHeader();
	printLine(DEFAULT_LINE_CHAR);
	cout << center("Search", PROGRAM_WIDTH) << endl;
	printLine(DEFAULT_LINE_CHAR);
	cout << endl;
	cout << "What are you looking for? ";
	getline(cin, search);
	for (auto applicant: candidates) // need to add to_lower conversion + nice layout
	{
		if (applicant.getFirstName().find(search) != string::npos)
			results.push_back(i);
		else if (applicant.getLastName().find(search) != string::npos)
			results.push_back(i);
		else if (applicant.getJobTitle().find(search) != string::npos)
			results.push_back(i);
		else if (applicant.getLocation().find(search) != string::npos)
			results.push_back(i);
		else if (applicant.getPhoneNumber().find(search) != string::npos)
			results.push_back(i);
		else if (applicant.getEmail().find(search) != string::npos)
			results.push_back(i);
		i++;
	}
	if (!results.empty())
	{
		cout << endl << results.size() << " result(s) found: " << endl << endl;
		cout << "Index\t|First Name     |Last Name      |Job Title         |Location          |Phone Number   |Email Address       " << endl;
		for (int index: results)
		{
			firstName = candidates.at(index).getFirstName();
			lastName = candidates.at(index).getLastName();
			jobTitle = candidates.at(index).getJobTitle();
			location = candidates.at(index).getLocation();
			phone = candidates.at(index).getPhoneNumber();
			email = candidates.at(index).getEmail();
			firstName.resize(15, ' ');
			lastName.resize(15, ' ');
			jobTitle.resize(18, ' ');
			location.resize(18, ' ');
			phone.resize(15, ' ');
			email.resize(25, ' ');
			cout << index << "\t|" << firstName << "|" << lastName << "|" << jobTitle << "|" 
				<< location << "|" << phone << "|" << email << endl;
		}
	}
	else
		cout << "No results found!" << endl;
	getline(cin, search);
	clearScreen();
}

void clearScreen(void)
{
	system("CLS"); // maybe I could dedect which OS is and use if/else
}

int main()
{
	string input;
	vector <Applicant> candidates {};
	do
	{
		printHeader();
		printLine(DEFAULT_LINE_CHAR);
		cout << center("Main menu", PROGRAM_WIDTH) << endl;
		printLine(DEFAULT_LINE_CHAR);
		cout << " N - New Applicant \tL - List Applicants \tS - Search \tZ - Clear screen"; // not ideal for resizing, vector with menu links
		cout << "\tD - Delete List \tP - Preferences \tI - Imprint \tQ - Quit " << endl;
		printLine(DEFAULT_LINE_CHAR);
		cout << endl;
		cout << "What do you wanna do?: ";
		getline (cin, input);
		cout << endl;

		if (input == "N" || input == "n")
		{
			Applicant newApplicant;
			newApplicant = newCandidate();
			candidates.push_back(newApplicant);
		}
		else if (input == "L" || input == "l")
			listCandidates(candidates);
		else if (input == "S" || input == "s")
			search(candidates);
		else if (input == "D" || input == "d")
		{
			candidates.clear();
			clearScreen();
		}
		else if (input == "Z" || input == "z")
			clearScreen();
		else if (input == "P" || input == "p")
			;
		else if (input == "I" || input == "i")
			imprint();
		else if (input == "Q" || input == "q")
			cout << "Thank you for using S-ATS! See you soon!" << endl;
		else
		{
			cout << "Please enter a valid input  [N, L, S, Z, D, I, Q]" << endl;
			getline (cin, input);
			clearScreen();			
		}
	} while (input != "Q" && input != "q");
	return (0);
}