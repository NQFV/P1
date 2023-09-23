#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct FileData {
	string filename;
	string creationDate;
	int fileSize;

	FileData(const string& name, const string& date, int size)
		: filename(name), creationDate(date), fileSize(size) {}
};

int main() {
	setlocale(LC_ALL, "Ru");
	vector<FileData> files;
	ifstream inputFile("input.txt");
	string filename;
	string date;
	int size;

	while (getline(inputFile, filename, ',')) {
		if (getline(inputFile, date, ',')) {
			if (inputFile >> size) {
				files.emplace_back(filename, date, size);
				inputFile.ignore();
			}
			else {
				cout << "Некорректный формат ввода." << endl;
				inputFile.close();
				return 1;
			}
		}
	}

	for (const FileData& file : files) {
		cout << "Название файла: " << file.filename << endl;
		cout << "Дата создания: " << file.creationDate << endl;
		cout << "Размер (в байтах): " << file.fileSize << endl;
		cout << "________________" << endl;
	}

	inputFile.close();
}