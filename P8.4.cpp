/* THIS PROGRAM IS PREPARED BY 24CE058_Mahima Kukadiya
8.4 Standard Template Library � Store and sort student records.*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to hold student data
struct Student
{
    string name;
    int score;
};

// Comparator to sort students in descending order of score
bool compareByScore(const Student& a, const Student& b)
{
    return a.score > b.score;
}

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<Student> students(n);
    cout << "Enter name and score of each student:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> students[i].name >> students[i].score;
    }

    // Sort using custom comparator
    sort(students.begin(), students.end(), compareByScore);

    // Display ranked list
    cout << "\n--- Student Ranking ---\n";
    int rank = 1;
    for (auto it = students.begin(); it != students.end(); ++it)
    {
        cout << "Rank " << rank++ << ": " << it->name << " (Score: " << it->score << ")\n";
    }
cout << "\n24CE058-Mahima Kukadiya";
    return 0;
}
