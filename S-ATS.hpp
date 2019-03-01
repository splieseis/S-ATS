#ifndef S_ATS_HPP
# define S_ATS_HPP

/* Libraries */

# include <iostream>
# include <iomanip>
# include <vector>
# include <string>
# include <locale>
# include <fstream>
# include <cstdlib>
# include <time.h>


/* Header files */

# include "Applicant.class.hpp"
# include "Settings.class.hpp"

using namespace std;

/* Function Prototypes */

/* main.cpp */

void readCandidates(std::vector <Applicant> &candidates, Settings &settings);
void exeMainMenu(std::vector <Applicant> &candidates, Settings &settings);
void saveCandidates(const std::vector <Applicant> &candidates, Settings &settings);

/* pageHeaders.cpp */

void printHeader(std::string menuTitle, Settings &settings);

/* mainFunctions.cpp */

void imprint(Settings &settings);
void details(std::vector <Applicant> &candidates, Settings &settings, int i);
void updateDetails(vector <Applicant> &candidates, Settings &settings, int i);
void listCandidates(std::vector <Applicant> &candidates, Settings &settings);
void printList(std::vector <Applicant> &candidates, Settings &settings);
void printDetails(std::vector <Applicant> &candidates, int i);
Applicant newCandidate(Settings &settings);
std::vector <size_t> getDeliminatorPos(const std::string line, char c);
void search(std::vector <Applicant> candidates, Settings &settings);
void deleteCandidate(vector <Applicant> &candidates, int i);
void printSettings(Settings &settings);
void preferences(Settings &settings);
void updateSettings(Settings &settings);
void defaultSettings(Settings &settings, std::string selection);
void saveSettings(Settings &settings);
void readSettings(Settings &settings);
void initDelimiter(std::string line, Settings &settings);
void saveAs(vector <Applicant> &candidates, Settings &settings);
int multiFieldSearch(Applicant &applicant, string input);

/* utilities.cpp */

vector <std::string> splitWords(std::string &input, char del);
vector <size_t> getDelimiterPos(const std::string line, char c);
std::string center(std::string input, int width);
void printLine(Settings &settings);
void clearScreen(void);
std::string keyGenerator(void);
std::string encryption(std::string str, std::string key, Settings &settings);
std::string decryption(std::string str, std::string key, Settings &settings);
string lowerString(string input);
bool askSaveChanges(void);

/* checkFunctions.cpp */

bool check(std::string input, std::string selection);
bool checkInt(std::string input);

#endif