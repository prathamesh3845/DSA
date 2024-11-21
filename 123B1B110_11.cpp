#include <iostream>
#define size 5
using namespace std;

class Employee {
    int EmpId;
    string name;
    float salary;

public:
    Employee() {
        EmpId = 0;
        name = "NA";
        salary = 0;
    }

    void read() {
        cout << "\nEnter the EMP ID : ";
        cin >> EmpId;
        cout << "Enter the EMP Name : ";
        cin >> name;
        cout << "Enter the EMP salary: ";
        cin >> salary;
    }

    void display1() {
        cout << "Emp ID : " << EmpId << endl;
        cout << "Emp Name : " << name << endl;
        cout << "Emp Salary : " << salary << endl;
        cout << endl;
    }

    void reset() {
        EmpId = 0;
        name = "NA";
        salary = 0;
    }

    int getEmpID() {
        return EmpId;
    }
};

class hashtable {
    Employee emp[size];
    int flag[size];

public:
    hashtable() {
        for (int i = 0; i < size; i++) {
            flag[i] = 0;
        }
    }

    void insert();
    void displaydata();
    void deletedata(int);
    void searchdata(int);
};

void hashtable::insert() {
    Employee newobj;
    newobj.read();
    int EmployeeId = newobj.getEmpID();
    int pos = EmployeeId % size;
    if (flag[pos] == 0) {
        emp[pos] = newobj;
        flag[pos] = 1;
    } else {
        bool inserted = false;
        for (int i = 0; i < size; i++) {
            pos = (pos + 1) % size;
            if (flag[pos] == 0) {
                emp[pos] = newobj;
                flag[pos] = 1;
                inserted = true;
                break;
            }
        }
        if (!inserted) {
            cout << "Hash Table is full. We can't insert employee data" << endl;
        }
    }
}

void hashtable::displaydata() {
    cout << "\nEmployee Information : " << endl;
    for (int i = 0; i < size; i++) {
        cout << "Employee NO : " << i << endl;
        emp[i].display1();
    }
}

void hashtable::searchdata(int EmpidToSearch) {
    int pos = EmpidToSearch % size;
    if (EmpidToSearch == emp[pos].getEmpID()) {
        cout << "The Employee is present, and Employee information is: " << endl;
        emp[pos].display1();
        return;
    } else {
        for (int i = 0; i < size; i++) {
            pos = (pos + 1) % size;
            if (EmpidToSearch == emp[pos].getEmpID()) {
                cout << "The Employee is present, and Employee information is: " << endl;
                emp[pos].display1();
                return;
            }
        }
        cout << "The Employee ID " << EmpidToSearch << " is not present in the hash table." << endl;
    }
}

void hashtable::deletedata(int EmpDEL) {
    int pos = EmpDEL % size;
    if (EmpDEL == emp[pos].getEmpID()) {
        flag[pos] = 0;
        cout << "The Employee Data Deleted: " << endl;
        emp[pos].display1();
        emp[pos].reset();
        return;
    } else {
        for (int i = 0; i < size; i++) {
            pos = (pos + 1) % size;
            if (EmpDEL == emp[pos].getEmpID()) {
                flag[pos] = 0;
                cout << "The Employee Data Deleted: " << endl;
                emp[pos].display1();
                emp[pos].reset();
                return;
            }
        }
        cout << "The Employee ID " << EmpDEL << " is not present in the hash table." << endl;
    }
}

int main() {
    hashtable hash;
    cout << "MENU ARE:" << endl
         << "1 -> INSERT THE EMPLOYEE DATA IN HASHTABLE" << endl
         << "2 -> DISPLAY THE EMPLOYEE DATA FROM HASHTABLE" << endl
         << "3 -> SEARCH THE EMPLOYEE DATA IN HASHTABLE" << endl
         << "4 -> DELETE THE EMPLOYEE DATA FROM HASHTABLE" << endl
         << "5 -> EXIT" << endl;
    int choice;
    int EmpDEL;
    int EmpidToSearch;
    do {
        cout << "\nENTER YOUR CHOICE : ";
        cin >> choice;

        switch (choice) {
        case 1:
            hash.insert();
            break;
        case 2:
            hash.displaydata();
            break;
        case 3:
            cout << "ENTER THE EMPLOYEE ID TO SEARCH : ";
            cin >> EmpidToSearch;
            hash.searchdata(EmpidToSearch);
            break;
        case 4:
            cout << "ENTER THE EMPLOYEE ID TO DELETE : ";
            cin >> EmpDEL;
            hash.deletedata(EmpDEL);
            break;
        case 5:
            cout << "EXIT THE PROGRAM" << endl;
            break;
        default:
            cout << "INVALID CHOICE";
            break;
        }
    } while (choice != 5);
    return 0;
}