#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct { 
    int h1;
    int h2;
} CPereche;

int main()
{
    int n;
    cout << "The number of students is ";
    cin >> n;
    cout << endl;

    int i;
    int min = 0;
    int nrOrdin = 0;
    CPereche *perechi;
    perechi = (CPereche*)malloc(n * sizeof(CPereche));
    cout << "Elementele vectorului sunt: " << endl;
    for(i = 0; i < n; i++) {
        cin >> perechi[i].h1;
        cin >> perechi[i].h2;
    }
    
    if (n > 1) {
        min = abs(perechi[0].h1 - perechi[0].h2);
    }
    for(i = 1; i < n; i++) {
        if( abs(perechi[i].h1 - perechi[i].h2) < min) {
            nrOrdin = i;
        }
    }
    cout << "Nr ordin is: " << nrOrdin;
    return 0;
}