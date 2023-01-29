#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct { 
    int diffMin;
    int v1;
    int v2;
} CMinDiff;

int main()
{
    int *v, n, i;
    CMinDiff perechi;
    perechi.diffMin = 0;
    cout << "Numarul de elemente este: ";
    cin >> n;
    cout << endl;
    v = (int*)malloc(n * sizeof(int));
    cout << "Elementele vectorului sunt: " << endl;
    for(i = 0; i < n; i++) {
        cin >> v[i];
    }
    if (n > 1) {
        perechi.diffMin = abs(v[0] - v[1]);
        perechi.v1 = v[0];
        perechi.v2 = v[1];
    }
    for(i = 1; i < n-1; i++) {
        if( abs(v[i] - v[i+1]) < perechi.diffMin){
            perechi.diffMin = abs(v[i] - v[i+1]);
            perechi.v1 = v[i];
            perechi.v2 = v[i+1];
        }
    }
    cout << "DiffMin is: " << perechi.diffMin << endl << "The numbers are: " << perechi.v1 << " and " << perechi.v2; 
    return 0;
}