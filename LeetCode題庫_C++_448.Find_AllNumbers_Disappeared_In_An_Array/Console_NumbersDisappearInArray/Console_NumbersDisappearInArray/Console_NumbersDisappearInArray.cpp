// Console_NumbersDisappearInArray.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> result;
        int nums_size = nums.size();
        
        // solution 2 (best)
        {
            vector<int> nums_count_vec(nums_size + 1, 0);  
            for (size_t i = 0; i < nums_size; i++)
            {
                nums_count_vec[nums[i]]++;     // record each counts of element in nums
            }

            for (size_t i = 1; i < nums_count_vec.size(); i++)
            {
                if( nums_count_vec[i] == 0 )   // judge if the count of element array is EMPTY or not
                    result.push_back(i);
            }
        }
        

        // // solution 1 (keven)
        // {
        //     set<int> nums_set{nums.begin(), nums.end()};
        //     for (int i = 1; i <= nums_size; i++)
        //     {
        //         if( nums_set.find( i ) == nums_set.end() ){
        //             result.push_back(i);
        //         }
        //     }
        // }

        return (result);
    }
};


int main()
{
    std::cout << "Hello LeetCode - Find All Numbers disappeared in an array!\n";

    printf("LeetCode - 448. Find All Numbers disappeared in an array\n");
    cout << "https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array" << endl << endl;
    // cout << "solution: https://medium.com/@zero.ling/c-sort-a-map-by-value-601a60ec0e01" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: nums = [4, 3, 2, 7, 8, 2, 3, 1]\n");
    printf("expected result: [5, 6]\n");
    {
        vector<int> nums = { 4, 3, 2, 7, 8, 2, 3, 1 };

        Solution Solution_cs;
        auto Result = Solution_cs.findDisappearedNumbers(nums);
        printf("Result value size is %d, true=%d, false=%d\n", Result.size(), true, false);
        for (size_t i = 0; i < Result.size(); i++)
        {
            printf("Result[%d]=%d\n", i, Result[i]);
        }
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: nums = [1, 1]\n");
    printf("expected result: [2]\n");
    {
        vector<int> nums = { 1, 1 };

        Solution Solution_cs;
        auto Result = Solution_cs.findDisappearedNumbers(nums);
        printf("Result value size is %d, true=%d, false=%d\n", Result.size(), true, false);
        for (size_t i = 0; i < Result.size(); i++)
        {
            printf("Result[%d]=%d\n", i, Result[i]);
        }

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
