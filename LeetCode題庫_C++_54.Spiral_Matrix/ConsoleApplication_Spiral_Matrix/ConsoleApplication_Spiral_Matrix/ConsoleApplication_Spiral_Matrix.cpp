// ConsoleApplication_Spiral_Matrix.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    enum {
        enum_row_left_to_right = 1,
        enum_col_top_to_bottom,
        enum_row_right_to_left,
        enum_col_bottom_to_top,
    }traversal_dire;
    
    vector<vector<bool>> check_fg_vec_vec;

    void DFS(vector<int> &path_res, vector<vector<int>> &matrix, int &startPos_x, int &startPos_y, int direction)
    {
        // out of edge
        if (startPos_x < 0 || startPos_x >= matrix.size() || startPos_y < 0 || startPos_y >= matrix[0].size())
        {
            return;
        }

        // already has checked
        if (check_fg_vec_vec[startPos_x][startPos_y])
        {
            return;
        }
        
        if (direction == enum_row_left_to_right)
        {
            path_res.push_back(matrix[startPos_x][startPos_y]);
            check_fg_vec_vec[startPos_x][startPos_y] = true;
            startPos_y++;
            DFS(path_res, matrix, startPos_x, startPos_y, direction);
        }
        else if (direction == enum_col_top_to_bottom)
        {
            // printf("DFC func >>>> enum_col_top_to_bottom case\n");
            if (startPos_x >= matrix.size() - 1)
            {
                startPos_x--;
                return;
            }
            if (check_fg_vec_vec[startPos_x+1][startPos_y])
            {
                startPos_x--;
                return;
            }
            path_res.push_back(matrix[startPos_x][startPos_y]);
            check_fg_vec_vec[startPos_x][startPos_y] = true;
            startPos_x++;
            DFS(path_res, matrix, startPos_x, startPos_y, direction);
        }
        else if (direction == enum_row_right_to_left)
        {
            path_res.push_back(matrix[startPos_x][startPos_y]);
            check_fg_vec_vec[startPos_x][startPos_y] = true;
            startPos_y--;
            DFS(path_res, matrix, startPos_x, startPos_y, direction);
        }
        else if (direction == enum_col_bottom_to_top)
        {
            // printf("DFC func >>>> enum_col_bottom_to_top case, startPos_x:%d\n", startPos_x);
            if (startPos_x == 0)
            {
                return;
            }
            if (check_fg_vec_vec[startPos_x][startPos_y])
            {
                return;
            }
            path_res.push_back(matrix[startPos_x][startPos_y]);
            check_fg_vec_vec[startPos_x][startPos_y] = true;
            startPos_x--;
            DFS(path_res, matrix, startPos_x, startPos_y, direction);
        }
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // solution 1 (keven, using DFS to solve)
        {
            // printf("************ Init check_2D_vec *****************\n");
            check_fg_vec_vec.resize(matrix.size(), vector<bool>(matrix[0].size(), false));
            // for (size_t i = 0; i < check_fg_vec_vec.size(); i++)
            // {
            //     for (size_t j = 0; j < check_fg_vec_vec[i].size(); j++)
            //     {
            //         auto status = check_fg_vec_vec[i][j];
            //         printf("%d(%d),", int(check_fg_vec_vec[i][j]), true);
            //     }
            //     printf("\n");
            // }
            // printf("\n");
            // printf("***********************************************\n");

            vector<int> res;
            int startIdx_x = 0;
            int startIdx_y = 0;

            do{
                static int loopcount = 0;
                loopcount++;
                int Idx_x = startIdx_x;
                int Idx_y = startIdx_y;
                // printf("\n******* loop:%d *******\n\n", loopcount);
                // printf("main(L->R) --> Idx_x:%d, Idx_y:%d\n", Idx_x, Idx_y);


                // left->right
                DFS(res, matrix, Idx_x, Idx_y, enum_row_left_to_right);
                Idx_y--;  // reset

                if (matrix.size() < 2)
                {
                    // ONLY 1 row
                    // already DONE, so break it.
                    break;
                }

                // top->bot
                {
                    Idx_x++;
                    // printf("main(T->B) --> Idx_x:%d, Idx_y:%d\n", Idx_x, Idx_y);
                    DFS(res, matrix, Idx_x, Idx_y, enum_col_top_to_bottom);
                }

                // right->left
                {
                    Idx_x++;
                    // printf("main(R->L) --> Idx_x:%d, Idx_y:%d\n", Idx_x, Idx_y);
                    DFS(res, matrix, Idx_x, Idx_y, enum_row_right_to_left);
                    Idx_y++;  // reset
                }

                // bot->top
                {
                    Idx_x--;
                    // printf("main(B->T) --> Idx_x:%d, Idx_y:%d\n", Idx_x, Idx_y);
                    DFS(res, matrix, Idx_x, Idx_y, enum_col_bottom_to_top);
                }
                
                startIdx_x++;
                startIdx_y++;

                if (matrix[0].size() < 2)
                {
                    // ONLY 1 column
                    // already DONE, so break it.
                    break;
                }
                
                
            }while (!check_fg_vec_vec[startIdx_x][startIdx_y]);
            
            return res;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Spiral Matrix, DataStructure(Array, Matrix)!\n";
    cout << "https://leetcode.com/problems/spiral-matrix/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: matrix = [[1,2,3],[4,5,6],[7,8,9]]\n");
    printf("expected result: output = [1,2,3,6,9,8,7,4,5]\n");
    {
        vector<vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};
        
        Solution solution;
        auto result = solution.spiralOrder(matrix);
        printf("result size:%d\n", result.size());
        for (size_t i = 0; i < result.size(); i++)
        {
            printf("%d,", result[i]);
        }
        printf("\n");
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]\n");
    printf("expected result: output = [1,2,3,4,8,12,11,10,9,5,6,7]\n");
    {
        vector<vector<int>> matrix{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
        
        Solution solution;
        auto result = solution.spiralOrder(matrix);
        printf("result size:%d\n", result.size());
        for (size_t i = 0; i < result.size(); i++)
        {
            printf("%d,", result[i]);
        }
        printf("\n");
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: matrix = [[1,2,3],[4,5,6]]\n");
    printf("expected result: output = [1,2,3,6,5,4]\n");
    {
        vector<vector<int>> matrix{{1,2,3},{4,5,6}};
        
        Solution solution;
        auto result = solution.spiralOrder(matrix);
        printf("result size:%d\n", result.size());
        for (size_t i = 0; i < result.size(); i++)
        {
            printf("%d,", result[i]);
        }
        printf("\n");
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: matrix = [[1,2,3]]\n");
    printf("expected result: output = [1,2,3]\n");
    {
        vector<vector<int>> matrix{{1,2,3}};
        
        Solution solution;
        auto result = solution.spiralOrder(matrix);
        printf("result size:%d\n", result.size());
        for (size_t i = 0; i < result.size(); i++)
        {
            printf("%d,", result[i]);
        }
        printf("\n");
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 5 ****************************\n");
    printf("input: matrix = [[1,2,3,4,5],[6,7,8,9,10],[11,12,13,14,15],[16,17,18,19,20],[21,22,23,24,25],[26,27,28,29,30]]\n");
    printf("expected result: output = [1,2,3,4,5,10,15,20,25,30,29,28,27,26,21,16,11,6,7,8,9,14,19,24,23,22,17,12,13,18]\n");
    {
        vector<vector<int>> matrix{{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25},{26,27,28,29,30}};
        
        Solution solution;
        auto result = solution.spiralOrder(matrix);
        printf("result size:%d\n", result.size());
        for (size_t i = 0; i < result.size(); i++)
        {
            printf("%d,", result[i]);
        }
        printf("\n");
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
