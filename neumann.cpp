#include <iostream>
#include <bitset>

using namespace std;

long vonNeumann4DigitsIte(long graine)
{
    long alea, temp;

    alea = graine*graine;
    alea /= 100;

    temp = alea / 10000;
    temp *= 10000;

    alea -= temp;

    return alea;
}

void vonNeumann(long graine, long nb)
{
    long alea = graine;

    for(long i = 0;i<nb;i++)
    {
        cout << alea << endl;
        alea = vonNeumann4DigitsIte(alea);
    }
}

void vonNeumannTests()
{
    cout << "Etat absorbant type 0" << endl;
    vonNeumann(1234, 70);
    cout << endl;

    cout << "Cycle" << endl;
    vonNeumann(4100, 10);
    cout << endl;

}

long * LCG(long graine,long a, long c, long m, long nb, bool trace)
{
    long * res = new long[nb];
    long cour = graine;
    for (long i = 0; i<nb ; i++)
    {
        res[i] = cour;
        cour = (a*cour+c) % m;
    }

    if(trace)
    {
        for(long i=0;i<nb;i++)
        {
            cout << res[i] << endl;
        }
    }

    return res;
}

long * LCGStatTest(long nbSimu, bool trace)
{
    long * tab = new long[10];
    long * res = LCG(32162,65539,0,32768,100,false);
    double cour;
    long tronc = 0;

    for(long i = 0; i<nbSimu; i++)
    {
        cour = res[i]/65538.0;
        tronc = 10*cour;
        tab[tronc]++;
    }

    delete res;

    if(trace)
    {
        for(long i = 0; i<10; i++)
        {
            cout << i << " : " << tab[i] << endl;
        }
    }

    return tab;
}

/**
 * Ne pas tenir compte de cette fonction.
 * On avait pas réussi avec des longs classiques
 * Esayer de le faire avec un bitset. Sinon laisse tomber.
 * C'est toujours mieux de l'avoir pour le partiel.
 */

/*
void LFSR4bits()
{
    bitset<4> horloge(0);
    bitset<4> graine(6);
    bitset<4> sortie(0);
    bitset<4> entree(0);


    //A faire en bitset
    for(long i = 0; i < 8; i++)
    {
        sortie = graine % 2;
        graine = graine >>> 1;

        entree = horloge ^ sortie;
        cout << "Entree : " << entree << endl;

        graine += entree*8;
        cout << "Graine : " << graine << endl;

        sortie.
    }
}
*/

/**
 *
 * @param graine
 * @param a
 * @param c
 * @param m
 * @param nb
 * @param N
 * @param trace
 * @return
 *
 * L'algo est bon mais les résultats ne vont pas... Voir main.cpp
 */
long * LCGBrassage(long * graine, long * a, long * c, long m, long nb, long N, bool trace)
{
    long * LCGX;
    long * LCGY;
    long * tab = new long[N];
    long indice;
    long * res = new long[10];
    double cour;
    long tronc;

    LCGX = LCG(graine[0], a[0], c[0], m, nb, false);
    LCGY = LCG(graine[1], a[1], c[1], m, nb, false);

    for(long i=0; i<N; i++)
    {
        indice = LCGY[i] % nb;
        tab[i] = LCGX[indice];
    }


    for(int i=0;i<nb;i++)
    {
        cour = tab[i] / ((float) m+2);
        tronc = 10*cour;
        res[tronc]++;

    }

    if(trace)
    {
        for(int i = 0; i < 9; i++)
        {
            cout << i << " : " << res[i] << endl;
        }
    }

    delete [] LCGX;
    delete [] LCGY;
    delete [] tab;

    return res;
}