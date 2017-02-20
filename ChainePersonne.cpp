#include "ChainePersonne.h"

#include <iostream>
#include <fstream>

/**
	Constructeur par d�faut intialisant la t�te � NULL.
*/
ChainePersonne::ChainePersonne() :
	d_tete{ NULL }
{}

/**
	Destructeur par d�faut s'occupant uniquement de vider la liste de personnes.
*/
ChainePersonne::~ChainePersonne()
{
	vider();
}

/**
	Cette fonction permet d'ins�rer une personne dans la liste chain�e ChainePersonne en respectant l'ordre alphab�tique des noms.

	@param[in] p - une Personne.
*/
void ChainePersonne::insere_en_ordre(const Personne& p)
{
	ChainonPersonnes* n = new ChainonPersonnes{ p };
	//Insertion en t�te.
	if (d_tete == NULL || d_tete->d_personne.nom() >= p.nom())
	{
		n->d_suivant = d_tete;
		d_tete = n;
	}

	//Insertion milieu/queue.
	else
	{
		ChainonPersonnes* crt = d_tete;
		while (crt->d_suivant != NULL && crt->d_suivant->d_personne.nom() < p.nom())
		{
			crt = crt->d_suivant;
		}

		n->d_suivant = crt->d_suivant;
		crt->d_suivant = n;
	}
}
/**
	Cette fonction permet de supprimer une personne avec un nom et un pr�nom donn�.

	@param[in] nom		- une cha�ne de caract�re comportant le nom de la personne � chercher ;
	@param[in] prenom	- une cha�ne de caract�re comportant le pr�nom de la personne � chercher.
*/
void ChainePersonne::supprimer(const std::string & nom, const std::string & prenom)
{
	if (d_tete != NULL)
	{
		//Suppression en t�te.
		if (d_tete->d_personne.nom() == nom && d_tete->d_personne.prenom() == prenom)
		{
			//Message de confirmation de suppression.
			std::cout << "Supprimer cette personne ? (y/n)" << std::endl;
			std::cout << d_tete->d_personne;

			std::string choix;
			std::cin >> choix;
			if (choix == "y")
			{
				ChainonPersonnes* as{ d_tete };
				d_tete = d_tete->d_suivant;
				delete as;
			}
		}
		//Insertion milieu/queue.
		else
		{
			ChainonPersonnes* crt{ d_tete };
			while (crt->d_suivant != NULL && (crt->d_suivant->d_personne.nom() != nom && crt->d_suivant->d_personne.prenom() != prenom))
			{
				crt = crt->d_suivant;
			}

			if (crt->d_suivant != NULL)
			{
				//Message de confirmation de suppression.
				std::cout << "Supprimer cette personne ? (y/n)" << std::endl;
				std::cout << crt->d_suivant->d_personne;

				std::string choix;
				std::cin >> choix;
				if (choix == "y")
				{
					ChainonPersonnes* as = crt->d_suivant;
					crt->d_suivant = as->d_suivant;
					delete as;
				}
			}
		}
	}
}

/**
	Fonction permettant d'afficher la liste des personnes sur la sortie standard "cout".
*/
void ChainePersonne::afficher_chaine() const
{
	//Si la liste ne contient rien, on signale qu'aucun utilisateur n'est pr�sent dans la liste.
	if (d_tete == NULL) std::cout << "Aucun utilisateur trouve." << std::endl;
	else
	{
		ChainonPersonnes *crt{ d_tete };
		while (crt != NULL)
		{
			std::cout << crt->d_personne << std::endl << std::endl;
			crt = crt->d_suivant;
		}
	}
}


/**
	Fonction permettant de recevoir la liste des personnes contenue dans le fichier dont le nom est compris dans "nomFichier".

	@param[in] nomFichier - cha�ne de caract�re contenant le nom du fichier d'o� importer la liste.
*/
void ChainePersonne::importer(const std::string& nomFichier)
{
	vider();
	std::ifstream f(nomFichier);
	
	std::string nom;
	std::string prenom;
	std::string telephone;
	std::string mail;

	//Bool�en utilis� pour v�rifier qu'on est � la fin du fichier, f.eof() exploitant tr�s mal les lignes finales vides.
	bool eof{ false };
	while (!eof)
	{
			std::getline(f, nom);
			//Si on a pas affaire � la derni�re ligne du fichier, on continue la lecture.
			if (nom != "")
			{
				std::getline(f, prenom);
				std::getline(f, telephone);
				std::getline(f, mail);
				insere_en_ordre({ nom, prenom, telephone, mail });
			}
			//Sinon on signale la fin du fichier pour sortir de la boucle.
			else eof = true;
	}
}

/**
	Fonction permettant d'enregistrer la liste des personnes dans le fichier dont le nom est compris dans "nomFichier".

	@param[in] nomFichier - cha�ne de caract�re contenant le nom du fichier d'o� exporter la liste.
*/
void ChainePersonne::exporter(const std::string& nomFichier)	const
{
	std::ofstream f(nomFichier, std::ofstream::trunc);

	ChainonPersonnes *crt{ d_tete };
	while (crt != NULL)
	{
		f << crt->d_personne << std::endl;
		crt = crt->d_suivant;
	}
}

/**
	Fonction permettant de vider int�gralement la liste des personnes, mettant ainsi la t�te � nouveau � NULL.
	Cette fonction est notamment utilis�e pour l'importation des donn�es, pour �viter les doublons.
*/
void ChainePersonne::vider()
{
	if (d_tete != NULL)
	{
		ChainonPersonnes* crt{ d_tete };
		ChainonPersonnes* suivant;

		while (crt != NULL)
		{
			suivant = crt->d_suivant;
			delete crt;
			crt = suivant;
		}

		d_tete = NULL;
	}
}