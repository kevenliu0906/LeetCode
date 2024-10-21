// ConsoleApp_Unique_BST.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        // solution 0 (keven, reference other: https://medium.com/@bill800227/leetcode-96-unique-binary-search-trees-abce6e62a7a0)
        {
            if (n == 0)
                return 1;
            
            vector<int> dp(n+1, 0);
            dp[0] = 1;
            dp[1] = 1;

            for (int i = 2; i <= n; i++){
                for (int j = 0; j < i; j++){
                    dp[i] += dp[j] * dp[i-j-1];
                }
                
            }
            
            return dp[n];
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Unique Binary Search Trees, Algorithm(Dynamic Programming, Binary Search Tree)!\n";
    cout << "https://leetcode.com/problems/unique-binary-search-trees/" << endl;
    cout << "solution: https://medium.com/@bill800227/leetcode-96-unique-binary-search-trees-abce6e62a7a0" << endl << endl;
    
    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: n = 3\n");
    printf("expected result: output = 5\n");
    {
        int n = 3;
        Solution solution;
        auto res = solution.numTrees(n);

        printf("res is %d\n", res);
    }
    printf("*****************************************************\n");

    printf("\n\n");
    
    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: n = 1\n");
    printf("expected result: output = 1\n");
    {
        int n = 1;
        Solution solution;
        auto res = solution.numTrees(n);

        printf("res is %d\n", res);
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
