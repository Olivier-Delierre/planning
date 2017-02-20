/**
Gestion d'un emploi du temps
@author Olivier Delierre
@author Florent Hess
@author Benoît Fantozzi
@author Ilyasse Tissafi
@version 1.0
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

#include "date.h"
#include "rdv.h"
#include "ChainePersonne.h"

using namespace std;

static const string FICHIER_RDV{ "rdvlist.db" };
static const string FICHIER_USER{ "userlist.db" };

void testChaine()
{
	ChainePersonne liste_personnes;
	int choix;

	string nom;
	string prenom;
	string telephone;
	string mail;

	liste_personnes.importer(FICHIER_USER);
	while (1)
	{
		system("cls");
		cout << "1. Inserer une personne" << endl;
		cout << "2. Supprimer une personne" << endl;
		cout << "3. Lister les personnes" << endl;

		cin >> choix;
		cout << endl;

		switch (choix)
		{
		case 1:
			cout << "Nom : ";
			cin >> nom;
			cout << "Prenom : ";
			cin >> prenom;
			cout << "Telephone : ";
			cin >> telephone;
			cout << "Mail : ";
			cin >> mail;

			liste_personnes.insere_en_ordre({ nom, prenom, telephone, mail });
			liste_personnes.exporter(FICHIER_USER);
			cout << "La personne a bien ete ajoutee.";
			break;
		case 2:
			cout << "Nom : ";
			cin >> nom;
			cout << "Prenom : ";
			cin >> prenom;

			liste_personnes.supprimer(nom, prenom);
			liste_personnes.exporter(FICHIER_USER);
			cout << "La personne a bien ete supprimee";
			break;
		case 3:
			liste_personnes.afficher_chaine();
			break;
		}

		system("pause");
	}
}

int main() {
	testChaine();
	return 0;
}
