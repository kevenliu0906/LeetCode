// Console_SearchInsertPosition.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int searchInsert(vector<int> nums, int target){
        int ResultIndex = 0;
        int left = 0;
        int right = nums.size() - 1;
        while( left <= right ){
            int mid = left + (right - left)/2;
            // if( target == nums[mid] )
            //     return mid;
            if( target <= nums[mid] )
                right = mid - 1;
            else 
                left = mid + 1;
        }
        ResultIndex = left;
        return ResultIndex;
    }
};


int main()
{
    std::cout << "Hello LeetCode - Search Insert Position!\n";

    printf("****************************************\n");
    // Input: nums:[1, 3, 5, 6], target:5
    // Output: 2
    printf("test case 1, input nums:[1, 3, 5, 6], target:5\n");
    vector<int> nums{ 1, 3, 5, 6 };
    int target = 5;
    Solution _Solution;
    auto res = _Solution.searchInsert(nums, target);
    printf("input nums:");
    for (size_t i = 0; i < nums.size(); i++)
    {
        printf("%d, ", nums[i]);
    }
    printf("\n");
    printf("target:%d\n", target);
    printf("\n");

    printf("Search Insert Position is %d\n", res);
    printf("****************************************\n");

    printf("\n\n");

    printf("****************************************\n");
    // Input: nums:[1, 3, 5, 6], target:2
    // Output: 1
    printf("test case 2, input nums:[1, 3, 5, 6], target:2\n");
    vector<int> nums1{ 1, 3, 5, 6 };
    int target1 = 2;
    Solution _Solution1;
    auto res1 = _Solution1.searchInsert(nums1, target1);
    printf("input nums:");
    for (size_t i = 0; i < nums1.size(); i++)
    {
        printf("%d, ", nums1[i]);
    }
    printf("\n");
    printf("target:%d\n", target1);
    printf("\n");

    printf("Search Insert Position is %d\n", res1);
    printf("****************************************\n");

    printf("\n\n");

    printf("****************************************\n");
    // Input: nums:[1, 3, 5, 6], target:7
    // Output: 4
    printf("test case 3, input nums:[1, 3, 5, 6], target:7\n");
    vector<int> nums2{ 1, 3, 5, 6 };
    int target2 = 7;
    Solution _Solution2;
    auto res2 = _Solution2.searchInsert(nums2, target2);
    printf("input nums:");
    for (size_t i = 0; i < nums2.size(); i++)
    {
        printf("%d, ", nums2[i]);
    }
    printf("\n");
    printf("target:%d\n", target2);
    printf("\n");

    printf("Search Insert Position is %d\n", res2);
    printf("****************************************\n");

    printf("\n\n");

    printf("****************************************\n");
    // Input: nums:[1, 3, 5, 5, 6], target:5 (with repeat num in input array)
    // Output: 4
    printf("test case 4, input nums:[1, 3, 5, 5, 6], target:5 (with repeat num in input array)\n");
    vector<int> nums3{ 1, 3, 5, 5, 6 };
    int target3 = 5;
    Solution _Solution3;
    auto res3 = _Solution3.searchInsert(nums3, target3);
    printf("input nums:");
    for (size_t i = 0; i < nums3.size(); i++)
    {
        printf("%d, ", nums3[i]);
    }
    printf("\n");
    printf("target:%d\n", target3);
    printf("\n");

    printf("Search Insert Position is %d\n", res3);
    printf("****************************************\n");
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
