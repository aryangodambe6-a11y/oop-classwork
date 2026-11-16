#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
using namespace std;

class Patient
{
private:
    int patient_id;
    int patient_age;
    string patient_name;
    string patient_phone;
    string patient_address;
    string disease;
    string doctor_name;

public:

    // Constructor
    Patient()
    {
        patient_id = 0;
        patient_age = 0;
    }

    // Input patient details
    void setData()
    {
        cout << "\nEnter Patient ID: ";
        cin >> patient_id;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Patient Name: ";
        getline(cin, patient_name);

        cout << "Enter Patient Age: ";
        cin >> patient_age;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Phone Number: ";
        getline(cin, patient_phone);

        cout << "Enter Address: ";
        getline(cin, patient_address);

        cout << "Enter Disease: ";
        getline(cin, disease);

        cout << "Enter Doctor Name: ";
        getline(cin, doctor_name);
    }

    // Display patient details
    void DisplayData()
    {
        cout << "\n----- PATIENT DETAILS -----\n";
        cout << "Patient ID: " << patient_id << endl;
        cout << "Patient Name: " << patient_name << endl;
        cout << "Patient Age: " << patient_age << endl;
        cout << "Phone Number: " << patient_phone << endl;
        cout << "Address: " << patient_address << endl;
        cout << "Disease: " << disease << endl;
        cout << "Doctor Name: " << doctor_name << endl;
    }

    // Return patient ID
    int getId()
    {
        return patient_id;
    }

    // Update patient details
    void updateData()
    {
        cout << "\nEnter New Patient Name: ";
        getline(cin, patient_name);

        cout << "Enter New Patient Age: ";
        cin >> patient_age;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter New Phone Number: ";
        getline(cin, patient_phone);

        cout << "Enter New Address: ";
        getline(cin, patient_address);

        cout << "Enter New Disease: ";
        getline(cin, disease);

        cout << "Enter New Doctor Name: ";
        getline(cin, doctor_name);
    }

    // Save patient details in file
    void saveToFile(ofstream &file)
    {
        file << patient_id << endl;
        file << patient_name << endl;
        file << patient_age << endl;
        file << patient_phone << endl;
        file << patient_address << endl;
        file << disease << endl;
        file << doctor_name << endl;
    }

    // Load patient details from file
    bool loadFromFile(ifstream &file)
    {
        string age;

        if (!(file >> patient_id))
            return false;

        file.ignore(numeric_limits<streamsize>::max(), '\n');

        getline(file, patient_name);
        getline(file, age);
        getline(file, patient_phone);
        getline(file, patient_address);
        getline(file, disease);
        getline(file, doctor_name);

        patient_age = stoi(age);

        return true;
    }
};

// Save all patients
void savePatients(vector<Patient> &patients)
{
    ofstream file("patients.txt");

    for (int i = 0; i < patients.size(); i++)
    {
        patients[i].saveToFile(file);
    }

    file.close();
}

// Load patients from file
void loadPatients(vector<Patient> &patients)
{
    ifstream file("patients.txt");

    if (!file)
        return;

    while (true)
    {
        Patient p;

        if (!p.loadFromFile(file))
            break;

        patients.push_back(p);
    }

    file.close();
}

int main()
{
    vector<Patient> patients;
    int choice;

    // Load existing records
    loadPatients(patients);

    do
    {
        cout << "\n================================\n";
        cout << " HOSPITAL PATIENT MANAGEMENT SYSTEM\n";
        cout << "================================\n";

        cout << "1. Add Patient\n";
        cout << "2. Display All Patients\n";
        cout << "3. Search Patient\n";
        cout << "4. Update Patient\n";
        cout << "5. Delete Patient\n";
        cout << "6. Exit\n";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Add Patient
        if (choice == 1)
        {
            Patient p;
            p.setData();

            bool duplicate = false;

            for (int i = 0; i < patients.size(); i++)
            {
                if (patients[i].getId() == p.getId())
                {
                    duplicate = true;
                    break;
                }
            }

            if (duplicate)
            {
                cout << "\nPatient ID Already Exists!\n";
            }
            else
            {
                patients.push_back(p);
                savePatients(patients);
                cout << "\nPatient Added Successfully!\n";
            }
        }

        // Display All Patients
        else if (choice == 2)
        {
            if (patients.empty())
            {
                cout << "\nNo Patient Records Found!\n";
            }
            else
            {
                for (int i = 0; i < patients.size(); i++)
                {
                    patients[i].DisplayData();
                }
            }
        }

        // Search Patient
        else if (choice == 3)
        {
            int searchId;
            bool found = false;

            cout << "Enter Patient ID: ";
            cin >> searchId;

            for (int i = 0; i < patients.size(); i++)
            {
                if (patients[i].getId() == searchId)
                {
                    patients[i].DisplayData();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "\nPatient Not Found!\n";
        }

        // Update Patient
        else if (choice == 4)
        {
            int updateId;
            bool found = false;

            cout << "Enter Patient ID to Update: ";
            cin >> updateId;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            for (int i = 0; i < patients.size(); i++)
            {
                if (patients[i].getId() == updateId)
                {
                    patients[i].updateData();
                    savePatients(patients);
                    cout << "\nPatient Updated Successfully!\n";
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "\nPatient Not Found!\n";
        }

        // Delete Patient
        else if (choice == 5)
        {
            int deleteId;
            bool found = false;

            cout << "Enter Patient ID to Delete: ";
            cin >> deleteId;

            for (int i = 0; i < patients.size(); i++)
            {
                if (patients[i].getId() == deleteId)
                {
                    patients.erase(patients.begin() + i);
                    savePatients(patients);

                    cout << "\nPatient Deleted Successfully!\n";
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "\nPatient Not Found!\n";
        }

        // Exit
        else if (choice == 6)
        {
            savePatients(patients);
            cout << "\nThank You For Using Our System!\n";
        }

        else
        {
            cout << "\nInvalid Choice! Try Again.\n";
        }

    } while (choice != 6);

    return 0;
}
