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

using namespace std;

static const string DBFILE { "rdvlist.db" };

void enregistrementTest(const Rdv& rdv) {
  ofstream f(DBFILE.c_str());
  f << rdv.name() << endl << rdv.date() << endl << endl;
}

void lectureTest() {
  ifstream f(DBFILE.c_str());
  string name;
  Date date;

  getline(f, name); //On récupère la ligne entière pour pas que cela coupe au premier espace
  f >> date;

  Rdv rdv { name, date };
  cout << rdv;
}

void displayTestRdv() {
  Date date;
  string name;

  cout << "Saisissez un nom de rendez-vous : ";
  getline(cin, name);

  cout << "Saisissez une date : ";
  cin >> date;

  Rdv rdv { name, date };
  cout << rdv;

  enregistrementTest(rdv);
  enregistrementTest(rdv);
}

int main() {
  //displayTestRdv();
  lectureTest();
  return 0;
}
