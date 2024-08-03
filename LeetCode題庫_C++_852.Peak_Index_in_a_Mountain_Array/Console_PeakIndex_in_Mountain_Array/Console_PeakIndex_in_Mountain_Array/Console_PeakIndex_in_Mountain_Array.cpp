// Console_PeakIndex_in_Mountain_Array.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        // solution 0 (keven, best, using binary search)
        {
            int leftIndex = 0;
            int rightIndex = arr.size() - 1;
            while (rightIndex - leftIndex >= 2)
            {
                int midIndex = leftIndex + (rightIndex - leftIndex)/2;
                if (arr[midIndex] - arr[midIndex-1] > 0)
                {
                    // represent the left-side is lower side, so consider the right-side
                    leftIndex = midIndex;
                }
                else {
                    rightIndex = midIndex-1;
                }
            }

            if (arr[leftIndex] > arr[rightIndex])
            {
                return leftIndex;
            }else{
                return rightIndex;
            }
            
            
        }

        // solution 1 (keven, using HASH TABLE to solve)
        {
            multimap<int,int> peak_value_index_multimap;   // key: element_value, value: element_index
            for (size_t i = 0; i < arr.size(); i++)
            {
                auto value = arr[i];
                peak_value_index_multimap.insert(pair<int,int>(value,i));
            }
            
            auto last_element = peak_value_index_multimap.rbegin();
            // printf("last element, key:%d, value:%d\n", last_element->first, last_element->second);
            return last_element->second;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Peak Index in a Mountain Array, Algorithm(Binary Search)!\n";
    cout << "https://leetcode.com/problems/peak-index-in-a-mountain-array/" << endl << endl;
    // cout << "solution: https://https://hackmd.io/@Zero871015/LeetCode-237/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: arr = [0,1,0]\n");
    printf("expected result: output = 1\n");
    {
        vector<int> arr{0, 1, 0};

        Solution solution;
        auto result = solution.peakIndexInMountainArray(arr);
        printf("Peak index is:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: arr = [0,2,1,0]\n");
    printf("expected result: output = 1\n");
    {
        vector<int> arr{0, 2, 1, 0};

        Solution solution;
        auto result = solution.peakIndexInMountainArray(arr);
        printf("Peak index is:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: arr = [0,10,5,2]\n");
    printf("expected result: output = 1\n");
    {
        vector<int> arr{0, 10, 5, 2};

        Solution solution;
        auto result = solution.peakIndexInMountainArray(arr);
        printf("Peak index is:%d\n", result);
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
