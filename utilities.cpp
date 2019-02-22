#include "S-ATS.hpp"

string encryption(string str, string key, Settings &settings)
{
	string ascii {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ! 0123456789?^$%&/()#=*+-~@`_{}[]\\|\'"};
	size_t i {0};
	size_t index {0};
	if (settings.getEncryption())
	{
		for (char c: str)
		{
			i = ascii.find(c);
			if (i != string::npos)
				str.at(index) = key.at(i);
			index++;
		}
	}
	return (str);
}

string decryption(string str, string key, Settings &settings)
{
	string ascii {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ! 0123456789?^$%&/()#=*+-~@`_{}[]\\|\'"};
	size_t i {0};
	size_t index {0};
	
	if (settings.getEncryption())
	{
		for (char c: str)
		{
			i = key.find(c);
			if (i != string::npos)
				str.at(index) = ascii.at(i);
			index++;
		}
	}
	return (str);
}

string keyGenerator(void)
{
	string ascii {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ! 0123456789?^$%&/()#=*+-~@`_{}[]\\|\'"};
	int num1 {0};
	int num2 {0};
	int i {0};
	int max {0};
	
	srand (time(NULL));
	max = ascii.size();
	while (i < 1000)
	{
		num1 = rand() % max;
		num2 = rand() % max;
		swap(ascii[num1], ascii[num2]);
		i++;
	}
	return (ascii);
}

void printLine(Settings &settings)
{
	int i;
	int max = settings.getProgramWidth();
	for (i = 0; i < max; i++)
		cout << settings.getLineChar();
	cout << endl;
}

string center(string input, int width) { 
    return (string((width - input.length()) / 2, ' ') + input);
}

void clearScreen(void)
{
	system("CLS"); // maybe I could dedect which OS is and use if/else
}