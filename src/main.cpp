#include <iostream>
#include <fstream>
//#include "Wektor.hh"
#include "Macierz.hh"
#include "rozmiar.h"
#include "UkladRownanLiniowych.hh"
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
//TWektor<LZespolona, 5> W1, W2,W3;
//TWektor<LZespolona, 5> W2;
//double tabl[ROZMIAR] = {3.002, 5.01, 1.002, 2.9};
double x=2.0;
TWektor<double, 5> W1, W2,W3;

cin>>W1;
cin>> W2;   //sprawdzenie >>
cout<<endl<<W1<<endl;  //sprawdzenie <<
//W2=TWektor<double, 5>(tabl); // sprawdzenie konstruktora z parametrem wejsciowym
cout<<endl<<W2<<endl;
cout<<W1+W2<<endl;    // sprawdzenie +
W2+=W1;   //sprawdzenie +=
cout<<"+="<<W2<<endl;
cout<<W1-W2<<endl;    //sprawdzenie -
cout<<"lz*lz"<<W1*W2<<endl;    //sprawdzenie *
cout<<W1*x<<endl;     //sprawdzenie * double
cout<<W1/x<<endl;     //sprawdzenie /
W3=W1;
cout<<"1"<<W1<<endl;
cout<<"2"<<W2<<endl;
cout<<"3"<<W3<<endl;

if(W2==W3)
{
  cout<<"rowne"<<endl;
}
else cout<<"zle"<<endl;
if(W2!=W3)
{
  cout<<"nierowne"<<endl;
}
else cout<<"zle"<<endl;
if(W1[0]>x)
{
  cout<<"zle";
}
else cout<<"mniejsze"<<endl;
cout<<"KONIEC"<<endl;



//main do szablonu, ruszac//




  return 0;
}
