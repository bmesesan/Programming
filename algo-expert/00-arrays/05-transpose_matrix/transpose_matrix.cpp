#include <iostream>
#include <vector>
#include <map>
#include <cassert>
using namespace std;


vector<vector<int>> transposeMatrix(vector<vector<int>> matrix) {
    // Write your code here.
    // Matrix
    // 1 2 3
    // 5 6 7
    // Transpose
    // 1 5
    // 2 6
    // 3 7
    int n = matrix.size();
    int m = matrix[0].size();
    int *transposed = (int*)std::malloc(n * m * sizeof(int));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            transposed[j * n + i] = matrix[i][j];
        }
    }

    vector<vector<int>> result;
    int* cursor = transposed; 
    for (int i = 0; i < m; i++){
        result.push_back(vector<int>(cursor, cursor + n));
        cursor += n;
    }

    return result;
}


void test_0(void) {
    vector<vector<int>> input = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> expected = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
    auto actual = transposeMatrix(input);
    assert(expected == actual);
    printf("Done test 0!");
}

int main()
{
    test_0();
}