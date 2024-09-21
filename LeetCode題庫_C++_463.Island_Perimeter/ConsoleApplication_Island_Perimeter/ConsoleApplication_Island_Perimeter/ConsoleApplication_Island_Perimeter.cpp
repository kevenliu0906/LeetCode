// ConsoleApplication_Island_Perimeter.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // solution 1 (keven, force directly)
        {
            int res = 0;
            for (size_t i = 0; i < grid.size(); i++)
            {
                for (size_t j = 0; j < grid[i].size(); j++)
                {
                    if (grid[i][j] == 1)
                    {
                        res += 4;   // default add 4 because it's 4 side for each island
                        if ( (j+1 < grid[i].size()) && grid[i][j+1] == 1)
                        {
                            res -= 2;  // sub 2 because two sides are covered.
                        }

                        if ((i+1 < grid.size()) && grid[i+1][j] == 1)
                        {
                            res -= 2;  // sub 2 because two sides are covered.
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
    std::cout << "Hello LeetCode - Island Perimeter, Algorithm(Depth-First Search, Breadth-First Search, Array)!\n";

    cout << "https://leetcode.com/problems/island-perimeter/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]\n");
    printf("expected result: output = 16\n");
    {
        vector<vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
        
        Solution solution;
        auto res = solution.islandPerimeter(grid);
        printf("res is %d\n", res);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: grid = [[1]]\n");
    printf("expected result: output = 4\n");
    {
        vector<vector<int>> grid = {{1}};
        
        Solution solution;
        auto res = solution.islandPerimeter(grid);
        printf("res is %d\n", res);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: grid = [[1,0]]\n");
    printf("expected result: output = 4\n");
    {
        vector<vector<int>> grid = {{1,0}};
        
        Solution solution;
        auto res = solution.islandPerimeter(grid);
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
