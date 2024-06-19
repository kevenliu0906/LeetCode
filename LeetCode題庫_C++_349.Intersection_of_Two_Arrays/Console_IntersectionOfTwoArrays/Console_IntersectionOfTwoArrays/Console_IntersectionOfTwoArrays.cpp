// Console_IntersectionOfTwoArrays.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2){
        // step1, put all the elements from nums1 into the "unordered_set" container
        // "unordered_set" feature - the element in "unordered_set" will be unique, NOT repeat and unordered.
        // "set" feature - the element in "set" will be ordered.
        unordered_set<int> total(nums1.begin(), nums1.end());
        unordered_set<int> repeat;
        
        vector<int> result;
        
        for (auto num2 : nums2)
        {
            // step2, 
            // check if all the elements within nums2 are existed in set(announce in step1) or NOT 
            if (total.find(num2) != total.end() )
            {
                repeat.insert(num2);
            }
        }

        result = vector<int>(repeat.begin(), repeat.end());

        return result;
    }
};

int main()
{
    std::cout << "Hello LeedCode - Intersection of Two Arrays - DataStructure (Set) !\n";

    printf("LeetCode - 349. Intersection of Two Arrays\n");
    cout << "https://leetcode.com/problems/intersection-of-two-arrays/" << endl << endl;
    cout << "solution: https://www.cnblogs.com/grandyang/p/5507129.html/" << endl;
    cout << "technique - unordered_set introduction" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: nums1=[1, 2, 2, 1], nums2=[2, 2]\n");
    printf("expected result: [2]\n");
    {
        vector<int> num1s{ 1, 2, 2, 1 };
        vector<int> num2s{ 2, 2 };
        Solution Solution_cs;
        auto Result = Solution_cs.intersection(num1s, num2s);
        printf("Result size is %d\n", Result.size());
        for (size_t i = 0; i < Result.size(); i++)
        {
            printf("Result[%d]=%d\n", i, Result[i]);
        }
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: nums1=[4, 9, 5], nums2=[9, 4, 9, 8, 4]\n");
    printf("expected result: [9, 4]\n");
    {
        vector<int> num1s{ 4, 9, 5 };
        vector<int> num2s{ 9, 4, 9, 8, 4 };
        Solution Solution_cs;
        auto Result = Solution_cs.intersection(num1s, num2s);
        printf("Result size is %d\n", Result.size());
        for (size_t i = 0; i < Result.size(); i++)
        {
            printf("Result[%d]=%d\n", i, Result[i]);
        }
    }
    printf("*****************************************************\n");
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
