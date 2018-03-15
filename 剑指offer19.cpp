#include<iostream>
#include<string>
#include<cctype>
#include <vector>
#include<exception>
#include <initializer_list>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {

        int row1 = 0, row2 = matrix.size();//row2行数
        int col1 = 0, col2 = matrix[0].size();//col2列数
        vector<int> result;
        while (true)
        {
            //从左到右打印
            for (int i = col1; i < col2; i++)
                result.push_back(matrix[row1][i]);
            row1++;

            if (row1 >= row2)break; //循环终止条件

            //从上往下打印
            for (int i = row1; i < row2; i++)
                result.push_back(matrix[i][col2-1]);
            col2--;

            if (col1 >= col2)break;

            //从右往左打印
            for (int i = col2-1; i >= col1; i--)
                result.push_back(matrix[row2-1][i]);
            row2--;

            if (row1 >= row2)break;

            //从下往上打印
            for (int i = row2-1; i >= row1; i--)
                result.push_back(matrix[i][col1]);
            col1++;

            if (col1 >= col2)break;
        }
        return result;
    }
};

int main()
{

    Solution so;
    vector<vector<int>> matrix;
    vector<int> vec;
    vector<int> result;

    vec = { 1,2,3,4};
    matrix.push_back(vec);
    vec = { 5,6,7,8 };
    matrix.push_back(vec);
    vec = { 9,10,11,12 };
    matrix.push_back(vec);
    vec = {13,14,15,16 };
    matrix.push_back(vec);

    result = so.printMatrix(matrix);

    while (!result.empty())
    {
        cout << *(result.end()-1) << "  ";
        result.pop_back();//从后往前打印
    }


    cout << endl;
    return 0;
}
