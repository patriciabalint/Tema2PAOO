#include <iostream>
#include <string>

class Car {
    std::string nume;
    int locuri;

public:
    // Constructor explicit care initializează obiectul
    Car(const std::string& nume, int locuri)
        : nume(nume), locuri(locuri) {}

    // Dezactivăm copy constructorul și operatorul de atribuire
    Car(const Car&) = delete; // Copy constructor
    Car& operator=(const Car&) = delete; // Operator de atribuire

    void afiseaza() const {
        std::cout << "Marca car: " << nume << ", Locuri: " << locuri << "\n";
    }

    // Destructor
    ~Car() {
        std::cout << "Mașina '" << nume << "' distrusă prin destructor.\n";
    }
};

int main() {
    // Inițializarea obiectului c1
    Car c1("Tesla Model 3", 5);
    c1.afiseaza();

    // Încercarea de a crea un alt obiect prin copiere va da eroare
    // Car c2 = c1; // Va da eroare pentru că copy constructorul a fost șters

    Car c3("BMW X5", 7);
    c3.afiseaza();

    // Încercarea de a atribui un obiect altuia va da eroare
    // c3 = c1; // Va da eroare pentru că operatorul de atribuire a fost șters

    return 0;
}