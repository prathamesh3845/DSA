#include <iostream>
#include <string>
using namespace std;

class Student {

public:
    int Roll_No;
    float CGPA;
    string Name;

    void get_data() {
	    cin>>Roll_No>>Name>>CGPA;
    }

    void display_data()  {
		cout<<"Roll : "<<Roll_No<<endl;
		cout<<"Name : "<<Name<<endl;
		cout<<"CGPA : "<<CGPA<<endl;
                cout<<endl;
    }

    friend void shellSort(Student S[], int n);
};

void shellSort(Student S[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            Student temp = S[i];
            int j;
            for (j = i; j >= gap && S[j - gap].Name  >  temp.Name; j -= gap) {
                S[j] = S[j - gap];
            }
            S[j] = temp;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of students  : ";
    cin >> n;
    Student S[n];
    cout<<"Enter data in format ---> Rollno | Name | CGPA   "<<endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter details of Student " << i + 1 <<"  : ";
        S[i].get_data();
    }

    shellSort(S, n);
    cout << endl << "\nSorted student data : \n" << endl;
    for (int i = 0; i < n; i++) {
        S[i].display_data();
    }

    return 0;
}

/*#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;
};

class linkedlist {
    node* head;

public:
    linkedlist() {
        head = NULL;
    }

    void add() {
        node* nn = new node;
        cout << "Enter data: ";
        cin >> nn->data;
        nn->next = NULL;
        nn->prev = NULL;

        if (head == NULL) {
            head = nn;
            return;
        }

        node* temp = head;
        while (temp->next != NULL) { // Stop at the last node
            temp = temp->next;
        }
        temp->next = nn; // Link new node at the end
        nn->prev = temp;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        node* temp = head;
        cout << "Forward Traversal: ";
        while (temp->next != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << temp->data << endl; // Print the last node

        cout << "Backward Traversal: ";
        while (temp != NULL) { // Traverse back to the head
            cout << temp->data << " -> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl; // Indicate the end
    }
};

int main() {
    linkedlist l;
    l.add();
    l.add();
    l.add();
    l.display();
    return 0;
}
*/