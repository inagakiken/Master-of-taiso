#pragma once
#include "inputbase.h"
#include <fstream>

class InputModel :
	public InputBase
{
private:
	//std::string fileName;
	std::vector<Skeleton> model;

public:
	InputModel(void);
	InputModel(std::string tempFileName);
	~InputModel(void);

	//void changeFile(std::string tempFileName);
	void readFile(std::string tempFileName);
	void writeFile(std::string tempFileName, Skeleton** skeleton);
};

