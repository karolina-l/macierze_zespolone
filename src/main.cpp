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
  char znacznik;
  fstream plik;


  plik.open("w1.txt", ios:: in); //otwieram plik z danymi
  cout<<"otwieram\n";
  if(plik.good() == true) // jesli plik zostal poprawnie otwarty
  {
    znacznik=getchar();
    cout<<znacznik<<endl;
    /*switch(znacznik)
    {
      case 'r':
      {
        TUkladRownanL<double,5> ukl;
        TWektor<double, 5> wynik;
        plik >> ukl;
        cout<<ukl<<endl;
        wynik=ukl.oblicz();
        cout<<"wynik: "<<endl;

      }
      case 'z':
      {
        TUkladRownanL<LZespolona,5> ukl;
        TWektor<LZespolona, 5> wynik;
        plik >> ukl;
        cout<<ukl<<endl;
        wynik=ukl.oblicz();
        cout<<"wynik: "<<endl;

      }
      default:
      cerr<<"Brak poprawnego znacznika typu danych"<<endl;
    }*/
  }
  plik.close();            //zamkniecie pliku
  return 0;
}
