#include <iostream>
//#include <cmath>
using namespace std;

class Node {
public:
    int coefficient;
    int exponent;
    Node* next;

    Node(int coeff, int exp) : coefficient(coeff), exponent(exp), next(NULL) {}
};

class Polynomial {
private:
    Node* head;

    void insertInOrder(int coeff, int exp) {
        Node* newNode = new Node(coeff, exp);
        if (!head || head->exponent < exp) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next && current->next->exponent > exp) {
                current = current->next;
            }
            if (current->next && current->next->exponent == exp) {
                current->next->coefficient += coeff;
                if (current->next->coefficient == 0) {
                    Node* temp = current->next;
                    current->next = current->next->next;
                    delete temp;
                }
                delete newNode;
            }
            else {
                newNode->next = current->next;
                current->next = newNode;
            }
        }
    }

public:
    Polynomial() : head(nullptr) {}

    ~Polynomial() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertTerm(int coeff, int exp) {
        if (coeff != 0)
            insertInOrder(coeff, exp);
    }

    void display() const {
        if (!head) {
            cout << "0" << endl;
            return;
        }
        Node* current = head;
        while (current) {
            cout << (current->coefficient > 0 && current != head ? "+" : "")
                << current->coefficient << "x^" << current->exponent;
            current = current->next;
        }
        cout << endl;
    }

    Polynomial operator+(const Polynomial& other) const {
        Polynomial result;
        Node* p1 = head;
        Node* p2 = other.head;

        while (p1 || p2) {
            if (p1 && (!p2 || p1->exponent > p2->exponent)) {
                result.insertTerm(p1->coefficient, p1->exponent);
                p1 = p1->next;
            }
            else if (p2 && (!p1 || p2->exponent > p1->exponent)) {
                result.insertTerm(p2->coefficient, p2->exponent);
                p2 = p2->next;
            }
            else {
                result.insertTerm(p1->coefficient + p2->coefficient, p1->exponent);
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return result;
    }

    Polynomial operator-(const Polynomial& other) const {
        Polynomial result;
        Node* p1 = head;
        Node* p2 = other.head;

        while (p1 || p2) {
            if (p1 && (!p2 || p1->exponent > p2->exponent)) {
                result.insertTerm(p1->coefficient, p1->exponent);
                p1 = p1->next;
            }
            else if (p2 && (!p1 || p2->exponent > p1->exponent)) {
                result.insertTerm(-p2->coefficient, p2->exponent);
                p2 = p2->next;
            }
            else {
                result.insertTerm(p1->coefficient - p2->coefficient, p1->exponent);
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return result;
    }

    Polynomial operator*(const Polynomial& other) const {
        Polynomial result;
        for (Node* p1 = head; p1; p1 = p1->next) {
            for (Node* p2 = other.head; p2; p2 = p2->next) {
                result.insertTerm(p1->coefficient * p2->coefficient, p1->exponent + p2->exponent);
            }
        }
        return result;
    }

    int evaluate(int x) const {
        int result = 0;
        for (Node* current = head; current; current = current->next) {
            result += current->coefficient * pow(x, current->exponent);
        }
        return result;
    }
};


void inputPolynomial(Polynomial& poly) {
    int n;
    cout << "\n Enter the number of terms in the polynomial: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int coeff, exp;
        cout << "\n Enter coefficient and exponent for term " << i + 1 << " : ";
        cin >> coeff >> exp;
        poly.insertTerm(coeff, exp);
    }
}


void menu() {
    Polynomial p1, p2;

    while (true) {
        cout << "\n Polynomial Operations Menu:";
        cout << "\n 1. Add terms to Polynomial 1";
        cout << "\n 2. Add terms to Polynomial 2";
        cout << "\n 3. Display Polynomials";
        cout << "\n 4. Add Polynomials";
        cout << "\n 5. Subtract Polynomials";
        cout << "\n 6. Multiply Polynomials";
        cout << "\n 7. Evaluate a Polynomial";
        cout << "\n 8. Exit\n";
        cout << "\n Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\n Adding terms to Polynomial 1:\n";
            inputPolynomial(p1);
            break;
        case 2:
            cout << "\n Adding terms to Polynomial 2:\n";
            inputPolynomial(p2);
            break;
        case 3:
            cout << "\n Polynomial 1: ";
            p1.display();
            cout << "\n Polynomial 2: ";
            p2.display();
            break;
        case 4: {
            Polynomial sum = p1 + p2;
            cout << "\n Sum: ";
            sum.display();
            break;
        }
        case 5: {
            Polynomial diff = p1 - p2;
            cout << "\n Difference: ";
            diff.display();
            break;
        }
        case 6: {
            Polynomial prod = p1 * p2;
            cout << "\n Product: ";
            prod.display();
            break;
        }
        case 7: {
            int polyChoice, x;
            cout << "\n Evaluate which polynomial (1 or 2) ? ";
            cin >> polyChoice;
            cout << "\n Enter the value of x: ";
            cin >> x;
            if (polyChoice == 1)
                cout << "\n Polynomial 1 evaluated at x = " << x << ": " << p1.evaluate(x) << endl;
            else if (polyChoice == 2)
                cout << "\n Polynomial 2 evaluated at x = " << x << ": " << p2.evaluate(x) << endl;
            else
                cout << "\n Invalid choice.";
            break;
        }
        case 8:
            cout << "\n Exiting the program.";
            return;
        default:
            cout << "\n Invalid choice. Try again.";
        }
    }
}

int main() {
    string choice;
    do {

    menu();
    cout << "\n Do you to continue(press y): ";
    cin >> choice;
    } while (choice == "Yes" || choice == "yes" || choice == "y" || choice == "Y"  );
    return 0;
}
