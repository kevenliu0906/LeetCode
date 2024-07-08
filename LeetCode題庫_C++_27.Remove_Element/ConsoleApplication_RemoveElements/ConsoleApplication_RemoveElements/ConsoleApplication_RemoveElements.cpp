// ConsoleApplication_RemoveElements.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int removeElement(vector<int>& nums, int val) {

        int removeCount = 0;

        // solution (keven, best)
        {
            if ( nums.size() == 0 )
            {
                return removeCount;
            }

            for (size_t i = 0; i < nums.size(); i++)
            {
                if (nums[i] == val)
                {
                    nums[i] = -1;
                    removeCount++;
                }
            }

            sort(nums.begin(), nums.end());

            nums.erase(nums.begin(), nums.begin() + removeCount);

            printf("nums size:%d\n", nums.size());
            for (size_t i = 0; i < nums.size(); i++)
            {
                printf("nums[%d]=%d\n", i, nums[i]);
            }
            
        }

        return nums.size();
    }
};

int main()
{
    std::cout << "Hello LeetCode - Remove Element, Algorithm (Array, Two Pointers)!\n";

    printf("LeetCode - 27. Remove Elements\n");
    cout << "https://leetcode.com/problems/remove-element" << endl << endl;
    // cout << "solution: https://medium.com/@zero.ling/c-sort-a-map-by-value-601a60ec0e01" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: nums = [3, 2, 2, 3], val = 3\n");
    printf("expected result: 2, nums=[2, 2]\n");
    {

        Solution solution;
        vector<int> nums = {3, 2, 2, 3};
        int val = 3;
        
        auto removeElement = solution.removeElement(nums, val);
        printf("Result:%d, true:%d, false:%d\n", removeElement, true, false);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: nums = [0, 1, 2, 2, 3, 0, 4, 2], val = 2\n");
    printf("expected result: 5, nums=[0, 1, 4, 0, 3]\n");
    {

        Solution solution;
        vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
        int val = 2;
        
        auto removeElement = solution.removeElement(nums, val);
        printf("Result:%d, true:%d, false:%d\n", removeElement, true, false);
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
