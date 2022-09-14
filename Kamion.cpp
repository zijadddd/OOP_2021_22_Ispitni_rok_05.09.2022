#include "Kamion.h"

Kamion::Kamion()
{
    // Receno je u zadatku da se za klase Automobil i Kamion
    // uradi konstruktor i metoda za ispis.
    // Zato ovo radim u konstruktoru.
    std::cout << "Unesite karakteristike kamiona !\n";
    this->setImeVozila();
    this->setTezinaVozila();
    do {
        try {
            this->setBrojKonjskihSnaga();
            if (this->getBrojKonjskihSnaga() < 350) {
                throw "[GRESKA] Broj konjskih snaga kamiona mora biti veca od 349 !\nPonovo unesite broj konjskih snaga kamiona: ";
            }
        }
        catch (const char* Greska) {
            std::cout << Greska;
        }
    } while (this->getBrojKonjskihSnaga() < 350);
    do {
        try {
            this->setPogon();
            if (this->getPogon() == 0) {
                throw "[GRESKA] Kamion ne moze imati prednji pogon !\nPonovo unesite pogon kamiona: ";
            }
        }
        catch (const char* Greska) {
            std::cout << Greska;
        }
    } while (this->getPogon() == 0);
    this->setMjenjac();
    this->setNosivost();
}

void Kamion::setNosivost()
{
    std::cout << "Unesite nosivost kamiona: ";
    do {
        try {
            std::cin >> this->nosivost;
            // Ja sam ovdje 2 tone predstavio kao 2000 kg, mada nece biti greska ukoliko se promijeni i na manje jedinice kao npr 2 tone. 
            if (this->nosivost < 2000) {
                throw "[GRESKA] Nosivost kamiona mora biti minimalno 2 tone.\nPonovo unesite nosivost kamiona: ";
            }
        }
        catch (const char* Greska) {
            std::cout << Greska;
        }
    } while (this->nosivost < 2000);
    // Ovdje je iskoristen dio uslova iz zadatka koji kaze
    // da se prilikom unosa karakteristika kamiona bazi izuzetak
    // ukoliko nije zadovoljeno sljedece:
    // 1. Manje od 350 konjskih snaga
    // 2. Prednji pogon
    // 3. Nosivost manja od 2 tone - Zadovoljen uslov !
    // Ostali uslovi ce biti zadovoljeni u preopterecenom operatoru >> !
}

int Kamion::getNosivost()
{
    return this->nosivost;
}

double Kamion::getCijena()
{
    return this->nosivost * (this->nulaDoSto()/2);
}

char* Kamion::vratiTip()
{
    char tipVozila[6];
    strcpy_s(tipVozila, "Kamion");
    return tipVozila;
}
/*
std::istream& operator>>(std::istream& stream, Kamion& k)
{
    std::cout << "Unesite karakteristike kamiona !\n";
    k.setImeVozila();
    k.setTezinaVozila();
    do {
        try {
            k.setBrojKonjskihSnaga();
            if (k.getBrojKonjskihSnaga() < 350) {
                throw "[GRESKA] Broj konjskih snaga kamiona mora biti veca od 349 !\nPonovo unesite broj konjskih snaga kamiona: ";
            }
        }
        catch (const char* Greska) {
            std::cout << Greska;
        }
    } while (k.getBrojKonjskihSnaga() < 350);
    do {
        try {
            k.setPogon();
            if (k.getPogon() == 0) {
                throw "[GRESKA] Kamion ne moze imati prednji pogon !\nPonovo unesite pogon kamiona: ";
            }
        }
        catch (const char* Greska) {
            std::cout << Greska;
        }
    } while (k.getPogon() == 0);
    k.setMjenjac();
    k.setNosivost();
    return stream;
}
*/
std::ostream& operator<<(std::ostream& stream, Kamion& k)
{
    std::cout << "Podaci o kamionu\n";
    std::cout << "Ime kamiona: " << k.getImeVozila() << "\n";
    std::cout << "Tezina: " << k.getTezinaVozila() << "\n";
    std::cout << "Broj konjskih snaga: " << k.getBrojKonjskihSnaga() << "\n";
    std::cout << "Pogon: ";
    switch (k.getPogon()) {
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
    std::cout << "Mjenjac: ";
    switch (k.getMjenjac()) {
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
    std::cout << "Nula do sto funkcija: " << std::fixed << std::setprecision(2) << k.nulaDoSto() << "\n";
    std::cout << "Nosivost: " << k.getNosivost() << " kila. \n";
    std::cout << "Cijena: " << k.getCijena() << " KM.\n";
    return stream;
}
