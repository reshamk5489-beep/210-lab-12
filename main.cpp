#include <iostream>
#include <fstream>
#include <array>
using namespace std;

// Comment #1: Define a constant for the maximum number of GPA entries.
const int MAX_GPA_COUNT = 35;

void readGPAsFromFile(array<double, MAX_GPA_COUNT>&);

int main()
{
    // Comment #: Declare an array to hold GPA values.
    array<double, MAX_GPA_COUNT> gpaList;
}

// Comment #: Function to read GPA values from a file into the gpaList array.
void readGPAsFromFile(array<double, MAX_GPA_COUNT>& gpaList)
{
    // Comment #: Open the input file.
    ifstream inputFile("gpas.txt");
    
    // Comment #: Read GPA values from the file into the array.
    for (int i = 0; i < MAX_GPA_COUNT; ++i)
    {
        inputFile >> gpaList[i];
    }

    // Comment #: Close the input file.
    inputFile.close();
}