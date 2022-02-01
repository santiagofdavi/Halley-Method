/* HALLEY METHOD IN C++  

Created using the F.F.CAMPOS' Algotithm in "Algoritmos Numéricos", LTC 3rd

Author: Davi Ferreira Santiago
    School of Engineering, Universidade Federal de Minas Gerais
Date: February 1st, 2022 */

#ifndef HALLEY_H
#define HALLEY_H

double avaliacao_funcao(const double &x);

double avaliacao_derivada_funcao(const double &x);

double avaliacao_derivada2_funcao(const double &x);

void print(const double &x, const double &Fx, const double &DFx, 
           const double &D2Fx, const double &deltax, const unsigned &k);

void print_final(const double &x, const double &Fx, const double &DFx, 
                 const unsigned &k);

void halley(double &x, double &Toler, unsigned &IterMax);

#endif