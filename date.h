#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
public:
  /** Constructeurs et destructeurs */
  Date();
  Date(int day, int month, int year);
  ~Date();

  /** Affichage et lecture d'une Date */
  void display(std::ostream& ost)  const;
  void read(std::istream& ist);
private:
  int d_day;
  int d_month;
  int d_year;
};

/** Surcharge des opérateurs de lecture et d'écriture */
std::ostream& operator<<(std::ostream& ost, const Date& d);
std::istream& operator>>(std::istream& ist, Date& d);

#endif
