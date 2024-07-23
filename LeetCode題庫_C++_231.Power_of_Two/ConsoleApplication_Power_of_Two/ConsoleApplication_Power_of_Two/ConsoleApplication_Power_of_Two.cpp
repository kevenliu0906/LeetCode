// ConsoleApplication_Power_of_Two.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {

        // solution 0 (keven, best)
        {
            if(n==0)
                return false;
            else if(n==1)
                return true;
            else{
                if( n % 2 )
                    return false;
                else
                    return isPowerOfTwo(n/2);
            }
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Power of Two, Algorithm(Bit Manipulation, Recursion)!\n";
    cout << "https://leetcode.com/problems/power-of-two/" << endl << endl;
    // cout << "solution: https://haogroot.com/2021/02/28/bit-manipulation_leetcode/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: nums = 1\n");
    printf("expected result: output = true\n");
    {
        int n = 1;
        
        Solution solution;
        auto result = solution.isPowerOfTwo(n);
        printf("result:%d\n", result);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: nums = 16\n");
    printf("expected result: output = true\n");
    {
        int n = 16;
        
        Solution solution;
        auto result = solution.isPowerOfTwo(n);
        printf("result:%d\n", result);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: nums = 3\n");
    printf("expected result: output = false\n");
    {
        int n = 3;
        
        Solution solution;
        auto result = solution.isPowerOfTwo(n);
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
