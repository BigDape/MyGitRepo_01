#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
class Solution {
public:
    vector<int> printMatrix(vector<vector<int>> matrix) {
        vector<int> res;
        res.clear();
        int row = matrix.size();
        int col = matrix[0].size();
        int circle = ((row < col ? row : col) - 1) / 2 + 1;
        for (int i = 0; i < circle; i++)
        {
            for (int j = i; j < col - i; j++)
                res.push_back(matrix[i][j]);
            for (int k = i + 1; k < row - i; k++)
                res.push_back(matrix[k][col-1-i]);
            for (int m = col - i - 2; (m > -i) && (row - i - 1 != i); m--)
                res.push_back(matrix[row-i-1][m]);
            for (int n = row - i - 2; (n > i) && (col - i - 1 != i); n--)
                res.push_back(matrix[n][i]);
        }
        return res;
    };
};