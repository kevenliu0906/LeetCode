// ConsoleApplication_01_Matrix.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    vector<vector<int>> BFS_update_M(vector<vector<int>> &mat){
        queue<pair<int,int>> proc_num_que;   // store need process element
        int row = mat.size();
        int col = mat[0].size();

        for (size_t i = 0; i < mat.size(); i++)
        {
            for (size_t j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == 0) proc_num_que.push(pair<int,int>(i,j));
                else mat[i][j] = INT_MAX;
            }
        }

        // four direction
        vector<vector<int>> dirs_vec{{-1,0},{0,-1},{1,0},{0,1}};

        // START traversal from zero element
        while (!proc_num_que.empty())
        {
            auto cur_num = proc_num_que.front();
            // printf("cur_num.first:%d, cur_num.second:%d\n", cur_num.first, cur_num.second);
            proc_num_que.pop();

            // use this(replace below) to let performance better
            for (size_t i = 0; i < dirs_vec.size(); i++)
            {
                int x = cur_num.first + dirs_vec[i][0];
                int y = cur_num.second + dirs_vec[i][1];
                // printf(">>> next to cur_num, x:%d, y:%d\n", x, y);

                // these case should NOT update the element value
                // 1. out of range
                // 2. the value of element nearby current element is smaller (not necessary to update)
                if (x < 0 || x >= row || y < 0 || y >= col || mat[x][y] <= mat[cur_num.first][cur_num.second] + 1)
                {
                    continue;
                }
                
                mat[x][y] = mat[cur_num.first][cur_num.second] + 1;
                proc_num_que.push(pair<int,int>(x,y));
            }
            
            // for (auto dirs : dirs_vec)
            // {
            //     int x = cur_num.first + dirs[0];
            //     int y = cur_num.second + dirs[1];
            //     // printf(">>> next to cur_num, x:%d, y:%d\n", x, y);

            //     // these case should not update the element value
            //     // 1. out of range
            //     // 2. the value of element nearby current element is smaller (not necessary to update)
            //     if (x < 0 || x >= row || y < 0 || y >= col || mat[x][y] <= mat[cur_num.first][cur_num.second] + 1)
            //     {
            //         continue;
            //     }
                
            //     mat[x][y] = mat[cur_num.first][cur_num.second] + 1;
            //     zero_num_que.push(pair<int,int>(x,y));
            // }
        }
        
        return mat;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // solution 1 (keven, best understanding, using BFS to solve)
        //            (refer https://www.cnblogs.com/grandyang/p/6602288.html)
        {
            return BFS_update_M(mat);
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - 01 Matrix, Algorithm(Breadth First Search)!\n";
    cout << "https://leetcode.com/problems/01-matrix/" << endl;
    cout << "solution: https://www.cnblogs.com/grandyang/p/6602288.html" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: mat = [[0,0,0],[0,1,0],[0,0,0]]\n");
    printf("expected result: output = [[0,0,0],[0,1,0],[0,0,0]]\n");
    {
        vector<vector<int>> mat{{0,0,0},{0,1,0},{0,0,0}};

        Solution solution;
        auto res = solution.updateMatrix(mat);
        printf("res is >>> \n");
        for (size_t i = 0; i < res.size(); i++)
        {
            for (size_t j = 0; j < res[i].size(); j++)
            {
                printf("%d,", res[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: mat = [[0,0,0],[0,1,0],[1,1,1]]\n");
    printf("expected result: output = [[0,0,0],[0,1,0],[1,2,1]]\n");
    {
        vector<vector<int>> mat{{0,0,0},{0,1,0},{1,1,1}};

        Solution solution;
        auto res = solution.updateMatrix(mat);
        printf("res is >>> \n");
        for (size_t i = 0; i < res.size(); i++)
        {
            for (size_t j = 0; j < res[i].size(); j++)
            {
                printf("%d,", res[i][j]);
            }
            printf("\n");
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
