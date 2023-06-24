#include <iostream>
#include <vector>
#include <map>
#include <cassert>
using namespace std;


vector<int> arrayOfProducts(vector<int> array) {
    // Write your code here.
    // O(n * log(n))
    // mergeSort(array);
    vector<int> result;
    for (int i = 0; i < array.size(); i++) {
        int prod = 1;
        int idLeft = i - 1;
        int idRight = i + 1;
        while (idLeft > -1) {
            prod *= array[idLeft];
            idLeft--;
        }
        while (idRight < array.size()) {
            prod *= array[idRight];
            idRight++;
        }
        result.push_back(prod);
    }
    
    return result;
}


void test_0(void) {
    vector<int> input = {5, 1, 4, 2};
    vector<int> expected = {8, 40, 10, 20};
    vector<int> actual = arrayOfProducts(input);
    assert(expected == actual);
}

int main()
{
    test_0();
}