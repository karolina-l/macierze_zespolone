#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};




LZespolona  operator + (LZespolona  L1,  LZespolona  L2);
LZespolona  operator - (LZespolona  L1,  LZespolona  L2);
LZespolona  operator * (LZespolona  L1,  LZespolona  L2);
LZespolona  operator / (LZespolona  L1,  LZespolona  L2);
LZespolona  operator / (LZespolona  L1,  double dziel);
bool  operator == (LZespolona  L1,  LZespolona  L2);
bool  operator != (LZespolona  L1,  LZespolona  L2);
double  sprzezenie (LZespolona  L1);
std::istream &operator >> (std ::istream &czyt, LZespolona &L1);
std::ostream &operator << (std ::ostream &wys, LZespolona L1);
LZespolona  utworz (double re, double im);


#endif
