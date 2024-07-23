// ConsoleApplication_SingleNumber.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
// #include <map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        // solution 0 (best, using bit manipulation)
        {
            int Single = 0;
            for (size_t i = 0; i < nums.size(); i++)
            {
                Single = Single ^ nums[i];   // the nums[i] value will lost when appear twice
            }
            return Single;
        }

        // solution 1 (keven, using HASH TABLE)
        {
            unordered_set<int> nums_value_unordered_set;
            // multimap<int, int> nums_value_index_multimap;
            for (size_t i = 0; i < nums.size(); i++)
            {
                auto iter = nums_value_unordered_set.find(nums[i]);
                if ( iter == nums_value_unordered_set.end() )
                    nums_value_unordered_set.insert(nums[i]);
                else
                    nums_value_unordered_set.erase(iter);

                // auto iter = nums_value_index_multimap.find(nums[i]);
                // if (iter == nums_value_index_multimap.end()){
                //     nums_value_index_multimap.insert(pair<int, int>(nums[i], i));
                // }
                // else{
                //     nums_value_index_multimap.erase(iter);
                // }
            }

            // printf("rest value:%d\n", *nums_value_unordered_set.begin());

            // printf("rest value:%d\n", nums_value_index_multimap.begin()->first);
            
            return *nums_value_unordered_set.begin();
            
            // return nums_value_index_multimap.begin()->first;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Single Number, Algorithm(Bit Manipulation)!\n";
    cout << "https://leetcode.com/problems/single-number" << endl << endl;
    // cout << "solution: https://haogroot.com/2021/02/28/bit-manipulation_leetcode/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: nums = [2,2,1]\n");
    printf("expected result: output = 1\n");
    {
        vector<int> nums{2,2,1};
        
        Solution solution;
        auto result = solution.singleNumber(nums);
        printf("result:%d\n", result);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: nums = [4,1,2,1,2]\n");
    printf("expected result: output = 4\n");
    {
        vector<int> nums{4,1,2,1,2};
        
        Solution solution;
        auto result = solution.singleNumber(nums);
        printf("result:%d\n", result);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: nums = [1]\n");
    printf("expected result: output = 1\n");
    {
        vector<int> nums{1};
        
        Solution solution;
        auto result = solution.singleNumber(nums);
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
