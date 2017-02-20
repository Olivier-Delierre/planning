#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>

class Personne
{
public:
	/** Constructeur utilisant toutes les informations nécessaires */
	Personne(std::string nom, std::string prenom, std::string telephone, std::string mail);

	/** Affichage du nom */
	std::string nom()		const;
	/** Affichage du prénom */
	std::string prenom()	const;
	/** Affichage du téléphone */
	std::string telephone()	const;
	/** Affichage de l'adresse email */
	std::string mail()		const;

	/** Fonction d'affichage utilisée par la surcharge d'opérateur << */
	void display(std::ostream& ost)	const;
private:
	std::string d_nom;
	std::string d_prenom;
	std::string d_telephone;
	std::string d_mail;
};

/** Surcharge d'opérateur de lecture sur sortie standard */
std::ostream& operator<<(std::ostream& ost, const Personne& p);

#endif