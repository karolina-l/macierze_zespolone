#include "TWektor.cpp"
#include "LZespolona.hh"

using namespace std;

template class TWektor<double,5>;
template istream & operator >> (istream & str, TWektor<double,5> & W);
template ostream & operator << (ostream & str, const TWektor<double, 5> & W);

template class TWektor<LZespolona,5>;
template istream & operator >> (istream & str, TWektor<LZespolona,5> & W);
template ostream & operator << (ostream & str, const TWektor<LZespolona, 5> & W);
