#pragma once

#include "ucet.h"


class BeznyUcet : public Ucet{

    private:
        double poplatek;
    
    public:

        BeznyUcet(std::string cisloUctu, std::vector<double> historieTransakci, double poplatek);
        
        void analyzujUcet() const override;

        void vypisInfo() const override;

        bool operator==(const BeznyUcet& other);

        BeznyUcet&  operator+=(double hodnota);

        friend std::ostream& operator<<(std::ostream& os, const BeznyUcet& u);


};