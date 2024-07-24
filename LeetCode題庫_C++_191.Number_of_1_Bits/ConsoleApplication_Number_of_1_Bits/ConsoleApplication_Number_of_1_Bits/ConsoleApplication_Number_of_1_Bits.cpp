// ConsoleApplication_Number_of_1_Bits.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

using namespace std;

class Solution {
public:
    
    int total_1bit_num = 0;

    int hammingWeight(int n) {

        // solution 1 (keven, best)
        {
        if (n == 0 || n == 1){
            total_1bit_num += n;
            return total_1bit_num;
        }else{
            if (n%2)
            {
                total_1bit_num++;
            }
            
            n = n >> 1;
            hammingWeight(n);
        }
        
        return total_1bit_num;

        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Number of 1 Bits, Algorithm(Bit Manipulation, Divide and Conquer)!\n";
    cout << "https://leetcode.com/problems/number-of-1-bits/" << endl << endl;
    // cout << "solution: https://haogroot.com/2021/02/28/bit-manipulation_leetcode/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: nums = 11\n");
    printf("expected result: output = 3\n");
    {
        int n = 11;
        
        Solution solution;
        auto result = solution.hammingWeight(n);
        printf("result:%d\n", result);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: nums = 128\n");
    printf("expected result: output = 1\n");
    {
        int n = 128;
        
        Solution solution;
        auto result = solution.hammingWeight(n);
        printf("result:%d\n", result);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: nums = 2147483645\n");
    printf("expected result: output = 30\n");
    {
        int n = 2147483645;
        
        Solution solution;
        auto result = solution.hammingWeight(n);
        printf("result:%d\n", result);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: nums = 2147483647\n");
    printf("expected result: output = 31\n");
    {
        int n = 2147483647;
        
        Solution solution;
        auto result = solution.hammingWeight(n);
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
