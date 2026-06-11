#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    int rollNo[100];
    string name[100];
    float marks[100];

    int count = 0;
    int choice, searchRoll;

    // Load existing records from file
    ifstream infile("students.txt");

    while (infile >> rollNo[count] >> name[count] >> marks[count]) {
        count++;
    }

    infile.close();

    while (true) {

        cout << "\n\n===== STUDENT MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Search Student";
        cout << "\n4. Update Student";
        cout << "\n5. Delete Student";
        cout << "\n6. Save Records";
        cout << "\n7. Exit";
        cout << "\n\nEnter Choice: ";

        cin >> choice;

        switch (choice) {

        case 1:

            cout << "\nEnter Roll Number: ";
            cin >> rollNo[count];

            cout << "Enter Name: ";
            cin >> name[count];

            cout << "Enter Marks: ";
            cin >> marks[count];

            count++;

            cout << "\nStudent Added Successfully!";
            break;

        case 2:

            if (count == 0) {
                cout << "\nNo Records Found!";
            }
            else {

                cout << "\n\n===== STUDENT RECORDS =====\n";

                for (int i = 0; i < count; i++) {

                    cout << "\nRoll Number : " << rollNo[i];
                    cout << "\nName        : " << name[i];
                    cout << "\nMarks       : " << marks[i];

                    if(marks[i] >= 90)
                    cout << "\nGrade: A";
                    else if(marks[i] >= 75)
                    cout << "\nGrade: B";
                    else if(marks[i] >= 50)
                    cout << "\nGrade: C";
                    else
                    cout << "\nGrade: Fail";
                    cout << "\n--------------------------";
                }
            }

            break;

        case 3:

            cout << "\nEnter Roll Number to Search: ";
            cin >> searchRoll;

            {
                bool found = false;

                for (int i = 0; i < count; i++) {

                    if (rollNo[i] == searchRoll) {

                        cout << "\nStudent Found!";
                        cout << "\nRoll Number : " << rollNo[i];
                        cout << "\nName        : " << name[i];
                        cout << "\nMarks       : " << marks[i];

                        found = true;
                        break;
                    }
                }

                if (!found)
                    cout << "\nStudent Not Found!";
            }

            break;

        case 4:

            cout << "\nEnter Roll Number to Update: ";
            cin >> searchRoll;

            {
                bool found = false;

                for (int i = 0; i < count; i++) {

                    if (rollNo[i] == searchRoll) {

                        cout << "Enter New Name: ";
                        cin >> name[i];

                        cout << "Enter New Marks: ";
                        cin >> marks[i];

                        found = true;

                        cout << "\nRecord Updated Successfully!";
                        break;
                    }
                }

                if (!found)
                    cout << "\nStudent Not Found!";
            }

            break;

        case 5:

            cout << "\nEnter Roll Number to Delete: ";
            cin >> searchRoll;

            {
                bool found = false;

                for (int i = 0; i < count; i++) {

                    if (rollNo[i] == searchRoll) {

                        for (int j = i; j < count - 1; j++) {

                            rollNo[j] = rollNo[j + 1];
                            name[j] = name[j + 1];
                            marks[j] = marks[j + 1];
                        }

                        count--;

                        found = true;

                        cout << "\nRecord Deleted Successfully!";
                        break;
                    }
                }

                if (!found)
                    cout << "\nStudent Not Found!";
            }

            break;

        case 6:

            {
                ofstream outfile("students.txt");

                for (int i = 0; i < count; i++) {

                    outfile << rollNo[i] << " "
                            << name[i] << " "
                            << marks[i] << endl;
                }

                outfile.close();

                cout << "\nRecords Saved Successfully!";
            }

            break;

        case 7:

            {
                ofstream outfile("students.txt");

                for (int i = 0; i < count; i++) {

                    outfile << rollNo[i] << " "
                            << name[i] << " "
                            << marks[i] << endl;
                }

                outfile.close();

                cout << "\nData Saved. Exiting Program...";
                return 0;
            }

        default:
            cout << "\nInvalid Choice!";
        }
    }

    return 0;
}