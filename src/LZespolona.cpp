#include "LZespolona.hh"
#include <iostream>
#include <cstdlib>


/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    L1 - pierwszy skladnik dodawania,
 *    L2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  L1,  LZespolona L2)
{
  LZespolona  Wynik;

  Wynik.re = L1.re + L2.re;
  Wynik.im = L1.im + L2.im;
  return Wynik;
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    L1 - pierwszy skladnik odejmowania,
 *    L2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator - (LZespolona  L1,  LZespolona L2)
{
  LZespolona  Wynik;

  Wynik.re = L1.re - L2.re;
  Wynik.im = L1.im - L2.im;
  return Wynik;
}

/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    L1 - pierwszy skladnik mnozenia,
 *    L2 - drugi skladnik mnozenia.
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator * (LZespolona  L1,  LZespolona  L2)
{
  LZespolona  wynik, czynnik;

  wynik.re = L1.re * L2.re;
  czynnik.re = (-1) * L1.im * L2.im;
  wynik.im = L1.im * L2.re;
  czynnik.im = L1.re * L2.im;
  wynik.re += czynnik.re;
  wynik.im += czynnik.im;
  return wynik;
}

double  sprzezenie (LZespolona  L1)
{
  double wynik;
  wynik = (L1.re * L1.re) + (L1.im * L1.im);
  return wynik;
}

/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    L1 - pierwszy skladnik dzielenia,
 *    L2 - drugi skladnik dzielenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  L1,  LZespolona  L2)
{
  LZespolona wynik, czynnik;
  double  sprz;
  sprz = sprzezenie(L2);
  if(sprz==0)
  {
    std::cerr<<"nie można dzielić przez 0"<<std::endl;
    exit(EXIT_FAILURE);
  }
  czynnik.re = L2.re;
  czynnik.im = L2.im * (-1);
  wynik = L1 * czynnik;
  wynik.re = wynik.re/sprz;
  wynik.im = wynik.im/sprz;
  return wynik;
}

/*!
 * Realizuje dzielenie liczby zespolonej i double.
 * Argumenty:
 *    L1 - pierwszy skladnik dzielenia,
 *    dziel - drugi skladnik dzielenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  L1,  double dziel)
{
  if(dziel!=0)
  {
    L1.re=L1.re/dziel;
    L1.im=L1.im/dziel;
    return L1;
  }
  else
  {
    std::cerr<<"Nie mozna dzielic przez 0"<<std::endl;
        exit(EXIT_FAILURE);
  }
}

/*!
 * Realizuje porównanie liczb zespolonych.
 * Argumenty:
 *    L1 - pierwszy skladnik porownania,
 *    L2 - drugi skladnik porownania.
 * Zwraca:
 *    TRUE gdy wartosci sa rowne.
 *    FALSE gdy wartosci nie sa rowne.
 */
bool operator == (LZespolona  L1,  LZespolona  L2)
{
  double eps = 0.00001;
  if(L1.re-L2.re <eps)
  {
    if(L1.im-L2.im<eps)
    return true;
  }
  else
  {
    //std::cout<<"falsz";
    return false;
  }
}
/*!
 * Realizuje porównanie liczb zespolonych.
 * Argumenty:
 *    L1 - pierwszy skladnik porownania,
 *    L2 - drugi skladnik porownania.
 * Zwraca:
 *    FALSE gdy wartosci sa rowne.
 *    TRUE gdy wartosci nie sa rowne.
 */
bool  operator != (LZespolona  L1,  LZespolona  L2)
{
  return !(L1==L2);
}
///////////////////////

/*!
 * Realizuje operacje wczytania liczby zespolonej
 * Argumenty:
 *    czyt - nazwa strumienia
 *    L1 - liczba do wczytania.
 * Zwraca:
 *    wartosc strumienia
 */
 std::istream  &operator >> (std::istream & czyt, LZespolona &L1)
{
  char znak;
  double a,b;

    czyt >> znak;
    if(znak!= '(')
    {
      czyt.setstate(std::ios::failbit);
    }
    czyt>>a;
    czyt>>b;
    czyt>>znak;
    if(znak!= 'i')
    {
      czyt.setstate(std::ios::failbit);
    }
    czyt>>znak;
    if(znak!= ')')
    {
      czyt.setstate(std::ios::failbit);
    }

    if(!czyt.fail())
    {
      L1.re=a;
      L1.im=b;
    }
  return czyt;
}

/*!
 * Realizuje operacje wypisania liczby zespolonej
 * Argumenty:
 *    wys - nazwa strumienia
 *    L1 - liczba do wyswietlenia.
 * Zwraca:
 *    wartosc strumienia
 */
std::ostream  &operator << (std::ostream &wys, LZespolona L1)
{
    wys << "(" << L1.re  << std::showpos << L1.im  << std::noshowpos <<  "i)";
    return wys;
}

//////////////////////
/* tworzenie liczby zespolonej*/
LZespolona utworz(double re, double im)
{
  LZespolona L1;
  L1.re = re;
  L1.im = im;
  return L1;
}
