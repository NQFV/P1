#pragma once

#include <iostream>
#include "FileDate.h"


struct FileData 
{
	std::string name;
	Date creation_date;
	int size;

	void SetName(const std::string name);
	std::string GetName() const;

	void SetCreationDate(const Date date);
	Date GetCreationDate() const;

	void SetSize(const int size);
	int GetSize() const;

	void ReadFileData(std::istream& in);
	void WriteFileData(std::ostream& out = std::cout) const;

	static bool ValidateName(const std::string& name);
	static void InvalidName(const std::string& name);

	static bool ValidateSize(const int& size);
	static void InvalidSize(const int& size);

	FileData(const std::string& name, const Date& creation_date, const int& size);
	FileData() : name(""), creation_date(), size() {}
};
