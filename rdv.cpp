#include "rdv.h"

/**
  Constructeur par défaut qui initialise un Rdv de nom "Rendez-vous sans nom",
  le 01/01/1900.
*/
Rdv::Rdv() :
  d_name { "Rendez-vous sans nom" },
  d_date { 1, 1, 1900 }
{}

  /**
    Constructeur avec paramètres qui initialise le nom du rendez-vous à 'name'
    et la date du rdv à la date en paramètre.
  */
Rdv::Rdv(const std::string& name, const Date& date) :
  d_name { name },
  d_date { date }
{}

/**
  Destructeur de l'objet Rdv.
*/
Rdv::~Rdv()
{}

/**
  Affiche le rendez-vous sur un flux de sortie de la manière suivante :
  Nom rendez-vous
  ===============
  Le : 00/00/0000
  Avec : Pierre X, Paul Y, Jacques Z

  @param[out] ost - un flux de sortie.
*/
void Rdv::display(std::ostream& ost) const {
  ost << d_name << std::endl;

  for (int i = 0; i < d_name.size(); i++)
    ost << '=';

  ost << std::endl << "Le : " << d_date;

  ost << std::endl << "Avec : ";
  /*
  A venir, insertion de la liste des participants
  ===============================================
  for (int i = 0; i < nbPersonnes; i++)
    ost << d_personnes[i] << ", ";
  */
}
