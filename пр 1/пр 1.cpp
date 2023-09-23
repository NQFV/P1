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

vector<FileData> readDataFromFile(const string& filename) {
    vector<FileData> files;
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cerr << "Не удалось открыть файл." << endl;
        return files;
    }

    string line;
    while (getline(inputFile, line)) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);

        if (pos1 != string::npos && pos2 != string::npos) {
            string name = line.substr(0, pos1);
            string date = line.substr(pos1 + 1, pos2 - pos1 - 1);
            int size = stoi(line.substr(pos2 + 1));

            files.emplace_back(name, date, size);
        }
        else {
            cerr << "Некорректный формат ввода." << endl;
            files.clear();
            break;
        }
    }

    inputFile.close();
    return files;
}

void printFileData(const vector<FileData>& files) {
    for (const FileData& file : files) {
        cout << "Название файла: " << file.filename << endl;
        cout << "Дата создания: " << file.creationDate << endl;
        cout << "Размер (в байтах): " << file.fileSize << endl;
        cout << "________________" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Ru");
    const string inputFilename = "input.txt";
    vector<FileData> files = readDataFromFile(inputFilename);

    if (!files.empty()) {
        printFileData(files);
    }

    return 0;
}
