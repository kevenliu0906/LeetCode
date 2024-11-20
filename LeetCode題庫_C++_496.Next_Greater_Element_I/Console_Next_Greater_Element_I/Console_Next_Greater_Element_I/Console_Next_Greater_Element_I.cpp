// Console_Next_Greater_Element_I.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution{
private:
    void monotonic_stack(vector<int> &nums, unordered_map<int,int> &data_nums_NextGreaterValue){
        stack<int> mono_st;
        // printf("monotonic_stack (START)\n");
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            // printf("nums[%d]:%d\n", i, nums[i]);
            while (!mono_st.empty() && mono_st.top() <= nums[i])
            {
                // printf("pop mono_st >>> mono_st.top()=%d\n", mono_st.top());
                mono_st.pop();
            }
            
            auto next_greater_value = mono_st.empty() ? -1 : mono_st.top();
            // next_greater_nums[i] = next_greater_value;
            // printf("next_greater_value:%d\n", next_greater_nums[i]);
            data_nums_NextGreaterValue.insert(pair<int,int>(nums[i], next_greater_value));
            
            mono_st.push(nums[i]);
        }
        // printf("monotonic_stack (END)\n");
    }

public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> result;

        // solution 0 (keven, refactor, using Monotonic Stack to solve)
        {
            // calc monotonic stack for nums2
            unordered_map<int,int> data_nums_nextgreatervalue;

            monotonic_stack(nums2, data_nums_nextgreatervalue);

            for (int i = 0; i < nums1.size(); i++)
            {
                result.push_back(data_nums_nextgreatervalue[nums1[i]]);
            }

            return result;
        }

        // solution 1 (keven, best)
        {
            unordered_map<int, int> nums2_value_index_unmap;   // key: nums2[i](value), value: i(index)

            // create map within nums2 data for database
            for (size_t i = 0; i < nums2.size(); i++)
            {
                auto value = nums2[i];
                auto index = i;

                // nums2_map[value] = index;
                // nums2_value_index_unmap.insert(nums2_value_index_unmap.begin(), pair<int,int>(value, index));
                nums2_value_index_unmap.insert(pair<int,int>(value, index));
            }
            // // for debug nums2_map
            // for (auto each_nums2_unmap : nums2_value_index_unmap)
            // {
            //     printf("nums2_map, key:%d, value:%d\n", each_nums2_unmap.first, each_nums2_unmap.second);
            // }

            // START searching
            for (size_t i = 0; i < nums1.size(); i++)
            {
                auto search_value = nums1[i];

                auto res_index = nums2_value_index_unmap.at(search_value);

                bool Match = false;

                while( res_index < nums2_value_index_unmap.size() - 1 ){
                    res_index++;
                    if( nums2[res_index] > search_value ){
                        result.push_back(nums2[res_index]);
                        Match = true;
                        break;
                    }
                }

                if( !Match )
                    result.push_back(-1);

                // // for debug the result
                // for (size_t j = 0; j < result.size(); j++)
                // {
                //     printf("<kd> search:%d, result[%d]=%d\n", search_value, j, result[j]);
                // }
            }
        }

        return result;
    }
};

int main()
{
    std::cout << "Hello LeetCode - Next Greater Element I, DataStructure(HASH TABLE, Array) !\n";

    printf("LeetCode - 496. Next Greater Element I\n");
    cout << "https://leetcode.com/problems/next-greater-element-i/" << endl << endl;
    // cout << "solution: https://medium.com/@zero.ling/c-sort-a-map-by-value-601a60ec0e01" << endl;


    // // for testing insert function in map/unordered_map
    // {
    //     unordered_map<int, string> nums2_unmap;
    //     nums2_unmap[3] = "abc";
    //     nums2_unmap[1] = "ed";
    //     nums2_unmap[4] = "wxyz";
        
    //     for (auto nums2_unmap_each : nums2_unmap)
    //     {
    //         printf("<kd> nums2_unmap, key:%d, value:%s\n", nums2_unmap_each.first, nums2_unmap_each.second.c_str());
    //     }

    //     return 0;    
    // }
    

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: nums1 = [4, 1, 2], nums2 = [1, 3, 4, 2]\n");
    printf("expected result: [-1, 3, -1]\n");
    {
        vector<int> nums1 = {4, 1, 2};
        vector<int> nums2 = {1, 3, 4, 2};

        Solution Solution_cs;
        auto Result = Solution_cs.nextGreaterElement(nums1, nums2);
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
    printf("input: nums1 = [2, 4], nums2 = [1, 2, 3, 4]\n");
    printf("expected result: [3, -1]\n");
    {
        vector<int> nums1 = {2, 4};
        vector<int> nums2 = {1, 2, 3, 4};

        Solution Solution_cs;
        auto Result = Solution_cs.nextGreaterElement(nums1, nums2);
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
