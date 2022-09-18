#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>

#include "Vozilo.h"
#include "Kamion.h"
#include "Automobil.h"

class KontejnerVozila
{
private:
	int voziloIndex;
	std::vector<Vozilo> vozila;
	// Nekim cudom je moguce pushati u vektor tipa bazne klase
	// objekte tipa izvedenih klasa.
	std::vector<Kamion> kamioni;
	std::vector<Automobil> automobili;
public:

	KontejnerVozila();

	void setAutomobil();
	void setKamion();

	Vozilo vratiNajbrze();
	Vozilo operator[](int i);
	std::vector<Vozilo> operator()(int k);

	~KontejnerVozila() {};
	
};

