
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


struct Employee{
  int id;
  char designation[50];
  char name[50];
  float salary;
};

struct Index{
    int id;
    long datapos;
};

 void addemployee();
 void deleteemployee();
 void displayemployee();
 long searchemployee(int id);

const char* datafile="employeedata.data";
const char* indexfile="employeeindex.index";

void addemployee(){
    Employee emp;
    Index idx;
    
    cout<<"Enter id:";
    cin>>emp.id;
    cout<<"Enter name:";
    cin.ignore();
    cin.getline(emp.name,50);
    cout<<"Enter designation:";
    cin.getline(emp.designation,50);
    cout<<"Enter salary:";
    cin>>emp.salary;
    
    ofstream datafilestream(datafile,ios::binary | ios::app);
    datafilestream.seekp(0,ios::end);
    long datapos=datafilestream.tellp();
    datafilestream.write((char*)&emp,sizeof(Employee));
    datafilestream.close();
    
    ofstream indexfilestream(indexfile, ios::app | ios::binary);
    idx.id=emp.id;
    idx.datapos=datapos;
    indexfilestream.write((char*)&idx,sizeof(Index));
    indexfilestream.close();
    
    cout<<"Employee added successfully"<<endl;
}
    void deleteemployee(){
        int id;
        cout<<"Enter id to delete:";
        cin>>id;
        
        long pos=searchemployee(pos);
        if (pos==-1){
            cout<<"employee not found";
            return;
        }
        
        fstream datafilestream(datafile,ios::binary);
        Employee emp;
        datafilestream.seekg(pos);
        datafilestream.read((char*)&emp,sizeof(Employee));
        
        strcpy(emp.name,"");
        strcpy(emp.designation,"");
        emp.salary=0;
        
        datafilestream.seekp(pos);
        datafilestream.write((char*)&emp,sizeof(Employee));
        datafilestream.close();
        
        cout<<"Employee deleted successfully"<<endl;
        
    }
      void displayemployee(){
        int id;
        cout<<"Enter id to display:";
        cin>>id;
        
        long pos=searchemployee(pos);
        if (pos==-1){
            cout<<"employee not found";
            return;
        }
        
        ifstream datafilestream("datafile",ios::binary);
        Employee emp;
        datafilestream.seekg(pos);
        datafilestream.read((char*)&emp,sizeof(Employee));
        
        cout << "Employee ID: " << emp.id << endl;
        cout << "Name: " << emp.name << endl;
        cout << "Designation: " << emp.designation << endl;
        cout << "Salary: " << emp.salary << endl;
  }
  
  long searchemployee(int id){
      ifstream indexfilestream("indexfile",ios::binary);
      Index idx;
      
      while(indexfilestream.read((char*)&id,sizeof(Index))){
          if(idx.id==id){
              indexfilestream.close();
              return idx.datapos;
          }
      }
      indexfilestream.close();
      return -1;
  }
  
  int main(){
    int choice;
    while (true) {
        cout << "\nEmployee Information System" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Delete Employee" << endl;
        cout << "3. Display Employee" << endl;
        cout<<"4.searchemployee"<<endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addemployee();
                    break;
            case 2: deleteemployee();
                    break;
            case 3: displayemployee();
                    break;
          case 4:int id;
                   cout<<"Enter id to search"<<endl;
                   cout<<searchemployee(id);
                   break;
            case 5: cout << "Exiting..." << endl; 
                    return 0;
            default: cout << "Invalid choice. Please try again." << endl;
        }
    }
}
    
    