#include <iostream>
#include <vector>
#include <vector>
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
    // Write your code here.
    int cnt_arr = 0;
    int cnt_sub = 0;
    for (cnt_arr = 0; cnt_arr < array.size(); cnt_arr++) {
        if (array[cnt_arr] == sequence[0]) {
            cnt_sub = 0;
            for (int i = cnt_arr; i < array.size(); i++) {
                if (array[i] == sequence[cnt_sub]) {
                    cnt_sub++;
                }
                if (cnt_sub == sequence.size()) {
                    return true;
                }
            }
        }    
    }
    
    return false;
}


void test_0(void) {
    // Test 1
    vector<int> array = {5, 1, 22, 25, 6, -1, 8, 10};
    vector<int> subsequence = {1, 6, 1, 10};
    bool result = isValidSubsequence(array, subsequence);
    std::cout << "Result = " << result << std::endl;
    printf("Done test 0!");
}

int main()
{
    // Test 1
    test_0();
}