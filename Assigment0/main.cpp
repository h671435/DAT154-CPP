#include <iostream>
using namespace std;

int lengdeFunction(wchar_t *p) {
    int i = 0;
    for (; *p; p++) {
        i++;
    }
    return i;
}

int CountDoubleChars(wchar_t* pch) {
    int antallDobbel = 0;
    while (*pch) {
        if (*pch == *(pch + 1)) {
            antallDobbel++;
        }
        pch++;
    }
    return antallDobbel;
}


int main() {
    /* Oppgave 1 / 2
    wchar_t buffer[25];

    wcout << L"Enter a word: ";
    wcin >> buffer;

    wcout << L"You typed: " << buffer << "\n";

    lengdeFunction(buffer);*/

    // Oppgave 3
    // The output below should be 3 (the double m’s)
    wchar_t s[] = L"Ammount of summers drummers - ";
    wcout << s << L" number of doublechars : " << CountDoubleChars(s);

    return 0;
}
