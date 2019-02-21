#include "S-ATS.hpp"

void initSettings(Settings &settings)
{
	settings.setProgramWidth(171);
	settings.setLineChar('~');
	settings.setEncryption(false);
}

int main()
{
	vector <Applicant> candidates {};
	Settings settings {};
	
	initSettings(settings);
	readCandidates(candidates, settings);
	exeMainMenu(candidates, settings);
	saveCandidates(candidates, settings);
	return (0);
}