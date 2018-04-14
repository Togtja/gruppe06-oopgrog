#include "Resultat.h"
#include "RobustIO.h"
#include "Spillere.h"

extern RobustIO rIO;
extern Spillere spillere;

// les info om resultat fr� fil
Resultat::Resultat(std::ifstream& fil, char _dato[])
{
	for (int i = 0; i < DATOLEN; i++)
	{
		dato[i] = _dato[i];
	}

	fil >> hjemmemaal;
	fil >> bortemaal;
	fil >> normalTid;

	for (int i = 0; i < hjemmemaal; i++)
	{
		fil >> hjemmescorere[i];
	}

	for (int i = 0; i < bortemaal; i++)
	{
		fil >> bortescorere[i];
	}

	fil.ignore();
}

Resultat::Resultat(Lag* hjemmelag, Lag* bortelag)
{
	rIO.lesDato("Dato", dato);

	/*
	// les inn antal m�l
	std::cout << "Maal:\n";
	hjemmemaal = rIO.lesTall(hjemmelag->getNavn(), 0, MAXMAAL);
	bortemaal = rIO.lesTall(bortelag->getNavn(), 0, MAXMAAL);

	// sp�r om kampen blei ferdig til normal tid
	std::cout << "Ble kampen ferdig paa normal tid? (y/n) ";
	normalTid = rIO.lesInnTilStor() == 'Y';

	// les inn m�lscorarar for alle m�la
	
	// heimem�l
	if (hjemmemaal > 0)
	{
		std::cout << "Maalscorere (" << hjemmelag->getNavn() << "):\n";
		for (int i = 0; i < hjemmemaal; i++)
		{
			// TODO: List opp spelarane p� laget for brukarvennlegheit
			do
			{
				hjemmescorere[i] = rIO.lesTall("Spillerens nummer",
					0, spillere.getSisteNr());

				if (!hjemmelag->spillerILag(hjemmescorere[i]))
				{
					std::cout << hjemmescorere[i] << " spiller ikke for "
						<< hjemmelag->getNavn() << "!\n";
				}
			} while (!hjemmelag->spillerILag(hjemmescorere[i]));
		}
	}

	// bortem�l
	if (bortemaal > 0)
	{
		std::cout << "Maalscorere (" << bortelag->getNavn() << "):\n";
		for (int i = 0; i < bortemaal; i++)
		{
			// TODO: List opp spelarane p� laget for brukarvennlegheit
			do
			{
				bortescorere[i] = rIO.lesTall("Spillerens nummer",
					0, spillere.getSisteNr());

				if (!bortelag->spillerILag(bortescorere[i]))
				{
					std::cout << bortescorere[i] << " spiller ikke for "
						<< bortelag->getNavn() << "!\n";
				}
			} while (!bortelag->spillerILag(bortescorere[i]));
		}
	}
	*/
}

bool Resultat::sameDate(char* date)
{
    return !strcmp(date, dato);
}

// returnerer datoen i "dd/mm"-form
char* Resultat::kortDato()
{
	char* kortDato = new char[6];
	kortDato[0] = dato[6];
	kortDato[1] = dato[7];
	kortDato[2] = '/';
	kortDato[3] = dato[4];
	kortDato[4] = dato[5];
	kortDato[5] = '\0';
	return kortDato;
}

char* Resultat::langDato()
{
	return dato;
}

void Resultat::skrivResultatTilSkjerm()
{
    std::cout << hjemmemaal << " - " << bortemaal;
    if (normalTid)
    {
        std::cout << " normal tid\n";
    }
    else
    {
        std::cout << " overtid\n";
    }
    if (hjemmemaal)
        std::cout << "HjemmeMaal ble scoret av: \n";
    for (int i = 0; i < hjemmemaal; i++)
    {
        std::cout << spillere.getSpillerNavn(hjemmescorere[i]) << '\n';
    }
    if (bortemaal)
        std::cout << "Bortemaal ble scoret av: \n";
    for (int i = 0; i < bortemaal; i++)
    {
        std::cout << spillere.getSpillerNavn(bortescorere[i]) << '\n';
    }
    std::cout << std::endl;
    
}

void Resultat::skrivResultatTilFil(std::ofstream & utfil)
{
    utfil << hjemmemaal << " - " << bortemaal;
    if (normalTid)
    {
        utfil << " normal tid\n";
    }
    else
    {
        utfil << " overtid\n";
    }
    if (hjemmemaal)
        utfil << "HjemmeMaal ble scoret av: \n";
    for (int i = 0; i < hjemmemaal; i++)
    {
        utfil << spillere.getSpillerNavn(hjemmescorere[i]) << '\n';
    }
    if (bortemaal)
        utfil << "Bortemaal ble scoret av: \n";
    for (int i = 0; i < bortemaal; i++)
    {
        utfil << spillere.getSpillerNavn(bortescorere[i]) << '\n';
    }
    utfil << '\n';
}

int  Resultat::getHjemmemaal() {
	return hjemmemaal;
}

int  Resultat::getBortemaal() {
	return bortemaal;
}

bool Resultat::getNormalTid() {
	return normalTid;
}