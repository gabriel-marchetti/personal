#include <bits/stdc++.h>

using namespace std;

double calculateProb(double Ncows, double Ncars, double Nshow)
{
    double prob{0};

    prob += ( Ncars / (Ncars + Ncows) ) * ( (Ncars-1) / (Ncars + Ncows - Nshow - 1) );
    prob += ( Ncows / (Ncars + Ncows) ) * ( (Ncars) / (Ncars + Ncows - Nshow - 1) );

    return prob;
}

int main(void)
{
    double Ncars{0}, Ncows{0}, Nshow{0}, probability{0};
    
    while( cin >> Ncows >> Ncars >> Nshow ){
        probability = calculateProb(Ncows, Ncars, Nshow);
        printf("%.5f\n", probability);
    }
    

    return 0;
}