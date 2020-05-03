#include "TUkladRownanLiniowych.hh"

 /*
   Komstruktor klasy UkladRownanL;
   tworzy MacierzKw, której elementy
   sa rowne 0.0 i Wektor w postaci:
   wek={0.0, 0.0, 0.0}
 */
 template <typename TYP, int ROZM>
TUkladRownanL<TYP,ROZM>:: TUkladRownanL()
{
  M=TMacierzKw<TYP,ROZM>();
  W=TWektor<TYP,ROZM>();
}

/*
  Komstruktor klasy TUkladRownanL;
  tworzy MacierzKw i Wektor, których elementy
  sa rowne zadanej macierzy i wektorowi
*/
template <typename TYP, int ROZM>
TUkladRownanL<TYP,ROZM>:: TUkladRownanL(const TMacierzKw<TYP,ROZM> & AA,const TWektor<TYP,ROZM> & BB)
{
  M=AA;
  W=BB;
}

/*
  metoda zwroc_macierz zwraca macierz
  danego ukladu rownan
*/
template <typename TYP, int ROZM>
const TMacierzKw <TYP,ROZM> TUkladRownanL<TYP,ROZM>::zwroc_macierz() const
{
  return this->M;
}

/*
  metoda zmien_macierz zmienia macierz
  danego ukladu rownan na podana do metody
*/
template <typename TYP, int ROZM>
void TUkladRownanL<TYP,ROZM>:: zmien_macierz(const TMacierzKw<TYP,ROZM> & mat)
{
    M=mat;
}

/*
  metoda zwroc_wektor zwraca wektor
  danego ukladu rownan
*/
template <typename TYP, int ROZM>
const TWektor<TYP,ROZM> TUkladRownanL<TYP,ROZM>::zwroc_wektor() const
{
  return this->W;
}

/*
  metoda zmien_wektor zmienia wektor
  danego ukladu rownan na podany do metody
*/
template <typename TYP, int ROZM>
void TUkladRownanL<TYP,ROZM>::zmien_wektor(const TWektor<TYP,ROZM> & wek)
{
  W=wek;
}

/*
  metoda oblicz rozwiazuje dany uklad rownan
  zwraca wektor wynikow
*/
template <typename TYP, int ROZM>
TWektor<TYP,ROZM> TUkladRownanL<TYP,ROZM>:: oblicz() const
{
  TUkladRownanL pom=*this;
  TMacierzKw<TYP,ROZM> mat;
  TWektor<TYP,ROZM> wyn, temp, wek;
  TYP wyznacznik[ROZMIAR], wyzn;
  double eps=0.000000001;

  mat=pom.zwroc_macierz();
  wek=pom.zwroc_wektor();
  wyzn=mat.wyznacznik();
  for(int i=0; i<ROZMIAR; i++)
  {
    temp=mat.zwroc_kolumne(i);
    mat.zmien_kolumne(i, wek);
    wyznacznik[i]=mat.wyznacznik();
    mat.zmien_kolumne(i, temp);
  }

  /*for (int i=0; i<ROZMIAR; i++)
  {
    wyn[i]=wyznacznik[i]/wyzn;
    cout<<"wyn"<<i<<": "<<wyn[i]<<endl;
  }


  if(wyzn>eps)
  cout<<"elo";
  else
  cout<< "melo";
    return wyn;*/

  if((wyzn>eps) || (wyzn*(-1))>eps)
  {
    for (int i=0; i<ROZMIAR; i++)
    {
      wyn[i]=wyznacznik[i]/wyzn;
    }

    return wyn;
  }
  else
  {
    int li=0;
    for(int i=0; i<ROZMIAR; i++)
    {
      if((wyznacznik[i]>eps) || (wyznacznik[i]*(-1))>eps)
        li++;
    }
    if(li==0)
    {
      cout<<"Uklad jest nieoznaczony"<<endl;
      return 0;
    }
    else
    {
      cout<<"Uklad jest sprzeczny"<<endl;
      return 0;
    }
  }

}

/*
  metoda blad oblicza blad wyniku w stosunku
  do wektora ukladu rownan
  zwraca liczbe double rowna dlugosci wektora bledu
*/
/*template <typename TYP, int ROZM>
double TUkladRownanL<TYP,ROZM>:: blad(TWektor<TYP,ROZM> wyn) const
{
    TWektor<TYP,ROZM> eps, mnoz;
    double bl;

    mnoz=M*wyn;
    eps=mnoz-W;
    bl=eps.dlugosc();

    return bl;
}*/

/*
  Przeciazenie operatora ">>"
  dla klasy TUkladRownanL
  zwraca strumien przesuniecia bitowego w prawo
*/
template <typename TYP, int ROZM>
istream & operator >> (istream &str, TUkladRownanL<TYP,ROZM> &Ukl)
{
  TMacierzKw<TYP,ROZM> mat;
  TWektor<TYP,ROZM>  wek;

  str >> mat;
  Ukl.zmien_macierz(mat);
  str >> wek;
  Ukl.zmien_wektor(wek);

  return str;
}

/*
  Przeciazenie operatora "<<"
  dla klasy TUkladRownanL
  zwraca strumien przesuniecia bitowego w prawo
*/
template <typename TYP, int ROZM>
ostream & operator << (ostream  &str,  const TUkladRownanL<TYP,ROZM> &Ukl )
{
  TMacierzKw<TYP,ROZM> mat;
  TWektor<TYP,ROZM>  wek;
  wek=Ukl.zwroc_wektor();
  mat=Ukl.zwroc_macierz();

    for (int i=0; i<ROZMIAR; i++)
  {
    for (int j=0; j<ROZMIAR+1; j++)
    {
      if(j==0)
        str<<"|";

      if(j==ROZMIAR)
      {
        str<<"|"<<" "<<"|x_"<<i+1<<"|";

        if(i==(ROZMIAR/2))
        str<<" = |"<<wek[i]<<"|";
        else
        str<<"   |"<<wek[i]<<"|";
        str<<endl;
      }
      else
      str<<mat[i][j]<<" ";

    }
  }
  return str;
}
