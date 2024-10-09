// ConsoleApplication_Game_of_Life.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:

    void check_8_direction(vector<vector<int>> &board, int x, int y, int &sum_0, int &sum_1){
        if (x < 0 || x >= board.size() || y < 0 || y >= board[x].size())
        {
            return;
        }
        
        if (board[x][y] == 0)
        {
            sum_0++;
        }
        
        if (board[x][y] == 1)
        {
            sum_1++;
        }
    }

    void Imple_GOL(vector<vector<int>> &board){
        vector<int> final_vec;
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[i].size(); j++)
            {
                // STEP1: check current cell value
                auto cur_cell = board[i][j];

                // STEP2: calc total sum of cells from eight direction for current cell
                auto total_sum_0 = 0;
                auto total_sum_1 = 0;
                check_8_direction(board, i-1, j-1, total_sum_0, total_sum_1);
                check_8_direction(board, i-1, j, total_sum_0, total_sum_1);
                check_8_direction(board, i-1, j+1, total_sum_0, total_sum_1);
                check_8_direction(board, i, j-1, total_sum_0, total_sum_1);
                check_8_direction(board, i, j+1, total_sum_0, total_sum_1);
                check_8_direction(board, i+1, j-1, total_sum_0, total_sum_1);
                check_8_direction(board, i+1, j, total_sum_0, total_sum_1);
                check_8_direction(board, i+1, j+1, total_sum_0, total_sum_1);

                // STEP3: store the new next-generation value for each cell
                auto next_gen_cur_cell = 0;
                if (cur_cell == 1)
                {
                    if (total_sum_1 != 2 && total_sum_1 != 3)
                    {
                        final_vec.push_back(0);  // lives on to the next generation
                    }else{
                        final_vec.push_back(cur_cell);
                    }
                }
                else if (cur_cell == 0)
                {
                    if (total_sum_1 == 3)
                    {
                        final_vec.push_back(1);  
                    }
                    else{
                        final_vec.push_back(cur_cell);
                    }
                }
                
            }
        }

        // STEP4: substitute current cell from new next-generation value
        int checkIdx = 0;
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[i].size(); j++)
            {
                board[i][j] = final_vec[checkIdx];
                checkIdx++;
            }
            
        }
    }

public:
    void gameOfLife(vector<vector<int>>& board) {
        Imple_GOL(board);
    }
};

int main()
{
    std::cout << "Hello LeetCode - Game of Life, DataStructure(Array)!\n";
    cout << "https://leetcode.com/problems/game-of-life/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]\n");
    printf("expected result: output = [0,0,0],[1,0,1],[0,1,1],[0,1,0]]\n");
    {
        vector<vector<int>> board{ {0,1,0},{0,0,1},{1,1,1},{0,0,0} };
        
        Solution solution;
        printf("------ input(START): board --> \n");
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[i].size(); j++)
            {
                printf("%d,", board[i][j]);
            }
            printf("\n");
        }
        
        solution.gameOfLife(board);
        printf("------ input(End): board --> \n");
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[i].size(); j++)
            {
                printf("%d,", board[i][j]);
            }
            printf("\n");
        }
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: board = [[1,1],[1,0]]\n");
    printf("expected result: output = [[1,1],[1,1]]\n");
    {
        vector<vector<int>> board {{1,1},{1,0}};
        
        Solution solution;
        printf("------ input(START): board --> \n");
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[i].size(); j++)
            {
                printf("%d,", board[i][j]);
            }
            printf("\n");
        }
        
        solution.gameOfLife(board);
        printf("------ input(End): board --> \n");
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[i].size(); j++)
            {
                printf("%d,", board[i][j]);
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
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
