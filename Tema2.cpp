#include <iostream>
#include <string>

// Item 4: Asigură-te că obiectele sunt inițializate înainte de utilizare
// Item 5: Cunoaște funcțiile pe care C++ le generează automat
// Item 6: Șterge explicit funcțiile generate pe care nu le dorești

class Bus {
    std::string routeName;
    int seats; // numărul de locuri

public:
    // Constructor care inițializează toți membrii (Item 4)
    Bus(const std::string& routeName, int seats)
        : routeName(routeName), seats(seats) {}

    Bus(const Bus&) = delete; // Ștergem copy constructorul (Item 6)

    Bus& operator=(const Bus&) = delete; // Ștergem operatorul de atribuire (Item 6)

    void display() const {
        std::cout << "Rută autobuz: " << routeName << ", Număr de locuri: " << seats << "\n";
    } // Funcție pentru afișarea informațiilor despre autobuz

    // Destructor pentru distrugerea obiectelor
    ~Bus() {
        std::cout << "Autobuzul de pe ruta '" << routeName << "' a fost distrus.\n";
    }
};

int main() {
    // Inițializăm un obiect Bus
    Bus bus1("Linia 21", 50); // Autobuz cu 50 de locuri
    bus1.display();

    // Încercăm să copiem autobuzul (va da eroare pentru că am șters copy constructorul)
    // Bus bus2 = bus1; // Această linie va genera eroare!

    Bus bus3("Linia 335", 30); // Creăm alt autobuz
    bus3.display();

    // Încercăm să atribuim un autobuz altuia (va da eroare pentru că am șters operatorul=)
    // bus2 = bus1; // Această linie va genera eroare!

    return 0;
}
