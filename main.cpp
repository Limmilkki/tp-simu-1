#include <iostream>
#include "headers/neumann.hpp"
using namespace std;
int main() {
    //LCG(32162,65539,0,32768,100,false); //RANDU Generator with 16bits. Supposed to be bad generator
    //LCG(34946,69069,0,32768,100,false); //Marsaglia Generator used in VAX machine. Supposed to be good.

    long g[2] = {32162,65539};
    long a[2] = {65539,69069};
    long c[2] = {0,0};
    long m = 32768;
    long nb = 10*m;
    LCGBrassage(g,a,c,m,nb,nb,true);
    return 0;
}

/**
RANDU GENERATOR TEST 10*2^16 Numbers
0 : 65600
1 : 65520
2 : 65520
3 : 65600
4 : 65440
5 : 65600
6 : 65520
7 : 65520
8 : 65600
9 : 65440
 **/

/**
Marsaglia Generator TEST 10*2^16 NUmbers
0 : 65520
1 : 65600
2 : 65520
3 : 65520
4 : 65520
5 : 65600
6 : 65520
7 : 65520
8 : 65520
9 : 65520
**/

