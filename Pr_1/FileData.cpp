#pragma once

#include <iostream>
#include <string>
#include "FileData.h"
#include "FileDate.h"

void FileData::SetName(const std::string name)
{
	this->name = name;
}

std::string FileData::GetName() const
{
	return name;
}

void FileData::SetCreationDate(const Date creation_date)
{
	this->creation_date = creation_date;
}

Date FileData::GetCreationDate() const
{
	return creation_date;
}

void FileData::SetSize(const int size)
{
	this->size = size;
}

int FileData::GetSize() const
{
	return size;
}

void FileData::ReadFileData(std::istream& in)
{
	std::string input_name;
	if (std::getline(in, input_name, ' '))
	{
		this->SetName(input_name);
		Date input_date;
		input_date.ReadDate(in);
		this->SetCreationDate(input_date);
		int input_size;
		if (in >> input_size)
		{
			this->SetSize(input_size);
		}
	}
	in.ignore();
}

void FileData::WriteFileData(std::ostream& out) const
{
	out << "File Name: " << this->GetName() << std::endl;
	Date output_date = this->GetCreationDate();
	output_date.WriteDate(out);
	out << "Size (in bytes): " << this->GetSize() << std::endl;
}

bool FileData::ValidateName(const std::string& name) {
	static const std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789`~!@#$%^&()_+-={[]};',.";
    for (char ch : name) {
        if (alphabet.find(ch) == std::string::npos) {
            return false;
        }
    }
    return true;
}

void FileData::InvalidName(const std::string& name)
{
	static const std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789`~!@#$%^&()_+-={[]};',.";

    if (name.empty() || !ValidateName(name) || name.find_first_not_of(alphabet) != std::string::npos) {
        throw std::runtime_error("Invalid name!");
    }
    ValidateName(name);
}

bool FileData::ValidateSize(const int& size)
{
    if (size < 0) {
        return false;
    }
    return true;
}

void FileData::InvalidSize(const int& size)
{
    if (size < 0)
    {
        throw std::runtime_error("Invalid price!");
    }
    ValidateSize(size);
}

FileData::FileData(const std::string& name, const Date& creation_date, const int& size) : name(name), creation_date(creation_date), size(size) {}

