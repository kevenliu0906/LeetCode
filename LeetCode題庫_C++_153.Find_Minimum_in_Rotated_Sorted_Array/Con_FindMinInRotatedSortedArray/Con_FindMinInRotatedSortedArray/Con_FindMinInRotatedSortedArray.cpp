// Con_FindMinInRotatedSortedArray.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {

        // solution 0 (best)
        {
            int leftIndex = 0;
            int rightIndex = nums.size()-1;
            int minimum_value = nums[0];
            while (leftIndex <= rightIndex)
            {
                int mid = leftIndex + (rightIndex - leftIndex)/2;
                // minimum_value = (nums[mid] < minimum_value)? nums[mid] : minimum_value;
                minimum_value = std::min(minimum_value, nums[mid]);
                if ( nums[mid] < nums[rightIndex] ){
                    rightIndex = mid - 1;   // shift the mid to left-side(move to smaller side, because need to find the smallest value)
                }else{
                    leftIndex = mid + 1;    // shift the mid to right-side(move to smaller side, because need to find the smallest value)
                }
            }
            return minimum_value;
        }

        // solution 1 (keven, use sort function in algorithm)
        {
            sort(nums.begin(), nums.end());

            return nums[0];
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Find Minimum in Rotated Sorted Array!\n";
    cout << "https://leetcode.com/problems/find-minimum-in-rotated-sorted-array" << endl << endl;
    // cout << "solution: https://www.geeksforgeeks.org/count-ways-reach-nth-stair/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: nums = [3,4,5,1,2]\n");
    printf("expected result: output = 1\n");
    {
        vector<int> nums{3,4,5,1,2};
        
        Solution solution;
        auto result = solution.findMin(nums);
        printf("result:%d\n", result);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: nums = [4,5,6,7,0,1,2]\n");
    printf("expected result: output = 0\n");
    {
        vector<int> nums{4,5,6,7,0,1,2};
        
        Solution solution;
        auto result = solution.findMin(nums);
        printf("result:%d\n", result);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: nums = [11,13,15,17]\n");
    printf("expected result: output = 11\n");
    {
        vector<int> nums{11,13,15,17};
        
        Solution solution;
        auto result = solution.findMin(nums);
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
