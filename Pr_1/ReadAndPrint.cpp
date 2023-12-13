#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "ReadAndPrint.h"
#include "FileData.h"


std::vector<FileData> ReadStruct(std::ifstream& in)
{
	std::string input;
	std::vector<FileData> file_array;
	while (in)
	{
		FileData file_data;
		file_data.ReadFileData(in);
		file_array.emplace_back(file_data);
	}
	return file_array;
}

void PrintStruct(const std::vector<FileData>& data_array)
{
	for (const auto& file : data_array)
	{
		file.WriteFileData();
	}
}