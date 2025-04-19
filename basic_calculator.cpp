
#include <iostream>
#include <limits> // For input validation
using namespace std;

// Function declarations
void showMenu();
void performCalculation(char choice);
double getNumber(const string& prompt);

int main() {
    char choice;
    bool running = true;

    cout << "=============================
";
    cout << "     SIMPLE C++ CALCULATOR   
";
    cout << "=============================
";

    while (running) {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 'q' || choice == 'Q') {
            running = false;
            cout << "Exiting Calculator. Goodbye!\n";
        } else {
            performCalculation(choice);
        }

        cout << "\n-----------------------------\n";
    }

    return 0;
}

// Function to show the calculator menu
void showMenu() {
    cout << "\nChoose Operation:\n";
    cout << "1. Addition (+)\n";
    cout << "2. Subtraction (-)\n";
    cout << "3. Multiplication (*)\n";
    cout << "4. Division (/)\n";
    cout << "5. Modulus (%) [integers only]\n";
    cout << "Q. Quit\n";
}

// Function to safely get a number from the user
double getNumber(const string& prompt) {
    double num;
    while (true) {
        cout << prompt;
        cin >> num;
        if (cin.fail()) {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear(); // clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        } else {
            return num;
        }
    }
}

// Function to perform selected calculation
void performCalculation(char choice) {
    double num1, num2;

    switch (choice) {
        case '1':
        case '+':
            num1 = getNumber("Enter first number: ");
            num2 = getNumber("Enter second number: ");
            cout << "Result: " << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
            break;

        case '2':
        case '-':
            num1 = getNumber("Enter first number: ");
            num2 = getNumber("Enter second number: ");
            cout << "Result: " << num1 << " - " << num2 << " = " << (num1 - num2) << endl;
            break;

        case '3':
        case '*':
            num1 = getNumber("Enter first number: ");
            num2 = getNumber("Enter second number: ");
            cout << "Result: " << num1 << " * " << num2 << " = " << (num1 * num2) << endl;
            break;

        case '4':
        case '/':
            num1 = getNumber("Enter numerator: ");
            do {
                num2 = getNumber("Enter denominator (non-zero): ");
                if (num2 == 0) {
                    cout << "Denominator cannot be zero.\n";
                }
            } while (num2 == 0);
            cout << "Result: " << num1 << " / " << num2 << " = " << (num1 / num2) << endl;
            break;

        case '5':
        case '%':
            int int1, int2;
            cout << "Enter first integer: ";
            cin >> int1;
            cout << "Enter second integer (non-zero): ";
            while (true) {
                cin >> int2;
                if (int2 == 0) {
                    cout << "Second number cannot be zero. Try again: ";
                } else {
                    break;
                }
            }
            cout << "Result: " << int1 << " % " << int2 << " = " << (int1 % int2) << endl;
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
    }
}
