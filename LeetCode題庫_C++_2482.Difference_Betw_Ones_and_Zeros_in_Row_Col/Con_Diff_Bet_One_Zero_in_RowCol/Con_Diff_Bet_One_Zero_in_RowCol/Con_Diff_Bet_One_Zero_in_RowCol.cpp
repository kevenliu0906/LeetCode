// Con_Diff_Bet_One_Zero_in_RowCol.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> all_ones_minus_zeros(vector<vector<int>> &grid){
        int row = grid.size();
        int col = grid[0].size();

        vector<int> element_one_counts_row_vec(row, 0);   // record total numbers of #1 in each row.
        vector<int> element_zero_counts_row_vec(row, 0);  // record total numbers of #0 in each row.
        vector<int> element_one_counts_col_vec(col, 0);   // record total numbers of #1 in each col.
        vector<int> element_zero_counts_col_vec(col, 0);  // record total numbers of #0 in each col.

        // STEP1: traverse all element and summerize total counts for each row & col
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                if (grid[i][j] == 0){
                    // element is #0
                    element_zero_counts_row_vec[i]++;
                    element_zero_counts_col_vec[j]++;

                }else{
                    // element is #1
                    element_one_counts_row_vec[i]++;
                    element_one_counts_col_vec[j]++;
                }
            }
        }

        // printf("#1 row counts >>>\n");
        // for (size_t i = 0; i < element_one_counts_row_vec.size(); i++)
        //     printf("%d,", element_one_counts_row_vec[i]);
        // printf("\n\n");

        // printf("#0 row counts >>>\n");
        // for (size_t i = 0; i < element_zero_counts_row_vec.size(); i++)
        //     printf("%d,", element_zero_counts_row_vec[i]);
        // printf("\n\n");

        // printf("#1 col counts >>>\n");
        // for (size_t i = 0; i < element_one_counts_col_vec.size(); i++)
        //     printf("%d,", element_one_counts_col_vec[i]);
        // printf("\n\n");

        // printf("#0 col counts >>>\n");
        // for (size_t i = 0; i < element_zero_counts_col_vec.size(); i++)
        //     printf("%d,", element_zero_counts_col_vec[i]);
        // printf("\n\n");

        // STEP2: traverse again and figure the result
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                grid[i][j] = element_one_counts_row_vec[i] + element_one_counts_col_vec[j] - element_zero_counts_row_vec[i] - element_zero_counts_col_vec[j];
            }
        }
        
        return grid;
    }

public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        // solution 1 (keven, solve directly)
        {
            return all_ones_minus_zeros(grid);
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Difference Between Ones and Zeros in Row and Col, DataStructure(Array)!\n";
    cout << "https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column//" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: grid = [[0,1,1],[1,0,1],[0,0,1]]\n");
    printf("expected result: output = [[0,0,4],[0,0,4],[-2,-2,2]]\n");
    printf("Explanation - diff[0][0] = onesRow0 + onesCol0 - zerosRow0 - zerosCol0 = 2 + 1 - 1 - 2 = 0\n");
    printf("            - diff[0][1] = onesRow0 + onesCol1 - zerosRow0 - zerosCol1 = 2 + 1 - 1 - 2 = 0\n");
    printf("            - diff[0][2] = onesRow0 + onesCol2 - zerosRow0 - zerosCol2 = 2 + 3 - 1 - 0 = 4\n");
    printf("            - diff[1][0] = onesRow1 + onesCol0 - zerosRow1 - zerosCol0 = 2 + 1 - 1 - 2 = 0\n");
    printf("            - diff[1][1] = onesRow1 + onesCol1 - zerosRow1 - zerosCol1 = 2 + 1 - 1 - 2 = 0\n");
    printf("            - diff[1][2] = onesRow1 + onesCol2 - zerosRow1 - zerosCol2 = 2 + 3 - 1 - 0 = 4\n");
    printf("            - diff[2][0] = onesRow2 + onesCol0 - zerosRow2 - zerosCol0 = 1 + 1 - 2 - 2 = -2\n");
    printf("            - diff[2][1] = onesRow2 + onesCol1 - zerosRow2 - zerosCol1 = 1 + 1 - 2 - 2 = -2\n");
    printf("            - diff[2][2] = onesRow2 + onesCol2 - zerosRow2 - zerosCol2 = 1 + 3 - 2 - 0 = 2\n");
    {
        vector<vector<int>> grid = {{0,1,1},{1,0,1},{0,0,1}};
        Solution solution;
        auto res = solution.onesMinusZeros(grid);

        printf("res size is %d\n", res.size());
        for (size_t i = 0; i < res.size(); i++)
        {
            for (size_t j = 0; j < res[i].size(); j++)
            {
                printf("%d,", res[i][j]);
            }
            printf("\n");
        }
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: grid = [[1,1,1],[1,1,1]]\n");
    printf("expected result: output = [[5,5,5],[5,5,5]]\n");
    {
        vector<vector<int>> grid = {{1,1,1},{1,1,1}};
        Solution solution;
        auto res = solution.onesMinusZeros(grid);

        printf("res size is %d\n", res.size());
        for (size_t i = 0; i < res.size(); i++)
        {
            for (size_t j = 0; j < res[i].size(); j++)
            {
                printf("%d,", res[i][j]);
            }
            printf("\n");
        }
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
//   4. 使用 [錯誤清單] 視窗，檢視錯誤eee
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
