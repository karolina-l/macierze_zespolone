#include "LZespolona.hh"
#include <iostream>
#include <cstdlib>
#include <cmath>



LZespolona::LZespolona()
{
  re=0.0;
  im=0.0;
}
LZespolona::LZespolona(double l, double m)
{
  re=l;
  im=m;
}

 LZespolona LZespolona::operator = (double l)
 {
   re=l;
   im=0.0;
   return *this;
 }

double LZespolona::get_im()const
{
  return im;
}
double LZespolona::get_re()const
{
  return re;
}
/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    L1 - pierwszy skladnik dodawania,
 *    L2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator + (const LZespolona  &L2) const
{
  LZespolona  Wynik;
  LZespolona L1=*this;

  Wynik.re = L1.re + L2.re;
  Wynik.im = L1.im + L2.im;
  return Wynik;
}

LZespolona  LZespolona:: operator += (const LZespolona  &L2)
{
  *this=*this+L2;
  return *this;
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    L1 - pierwszy skladnik odejmowania,
 *    L2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator - (const LZespolona  &L2)const
{
  LZespolona  Wynik;
  LZespolona L1=*this;

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
 LZespolona  LZespolona::operator * (const LZespolona  &L2)const
{
  LZespolona  wynik, czynnik;
  LZespolona L1=*this;

  wynik.re = L1.re * L2.re;
  czynnik.re = (-1) * L1.im * L2.im;
  wynik.im = L1.im * L2.re;
  czynnik.im = L1.re * L2.im;
  wynik.re += czynnik.re;
  wynik.im += czynnik.im;
  return wynik;
}

LZespolona   LZespolona::operator * (double l)const
{
  LZespolona L1;
  L1.re=re*l;
  L1.im=im*l;
  return L1;
}

double LZespolona:: modul() const
{
  LZespolona L1=*this;
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
 LZespolona  LZespolona::operator / (const LZespolona  &L2)const
{
  LZespolona L1=*this;
  LZespolona wynik, czynnik;
  double  sprz;
  sprz = L2.modul();
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
 LZespolona  LZespolona::operator / ( double dziel)const
{
  LZespolona L1=*this;
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
 bool  LZespolona::operator == ( const LZespolona  &L2)const
{
  //LZespolona L1=*this;
  double eps = 0.00000001;
  if(abs(re-L2.re)<eps && abs(im-L2.im)<eps)
  {
    std::cout<<"LZ rowne"<<std::endl;
    return true;
  }
  else
  {
    std::cout<<"LZ falsz"<<std::endl;
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
 bool  LZespolona::operator != (const LZespolona  &L2)const
{
//LZespolona L1=*this;
  return !(*this==L2);
}

bool   LZespolona::operator > (double l)const
{
  if(re>l && im>l)
    return true;
  else
    return false;
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
 std::istream &operator >> (std ::istream &czyt, LZespolona &L1)
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
      L1=LZespolona(a,b);
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
 std::ostream &operator << (std ::ostream &wys, const LZespolona &L1)
{
  double a, b;
  a=L1.get_re();
  b=L1.get_im();

    wys << "(" << a  << std::showpos << b  << std::noshowpos <<  "i)";
    return wys;
}

//////////////////////
/* tworzenie liczby zespolonej*/
/*LZespolona LZespolona::utworz(double re, double im)
{
  LZespolona L1=*this;
  LZespolona L1;
  L1.re = re;
  L1.im = im;
  return L1;
}*/
