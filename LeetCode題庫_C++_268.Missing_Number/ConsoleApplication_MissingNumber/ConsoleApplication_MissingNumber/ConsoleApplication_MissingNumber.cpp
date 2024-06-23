// ConsoleApplication_MissingNumber.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;


class Solution{
public:
    int missingnumber(vector<int> &nums){

        sort(nums.begin(), nums.end());
        // // for debug the element after sorting
        // for (size_t i = 0; i < nums.size(); i++)
        // {
        //     printf("<kd> after sort: nums[%d]=%d\n", i, nums[i]);
        // }

        // check the left side boundary exist or not
        if( nums[0] != 0 )
            return 0;
        // check the right side boundary exist or not
        if( nums[nums.size() - 1] != nums.size() )
            return nums.size();

        // because of nums[0] is 0, so check if nums[1] is 1 in first iteration
        for (size_t i = 0; i < nums.size() - 1; i++)
        {
            if( abs(nums[i] - nums[i+1]) > 1 )
                return nums[i + 1] - 1;
        }

        return -1;
    }
};


int main()
{
    std::cout << "Hello LeetCode - Missing Number, DataStructure (HASH TABLE)!\n";

    printf("LeetCode - 268. Missing Number\n");
    cout << "https://leetcode.com/problems/missing-number" << endl << endl;
    cout << "solution: https://medium.com/@zero.ling/c-sort-a-map-by-value-601a60ec0e01" << endl;
    // cout << "solution: https://blog.techbridge.cc/2017/01/21/simple-hash-table-intro/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: nums={3, 0, 1}\n");
    printf("expected result: 2\n");
    {
        vector<int> nums{3, 0, 1};

        Solution Solution_cs;
        auto Result = Solution_cs.missingnumber(nums);
        printf("Result value is %d, true(%d), false(%d)\n", Result, true, false);

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: nums={0, 1}\n");
    printf("expected result: 2\n");
    {
        vector<int> nums{0, 1};

        Solution Solution_cs;
        auto Result = Solution_cs.missingnumber(nums);
        printf("Result value is %d, true(%d), false(%d)\n", Result, true, false);

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: nums={9, 6, 4, 2, 3, 5, 7, 0, 1}\n");
    printf("expected result: 8  \n");
    {
        vector<int> nums{9, 6, 4, 2, 3, 5, 7, 0, 1};

        Solution Solution_cs;
        auto Result = Solution_cs.missingnumber(nums);
        printf("Result value is %d, true(%d), false(%d)\n", Result, true, false);

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
