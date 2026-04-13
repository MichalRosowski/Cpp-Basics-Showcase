#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>

using namespace std;

// --- FUNKCJE POMOCNICZE ---

void waitForKey() {
    cout << "\nNacisnij Enter, aby kontynuowac...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// --- MODUŁY ---

void playMiniSlot() {
    clearScreen();
    srand(time(NULL));
    cout << "===========================" << endl;
    cout << "   MINI SLOT MACHINE       " << endl;
    cout << "===========================" << endl;
    cout << "Losowanie... [Enter]" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    int s1 = rand() % 7 + 1; 
    int s2 = rand() % 7 + 1;
    int s3 = rand() % 7 + 1;

    cout << "\n   [ " << s1 << " | " << s2 << " | " << s3 << " ]\n" << endl;

    if (s1 == s2 && s2 == s3) {
        cout << "JACKPOT!!! Gratulacje!" << endl;
    } else if (s1 == s2 || s2 == s3 || s1 == s3) {
        cout << "Dwie takie same! Mala wygrana." << endl;
    } else {
        cout << "Brak wygranej. Sprobuj ponownie!" << endl;
    }
    waitForKey();
}

void playGuessNumber() {
    clearScreen();
    srand(time(NULL));
    int liczba = rand() % 100 + 1; 
    int strzal = 0;
    int proby = 0;

    cout << "=== GRA: ZGADNIJ LICZBE ===" << endl;
    cout << "Komputer wylosowal liczbe od 1 do 100." << endl;

    while (strzal != liczba) {
        cout << "Podaj swoj strzal: ";
        if (!(cin >> strzal)) {
            cout << "Blad! Podaj poprawna liczbe." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        proby++;
        if (strzal > liczba) cout << "Za duzo!" << endl;
        else if (strzal < liczba) cout << "Za malo!" << endl;
        else cout << "Odgadles w " << proby << " probach!" << endl;
    }
    waitForKey();
}

void checkPrimeNumber() {
    clearScreen();
    int liczba;
    cout << "=== TEST LICZBY PIERWSZEJ ===" << endl;
    cout << "Podaj liczbe: ";
    if (!(cin >> liczba)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } else {
        if(liczba < 2) cout << "Nie jest pierwsza." << endl;
        else if(liczba == 2 || liczba == 3) cout << "Jest pierwsza." << endl;
        else {
            bool pierwsza = true;  
            for (int i = 5; i * i <= liczba; i += 6) {
                if (liczba % i == 0 || liczba % (i + 2) == 0) {
                    pierwsza = false; 
                    break;
                }
            }
            if (pierwsza) cout << "Liczba jest pierwsza." << endl;
            else cout << "Liczba nie jest pierwsza." << endl;
        }
    }
    waitForKey();
}

// --- MENU GŁÓWNE ---

int main() {
    while (true) {
        clearScreen();
        int wybor;
        cout << "====================================" << endl;
        cout << "   C++ PROJECTS   " << endl;
        cout << "====================================" << endl;
        cout << "1. Mini Slot Machine" << endl;
        cout << "2. Gra: Zgadnij liczbe" << endl;
        cout << "3. Algorytm: Liczba pierwsza" << endl;
        cout << "4. O projekcie (Credits)" << endl;
        cout << "5. Wyjscie" << endl;
        cout << "------------------------------------" << endl;
        cout << "Wybor: ";
        
        if (!(cin >> wybor)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (wybor) {
            case 1: playMiniSlot(); break;
            case 2: playGuessNumber(); break;
            case 3: checkPrimeNumber(); break;
            case 4:
                clearScreen();
                cout << "====================================" << endl;
                cout << "           CREDITS                  " << endl;
                cout << "====================================" << endl;
                cout << "Autor: Michal Rosowski" << endl;
                cout << "\nOpis:" << endl;
                cout << "To jest projekt zbiorczy, w ktorym polaczylem" << endl;
                cout << "rozne mniejsze programy i cwiczenia stworzone" << endl;
                cout << "przeze mnie podczas nauki jezyka C++." << endl;
                cout << "\nCalosc zostala uporzadkowana w formie" << endl;
                cout << "modularnej aplikacji z menu sterujacym." << endl;
                cout << "====================================" << endl;
                waitForKey();
                break;
            case 5: return 0;
            default: waitForKey(); break;
        }
    }
    return 0;
}