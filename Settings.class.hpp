#ifndef SETTINGS_CLASS_HPP
# define SETTINGS_CLASS_HPP

class Settings
{
public:
	Settings();
	~Settings();

	void		setProgramWidth(int width);
	void		setLineChar(char c);
	void		setEncryption(bool stage);
	void		setFilename(std::string name);
	void		setCsvDelimiter(char c);
	void		setVersionControl(bool stage);

	int			getProgramWidth(void);
	char		getLineChar(void);
	bool		getEncryption(void);
	std::string	getFilename(void);
	char		getCsvDelimiter(void);
	bool		getVersionControl(void);
	
private:
	int			_PROGRAM_WIDTH;
	char		_LINE_CHAR;
	bool		_ENCRYPTION;
	std::string	_FILENAME;
	char		_CSV_DELIMITER;
	bool		_VERSION_CONTROL;
};

#endif // SETTINGS_CLASS_HPP
