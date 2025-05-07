/*THIS PROGRAM IS PREPARED BY 24CE058_Mahima Kukadiya
Text File Analyzer with Manual Memory Management and Error Handling in C++*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;

bool isWordChar(char c) {
    return isalnum(c);
}

int main() {
    char filename[100];
    cout << "Enter the filename: ";
    cin.getline(filename, 100);

    ifstream file(filename);

    if (!file) {
        cout << "Error: Unable to open file.\n";
        return 1;
    }

    const int MAX_LINE_LEN = 1000;
    char* line = new char[MAX_LINE_LEN];

    int charCount = 0, wordCount = 0, lineCount = 0;

    while (file.getline(line, MAX_LINE_LEN)) {
        lineCount++;
        int len = strlen(line);
        charCount += len;
        charCount++;

        bool inWord = false;
        for (int i = 0; i < len; i++) {
            if (isWordChar(line[i])) {
                if (!inWord) {
                    wordCount++;
                    inWord = true;
                }
            } else {
                inWord = false;
            }
        }
    }

    cout << "\nStatistics for file \"" << filename << "\":\n";
    cout << "Lines: " << lineCount << endl;
    cout << "Words: " << wordCount << endl;
    cout << "Characters (with newline): " << charCount << endl;

    delete[] line;
    file.close();

    cout<<"\n24cE058-Mahima kukadiya\n";

    return 0;
}

