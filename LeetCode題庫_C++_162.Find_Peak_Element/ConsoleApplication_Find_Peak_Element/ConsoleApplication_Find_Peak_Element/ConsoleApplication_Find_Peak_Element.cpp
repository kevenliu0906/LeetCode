// ConsoleApplication_Find_Peak_Element.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // solution 0 (reference others, best, using binary search to solve)
        {
            int left = 0, right = nums.size() - 1;
        
            while (left < right) {
                int mid = left + (right - left) / 2;   // remember, in this judgement, this will always "left <= mid < right"
                                                       // so the mid-1 maybe could not exist, just need judge the "mid & mid+1"
                
                if (nums[mid] > nums[mid + 1]) {
                    // If mid is greater than the next element, the peak is on the left side (including mid)
                    right = mid;       // because the target is to find peak, so need to cover the bigger value(that's mid in this case)
                } else {
                    // If mid is less than the next element, the peak is on the right side
                    left = mid + 1;    // because the target is to find peak, so don't need to cover smallar value(that's mid in this case)
                }
            }
            
            // When left == right, we've found a peak element
            return left;
        }

        // solution 1 (keven, using binary search to solve it)
        {
            int leftIndex = 0;
            int rightIndex = nums.size() - 1;

            while (leftIndex <= rightIndex)
            {
                static int count = 0;
                count++;

                int midIndex = leftIndex + (rightIndex - leftIndex)/2;
                bool mid_bigger_before = false;
                bool mid_bigger_next = false;
                // printf("count:%d, leftIndex:%d, rightIndex:%d, midIndex:%d\n", 
                //         count, 
                //         leftIndex, 
                //         rightIndex,
                //         midIndex);
                if (leftIndex == rightIndex)
                {
                    return leftIndex;
                }
                else if (rightIndex - leftIndex == 1)
                {
                    return nums[leftIndex] > nums[rightIndex] ? leftIndex : rightIndex ;
                }


                if (nums[midIndex] > nums[midIndex - 1])
                {
                    mid_bigger_before = true;
                }
                if (nums[midIndex] > nums[midIndex + 1])
                {
                    mid_bigger_next = true;
                }
                
                if (mid_bigger_before && mid_bigger_next)
                {
                    // FOUND it!!!
                    return midIndex;
                }
                if (mid_bigger_before && !mid_bigger_next)
                {
                    leftIndex = midIndex + 1;
                }
                if (!mid_bigger_before && mid_bigger_next)
                {
                    rightIndex = midIndex - 1;
                }
                if (!mid_bigger_before && !mid_bigger_next)
                {
                    leftIndex = midIndex + 1;
                }

            }
            
            return -1;
        }
        // return 0;
    }
};

int main()
{
    std::cout << "Hello LeetCode - Find Peak Element, Algorithm(Binary Search)!\n";
    cout << "https://leetcode.com/problems/find-peak-element/" << endl << endl;
    // cout << "solution: https://https://hackmd.io/@Zero871015/LeetCode-237/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: nums = [1,2,3,1]\n");
    printf("expected result: output = 2\n");
    {
        vector<int> nums{1,2,3,1};
        Solution solution;

        auto result = solution.findPeakElement(nums);
        printf("find peak element index:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: nums = [1,2,1,3,5,6,4]\n");
    printf("expected result: output = 5\n");
    {
        vector<int> nums{1,2,1,3,5,6,4};
        Solution solution;

        auto result = solution.findPeakElement(nums);
        printf("find peak element index:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: nums = [2]\n");
    printf("expected result: output = 0\n");
    {
        vector<int> nums{2};
        Solution solution;

        auto result = solution.findPeakElement(nums);
        printf("find peak element index:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: nums = [2,6]\n");
    printf("expected result: output = 1\n");
    {
        vector<int> nums{2,6};
        Solution solution;

        auto result = solution.findPeakElement(nums);
        printf("find peak element index:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 5 ****************************\n");
    printf("input: nums = [8,6,3,4,2]\n");
    printf("expected result: output = 0 or 3\n");
    {
        vector<int> nums{8,6,3,4,2};
        Solution solution;

        auto result = solution.findPeakElement(nums);
        printf("find peak element index:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 6 ****************************\n");
    printf("input: nums = [6,5,4,3,2,3,2]\n");
    printf("expected result: output = 0 or 5\n");
    {
        vector<int> nums{6,5,4,3,2,3,2};
        Solution solution;

        auto result = solution.findPeakElement(nums);
        printf("find peak element index:%d\n", result);
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
