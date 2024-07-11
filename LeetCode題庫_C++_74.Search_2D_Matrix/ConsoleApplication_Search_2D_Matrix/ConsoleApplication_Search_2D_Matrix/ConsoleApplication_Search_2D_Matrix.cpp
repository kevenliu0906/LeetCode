// ConsoleApplication_Search_2D_Matrix.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        bool result = false;

        // solution 1 (keven, best)
        {
            vector<int> single_vec;
            for (size_t i = 0; i < matrix.size(); i++)
            {
                for (size_t j = 0; j < matrix[0].size(); j++)
                {
                    single_vec.push_back(matrix[i][j]);
                }
            }
            
            int left = 0;
            int right = single_vec.size() - 1;
            // printf("left:%d, right:%d\n", left, right);
            // for (size_t i = left; i <= right; i++)
            // {
            //     printf("single_vec[%d]=%d\n", i, single_vec[i]);
            // }

            // use binary search to figure out
            while ( left <= right )
            {
                int mid = left + (right - left)/2;
                if( target == single_vec[mid] )
                    return true;
                else if ( target < single_vec[mid] )
                    right = mid - 1;
                else
                    left = mid+ 1;
            }
        }

        return result;
    }
};

int main()
{
    std::cout << "Hello LeetCode - Search 2D Matrix, Algorithm(Binary Search)!\n";
    printf("LeetCode - 74. Search 2D Matrix\n");
    cout << "https://leetcode.com/problems/search-a-2d-matrix" << endl << endl;
    // cout << "solution: https://mocowcow.github.io/leetcode-222-count-complete-tree-nodes/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3\n");
    printf("expected result: output = true\n");
    {
        vector<vector<int>> matrix{{1,3,5,7},{10,11,16,20},{23,30,34,60}};
        int target = 3;

        Solution solution;
        auto result = solution.searchMatrix(matrix, target);
        printf("result:%d, ture:%d, false:%d\n", result, true, false);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13\n");
    printf("expected result: output = false\n");
    {
        vector<vector<int>> matrix{{1,3,5,7},{10,11,16,20},{23,30,34,60}};
        int target = 13;

        Solution solution;
        auto result = solution.searchMatrix(matrix, target);
        printf("result:%d, ture:%d, false:%d\n", result, true, false);
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
