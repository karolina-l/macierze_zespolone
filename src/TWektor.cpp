#include "TWektor.hh"
#include <cmath>

template <typename TYP, int ROZM>
TWektor<TYP,ROZM>::TWektor()
{
  for(int i=0; i<ROZMIAR; i++)
  {
    Twek[i]=0.0;
  }
}

template <typename TYP, int ROZM>
TWektor<TYP,ROZM>::TWektor(TYP tab[ROZM])
{
  for(int i=0; i<ROZMIAR; i++)
  {
    Twek[i]=tab[i];
  }
}

template <typename TYP, int ROZM>
const TYP & TWektor<TYP,ROZM>::operator[] (int index) const
{
  if (index < 0 || index > ROZMIAR)
  {
    cerr << "indeks poza zakresem" << endl;
    exit(1);
  }
  else
  {
    return Twek[index];
  }
}

template <typename TYP, int ROZM>
TYP & TWektor<TYP,ROZM>::operator[] (int index)
{
   if (index < 0 || index > ROZMIAR)
   {
     cerr << "indeks poza zakresem" << endl;
     exit(1);
   }
   else
   {
     return Twek[index];
   }
 }

template <typename TYP, int ROZM>
TWektor<TYP, ROZM> TWektor<TYP,ROZM>::operator + (const TWektor<TYP, ROZM> & W) const
{
  TYP nowy[ROZMIAR]={0.0};
  for(int i=0; i<ROZMIAR; i++)
  {
    nowy[i]=this->Twek[i]+W.Twek[i];
  }
  return TWektor(nowy);
}

template <typename TYP, int ROZM>
TWektor<TYP, ROZM> TWektor<TYP,ROZM>::operator += (const TWektor<TYP, ROZM> & W)
{
  for(int i=0; i<ROZMIAR; i++)
  {
    this->Twek[i]+=W.Twek[i];
  }
  return *this;
}

template <typename TYP, int ROZM>
TWektor<TYP, ROZM> TWektor<TYP,ROZM>::operator - (const TWektor<TYP, ROZM> & W) const
{
  TYP nowy[ROZMIAR]={0.0};
  for(int i=0; i<ROZMIAR; i++)
  {
    nowy[i]=this->Twek[i]-W.Twek[i];
  }
  return TWektor(nowy);
}

template <typename TYP, int ROZM>
TYP TWektor<TYP,ROZM>::operator * (const TWektor<TYP, ROZM> & W) const
{
  TYP nowy[ROZMIAR]={0.0};
  TYP wynik=0.0;
  for(int i=0; i<ROZMIAR; i++)
  {
    nowy[i]=this->Twek[i]*W.Twek[i];
    wynik+=nowy[i];
  }
  return wynik;
}

template <typename TYP, int ROZM>
TWektor<TYP, ROZM> TWektor<TYP,ROZM>::operator * (double l) const
{
  TYP nowy[ROZMIAR]={0.0};
  for(int i=0; i<ROZMIAR; i++)
  {
    nowy[i]=this->Twek[i]*l;
  }
  return TWektor(nowy);
}

template <typename TYP, int ROZM>
TWektor<TYP, ROZM> TWektor<TYP,ROZM>::operator / (double l) const
{
  TYP nowy[ROZMIAR]={0.0};
  for(int i=0; i<ROZMIAR; i++)
  {
    nowy[i]=this->Twek[i]/l;
  }
  return TWektor(nowy);
}

template <typename TYP, int ROZM>
bool TWektor<TYP,ROZM>::operator == (const TWektor<TYP, ROZM> & W) const
{
  double epsilon=0.000001;
  for (int i=0; i<ROZMIAR; ++i)
  {
    if(abs(Twek[i]-W.Twek[i])>epsilon)
    return false;
  }
  return true;
}

template <typename TYP, int ROZM>
bool TWektor<TYP,ROZM>::operator != (const TWektor<TYP, ROZM> & W) const
{
    return !(*this==W);
}

template <typename TYP, int ROZM>
double TWektor<TYP,ROZM>::dlugosc() const //modul
{
  double wynik, a=0.0;
  for (int i=0; i<ROZMIAR; i++)
  {
    a+=this->Twek[i]*this->Twek[i];
  }
  wynik=sqrt(a);
  return wynik;
}


template <typename TYP, int ROZM>
istream & operator >> (istream & str, TWektor<TYP, ROZM> & W)
{
  TYP pom[ROZMIAR]={0};
  for(int i=0; i<ROZMIAR; i++)
  {
    str >> pom[i];
  }
  W=TWektor<TYP, ROZM>(pom);
  return str;
}
template <typename TYP, int ROZM>
ostream & operator << (ostream & str, const TWektor<TYP, ROZM> & W)
{
  for (int i=0; i<ROZMIAR; i++)
  {
    str << W[i]<<" ";
  }

  return str;
}
