// ConsoleApplication_Surround_Resgions.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

void dbg_2D_vec(vector<vector<char>> &arr_2D){
    printf("**************** dbg_2D_vec ***********************\n");
    for (size_t i = 0; i < arr_2D.size(); i++)
    {
        for (size_t j = 0; j < arr_2D[i].size(); j++)
        {
            printf("%c,", arr_2D[i][j]);
        }
        printf("\n");
    }
    
}


class Solution {
private:
    void DFS_restore(vector<vector<char>> &board, int x, int y){
        if ( x < 0 || x >= board.size() || y < 0 || y >= board[x].size() )  // the cell is outside the 2D-array
        {
            return;
        }
        
        if ( board[x][y] != 'E' )      // process the cell is 'E'
        {
            return ;
        }

        board[x][y] = 'O';             // restore the cell from 'E' to 'O' in the edge    

        DFS_restore(board, x-1, y);
        DFS_restore(board, x+1, y);
        DFS_restore(board, x, y-1);
        DFS_restore(board, x, y+1);
    }

    void DFS_run(vector<vector<char>> &board, int x, int y, char origin_symb, char replace_symb){
        
        if ( x < 0 || x >= board.size() || y < 0 || y >= board[x].size() )  // the cell is outside the 2D-array
        {
            return;
        }
        
        if (board_proc_status[x][y])   // already has processed
        {
            return;
        }

        if (board[x][y] != origin_symb)
        {
            return;
        }

        board[x][y] = replace_symb;
        board_proc_status[x][y] = true;
        
        DFS_run(board, x-1, y, origin_symb, replace_symb);
        DFS_run(board, x+1, y, origin_symb, replace_symb);
        DFS_run(board, x, y-1, origin_symb, replace_symb);
        DFS_run(board, x, y+1, origin_symb, replace_symb);
    }

public:
    vector<vector<bool>> board_proc_status;
    multimap<int,int> match_cell_row_col_multimap;   // record match cells for current run, key: row_idx, value: col_idx
    multimap<int,int> match_cell_col_row_multimap;   // record match cells for current run, key: col_idx, value: row_idx

    void DFS(vector<vector<char>> &board, int x, int y)
    {
        if ( x < 0 || x >= board.size() || y < 0 || y >= board[x].size() || board[x][y] == 'X' )
        {
            return;
        }

        if (board_proc_status[x][y])
        {
            return;
        }
        
        board_proc_status[x][y] = true;  // mark current cell has checked.
        match_cell_row_col_multimap.insert(pair<int,int>(x,y));
        match_cell_col_row_multimap.insert(pair<int,int>(y,x));

        DFS(board, x-1, y);
        DFS(board, x+1, y);
        DFS(board, x, y-1);
        DFS(board, x, y+1);
    }

    void solve(vector<vector<char>>& board) {
        // solution 0 (keven, using DFS to solve, reference others https://bclin.tw/2022/06/14/leetcode-130/ )
        {
            int board_row = board.size();
            int board_col = board[0].size();
            board_proc_status.resize(board_row);
            for (size_t i = 0; i < board_proc_status.size(); i++)
            {
                board_proc_status[i].resize(board_col, false);
            }

            
            // STEP1: replace edge cell from 'O' to 'E' (this easy to know which 'O' cell is connected to edge)
            for (size_t i = 0; i < board.size(); i++)
            {
                for (size_t j = 0; j < board[i].size(); j++)
                {
                    if (board[i][j] == 'O' && (i == 0 || i == board.size() - 1 || j == 0 || j == board[i].size() - 1))
                    {
                        // printf(">>>>> cur cell board[%d][%d]=%c\n", i, j, board[i][j]);
                        DFS_run(board, i, j, 'O', 'E');
                    }
                    
                }
                
            }
            // STEP2: replace others cell from 'O' to 'X'
            for (size_t i = 0; i < board.size(); i++)
            {
                for (size_t j = 0; j < board[i].size(); j++)
                {
                    if (board[i][j] == 'O')
                    {
                        board[i][j] = 'X';
                        // DFS_run(board, i, j, 'O', 'X');
                    }
                    else if (board[i][j] == 'E')
                    {
                        board[i][j] = 'O';
                    }
                    
                }
            }

            return;
        }

        // solution 1 (keven, using DFS to solve)
        {
            int board_row = board.size();
            int board_col = board[0].size();
            board_proc_status.resize(board_row);
            for (size_t i = 0; i < board_proc_status.size(); i++)
            {
                board_proc_status[i].resize(board_col, false);
            }
            // printf("board_proc_status, row:%d, col:%d\n", board_proc_status.size(), board_proc_status[0].size());

            for (size_t i = 0; i < board.size(); i++)
            {
                for (size_t j = 0; j < board[i].size(); j++)
                {
                    if (board[i][j] == 'O')
                    {
                        // printf("i:%d, j:%d >>>>>> \n", i, j);
                        match_cell_row_col_multimap.clear();
                        match_cell_col_row_multimap.clear();
                        DFS(board, i, j);
                        // for (auto match_cell_row_col_multimap_single : match_cell_row_col_multimap)
                        // {
                        //     printf("(%d,%d),", match_cell_row_col_multimap_single.first, match_cell_row_col_multimap_single.second);
                        // }
                        // printf("\n");

                        if (match_cell_row_col_multimap.size() && match_cell_col_row_multimap.size())
                        {
                            if (match_cell_row_col_multimap.begin()->first != 0 && match_cell_row_col_multimap.rbegin()->first != (board_row - 1) &&  // for row is not in the edge
                                match_cell_col_row_multimap.begin()->first != 0 && match_cell_col_row_multimap.rbegin()->first != (board_col - 1) )   // for col is not in the edge
                            {
                                // change board cell value HERE!!!!
                                for (auto match_cell_row_col_multimap_single : match_cell_row_col_multimap)
                                {
                                    board[match_cell_row_col_multimap_single.first][match_cell_row_col_multimap_single.second] = 'X';
                                }
                            }
                        }
                    }
                }
            }
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Surrounded regions, Algorithm(Depth-First Search)!\n";
    cout << "https://leetcode.com/problems/surrounded-regions/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: board = [[\"X\",\"X\",\"X\",\"X\"]\n");
    printf("                [\"X\",\"O\",\"O\",\"X\"]\n");
    printf("                [\"X\",\"X\",\"O\",\"X\"]\n");
    printf("                [\"X\",\"O\",\"X\",\"X\"]]\n");
    printf("expected result: output = [[\"X\",\"X\",\"X\",\"X\"]\n");
    printf("                           [\"X\",\"X\",\"X\",\"X\"]\n");
    printf("                           [\"X\",\"X\",\"X\",\"X\"]\n");
    printf("                           [\"X\",\"O\",\"X\",\"X\"]]\n");
    {
        vector<vector<char>> board{{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
        
        Solution solution;
        
        printf("original board >>>>> \n");
        dbg_2D_vec(board);
        solution.solve(board);

        printf("\nafter solve board >>>>> \n");
        dbg_2D_vec(board);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: board = [[\"X\",\"X\",\"X\",\"O\"]\n");
    printf("                [\"X\",\"O\",\"O\",\"X\"]\n");
    printf("                [\"X\",\"X\",\"O\",\"X\"]\n");
    printf("                [\"X\",\"O\",\"X\",\"O\"]]\n");
    printf("expected result: output = [[\"X\",\"X\",\"X\",\"O\"]\n");
    printf("                           [\"X\",\"X\",\"X\",\"X\"]\n");
    printf("                           [\"X\",\"X\",\"X\",\"X\"]\n");
    printf("                           [\"X\",\"O\",\"X\",\"O\"]]\n");
    {
        vector<vector<char>> board{{'X','X','X','O'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','O'}};
        
        Solution solution;
        
        printf("original board >>>>> \n");
        dbg_2D_vec(board);
        solution.solve(board);

        printf("\nafter solve board >>>>> \n");
        dbg_2D_vec(board);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: board = [[\"O\",\"X\",\"O\",\"X\"]\n");
    printf("                [\"X\",\"O\",\"O\",\"X\"]\n");
    printf("                [\"X\",\"X\",\"O\",\"X\"]\n");
    printf("                [\"X\",\"O\",\"X\",\"O\"]]\n");
    printf("expected result: output = [[\"O\",\"X\",\"O\",\"X\"]\n");
    printf("                           [\"X\",\"O\",\"O\",\"X\"]\n");
    printf("                           [\"X\",\"X\",\"O\",\"X\"]\n");
    printf("                           [\"X\",\"O\",\"X\",\"O\"]]\n");
    {
        vector<vector<char>> board{{'O','X','O','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','O'}};
        
        Solution solution;
        
        printf("original board >>>>> \n");
        dbg_2D_vec(board);
        solution.solve(board);

        printf("\nafter solve board >>>>> \n");
        dbg_2D_vec(board);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: board = [[\"X\"]]\n");
    printf("expected result: output = [[\"X\"]]\n");
    {
        vector<vector<char>> board{{'X'}};
        
        Solution solution;
        
        printf("original board >>>>> \n");
        dbg_2D_vec(board);
        solution.solve(board);

        printf("\nafter solve board >>>>> \n");
        dbg_2D_vec(board);
        
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
