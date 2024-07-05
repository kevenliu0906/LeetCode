// Console_Search_in_RotatedSortedArray.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution{
public:
    int search(vector<int> &nums, int target){
        
        // // solution 1 (keven, have bug)
        // { 
        //     int left = 0;
        //     int right = nums.size() - 1;
            
        //     printf("left:%d, right:%d\n", left, right);
        //     while(left <= right){
        //         int mid = left + (right - left) / 2;
        //         printf("In-Loop, left:%d, right:%d, mid:%d, nums[mid]:%d, target:%d\n", left, right, mid, nums[mid], target);
        //         if( target == nums[mid] )
        //             return mid;
        //         else if( target < nums[mid] && target >= nums[left] )  // represent target is on the part of "ascending order"
        //             right = mid - 1;
        //         else /*if( target > nums[mid] && target <= nums[right] )*/{  // represent target is on the part of "pivot"
        //             left = mid + 1;
        //         }
        //     }
        //     printf("End-Loop(means there is no exist num with target value), left:%d, right:%d\n", left, right);

        //     return -1;
        // }

        // solution 2 (keven, best)
        {
            int searchIndex = -1;
            map<int, int> nums_num_index_map;
            for (size_t i = 0; i < nums.size(); i++)
            {
                nums_num_index_map.insert(pair<int, int>(nums[i], i));
            }
            
            if( nums_num_index_map.count(target) )
                searchIndex = nums_num_index_map[target];

            return searchIndex;
        }

    }
};

int main()
{
    std::cout << "Hello LeetCode - Search in Rotated Sorted Array, Algorithm (Binary Search, Array)!\n";

    printf("LeetCode - 33. Search in Rotated Sorted Array\n");
    cout << "https://leetcode.com/problems/search-in-rotated-sorted-array" << endl << endl;
    // cout << "solution: https://medium.com/@zero.ling/c-sort-a-map-by-value-601a60ec0e01" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: nums = [4, 5, 6, 7, 0, 1, 2], target = 0\n");
    printf("expected result: 4\n");
    {

        Solution solution;
        vector<int> nums{4, 5, 6, 7, 0, 1, 2};
        int target = 0;
        
        auto counts = solution.search(nums, target);
        printf("Result:%d\n", counts);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: nums = [4, 5, 6, 7, 0, 1, 2], target = 3\n");
    printf("expected result: -1\n");
    {

        Solution solution;
        vector<int> nums{4, 5, 6, 7, 0, 1, 2};
        int target = 3;
        
        auto counts = solution.search(nums, target);
        printf("Result:%d\n", counts);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: nums = [1], target = 0\n");
    printf("expected result: -1\n");
    {

        Solution solution;
        vector<int> nums{1};
        int target = 0;
        
        auto counts = solution.search(nums, target);
        printf("Result:%d\n", counts);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: nums = [5, 1, 3], target = 5\n");
    printf("expected result: 0\n");
    {

        Solution solution;
        vector<int> nums{5, 1, 3};
        int target = 5;
        
        auto counts = solution.search(nums, target);
        printf("Result:%d\n", counts);
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
