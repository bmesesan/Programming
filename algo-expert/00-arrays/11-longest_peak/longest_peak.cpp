#include <iostream>
#include <vector>
#include <map>
#include <cassert>
using namespace std;


int longestPeak(vector<int> array) {
    // Write your code here.
    int longestPeak = 0;

    if (array.size() < 3) {
        return 0;
    }

    for (int i = 1; i < array.size() - 1; i++) {
        if (array[i - 1] < array[i] && array[i + 1] < array[i]) {
            int currPeak = 3;
            
            // Check left
            int currIdLeft = i - 1;
            int idLeft = i - 2;
            int additionalLeft = 0;
            while (idLeft > -1 && array[idLeft] < array[currIdLeft]) {
                currIdLeft = idLeft;
                idLeft--;
                additionalLeft++;
            }

            // Check right
            int currIdRight = i + 1;
            int idRight = i + 2;
            int additionalRight = 0;
            while (idRight < array.size() && array[idRight] < array[currIdRight]) {
                currIdRight = idRight;
                idRight++;
                additionalRight++;
            }

            // Update current peak and compare it with the lngest peak
            currPeak += (additionalLeft + additionalRight);
            if (currPeak > longestPeak) {
                longestPeak = currPeak;
            }
        }
    }

    return longestPeak;
}



void test_0(void) {
    vector<int> input = {1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3};
    int expected = 6;
    int actual = longestPeak(input);
    assert(expected == actual);
}

int main()
{
    test_0();
}