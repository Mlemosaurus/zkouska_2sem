#pragma once

#include "ucet.h"


class SporiciUcet : public Ucet{

    private:
        double urok;
    
    public:
        SporiciUcet(std::string cisloUctu, std::vector<double> historieTransakci, double urok);

        void analyzujUcet() const override;

        void vypisInfo() const override;


};