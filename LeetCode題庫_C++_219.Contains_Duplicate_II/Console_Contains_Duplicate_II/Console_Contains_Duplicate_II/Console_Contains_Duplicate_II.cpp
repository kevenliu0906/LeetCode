// Console_Contains_Duplicate_II.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        map<int, int> nums_map_value_index;  // key: element value(nums[i]), value: element index(i)
        multimap<int, int> nums_multimap_value_index;  // key: element value(nums[i]), value: element index(i)
        
        for (size_t i = 0; i < nums.size(); i++)
        {
            // nums_map_value_index.insert(pair<int, int>(nums[i], i));
            nums_multimap_value_index.insert(pair<int, int>(nums[i], i));
        }
        // // debug for nums_map element value
        // for (auto nums_map_iter : nums_map_value_index)
        // {
        //     auto num_value = nums_map_iter.first;
        //     auto num_index = nums_map_iter.second;
        //     printf("<kd> nums_map_value_index[%d]=%d\n", num_value, num_index);
        // }
        // // debug for nums_multimap element value
        // for (auto nums_multimap_iter : nums_multimap_value_index)
        // {
        //     auto num_value = nums_multimap_iter.first;
        //     auto num_index = nums_multimap_iter.second;
        //     printf("<kd> nums_multimap_value_index[%d]=%d\n", num_value, num_index);
        // }

        //----- judgement HERE
        vector<int> sort_numValue_vec;
        vector<int> sort_numIndex_vec;
        for (auto nums_multimap_iter : nums_multimap_value_index)
        {
            auto num_value = nums_multimap_iter.first;
            auto num_index = nums_multimap_iter.second;
            sort_numValue_vec.push_back(num_value);
            sort_numIndex_vec.push_back(num_index);
        }
        for (size_t i = 0; i < sort_numValue_vec.size() - 1; i++)
        {
            if( (sort_numValue_vec[i] == sort_numValue_vec[i+1]) && (abs(sort_numIndex_vec[i] - sort_numIndex_vec[i+1]) <= k ) )
                return true;
        }
        
        return false;
    }
};

int main()
{
    std::cout << "Hello LeetCode - Contains Duplicate II, DataStructure (HASH TABLE) !\n";

    printf("LeetCode - 219. Contains Duplicate II\n");
    cout << "https://leetcode.com/problems/contains-duplicate-ii" << endl << endl;
    cout << "solution: https://medium.com/@zero.ling/c-sort-a-map-by-value-601a60ec0e01" << endl;
    // cout << "solution: https://blog.techbridge.cc/2017/01/21/simple-hash-table-intro/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: nums={1, 2, 3, 1}, k=3 \n");
    printf("expected result: TRUE\n");
    {
        vector<int> nums{1, 2, 3, 1};
        int k = 3;

        Solution Solution_cs;
        auto Result = Solution_cs.containsNearbyDuplicate(nums, k);
        printf("Result value is %d, true(%d), false(%d)\n", Result, true, false);

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: nums={1, 0, 1, 1}, k=1 \n");
    printf("expected result: TRUE\n");
    {
        vector<int> nums{1, 0, 1, 1};
        int k = 1;

        Solution Solution_cs;
        auto Result = Solution_cs.containsNearbyDuplicate(nums, k);
        printf("Result value is %d, true(%d), false(%d)\n", Result, true, false);

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: nums={1, 2, 3, 1, 2, 3}, k=2 \n");
    printf("expected result: FALSE\n");
    {
        vector<int> nums{1, 2, 3, 1, 2, 3};
        int k = 2;

        Solution Solution_cs;
        auto Result = Solution_cs.containsNearbyDuplicate(nums, k);
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
