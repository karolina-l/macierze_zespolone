#include "TWektor.cpp"
#include "TMacierz.cpp"
#include "TUkladRownanLiniowych.cpp"
#include "LZespolona.hh"

using namespace std;

template class TWektor<double,5>;
template istream & operator >> (istream & str, TWektor<double,5> & W);
template ostream & operator << (ostream & str, const TWektor<double, 5> & W);

template class TWektor<LZespolona,5>;
template istream & operator >> (istream & str, TWektor<LZespolona,5> & W);
template ostream & operator << (ostream & str, const TWektor<LZespolona, 5> & W);


template class TMacierzKw<double,5>;
template istream & operator >> (istream &str, TMacierzKw<double, 5> &M);
template ostream & operator << (ostream &str, const TMacierzKw<double,5> &M);


template class TMacierzKw<LZespolona,5>;
template istream & operator >> (istream &str, TMacierzKw<LZespolona, 5> &M);
template ostream & operator << (ostream &str, const TMacierzKw<LZespolona,5> &M);


template class TUkladRownanL<double,5>;
template istream & operator >> (istream &str, TUkladRownanL<double, 5> &M);
template ostream & operator << (ostream &str, const TUkladRownanL<double,5> &M);


template class TUkladRownanL<LZespolona,5>;
template istream & operator >> (istream &str, TUkladRownanL<LZespolona, 5> &M);
template ostream & operator << (ostream &str, const TUkladRownanL<LZespolona,5> &M);
