#include<iostream>
using namespace std;

class Polynomial;

struct Node {
    int coef;  
    int power; 
    Node *next; 
};

class Polynomial {
public:
    Node *head; 

    Polynomial() {
        head = nullptr;
    }

    void insertNode(int coef, int power) {
        Node *newNode = new Node;
        newNode->coef = coef;
        newNode->power = power;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node *current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void displayPolynomial() {
        if (head == nullptr) {
            cout << "No Polynomial" << endl;
        } else {
            Node *current = head;
            while (current != nullptr) {
                cout << current->coef << "x^" << current->power;
                if (current->next != nullptr) {
                    cout << " + ";
                }
                current = current->next;
            }
            cout << endl;
        }
    }

    friend Polynomial addPolynomial(Polynomial &p1, Polynomial &p2);
};

Polynomial addPolynomial(Polynomial &p1, Polynomial &p2) {
    Polynomial result;
    Node *cn1 = p1.head;
    Node *cn2 = p2.head;

    while (cn1 != nullptr && cn2 != nullptr) {
        if (cn1->power > cn2->power) {
            result.insertNode(cn1->coef, cn1->power);
            cn1 = cn1->next;
        } else if (cn1->power < cn2->power) {
            result.insertNode(cn2->coef, cn2->power);
            cn2 = cn2->next;
        } else {
            int sumCoef = cn1->coef + cn2->coef;
            result.insertNode(sumCoef, cn1->power);
            cn1 = cn1->next;
            cn2 = cn2->next;
        }
    }

    while (cn1 != nullptr) {
        result.insertNode(cn1->coef, cn1->power);
        cn1 = cn1->next;
    }

    while (cn2 != nullptr) {
        result.insertNode(cn2->coef, cn2->power);
        cn2 = cn2->next;
    }

    return result;
}

int main() {
    Polynomial p1, p2;

    cout << "1: Insert terms in polynomials." << endl;
    cout << "2: Display polynomials." << endl;
    cout << "3: Add the two polynomials." << endl;

    int choice;
    do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int n, coef, power;
            cout << "\nEnter the number of terms in polynomial p1: ";
            cin >> n;
            for (int i = 0; i < n; ++i) {
                cout << "Enter coefficient and power: ";
                cin >> coef >> power;
                p1.insertNode(coef, power);
            }

            cout << "\nEnter the number of terms in polynomial p2: ";
            cin >> n;
            for (int i = 0; i < n; ++i) {
                cout << "Enter coefficient and power: ";
                cin >> coef >> power;
                p2.insertNode(coef, power);
            }
            break;
        }
        case 2:
            cout << "\nPolynomial P1: ";
            p1.displayPolynomial();
            cout << "\nPolynomial P2: ";
            p2.displayPolynomial();
            break;

        case 3: {
            cout << "\nAddition of the two polynomials: ";
            Polynomial result = addPolynomial(p1, p2);
            result.displayPolynomial();
            break;
        }

        default:
            cout << "Please enter a valid choice." << endl;
        }
    } while (choice != 3);

    return 0;
}