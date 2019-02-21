#include "S-ATS.hpp"

void imprint(Settings &settings)
{
	string pause {};
	
	clearScreen();
	printHeader("Imprint", settings);
	cout << endl;
	cout << "Thank you for using Simon's Applicant Tracking System! (c) Simon Plieseis 2019" << endl;
	getline (cin, pause);
	clearScreen();
}

void updateDetails(vector <Applicant> &candidates, Settings &settings, int i)
{
	string input {};
	
	clearScreen();
	printHeader("Update Candidate Details", settings);
	cout << endl;
	printDetails(candidates, i);
	cout << endl;
	cout << "What do you want to update? ";
	getline (cin, input);
	if (check(input, "FIRST_NAME"))
	{
		cout << "\nCurrent First Name: " << candidates.at(i).getFirstName() << "-> New First Name: ";
		getline(cin, input);
		candidates.at(i).setFirstName(input);
		cout << "\nFirst Name succefully updated to " << candidates.at(i).getFirstName() << ". " << endl;
	}
	else if (check(input, "LAST_NAME"))
	{
		cout << "\nCurrent Last Name: " << candidates.at(i).getLastName() << "-> New Last Name: ";
		getline(cin, input);
		candidates.at(i).setLastName(input);
		cout << "\nLast Name succefully updated to " << candidates.at(i).getLastName() << ". " << endl;
	}
	else if (check(input, "JOB"))
	{
		cout << "\nCurrent Job Title: " << candidates.at(i).getJobTitle() << "-> New Job Title: ";
		getline(cin, input);
		candidates.at(i).setJobTitle(input);
		cout << "\nJob Title succefully updated to " << candidates.at(i).getJobTitle() << ". " << endl;
	}
	else if (check(input, "LOCATION"))
	{
		cout << "\nCurrent Location: " << candidates.at(i).getLocation() << "-> New Location: ";
		getline(cin, input);
		candidates.at(i).setLocation(input);
		cout << "\nLocation succefully updated to " << candidates.at(i).getLocation() << ". " << endl;
	}
	else if (check(input, "PHONE"))
	{
		cout << "\nCurrent Phone Number: " << candidates.at(i).getPhoneNumber() << "-> New Phone Number: ";
		getline(cin, input);
		candidates.at(i).setPhoneNumber(input);
		cout << "\nPhone Number succefully updated to " << candidates.at(i).getPhoneNumber() << ". " << endl;
	}
	else if (check(input, "EMAIL"))
	{
		cout << "\nCurrent Email Address: " << candidates.at(i).getEmail() << "-> New Email Address: ";
		getline(cin, input);
		candidates.at(i).setEmail(input);
		cout << "\nEmail succefully updated to " << candidates.at(i).getEmail() << ". " << endl;
	}
	else if (check(input, "QUIT"))
	{
		clearScreen();
		return;
	}
	else
	{
		cout << "\nPlease enter a valid field: [ First Name, Last Name, Job Title, Location, Phone number, Email ]" << endl;
		getline(cin, input);
		clearScreen();
		updateDetails(candidates, settings, i);
	}
	cout << "\nDo you want to update anything else? ";
	getline (cin, input);
	if (check(input, "YES"))
		updateDetails(candidates, settings, i);
	clearScreen();
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

void deleteCandidate(vector <Applicant> &candidates, int i)
{
	string input {};
	candidates.erase(candidates.begin() + i);
	cout << "\nDeleting candidate...";
	getline(cin, input);
}

void details(vector <Applicant> &candidates, Settings &settings, int i)
{
	string input{};
	clearScreen();
	printHeader("Candidate Details", settings);
	cout << endl;
	printDetails(candidates, i);
	cout << endl;
	cout << "U - Update \tD - Delete \tQ - Quit" << endl << endl;
	getline (cin, input);
	if (check(input, "UPDATE"))
		updateDetails(candidates, settings, i);
	else if (check(input, "DELETE"))
		deleteCandidate(candidates, i);
	else if (check(input, "QUIT"))
		clearScreen();
	else
	{
		cout << "Please enter a valid input: [ U, D, Q ]";
		getline (cin, input);
		clearScreen();
		details(candidates, settings, i);
	}
}

void printList(vector <Applicant> &candidates, Settings &settings)
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
				details(candidates, settings, index - 1);
			else
			{
				cout << "\nPlease enter a valid Index!" << endl;
				getline (cin, pause);
				listCandidates(candidates, settings);
			}
		}
		else if (check(input, "QUIT"))
			clearScreen();
		else
		{
			cout << "\nPlease enter a valid Index!" << endl;
			getline (cin, pause);
			listCandidates(candidates, settings);
		}
	}
	else
	{
		cout << "List is empty! - Add candidates first, thank you!\n";
		getline (cin, pause);
		clearScreen();
	}
}

void listCandidates(vector <Applicant> &candidates, Settings &settings)
{
	clearScreen();
	printHeader("Candidates", settings);
	cout << endl;
	printList(candidates, settings);
}

Applicant newCandidate(Settings &settings)
{
	string input;
	Applicant newCandidate;

	printHeader("New Candidate", settings);
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

void search(vector <Applicant> candidates, Settings &settings)
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
	
	printHeader("Search", settings);
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

vector <size_t> getDeliminatorPos(const string line)
{
	vector <size_t> deliminatorPos {};
	size_t pos {0};
	size_t len = line.size();
	deliminatorPos.push_back(0);
	while (pos < len)
	{
		if (line.at(pos) == DEFAULT_CSV_CHAR)
			deliminatorPos.push_back(pos);
		pos++;
	}
	return (deliminatorPos);
}

void readCandidates(vector <Applicant> &candidates, Settings &settings)
{
	string path {"data\\"};
	string name {};
	string fileExtension {".csv"};
	string line {};
	string key {};
	ifstream myfile;
	vector <size_t> deliminatorPos {};

	printHeader("HOME", settings);
	cout << "\nFilename: ";
	getline(cin, name);
	name.empty() ? name = DEFAULT_FILENAME : name = name;
	myfile.open (path + name + fileExtension);
	if (myfile.is_open())
	{
		if (settings.getEncryption())
			getline(myfile, key);
		getline(myfile, line); // to skip the header line
		while(getline(myfile, line))
		{
			Applicant newCandidate;
 			deliminatorPos = getDeliminatorPos(line);
			newCandidate.setFirstName(decryption(line.substr(deliminatorPos.at(0), (deliminatorPos.at(1) - deliminatorPos.at(0))), key, settings));
			newCandidate.setLastName(decryption(line.substr(deliminatorPos.at(1) + 1, (deliminatorPos.at(2) - 1 - deliminatorPos.at(1))), key, settings));
			newCandidate.setJobTitle(decryption(line.substr(deliminatorPos.at(2) + 1, (deliminatorPos.at(3) - 1 - deliminatorPos.at(2))), key, settings));
			newCandidate.setLocation(decryption(line.substr(deliminatorPos.at(3) + 1, (deliminatorPos.at(4) - 1 - deliminatorPos.at(3))), key, settings));
			newCandidate.setPhoneNumber(decryption(line.substr(deliminatorPos.at(4) + 1, (deliminatorPos.at(5) - 1 - deliminatorPos.at(4))), key, settings));
			newCandidate.setEmail(decryption(line.substr(deliminatorPos.at(5) + 1, (line.size() - deliminatorPos.at(5))), key, settings));
			candidates.push_back(newCandidate);
		}
		myfile.close();
	}
	else 
		cout << "Unable to open the file!\n";
}

void saveCandidates(const vector <Applicant> &candidates, Settings &settings)
{
	string input {};
	
	cout << endl << "Do you want to save your changes? Y/N" << endl;
	getline(cin, input);
	while (!check(input, "YES") && !check(input, "NO"))
	{
		cout << endl << "Do you want to save your changes? Y/N" << endl;
		getline(cin, input);
	}
	if (check(input, "YES"))
	{
		string path {"data\\"};
		string name {};
		string fileExtension {".csv"};
		string key = keyGenerator();
		ofstream myfile;
		
		cout << "Filename: ";
		getline(cin, name);
		name.empty() ? name = DEFAULT_FILENAME : name = name;
		myfile.open (path + name + fileExtension);
		if (myfile.is_open())
		{	
			cout << endl << "Saving Candidates...";
			if (settings.getEncryption())
				myfile << key + "\n";
			myfile << encryption("First Name", key, settings) + DEFAULT_CSV_CHAR + encryption("Last Name", key, settings) + DEFAULT_CSV_CHAR + encryption("Job Title", key, settings) + DEFAULT_CSV_CHAR
					+ encryption("Location", key, settings) + DEFAULT_CSV_CHAR + encryption("Phone Number", key, settings) + DEFAULT_CSV_CHAR + encryption("Email Address", key, settings) + "\n";
			for (auto applicant: candidates)
			{
				myfile << 
				  encryption(applicant.getFirstName(), key, settings) + DEFAULT_CSV_CHAR 
				+ encryption(applicant.getLastName(), key, settings) + DEFAULT_CSV_CHAR 
				+ encryption(applicant.getJobTitle(), key, settings) + DEFAULT_CSV_CHAR 
				+ encryption(applicant.getLocation(), key, settings) + DEFAULT_CSV_CHAR 
				+ encryption(applicant.getPhoneNumber(), key, settings) + DEFAULT_CSV_CHAR 
				+ encryption(applicant.getEmail(), key, settings) + "\n";
			}
			myfile.close();
		}
		else
		{
			cout << "Another program is currently using this file! Please close it first and then press Enter to save.\n";
			string pause {};
			getline(cin, pause);
			saveCandidates(candidates, settings);
		}
	}
	else
		cout << "Changes discarded!";
}

void printSettings(Settings &settings)
{
	cout << "Program Width: [ " << settings.getProgramWidth() << " ]\n";
	cout << "Line char:     [ " << settings.getLineChar() << " ]\n";
	if (settings.getEncryption())
		cout << "Encryption: [ ON ]\n";
	else
		cout << "Encryption: [ OFF ]\n";
}

void preferences(Settings &settings)
{
	string input {};
//	int num;
	
	printHeader("Settings", settings);
	cout << endl;
	printSettings(settings);
	cout << endl;
	cout << "U - Update \tD - Default \tQ - Quit" << endl << endl;
	getline(cin, input);
	if (input == "on")
		settings.setEncryption(true);
	else if (input == "off")
		settings.setEncryption(false);
//	cout << "Program Width: " << settings.getProgramWidth();
//	getline(cin, input);
//	if (isdigit(input[0]))
//	{
//		num = stoi(input);
//		if (num && 38 <= num && num <= 171)
//			settings.setProgramWidth(num);
//		else
//		{
//			cout << "Please enter a program width from [ 38 - 171 ]";
//			getline(cin, input);
//		}
//		cout << "Line char: " << settings.getLineChar();
//		getline(cin, input);
//		settings.setLineChar(input[0]);
//		getline(cin, input);
//	}
}

void exeMainMenu(vector <Applicant> &candidates, Settings &settings)
{
	string input {};
	do
	{
		printHeader("Main Menu", settings);
		cout << " N - New Applicant \tL - List Applicants \tSearch - Search \tZ - Clear screen"; // not ideal for resizing, vector with menu links
		cout << "\tS - Settings \tI - Imprint \tQ - Quit " << endl;
		printLine(settings);
		cout << endl;
		cout << "What do you wanna do?: ";
		getline (cin, input);
		cout << endl;
		if (check(input, "NEW"))
		{
			Applicant newApplicant;
			newApplicant = newCandidate(settings);
			candidates.push_back(newApplicant);
		}
		else if (check(input, "LIST"))
			listCandidates(candidates, settings);
		else if (check(input, "SEARCH"))
			search(candidates, settings);
		else if (input == "Z" || input == "z")
			clearScreen();
		else if (check(input, "SETTINGS"))
			preferences(settings);
		else if (check(input, "IMPRINT"))
			imprint(settings);
		else if (check(input, "QUIT"))
			cout << "Thank you for using S-ATS! See you soon!" << endl;
		else
		{
			cout << "Please enter a valid input  [N, L, S, Z, P, I, Q]" << endl;
			getline (cin, input);
			clearScreen();
		}
	} while (!check(input, "QUIT"));
}