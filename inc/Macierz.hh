#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <iostream>

using namespace std;

/*
  Klasa MacierzKw:
   zawiera:
   - pole mtx - tablica wektorow,
     rozmiar zadany zewnetrznie
   - konstruktory elementow klasy MacierzKw
   - przeciazenia operatorow klasy MacierzKw
   - metode zwroc_kolumne(), zmien_kolumne(),
     odwroc(), wyznacznik(), transponuj()
*/

//reprezentacja wierszowa
class MacierzKw  {

  Wektor mtx[ROZMIAR];
  
  public:
  MacierzKw();
  MacierzKw(const Wektor  tab[ROZMIAR]);
  const Wektor & operator[] (int index) const;
  Wektor & operator[] (int index);
  const MacierzKw  operator + (const MacierzKw & M);
  const MacierzKw  operator - (const MacierzKw & M);
  const MacierzKw  operator * (const MacierzKw & M);
  const Wektor operator * (const Wektor & W);
  const MacierzKw  operator * (double l);
  MacierzKw  odwroc() const;
  Wektor  zwroc_kolumne(int ind); //dla interpretacji wierszowej
  void zmien_kolumne(int ind, Wektor W); //dla interpretacji wierszowej
  double wyznacznik();
  MacierzKw transponuj() const;
};



istream & operator >> (istream &str, MacierzKw &M);


ostream & operator << (ostream &str, const MacierzKw &M);

#endif
