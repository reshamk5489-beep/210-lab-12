#include <iostream>
#include <fstream>
#include <array>
#include <iomanip>
using namespace std;

// Comment #1: Define a constant for the maximum number of GPA entries.
const int MAX_GPA_COUNT = 35;

void readGPAsFromFile(array<double, MAX_GPA_COUNT>&);
void outputGPAs(const array<double, MAX_GPA_COUNT>&);
void swapGPAs();
void fillGPAs();
bool findGPA(const array<double, MAX_GPA_COUNT>&, double);

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

    cout << endl << "Sorting the GPA list in the descending order." << endl;
    sort(gpaList.rbegin(), gpaList.rend());
    outputGPAs(gpaList);

    cout << endl << "Sorting the GPA list in the ascending order." << endl;
    sort(gpaList.begin(), gpaList.end());
    outputGPAs(gpaList);

    cout << endl << "Swapping two GPA lists." << endl;
    swapGPAs();

    cout << endl << "Filling the GPA list with 4.0." << endl;
    fillGPAs();

    cout << endl << "Finding a GPA in the list." << endl;
    double gpaToFind = 3.75;
    cout << "Is " << gpaToFind << " in the GPA list? " 
         << (findGPA(gpaList, gpaToFind) ? "Yes" : "No") << endl;

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

void swapGPAs()
{
    array<double, 4> gpaList1 = {3.5, 3.7, 3.9, 4.1};
    array<double, 4> gpaList2 = {2.5, 2.7, 2.9, 3.1};

    cout << "Before swap:" << endl;
    for (int i = 0; i < gpaList1.size(); ++i) cout << gpaList1[i] << " ";
    cout << endl;
    for (int i = 0; i < gpaList2.size(); ++i) cout << gpaList2[i] << " ";
    cout << endl;

    gpaList1.swap(gpaList2);

    cout << "After swap:" << endl;
    for (int i = 0; i < gpaList1.size(); ++i) cout << gpaList1[i] << " ";
    cout << endl;
    for (int i = 0; i < gpaList2.size(); ++i) cout << gpaList2[i] << " ";
    cout << endl;
}

void fillGPAs()
{
    array<double, 4> gpaList;
    gpaList.fill(4.0);
    for (int i = 0; i < gpaList.size(); ++i) cout << gpaList[i] << " ";
    cout << endl;
}

bool findGPA(const array<double, MAX_GPA_COUNT>& gpaList, double gpa)
{
    for (int i = 0; i < gpaList.size(); ++i)
    {
        if (gpa == gpaList[i]) return true;
    }

    return false;
}