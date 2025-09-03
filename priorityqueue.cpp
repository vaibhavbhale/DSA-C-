#include <iostream>
#include <string>
#define MAX 50
using namespace std;

class priority {
public:
    string name;
    int pri;
};

class Queue {
    priority arr[MAX];
    int rear;
    int front;

public:
    Queue() {
        rear = -1;
        front = -1;
    }

    bool isfull() {
        if (rear == MAX - 1){
            return true;
        }
         return false;
    }

    bool empty() {
        if(rear == front || rear == -1)
        {
            return true;
        }
           return false;
    }

    string check(int No) {
        if (No == 1) {
            return "General checkup";
        }
        else if (No == 2) {
            return "Non-serious";
        }
        else if (No == 3) {
            return "Serious";
        }
        else {
            return "Invalid";
        }
    }

    void enqueue(priority p) {
        if (isfull()) {
            cout << "Queue is full" << endl;
            return;
        }
        int i = rear;
        while (i >= 0 && p.pri > arr[i].pri) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = p;
        rear++;
    }

    void dequeue() {
        if (empty()) {
            cout << "Queue is empty" << endl;
        }
        else {
            front++;
            cout << arr[front].name << ": ";
            cout << check(arr[front].pri) << endl;
        }
    }
};

int main() {
    Queue obj;
    int count = 0;

    cout << "Enter the count of patients: ";
    cin >> count;

    for (int i = 0; i < count; i++) {
        priority p;
        cout << "Enter the name of patient: ";
        cin >> p.name;
        cout << "Enter the priority of patient : ";
        cin >> p.pri;
        obj.enqueue(p);
    }

    cout << "\nData of patients:\n";
    while (!obj.empty()) {
        obj.dequeue();
    }

    return 0;
}
