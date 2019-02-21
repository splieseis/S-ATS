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
	
	int getProgramWidth(void);
	char getLineChar(void);
	bool getEncryption(void);

private:
	int _PROGRAM_WIDTH;
	char _LINE_CHAR;
	bool _ENCRYPTION;
};

#endif // SETTINGS_CLASS_HPP
