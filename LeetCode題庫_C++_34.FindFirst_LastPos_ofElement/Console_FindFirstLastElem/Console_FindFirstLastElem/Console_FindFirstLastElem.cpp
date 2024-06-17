// Console_FindFirstLastElem.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int bingo = -1;
        vector<int> Result;
        // printf("searchRange --> step1\n");
        // step1: search the smallest index of element which value >= target
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target == nums[mid]) {
                bingo = mid;
                right = mid - 1;
            }
            if (target < nums[mid]) {
                right = mid - 1;
            }
            else if (target > nums[mid]) {
                left = mid + 1;
            }
        }
        if (bingo != -1)
            Result.push_back(left);
        
        // printf("(Step1), Current Result size:%d\n", Result.size());
        // for (size_t i = 0; i < Result.size(); i++)
        // {
        //     printf("Result[%d]=%d\n", i, Result[i]);
        // }

        left = 0;
        right = nums.size() - 1;
        bingo = -1;
        // printf("searchRange --> step2\n");
        //step2: search the smallest index of element which value > target
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target == nums[mid]) {
                bingo = mid;
                left = mid + 1;
            }
            if (target < nums[mid]) {
                right = mid - 1;
            }
            else if (target > nums[mid]) {
                left = mid + 1;
            }
        }
        if (bingo != -1)
            Result.push_back(left - 1);  // because the senario is to search the least position of element, so need -1
        // printf("(Step2), Current Result size:%d\n", Result.size());
        // for (size_t i = 0; i < Result.size(); i++)
        // {
        //     printf("Result[%d]=%d\n", i, Result[i]);
        // }


        if (Result.size() == 0) {
            Result.push_back(-1);
            Result.push_back(-1);
        }
        else if (Result.size() == 1) {
            auto element = Result[0];
            Result.push_back(element);
        }
        else {
            sort(std::begin(Result), std::end(Result));
        }

        return Result;
    }
};


int main()
{
    std::cout << "Hello LeetCode - Find First and Last Position of element in sorted array!\n";
    printf("LeetCode - 34. Find First and Last Position of Element in Sorted Array\n");
    cout << "https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/" << endl << endl;;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: nums=[5, 7, 7, 8, 8, 10], target=8\n");
    printf("expected result: [3, 4]\n");
    {
        vector<int> nums{ 5, 7, 7, 8, 8, 10 };
        int target = 8;
        Solution Solution_cs;
        auto Result = Solution_cs.searchRange(nums, target);
        printf("Result size is %d\n", Result.size());
        for (size_t i = 0; i < Result.size(); i++)
        {
            printf("Result[%d]=%d\n", i, Result[i]);
        }
        printf("*****************************************************\n");
    }

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: nums=[5, 7, 7, 8, 8, 10], target=6\n");
    printf("expected result: [-1, -1]\n");
    {
        vector<int> nums{ 5, 7, 7, 8, 8, 10 };
        int target = 6;
        Solution Solution_cs;
        auto Result = Solution_cs.searchRange(nums, target);
        printf("Result size is %d\n", Result.size());
        for (size_t i = 0; i < Result.size(); i++)
        {
            printf("Result[%d]=%d\n", i, Result[i]);
        }
        printf("*****************************************************\n");
    }

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: nums=[], target=0\n");
    printf("expected result: [-1, -1]\n");
    {
        vector<int> nums{ };
        int target = 0;
        Solution Solution_cs;
        auto Result = Solution_cs.searchRange(nums, target);
        printf("Result size is %d\n", Result.size());
        for (size_t i = 0; i < Result.size(); i++)
        {
            printf("Result[%d]=%d\n", i, Result[i]);
        }
    }
    printf("*****************************************************\n");
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
