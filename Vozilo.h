#pragma once

#include <iostream>
#include <string>
#include <math.h> 
#include <iomanip>

enum Pogon {
	FWD = 0, RWD, AWD
};

enum Mjenjac {
	MANUAL = 0, AUTOMATIC, DUAL_CLUTCH
};

class Vozilo
{
private:
	char imeVozila[20];
	int tezinaVozila, brojKonjskihSnaga;
	Pogon pogon;
	Mjenjac mjenjac;

public:
	Vozilo();
	void setImeVozila();
	void setTezinaVozila();
	void setBrojKonjskihSnaga();
	void setPogon();
	void setMjenjac();

	char* getImeVozila();
	int getTezinaVozila();
	int getBrojKonjskihSnaga();
	Pogon getPogon();
	Mjenjac getMjenjac();

	double faktorPogona();
	double faktorPrenosa();

	virtual double getCijena();
	virtual char* vratiTip();

	double nulaDoSto();

	friend std::istream& operator>>(std::istream& stream, Vozilo& v);
	friend std::ostream& operator<<(std::ostream& stream, Vozilo& v);

	~Vozilo() {};

};

