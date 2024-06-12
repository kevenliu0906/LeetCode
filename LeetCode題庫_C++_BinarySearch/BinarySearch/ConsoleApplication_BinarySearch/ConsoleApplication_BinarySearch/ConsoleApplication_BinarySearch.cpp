// ConsoleApplication_BinarySearch.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        int search(vector<int>& nums, int target) {        
            int left = 0;
            int right = nums.size() - 1;
            int loopCount = 0;
            while( left <= right ){
                loopCount++;
                int mid = left + (right - left)/2;
                printf("current_loop:%d, left:%d, right:%d, mid:%d\n", loopCount, left, right, mid);
                if( target == nums[mid] )
                    return mid;
                else if( target > nums[mid])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            return -1;
        }
};


int main()
{
    std::cout << "Hello LeetCode - BinarySearch !\n";

    printf("****************************************\n");
    // Input: nums:[-1, 0, 3, 5, 9, 12], target:9
    // Output: 4
    printf("test case 1, input nums:[-1, 0, 3, 5, 9, 12], target:9\n");
    vector<int> nums{-1, 0, 3, 5, 9, 12};
    int target = 9;
    Solution _Solution;
    auto res = _Solution.search(nums, target);
    printf("input nums:");
    for (size_t i = 0; i < nums.size(); i++)
    {
        printf("%d, ", nums[i]);
    }
    printf("\n");
    printf("target:%d\n", target);
    printf("\n");

    printf("Binary Search Index is %d\n", res);
    printf("****************************************\n");

    printf("\n\n");

    printf("****************************************\n");
    // Input: nums:[-1, 0, 3, 5, 9, 12], target:2
    // Output: -1
    printf("test case 2, input nums:[-1, 0, 3, 5, 9, 12], target:2\n");
    vector<int> nums1{ -1, 0, 3, 5, 9, 12 };
    int target1 = 2;
    Solution _Solution1;
    auto res1 = _Solution1.search(nums1, target1);
    printf("input nums:");
    for (size_t i = 0; i < nums1.size(); i++)
    {
        printf("%d, ", nums1[i]);
    }
    printf("\n");
    printf("target:%d\n", target1);
    printf("\n");

    printf("Binary Search Index is %d\n", res1);
    printf("****************************************\n");

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
