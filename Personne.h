#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>

class Personne
{
public:
	/** Constructeur utilisant toutes les informations n�cessaires */
	Personne(std::string nom, std::string prenom, std::string telephone, std::string mail);

	/** Affichage du nom */
	std::string nom()		const;
	/** Affichage du pr�nom */
	std::string prenom()	const;
	/** Affichage du t�l�phone */
	std::string telephone()	const;
	/** Affichage de l'adresse email */
	std::string mail()		const;

	/** Fonction d'affichage utilis�e par la surcharge d'op�rateur << */
	void display(std::ostream& ost)	const;
private:
	std::string d_nom;
	std::string d_prenom;
	std::string d_telephone;
	std::string d_mail;
};

/** Surcharge d'op�rateur de lecture sur sortie standard */
std::ostream& operator<<(std::ostream& ost, const Personne& p);

#endif