#include "date.h"

static const char SEPARATOR { '/' };

/**
  Constructeur par défaut qui initialise la date au 01/01/1900.
*/
Date::Date() :
  d_day { 1 },
  d_month { 1 },
  d_year { 1900 }
{}

/**
  Constructeur avec paramètres qui initialise la date au day/month/year.
*/
Date::Date(int day, int month, int year) :
  d_day { day },
  d_month { month },
  d_year { year }
{}

/**
  Destructeur de l'objet Date.
*/
Date::~Date() {

}

/**
  Affiche la Date sur un flux de sortie.
  Si le jour ou le mois est inférieur à 10, on rajoute un 0.

  @param[out] ost - un flux de sortie.
*/
void Date::display(std::ostream& ost)  const {
  if (d_day < 10) ost << '0' << d_day;
  else ost << d_day;

  ost << SEPARATOR;

  if (d_month < 10) ost << '0' << d_month;
  else ost << d_month;

  ost << SEPARATOR;

  ost << d_year;
}


/**
  Lis une date depuis un flux d'entrée.

  @param[out] ist - un flux d'entrée.
*/
void Date::read(std::istream& ist) {
  char k;
  ist >> d_day >> k >> d_month >> k >> d_year;
}

/**
  Surcharge de l'opérateur '<<'

  @param[out] ost - un flux de sortie ;
  @param[in] d - une Date.
  @return ost - le flux de sortie.
*/
std::ostream& operator<<(std::ostream& ost, const Date& d) {
  d.display(ost);
  return ost;
}

/**
  Surcharge de l'opérateur '>>'

  @param[out] ist - un flux d'entrée ;
  @param[out] d - une Date.
  @return ist - le flux d'entrée.
*/
std::istream& operator>>(std::istream& ist, Date& d) {
  d.read(ist);
  return ist;
}
