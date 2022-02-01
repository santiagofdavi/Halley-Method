/* HALLEY METHOD IN C++  

Created using the F.F.CAMPOS' Algotithm in "Algoritmos Numéricos", LTC 3rd

Author: Davi Ferreira Santiago
    School of Engineering, Universidade Federal de Minas Gerais
Date: February 1st, 2022 */

#include <iostream>
#include <cmath>
#include <iomanip>

#include "Halley.hpp"

using namespace std;

double avaliacao_funcao(const double &x){

    return 2 * pow(x, 3) - cos(x + 1) - 4;

}

double avaliacao_derivada_funcao(const double &x){

    return 6 * pow(x, 2) + sin(x + 1);

}

double avaliacao_derivada2_funcao(const double &x){

    return 12 * x + cos(x + 1);

}

void print(const double &x, const double &Fx, const double &DFx, 
           const double &D2Fx, const double &deltax, const unsigned &k){

    cout << setprecision(5) << fixed << k << "   " << x; 
        
    cout << scientific << "   " << Fx << "  " << DFx << "    ";
    cout << D2Fx << "    " << deltax << endl;
    cout.unsetf(ios::scientific);
    cout << setprecision(5) << fixed;

}

void print_final(const double &x, const double &Fx, const double &DFx, 
                 const unsigned &k){

    cout << setprecision(5) << fixed << k << "   " << x; 
        
    cout << scientific << "   " << Fx << "  " << DFx << "    " << endl;
    cout.unsetf(ios::scientific);
    cout << setprecision(5) << fixed;

}

void halley(double &x, double &Toler, unsigned &IterMax){

    cout << "\n\tCalculo de raiz pelo metodo de Halley\n" << endl;

    cout << "k     x_k         Fx_k        DFx_k        D2Fx_k        deltax_k" << endl;

    int Info;

    unsigned k = 0;

    double Fx;
    double DFx;
    
    double deltax = 1 + Toler;
    double D2Fx;

    while(1){

        Fx = avaliacao_funcao(x);
        DFx = avaliacao_derivada_funcao(x);
        D2Fx = avaliacao_derivada2_funcao(x);

        if((fabs(deltax) <= Toler && fabs(Fx) <= Toler)
            || k >= IterMax){

            print_final(x, Fx, DFx, k);

            goto SaiDoLoop;

        }

        D2Fx = avaliacao_derivada2_funcao(x);
        deltax = 2 * Fx * DFx / (2 * pow(DFx, 2) - Fx * D2Fx);

        print(x, Fx, DFx, D2Fx, deltax, k);

        x -= deltax;

        k++;

    }

    SaiDoLoop:

    if(fabs(deltax) <= Toler && fabs(Fx) <= Toler){

        Info = 0;

    }

    else{

        Info = 1;

    }

    cout << endl;
    
    if(Info == 0 || Info == 2){
        
        cout << "Raiz = " << x << endl;

    }

    cout << "Iter = " << k << endl;
    cout << "Info = " << Info << endl << endl;

}