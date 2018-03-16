#include "Spiller.h"

Spiller::Spiller() 
{
	std::cout << "\n\nWE ARE NOT SUPPOSED TO BE HERE\n\n";
}
Spiller::Spiller(int nr) : NumElement(nr)
{
	t.lesInnICharPointer("Navn paa spiller?", navn);
	t.lesInnICharPointer("Adressen til spiller?", adresse);
}
Spiller::Spiller(std::ifstream& inn, int num) : NumElement(num)
{
		t.lesCharPointerFraFil(inn, navn);
		t.lesCharPointerFraFil(inn, adresse);
}
void Spiller::display() 
{
	std::cout << number << std::endl;
	std::cout << navn << std::endl;
	std::cout << adresse << std::endl;
}
int Spiller::spillerNr() 
{
	return number;
}
bool Spiller::sameNavn(char* n) {
	if (!strcmp(n, navn)) {
		return true;
	}
	return false;
}

Spiller::~Spiller()
{
    delete[] navn;
    delete[] adresse;
}
