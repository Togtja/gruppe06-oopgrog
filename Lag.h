#pragma once

#include "RobustIO.h"
#include "ConstEnum.h"

extern RobustIO rIO;

class Lag
{
private:
	char* navn;             //Navn p� leget
	char* postadresse;      //Adressen til laget
	int antSpillere;        //Antall spillere i laget
	int spillerNr[MAXSPILLERE];  //ID til spillere
public:
	Lag();
	~Lag();
	bool spillerILag(int n);
	void display();
};