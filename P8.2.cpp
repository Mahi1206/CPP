/* THIS PROGRAM IS PREPARED BY 24CE058_Mahima Kukadiya
8.2 Standard Template Library � Count word frequency with map.*/
#include <iostream>
#include <map>
#include <sstream>
#include <iterator>
#include <algorithm>
using namespace std;

// Function to count word frequencies
void countWordFrequencies(const string& sentence)
{
    map<string, int> wordFrequency;

    // Create a stringstream from the sentence
    stringstream ss(sentence);
    string word;

    // Process each word in the sentence
    while (ss >> word) {
        // Remove punctuation from the word
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());

        // Convert the word to lowercase for case-insensitive counting
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        // Increase the word count in the map
        wordFrequency[word]++;
    }

    // Display the word frequencies
    cout << "\nWord Frequencies:\n";
    for (const auto& pair : wordFrequency)
    {
        cout << pair.first << ": " << pair.second << endl;
    }
}

int main()
{
    string sentence;

    cout << "Enter a sentence: ";
    getline(cin, sentence);  // Read a full line of input

    countWordFrequencies(sentence);  // Call the function to count word frequencies
     cout << "\n24CE058-Mahima Kukadiya\n";

return 0;
}

