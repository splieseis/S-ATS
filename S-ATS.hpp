#ifndef S_ATS_HPP
# define S_ATS_HPP
# include "Applicant.class.hpp"

const int PROGRAM_WIDTH = 171;
const char DEFAULT_LINE_CHAR = '~';
const char DEFAULT_CVS_CHAR = ';';

/* Function Prototypes */

void printHeader();
void imprint();
void details(std::vector <Applicant> &candidates, int i);
void listCandidates(std::vector <Applicant> &candidates);
void printList(std::vector <Applicant> &candidates);
void printDetails(std::vector <Applicant> &candidates, int i);
Applicant newCandidate(void);
std::string center(std::string input, int width);
void printLine(char c);
void clearScreen(void);

#endif