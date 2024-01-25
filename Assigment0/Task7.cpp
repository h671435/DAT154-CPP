#include <deque>
#include <iostream>
#include <string>

using namespace std;

class Car {
public:
    wstring color;

public:
    Car(wstring color) : color(color) {
    }
};

typedef deque<Car> koe;

class Garage {
public:
    int MAX_SIZE = 5;
    koe carKoe;

    void driveCar(wstring carColor) {
        if (carKoe.size() < MAX_SIZE) {
            carKoe.push_back(Car(carColor));
            wcout << L"Car with color " << carColor << L" driven into the garage." << endl;
        } else {
            wcout << L"The garage is full, please try another time" << endl;
        }
    }

    void reverseCar() {
        if (carKoe.empty()) {
            wcout << L"The garage is empty. There are no cars to drive out." << endl;
        } else {
            wcout << L"Car with color " << carKoe.front().color << L" has left the garage" << endl;
            carKoe.pop_front();
        }
    }
};

int main() {
    Garage ga;
    int choice = 0;
    do {
        wcout << endl << L"1 Drive a red car into the garage" << endl;
        wcout << L"2 Drive a blue car into the garage" << endl;
        wcout << L"3 Drive a green car into the garage" << endl;
        wcout << L"4 Drive the car out of the garage" << endl;
        wcout << L"0 Quit" << endl;
        wcin >> choice;

        switch (choice) {
            case 1:
                ga.driveCar(L"Red");
                break;
            case 2:
                ga.driveCar(L"Blue");
                break;
            case 3:
                ga.driveCar(L"Green");
                break;
            case 4:
                ga.reverseCar();
                break;
            default:
                wcout << L"Write a number between 0 and 4" << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
