// ConsoleApplication_MajorityElement.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution{
public:
    int majorityElement(vector<int> &nums){

        sort(nums.begin(), nums.end());
        
        // printf("after sorting ----- \n");
        // for (size_t i = 0; i < nums.size(); i++)
        // {
        //     printf("nums[%d] = %d\n", i, nums[i]);
        // }
    
        int Count = 0;
        int MaxCount = 0;
        int Content = nums[0];
        map<int, int> Count_Content;
        int Result = 0;

        for (size_t i = 0; i < nums.size(); i++)
        {
            if( nums[i] > Content ){
                Count_Content.insert(pair<int, int>(Count, Content));
                // record max-count till now
                if(Count > MaxCount)
                    MaxCount = Count;
                // re-direct to the next content
                Count = 1;
                Content = nums[i];
            }else{
                Count++;
            }
        }
        Count_Content.insert(pair<int, int>(Count, Content));
        // record max-count till now
        if(Count > MaxCount)
            MaxCount = Count;
        
        Result = (Count_Content.find(MaxCount))->second;
        
        return Result;
    }
};

int main()
{
    std::cout << "Hello LeetCode - Majority Element, DataStructure (HASH TABLE)!\n";

    printf("LeetCode - 169. Majority Element\n");
    cout << "https://leetcode.com/problems/majority-element/" << endl << endl;
    // cout << "solution: https://blog.techbridge.cc/2017/01/21/simple-hash-table-intro/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: nums = [3, 2, 3]\n");
    printf("expected result: 3\n");
    {
        vector<int> nums{3, 2, 3};

        Solution Solution_cs;
        auto Result = Solution_cs.majorityElement(nums);
        printf("Result value is %d\n", Result);

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: nums = [2, 2, 1, 1, 1, 2, 2]\n");
    printf("expected result: 2\n");
    {
        vector<int> nums{2, 2, 1, 1, 1, 2, 2};

        Solution Solution_cs;
        auto Result = Solution_cs.majorityElement(nums);
        printf("Result value is %d\n", Result);

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
