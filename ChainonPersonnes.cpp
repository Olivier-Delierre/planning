#include "ChainonPersonnes.h"



ChainonPersonnes::ChainonPersonnes(const Personne& p) :
	d_personne { p },
	d_suivant { NULL }
{}

ChainonPersonnes::ChainonPersonnes(ChainonPersonnes* p) :
	d_personne { p->d_personne },
	d_suivant { p->d_suivant }
{}
