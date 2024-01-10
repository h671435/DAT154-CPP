#include <iostream>
#include <string>
using namespace std;

int main() {
    // Define an integer and a pointer to an integer
    int x = 10;
    int y = 20;
    int* pi = nullptr; // Bruk nullptr i stedet for 0

    // Initialize the pointer via &, & gives the address
    pi = &x;

    // Print its contents * gives pointer content (dereference => get what it points to)
    wcout << L"The value of x is " << *pi << endl;

    pi = &y;
    wcout << L"The content of what pi points to is " << *pi << endl;

}
