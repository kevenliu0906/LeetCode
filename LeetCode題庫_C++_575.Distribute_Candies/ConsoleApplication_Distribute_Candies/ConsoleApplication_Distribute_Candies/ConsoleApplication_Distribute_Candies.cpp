// ConsoleApplication_Distribute_Candies.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <set>

using namespace std;

class Solution{
public:
    int distributeCandies(vector<int> &candyType){

        int result = 0;

        // solution 1 (keven)
        set<int> candyType_set(candyType.begin(), candyType.end());

        if( candyType.size()/2 >= candyType_set.size() )
            result = candyType_set.size();
        else
            result = candyType.size()/2;

        return result;
    }
};

int main()
{
    std::cout << "Hello LeetCode - Distribute Candies, DataStructure (HASH TABLE, Array)!\n";

    printf("LeetCode - 575. Distribute Candies\n");
    cout << "https://leetcode.com/problems/distribute-candies/" << endl << endl;
    // cout << "solution: https://medium.com/@zero.ling/c-sort-a-map-by-value-601a60ec0e01" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: candyType = [1, 1, 2, 2, 3, 3]\n");
    printf("expected result: 3\n");
    {
        vector<int> candyType = {1, 1, 2, 2, 3, 3};

        Solution Solution_cs;
        auto Result = Solution_cs.distributeCandies(candyType);

        printf("Result value size is %d, true=%d, false=%d\n", Result, true, false);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: candyType = [1, 1, 2, 3]\n");
    printf("expected result: 2\n");
    {
        vector<int> candyType = {1, 1, 2, 3};

        Solution Solution_cs;
        auto Result = Solution_cs.distributeCandies(candyType);

        printf("Result value size is %d, true=%d, false=%d\n", Result, true, false);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: candyType = [6, 6, 6, 6]\n");
    printf("expected result: 1\n");
    {
        vector<int> candyType = {6, 6, 6, 6};

        Solution Solution_cs;
        auto Result = Solution_cs.distributeCandies(candyType);

        printf("Result value size is %d, true=%d, false=%d\n", Result, true, false);
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
