// ConsoleApplication_Move_Zeroes.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution{
public:
    void moveZeroes(vector<int>& nums) {

        // solution 00 (keven, best)
        {
            int checkIndex = 0;
            int swapIndex = 0;
            while ( checkIndex < nums.size() - 1 ){
                if (nums[checkIndex] == 0)
                {
                    if (!swapIndex)  // represent search 1st 0 element and move it.
                    {
                        swapIndex = checkIndex + 1;
                    }
                    while ( swapIndex < nums.size() )
                    {
                        // printf("checkIndex:%d, swapIndex:%d\n", checkIndex, swapIndex);
                        if (nums[swapIndex] != 0)
                        {
                            // printf("(swap before) checkIndex:%d, nums[checkIndex]:%d, swapIndex:%d, nums[swapIndex]:%d\n", checkIndex, nums[checkIndex], swapIndex, nums[swapIndex]);
                            // swap two element
                            int tmp = nums[checkIndex];
                            nums[checkIndex] = nums[swapIndex];
                            nums[swapIndex] = tmp;
                            // 
                            swapIndex++;
                            // printf("(swap after) checkIndex:%d, nums[checkIndex]:%d, swapIndex:%d, nums[swapIndex]:%d\n", checkIndex, nums[checkIndex], swapIndex, nums[swapIndex]);
                            break;
                        }
                        
                        swapIndex++;
                    } 
                }
                
                checkIndex++;
            }
            return;
        }

        // solution 0 (keven)
        {
            int targetZeroPutIndex = nums.size() - 1;   // put the last 1 element
            for (int checkIndex = nums.size() - 1; checkIndex >= 0; checkIndex--)
            {
                // move the element value = 0 to the last element
                if (nums[checkIndex] == 0)
                {
                    // printf("nums[%d]:%d\n", checkIndex, nums[checkIndex]);
                    int currentIndex = checkIndex;
                    while (currentIndex != targetZeroPutIndex)
                    {
                        // printf("before swap, targetZeroPutIndex:%d, nums[%d]:%d, nums_next[%d]:%d\n", targetZeroPutIndex, currentIndex, nums[currentIndex], currentIndex+1, nums[currentIndex+1]);
                        // swap the zero to the next element
                        int tmp = nums[currentIndex];
                        nums[currentIndex] = nums[currentIndex+1];
                        nums[currentIndex+1] = tmp;
                        // 
                        // printf("after swap, targetZeroPutIndex:%d, nums[%d]:%d, nums_next[%d]:%d\n", targetZeroPutIndex, currentIndex, nums[currentIndex], currentIndex+1, nums[currentIndex+1]);
                        currentIndex++;
                    }
                    targetZeroPutIndex--;  // put the last 2 element
                    // break;
                }
            }
            
            return;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Move Zeroes, Algorithm(Two Pointer)!\n";
    cout << "https://leetcode.com/problems/move-zeroes" << endl << endl;
    // cout << "solution: https://www.geeksforgeeks.org/count-ways-reach-nth-stair/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: nums = [0,1,0,3,12]\n");
    printf("expected result: output = [1,3,12,0,0]\n");
    {
        vector<int> nums{0,1,0,3,12};
        
        Solution solution;
        solution.moveZeroes(nums);
        printf("(AFTER moving) nums size:%d\n", nums.size());
        for (size_t i = 0; i < nums.size(); i++)
        {
            printf("nums[%d]:%d\n", i, nums[i]);
        }
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: nums = [0]\n");
    printf("expected result: output = [0]\n");
    {
        vector<int> nums{0};
        
        Solution solution;
        solution.moveZeroes(nums);
        printf("(AFTER moving) nums size:%d\n", nums.size());
        for (size_t i = 0; i < nums.size(); i++)
        {
            printf("nums[%d]:%d\n", i, nums[i]);
        }
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: nums = [0,1,0,3]\n");
    printf("expected result: output = [1,3,0,0]\n");
    {
        vector<int> nums{ 0,1,0,3 };

        Solution solution;
        solution.moveZeroes(nums);
        printf("(AFTER moving) nums size:%d\n", nums.size());
        for (size_t i = 0; i < nums.size(); i++)
        {
            printf("nums[%d]:%d\n", i, nums[i]);
        }

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: nums = [0, 0, 0, 1]\n");
    printf("expected result: output = [1, 0, 0, 0]\n");
    {
        vector<int> nums{0, 0, 0, 1};
        
        Solution solution;
        solution.moveZeroes(nums);
        printf("(AFTER moving) nums size:%d\n", nums.size());
        for (size_t i = 0; i < nums.size(); i++)
        {
            printf("nums[%d]:%d\n", i, nums[i]);
        }
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 5 ****************************\n");
    printf("input: nums = [0, 2, 0, 1, 0]\n");
    printf("expected result: output = [2, 1, 0, 0, 0]\n");
    {
        vector<int> nums{ 0, 2, 0, 1, 0 };

        Solution solution;
        solution.moveZeroes(nums);
        printf("(AFTER moving) nums size:%d\n", nums.size());
        for (size_t i = 0; i < nums.size(); i++)
        {
            printf("nums[%d]:%d\n", i, nums[i]);
        }

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 6 ****************************\n");
    printf("input: nums = [3, 2, 5, 1, 6]\n");
    printf("expected result: output = [3, 2, 5, 1, 6]\n");
    {
        vector<int> nums{ 3, 2, 5, 1, 6 };

        Solution solution;
        solution.moveZeroes(nums);
        printf("(AFTER moving) nums size:%d\n", nums.size());
        for (size_t i = 0; i < nums.size(); i++)
        {
            printf("nums[%d]:%d\n", i, nums[i]);
        }

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 7 ****************************\n");
    printf("input: nums = [4,2,4,0,0,3,0,5,1,0]\n");
    printf("expected result: output = [4,2,4,3,5,1,0,0,0,0]\n");
    {
        vector<int> nums{ 4, 2, 4, 0, 0, 3, 0, 5, 1, 0 };

        Solution solution;
        solution.moveZeroes(nums);
        printf("(AFTER moving) nums size:%d\n", nums.size());
        for (size_t i = 0; i < nums.size(); i++)
        {
            printf("nums[%d]:%d\n", i, nums[i]);
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
