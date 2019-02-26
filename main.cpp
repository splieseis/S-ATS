#include "S-ATS.hpp"

int main()
{
	vector <Applicant> candidates {};
	Settings settings {};

	readSettings(settings);
	readCandidates(candidates, settings);
	exeMainMenu(candidates, settings);
	saveCandidates(candidates, settings);
	saveSettings(settings);
	return (0);
}