#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include"TMacierz.hh"
#include "TWektor.hh"
#include "rozmiar.h"
using namespace std;


/*
  Klasa UkladRownanL:
   zawiera:
   - pole M - TMacierzKw
   - pole W - Wektor
   - konstruktory elementow klasy UkladRownanL
   - przeciazenia strumieni dla klasy UkladRownanL
   - metody zwroc_macierz(), zmien_macierz(),
     zwroc_Wektor(), zmien_wektor(), oblicz(), blad()

 */
template <typename TYP, int ROZM>
class TUkladRownanL    {

  TMacierzKw<TYP, ROZM> M;
  TWektor<TYP, ROZM> W;
  public:
  TUkladRownanL();
  TUkladRownanL(const TMacierzKw<TYP, ROZM> & AA, const TWektor<TYP, ROZM> & BB);
  const TMacierzKw<TYP, ROZM> zwroc_macierz() const;
  void zmien_macierz(const TMacierzKw<TYP, ROZM> & mat);
  const TWektor<TYP, ROZM> zwroc_wektor() const;
  void zmien_wektor(const TWektor<TYP, ROZM> & wek);
  TWektor<TYP, ROZM> oblicz() const;
  //double blad(const TWektor<TYP, ROZM> & wyn) const;
};


template <typename TYP, int ROZM>
istream & operator >> (istream &str, TUkladRownanL<TYP, ROZM> &Ukl);

template <typename TYP, int ROZM>
ostream & operator << (ostream  &str, const TUkladRownanL<TYP, ROZM> &Ukl );


#endif
