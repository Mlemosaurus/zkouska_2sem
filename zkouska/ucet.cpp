#include "ucet.h"
#include <iostream>
#include <vector>
#include <string>


    int Ucet::pocetUctu =0;

 Ucet::Ucet(std::string cisloUctu, std::vector<double> historieTransakci){
    this->cisloUctu = cisloUctu;
    this->historieTransakci = historieTransakci;
    pocetUctu++;
 }

        Ucet::~Ucet(){
            pocetUctu--;
        }

        void Ucet::pridejTransakci(double hodnota){
            historieTransakci.push_back(hodnota);
        }

       void Ucet::pridejTransakce(std::vector<double> hodnoty){
            for(double cislo : hodnoty){
                historieTransakci.push_back(cislo);
            }

       }

         int Ucet::getPocet(){
            return pocetUctu;
         }

        std::vector<double>& Ucet::getHistorie(){
            return historieTransakci;
        }



        void Ucet:: vypisInfo() const{
            std::cout<<"Cislo uctu: "<<cisloUctu<<" pocet transakci: "<<historieTransakci.size()<<std::endl;
        }