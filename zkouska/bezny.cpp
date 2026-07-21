#include "bezny.h"
#include <iostream>

 BeznyUcet::BeznyUcet(std::string cisloUctu, std::vector<double> historieTransakci, double poplatek) : Ucet(cisloUctu, historieTransakci){
    this->poplatek = poplatek;
 }
        
        void BeznyUcet::analyzujUcet() const {
            int vybery = 0;
            for(double cislo : historieTransakci){
                if(cislo<0) vybery++;
            }
            std::cout<<"ANALYZA Pocet vyberu: "<<vybery<<std::endl;
        }

       void  BeznyUcet::vypisInfo() const {
        std::cout<<"VYPIS Cislo uctu: "<<cisloUctu<<" pocet transakci: "<<historieTransakci.size()<<" poplatek: "<<poplatek<<std::endl;
       }


       bool BeznyUcet::operator==(const BeznyUcet& other){
       return (this->poplatek == other.poplatek);
       }

        BeznyUcet&  BeznyUcet::operator+=(double hodnota){
            this->historieTransakci.push_back(hodnota);
            //this->pridejTransakci(hodnota);    //pomocí metody z bazické třídy, ale to nahoře je jistota
            return *this;   //musíme vrátit referenci na aktuální objekt
        }

                //void BeznyUcet::operator+=(double hodnota){}  pak historieTransakci.push_back(hodnota);


        std::ostream& operator <<( std::ostream& os,const BeznyUcet& u){
            os<<"BeznyUcet: "<<u.cisloUctu<<" , transakci: "<<u.historieTransakci.size();
            return os;
        }


