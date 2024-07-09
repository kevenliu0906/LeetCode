// Console_SingleElementInSortedArray.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int singleNonDuplicate(vector<int>& nums) {

        // because there is 'a' single Non duplicat, so nums.size() must be odd
        int left = 0;
        int right = nums.size() - 1;

        // solution 1 (keven, best)
        {
            while(left <= right){
                if( left == right )
                    return nums[left];
                else{
                    int mid = left + (right - left)/2;
                    if( right - left == 2 ){  // represent these only 3 num exist 
                        if( nums[mid] != nums[left] )
                            return nums[left];
                        else if( nums[mid] != nums[right] )
                            return nums[right];
                    }else{
                        if( (nums[mid] != nums[mid-1]) && (nums[mid] != nums[mid+1]) )
                            return nums[mid];

                        if( mid % 2 == 0 ){   // represent there are even counts number before mid
                            if( nums[mid] == nums[mid-1] ){
                                // represent left-side exist non-duplicated num
                                right = mid - 2;  // (mid-1) has already considered, so remove these item
                            }
                            else{
                                // represent right-side exist non-duplicated num
                                left = mid + 2;   // (mid+1) has already considered, so remove these item
                            }
                        }
                        else{                 // represent there are odd counts number before mid
                            if( nums[mid] == nums[mid-1] )
                                left = mid + 1;
                            else
                                right = mid - 1;
                        }
                    }
                }
            }
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Single Element In Sorted Array, Algorithm ( Binary Search )!\n";
    printf("LeetCode - 540. Single Element in Sorted Array\n");
    cout << "https://leetcode.com/problems/single-element-in-a-sorted-array" << endl << endl;
    cout << "solution: https://hackmd.io/@meyr543/ryUhMY4zY" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: l1 = [1, 1, 2, 3, 3, 4, 4, 8, 8]\n");
    printf("expected result: output = 2\n");
    {
        
        vector<int> nums{1, 1, 2, 3, 3, 4, 4, 8, 8};
        Solution solution;
        auto result = solution.singleNonDuplicate(nums);
        printf("result:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: l1 = [1]\n");
    printf("expected result: output = 1\n");
    {

        vector<int> nums{ 1 };
        Solution solution;
        auto result = solution.singleNonDuplicate(nums);
        printf("result:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: l1 = [1, 2, 2, 3, 3]\n");
    printf("expected result: output = 1\n");
    {

        vector<int> nums{ 1, 2, 2, 3, 3 };
        Solution solution;
        auto result = solution.singleNonDuplicate(nums);
        printf("result:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: l1 = [1, 1, 2, 3, 3]\n");
    printf("expected result: output = 2\n");
    {

        vector<int> nums{ 1, 1, 2, 3, 3 };
        Solution solution;
        auto result = solution.singleNonDuplicate(nums);
        printf("result:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 5 ****************************\n");
    printf("input: l1 = [1, 1, 2, 2, 3]\n");
    printf("expected result: output = 3\n");
    {

        vector<int> nums{ 1, 1, 2, 2, 3 };
        Solution solution;
        auto result = solution.singleNonDuplicate(nums);
        printf("result:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 6 ****************************\n");
    printf("input: l1 = [3, 3, 7, 7, 10, 11, 11]\n");
    printf("expected result: output = 10\n");
    {

        vector<int> nums{ 3, 3, 7, 7, 10, 11, 11 };
        Solution solution;
        auto result = solution.singleNonDuplicate(nums);
        printf("result:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 7 ****************************\n");
    printf("input: l1 = [1, 1, 2, 2, 3]\n");
    printf("expected result: output = 3\n");
    {

        vector<int> nums{ 1, 1, 2, 2, 3 };
        Solution solution;
        auto result = solution.singleNonDuplicate(nums);
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
