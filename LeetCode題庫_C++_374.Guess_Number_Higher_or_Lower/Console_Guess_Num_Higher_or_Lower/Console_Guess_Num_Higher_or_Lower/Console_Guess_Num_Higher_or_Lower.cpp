// Console_Guess_Num_Higher_or_Lower.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

using namespace std;

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:

    int target = 0;

    int guess(int num){
        if (num == target)
        {
            return 0;
        }
        else if (num > target)
        {
            return (-1);
        }
        else if (num < target)
        {
            return 1;
        }

        return 2;
    }

    int guessNumber(int n) {
        
        // solution 1 (keven, best)
        {
            int left = 1;
            int right = n;

            while ( left <= right )
            {
                int mid = left + (right - left)/2;
                auto guessValue = guess(mid);
                switch (guessValue)
                {
                    case 0:
                    {
                        // bingo~~~, guess CORRECT
                        // printf("BINGO~~~ mid:%d\n", mid);
                        return mid;
                    }
                    break;
                    case 1:
                    {
                        left = mid + 1;
                        // printf("guess:%d, return:%d, shift left:%d\n", mid, guessValue, left);
                    }
                    break;
                    case -1:
                    {
                        right = mid - 1;
                        // printf("guess:%d, return:%d, shift right:%d\n", mid, guessValue, right);
                    }
                    break;
                
                default:
                    break;
                }   
            }
            
            return 0;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCoe - Guess Number Higher or Lower, Algorithm(Binary Search)!\n";
    cout << "https://leetcode.com/problems/guess-number-higher-or-lower/" << endl << endl;
    // cout << "solution: https://hackmd.io/@PeterLei/leetcode374?utm_source=preview-mode&utm_medium=rec/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: n = 10, pick = 6\n");
    printf("expected result: output = 6\n");
    {
        int n = 10;
        
        Solution solution;
        solution.target = 6;
        auto result = solution.guessNumber(n);
        printf("result:%d\n", result);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: n = 1, pick = 1\n");
    printf("expected result: output = 1\n");
    {
        int n = 1;
        
        Solution solution;
        solution.target = 1;
        auto result = solution.guessNumber(n);
        printf("result:%d\n", result);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: n = 2, pick = 1\n");
    printf("expected result: output = 1\n");
    {
        int n = 2;
        
        Solution solution;
        solution.target = 1;
        auto result = solution.guessNumber(n);
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
