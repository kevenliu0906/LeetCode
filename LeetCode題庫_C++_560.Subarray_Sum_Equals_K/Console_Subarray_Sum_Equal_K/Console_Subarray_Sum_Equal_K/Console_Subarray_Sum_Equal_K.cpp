// Console_Subarray_Sum_Equal_K.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int subarraySum(vector<int>& nums, int k) {

        // solution 1 (keven)
        {
            int totalsubarraySum = 0;

            for (size_t currentIndex = 0; currentIndex < nums.size(); currentIndex++)
            {
                // printf("currentIndex:%d\n", currentIndex);
                int totalSum = nums[currentIndex];

                if (totalSum == k)
                {
                    totalsubarraySum++;
                    // printf("<loop-%d>:totalSum:%d, totalsubarraySum:%d\n", currentIndex, totalSum, totalsubarraySum);
                    // continue;
                }
                else{

                }
                
                int NextIndex = currentIndex+1;
                while ( NextIndex < nums.size() )
                {
                    totalSum = totalSum + nums[NextIndex];
                    // printf("totalSum:%d, nums[%d]:%d\n", totalSum, NextIndex, nums[NextIndex]);
                    if (totalSum == k)
                    {
                        totalsubarraySum++;
                        // continue;
                    }
                    
                    if (totalSum>k)
                    {
                        // continue;
                    }
                    
                    NextIndex++;
                }
                
            }
            
            // printf("totalsubarraySum:%d\n", totalsubarraySum);
            
            return totalsubarraySum;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Subarray Sum Equals K, DataStructure(HASH TABLE)!\n";
    cout << "https://leetcode.com/problems/subarray-sum-equals-k" << endl << endl;
    // cout << "solution: https://www.geeksforgeeks.org/count-ways-reach-nth-stair/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: nums = [1, 1, 1], k = 2\n");
    printf("expected result: output = 2\n");
    {
        vector<int> nums{1, 1, 1};
        int k = 2;
        
        Solution solution;
        auto result = solution.subarraySum(nums, k);
        printf("result value:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: nums = [1, 2, 3], k = 3\n");
    printf("expected result: output = 2\n");
    {
        vector<int> nums{1, 2, 3};
        int k = 3;
        
        Solution solution;
        auto result = solution.subarraySum(nums, k);
        printf("result value:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: nums = [1, 2, 1], k = 2\n");
    printf("expected result: output = 1\n");
    {
        vector<int> nums{1, 2, 1};
        int k = 2;
        
        Solution solution;
        auto result = solution.subarraySum(nums, k);
        printf("result value:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: nums = [2, 2, 2], k = 2\n");
    printf("expected result: output = 3\n");
    {
        vector<int> nums{2, 2, 2};
        int k = 2;
        
        Solution solution;
        auto result = solution.subarraySum(nums, k);
        printf("result value:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 5 ****************************\n");
    printf("input: nums = [1, -1, 0], k = 0\n");
    printf("expected result: output = 3\n");
    {
        vector<int> nums{1, -1, 0};
        int k = 0;
        
        Solution solution;
        auto result = solution.subarraySum(nums, k);
        printf("result value:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 6 ****************************\n");
    printf("input: nums = [0, 0], k = 0\n");
    printf("expected result: output = 3\n");
    {
        vector<int> nums{0, 0};
        int k = 0;
        
        Solution solution;
        auto result = solution.subarraySum(nums, k);
        printf("result value:%d\n", result);
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
