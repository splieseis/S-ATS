#include "S-ATS.hpp"

void printHeader(string menuTitle, Settings &settings)
{
	int width = settings.getProgramWidth();
	clearScreen();
	for (int i {0}; i < width - static_cast <int> (settings.getFilename().size()); i++)
		cout << " ";
	cout << settings.getFilename() << endl;
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