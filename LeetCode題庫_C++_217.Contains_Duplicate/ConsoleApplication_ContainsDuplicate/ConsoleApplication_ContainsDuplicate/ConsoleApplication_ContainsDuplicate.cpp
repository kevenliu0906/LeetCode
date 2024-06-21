// ConsoleApplication_ContainsDuplicate.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_set<int> nums_set(nums.begin(), nums.end());
        
        if(nums_set.size() != nums.size()){
            // represent the element in nums has repeated.
            return true;
        }

        return false;
    }
};

int main()
{
    std::cout << "Hello LeetCode - Contains Duplicate, DataStructure (HASH TABLE)!\n";

    printf("LeetCode - 217. Contains Duplicate\n");
    cout << "https://leetcode.com/problems/contains-duplicate" << endl << endl;
    // cout << "solution: https://blog.techbridge.cc/2017/01/21/simple-hash-table-intro/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: nums = [1, 2, 3, 1]\n");
    printf("expected result: true\n");
    {
        vector<int> nums{ 1, 2, 3, 1 };

        Solution Solution_cs;
        auto Result = Solution_cs.containsDuplicate(nums);
        printf("Result value is %d, true(%d), false(%d)\n", Result, true, false);

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: nums = [1, 2, 3, 4]\n");
    printf("expected result: false\n");
    {
        vector<int> nums{ 1, 2, 3, 4 };

        Solution Solution_cs;
        auto Result = Solution_cs.containsDuplicate(nums);
        printf("Result value is %d, true(%d), false(%d)\n", Result, true, false);

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: nums = [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]\n");
    printf("expected result: true\n");
    {
        vector<int> nums{ 1, 2, 3, 1 };

        Solution Solution_cs;
        auto Result = Solution_cs.containsDuplicate(nums);
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
