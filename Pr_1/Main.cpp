#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "FileDate.h"
#include "FileData.h"
#include "ReadAndPrint.h"

int main() {
    std::ifstream in("input.txt");
    std::vector<FileData> file_array = ReadStruct(in);
    PrintStruct(file_array);
    in.close();
}
