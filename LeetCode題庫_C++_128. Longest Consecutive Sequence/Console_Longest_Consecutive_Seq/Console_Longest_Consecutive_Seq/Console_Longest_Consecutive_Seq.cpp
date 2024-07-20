// Console_Longest_Consecutive_Seq.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // solution 1 (keven, best)
        {
            if (nums.size() == 0)
                return 0;

            sort(nums.begin(), nums.end());
            
            int current_num = nums[0] - 1;  // in order to consider the 1st element is consecutive in the for loop judgement
            int consecutiveCount = 0;
            int max_consecutive_count = 0;
            for (size_t i = 0; i < nums.size(); i++)
            {
                // printf("nums[%d]:%d\n", i, nums[i]);
                if ( (nums[i] - current_num) == -1 || (nums[i] - current_num) == 1 ){
                    // consecutive case
                    current_num = nums[i];
                    consecutiveCount++;
                }
                else if( (nums[i] - current_num) == 0 ){
                    // same element case and have already judged, check the next one.
                    continue;
                }
                else{
                    // non-consecutive case
                    current_num = nums[i];
                    // upload the max-consecutive-count
                    if ( consecutiveCount > max_consecutive_count )
                    {
                        max_consecutive_count = consecutiveCount;
                    }
                    consecutiveCount = 0;
                    consecutiveCount++;  // current non-consecutive need to be recorded
                }
                
            }

            if ( consecutiveCount > max_consecutive_count )
            {
                max_consecutive_count = consecutiveCount;
            }    

            return max_consecutive_count;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - DataStructure(HASH TABLE, )!\n";
    cout << "https://leetcode.com/problems/longest-consecutive-sequence" << endl << endl;
    // cout << "solution: https://www.geeksforgeeks.org/count-ways-reach-nth-stair/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: nums = [100, 4, 200, 1, 3, 2]\n");
    printf("expected result: output = 4\n");
    {
        vector<int> nums{100, 4, 200, 1, 3, 2};
        
        Solution solution;
        auto result = solution.longestConsecutive(nums);
        printf("result value:%d\n", result);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]\n");
    printf("expected result: output = 9\n");
    {
        vector<int> nums{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
        
        Solution solution;
        auto result = solution.longestConsecutive(nums);
        printf("result value:%d\n", result);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: nums = []\n");
    printf("expected result: output = 0\n");
    {
        vector<int> nums{};
        
        Solution solution;
        auto result = solution.longestConsecutive(nums);
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
