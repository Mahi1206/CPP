/*THIS PROGRAM IS PREPARED BY 24CE058_Mahima Kukadiya
Case-Insensitive Word Frequency Counter Using Dynamic Memory (No STL)*/
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void toLower(char* str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

int findWord(char** words, int count, const char* word) {
    for (int i = 0; i < count; i++) {
        if (strcmp(words[i], word) == 0)
            return i;
    }
    return -1;
}

int main() {
    const int MAX_LEN = 1000;
    char paragraph[MAX_LEN];

    cout << "Enter a paragraph:\n";
    cin.getline(paragraph, MAX_LEN);
    int capacity = 10;
    char** words = new char*[capacity];
    int* counts = new int[capacity];
    int wordCount = 0;

    char* token = strtok(paragraph, " ,.-!?;:\n");

    while (token != nullptr) {
        toLower(token);

        int index = findWord(words, wordCount, token);
        if (index != -1) {
            counts[index]++;
        } else {
            if (wordCount == capacity){
                capacity *= 2;
                char** tempWords = new char*[capacity];
                int* tempCounts = new int[capacity];
                for (int i = 0; i < wordCount; i++) {
                    tempWords[i] = words[i];
                    tempCounts[i] = counts[i];
                }
                delete[] words;
                delete[] counts;
                words = tempWords;
                counts = tempCounts;
            }

            words[wordCount] = new char[strlen(token) + 1];
            strcpy(words[wordCount], token);
            counts[wordCount] = 1;
            wordCount++;
        }

        token = strtok(nullptr, " ,.-!?;:\n");
    }

    cout << "\nWord Frequencies:\n";
    for (int i = 0; i < wordCount; i++) {
        cout << words[i] << " : " << counts[i] << endl;
        delete[] words[i];
    }
    delete[] words;
    delete[] counts;

    cout<<"\n24CE058-Mahima Kukadiya\n";

    return 0;
}

