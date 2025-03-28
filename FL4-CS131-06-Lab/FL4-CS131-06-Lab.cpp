#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// Declare grade check function
char gradeCheck(int num);
int main() {
    // Integer for reading number grade
    int num;
    // String for reading name of grade receiver
    // File path, file to read from, and file to write to stored as strings to reduce code clutter
    // Same concept as functions, on a smaller scale
    string name, path = "c:\\Users\\thesp\\Desktop", read = "GradeNumbers.txt", write = "GradeLetters.txt";
    // File to read from and file to write to initialized, both can be written on two lines instead of one
    ifstream inFile(path + "\\" + read);
    ofstream outFile(path + "\\" + write);
    // Checks that both files can actually be opened, exits the program if not
    if (inFile.fail()) {
        cout << "Input file failed\n\n";
        system("pause");
        exit(1);
    }
    if (outFile.fail()) {
        cout << "Output file failed\n\n";
        system("pause");
        exit(1);
    }
    // Flavor text
    cout << "Reading number grade input file...\n\n";
    // The essence of this assignment is in these four lines; while there is data in "read",
    // print this data in "write" with the gradeCheck function to convert number to letter grades
    while (inFile >> name >> num) {
        cout << name << "'s grade of " << num << " is " << gradeCheck(num) << "\n";
        outFile << name << " " << num << " " << gradeCheck(num) << "\n";
    }
    cout << "\nAbove data written into output file.\n\n";
    system("pause");
    return 0;
}
// Define function; checks grade ranges and returns corresponding values
char gradeCheck(int num) {
    if (num >= 90)
        return 'A';
    else if (num >= 80)
        return 'B';
    else if (num >= 70)
        return 'C';
    else if (num >= 60)
        return 'D';
    else if (num >= 0)
        return 'F';
    else
        return 'Z';
}