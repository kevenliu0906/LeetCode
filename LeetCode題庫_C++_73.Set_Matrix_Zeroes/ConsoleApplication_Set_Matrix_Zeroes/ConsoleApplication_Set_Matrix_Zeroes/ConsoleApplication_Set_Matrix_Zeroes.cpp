// ConsoleApplication_Set_Matrix_Zeroes.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void dbg_2D_matrix(vector<vector<int>>& matrix){
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[i].size(); j++)
        {
            printf("%2d,", matrix[i][j]);
        }
        printf("\n");
    }
}

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // solution 1 (keven, using hash table to solve)
        {
            vector<int> col_indicate_zero;
            vector<int> row_indicate_zero;
            for (int i = 0; i < matrix.size(); i++){
                // STEP1: check if 0 cell exist in each row
                unordered_set<int> m_row(matrix[i].begin(), matrix[i].end());
                if (m_row.count(0)){
                    // printf("current row:%d would totally(size:%d) be set into all zeroes\n", i, matrix[i].size());
                    // represent current row: i has 0 cell
                    row_indicate_zero.push_back(i);
                    
                    // STEP2: check if 0 cell exist
                    for (int j = 0; j < matrix[i].size(); j++){
                        if (matrix[i][j] == 0){
                            // printf("current col:%d is 0\n", j);
                            // represent current cell is 0
                            col_indicate_zero.push_back(j);
                        }
                        
                    }

                    // clear current row cell into 0 value
                    vector<int> tmp_zero_row(matrix[i].size(), 0);
                    matrix[i].swap(tmp_zero_row);
                }   
            }            

            for (size_t i = 0; i < col_indicate_zero.size(); i++){
                // clear current col cell into 0 value (because of col-index will affect below row, so need clear it in the end)
                auto col_zero_idx = col_indicate_zero[i];
                int row_clear_idx  = 0;
                while (row_clear_idx < matrix.size()){
                    matrix[row_clear_idx][col_zero_idx] = 0;
                    row_clear_idx++;
                }
            }
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Set Matrix Zeroes, DataStructure(HASH TABLE, Array)!\n";
    cout << "https://leetcode.com/problems/set-matrix-zeroes/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: matrix = [[1,1,1],[1,0,1],[1,1,1]]\n");
    printf("expected result: output = [[1,0,1],[0,0,0],[1,0,1]]\n");
    {
        vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
        
        Solution solution;
        printf("before setZeroes >>>>>>\n");
        dbg_2D_matrix(matrix);
        solution.setZeroes(matrix);
        printf("after setZeroes >>>>>>\n");
        dbg_2D_matrix(matrix);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]\n");
    printf("expected result: output = [[0,0,0,0],[0,4,5,0],[0,3,1,0]]\n");
    {
        vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
        
        Solution solution;
        printf("before setZeroes >>>>>>\n");
        dbg_2D_matrix(matrix);
        solution.setZeroes(matrix);
        printf("after setZeroes >>>>>>\n");
        dbg_2D_matrix(matrix);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: matrix = [[1,2,3,4],[5,0,7,8],[0,10,11,12],[13,14,15,0]]\n");
    printf("expected result: output = [[0,0,3,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]\n");
    {
        vector<vector<int>> matrix = {{1,2,3,4},{5,0,7,8},{0,10,11,12},{13,14,15,0}};
        
        Solution solution;
        printf("before setZeroes >>>>>>\n");
        dbg_2D_matrix(matrix);
        solution.setZeroes(matrix);
        printf("after setZeroes >>>>>>\n");
        dbg_2D_matrix(matrix);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
