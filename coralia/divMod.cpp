#include <iostream>
#include <vector>
#include <string>

using namespace std;

void littleNumbers(int n, int *v) {
    
    int i = 0;
    while ( n!= 0) {
        v[i] = n % 10;
        n = n/10;
        i++; 
    }
}

int main()
{
    int v[20];
    int *p1 = &v[0];
    int *p2 = &v[1];
    int *p3 = &v[2];
    int **p4 = &p1;
    littleNumbers(123456789, &v[0]);
    return 0;
}