#pragma once
#include "Vozilo.h"

#include <string>

class Kamion :
    public Vozilo
{
private:
    int nosivost;
public:
    Kamion();
    void setNosivost();

    int getNosivost();
    double getCijena();
    char* vratiTip();

    //friend std::istream& operator>>(std::istream& stream, Kamion& k);
    friend std::ostream& operator<<(std::ostream& stream, Kamion& k);

    ~Kamion() {};
};

