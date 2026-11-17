
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
};

int main() {
    const string filename = "students.csv";

    // 1. Writing records to CSV and demonstrating tellp() & seekp()
    ofstream outFile(filename);

    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return 1;
    }

    Student s1 = {101, "Parth", 89.5};
    Student s2 = {102, "Snehal", 90.0};
    Student s3 = {103, "Rohan", 70.0};

    cout << "Initial write pointer position (tellp): " << outFile.tellp() << endl;

    outFile << "Roll,Name,Marks\n";

    streampos firstRecordPos = outFile.tellp(); // Bookmark position of 1st record

    cout << "Position after header (tellp): " << firstRecordPos << endl;

    outFile << s1.rollNo << "," << s1.name << "," << s1.marks << "\n";
    outFile << s2.rollNo << "," << s2.name << "," << s2.marks << "\n";
    outFile << s3.rollNo << "," << s3.name << "," << s3.marks << "\n";

    cout << "Position after writing 3 records (tellp): " << outFile.tellp() << endl;

    // Demonstrate seekp(): Jump back to 1st record and update Parth's marks
    // "101,Parth," is 10 characters long, so marks start at firstRecordPos + 10
    outFile.seekp(firstRecordPos + streamoff(10));

    outFile << "97.0";

    cout << "Updated Parth's marks in-place using seekp()!" << endl;

    outFile.close();

    // 2. Reading records from CSV and demonstrating tellg() and seekg()
    ifstream inFile(filename);

    if (!inFile) {
        cout << "Error opening file for reading!" << endl;
        return 1;
    }

    cout << "\nInitial read pointer position (tellg): " << inFile.tellg() << endl;

    string line;

    cout << "\n--- Student Records Read from CSV ---" << endl;

    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.clear(); // Clear EOF flag BEFORE calling tellg()

    cout << "End-of-file read pointer position (tellg): " << inFile.tellg() << endl;

    // 3. Demonstrating seekg() to rewind back to start
    inFile.seekg(0, ios::beg);

    cout << "\nAfter seekg(0, ios::beg), pointer is at: " << inFile.tellg() << endl;

    getline(inFile, line);

    cout << "Re-reading line 1: " << line << endl;

    inFile.close();

    return 0;
}
