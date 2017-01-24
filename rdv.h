#ifndef RDV_H
#define RDV_H

#include <iostream>
#include <string>

#include "date.h"

class Rdv {
public:
  /** Constructeurs et destructeurs */
  Rdv();
  Rdv(const std::string& name, const Date& date);
  ~Rdv();

  Date date()   const;
  void display(std::ostream& ost)  const;
  std::string name() const;
private:
  std::string d_name;
  Date d_date;
  /*
  A venir, liste des participants et leur nombre
  ==============================================
  Personne *d_personnes;
  int nbPersonnes;
  */
};

/** Surcharge de l'opérateur '<<' */
std::ostream& operator<<(std::ostream& ost, const Rdv& rdv);

#endif
