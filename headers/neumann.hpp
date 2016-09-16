//
// Created by kevin on 16/09/2016.
//

#ifndef TP_SIMU_1_NEUMANN_HPP
#define TP_SIMU_1_NEUMANN_HPP

int vonNeumann4DigitsIte(int graine);
void vonNeumann(int graine, int nb);
void vonNeumannTests();
int * LCG(int graine,int a, int c, int m, int nb, bool trace);
int * LCGStatTest(int nbSimu, bool trace);
void LFSR4bits();
#endif //TP_SIMU_1_NEUMANN_HPP
