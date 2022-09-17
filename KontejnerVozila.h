#pragma once

#include <iostream>
#include <fstream>
#include <vector>

#include "Vozilo.h"
#include "Kamion.h"
#include "Automobil.h"

class KontejnerVozila
{
private:
	int brojVozila;
	std::vector<Vozilo> vozila;
	// Nekim cudom je moguce pushati u vektor tipa bazne klase
	// objekte tipa izvedenih klasa.
	std::vector<Kamion> kamioni;
	std::vector<Automobil> automobili;
public:

	KontejnerVozila();

	void setAutomobili();
	void setKamioni();

	Vozilo vratiNajbrze();
	Vozilo operator[](int i);
	Vozilo operator()(int k);

	~KontejnerVozila() {};
	
};

