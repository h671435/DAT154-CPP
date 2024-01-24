#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    wcout << L"Skriv inn et ord per linje, send inn en tom linje for å stoppe\n" << endl;
    vector<wstring> ord;

    while (true) {
        wstring input;
        getline(wcin, input);
        if (input.empty()) {
            break;
        }
        ord.push_back(input);
    }

    sort(ord.begin(), ord.end());
    for (vector<wstring>::iterator i = ord.begin(); i < ord.end(); i++) {
        wcout << *i << endl;
    }

    return 0;
}
