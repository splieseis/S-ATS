#include "S-ATS.hpp"

int main()
{
	vector <Applicant> candidates {};
	Settings settings {};

	readSettings(settings);
	readCandidates(candidates, settings);
	exeMainMenu(candidates, settings);
	if (askSaveChanges())
		saveCandidates(candidates, settings);
	else
	saveSettings(settings);
	return (0);
}