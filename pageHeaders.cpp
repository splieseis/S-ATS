#include "S-ATS.hpp"

void printHeader(string menuTitle, Settings &settings)
{
	int width = settings.getProgramWidth();
	clearScreen();
	cout << endl;
	cout << center("*****         ***     *********  *****", width)<< endl;
	cout << center("**           ** **    *********  **   ", width)<< endl;
	cout << center("*****  ***  *******      ***     *****", width)<< endl;
	cout << center("   **      ***   ***     ***        **", width)<< endl;
	cout << center("*****     ***     ***    ***     *****", width)<< endl;
	cout << endl;
	printLine(settings);
	cout << center(menuTitle, width) << endl;
	printLine(settings);
	
/*		cout << "------------------------------------------------------------------------------------" << endl;
		cout << "-                      *****           *      ********* *****                      -" << endl;
		cout << "-                      ** **          ***     ********* ** **                      -" << endl;
		cout << "-                      **            ** **       ***    **                         -" << endl;
		cout << "-                      *****  ***   **   **      ***    *****                      -" << endl;
		cout << "-                         **  ***  *********     ***       **                      -" << endl;
		cout << "-                      ** **      ***     ***    ***    ** **                      -" << endl;
		cout << "-                      *****     ***       ***   ***    *****                      -" << endl;
		cout << "------------------------------------------------------------------------------------" << endl;
*/
}