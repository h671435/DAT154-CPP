#include <iostream>
using namespace std;

void BuyCar(int *pnr, int *pbuy) {
    wcout << L"Enter nr:";
    wcin >> *pnr;
    wcout << L"Enter price:";
    wcin >> *pbuy;
}

void SellCar(int *pnr, int *psell) {
    wcout << L"Enter nr:";
    wcin >> *pnr;
    wcout << L"Enter price:";
    wcin >> *psell;
}

void ListCars(int *pnr, int *pbuy, int n) {
    for (int i = 0; i < n; i++)
        wcout << L"Carnr: " << *(pnr + i) << L" Price: " << *(pbuy + i) << endl;
}

int main() {
    int carnr[1000];
    int buyprice[1000];
    int sellprice[1000];
    int choice = 0;
    int idx = 0;
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
            case 1: BuyCar(&nr, &buy);
                carnr[idx] = nr;
                buyprice[idx] = buy;
                sellprice[idx] = 0;
                idx++;
                break;
            case 2: SellCar(&nr, &sell);
                i = 0;
                while (i < idx && carnr[i] != nr) {
                    ++i;
                }
                if (i < idx) {
                    sellprice[i] = sell;
                    wcout << L"Set car " << nr << L" to sold price lol? " << sell << "\n";
                } else {
                    wcout << L"Couldnt find car with number " << nr << "\n";
                }
                break;
            case 4: ListCars(carnr, buyprice, idx);
                break;
        }
    } while (choice != 0);
}
