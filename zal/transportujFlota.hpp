#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    unsigned int licznikTowaru = 0;                           //licznik towaru na poczatku
    unsigned int liczbaZaglowcow = 0;                         //licznik zaglowcow na poczatku

    if(towar == 0)                                            //jesli liczba towaru jest rowna 0
      return liczbaZaglowcow;

    Stocznia stocznia{};                                      

    while(licznikTowaru < towar)
    {
      Statek* statek = stocznia();
      licznikTowaru += (statek->transportuj());              //dodanie towaru znajdującego sie na statku

      if(dynamic_cast<Zaglowiec*>(statek))                   //sprawdzenie czy statek jest zaglowcem
        liczbaZaglowcow += 1;

      delete statek;                                         //niszczenie statku
    }

   return liczbaZaglowcow; 
}