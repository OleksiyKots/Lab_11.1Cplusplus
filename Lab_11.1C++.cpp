#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ������� ��� ��������� ���������� �����
void CreateTXT(const char* fname) {
    ofstream fout(fname);
    if (!fout) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }
    char ch;
    string line;
    do {
        cin.ignore(); // ������� ����� �����
        cout << "Enter line: ";
        getline(cin, line);
        fout << line << endl;
        cout << "Continue? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    fout.close();
}

// ������� ��� ��������� ����� ���������� �����
void PrintTXT(const char* fname) {
    ifstream fin(fname);
    if (!fin) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();
}

// ������� ��� �������� �������� ����� ������ ������
bool HasThreeStarsInRow(const char* fname) {
    ifstream fin(fname);
    if (!fin) {
        cerr << "Error opening file for reading!" << endl;
        return false;
    }
    string line;
    while (getline(fin, line)) {
        if (line.find("***") != string::npos) {
            fin.close();
            return true;
        }
    }
    fin.close();
    return false;
}

int main() {
    char fname[100];

    // �������� ���� �����
    cout << "Enter file name: ";
    cin >> fname;

    // ��������� �����
    CreateTXT(fname);

    // ��������� ����� �����
    cout << "\nFile content:\n";
    PrintTXT(fname);

    // �������� �� �������� ����� ������ ������
    if (HasThreeStarsInRow(fname)) {
        cout << "\nThe file contains three consecutive stars (***)." << endl;
    }
    else {
        cout << "\nThe file does not contain three consecutive stars (***)." << endl;
    }

    return 0;
}
