#pragma once

#include "Personne.h"

class ChainonPersonnes
{
public:
	ChainonPersonnes(const Personne& p);
	ChainonPersonnes(ChainonPersonnes *p);

	/** Amitié */
	friend class ChainePersonne;
private:
	Personne d_personne;
	ChainonPersonnes* d_suivant;
};

