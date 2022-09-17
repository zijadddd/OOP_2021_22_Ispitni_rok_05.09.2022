#include "KontejnerVozila.h"

KontejnerVozila::KontejnerVozila()
{
    this->brojVozila = 0;
}

void KontejnerVozila::setAutomobili()
{
    Automobil a;
    this->automobili.push_back(a);
    this->vozila.push_back(a);
    this->brojVozila++;

    std::ofstream izlaz("./automobili.txt", std::ios_base::app | std::ios_base::out);
    izlaz << a;
}

void KontejnerVozila::setKamioni()
{
    Kamion k;
    this->kamioni.push_back(k);
    this->vozila.push_back(k);
    this->brojVozila++;

    std::ofstream izlaz("./kamioni.txt", std::ios_base::app | std::ios_base::out);
    izlaz << k;
}

Vozilo KontejnerVozila::vratiNajbrze()
{
    try {
        if (this->vozila.size() == 0) throw "Nema vozila u kolekciji !";
        else if (this->vozila.size() == 1) return this->vozila[0];
        else {
            Vozilo v = this->vozila[0];
            for (int i = 1; i < this->vozila.size(); i++) if (v.nulaDoSto() < this->vozila[i].nulaDoSto()) v = this->vozila[i];
            return v;
        }
    }
    catch (const char* Greska) {
        std::cout << Greska;
    }
}

Vozilo KontejnerVozila::operator[](int i)
{
    try {
        if (i < 0 || i > this->vozila.size() - 1) throw "[GRESKA] Proslijedjeni parametar je izvan opsega.";
        return this->vozila[i];
    }
    catch (const char* Greska) {
        std::cout << Greska;
    }
}

Vozilo KontejnerVozila::operator()(int k)
{
    try {
        if (this->vozila.size() <= 0) throw "Nema vozila u kolekciji !";
        std::vector<Vozilo> temp;
        for (int i = 0; i < this->vozila.size(); i++) if (this->vozila[i].getBrojKonjskihSnaga() >= k) temp.push_back(this->vozila[i]);
    }
    catch (const char* Greska) {
        std::cout << "Greska";
    }
}

