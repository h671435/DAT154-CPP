#include <iostream>
#include <vector>
using namespace std;

class Car {
public:
    int number;
    int buyPrice;
    int sellPrice;

    Car(int nr, int bprice, int sprice) : number(nr), buyPrice(bprice), sellPrice(sprice) {
    }
};

class CarManager {
private:
    vector<Car> cars;

public:
    void BuyCar() {
        int nr, buy;
        wcout << L"Enter nr:";
        wcin >> nr;
        wcout << L"Enter buy price:";
        wcin >> buy;
        cars.push_back(Car(nr, buy, 0));
    }

    void SellCar() {
        int nr, sell;
        wcout << L"Enter nr:";
        wcin >> nr;
        wcout << L"Enter sell price:";
        wcin >> sell;

        bool carFound = false;

        for (auto &car: cars) {
            if (car.number == nr) {
                car.sellPrice = sell;
                carFound = true;
                wcout << L"Updated sell price for car " << nr << L" to: " << sell << "\n";
                break;
            }
        }

        if (!carFound) {
            wcout << L"Couldn't find car with number " << nr << "\n";
        }
    }

    void FindProfit() {
        int profit = 0;

        for (auto car : cars) {
            profit -= car.buyPrice;
            profit += car.sellPrice;
        }

        wcout << L"The total profit of the cars are: " << profit << "\n";
    }

    void ListCars() {
        for (auto car : cars) {
            wcout << "Car number: " << car.number << "\nBuy price: " << car.buyPrice << endl;
        }
    }


};


int main() {
    CarManager cm;
    int choice = 0;
    do {
        wcout << endl << L"List of choices" << endl;
        wcout << L"1 Buy a car" << endl;
        wcout << L"2 Sell a car" << endl;
        wcout << L"3 Find the profit" << endl;
        wcout << L"4 List all the cars" << endl;
        wcout << L"5 Cleanup list (remove sold cars)" << endl;
        wcout << L"0 Quit" << endl;
        wcin >> choice;

        switch (choice) {
                int nr, buy, i, sell;
            case 1: cm.BuyCar();
                break;
            case 2: cm.SellCar();
                break;
            case 3: cm.FindProfit();
                break;
            case 4: cm.ListCars();
                break;
        }
    } while (choice != 0);
}
