#include "S-ATS.hpp"

int main()
{
	vector <Applicant> candidates {};
	
	readCandidates(candidates);
	exeMainMenu(candidates);
	saveCandidates(candidates);
	return (0);
}