// Console_Find_the_Duplicated_Num.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    int findDuplicate(vector<int>& nums) {
        
        int duplicated_num = 0;

        // solution 1(best)
        {
            int nSize = nums.size();
            vector<int> num_count(nSize, 0);
            for (size_t i = 0; i < nSize; i++)
            {
                num_count[nums[i]]++;
            }
            // for (size_t i = 0; i < num_count.size(); i++)
            // {
            //     printf("num_count[%d]=%d\n", i, num_count[i]);
            // }
            for (size_t i = 0; i < num_count.size(); i++)
            {
                if( num_count[i] > 1 )
                    return i;
            }
            
            
            return -1;
        }
        
        // // solution 2(keven)
        // {
        //     unordered_map<int, int> num_count_unordered_map;
            
        //     for (size_t i = 0; i < nums.size(); i++)
        //     {
        //         if( num_count_unordered_map.count( nums[i] ) == 0 ){
        //             num_count_unordered_map.insert(pair<int, int>( nums[i], 1 ));
        //         }else{
        //             duplicated_num = nums[i];
        //             break;
        //         }
        //     }
            
        //     return duplicated_num;
        // }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Find the Duplicated Number, Algorithm(Binary Search, Array)!\n";
    printf("LeetCode - 287. Find the Duplicated Number\n");
    cout << "https://leetcode.com/problems/find-the-duplicate-number" << endl << endl;
    // cout << "solution: https://mocowcow.github.io/leetcode-222-count-complete-tree-nodes/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: nums = [1, 3, 4, 2, 2]\n");
    printf("expected result: output = 2\n");
    {
        vector<int> nums{1, 3, 4, 2, 2};  
        Solution solution;
        auto result = solution.findDuplicate(nums);
        printf("Result:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: nums = [3, 1, 3, 4, 2]\n");
    printf("expected result: output = 3\n");
    {
        vector<int> nums{3, 1, 3, 4, 2};  
        Solution solution;
        auto result = solution.findDuplicate(nums);
        printf("Result:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: nums = [3, 3, 3, 3, 3]\n");
    printf("expected result: output = 3\n");
    {
        vector<int> nums{3, 3, 3, 3, 3};  
        Solution solution;
        auto result = solution.findDuplicate(nums);
        printf("Result:%d\n", result);
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
