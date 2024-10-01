// ConsoleApplication_Number_of_Islands.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void DFS_all_elements(vector<vector<char>> &grid, int x, int y)
    {
        if (x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y] != '1')
        {
            return;
        }

        grid[x][y] = '0';  // clear the element when has visited it
        DFS_all_elements(grid, x - 1, y);
        DFS_all_elements(grid, x + 1, y);
        DFS_all_elements(grid, x, y - 1);
        DFS_all_elements(grid, x, y + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        // solution 0 (keven, reference others https://medium.com/@aien1020210305/leetcode-%E7%AD%86%E8%A8%98-200-number-of-islands-f4284b977b45)
        {
            int res = 0;
            for (int i = 0; i < grid.size(); i++)
            {
                for (int j = 0; j < grid[i].size(); j++)
                {
                    if (grid[i][j] == '1')
                    {
                        DFS_all_elements(grid, i, j);
                        res++;
                    }
                    
                }
                
            }
            return res;
        }
        // solution 1 (keven, using hash table to solve, has bug in testcase6)
        {
            vector<int> last_row_land_idx;   // record the land index appear in last row
            vector<vector<int>> last_row_land_idx_vec;
            int res = 0;
            for (int i = 0; i < grid.size(); i++)
            {
                vector<int> cur_row_land_idx;
                vector<vector<int>> cur_row_land_idx_vec;
                for (int j = 0; j < grid[i].size(); j++){
                    if (grid[i][j] == '1'){
                        // island case
                        cur_row_land_idx.push_back(j);                        
                    }else{
                        if (cur_row_land_idx.size()){
                            cur_row_land_idx_vec.push_back(cur_row_land_idx);
                            cur_row_land_idx.clear();
                        }
                    }
                }
                if (cur_row_land_idx.size()){
                    cur_row_land_idx_vec.push_back(cur_row_land_idx);
                    cur_row_land_idx.clear();
                }

                printf("********** i:%d ***********\n", i);
                if (last_row_land_idx_vec.size() == 0)
                {
                    last_row_land_idx_vec.swap(cur_row_land_idx_vec);
                    res += last_row_land_idx_vec.size();
                    printf("row(%d) >>> res:%d\n", i, res);
                }
                else
                {
                    for (int j = 0; j < cur_row_land_idx_vec.size(); j++)
                    {
                        auto cur_row_land_idx = cur_row_land_idx_vec[j];
                        bool alreadyExist = false;
                        
                        for (int k = 0; k < cur_row_land_idx.size(); k++)
                        {
                            auto cur_row_land = cur_row_land_idx[k];
                            printf("row(%d) >>> cur_row_land:%d\n", i, cur_row_land);

                            // compare cur_land_idx with last_land_idx
                            for (int z = 0; z < last_row_land_idx_vec.size(); z++)
                            {
                                auto last_row_land_base = last_row_land_idx_vec[z];
                                unordered_set<int> last_row_land_base_set(last_row_land_base.begin(), last_row_land_base.end());
                                if (last_row_land_base_set.find(cur_row_land) != last_row_land_base_set.end())
                                {
                                    printf("FOUND IT!! break\n");
                                    alreadyExist = true;
                                    break;
                                }
                                
                            }
                            
                            if (alreadyExist){
                                break;
                            }
                        }
                        
                        if (!alreadyExist){
                            res++;
                        }
                        
                    }

                    last_row_land_idx_vec.swap(cur_row_land_idx_vec);
                    
                    // for (int j = 0; j < last_row_land_idx_vec.size(); j++)
                    // {
                    //     auto last_row_land_base = last_row_land_idx_vec[j];
                    //     unordered_set<int> last_row_land_base_set(last_row_land_base.begin(), last_row_land_base.end());
                    // }
                    
                    // unordered_set<int> last_row_land_set(last_row_land.begin(), last_row_land.end());
                    // int last_row_idx = -2;
                    // for (int k = 0; k < cur_row_land.size(); k++){
                    //     // printf("cur_row_land[%d]:%d\n", k, cur_row_land[k]);
                    //     if (last_row_land_set.find(cur_row_land[k]) == last_row_land_set.end())
                    //     {
                    //         if (cur_row_land[k] - last_row_idx > 1)
                    //         {
                    //             res++;
                    //         }
                    //         // printf("res(%d)\n", res);
                    //     }
                    //     last_row_idx = cur_row_land[k];
                    // }

                    // last_row_land.swap(cur_row_land);
                }
            }
            
            return res;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Number of Islands, Algorithm(Depth-First Search, Breadth-First Search)!\n";
    cout << "https://leetcode.com/problems/number-of-islands/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: grid = [[\"1\",\"1\",\"1\",\"1\",\"0\"],\n");
    printf("               [\"1\",\"1\",\"0\",\"1\",\"0\"],\n");
    printf("               [\"1\",\"1\",\"0\",\"0\",\"0\"],\n");
    printf("               [\"0\",\"0\",\"0\",\"0\",\"0\"]]\n");
    printf("expected result: output = 1\n");
    {
        vector<vector<char>> grid{{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
        
        Solution solution;
        auto res = solution.numIslands(grid);
        printf("res is %d\n", res);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: grid = [[\"1\",\"1\",\"0\",\"0\",\"0\"],\n");
    printf("               [\"1\",\"1\",\"0\",\"0\",\"0\"],\n");
    printf("               [\"0\",\"0\",\"1\",\"0\",\"0\"],\n");
    printf("               [\"0\",\"0\",\"0\",\"1\",\"1\"]]\n");
    printf("expected result: output = 3\n");
    {
        vector<vector<char>> grid{{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
        
        Solution solution;
        auto res = solution.numIslands(grid);
        printf("res is %d\n", res);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: grid = [[\"1\",\"0\",\"1\",\"0\",\"1\"],\n");
    printf("               [\"0\",\"1\",\"0\",\"1\",\"0\"],\n");
    printf("               [\"1\",\"0\",\"1\",\"0\",\"1\"],\n");
    printf("               [\"0\",\"1\",\"0\",\"1\",\"0\"]]\n");
    printf("expected result: output = 10\n");
    {
        vector<vector<char>> grid{{'1','0','1','0','1'},{'0','1','0','1','0'},{'1','0','1','0','1'},{'0','1','0','1','0'}};
        
        Solution solution;
        auto res = solution.numIslands(grid);
        printf("res is %d\n", res);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: grid = [[\"1\",\"1\",\"1\"],\n");
    printf("               [\"0\",\"1\",\"0\"],\n");
    printf("               [\"1\",\"1\",\"1\"],\n");
    printf("expected result: output = 1\n");
    {
        vector<vector<char>> grid{{'1','1','1'},{'0','1','0'},{'1','1','1'}};
        
        Solution solution;
        auto res = solution.numIslands(grid);
        printf("res is %d\n", res);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 5 ****************************\n");
    printf("input: grid = [[\"1\",\"0\",\"0\"],\n");
    printf("               [\"0\",\"0\",\"0\"],\n");
    printf("               [\"0\",\"0\",\"1\"],\n");
    printf("expected result: output = 2\n");
    {
        vector<vector<char>> grid{{'1','0','0'},{'0','0','0'},{'0','0','1'}};
        
        Solution solution;
        auto res = solution.numIslands(grid);
        printf("res is %d\n", res);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 6 ****************************\n");
    printf("input: grid = [[\"1\",\"0\",\"1\",\"1\",\"1\"],\n");
    printf("               [\"1\",\"0\",\"1\",\"0\",\"1\"],\n");
    printf("               [\"1\",\"1\",\"1\",\"0\",\"1\"],\n");
    printf("expected result: output = 1\n");
    {
        vector<vector<char>> grid{{'1','0','1','1','1'},{'1','0','1','0','1'},{'1','1','1','0','1'}};
        
        Solution solution;
        auto res = solution.numIslands(grid);
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
