#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "KontejnerVozila.h"

int meni() {
    system("cls");
    std::cout << "\t\t\t\t  1. Dodaj kamion u kolekciju." << std::endl;
    std::cout << "\t\t\t\t  2. Dodaj automobil u kolekciju." << std::endl;
    std::cout << "\t\t\t\t  3. Informacije o konkretnom vozilu.\n\t\t\t\t  -(preklopljeni operator [])" << std::endl;
    std::cout << "\t\t\t\t  4. Vozila sa konkretnim brojem konjskih snaga ili vise.\n\t\t\t\t  -(preklopljeni operator ())" << std::endl;
    std::cout << "\t\t\t\t  5. Najbrze vozilo u kolekciji." << std::endl;
	std::cout << "\t\t\t\t  6. Izadji." << std::endl;
    std::cout << "\t\t\t\t __________________________________________________________\n\n";
    std::cout << "\t\t\t\t  Unesite opciju: ";

    int izbor;
    do {
        std::cin >> izbor;
        if (izbor < 1) {
            std::cout << "\t\t\t\t  Greska - Ne mozete unijeti opciju manju od 1.\n";
            std::cout << "\t\t\t\t  Ponovo unesite opciju: ";
        }
        else if (izbor > 6) {
            std::cout << "\t\t\t\t  Greska - Ne mozete unijeti opciju vecu od 6.\n";
            std::cout << "\t\t\t\t  Ponovo unesite opciju: ";
        }
    } while (izbor < 1 || izbor > 6);
    std::cin.ignore();
    return izbor;
}

int main() {

	KontejnerVozila kontejner;
	system("cls");

	std::string letters[9]{
	"\t\t\t\t\t____________________________________________\n",
	"\t\t\t\t\t   ___   ___  ____  \n",
	"\t\t\t\t\t  / _ \\ / _ \\|  _ \\ \n",
	"\t\t\t\t\t | | | | | | | |_) |\n",
	"\t\t\t\t\t | |_| | |_| |  __/ \n",
	"\t\t\t\t\t  \\___/ \\___/|_|    \n",
	"\t\t\t\t\t____________________________________________\n"
	};

	std::cout << "\n\n\n\n\n\n\n\n";

	for (int i = 0; i < 7; i++) {
		std::cout << letters[i];
		Sleep(500);
	}
	std::cout << "\t\t\t\t\t";
	char dobrodoslica[] = " ROK: 05.09.2022!";
	for (int i = 0; i < strlen(dobrodoslica); i++) {
		std::cout << dobrodoslica[i];
		Sleep(300);
	}
	std::cout << "\n\t\t\t\t\t Pritisnite bilo koju tipku da nastavite...";
	_getch();
	system("cls");

	int izbor;
	while (izbor = meni()) {
		switch (izbor) {
			case 1: {
				kontejner.setKamion();
				std::cout << "\n\t\t\t\t  Pritisnite bilo koju tipku da nastavite...";
				_getch();
				break;
			}
			case 2: {
				kontejner.setAutomobil();
				std::cout << "\n\t\t\t\t  Pritisnite bilo koju tipku da nastavite...";
				_getch();
				break;
			}
			case 3: {
				std::cout << "\t\t\t\t  Unesite index vozila kojeg zelite da vidite: ";
				int choice = 0;
				std::cin >> choice;
				Vozilo vozilo;
				vozilo = kontejner[choice];
				std::cout << vozilo;
				std::cout << "\n\t\t\t\t  Pritisnite bilo koju tipku da nastavite...";
				_getch();
				break;
			}
			case 4: {
				std::cout << "\t\t\t\t  Unesite broj konjskih snaga: ";
				int num = 0;
				do {
					std::cin >> num;
					if (num < 0) std::cout << "\t\t\t\t  [GRESKA] Nije moguce imati negativan broj konjskih snaga !\nPonovo unesite: ";
				} while (num < 0);
				std::vector<Vozilo> vozila = kontejner(num);
				// Vracen je vektor vozila, ali ja ispisujem samo imena vozila.
				for (int i = 0; i < vozila.size(); i++) std::cout << "\n\t\t\t\t  " << i + 1 << ". " << vozila[i].getImeVozila() << std::endl;
				std::cout << "\n\t\t\t\t  Pritisnite bilo koju tipku da nastavite...";
				_getch();
				break;
			}
			case 5: {
				Vozilo v = kontejner.vratiNajbrze();
				std::cout << v;
				std::cout << "\n\t\t\t\t  Pritisnite bilo koju tipku da nastavite...";
				_getch();
				break;
			}
			case 6: {
				exit(0);
			}
		}
	}
	return 0;
}