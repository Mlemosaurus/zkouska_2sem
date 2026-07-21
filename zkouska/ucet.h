#pragma once

#include <string>
#include <vector>



class Ucet{

    protected:
        std::string cisloUctu;
        std::vector<double> historieTransakci;
        static int pocetUctu;
    
    public:

        Ucet(std::string cisloUctu, std::vector<double> historieTransakci);

        virtual ~Ucet();   //Nezapomeň na virtual, pro polymorfizmus je potřeba

        void pridejTransakci(double hodnota);

        void pridejTransakce(std::vector<double> hodnoty);

        static int getPocet();

        virtual void analyzujUcet() const = 0;   //tohle je čistě vitruální, DEJ TAM NULU

        virtual void vypisInfo() const;

        std::vector<double>& getHistorie();  //!!Potřeba do mainu, abys mohl brát z účtů vektory!!



};