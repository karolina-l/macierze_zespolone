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
class LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
public:
LZespolona();
LZespolona(double l, double m);
LZespolona  operator = (double l);
double get_im()const;
double get_re()const;
LZespolona  operator + (const LZespolona  &L2) const;
LZespolona  operator - (const LZespolona  &L2)const;
LZespolona  operator * (const LZespolona  &L2)const;
LZespolona  operator / (const LZespolona  &L2)const;
LZespolona  operator / ( double dziel)const;
bool  operator == ( const LZespolona  &L2)const;
bool  operator != (const LZespolona  &L2)const;
double  modul() const;
//LZespolona  utworz (double re, double im);

};


std::istream &operator >> (std ::istream &czyt,  LZespolona &L1);
std::ostream &operator << (std ::ostream &wys, const LZespolona& L1);
#endif


/*
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
//  double   im;    /*! Pole repezentuje czesc urojona. */
/*};



LZespolona  operator = (LZespolona  L1, double l);
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
explicit LZespolona  utworz (double re, double im);


*/
