#include "Idrett.h"

Idrett::Idrett(char* navn) : TextElement(navn)
{
	divisjoner = new List(Sorted);
	nyDivisjon();
	tabelltype = rIO.lesTabelltype("Tabelltype: ");
	
}
Idrett::Idrett(std::ifstream&inn, char* navn) : TextElement(navn) 
{
	char* tabelltype;
	rIO.lesCharPointerFraFil(inn, tabelltype);
	tabelltype = rIO.lesTabelltypeFraFil(tabelltype);
	divisjoner = new List(Sorted);
	//std::ifstream innDiv("gruppe06-ooprog/NY_DIV.DTA")
}
void Idrett::nyDivisjon() {
	char* t;
	rIO.lesInnICharPointer("Navn paa Divisjon/Avdeling?", t);
	if (!divisjoner->inList(t)) {
		divisjoner->add((TextElement*)new DivAvd(t));
	}
	else
	{
		std::cout << "Denne divisjonen finner allerede i listen";
	}
}
Idrett::~Idrett()
{
	delete divisjoner;
}

void Idrett::display()
{
	std::cout << text << '\n'
		<< "Tabelltype: " << tabelltype << '\n'
		<< "Antall divisjoner: " << divisjoner->noOfElements() << '\n';
	divisjoner->displayList();
}