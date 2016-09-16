#include <iostream>

using namespace std;

int vonNeumann4DigitsIte(int graine)
{
    int alea, temp;

    alea = graine*graine;
    alea /= 100;

    temp = alea / 10000;
    temp *= 10000;

    alea -= temp;

    return alea;
}

void vonNeumann(int graine, int nb)
{
    int alea = graine;

    for(int i = 0;i<nb;i++)
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

int * LCG(int graine,int a, int c, int m, int nb, bool trace)
{
    int * res = new int[nb];
    int cour = graine;
    for (int i = 0; i<nb ; i++)
    {
        res[i] = cour;
        cour = (a*cour+c) % m;
    }

    if(trace)
    {
        for(int i=0;i<nb;i++)
        {
            cout << res[i] << endl;
        }
    }

    return res;
}

int * LCGStatTest(int nbSimu, bool trace)
{
    int * tab = new int[10];
    int * res = LCG(125, 25, 16, 256, nbSimu, false);
    double cour;
    int tronc = 0;

    for(int i = 0; i<nbSimu; i++)
    {
        cour = res[i]/254.0;
        tronc = 10*cour;
        tab[tronc]++;
    }

    delete res;

    if(trace)
    {
        for(int i = 0; i<10; i++)
        {
            cout << i << " : " << tab[i] << endl;
        }
    }

    return tab;
}

int * LFSR4bits()
{
    
}