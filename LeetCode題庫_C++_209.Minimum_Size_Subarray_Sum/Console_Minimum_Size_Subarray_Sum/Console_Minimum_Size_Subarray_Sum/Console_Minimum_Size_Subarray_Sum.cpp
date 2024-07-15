// Console_Minimum_Size_Subarray_Sum.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        // solution 1 (keven, best)
        {
            int right = 0;
            int left = 0;
            int total = 0;
            int element_count = 0;
            int min_len = nums.size() + 1;

            while ( right < nums.size() ){
                total += nums[right];
                element_count++;
                
                if ( total >= target )
                {
                    // printf("right:%d, total:%d, min_len:%d, element_count:%d\n", right, total, min_len, element_count);
                    min_len = (min_len < element_count) ? min_len : element_count;
                    // bingo, found it 
                    // then minimize the scape
                    while (left <= right)
                    {
                        total -= nums[left];
                        element_count--;
                        if ( total >= target )
                        {
                            // printf("min_len:%d, element_count:%d\n", min_len, element_count);
                            min_len = (min_len < element_count) ? min_len : element_count;
                        }
                        else{
                            left++;
                            break;
                        }
                        
                        left++;
                    }

                }
                
                right++;
            }

            if (min_len == nums.size() + 1)
            {
                // represent these is no min-sub array length meats the target
                min_len = 0;
            }

            return min_len;
        }


        // solution 2 (best, demo)
        {
            int res = INT_MAX, left = 0, sum = 0;
            for (int i = 0; i < nums.size(); ++i) {
                sum += nums[i];
                while (left <= i && sum >= target) {
                    res = min(res, i - left + 1);
                    sum -= nums[left++];
                }
            }
            return res == INT_MAX ? 0 : res;
            
        }
        
        // Solution 3 (Time Exceed)
        {
            int MinResult = nums.size() + 1;   // assume the minimum result is equal to nums.size() + 1 (so if the result is still nums.size()+1 means there is no result)
            for (size_t currentIndex = 0; currentIndex < nums.size(); currentIndex++)
            {
                int increaseIndex = currentIndex;
                int totalSum = 0;
                int element_count = 0;
                bool Found = false;
                while( increaseIndex < nums.size() ){
                    totalSum = totalSum + nums[increaseIndex];
                    element_count++;
                    // printf("nums[%d]:%d, (increase) totalSum:%d\n", increaseIndex, nums[increaseIndex], totalSum);
                    if ( totalSum >= target ){
                        // bingo, found it. ( from the increase side)
                        Found = true;
                        MinResult = (element_count < MinResult) ? element_count : MinResult;
                        // printf("(Increase side)-> element_count:%d, nums[%d]:%d, totalSum:%d, MinResult:%d\n", element_count, increaseIndex, nums[increaseIndex], totalSum, MinResult);
                        
                        
                        if ( element_count == 1 ){
                            return 1;   // this is already mininum result, so directly return it
                        }

                        // minimize the scale (from the decrease side)
                        int decreaseIndex = currentIndex;
                        while( (decreaseIndex) < nums.size() ){
                            totalSum = totalSum - nums[decreaseIndex];
                            element_count--;

                            // printf("nums[%d]:%d, (decrease) totalSum:%d\n", decreaseIndex, nums[decreaseIndex], totalSum);
                            if( totalSum >= target ){
                                // bingo, found it.
                                Found = true;
                                MinResult = (element_count < MinResult) ? element_count : MinResult;
                                // printf("(decrease side)-> element_count:%d, nums[%d]:%d, totalSum:%d, MinResult:%d\n", element_count, decreaseIndex, nums[decreaseIndex], totalSum, MinResult);

                                if ( element_count == 1 ){
                                    return 1;   // this is mininum result, so directly return it
                                }
                            }else{
                                break;
                            }

                            decreaseIndex++;
                        }

                        break;
                    }

                    increaseIndex++;
                    
                }
                
            }

            if ( MinResult == nums.size() + 1 )
                return 0;

            return MinResult;
            
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Minimum Size Subarray Sum, Algorithm(Slide Window, Array)!\n";
    printf("LeetCode - 209. Minimum Size Subarray Sum\n");
    cout << "https://leetcode.com/problems/minimum-size-subarray-sum" << endl << endl;
    // cout << "solution: https://mocowcow.github.io/leetcode-222-count-complete-tree-nodes/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: target = 7, nums: [2,3,1,2,4,3]\n");
    printf("expected result: output = 2\n");
    {
        int target = 7;
        vector<int> nums{2, 3, 1, 2, 4, 3};
        Solution solution;
        auto result = solution.minSubArrayLen(target, nums);
        printf("result:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: target = 4, nums: [1,4,4]\n");
    printf("expected result: output = 1\n");
    {
        int target = 4;
        vector<int> nums{1,4,4};
        Solution solution;
        auto result = solution.minSubArrayLen(target, nums);
        printf("result:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: target = 11, nums: [1,1,1,1,1,1,1,1]\n");
    printf("expected result: output = 0\n");
    {
        int target = 11;
        vector<int> nums{1,1,1,1,1,1,1,1};
        Solution solution;
        auto result = solution.minSubArrayLen(target, nums);
        printf("result:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: target = 213, nums: [12, 28, 83, 4, 25, 26, 25, 2, 25, 25, 25, 12]\n");
    printf("expected result: output = 8\n");
    {
        int target = 213;
        vector<int> nums{12, 28, 83, 4, 25, 26, 25, 2, 25, 25, 25, 12};
        Solution solution;
        auto result = solution.minSubArrayLen(target, nums);
        printf("result:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 5 ****************************\n");
    printf("input: target = 15, nums: [1, 2, 3, 4, 5]\n");
    printf("expected result: output = 5\n");
    {
        int target = 15;
        vector<int> nums{1, 2, 3, 4, 5};
        Solution solution;
        auto result = solution.minSubArrayLen(target, nums);
        printf("result:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 6 ****************************\n");
    printf("input: target = 15, nums: [5,1,3,5,10,7,4,9,2,8]\n");
    printf("expected result: output = 2\n");
    {
        int target = 15;
        vector<int> nums{5,1,3,5,10,7,4,9,2,8};
        Solution solution;
        auto result = solution.minSubArrayLen(target, nums);
        printf("result:%d\n", result);
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
