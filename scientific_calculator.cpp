
#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

// Function declarations
void showMenu();
double getNumber(const string& prompt);
void performOperation(int choice);
long long factorial(int n);

int main() {
    int choice;
    bool running = true;

    cout << "====================================\n";
    cout << "        SCIENTIFIC CALCULATOR       \n";
    cout << "====================================\n";

    while (running) {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Exiting Calculator. Goodbye!\n";
            break;
        }

        performOperation(choice);
        cout << "\n------------------------------------\n";
    }

    return 0;
}

void showMenu() {
    cout << "\nChoose Operation:\n";
    cout << " 1. Addition (+)\n";
    cout << " 2. Subtraction (-)\n";
    cout << " 3. Multiplication (*)\n";
    cout << " 4. Division (/)\n";
    cout << " 5. Modulus (%)\n";
    cout << " 6. Power (x^y)\n";
    cout << " 7. Square Root (√x)\n";
    cout << " 8. Natural Log (ln)\n";
    cout << " 9. Log Base 10 (log10)\n";
    cout << "10. Exponential (e^x)\n";
    cout << "11. Sine (sin)\n";
    cout << "12. Cosine (cos)\n";
    cout << "13. Tangent (tan)\n";
    cout << "14. Factorial (n!)\n";
    cout << " 0. Quit\n";
}

double getNumber(const string& prompt) {
    double num;
    while (true) {
        cout << prompt;
        cin >> num;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            return num;
        }
    }
}

void performOperation(int choice) {
    double num1, num2;

    switch (choice) {
        case 1:
            num1 = getNumber("Enter first number: ");
            num2 = getNumber("Enter second number: ");
            cout << "Result: " << num1 + num2;
            break;

        case 2:
            num1 = getNumber("Enter first number: ");
            num2 = getNumber("Enter second number: ");
            cout << "Result: " << num1 - num2;
            break;

        case 3:
            num1 = getNumber("Enter first number: ");
            num2 = getNumber("Enter second number: ");
            cout << "Result: " << num1 * num2;
            break;

        case 4:
            num1 = getNumber("Enter numerator: ");
            do {
                num2 = getNumber("Enter denominator (non-zero): ");
                if (num2 == 0) cout << "Cannot divide by zero!\n";
            } while (num2 == 0);
            cout << "Result: " << num1 / num2;
            break;

        case 5:
            int a, b;
            cout << "Enter two integers:\n";
            cin >> a >> b;
            while (b == 0) {
                cout << "Second number cannot be zero. Re-enter: ";
                cin >> b;
            }
            cout << "Result: " << a % b;
            break;

        case 6:
            num1 = getNumber("Enter base (x): ");
            num2 = getNumber("Enter exponent (y): ");
            cout << "Result: " << pow(num1, num2);
            break;

        case 7:
            num1 = getNumber("Enter number: ");
            if (num1 < 0)
                cout << "Error: Cannot take square root of negative number.";
            else
                cout << "Result: " << sqrt(num1);
            break;

        case 8:
            num1 = getNumber("Enter number: ");
            if (num1 <= 0)
                cout << "Error: ln(x) is undefined for x <= 0.";
            else
                cout << "Result: " << log(num1);
            break;

        case 9:
            num1 = getNumber("Enter number: ");
            if (num1 <= 0)
                cout << "Error: log10(x) is undefined for x <= 0.";
            else
                cout << "Result: " << log10(num1);
            break;

        case 10:
            num1 = getNumber("Enter exponent: ");
            cout << "Result: " << exp(num1);
            break;

        case 11:
            num1 = getNumber("Enter angle (in degrees): ");
            cout << "Result: " << sin(num1 * M_PI / 180);
            break;

        case 12:
            num1 = getNumber("Enter angle (in degrees): ");
            cout << "Result: " << cos(num1 * M_PI / 180);
            break;

        case 13:
            num1 = getNumber("Enter angle (in degrees): ");
            cout << "Result: " << tan(num1 * M_PI / 180);
            break;

        case 14:
            int n;
            cout << "Enter a non-negative integer: ";
            cin >> n;
            if (n < 0) {
                cout << "Factorial is undefined for negative numbers.";
            } else {
                cout << "Result: " << factorial(n);
            }
            break;

        default:
            cout << "Invalid choice. Please select from the menu.";
    }
}

// Function to calculate factorial of a number
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}
