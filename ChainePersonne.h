#ifndef CHAINEPERSONNE_H
#define CHAINEPERSONNE_H

#include "Personne.h"
#include "ChainonPersonnes.h"

class ChainePersonne
{
public:
	/** Constructeur par défaut */
	ChainePersonne();
	/** Destructeur par défaut */
	~ChainePersonne();

	/** Insère selon l'ordre alphabétique des noms */
	void insere_en_ordre(const Personne& p);
	/** Supprimme une personne selon le nom et le prenom */
	void supprimer(const std::string& nom, const std::string& prenom);
	/** Affiche la liste de personnes */
	void afficher_chaine()	const;
	/** Importe depuis un fichier une liste de personnes */
	void importer(const std::string& nomFichier);
	/** Exporte vers un fichier une liste de personnes */
	void exporter(const std::string& nomFichier) const;
	/** Vide la chaine */
	void vider();
private:
	ChainonPersonnes* d_tete;
};

#endif
