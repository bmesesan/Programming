#include <iostream>
#include <vector>
#include <map>
#include <cassert>
using namespace std;


vector<int> spiralTraverse(vector<vector<int>> array) {
    // Write your code here.
    std::vector<int> result;

    int finalRow = array.size() / 2;
    int finalCol = array[0].size() / 2;
    int startRow = 0;
    int stopRow = array.size() - 1;
    int startCol = 0;
    int stopCol = array[0].size() - 1;
    int i;
    int j;

    while (startRow <= stopRow && startCol <= stopCol) { 
        i = startRow;
        j = startCol;
        while (j <= stopCol) {
            result.push_back(array[i][j]);
            j++;
        }
        
        i = startRow + 1;
        j = stopCol;
        while (i <= stopRow) {
            result.push_back(array[i][j]);
            i++;
        }
        
        if (startRow != stopRow) {
            i = stopRow;
            j = stopCol - 1;
            while (j >= startCol) {
                result.push_back(array[i][j]);
                j--;
            }
        }
        
        if (startCol != stopCol) {
            i = stopRow - 1;
            j = startCol;
            while (i >= startRow + 1) {
                result.push_back(array[i][j]);
                i--;
            }
        }
        

        startRow += 1;
        startCol += 1;
        stopRow -= 1;
        stopCol -= 1;
    }

    return result;
}


void test_0(void) {
    vector<vector<int>> input = {
        {1, 2, 3, 4},
        {12, 13, 14, 5},
        {11, 16, 15, 6},
        {10, 9, 8, 7},
    };
    vector<int> expected = {1, 2,  3,  4,  5,  6,  7,  8,
                            9, 10, 11, 12, 13, 14, 15, 16};
    vector<int> actual = spiralTraverse(input);
    assert(expected == actual);
}

void test_1(void) {
    vector<vector<int>> input = {
        {1, 2, 3, 4},
        {10, 11, 12, 5},
        {9, 8, 7, 6},
    };
    // vector<int> expected = {4, 2, 3, 6, 7, 8, 1, 9, 5, 10,
    //                         14, 11, 17, 13, 18};
    vector<int> actual = spiralTraverse(input);
    // assert(expected == actual);
}

int main()
{
    test_0();
    // test_1();
}