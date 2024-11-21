#include <iostream>
using namespace std;

struct Job {
    string jobname;
    int priority;
    int Time;
    Job *next, *prev;

    Job() {
        next = prev = nullptr;
    }

    ~Job() {
        next = prev = nullptr;
    }

    void read() {
        cout << "Enter job name : ";
        cin >> jobname;
        cout << "Enter priority of Job: ";
        cin >> priority;
        cout << "Enter time : ";
        cin >> Time;
    }

    void display() {
        cout << "Job name : " << jobname << endl;
        cout << "Priority : " << priority << endl;
        cout << "Time : " << Time << endl;
        cout << endl;
    }
};

class dequeujob {
    Job *front, *rear;

public:
    dequeujob() {
        front = rear = nullptr;
    }

    void pushfront(Job *nn) {
        nn->next = front;
        if (front != nullptr)
            front->prev = nn;
        front = nn;
        if (rear == nullptr)
            rear = nn;
    }

    void pushback(Job *nn) {
        if (rear != nullptr)
            rear->next = nn;
        nn->prev = rear;
        rear = nn;
        if (front == nullptr)
            front = nn;
    }
    
    void popfront() {
        if (front == nullptr) {
            cout << "Queue is Empty !!!" << endl;
            return;
        }
        Job *temp = front;
        front = front->next;
        cout << "Job Deleted is : " << endl;
        temp->display();
        delete temp;
        if (front != nullptr)
            front->prev = nullptr;
        else
            rear = nullptr;
    }

    void popback() {
        if (front == nullptr) {
            cout << "Queue is empty!!!" << endl;
            return;
        }
        Job *temp = rear;
        rear = rear->prev;
        cout << "Job Deleted is : " << endl;
        temp->display();
        delete temp;
        if (rear != nullptr)
            rear->next = nullptr;
        else
            front = nullptr;
    }

    void Display() {
        Job *cn = front;
        while (cn != nullptr) {
            cn->display();
            cn = cn->next;
        }
    }

    void addjob() {
        Job *nn = new Job;
        nn->read();
        if (front == nullptr) {
            front = rear = nn;
            return;
        }
        if (front->priority >= nn->priority) {
            pushfront(nn);
        }
        else if (rear->priority <= nn->priority) {
            pushback(nn);
        }
        else {
            cout << "Invalid Input of priority. Change priority of job !!!" << endl;
            delete nn;
        }
    }

    void removejob() {
        popfront();
    }

    void searchjob() {
        string jobtosearched;
        cout << "Enter the name of the job to be searched : ";
        cin >> jobtosearched;
        if (front == nullptr) {
            cout << "Queue is empty!!!" << endl;
            return;
        }
        Job *temp = front;
        while (temp != nullptr) {
            if (temp->jobname == jobtosearched) {
                cout << "The job '" << jobtosearched << "' is present." << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "The job '" << jobtosearched << "' is not present." << endl;
    }
};

int main() {
    dequeujob obj;
    int choice;
    cout << "1 -> Add Job with priority " << endl
         << "2 -> Remove Job " << endl
         << "3 -> Display Job " << endl
         << "4 -> Search the job" << endl
         << "5 -> EXIT THE PROGRAM..." << endl
         << endl;
    do {
        cout << "Enter the choice : ";
        cin >> choice;

        switch (choice) {
        case 1:
            obj.addjob();
            cout << endl;
            break;

        case 2:
            obj.removejob();
            cout << endl;
            break;

        case 3:
            obj.Display();
            cout << endl;
            break;

        case 4:
            obj.searchjob();
            cout << endl;
            break;

        case 5:
            cout << "Exit ..." << endl;
            break;

        default:
            cout << "INVALID CHOICE " << endl;
        }
    } while (choice != 5);
    return 0;
}
