#include "Automobil.h"

Automobil::Automobil()
{
    // Receno je u zadatku da se za klase Automobil i Kamion
    // uradi konstruktor i metoda za ispis.
    // Zato ovo radim u konstruktoru.
    std::cout << "\t\t\t\t  Unesite karakteristike automobila !\n";
    this->setImeVozila();
    this->setTezinaVozila();
    this->setBrojKonjskihSnaga();
    this->setPogon();
    this->setMjenjac();
    this->setRokOtplate();
}

void Automobil::setRokOtplate()
{
    do {
        std::cout << "\t\t\t\t  Unesite rok otplate automobila: ";
        std::cin >> this->rokOtplate;
        if (this->rokOtplate < 0) {
            std::cout << "\t\t\t\t  [GRESKA] Rok otplate ne moze biti manji od 0 !\n";
        }
    } while (this->rokOtplate < 0);
}

int Automobil::getRokOtplate()
{
    return this->rokOtplate;
}

double Automobil::getMjesecnaRata()
{
    // Ovdje pretpostavljam da treba uraditi sljedece:
    // Ako je npr. rok otplate 7 mjeseci da ce se mjesecna 
    // rata povecati za 5%. Tako da cu odma to racunat.
    double rata = 5 * this->getBrojKonjskihSnaga();
    for (int i = 0; i < getRokOtplate() / 6; i++) rata *= 1.05;
    return rata;
}

double Automobil::getCijena()
{
    return this->getMjesecnaRata() * this->getRokOtplate();
}

char* Automobil::vratiTip()
{
    char tipVozila[6];
    strcpy_s(tipVozila, "Automobil");
    return tipVozila;
}

std::ostream& operator<<(std::ostream& stream, Automobil& a)
{
    std::cout << "\t\t\t\t  Podaci o kamionu\n";
    std::cout << "\t\t\t\t  Ime kamiona: " << a.getImeVozila() << "\n";
    std::cout << "\t\t\t\t  Tezina: " << a.getTezinaVozila() << "\n";
    std::cout << "\t\t\t\t  Broj konjskih snaga: " << a.getBrojKonjskihSnaga() << "\n";
    std::cout << "\t\t\t\t  Pogon: ";
    switch (a.getPogon()) {
    case 0:
        std::cout << "FWD\n";
        break;
    case 1:
        std::cout << "RWD\n";
        break;
    case 2:
        std::cout << "AWD\n";
        break;
    }
    std::cout << "\t\t\t\t  Mjenjac: ";
    switch (a.getMjenjac()) {
    case 0:
        std::cout << "MANUAL\n";
        break;
    case 1:
        std::cout << "AUTOMATIC\n";
        break;
    case 2:
        std::cout << "DUAL CLUTCH\n";
        break;
    }
    std::cout << "\t\t\t\t  Nula do sto funkcija: " << std::fixed << std::setprecision(2) << a.nulaDoSto() << "\n";
    std::cout << "\t\t\t\t  Rok otplate: " << a.getRokOtplate() << " mjeseci\n";
    std::cout << "\t\t\t\t  Mjesecna rata: " << a.getMjesecnaRata() << " KM\n";
    std::cout << "\t\t\t\t  Ukupna cijena: " << a.getCijena() << " KM\n";
    return stream;
}
