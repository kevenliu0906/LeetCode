// ConsoleApplication_Subsets.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        // solution 0 (keven, best, reference other use bit manipulation)
        //               use bit map to solve, bit[0] represent nums[0], bit[1] represent nums[1], bit[2] represent nums[2], etc..
        {
            vector<vector<int>> result;
            int num_size = nums.size();
            int combination = 1<<num_size;   // record total possible combination 
            
            for (size_t i = 0; i < combination; i++)  // according each possible combination
            {
                vector<int> sub_nums;
                for (size_t j = 0; j < num_size; j++) // figure out which bit is ON/OFF
                {
                    if ( i & (1<<j) )
                    {
                        sub_nums.push_back(nums[j]);
                    }
                    
                }
                result.push_back(sub_nums);
            }
            return result;
        }
        // solution 1 (keven, using backtracking to solve)
        {
            vector<vector<int>> result;
            vector<int> subset;
            vector<vector<int>> last_subset;
            vector<vector<int>> current_subset;

            // original case
            // there will be a empty subset for all nums
            result.push_back(subset);
            last_subset.push_back(subset);

            int finalsize = 0;
            do{
                finalsize = (last_subset.end()-1)->size();
                // printf("<LOOP-START>The size of last element in last_subset is %d\n", finalsize);
                
                // STEP1, use last_sub to append each elements of nums to achieve goal
                //        remember use new copy array(current_sub) from original array(last_subset) to process
                current_subset.clear();
                for (auto last_subset_each : last_subset)
                {
                    for (size_t i = 0; i < nums.size(); i++)
                    {
                        auto current_subset_each = last_subset_each;
                        
                        if (current_subset_each.size()){
                            auto current_subset_each_lastElement = current_subset_each[current_subset_each.size()-1];
                            if (nums[i] <= current_subset_each_lastElement){
                                // add this to let each append element is ascending & different from last-element
                                continue;
                            }
                        }
                        
                        unordered_set<int> _subset_each_unorderedset(current_subset_each.begin(), current_subset_each.end());
                        if (_subset_each_unorderedset.count(nums[i]) == 0)
                        {
                            current_subset_each.push_back(nums[i]);
                            current_subset.push_back(current_subset_each);
                        }
                    }
                }

                // STEP2, udpate the last_sub
                //        copy data from "current_sub" to "last_sub"
                last_subset = current_subset;
                
                // STEP3, update the result content
                for (size_t i = 0; i < last_subset.size(); i++)
                {
                    auto tmp_sub = last_subset[i];
                    result.push_back(tmp_sub);
                }

                // because already update the last_sub, so need update the finalsize in order to break loop immediately
                finalsize = (last_subset.end() - 1)->size();
                // printf("<LOOP-END>The size of last element in last_subset is %d\n", finalsize);
                
            }while(finalsize < nums.size());

            return result;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Subsets, Algorithm(Backtracking)!\n";

    cout << "https://leetcode.com/problems/insertion-sort-list/" << endl << endl;
    // cout << "solution: https://https://hackmd.io/@Zero871015/LeetCode-237/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: nums = [1,2,3]\n");
    printf("expected result: output = [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]\n");
    {
        vector<int> nums{1,2,3};

        Solution solution;
        auto result = solution.subsets(nums);

        printf("Subsets: >>>>> \n");
        for (size_t i = 0; i < result.size(); i++)
        {
            if (result[i].size() == 0)
            {
                printf("NULL");
            }
            else{
                for (size_t j = 0; j < result[i].size(); j++)
                {
                    printf("%d,", result[i][j]);
                }
            }
            printf("\n");
        }
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: nums = [0]\n");
    printf("expected result: output = [[],[0]]\n");
    {
        vector<int> nums{0};

        Solution solution;
        auto result = solution.subsets(nums);

        printf("Subsets: >>>>> \n");
        for (size_t i = 0; i < result.size(); i++)
        {
            if (result[i].size() == 0)
            {
                printf("NULL");
            }
            else{
                for (size_t j = 0; j < result[i].size(); j++)
                {
                    printf("%d,", result[i][j]);
                }
            }
            printf("\n");
        }
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: nums = [5,2,3,1]\n");
    printf("expected result: output = [[],[1],[2],[3],[5],[1,2],[1,3],[1,5],[2,3],[2,5],[3,5],[1,2,3],[1,2,5],[1,3,5],[2,3,5],[1,2,3,5]]\n");
    {
        vector<int> nums{5,2,3,1};

        Solution solution;
        auto result = solution.subsets(nums);

        printf("Subsets: >>>>> \n");
        for (size_t i = 0; i < result.size(); i++)
        {
            if (result[i].size() == 0)
            {
                printf("NULL");
            }
            else{
                for (size_t j = 0; j < result[i].size(); j++)
                {
                    printf("%d,", result[i][j]);
                }
            }
            printf("\n");
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
