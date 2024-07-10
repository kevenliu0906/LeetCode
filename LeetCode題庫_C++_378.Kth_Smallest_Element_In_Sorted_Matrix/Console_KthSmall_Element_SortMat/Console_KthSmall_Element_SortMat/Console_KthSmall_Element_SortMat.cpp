// Console_KthSmall_Element_SortMat.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        // solution 1 (keven, best)
        {   
            vector<int> test(matrix.size() * matrix[0].size(), 0);
            // for (size_t i = 0; i < test.size(); i++)
            // {
            //     printf("(initial) test[%d]=%d\n", i, test[i]);
            // }

            
            for (size_t i = 0; i < matrix.size(); i++)
            {
                for (size_t j = 0; j < matrix[i].size(); j++)
                {
                    int index = matrix[i].size() * i + j;
                    // printf("index:%d, matrix[%d][%d]=%d\n", index, i, j, matrix[i][j]);
                    test[ index ] = matrix[i][j];
                    // printf("test[%d]=%d\n", index, test[index]);
                }
            }
            
            sort(test.begin(), test.end());

            // for (size_t i = 0; i < test.size(); i++)
            // {
            //     printf("(after sort) test[%d]=%d\n", i, test[i]);
            // }

            // printf("k:%d\n", k);
            if( (k - 1) >= 0 && (k - 1) < test.size())
                return test[k-1];
            
            return 0;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Kth Smallest element in Sorted Matrix, Algorithm( Binary Search, Array )\n";
    printf("LeetCode - 378. Kth Smallest element in Sorted Matrix\n");
    cout << "https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/" << endl << endl;
    // cout << "solution: https://mocowcow.github.io/leetcode-222-count-complete-tree-nodes/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8\n");
    printf("expected result: output = 13\n");
    {
        vector<vector<int>> matrix{{1,5,9},{10,11,13},{12,13,15}};
        int k = 8;
        Solution solution;
        auto result = solution.kthSmallest(matrix, k);
        printf("Result:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: matrix = [[-5], k = 1\n");
    printf("expected result: output = -5\n");
    {
        vector<vector<int>> matrix{{-5}};
        int k = 1;
        Solution solution;
        auto result = solution.kthSmallest(matrix, k);
        printf("Result:%d\n", result);
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
