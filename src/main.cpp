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

int main(){

    double x, Toler;
    unsigned IterMax;

    cin >> x >> Toler >> IterMax;

    halley(x, Toler, IterMax);

    return 0;

}