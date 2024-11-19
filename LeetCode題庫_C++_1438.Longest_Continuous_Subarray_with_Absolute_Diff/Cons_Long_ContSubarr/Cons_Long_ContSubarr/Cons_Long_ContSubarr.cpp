// Cons_Long_ContSubarr.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
private:
    int array_max_absolute_diff_small_equal_limit(vector<int> &nums, int startIdx, int endIdx, int limit){

        // printf("startIdx:%d, endIdx:%d\n", startIdx, endIdx);
        multiset<int> sort_nums_multiset;
        while (startIdx <= endIdx)
        {
            // printf("sort_nums_multiset insert %d\n", nums[startIdx]);
            sort_nums_multiset.insert(nums[startIdx]);
            startIdx++;
        }
        
        auto start = *sort_nums_multiset.begin();
        auto end = *sort_nums_multiset.rbegin();
        // printf("array_max_absolute_diff_small_equal_limit >>> start:%d, end:%d\n", start, end);
        auto diff = end - start;
        if (diff > limit)
        {
            return -1;
        }
        
        return sort_nums_multiset.size();
    }

public:
    int longestSubarray(vector<int>& nums, int limit) {
        // solution 0 (keven, refer others with Sliding Window + TreeSet
        // https://zxi.mytechroad.com/blog/queue/leetcode-1438-longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/)
        // thinking - Use a treeset to maintain a range of [l, r] such that max(nums[l~r]) – min(nums[l~r]) <= limit.
        //            Every time, we add nums[r] into the tree, and move l towards r to keep the max diff under limit.
        {
            multiset<int> meet_num_multiset;
            int L_idx = 0;
            // int R_idx = 0;
            int max_len = 0;
            for (int R_idx = 0; R_idx < nums.size(); R_idx++)
            {
                meet_num_multiset.insert(nums[R_idx]);
                while (*meet_num_multiset.rbegin() - *meet_num_multiset.begin() > limit)
                {
                    // current combination does not meet the requirement (diff must be <= limit)

                    // auto erase_item = *meet_num_multiset.equal_range(nums[L_idx]).first;
                    // auto begin_item = *meet_num_multiset.find(nums[L_idx]);
                    // printf("while loop, erase >>> nums[L_idx]:%d, *meet_num_multiset.begin():%d, erase_item:%d, begin_item:%d\n", nums[L_idx], *meet_num_multiset.begin(), erase_item, begin_item);
                    meet_num_multiset.erase(meet_num_multiset.find(nums[L_idx]));
                    L_idx++;
                }
                max_len = max(max_len, R_idx - L_idx + 1);
            }
            
            return max_len;
        }

        // solution 1 (keven, force directly, TLE in testcase 37)
        {
            int subarray_idx = nums.size() - 1;
            while (subarray_idx >= 0)
            {
                int start_array_idx = 0;
                while (start_array_idx + subarray_idx < nums.size())
                {   
                    auto diff = array_max_absolute_diff_small_equal_limit(/*check_arr*/nums, start_array_idx, start_array_idx + subarray_idx, limit);
                    if (diff > 0)
                    {
                        return diff;
                    }

                    start_array_idx++;
                }
                
                subarray_idx--;
            }
            
            return 0;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Longest Continuous Subarray with Absolute Diff Less than or equal to Limit, Algorithm(Side Windows)!\n";
    cout << "https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/" << endl;
    cout << "best solution: https://zxi.mytechroad.com/blog/queue/leetcode-1438-longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: nums = [8,2,4,7], limit = 4\n");
    printf("expected result: output = 2\n");

    printf("Explanation: All subarrays are:\n"); 
    printf("[8] with maximum absolute diff |8-8| = 0 <= 4.\n");
    printf("[8,2] with maximum absolute diff |8-2| = 6 > 4.\n");
    printf("[8,2,4] with maximum absolute diff |8-2| = 6 > 4.\n");
    printf("[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.\n");
    printf("[2] with maximum absolute diff |2-2| = 0 <= 4.\n");
    printf("[2,4] with maximum absolute diff |2-4| = 2 <= 4.\n");
    printf("[2,4,7] with maximum absolute diff |2-7| = 5 > 4.\n");
    printf("[4] with maximum absolute diff |4-4| = 0 <= 4.\n");
    printf("[4,7] with maximum absolute diff |4-7| = 3 <= 4.\n");
    printf("[7] with maximum absolute diff |7-7| = 0 <= 4.\n");
    printf("Therefore, the size of the longest subarray is 2.\n");
    {
        vector<int> nums{8,2,4,7};
        int limit = 4;

        Solution solution;
        auto res = solution.longestSubarray(nums, limit);
        printf("res is %d\n", res);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: nums = [10,1,2,4,7,2], limit = 5\n");
    printf("expected result: output = 4\n");
    printf("Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.\n"); 
    {
        vector<int> nums{10,1,2,4,7,2};
        int limit = 5;

        Solution solution;
        auto res = solution.longestSubarray(nums, limit);
        printf("res is %d\n", res);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: nums = [4,2,2,2,4,4,2,2], limit = 0\n");
    printf("expected result: output = 3\n");
    {
        vector<int> nums{4,2,2,2,4,4,2,2};
        int limit = 0;

        Solution solution;
        auto res = solution.longestSubarray(nums, limit);
        printf("res is %d\n", res);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: nums = [8], limit = 10\n");
    printf("expected result: output = 1\n");
    {
        vector<int> nums{ 8 };
        int limit = 10;

        Solution solution;
        auto res = solution.longestSubarray(nums, limit);
        printf("res is %d\n", res);
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
