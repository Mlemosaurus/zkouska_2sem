#include "sporak.h"

#include <iostream>


SporiciUcet::SporiciUcet(std::string cisloUctu, std::vector<double> historieTransakci, double urok) : Ucet(cisloUctu, historieTransakci){
    this->urok = urok;
  }
        
         void SporiciUcet::analyzujUcet() const {
            int vklady = 0;
            double suma = 0.0;
            for(double cislo : historieTransakci){
                 if(cislo>0) {
                    suma +=cislo;
                    vklady++;
            }
            if(vklady>0){
                suma = suma / (double) vklady;
            }else suma =0;
            
        }
         std::cout<<"ANALYZA Prumerny vklad: "<<suma<<std::endl;
    }

        void SporiciUcet::vypisInfo() const {
         std::cout<<"VYPIS Cislo uctu: "<<cisloUctu<<" pocet transakci: "<<historieTransakci.size()<<" urok: "<<urok<<std::endl;
        }