#include <iostream>
#include <vector>
#include <map>
#include <cassert>
using namespace std;


int nonConstructibleChange(vector<int> coins) {
    int minChange = 0;
    if (coins.size() > 1) {
        for (int i = 0; i < coins.size() - 1; i++) {
            for (int j = i + 1; j < coins.size(); j++) {
                if (coins[j] < coins[i]) {
                    int aux = coins[j];
                    coins[j] = coins[i];
                    coins[i] = aux;
                }
            }
        }
    }    

    for (int i = 0; i < coins.size(); i++) {
        if (coins[i] > minChange + 1) {
            return (minChange + 1);
        } else {
            minChange += coins[i];
        }
    }
    return (minChange + 1);
}

void test_0(void) {
    vector<int> input = {5, 7, 1, 1, 2, 3, 22};
    int expected = 20;
    auto actual = nonConstructibleChange(input);
    assert(expected == actual);
    printf("Done test 0!");
}


void test_1(void) {
    vector<int> input = {109, 2000, 8765, 19, 18, 17, 16, 8, 1, 1, 2, 4};
    int expected = 20;
    auto actual = nonConstructibleChange(input);
    assert(expected == actual);
    printf("Done test 0!");
}

int main()
{
    // Test 1
    test_0();
    // test_1();
}