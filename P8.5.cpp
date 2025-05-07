/* THIS PROGRAM IS PREPARED BY 24CE058_Mahima Kukadiya
8.5 Standard Template Library � Organize files with dynamic sequences.*/
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

void addFolder(map<string, vector<string>>& directory, const string& folderName)
{
    // Create folder only if it doesn't exist
    if (directory.find(folderName) == directory.end())
    {
        directory[folderName] = {};
        cout << "Folder '" << folderName << "' created.\n";
    } else {
        cout << "Folder '" << folderName << "' already exists.\n";
    }
}

void addFileToFolder(map<string, vector<string>>& directory, const string& folderName, const string& fileName)
{
    if (directory.find(folderName) != directory.end())
    {
        directory[folderName].push_back(fileName);
        cout << "File '" << fileName << "' added to folder '" << folderName << "'.\n";
    } else {
        cout << "Folder '" << folderName << "' does not exist.\n";
    }
}

void displayDirectory(const map<string, vector<string>>& directory)
{
    cout << "\n--- Directory Structure ---\n";
    for (const auto& folder : directory)
    {
        cout << "Folder: " << folder.first << "\n";
        for (const auto& file : folder.second)
        {
            cout << "  - " << file << "\n";
        }
    }
}

int main()
{
    map<string, vector<string>> directory;
    int choice;
    string folder, file;

    do {
        cout << "1. Add Folder\n2. Add File to Folder\n3. Display Directory\n4. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore(); // to consume newline

        switch (choice)
        {
            case 1:
                cout << "Enter folder name: ";
                getline(cin, folder);
                addFolder(directory, folder);
                break;

            case 2:
                cout << "Enter folder name: ";
                getline(cin, folder);
                cout << "Enter file name: ";
                getline(cin, file);
                addFileToFolder(directory, folder, file);
                break;

            case 3:
                displayDirectory(directory);
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    cout << "\n24CE058-Mahima Kukadiya";
    return 0;
}
