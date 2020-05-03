#include <iostream>
#include <fstream>
//#include "Wektor.hh"
//#include "TMacierz.hh"
#include "rozmiar.h"
//#include "UkladRownanLiniowych.hh"
//#include "TWektor.hh"
#include "mym.cpp"
#include "LZespolona.hh"



using namespace std;

int main()
{
  ////MAIN DO PROGRAMU NIE RUSZAĆ////
/*  //deklaracja danych
  UkladRownanL Uk;
  Wektor wynik;
  double blad;
  fstream plik;


  plik.open("plik.txt", ios:: in); //otwieram plik z danymi
  if(plik.good() == true) // jesli plik zostal poprawnie otwarty
  {
    plik>>Uk;             //UkladRownanL przybiera dane zawarte w pliku
  }
  cout<<endl<<Uk<<endl;   //wypisanieukladu rownan
  wynik=Uk.oblicz();      //rozwiaanie ukladu rownan
  blad=Uk.blad(wynik);    //wyznaczenie bledu przyblizen
  cout<<"wynik "<<wynik<<endl; //wypisanie rozwiazania
  cout<<"blad "<<blad<<endl;   //wypisanie wartosci bledu
  plik.close();            //zamkniecie pliku
*/
////MAIN DO PROGRAMU NIE RUSZAĆ////

/*fstream plik1, plik2;
plik1.open("w1.txt", ios:: in);
if(plik1.good() == true) // jesli plik zostal poprawnie otwarty
{
  cout<<"otwarte";
  plik1>>M1;            //UkladRownanL przybiera dane zawarte w pliku
}
plik2.open("w2.txt", ios:: in); //otwieram plik z danymi
if(plik2.good() == true) // jesli plik zostal poprawnie otwarty
{
  plik2>>M2;             //UkladRownanL przybiera dane zawarte w pliku
}
*/


//main do szablonu, ruszac//
TUkladRownanL <double,5> uk;
TWektor<double, 5> w;
cin>>uk;
cout<<endl<<uk<<endl;
w=uk.oblicz();
cout<<endl<<w<<endl;

cout<<"KONIEC"<<endl;



//main do szablonu, ruszac//



//plik1.close();
//plik2.close();
  return 0;
}
