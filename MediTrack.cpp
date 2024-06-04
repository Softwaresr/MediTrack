#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <ctime>
#include <iomanip>

using namespace std;

void displayWelcome();
void displayMenu();
void displayHospitalInfo();
void addNewPatient();
void addDiagnosisInfo();
void displayPatientHistory();
int login();
void exitProgram();

int main() {
    displayWelcome();

    if (login() != 0) {
        return 1;
    }

    int choice;
    while (true) {
        displayMenu();
        cout << "\t\t\t\t\t\tEnter your choice: ";
        cin >> choice;

        if (choice < 1 || choice > 5) {
            cout << "\n\n\t\t\t\t\t\tInvalid Choice\n";
            cout << "\t\t\t\t\t\tTry again...\n\n";
            continue;
        }

        system("cls");

        switch (choice) {
            case 1:
                addNewPatient();
                break;
            case 2:
                addDiagnosisInfo();
                break;
            case 3:
                displayPatientHistory();
                break;
            case 4:
                displayHospitalInfo();
                break;
            case 5:
                exitProgram();
                return 0;
        }
    }

    return 0;
}

void displayWelcome() {
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                  WELCOME TO                                           |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                           HOSPITAL MANAGEMENT SYSTEM                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
    cout << "\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
    system("pause");
    system("cls");
}

void displayMenu() {
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  HOSPITAL MANAGEMENT SYSTEM \n\n";
    cout << "\n\n\t\t\t\t\t\tPlease, Choose from the following Options: \n\n";
    cout << "\t\t\t\t\t\t _________________________________________________________________ \n";
    cout << "\t\t\t\t\t\t|                                                                 |\n";
    cout << "\t\t\t\t\t\t|             1  >> Add New Patient Record                        |\n";
    cout << "\t\t\t\t\t\t|             2  >> Add Diagnosis Information                     |\n";
    cout << "\t\t\t\t\t\t|             3  >> Full History of the Patient                   |\n";
    cout << "\t\t\t\t\t\t|             4  >> Information About the Hospital                |\n";
    cout << "\t\t\t\t\t\t|             5  >> Exit the Program                              |\n";
    cout << "\t\t\t\t\t\t|_________________________________________________________________|\n\n";
}

void displayHospitalInfo() {
    ifstream file("hos.txt");
    if (!file) {
        cout << "\nError while opening the file\n";
        return;
    }

    cout << "\n\n\n\n\n\n\n\t\t\t\t\t   ...........................Information about the Hospital.............................\n\n";
    string line;
    while (getline(file, line)) {
        cout << line << "\n\t\t";
    }
    cout << "\n\n\t\t";
    system("pause");
    system("cls");
}

void addNewPatient() {
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    cout << "\n\n\t\t\t\t\t\t\t\t" << asctime(timeinfo);

    ofstream pat_file;
    char fname[20];
    cout << "\n\n\n\nEnter the patient's file name: ";
    cin.ignore();
    cin.getline(fname, 20);
    pat_file.open(fname);
    if (!pat_file) {
        cout << "\nError while opening the file\n";
        return;
    }

    struct PatientInfo {
        char name[20];
        char address[100];
        char contact[10];
        char age[5];
        char sex[8];
        char blood_gp[5];
        char disease_past[50];
        char id[15];
    };

    PatientInfo ak;
    cout << "\n********************************************************************\n";
    pat_file << "\n********************************************************************\n\n";
    cout << "\nName: ";
    pat_file << "Name: ";
    cin.getline(ak.name, 20);
    pat_file << ak.name << "\n";
    cout << "\nAddress: ";
    pat_file << "Address: ";
    cin.getline(ak.address, 100);
    pat_file << ak.address << "\n";
    cout << "\nContact Number: ";
    pat_file << "Contact Number: ";
    cin.getline(ak.contact, 10);
    pat_file << ak.contact << "\n";
    cout << "\nAge: ";
    pat_file << "Age: ";
    cin.getline(ak.age, 5);
    pat_file << ak.age << "\n";
    cout << "\nSex: ";
    pat_file << "Sex: ";
    cin.getline(ak.sex, 8);
    pat_file << ak.sex << "\n";
    cout << "\nBlood Group: ";
    pat_file << "Blood Group: ";
    cin.getline(ak.blood_gp, 5);
    pat_file << ak.blood_gp << "\n";
    cout << "\nAny Major disease suffered earlier: ";
    pat_file << "Any Major disease suffered earlier: ";
    cin.getline(ak.disease_past, 50);
    pat_file << ak.disease_past << "\n";
    cout << "\nPatient ID: ";
    pat_file << "Patient ID: ";
    cin.getline(ak.id, 15);
    pat_file << ak.id << "\n";
    cout << "\n********************************************************************\n";
    pat_file << "\n********************************************************************\n\n";
    cout << "\nInformation Saved Successfully\n";

    system("pause");
    system("cls");
}

void addDiagnosisInfo() {
    fstream pat_file;
    char fname[20];
    cout << "\n\nEnter the patient's file name to be opened: ";
    cin.ignore();
    cin.getline(fname, 20);
    system("cls");
    pat_file.open(fname, ios::in);
    if (!pat_file) {
        cout << "\nError while opening the file\n";
        return;
    }

    cout << "\n\n\n\n\t\t\t\t........................................ Information about " << fname << " ........................................\n\n\n\n";
    string info;
    while (getline(pat_file, info)) {
        cout << info << "\n";
    }
    cout << "\n";
    pat_file.close();

    pat_file.open(fname, ios::out | ios::app);
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    cout << "Adding more information in patient's file on: " << asctime(timeinfo);
    pat_file << "Description of " << asctime(timeinfo) << "\n";

    struct DiagnosisInfo {
        char symptom[500];
        char diagnosis[500];
        char medicine[500];
        char admission[30];
        char ward[15];
    };

    DiagnosisInfo add;
    cout << "\nSymptoms: ";
    pat_file << "Symptoms: ";
    cin.getline(add.symptom, 500);
    pat_file << add.symptom << "\n";
    cout << "\nDiagnosis: ";
    pat_file << "Diagnosis: ";
    cin.getline(add.diagnosis, 500);
    pat_file << add.diagnosis << "\n";
    cout << "\nMedicines: ";
    pat_file << "Medicines: ";
    cin.getline(add.medicine, 500);
    pat_file << add.medicine << "\n";
    cout << "\nAdmission Required? : ";
    pat_file << "Admission Required? : ";
    cin.getline(add.admission, 30);
    pat_file << add.admission << "\n";
    cout << "\nType of ward: ";
    pat_file << "Type of ward: ";
    cin.getline(add.ward, 15);
    pat_file << add.ward << "\n";
    pat_file << "\n\n\n";
    pat_file.close();

    cout << "\n\n\n\n\t\t\t\t\t\t\t\tInformation added successfully\n";
    system("pause");
    system("cls");
}

void displayPatientHistory() {
    fstream pat_file;
    char fname[20];
    cout << "\n\nEnter the patient's file name to be opened: ";
    cin.ignore();
    cin.getline(fname, 20);
    system("cls");
    pat_file.open(fname, ios::in);
    if (!pat_file) {
        cout << "\nError while opening the file\n";
        return;
    }

    cout << "\n\n\n\n\t\t\t\t........................................ Full Medical History of " << fname << " ........................................\n\n\n\n";
    string info;
    while (getline(pat_file, info)) {
        cout << info << "\n";
    }
    cout << "\n";
    pat_file.close();

    cout << "\n\n\n\n\t\t\t\t";
    system("pause");
    system("cls");
}

int login() {
    string pass = "";
    char ch;
    cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  HOSPITAL MANAGEMENT SYSTEM \n\n";
    cout << "\t\t\t\t\t\t\t\t------------------------------";
    cout << "\n\t\t\t\t\t\t\t\t\t     LOGIN \n";
    cout << "\t\t\t\t\t\t\t\t------------------------------\n\n";
    cout << "\t\t\t\t\t\t\t\tEnter Password: ";
    ch = _getch();
    while (ch != 13) {
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    if (pass == "pass") {
        cout << "\n\n\n\t\t\t\t\t\t\t\tAccess Granted! \n";
        system("PAUSE");
        system("CLS");
        return 0;
    } else {
        cout << "\n\n\t\t\t\t\t\t\t\tAccess Aborted...Please Try Again!!\n";
        system("PAUSE");
        system("CLS");
        login();
        return 1;
    }
}

void exitProgram() {
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  HOSPITAL MANAGEMENT SYSTEM \n\n";
    cout << "\t\t\t\t\t\t\t\t\tBrought To You By\n\n";
    cout << "\t\t\t\t\t\t\t\t\t    LEYLA ABDULLAYEVA \n\n";
    exit(0);
}
