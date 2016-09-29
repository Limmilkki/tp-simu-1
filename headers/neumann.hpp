//
// Created by kevin on 16/09/2016.
//

#ifndef TP_SIMU_1_NEUMANN_HPP
#define TP_SIMU_1_NEUMANN_HPP

long vonNeumann4DigitsIte(long graine);
void vonNeumann(long graine, long nb);
void vonNeumannTests();
long * LCG(long graine,long a, long c, long m, long nb, bool trace);
long * LCGStatTest(long nbSimu, bool trace);
void LFSR4bits();
long * LCGBrassage(long * graine, long * a, long * c, long m, long nb,long N,bool trace);
#endif //TP_SIMU_1_NEUMANN_HPP
