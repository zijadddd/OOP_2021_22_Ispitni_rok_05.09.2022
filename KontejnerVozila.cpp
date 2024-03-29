#include "KontejnerVozila.h"

KontejnerVozila::KontejnerVozila()
{
}

void KontejnerVozila::setAutomobil()
{
    Automobil a;
    this->automobili.push_back(a);
    this->vozila.push_back(a);


    std::ofstream izlaz("./automobili.txt", std::ios_base::app | std::ios_base::out);
    izlaz << a.getImeVozila() << std::endl;
    izlaz << a.getBrojKonjskihSnaga() << std::endl;
    izlaz << a.getTezinaVozila() << std::endl;
    izlaz << a.getMjenjac() << std::endl;
    izlaz << a.getPogon() << std::endl;
    izlaz << a.getCijena() << std::endl;
    izlaz << a.getRokOtplate() << std::endl;
    izlaz << a.getMjesecnaRata() << std::endl;
    izlaz.close();
}

void KontejnerVozila::setKamion()
{
    Kamion k;
    this->kamioni.push_back(k);
    this->vozila.push_back(k);

    std::ofstream izlaz("./kamioni.txt", std::ios_base::app | std::ios_base::out);
    izlaz << k.getImeVozila() << std::endl;
    izlaz << k.getBrojKonjskihSnaga() << std::endl;
    izlaz << k.getTezinaVozila() << std::endl;
    izlaz << k.getMjenjac() << std::endl;
    izlaz << k.getPogon() << std::endl;
    izlaz << k.getNosivost() << std::endl;
    izlaz.close();
}

Vozilo KontejnerVozila::vratiNajbrze()
{
    try {
        if (this->vozila.size() == 0) throw "\t\t\t\t  Nema vozila u kolekciji !";
        else if (this->vozila.size() == 1) return this->vozila[0];
        else {
            Vozilo v = this->vozila[0];
            for (int i = 1; i < this->vozila.size(); i++) if (v.nulaDoSto() > this->vozila[i].nulaDoSto()) v = this->vozila[i];
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
        if (i < 0 || i > this->vozila.size() - 1) throw "\t\t\t\t  [GRESKA] Proslijedjeni parametar je izvan opsega.";
        return this->vozila[i];
    }
    catch (const char* Greska) {
        std::cout << Greska;
    }
}

std::vector<Vozilo> KontejnerVozila::operator()(int k)
{
    try {
        if (this->vozila.size() <= 0) throw "\t\t\t\t  Nema vozila u kolekciji !";
        std::vector<Vozilo> temp;
        for (int i = 0; i < this->vozila.size(); i++) if (this->vozila[i].getBrojKonjskihSnaga() >= k) temp.push_back(this->vozila[i]);
        return temp;
    }
    catch (const char* Greska) {
        std::cout << "Greska";
    }
}

