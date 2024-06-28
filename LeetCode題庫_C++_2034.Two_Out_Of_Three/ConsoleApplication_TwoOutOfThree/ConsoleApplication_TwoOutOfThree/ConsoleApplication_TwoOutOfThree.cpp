// ConsoleApplication_TwoOutOfThree.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {

        vector<int> result;

        // solution 1 (keven, best)
        set<int> totalnums_set;   // gather all nums within s1, s2, s3

        set<int> nums1_set(nums1.begin(), nums1.end());
        set<int> nums2_set(nums2.begin(), nums2.end());
        set<int> nums3_set(nums3.begin(), nums3.end());

        totalnums_set.insert(nums1.begin(), nums1.end());
        totalnums_set.insert(nums2.begin(), nums2.end());
        totalnums_set.insert(nums3.begin(), nums3.end());

        // // debug gather all nums from s1, s2, s3
        // printf("total_nums_set size:%d\n", totalnums_set.size());
        // for (auto totalnums_set_each : totalnums_set)
        // {
        //     printf("totalnums_set_each:%d\n", totalnums_set_each);
        // }

        for (auto totalnums_set_each : totalnums_set)
        {
            bool nums1_set_find = false;
            bool nums2_set_find = false;
            bool nums3_set_find = false;

            if( nums1_set.count(totalnums_set_each) )
                nums1_set_find = true;
            if( nums2_set.count(totalnums_set_each) )
                nums2_set_find = true;
            if( nums3_set.count(totalnums_set_each) )
                nums3_set_find = true;

            if( nums1_set_find && nums2_set_find )
                result.push_back(totalnums_set_each);
            else if( nums1_set_find && nums3_set_find )
                result.push_back(totalnums_set_each);
            else if( nums2_set_find && nums3_set_find )
                result.push_back(totalnums_set_each);
        }

        return result;
    }
};

int main()
{
    std::cout << "Hello LeetCode - Two Out Of Three, DataStructure (HASH TABLE, Array)!\n";

    printf("LeetCode - 496. Next Greater Element I\n");
    cout << "https://leetcode.com/problems/next-greater-element-i/" << endl << endl;
    // cout << "solution: https://medium.com/@zero.ling/c-sort-a-map-by-value-601a60ec0e01" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: nums1 = [1, 1, 3, 2], nums2 = [2, 3], nums3 = [3]\n");
    printf("expected result: [3, 2]\n");
    {
        vector<int> nums1 = { 1, 1, 3, 2 };
        vector<int> nums2 = { 2, 3 };
        vector<int> nums3 = { 3 };

        Solution Solution_cs;
        auto Result = Solution_cs.twoOutOfThree(nums1, nums2, nums3);
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
    printf("input: nums1 = [3, 1], nums2 = [2, 3], nums3 = [1, 2]\n");
    printf("expected result: [2, 3, 1]\n");
    {
        vector<int> nums1 = { 3, 1 };
        vector<int> nums2 = { 2, 3 };
        vector<int> nums3 = { 1, 2 };

        Solution Solution_cs;
        auto Result = Solution_cs.twoOutOfThree(nums1, nums2, nums3);
        printf("Result value size is %d, true=%d, false=%d\n", Result.size(), true, false);
        for (size_t i = 0; i < Result.size(); i++)
        {
            printf("Result[%d]=%d\n", i, Result[i]);
        }
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: nums1 = [1, 2, 2], nums2 = [4, 3, 3], nums3 = [5]\n");
    printf("expected result: []\n");
    {
        vector<int> nums1 = { 1, 2, 2 };
        vector<int> nums2 = { 4, 3, 3 };
        vector<int> nums3 = { 5 };

        Solution Solution_cs;
        auto Result = Solution_cs.twoOutOfThree(nums1, nums2, nums3);
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
