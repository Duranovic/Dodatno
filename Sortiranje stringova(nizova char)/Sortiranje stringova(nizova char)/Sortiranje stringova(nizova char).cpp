// Sortiranje stringova(nizova char).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

const char *crt = "\n--------------------------------------------------\n";


void Unos(char *&niz, const char * naziv)
{
	niz = new char[strlen(naziv) + 1];
	strcpy_s(niz, strlen(naziv) + 1, naziv);
}
void Ispis(char * niz [], int vel)
{
	for (size_t i = 0; i < vel; i++)
	{
		cout << i+1<<". "<<niz[i] << endl;
	}
	cout << crt;
}
void Sortiraj(char *niz[], int max)
{
	for (size_t i = 0; i < max; i++)
	{
		int j = i;
		while (j != 0)
		{
			bool prolaz = false;
		
				if (strlen(niz[j]) < strlen(niz[j - 1]))
				{
					prolaz = true;
				}
				else if (strlen(niz[j]) == strlen(niz[j - 1]))
				{
					for (size_t brojac = 0; brojac < 100; brojac++)
					{
						if(strlen(niz[j]) > brojac)
						{
							if (niz[j][brojac] == niz[j-1][brojac])
							{
								prolaz = true;
							}
							else if (niz[j][brojac] < niz[j - 1][brojac])
							{
								prolaz = true;
							}
							else
							{
								prolaz = false;
								break;
							}
						}
					}
				}
				if (prolaz)
				{
					char * temp;
					Unos(temp, niz[j]);
					delete[] niz[j];
					Unos(niz[j], niz[j - 1]);
					delete[] niz[j - 1];
					Unos(niz[j - 1], temp);
				}
				j--;
		}
	}
}
char * BinarnoPretrazivanje(char *niz[], int max, const char * search)
{
	int lijevo = 0;
	int desno = max - 1;
	int sredina = (lijevo + desno) / 2;

	while (lijevo <= desno)
	{
		bool IdiLijevo = false;

		if (strcmp(search, niz[sredina]) == 0)
			return niz[sredina];

		if (strlen(search) < strlen(niz[sredina]))
		{
			IdiLijevo = true;
		}
		else if (strlen(search) == strlen(niz[sredina]))
		{
			for (size_t brojac = 0; brojac < 100; brojac++)
			{
				if (strlen(search) > brojac)
				{
					if (search[brojac] == niz[sredina][brojac])
					{
						IdiLijevo = false;
					}
					else if (search[brojac] < niz[sredina][brojac])
					{
						IdiLijevo = true;
						break;
					}
					else
					{
						IdiLijevo = false;
						break;
					}
				}
			}
		}
		if (IdiLijevo == true)
			desno = sredina - 1;
		else
			lijevo = sredina + 1;
			

		sredina = (lijevo + desno) / 2;
	}
}

int main()
{
	const int max = 8;
	char * nizKaraktera[max];
	Unos(nizKaraktera[0], "Cokolada");
	Unos(nizKaraktera[1], "Sok");
	Unos(nizKaraktera[2], "Miris");
	Unos(nizKaraktera[3], "Cokolade");
	Unos(nizKaraktera[4], "Milka");
	Unos(nizKaraktera[5], "Mirisna");
	Unos(nizKaraktera[6], "Cokoladu");
	Unos(nizKaraktera[7], "Cokoladi");


	Ispis(nizKaraktera, max);
	Sortiraj(nizKaraktera, max);
	Ispis(nizKaraktera, max);
	cout << crt;

	char * pok = BinarnoPretrazivanje(nizKaraktera, max, "Cokoladi");
	cout << "Pronadjena rijec je: " << pok << "\t[ Adresa: " << &pok << "]\n";

	system("pause>0");
    return 0;
}

