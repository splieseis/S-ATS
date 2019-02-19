#include "S-ATS.hpp"

void printHeader(string menuTitle)
{
	clearScreen();
	printLine(' ');
	cout << center("*****         ***     *********  *****", PROGRAM_WIDTH)<< endl;
	cout << center("**           ** **    *********  **   ", PROGRAM_WIDTH)<< endl;
	cout << center("*****  ***  *******      ***     *****", PROGRAM_WIDTH)<< endl;
	cout << center("   **      ***   ***     ***        **", PROGRAM_WIDTH)<< endl;
	cout << center("*****     ***     ***    ***     *****", PROGRAM_WIDTH)<< endl;
	printLine(' ');
	printLine(DEFAULT_LINE_CHAR);
	cout << center(menuTitle, PROGRAM_WIDTH) << endl;
	printLine(DEFAULT_LINE_CHAR);
	
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