#include "S-ATS.hpp"

int main()
{
	vector <Applicant> candidates {};
	Settings settings {};

	readSettings(settings);
	readCandidates(candidates, settings);
	savePreviousVersion(candidates, settings);
	exeMainMenu(candidates, settings);
	if (askSaveChanges())
		saveCandidates(candidates, settings);
	saveSettings(settings);
	return (0);
}