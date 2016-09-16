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
    cout << vonNeumann(1234, 70);
    cout << endl;

    cout << "Cycle" << endl;
    cout << vonNeumann(4100, 10);
    cout << endl;

}