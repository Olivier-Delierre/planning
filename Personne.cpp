#include "Personne.h"

Personne::Personne(std::string nom, std::string prenom, std::string telephone, std::string mail) :
	d_nom{ nom },
	d_prenom{ prenom },
	d_telephone{ telephone },
	d_mail{ mail }
{}

/**
	Fonction retournant le nom de la personne.

	@return d_nom - le nom de la personne.
*/
std::string Personne::nom()					const
{
	return d_nom;
}

/**
	Fonction retournant le prénom de la personne.

	@return d_prenom - le prénom de la personne.
*/
std::string Personne::prenom()				const
{
	return d_prenom;
}

/**
	Fonction retournant le numéro de téléphone de la personne.

	@return d_telephone - le numéro de téléphone de la personne.
*/
std::string Personne::telephone()			const
{
	return d_telephone;
}

/**
	Fonction retournant l'adresse mail de la personne.

	@return d_mail - l'adresse mail de la personne.
*/
std::string Personne::mail()				const
{
	return d_mail;
}

void Personne::display(std::ostream & ost)	const
{
	ost << d_nom << std::endl; 
	ost << d_prenom << std::endl;
	ost << d_telephone << std::endl;
	ost << d_mail;
}

std::ostream& operator<<(std::ostream& ost, const Personne& p)
{
	p.display(ost);
	return ost;
}
