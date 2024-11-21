#include<iostream>
#include <string>
#define capacity 10
using namespace std;

class supermarketsystem {
    string arr[capacity];
    int front, rear;
    public:
    supermarketsystem() {front = rear = -1;}
    
    bool isEmpty() {
        return front == -1;
    }

    void customerarrival(string name) {
        if((rear + 1) % capacity == front) {
            cout << "Queue is full. Can't Add More Customer." << endl;
            return;
        }
        else if(isEmpty()) {
            rear = front = 0;
            arr[rear] = name;
        }
        else {
            rear = (rear + 1) % capacity;
            arr[rear] = name;
        }
        cout << "The customer arrived in supermarket : " << arr[rear] << endl;
        return;
    }

    string customerCheckout() {
        if(isEmpty()) {
            cout << "Queue is Empty. No one is in the Queue." << endl;
            return "";
        }
        string name = arr[front];
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % capacity;
        }
        cout << "The customer checked out is : " << name << endl;
    }

    void closeCheckoutCounter() {
        front = rear = -1;
        cout << "Checkout counter closed. All customers removed." << endl;
    }

    void viewCustomers() {
        if(rear == -1 && front == -1) {
            cout << "Queue is Empty. No one is in the Queue." << endl;
            return;
        }
        cout << "View customers : " << endl; 
        int i = front;
        while(i != rear) {
            cout << arr[i] << endl;
            i = (i + 1) % capacity;
        }
        cout << arr[rear] << endl;
    }
};

int main() {
    supermarketsystem obj;
    string name;
    int choice;
    cout << "\n--- Supermarket Checkout System ---\n";
    cout << "1. Customer Arrival" << endl;
    cout << "2. Customer Checkout" << endl;
    cout << "3. Close Checkout Counter" << endl;
    cout << "4. View Customers" << endl;
    cout << "5. Exit!!!" << endl << endl;

    do {
        cout << "Enter the choice : ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter the Customer Name  : ";
                cin >> name;
                obj.customerarrival(name);
                cout << endl;
                break;

            case 2:
                obj.customerCheckout();
                cout << endl;
                break;

            case 3:
                obj.closeCheckoutCounter();
                cout << endl;
                break;
             
            case 4:
                obj.viewCustomers();
                cout << endl;
                break;

            case 5:
                cout << "Exiting Supermarket checkout System ......." << endl;
                break;

            default:
                cout << "Enter the correct choice." << endl;
        } 
    } while(choice != 5);

    return 0;
}
