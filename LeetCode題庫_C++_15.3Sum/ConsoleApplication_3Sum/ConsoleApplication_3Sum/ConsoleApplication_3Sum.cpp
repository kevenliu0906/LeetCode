// ConsoleApplication_3Sum.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;

class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // solution 1 (best)
        {
            vector<vector<int>> result;  // final result

            // sort the original array first
            sort(nums.begin(), nums.end());

            int max_len = nums.size();
            for (size_t i = 0; i <= max_len - 3; i++)
            {
                int num = nums[i];
                int target = 0 - num;
                int left_index = i + 1;
                int right_index = max_len - 1;

                // skip the duplicated-checked element
                if( (i > 0) && nums[i] == nums[i-1] )
                    continue;

                while( left_index < right_index ){
                    if ( nums[left_index] + nums[right_index] == target )
                    {
                        result.push_back({nums[i], nums[left_index], nums[right_index]});
                        
                        // skip the duplicated-checked element
                        while( (left_index + 1 < max_len) && (nums[left_index] == nums[left_index + 1]) )
                            left_index++;
                        // skip the duplicated-checked element
                        while( (right_index > 0) && nums[right_index] == nums[right_index - 1] )
                            right_index--;

                        left_index++;
                        right_index--;
                    }
                    else if ( nums[left_index] + nums[right_index] < target )
                    {
                        // skip the duplicated-checked element
                        while( (left_index + 1 < max_len) && (nums[left_index] == nums[left_index + 1]) )
                            left_index++;
                        left_index++;
                    }
                    else
                    {
                        // skip the duplicated-checked element
                        while( (right_index > 0) && nums[right_index] == nums[right_index - 1] )
                            right_index--;
                        right_index--;
                    }
                }
            }
            
            return result;
        }
        
        // // solution 2 (keven, time limit exceed)
        // {
        //     sort(nums.begin(), nums.end());

        //     vector<vector<int>> result;    // final result
        //     set<vector<int>> database_set;   // database the single result, for judgement if the single result exist or NOT
            
        //     int index_i = 0, index_j = 0;
        //     int max_len = nums.size();
        //     while (index_i <= max_len - 3)
        //     {
        //         // skip the duplicated-checked element (REDUCE search time)
        //         while( (index_i > 0) && (index_i < max_len) && nums[index_i] == nums[index_i-1] ){
        //             index_i++;
        //             continue;
        //         }

        //         index_j = index_i + 1;

        //         // printf("**********************\n");
        //         // printf("i:%d\n", i);
        //         while (index_j <= max_len - 2 /*&& index_j > index_i*/)
        //         {
        //             int total_i_j = nums[index_i] + nums[index_j];
        //             int value_k = 0 - total_i_j;

        //             auto value_k_index_iter = nums.begin() + index_j + 1;
        //             unordered_set<int> value_k_possible_unordered_set(value_k_index_iter, nums.end());

        //             auto count_k = value_k_possible_unordered_set.count(value_k);
        //             // printf("nums[%d]:%d, nums[%d]:%d, value_k:%d, count(k):%d\n", i, nums[i], j, nums[j], value_k, count_k);
        //             if( count_k ){

        //                 // BINGO~~~~ Found the answer
        //                 vector<int> single_result;     // each single match result

        //                 // record the answer
        //                 single_result.push_back(nums[index_i]);
        //                 single_result.push_back(nums[index_j]);
        //                 single_result.push_back(value_k);
                        
        //                 // if (database_set.count(single_result) == 0)
        //                 {
        //                     result.push_back(single_result);
        //                     // database_set.insert(single_result);
        //                 }

        //                 // skip the duplicated-checked element (REDUCE search time)
        //                 while( (index_j+1 < max_len) && nums[index_j] == nums[index_j+1] )
        //                     index_j++;
        //             }
        //             index_j++;
        //         }
        //         // printf("**********************\n\n");

        //         index_i++;
        //     }

        //     return result;
        // }
    
    }
};

int main()
{
    std::cout << "Hello LeetCode - 3Sum, Algorithm(Two Pointer, Array)!\n";
    printf("LeetCode - 15. 3Sum\n");
    cout << "https://leetcode.com/problems/3sum/" << endl << endl;
    // cout << "solution: https://www.geeksforgeeks.org/count-ways-reach-nth-stair/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: nums = [-1, 0, 1, 2, -1, -4]\n");
    printf("expected result: output = [[-1, -1, 2], [-1, 0, 1]]\n");
    {
        vector<int> nums{-1, 0, 1, 2, -1, -4};
        Solution solution;
        auto result = solution.threeSum(nums);
        printf("result size:%d\n", result.size());
        for (size_t i = 0; i < result.size(); i++)
        {
            printf("--------------------------\n");
            printf("result[%d]:\n", i);
            auto single_result = result[i];
            for (size_t j = 0; j < single_result.size(); j++)
            {
                printf("%d, ", single_result[j]);
            }
            printf("\n--------------------------\n\n");
            
        }
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: nums = [0, 1, 1]\n");
    printf("expected result: output = []\n");
    {
        vector<int> nums{ 0, 1, 1 };
        Solution solution;
        auto result = solution.threeSum(nums);
        printf("result size:%d\n", result.size());
        for (size_t i = 0; i < result.size(); i++)
        {
            printf("--------------------------\n");
            printf("result[%d]:\n", i);
            auto single_result = result[i];
            for (size_t j = 0; j < single_result.size(); j++)
            {
                printf("%d, ", single_result[j]);
            }
            printf("\n--------------------------\n\n");

        }

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: nums = [0, 0, 0]\n");
    printf("expected result: output = [[0, 0, 0]]\n");
    {
        vector<int> nums{ 0, 0, 0 };
        Solution solution;
        auto result = solution.threeSum(nums);
        printf("result size:%d\n", result.size());
        for (size_t i = 0; i < result.size(); i++)
        {
            printf("--------------------------\n");
            printf("result[%d]:\n", i);
            auto single_result = result[i];
            for (size_t j = 0; j < single_result.size(); j++)
            {
                printf("%d, ", single_result[j]);
            }
            printf("\n--------------------------\n\n");

        }

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: nums = [1, 2, -2, -1]\n");
    printf("expected result: output = []\n");
    {
        vector<int> nums{ 1, 2, -2, -1 };
        Solution solution;
        auto result = solution.threeSum(nums);
        printf("result size:%d\n", result.size());
        for (size_t i = 0; i < result.size(); i++)
        {
            printf("--------------------------\n");
            printf("result[%d]:\n", i);
            auto single_result = result[i];
            for (size_t j = 0; j < single_result.size(); j++)
            {
                printf("%d, ", single_result[j]);
            }
            printf("\n--------------------------\n\n");

        }

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 5 ****************************\n");
    printf("input: nums = [3, -2, 1, 0]\n");
    printf("expected result: output = []\n");
    {
        vector<int> nums{ 3, -2, 1, 0 };
        Solution solution;
        auto result = solution.threeSum(nums);
        printf("result size:%d\n", result.size());
        for (size_t i = 0; i < result.size(); i++)
        {
            printf("--------------------------\n");
            printf("result[%d]:\n", i);
            auto single_result = result[i];
            for (size_t j = 0; j < single_result.size(); j++)
            {
                printf("%d, ", single_result[j]);
            }
            printf("\n--------------------------\n\n");

        }

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 6 ****************************\n");
    printf("input: nums = [0, 0, 0, 0]\n");
    printf("expected result: output = [0, 0, 0]\n");
    {
        vector<int> nums{ 0, 0, 0, 0 };
        Solution solution;
        auto result = solution.threeSum(nums);
        printf("result size:%d\n", result.size());
        for (size_t i = 0; i < result.size(); i++)
        {
            printf("--------------------------\n");
            printf("result[%d]:\n", i);
            auto single_result = result[i];
            for (size_t j = 0; j < single_result.size(); j++)
            {
                printf("%d, ", single_result[j]);
            }
            printf("\n--------------------------\n\n");

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
