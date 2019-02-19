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


/* Global vars (soon replaced) */

using namespace std;
const int PROGRAM_WIDTH = 171;
const char DEFAULT_LINE_CHAR = '~';
const char DEFAULT_CSV_CHAR = ';';
const std::string DEFAULT_FILENAME = "candidates";


/* Function Prototypes */

/* main.cpp */

void readCandidates(std::vector <Applicant> &candidates);
void exeMainMenu(std::vector <Applicant> &candidates);
void saveCandidates(const std::vector <Applicant> &candidates);

/* pageHeaders.cpp */

void printHeader(std::string menuTitle);

/* mainFunctions.cpp */

void imprint();
void details(std::vector <Applicant> &candidates, int i);
void listCandidates(std::vector <Applicant> &candidates);
void printList(std::vector <Applicant> &candidates);
void printDetails(std::vector <Applicant> &candidates, int i);
Applicant newCandidate(void);
std::vector <size_t> getDeliminatorPos(const std::string line);
void search(std::vector <Applicant> candidates);

/* utilities.cpp */

std::string center(std::string input, int width);
void printLine(char c);
void clearScreen(void);
std::string keyGenerator(void);
std::string encryption(std::string str, std::string key);
std::string decryption(std::string str, std::string key);

#endif