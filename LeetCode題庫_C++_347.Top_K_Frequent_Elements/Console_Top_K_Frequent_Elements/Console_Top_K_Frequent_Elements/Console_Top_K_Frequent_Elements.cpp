// Console_Top_K_Frequent_Elements.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class Solution{
public:

    void swap_pair_vec(int &pair_a, int &pair_b){
        int tmp = pair_a;
        pair_a = pair_b;
        pair_b = tmp;
    }
    
    vector<int> topKFrequent(vector<int> &nums, int k){

        vector<int> result;

        // solution 1 (best)
        {
            // STEP1: ecount for each nums
            unordered_map<int, int> nums_unorderedmap_num_counts;   // key: num, value: counts
            for (size_t i = 0; i < nums.size(); i++)
            {
                nums_unorderedmap_num_counts[nums[i]]++;
            }
            // printf("--------- DEBUG STEP1 ---------\n");

            // STEP2: switch to pair array of (frquency & num)
            vector<pair<int, int>> FrequnecyNum_vec(nums_unorderedmap_num_counts.begin(), nums_unorderedmap_num_counts.end());  // pair_first: counts, pair_second: num
            for (size_t i = 0; i < FrequnecyNum_vec.size(); i++)
            {
                // change storage data format from "pair_first: num, pair_sec: counts" to "pair_first: counts, pair_sec: num"
                swap_pair_vec(FrequnecyNum_vec[i].first, FrequnecyNum_vec[i].second);  
            }
            // printf("--------- DEBUG STEP2 ---------\n");
            // printf("FrequnecyNum_vec size:%d\n", FrequnecyNum_vec.size());
            // for (size_t i = 0; i < FrequnecyNum_vec.size(); i++)
            // {
            //     printf("FrequnecyNum_vec[%d]:%d\n", i, FrequnecyNum_vec[i]);
            // }

            // STEP3: change to map inorder to sort pair array of (frequency & num)
            multimap<int, int> FrequencyNum_multimap(FrequnecyNum_vec.begin(), FrequnecyNum_vec.end());
            // printf("--------- DEBUG STEP3 ---------\n");
            // for (auto FrequencyNum_multimap_each : FrequencyNum_multimap )
            // {
            //     printf("FrequencyNum_multimap_each, key:%d, value:%d\n", FrequencyNum_multimap_each.first, FrequencyNum_multimap_each.second);
            // }
            
            
            for (auto FrequencyNum_multimap_iter = FrequencyNum_multimap.rbegin(); FrequencyNum_multimap_iter != FrequencyNum_multimap.rend(); FrequencyNum_multimap_iter++)
            {
                if( k > 0 ){
                    k--;
                    result.push_back(FrequencyNum_multimap_iter->second);
                }
            }

        }

        // // solution 2 (keven)
        // {
        //     unordered_map<int, int> nums_unorderedmap_num_counts;
        //     multimap<int, int> nums_multimap_counts_num;     
            
            
        //     // STEP1, calc the total counts for each num
        //     for (size_t i = 0; i < nums.size(); i++)
        //     {
        //         auto current_num = nums[i];
        //         // printf("current_num:%d\n", current_num);
        //         // step1-1, get the counts for current num
        //         int origin_EachNum_Counts = 0;
        //         if( nums_unorderedmap_num_counts.count(current_num) )
        //             origin_EachNum_Counts = nums_unorderedmap_num_counts.at(current_num);
                
        //         // step1-2, counts increase
        //         origin_EachNum_Counts++;

        //         // step1-3 erase the original count for current num
        //         if( nums_unorderedmap_num_counts.count(current_num) )
        //             nums_unorderedmap_num_counts.erase(current_num);
                
        //         // step1-4, replace the increase counts for current num
        //         nums_unorderedmap_num_counts.insert(pair<int, int>(current_num, origin_EachNum_Counts));
        //     }
        //     // // debug for elements in nums_unorderedmap_num_counts
        //     // printf("DEBUG ---> STEP1\n");
        //     // for (auto nums_unorderedmap_num_counts_each : nums_unorderedmap_num_counts)
        //     // {
        //     //     printf("nums_unorderedmap_num_counts_each, key:%d, value:%d\n", nums_unorderedmap_num_counts_each.first, nums_unorderedmap_num_counts_each.second);
        //     // }
        //     // printf("-------------------------------------------------------\n");

        //     // STEP2, transfer into sort map
        //     for (auto nums_unorderedmap_num_counts_each : nums_unorderedmap_num_counts)
        //     {
        //         nums_multimap_counts_num.insert(pair<int, int>(nums_unorderedmap_num_counts_each.second, nums_unorderedmap_num_counts_each.first));
        //     }
        //     // // debug for elements in nums_multimap_counts_num
        //     // printf("DEBUG ---> STEP2\n");
        //     // for (auto nums_multimap_counts_num_each : nums_multimap_counts_num)
        //     // {
        //     //     printf("nums_multimap_counts_num_each, key:%d, value:%d\n", nums_multimap_counts_num_each.first, nums_multimap_counts_num_each.second);
        //     // }
        //     // printf("-------------------------------------------------------\n");

        //     for (auto iter = nums_multimap_counts_num.rbegin(); iter != nums_multimap_counts_num.rend(); iter++)
        //     {
        //         if( k > 0 ){
        //             auto counts = iter->first;
        //             auto num = iter->second;
        //             // printf("<FINAL> counts:%d, num:%d, k:%d\n", counts, num, k);
        //             result.push_back(num);
        //             k--;
        //         }
        //     }
        // }
        
        return result;
    }
};

int main()
{
    std::cout << "Hello LeetCode - Top K Frequent Elements, DataStructure (HASH TABLE, Array, Heap, Bucket Sort)!\n";

    printf("LeetCode - 347. Top K Frequent Elements\n");
    cout << "https://leetcode.com/problems/top-k-frequent-elements" << endl << endl;
    // cout << "solution: https://medium.com/@zero.ling/c-sort-a-map-by-value-601a60ec0e01" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: nums = [1, 1, 1, 2, 2, 3], k = 2\n");
    printf("expected result: [1, 2]\n");
    {
        vector<int> nums{1, 1, 1, 2, 2, 3};
        int k = 2;

        Solution Solution_cs;
        auto Result = Solution_cs.topKFrequent(nums, k);

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
    printf("input: nums = [1], k = 1\n");
    printf("expected result: [1]\n");
    {
        vector<int> nums{1};
        int k = 1;

        Solution Solution_cs;
        auto Result = Solution_cs.topKFrequent(nums, k);

        printf("Result value size is %d, true=%d, false=%d\n", Result.size(), true, false);
        for (size_t i = 0; i < Result.size(); i++)
        {
            printf("Result[%d]=%d\n", i, Result[i]);
        }
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: nums = [1, 2], k = 2\n");
    printf("expected result: [1, 2]\n");
    {
        vector<int> nums{1, 2};
        int k = 2;

        Solution Solution_cs;
        auto Result = Solution_cs.topKFrequent(nums, k);

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
