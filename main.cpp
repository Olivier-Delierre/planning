#include <iostream>
#include <string>

#include "date.h"
#include "rdv.h"

using namespace std;

void displayTestRdv() {
  Date date;
  string name;

  cout << "Saisissez un nom de rendez-vous : ";
  cin >> name;

  cout << "Saisissez une date : ";
  cin >> date;

  Rdv rdv { name, date };
  rdv.display(cout);
}

int main() {
  displayTestRdv();
  return 0;
}
