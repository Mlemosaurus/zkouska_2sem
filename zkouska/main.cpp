#include <iostream>
#include <vector>
#include <string>

#include "ucet.h"
#include "bezny.h"
#include "sporak.h"

void nejdelsiRada(Ucet* u);  //algoritmy ve funkcích, definice na konci souboru
void odstraneniVyberu(Ucet* u);


int main(){

    std::cout<<"pocet uctu: "<<Ucet::getPocet()<<std::endl;

    //START algoritmy a pretezovani 
    

   
    BeznyUcet a("123", {20, -40, 50, 60}, 50 );
    BeznyUcet b("124", {-40, 50, 60, 55, 10, -50, -20, -30, 10, 0}, 50);  //Jdou tam dát čistě i hodnoty
    BeznyUcet c("125", {20, -40, 30, 55}, 40);

     int je = (a==b);    //zkoušení přetěžování
    int neni = (b==c);
    std::cout<<je<<" "<<neni<<std::endl;

    std::cout<<b<<std::endl;
    b += 22;
    std::cout<<b<<std::endl;
    
    

    //Algoritmus 1 - nejdelsi vklad

    //std::vector<double> cisla = {10, 40, 30 ,-40, -30, -80, -20};    // do algorimu si dej misto transakce cisla a mas obecny algoritmy <3
   

    int max_pocet = 0;
    int akt_pocet = 0;

    std::vector<double>& transakce = b.getHistorie();   //!!udělaj si getter v bazický třidě!!

    for(double num : transakce){  //vyspání vektoru
        std::cout<<num<<" ";
    }

    for(int i = 0;i <transakce.size();i++){   
        if(transakce[i]>0){
            akt_pocet++;
        }else{
            if(akt_pocet>max_pocet) max_pocet = akt_pocet;
            akt_pocet = 0;          
        }
       
    } if(akt_pocet>max_pocet) max_pocet = akt_pocet;

    std::cout<<"Nejdelsi rada vyberu: "<<max_pocet<<std::endl;


    nejdelsiRada(&b); // to samý ve funkci


    //algoritmus 2 ostraneni malych vyberu
    

    std::cout<<std::endl;

    for(int i = 0; i<transakce.size();i++){      //obecny algoritmus pro random vektor
        if(transakce[i]> -50 && transakce[i] < 0){
            transakce.erase(transakce.begin()+i);  //skočí to o 2: zmenší se vektor, takže i ukazuje na další prvek a pak se dá i++ -> jeden se přeskočí
            i--;
        }
    }

    for(double num : transakce){
        std::cout<<num<<" ";
    }


    odstraneniVyberu(&b); // to samý ve funkci
    //šlo by i např: odstraneniVyberu(seznam[0]) když to máš ve vektoru ukazatelů
    //nebo odstaneniVyberu(p), když to alokuješ dynamicky, bo už tam * je a ty potřebuješ Ucet * u <3

    
    //KONEC algoritmů a pretezovani

    

    //DYNAMICKÁ ALOKACE, POLYMORFISMUS

    BeznyUcet *p = new BeznyUcet("200", {10, 70, 30, -40}, 20);   //dynamický vytváření, nezapoměň na konci odstanit delete
    BeznyUcet *q = new BeznyUcet("201", {10, 20, -30, -40}, 40);
    SporiciUcet *r = new SporiciUcet("202", {10, -20, 150, -40}, 30);

    std::cout<<"pocet uctu: "<<Ucet::getPocet()<<std::endl;


    std::vector<Ucet*> seznam;   //more, tohle jsi měl blbě! vektor ukazatelů

    seznam.push_back(p);  
    seznam.push_back(q);
    seznam.push_back(r);

    for(int i = 0; i<seznam.size(); i++){   //polymorfismus
        seznam[i]->vypisInfo();
        seznam[i]->analyzujUcet();

    }

    delete p;    //Když to vytvoříš, musíš to odstanit
    delete q;
    delete r;

    std::cout<<"pocet uctu: "<<Ucet::getPocet()<<std::endl;


    return 0;
}




void nejdelsiRada(Ucet* u){
    int max_pocet = 0;
    int akt_pocet = 0;


    
    std::vector<double>& transakce = u->getHistorie();   //udělaj si getter v bazický třidě

    for(double num : transakce){  //vyspání vektoru
        std::cout<<num<<" ";
    }

    for(int i = 0;i <transakce.size();i++){   
        if(transakce[i]>0){
            akt_pocet++;
        }else{
            if(akt_pocet>max_pocet) max_pocet = akt_pocet;
            akt_pocet = 0;          
        }
       
    } if(akt_pocet>max_pocet) max_pocet = akt_pocet;

    std::cout<<"Nejdelsi rada vyberu: "<<max_pocet<<std::endl;
}


void odstraneniVyberu(Ucet* u){
 
    std::vector<double>& transakce = u->getHistorie();

    for(int i = 0; i<transakce.size();i++){      //obecny algoritmus pro random vektor
        if(transakce[i]> -50 && transakce[i] < 0){
            transakce.erase(transakce.begin()+i);  //skočí to o 2: zmenší se vektor, takže i ukazuje na další prvek a pak se dá i++ -> jeden se přeskočí
            i--;
        }
    }

    for(double num : transakce){
        std::cout<<num<<" ";
    }
}
