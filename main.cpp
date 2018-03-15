#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <iostream>
#include "ListTool2B.h"
#include "ConstEnum.h"
#include "RobustIO.h"
//Globale Variabler
RobustIO t;
//Funksjon deklaration
void skrivMeny();
void valgMeny();

int main()
{
	skrivMeny();
	valgMeny();
}

void skrivMeny()
{ 
	std::cout << "\n\nFLGENDE KOMMANDOER ER TILGJENGELIGE:";
	std::cout << "\t\nS og A | nr | navn - (S)kriver (A)lle spillern eller alle med nr/navn";
	std::cout << "\t\nI og A | navn - (S)kriver (A)lle idrettene eller idretten med navn";
	std::cout << "\t\nN og S | I | D - (N)y (S)piller,(I)drett eller (D)ivisjon/avdeling";
	std::cout << "\t\nF og S | I | D - (F)jern (S)piller,(I)drett eller (D)ivisjon/avdeling";
	std::cout << "\t\nL - Skriv termin(L)iste for en gitt divisjon/avdeling til skjerm eller fil";
	std::cout << "\t\nK - Skriv alle Kampene en gitt dato for en hel idrett eller en divisjon/avdeling til skjerm eller fil";
	std::cout << "\t\nT - Skriv (T)abell for en hel idrett eller en divisjon/avdeling til skjerm eller fil";
	std::cout << "\t\nR - Lese (R)esultatliste inn fra fil";
	std::cout << "\t\nD - (D)ata om alle spillerne p� et lag";
	std::cout << "\t\nE - (E)ndre/redigere spillerne p� et lag";
	std::cout << "\t\nC - Skriv 10-p�-topp liste av topps(C)orerne for en gitt divisjon/avdeling eller et gitt lag til skjerm eller fil";
	std::cout << "\t\nQ = Quit/Avslutt";
}

void valgMeny() 
{
	char kommando = t.lesInTilStor(); // Leser brukerens �nske/valg.
	while (kommando != 'Q') 
	{
		switch (kommando) 
		{
		case 'S': break; 
		case 'I': break; 
		case 'N': break; 
		case 'F': break; 
		case 'L': break; 
		case 'K': break; 
		case 'T': break; 
		case 'R': break;
		case 'D': break;
		case 'E': break;
		case 'C': break;
		default: skrivMeny(); break; //Skriver meny
		}
		kommando = t.lesInTilStor(); // Leser brukerens �nske/valg.
	};
}