#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include<windows.h>

using namespace std;

void logActivity(const string& time, const string& importance, const string& activity);

int main() {
    while (true) {
        time_t now = time(0);
        char* dt = ctime(&now);
        string currentTime(dt);

        string importance;
        string activity;

        cout << "IMPORTANCE: ";
        getline(cin, importance);
        if(importance==""){
            importance="NULL";
        }

        cout << "CONTENT: ";
        getline(cin, activity);
        if(activity == "") {
            activity = "NULL";
        }

        logActivity(currentTime, importance, activity);

        cout << "DONE!" << endl;
        Sleep(500);
        system("cls");
    }

    return 0;
}

void logActivity(const string& time, const string& importance, const string& activity) {
    const string filename ="MY.log";

    ofstream outFile;

    outFile.open(filename, ios::app);

    if (!outFile.is_open()) {
        cerr << "CANNOT OPEN FILE:" << filename << endl;
        return;
    }

    outFile << "TIME\n{\n" << time << "}\nIMPORTANCE\n{\n" << importance << "\n}\nACTIVITY\n{\n" << activity <<"\n}"<< endl;

    outFile.close();
}