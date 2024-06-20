// ConsoleApplication_HappyNumber.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>

using namespace std;

class Solution{
public:
    unordered_map<int, int> Record_Step;
    bool isHappy(int n){

        if (n == 1)
            return true;

        int InputNum = n;
        int FinalValue = 0;

        // printf("current call isHappy(n:%d), before while-loop, InputNum:%d, FinalValue:%d\n", n, InputNum, FinalValue);
        // step1: check the origin input n
        do{
            
            int quotiet = InputNum / 10;
            int remainder = InputNum % 10;

            FinalValue += remainder * remainder;
            InputNum = InputNum / 10;

        }while( InputNum > 0);
        // printf("current call isHappy(n:%d), after while-loop, InputNum:%d, FinalValue:%d\n", n, InputNum, FinalValue);

        if( Record_Step.find(n) == Record_Step.end() ){
            // record current input n & result FinalValue
            Record_Step.insert(pair<int, int>(n, FinalValue));
        }else{
            // represent current input occur again, if runing it will cause infinitely loop, 
            // so return false directly.
            return false;
        }

        return isHappy(FinalValue);

    }
};

int main()
{
    std::cout << "Hello LeetCode - Happy Number, DataStructure (HASH TABLE)!\n";

    printf("LeetCode - 202. Happy Number\n");
    cout << "https://leetcode.com/problems/happy-number/" << endl << endl;
    // cout << "solution: https://blog.techbridge.cc/2017/01/21/simple-hash-table-intro/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: n = 19\n");
    printf("expected result: true\n");
    {
        int n = 19;

        Solution Solution_cs;
        auto Result = Solution_cs.isHappy(n);
        printf("Result value is %d, true(%d), false(%d)\n", Result, true, false);

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: n = 2\n");
    printf("expected result: false\n");
    {
        int n = 2;

        Solution Solution_cs;
        auto Result = Solution_cs.isHappy(n);
        printf("Result value is %d, true(%d), false(%d)\n", Result, true, false);

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: n = 14\n");
    printf("expected result: false\n");
    {
        int n = 14;

        Solution Solution_cs;
        auto Result = Solution_cs.isHappy(n);
        printf("Result value is %d, true(%d), false(%d)\n", Result, true, false);

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
