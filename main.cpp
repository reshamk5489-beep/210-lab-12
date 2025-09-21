#include <iostream>
#include <fstream>
#include <array>
#include <iomanip>
using namespace std;

// Comment #1: Define a constant for the maximum number of GPA entries.
const int MAX_GPA_COUNT = 35;

void readGPAsFromFile(array<double, MAX_GPA_COUNT>&);
void outputGPAs(const array<double, MAX_GPA_COUNT>&);

int main()
{
    // Comment #: Declare an array to hold GPA values.
    array<double, MAX_GPA_COUNT> gpaList;

    // Comment #: Read GPA values from the file into the array.
    readGPAsFromFile(gpaList);

    // Comment #: Output the GPA values to the console.
    outputGPAs(gpaList);

    // Comment #: Check if the GPA list is empty and output the result.
    cout << endl << "Is the GPA list empty? " << (gpaList.empty() ? "Yes" : "No") << endl;

    cout << "Front: " << gpaList.front() << endl;
    cout << "Back: " << gpaList.back() << endl;

    cout << "Sorting the GPA list in the descending order." << endl;
    sort(gpaList.rbegin(), gpaList.rend());
    outputGPAs(gpaList);

    return 0;
}

// Comment #: Function to read GPA values from a file into the gpaList array.
void readGPAsFromFile(array<double, MAX_GPA_COUNT>& gpaList)
{
    // Comment #: Open the input file.
    ifstream inputFile("gpas.txt");
    
    // Comment #: Read GPA values from the file into the array.
    for (int i = 0; i < gpaList.size(); ++i)
    {
        inputFile >> gpaList[i];
    }

    // Comment #: Close the input file.
    inputFile.close();
}

void outputGPAs(const array<double, MAX_GPA_COUNT>& gpaList)
{
    // Comment #: Output the GPA values to the console.
    for (int i = 0; i < gpaList.size(); ++i)
    {
        cout << fixed << setprecision(2) << gpaList.at(i) << endl;
    }
}