#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class student {
private:
    string name;
    char Div;
    string address;
    int roll_no;

public:
    void getdata() {
        cout << "Enter the name: ";
        cin >> name;
        cout << "Enter the division: ";
        cin >> Div;
        cout << "Enter the address: ";
        cin >> address;
        cout << "Enter the roll number: ";
        cin >> roll_no;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Division: " << Div << endl;
        cout << "Address: " << address << endl;
        cout << "Roll Number: " << roll_no << endl;
    }

    void add() {
        student s1;
        s1.getdata();
        ofstream file;

        file.open("student.txt", ios::binary | ios::app);
        file.write((char*)& s1, sizeof(s1));
        file.close();
    }

    void search() {
        student s1;
        int roll;
        cout << "Enter roll number to search: ";
        cin >> roll;
        ifstream file;
        file.open("student.txt", ios::binary);
        bool found = false;

        while (file.read((char*)&s1, sizeof(s1))) {
            if (s1.roll_no == roll) {
                s1.display();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Student not found!" << endl;
        }
        file.close();
    }

    void remove_student() {
        student s1;
        int roll;
        cout << "Enter roll number to delete: ";
        cin >> roll;
        ifstream file1;
        ofstream file2;
        file1.open("student.txt", ios::binary);
        file2.open("temp.txt", ios::binary | ios::app);
        bool found = false;
        
        while (file1.read((char*)&s1, sizeof(s1))) {
            if (s1.roll_no != roll) {
                file2.write((char*)&s1, sizeof(s1));
            } else {
                found = true;
            }
        }

        file1.close();
        file2.close();
        remove("student.txt");
        rename("temp.txt", "student.txt");

        if (found) {
            cout << "Student deleted successfully." << endl;
        } else {
            cout << "Student not found!" << endl;
        }
    }

    int get_roll() {
        return roll_no;
    }
};

int main() {
    int ch;
    student s;

    while (true)
    {
    cout << "***************MENU***************" << endl;
    cout << "1. Add" << endl;
    cout << "2. Search" << endl;
    cout << "3. Delete" << endl;
    cout << "4. Display" << endl;
    cout << "5. Exit" << endl;
    
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            s.add();
            break;
        case 2:
            s.search();
            break;
        case 3:
            s.remove_student();
            break;
        case 4:
            s.display();
            break;
        case 5:
            cout << "Exiting..." <<endl;
            return 0;
        default: 
            cout << "Invalid choice, try again." << endl;
        }
    }      
}
