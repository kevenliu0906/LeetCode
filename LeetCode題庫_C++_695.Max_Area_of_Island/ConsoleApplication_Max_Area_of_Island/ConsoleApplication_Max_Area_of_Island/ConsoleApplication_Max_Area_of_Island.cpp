// ConsoleApplication_Max_Area_of_Island.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int maxArea = 0;
    int curArea = 0;
    void DFS_run(vector<vector<int>> &grid, int x, int y){

        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[x].size())
        {
            return;
        }
        
        if (grid[x][y] != 1)
        {
            return;
        }
        
        grid[x][y] = 0;
        curArea++;

        DFS_run(grid, x-1, y);
        DFS_run(grid, x+1, y);
        DFS_run(grid, x, y-1);
        DFS_run(grid, x, y+1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // solution 0 (keven, using DFS to solve it)
        {
            for (size_t i = 0; i < grid.size(); i++)
            {
                for (size_t j = 0; j < grid[i].size(); j++)
                {
                    if (grid[i][j] == 1)
                    {
                        curArea = 0;  // reset current area value
                        DFS_run(grid, i, j);
                        // printf("i:%d, j:%d, curArea:%d\n", i, j, curArea);
                        maxArea = max(curArea, maxArea);
                        // printf("maxArea:%d\n", maxArea);
                    }
                    
                }
                
            }
            
            return maxArea;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Max Area of Island, Algorithm(Depth-First Search, Breadth-First Search)!\n";
    cout << "https://leetcode.com/problems/max-area-of-island" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0]\n");
    printf("               [0,0,0,0,0,0,0,1,1,1,0,0,0]\n");
    printf("               [0,1,1,0,1,0,0,0,0,0,0,0,0]\n");
    printf("               [0,1,0,0,1,1,0,0,1,0,1,0,0]\n");
    printf("               [0,1,0,0,1,1,0,0,1,1,1,0,0]\n");
    printf("               [0,0,0,0,0,0,0,0,0,0,1,0,0]\n");
    printf("               [0,0,0,0,0,0,0,1,1,1,0,0,0]\n");
    printf("               [0,0,0,0,0,0,0,1,1,0,0,0,0]]\n");
    printf("expected result: output = 6\n");
    {
        vector<vector<int>> grid{{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
        
        Solution solution;
        auto result = solution.maxAreaOfIsland(grid);
        printf("result:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: grid = [[0,0,0,0,0,0,0,0]]\n");
    printf("expected result: output = 0\n");
    {
        vector<vector<int>> grid{{0,0,0,0,0,0,0,0}};
        
        Solution solution;
        auto result = solution.maxAreaOfIsland(grid);
        printf("result:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0]\n");
    printf("               [0,0,0,0,0,0,1,1,1,1,1,0,0]\n");
    printf("               [0,1,1,0,1,0,0,1,0,1,0,0,0]\n");
    printf("               [0,1,0,0,1,1,0,0,1,0,1,0,0]\n");
    printf("               [0,1,0,0,1,1,0,0,1,1,1,0,0]\n");
    printf("               [0,0,0,0,0,0,0,0,0,0,1,0,0]\n");
    printf("               [0,0,0,0,0,0,0,1,1,1,0,0,0]\n");
    printf("               [0,0,0,0,0,0,0,1,1,0,0,0,0]]\n");
    printf("expected result: output = 8\n");
    {
        vector<vector<int>> grid{{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,1,1,1,1,1,0,0},{0,1,1,0,1,0,0,1,0,1,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
        
        Solution solution;
        auto result = solution.maxAreaOfIsland(grid);
        printf("result:%d\n", result);
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
