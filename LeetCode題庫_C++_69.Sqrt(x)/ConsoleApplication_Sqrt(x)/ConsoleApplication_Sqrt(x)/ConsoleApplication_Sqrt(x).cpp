// ConsoleApplication_Sqrt(x).cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {

        // solution 1 (keven, best, binary search)
        {
            if (x == 0 || x == 1){
                return x;
            }
            if (x == 4){
                return 2;
            }
            
            int left = 1;
            int right = x/2;
            // int LoopCount = 0;
            while (left<=right)
            {
                // LoopCount++;
                int64_t mid = left + (right-left)/2;
                int64_t mid_square = mid * mid;
                // printf("Loop:%d, L:%d, R:%d, mid:%lld, mid_square:%lld\n", LoopCount, left, right, mid, mid_square);

                if (mid_square == x){
                    return mid;
                }else if(mid_square < x){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
            
            return right;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Sqrt(x), Algorithm(Binary Search)!\n";
    cout << "https://leetcode.com/problems/sqrtx/" << endl << endl;
    // cout << "solution: https://hackmd.io/@PeterLei/leetcode374?utm_source=preview-mode&utm_medium=rec/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: x = 4\n");
    printf("expected result: output = 2\n");
    {
        int n = 4;
        
        Solution solution;
        auto result = solution.mySqrt(n);
        printf("result:%d\n", result);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: x = 8\n");
    printf("expected result: output = 2\n");
    {
        int n = 8;
        
        Solution solution;
        auto result = solution.mySqrt(n);
        printf("result:%d\n", result);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: x = 0\n");
    printf("expected result: output = 0\n");
    {
        int n = 0;
        
        Solution solution;
        auto result = solution.mySqrt(n);
        printf("result:%d\n", result);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: x = 2^31 - 1\n");
    printf("expected result: output = 46340\n");
    {
        int n = pow(2, 31) - 1;
        printf("input:2^31-1=%d\n", n);
        
        Solution solution;
        auto result = solution.mySqrt(n);
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
