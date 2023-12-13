#pragma once

#include <vector>
#include <fstream>
#include "FileData.h"

std::vector<FileData> ReadStruct(std::ifstream& in);

void PrintStruct(const std::vector<FileData>& arr);
