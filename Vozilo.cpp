#include "Vozilo.h"

Vozilo::Vozilo()
{
    strcpy_s(this->imeVozila, "Vozilo");
    this->tezinaVozila = 0;
    this->brojKonjskihSnaga = 0; 
    this->pogon = FWD;
    this->mjenjac = MANUAL;
}

void Vozilo::setImeVozila()
{
    do {
        std::cout << "\t\t\t\t  Unesite ime vozila: ";
        std::cin.getline(this->imeVozila, sizeof this->imeVozila);
        if (strlen(this->imeVozila) == 0 || strlen(this->imeVozila) < 3) std::cout << "\t\t\t\t  [GRESKA]Niste pravilno unijeli ime vozila!\n\t\t\t\t  Ime mora sadrzavati minimalno 3 karaktera.\n";
    } while (strlen(this->imeVozila) == 0 || strlen(this->imeVozila) < 3);
    std::cout << "\t\t\t\t  [INFO] Uspjesno ste postavili ime vozila.\n";
}

void Vozilo::setTezinaVozila()
{
    do {
        std::cout << "\t\t\t\t  Unesite tezinu vozila: ";
        std::cin >> this->tezinaVozila;
        if (this->tezinaVozila < 100 || this->tezinaVozila > 50000) std::cout << "\t\t\t\t  [GRESKA] Niste pravilno unijeli tezinu vozila!\n\t\t\t\t  Tezina vozila mora biti u rasponu 100-50000 kg.\n";
    } while (this->tezinaVozila < 100 || this->tezinaVozila > 50000);
    std::cout << "\t\t\t\t  [INFO] Uspjesno ste postavili tezinu vozila.\n";
}

void Vozilo::setBrojKonjskihSnaga()
{
    do {
        std::cout << "\t\t\t\t  Unesite broj konjskih snaga vozila: ";
        std::cin >> this->brojKonjskihSnaga;
        if (this->brojKonjskihSnaga < 20 || this->brojKonjskihSnaga > 2000) std::cout << "\t\t\t\t  [GRESKA] Niste pravilno unijeli broj konjskih snaga vozila!\n\t\t\t\t  Broj konjskih snaga mora biti u rasponu 20-2000.\n";
    } while (this->brojKonjskihSnaga < 20 || this->brojKonjskihSnaga > 2000);
    // Maksimalni broj konjskih snaga sam dao onako, nez kako se krecu 
    std::cout << "\t\t\t\t  [INFO] Uspjesno ste postavili broj konjskih snaga vozila.\n";
}

void Vozilo::setPogon()
{
    int choice = 0; 
    do {
        std::cout << "\t\t\t\t  Moguci pogoni: FWD = 0 | RWD = 1 | AWD = 2\n\t\t\t\t  Unesite pogon vozila: ";
        std::cin >> choice;
        if (choice < 0 || choice > 2) std::cout << "\t\t\t\t  [GRESKA] Niste pravilno unijeli pogon vozila!\n\t\t\t\t  Odabir pogona mora biti u rasponu 0-2.\n";
    } while (choice < 0 || choice > 2);
    switch(choice) {
    case 0:
        this->pogon = FWD;
        break;
    case 1:
        this->pogon = RWD;
        break;
    case 2: 
        this->pogon = AWD;
        break;
    }
    std::cout << "\t\t\t\t  [INFO] Uspjesno ste postavili pogon vozila.\n";
}

void Vozilo::setMjenjac()
{
    int choice = 0;
    do {
        std::cout << "\t\t\t\t  Moguci mjenjaci: MANUAL = 0 | AUTOMATIC = 1 | DUAL_CLUTCH = 2\n\t\t\t\t  Unesite mjenjac vozila: ";
        std::cin >> choice;
        if (choice < 0 || choice > 2) std::cout << "\t\t\t\t  [GRESKA] Niste pravilno unijeli mjenjac vozila!\n\t\t\t\t  Odabir mjenjaca mora biti u rasponu 0-2.\n";
    } while (choice < 0 || choice > 2);
    switch (choice) {
    case 0:
        this->mjenjac = MANUAL;
        break;
    case 1:
        this->mjenjac = AUTOMATIC;
        break;
    case 2:
        this->mjenjac = DUAL_CLUTCH;
        break;
    }
    std::cout << "\t\t\t\t  [INFO] Uspjesno ste postavili mjenjac vozila.\n";
}

char* Vozilo::getImeVozila()
{
    return this->imeVozila;
}

int Vozilo::getTezinaVozila()
{
    return this->tezinaVozila;
}

int Vozilo::getBrojKonjskihSnaga()
{
    return this->brojKonjskihSnaga;
}

Pogon Vozilo::getPogon()
{
    return this->pogon;
}

Mjenjac Vozilo::getMjenjac()
{
    return this->mjenjac;
}

double Vozilo::faktorPogona()
{
    switch (this->pogon) {
    case FWD: 
        return 1;
    case RWD:
        return 0.9;
    case AWD:
        return 0.85;
    }
}

double Vozilo::faktorPrenosa()
{
    switch (this->mjenjac) {
    case MANUAL:
        return 1;
    case AUTOMATIC:
        return 1.1;
    case DUAL_CLUTCH:
        return 0.925;
    }
}

double Vozilo::getCijena()
{
    return 0;
}

char* Vozilo::vratiTip()
{
    return nullptr;
}

double Vozilo::nulaDoSto()
{
    double result = pow(this->getTezinaVozila() * (2.2046 / this->getBrojKonjskihSnaga()) * 0.9 * this->faktorPogona() * this->faktorPrenosa(), 3);
    result = pow(result, 0.25);
    // 0.25 = 1/4 = ili 4 korijen
    return result;
}

std::istream& operator>>(std::istream& stream, Vozilo& v)
{
    v.setImeVozila();
    v.setTezinaVozila();
    v.setBrojKonjskihSnaga();
    v.setPogon();
    v.setMjenjac();
    return stream;
}

std::ostream& operator<<(std::ostream& stream, Vozilo& v)
{
    std::cout << "\t\t\t\t  Podaci o vozilu\n";
    std::cout << "\t\t\t\t  Ime vozila: " << v.getImeVozila() << "\n";
    std::cout << "\t\t\t\t  Tezina: " << v.getTezinaVozila() << "\n";
    std::cout << "\t\t\t\t  Broj konjskih snaga: " << v.getBrojKonjskihSnaga() << "\n";
    std::cout << "\t\t\t\t  Pogon: ";
    switch (v.getPogon()) {
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
    switch (v.getMjenjac()) {
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
    std::cout << "\t\t\t\t  Nula do sto funkcija: " << std::fixed << std::setprecision(2) << v.nulaDoSto();
    return stream;
}
