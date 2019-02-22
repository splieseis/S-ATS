#include "S-ATS.hpp"

bool checkInt(string input)
{
	if (isdigit(input[0]))
		return (true);
	return (false);
}

bool check(string input, string selection)
{
	if (selection == "YES")
	{
		if (input == "Y" || input == "y" || input == "Yes" || input == "YES" || input == "yes")
			return (true);
	}
	else if (selection == "NO")
	{
		if (input == "N" || input == "n" || input == "No" || input == "NO" || input == "no")
			return (true);
	}
	else if (selection == "ON")
	{
		if (input == "On" || input == "on" || input == "ON")
			return (true);
	}
	else if (selection == "NEW")
	{
		if (input == "N" || input == "n" || input == "New" || input == "NEW" || input == "new")
			return (true);
	}
	else if (selection == "LIST")
	{
		if (input == "L" || input == "l" || input == "List" || input == "LIST" || input == "list")
			return (true);
	}
	else if (selection == "SEARCH")
	{
		if (input == "Search" || input == "SEARCH" || input == "search")
			return (true);
	}
	else if (selection == "DELETE")
	{
		if (input == "D" || input == "d" || input == "Delete" || input == "DELETE" || input == "delete")
			return (true);
	}
	else if (selection == "SETTINGS")
	{
		if (input == "P" || input == "p" || input == "Settings" || input == "SETTINGS" || input == "settings") // P later for print
			return (true);
	}
	else if (selection == "IMPRINT")
	{
		if (input == "I" || input == "i" || input == "Imprint" || input == "IMPRINT" || input == "imprint")
			return (true);
	}
	else if (selection == "QUIT")
	{
		if (input == "Q" || input == "q" || input == "Quit" || input == "QUIT" || input == "quit" || input == "Exit" || input == "exit")
			return (true);
	}
	else if (selection == "FIRST_NAME")
	{
		if (input == "First name" || input == "first name" || input == "First Name" || input == "fn" || input == "FN")
			return (true);
	}
	else if (selection == "LAST_NAME")
	{
		if (input == "Last name" || input == "last name" || input == "Last Name" || input == "ln" || input == "LN")
			return (true);
	}
	else if (selection == "JOB")
	{
		if (input == "Job title" || input == "job title" || input == "Job Title" || input == "job" || input == "Job" || input == "j")
			return (true);
	}
	else if (selection == "LOCATION")
	{
		if (input == "Location" || input == "location" || input == "LOCATION" || input == "l" || input == "L")
			return (true);
	}
	else if (selection == "PHONE")
	{
		if (input == "Phone" || input == "phone" || input == "PHONE" || input == "Phone number" || input == "Phone Number" || input == "number")
			return (true);
	}
	else if (selection == "EMAIL")
	{
		if (input == "Email" || input == "email" || input == "Email address" || input == "Email Address" || input == "e" || input == "E")
			return (true);
	}
	else if (selection == "UPDATE")
	{
		if (input == "U" || input == "u" || input == "Update" || input == "update" || input == "UPDATE")
			return (true);
	}
	else if (selection == "PROGWIDTH")
	{
		if (input == "Prog width" || input == "prog width" || input == "width" || input == "Width" || input == "w" || input == "W")
			return (true);
	}
	else if (selection == "LINECHAR")
	{
		if (input == "Line char" || input == "line char" || input == "line" || input == "Line" || input == "l" || input == "L")
			return (true);
	}
	else if (selection == "ENCRYPTION")
	{
		if (input == "Encryption" || input == "encryption" || input == "e" || input == "E")
			return (true);
	}
	else if (selection == "DELIMITER")
	{
		if (input == "Delimiter" || input == "delimiter" || input == "d" || input == "D" || input == "delim" || input == "csv" || input == "CSV")
			return (true);
	}
	else if (selection == "DEFAULT")
	{
		if (input == "Default" || input == "default" || input == "d" || input == "D")
			return (true);
	}
	return (false);
}