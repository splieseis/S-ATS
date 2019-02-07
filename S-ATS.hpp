#ifndef S_ATS_HPP
# define S_ATS_HPP
# include "Applicant.class.hpp"

/* Function Prototypes */

void printHeader();
void imprint();
void details(std::vector <Applicant> candidates, int i);
void listCandidates(std::vector <Applicant> candidates);
void printList(std::vector <Applicant> candidates);
Applicant newCandidate(void);

#endif