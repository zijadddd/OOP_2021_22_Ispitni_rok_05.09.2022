#pragma once
#include "Vozilo.h"
class Automobil :
    public Vozilo
{
private:
    int rokOtplate;
public:
    Automobil();

    void setRokOtplate();

    int getRokOtplate();
    double getMjesecnaRata();
    double getCijena();
    char* vratiTip();

    friend std::ostream& operator>>(std::ostream& stream, Automobil& a);
    friend std::ostream& operator<<(std::ostream& stream, Automobil& a);

    ~Automobil() {};
};

