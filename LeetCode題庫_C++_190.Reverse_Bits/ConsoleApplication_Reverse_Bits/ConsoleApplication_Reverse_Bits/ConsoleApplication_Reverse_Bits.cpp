// ConsoleApplication_Reverse_Bits.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        // solution 0 (keven, best, using bit manipulation to solve)
        {
            uint32_t reverse_bit_value = 0;
            
            for (size_t i = 0; i <= 31; i++)
            {
                uint32_t currentBitValue = (n & (1<<i)) >> i;
                // printf("current_Bit_Value[%d]=%u\n", i, currentBitValue);
                reverse_bit_value = (reverse_bit_value << 1) + currentBitValue;
                // printf("i:%d, currentBitValue:%u, reverse_bit_value:%u\n", i, currentBitValue, reverse_bit_value);
            }
            
            return reverse_bit_value;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Reverse Bit, Algorithm(Divide and Conquer, Bit Manipulation)!\n";
    cout << "https://leetcode.com/problems/reverse-bits" << endl << endl;
    // cout << "solution: https://www.geeksforgeeks.org/count-ways-reach-nth-stair/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: n = 43261596(00000010100101000001111010011100)\n");
    printf("expected result: output = 964176192(00111001011110000010100101000000)\n");
    {
        uint32_t n = 43261596;  //00000010100101000001111010011100

        Solution solution;
        auto result = solution.reverseBits(n);
        printf("n:%d, reverse_bit(n):%d\n", n, result);

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: n = 4294967293(11111111111111111111111111111101)\n");
    printf("expected result: output = 3221225471(10111111111111111111111111111111)\n");
    {
        uint32_t n = 4294967293;  //11111111111111111111111111111101

        Solution solution;
        auto result = solution.reverseBits(n);
        printf("n:%u, reverse_bit(n):%u\n", n, result);

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: n = 2147483647(01111111111111111111111111111111)\n");
    printf("expected result: output = 4294967294(11111111111111111111111111111110)\n");
    {
        uint32_t n = 2147483647;  //01111111111111111111111111111111

        Solution solution;
        auto result = solution.reverseBits(n);
        printf("n:%u, reverse_bit(n):%u\n", n, result);

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: n = 4294967294(11111111111111111111111111111110)\n");
    printf("expected result: output = 2147483647(01111111111111111111111111111111)\n");
    {
        uint32_t n = 4294967294;  //11111111111111111111111111111110

        Solution solution;
        auto result = solution.reverseBits(n);
        printf("n:%u, reverse_bit(n):%u\n", n, result);

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 5 ****************************\n");
    printf("input: n = 805306367(00101111111111111111111111111111)\n");
    printf("expected result: output = 4294967284(11111111111111111111111111110100               )\n");
    {
        uint32_t n = 805306367;  //00101111111111111111111111111111

        Solution solution;
        auto result = solution.reverseBits(n);
        printf("n:%u, reverse_bit(n):%u\n", n, result);

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
