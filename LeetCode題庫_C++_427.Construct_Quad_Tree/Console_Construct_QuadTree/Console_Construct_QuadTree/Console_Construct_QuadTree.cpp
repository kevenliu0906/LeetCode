// Console_Construct_QuadTree.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;


// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
private:
    Node *QuadTree(vector<vector<int>> &grid, int x, int y, int len){
        if (len == 0)
        {
            return NULL;
        }
        
        bool allZeroes = true;
        bool allOnes = true;
        Node *res = NULL;
        for (int i = x; i < x + len; ++i)
        {
            for (int j = y; j < y + len; ++j)
            {
                if (grid[i][j] == 1){
                    allZeroes = false;
                }else{
                    allOnes = false;
                }
            }
        }

        if (allZeroes || allOnes){
            res = new Node(grid[x][y], true, NULL, NULL, NULL, NULL);
        }else{
            res = new Node(true, false,
                            QuadTree(grid, x,         y,         len/2),       // topLeft
                            QuadTree(grid, x,         y + len/2, len/2),       // topRight
                            QuadTree(grid, x + len/2, y,         len/2),       // botLeft
                            QuadTree(grid, x + len/2, y + len/2, len/2));      // botRight
        }
        
        return res;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        // solution 1 (reference others)
        {
            // (https://zxi.mytechroad.com/blog/geometry/leetcode-427-construct-quad-tree/)
            // (https://cdn.acwing.com/solution/content/206879//)
            return (QuadTree(grid, 0, 0, grid.size()));
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Construct Quad Tree, Algorithm(Divide and Conquer)!\n";
    cout << "https://leetcode.com/problems/construct-quad-tree/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: grid = [[0,1],[1,0]]\n");
    printf("expected result: output = [[0,1],[1,0],[1,1],[1,1],[1,0]]\n");
    {
        vector<vector<int>> grid{{0,1},{1,0}};
        
        Solution solution;

        auto res = solution.construct(grid);
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
