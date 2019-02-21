#ifndef SETTINGS_CLASS_HPP
# define SETTINGS_CLASS_HPP

class Settings
{
public:
	Settings();
	~Settings();

	void setProgramWidth(int width);
	void setLineChar(char c);
	void setEncryption(bool stage);
	void setFilename(std::string name);
	
	int getProgramWidth(void);
	char getLineChar(void);
	bool getEncryption(void);
	std::string getFilename(void);

private:
	int _PROGRAM_WIDTH;
	char _LINE_CHAR;
	bool _ENCRYPTION;
	std::string _FILENAME;
};

#endif // SETTINGS_CLASS_HPP
