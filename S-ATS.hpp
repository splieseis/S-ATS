#ifndef S_ATS_HPP
# define S_ATS_HPP

/* Libraries */

# include <iostream>
# include <vector>
# include <string>
# include <locale>
# include <fstream>
# include <cstdlib>
# include <time.h>


/* Header files */

# include "Applicant.class.hpp"
# include "Settings.class.hpp"

/* Global vars (soon replaced) */

using namespace std;
const char DEFAULT_CSV_CHAR = ';';
const std::string DEFAULT_FILENAME = "candidates";


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
std::vector <size_t> getDeliminatorPos(const std::string line);
void search(std::vector <Applicant> candidates, Settings &settings);
void deleteCandidate(vector <Applicant> &candidates, int i);

/* utilities.cpp */

std::string center(std::string input, int width);
void printLine(Settings &settings);
void clearScreen(void);
std::string keyGenerator(void);
std::string encryption(std::string str, std::string key, Settings &settings);
std::string decryption(std::string str, std::string key, Settings &settings);

/* checkFunctions.cpp */

bool check(std::string input, std::string selection);

#endif