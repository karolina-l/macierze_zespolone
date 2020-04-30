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




//main do szablonu, ruszac//
TMacierzKw<double,5> M1, M2;
double wyz;
/*TMacierzKw<LZespolona, 5> M1, M2;
TWektor<LZespolona,5> W;
LZespolona wyz;
fstream plik1, plik2;
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
}*/

/*cin>>W;
cout<<M1<<endl<<endl;
cout<<M2<<endl;
cout<<endl<<"+ "<<M1+M2<<endl;
cout<<"- "<<M1-M2<<endl<<endl;
cout<<"* "<<M1*M2<<endl<<endl;
cout<<"*w "<<M1*W<<endl<<endl;
cout<<"*2 "<<M1*2.0<<endl<<endl;
W=M1.zwroc_kolumne(1);
cout<<"k1: "<<W<<endl<<endl;
M2.zmien_kolumne(0,W);
cout<<"k0: "<<M2<<endl<<endl;*/
cin>>M1;
cout<<endl<<M1<<endl;
wyz=M2.wyznacznik();
cout<<"wyz: "<<wyz<<endl;

cout<<"KONIEC"<<endl;



//main do szablonu, ruszac//



//plik1.close();
//plik2.close();
  return 0;
}
