#include <iostream>
#include <fstream>
#include "rozmiar.h"
#include "mym.cpp"
#include "LZespolona.hh"



using namespace std;

int main()
{
  ////MAIN DO PROGRAMU NIE RUSZAĆ////
 //deklaracja danych

  fstream plik;


  plik.open("w1.txt", ios:: in); //otwieram plik z danymi
  cout<<"otwieram\n";
  if(plik.good() == true) // jesli plik zostal poprawnie otwarty
  {
    switch(plik.get())
    {
      case 'r':
      {
        TUkladRownanL<double,5> ukl;
        TMacierzKw<double,5> mx;
        TWektor<double, 5> wynik;
        plik >> ukl;
        mx=ukl.zwroc_macierz();
        mx=mx.transponuj();
        ukl.zmien_macierz(mx);
        cout<<ukl<<endl;
        wynik=ukl.oblicz();
        cout<<"wynik: "<<wynik<<endl;
        break;

      }
      case 'z':
      {
        TUkladRownanL<LZespolona,5> ukl;
        TMacierzKw<LZespolona,5> mx;
        TWektor<LZespolona, 5> wynik;
        plik >> ukl;
        mx=ukl.zwroc_macierz();
        mx=mx.transponuj();
        ukl.zmien_macierz(mx);
        cout<<ukl<<endl;
        wynik=ukl.oblicz();
        cout<<"wynik: "<<wynik<<endl;
        break;

      }
      default:
      cerr<<"Brak poprawnego znacznika typu danych"<<endl;
    }
  }
  plik.close();            //zamkniecie pliku
  return 0;
}
