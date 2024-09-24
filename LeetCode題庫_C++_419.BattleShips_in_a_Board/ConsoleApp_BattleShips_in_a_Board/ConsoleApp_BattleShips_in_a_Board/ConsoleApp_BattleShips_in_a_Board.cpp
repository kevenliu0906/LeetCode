// ConsoleApp_BattleShips_in_a_Board.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        // solution 1 (keven, force directly)
        {
            int res = 0;
            for (size_t i = 0; i < board.size(); i++)
            {
                for (size_t j = 0; j < board[i].size(); j++)
                {
                    if (board[i][j] == 'X')
                    {
                        res++;
                        // check if the next element is 'X'

                        //----- check same column
                        auto match_i = i;
                        match_i++;
                        while (match_i < board.size() && board[match_i][j] == 'X')
                        {
                            // on the same column
                            board[match_i][j] = '.';   // clear element value becuase it the same as before
                            match_i++;
                        }
                        
                        //----- check same row
                        auto match_j = j;
                        match_j++;
                        while (match_j < board[i].size() && board[i][match_j] == 'X')
                        {
                            board[i][match_j] = '.';   // clear element value becuase it the same as before
                            match_j++;
                        }
                    }
                    
                }
                
            }
            
            return res;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - BattleShips in a Board, Algorithm(Depth-First Search)!\n";
    cout << "https://leetcode.com/problems/battleships-in-a-board/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: board = [[\"X\",\".\",\".\",\"X\"],[\".\",\".\",\".\",\"X\"],[\".\",\".\",\".\",\"X\"]]\n");
    printf("expected result: output = 2\n");
    {
        vector<vector<char>> board = {{'X','.','.','X'},{'.','.','.','X'},{'.','.','.','X'}};
        
        Solution solution;
        auto res = solution.countBattleships(board);
        printf("res is %d\n", res);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: board = [[\".\"]]\n");
    printf("expected result: output = 0\n");
    {
        vector<vector<char>> board = {{'.'}};
        
        Solution solution;
        auto res = solution.countBattleships(board);
        printf("res is %d\n", res);
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
