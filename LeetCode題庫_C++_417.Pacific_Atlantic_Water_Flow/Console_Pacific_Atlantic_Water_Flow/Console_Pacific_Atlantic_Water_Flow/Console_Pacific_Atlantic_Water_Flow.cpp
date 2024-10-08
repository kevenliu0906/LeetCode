// Console_Pacific_Atlantic_Water_Flow.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<bool>> pacific_fg_vec_vec;
    vector<vector<bool>> atlantic_fg_vec_vec;

    void DFS_Others(vector<vector<int>> &heights, vector<vector<bool>> &target, int cur_h, int x, int y){
        // over edge 
        if (x < 0 || x >= heights.size() || y < 0 || y >= heights[0].size())
        {
            return;
        }
        
        // height is unders current
        if (heights[x][y] < cur_h)
        {
            return;
        }

        // has checked
        if (target[x][y])
        {
            return;
        }

        target[x][y] = true;
        
        DFS_Others(heights, target, heights[x][y], x + 1, y);
        DFS_Others(heights, target, heights[x][y], x - 1, y);
        DFS_Others(heights, target, heights[x][y], x, y + 1);
        DFS_Others(heights, target, heights[x][y], x, y - 1);
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // solution 0 (keven, refer others https://www.cnblogs.com/grandyang/p/5962508.html)
        //             using DFS to check from edge to central, because check from edge, so the param in cur_h is "INT_MIN" in the beginning 
        {
            vector<vector<int>> res;
            int m = heights.size();
            int n = heights[0].size();

            pacific_fg_vec_vec.resize(m, vector<bool>(n, false));
            atlantic_fg_vec_vec.resize(m, vector<bool>(n ,false));
             
            for (int i = 0; i < n; i++)
            {
                // remark the region from edge to central for pacific 
                DFS_Others(heights, pacific_fg_vec_vec, INT_MIN, 0, i);     // top-edge
                // remark the region from edge to central for atlantic
                DFS_Others(heights, atlantic_fg_vec_vec, INT_MIN, m-1, i);  // bottom-edge
            }

            for (int j = 0; j < m; j++)
            {
                // remark the region from edge to central for pacific 
                DFS_Others(heights, pacific_fg_vec_vec, INT_MIN, j, 0);     // left-edge
                // remark the region from edge to central for atlantic
                DFS_Others(heights, atlantic_fg_vec_vec, INT_MIN, j, n-1);  // right-edge
            }
            
            // check if status if true in both rivers
            for (int i = 0; i < heights.size(); i++)
            {
                for (int j = 0; j < heights[0].size(); j++)
                {
                    if (pacific_fg_vec_vec[i][j] && atlantic_fg_vec_vec[i][j])
                    {
                        res.push_back(vector<int>{i,j});
                    }
                }
            }

            return res;
        }
    
    }
};

int main()
{
    std::cout << "Hello LeetCode - Pacific Atlantic Water Flow, Algorithm(Depth-First Search)!\n";
    cout << "https://leetcode.com/problems/pacific-atlantic-water-flow/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]\n");
    printf("expected result: output = [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]\n");
    {
        vector<vector<int>> heights{{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
        
        Solution solution;
        auto result = solution.pacificAtlantic(heights);
        printf("result size:%d\n", result.size());
        for (size_t i = 0; i < result.size(); i++)
        {
            printf("[%d,%d],", result[i][0], result[i][1]);
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
