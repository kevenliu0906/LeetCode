// ConsoleApplication_Coin_Change.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
private:
    int min_coin_change_BFS(vector<int> &coins, int amount){

        printf("min_coin_change_BFS\n");

        if (amount == 0) return 0;

        sort(coins.begin(), coins.end());   // sort coins array with ascent order to save search time

        if (coins[0] > amount) return -1;   // the smallest one in coins vector is bigger than amount
        
        queue<int> cur_coins_sum;
        queue<int> tmp_coins_sum;
        vector<bool> amount_check_status_vec(amount + 1, false);      // record already process data to keep not process again
        int min_res = 0;

        for (auto each_coin : coins){
            if (each_coin < amount)
            {
                if (!amount_check_status_vec[each_coin]){
                    amount_check_status_vec[each_coin] = true;
                    tmp_coins_sum.push(each_coin);
                }
            }
            else if (each_coin == amount){
                // BINGO!!! found it~
                min_res++;
                return min_res;
            }
            else
                break;
        }
        
        min_res++;
        
        while (tmp_coins_sum.size())
        {
            cur_coins_sum.swap(tmp_coins_sum);
            while (cur_coins_sum.size())
            {
                auto cur_coin_sum = cur_coins_sum.front();
                // printf("min_res:%d, cur_coin_sum:%d\n", min_res, cur_coin_sum);
                if (cur_coin_sum == amount)
                {
                    // BINGO!!! found it~
                    return min_res;
                }
                
                if (cur_coin_sum < amount)
                {
                    // add each kind of coin value to cur_coin_sum , then judge if smaller than amount
                    for (auto each_coin_base : coins)
                    {
                        /*int*/long long tmp_cur_coin_sum = cur_coin_sum;  // avoid the addition in next line is overflow then coins have the biggest value of INT case
                        tmp_cur_coin_sum += each_coin_base;
                        if (tmp_cur_coin_sum > amount)
                        {
                            // because current tmp_coin_sum has already over the amount and coins array is ascent order, so not need to process again
                            break;
                        }
                        
                        if (tmp_cur_coin_sum <= amount){
                            if (!amount_check_status_vec[tmp_cur_coin_sum]){
                                amount_check_status_vec[tmp_cur_coin_sum] = true;
                                tmp_coins_sum.push(tmp_cur_coin_sum);
                            }
                        }
                    }
                }
                cur_coins_sum.pop();
            }
            
            min_res++;
        }
        
        return -1;
    }

    int min_coin_change_DP(vector<int> &coins, int amount){

        // printf("min_coin_change_DP\n");

        vector<int> DP(amount+1, amount+100);  // asign each element value to amount+100 to let next compare min function could be executed

        DP[0] = 0;
        for (int i = 1; i < DP.size(); i++)
        {
            for (auto j : coins)
            {
                if (i < j) continue;   // represent current-amount is less the current-coin value, so this current-coin value is not suitable for recording                
                
                DP[i] = min(DP[i], 1 + DP[i - j]);
                // printf("i:%d, j:%d, DP[%d]=%d\n", i, j, i, DP[i]);
            }
            // printf("DP[%d]=%d\n", i, DP[i]);
        }
        
        
        if (DP[amount] == amount+100){
            // printf("amount:%d is not meet sum of coins, so return -1\n");
            return -1;
        }
        
        return DP[amount];
    }

public:
    int coinChange(vector<int>& coins, int amount) {

        // solution 0 - keven (using DP to solve, best performance)
        {
            auto res = min_coin_change_DP(coins, amount);

            return res;
        }

        // solution 1 - keven (using BFS to solve, thinking as the same in LeetCode.433 https://leetcode.com/problems/minimum-genetic-mutation/)
        {
            auto res = min_coin_change_BFS(coins, amount);

            return res;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Coin Change, Algorithm(Breadth-First Search, Dynamic Programming)!\n";
    cout << "https://leetcode.com/problems/coin-change/" << endl;
    cout << "guide line: https://emmielin.medium.com/leetcode-%E7%AD%86%E8%A8%98-322-coin-change-d2a7acdbaaec " << endl;
    cout << "solution: https://hackmd.io/@rickrool/SyP7ZN1Ai" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: coins = [1,2,5], amount = 11\n");
    printf("expected result: output = 3\n");
    printf("Explanation: 11 = 5 + 5 + 1\n");
    {
        
        vector<int> coins{1,2,5};
        int amount = 11;

        Solution solution;
        auto res = solution.coinChange(coins, amount);
        printf("res is %d\n", res);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: coins = [2], amount = 3\n");
    printf("expected result: output = -1\n");
    {
        
        vector<int> coins{2};
        int amount = 3;

        Solution solution;
        auto res = solution.coinChange(coins, amount);
        printf("res is %d\n", res);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: coins = [186,419,83,408], amount = 6249\n");
    printf("expected result: output = 20\n");
    {
        
        vector<int> coins{186,419,83,408};
        int amount = 6249;

        Solution solution;
        auto res = solution.coinChange(coins, amount);
        printf("res is %d\n", res);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: coins = [1,2147483647], amount = 2\n");
    printf("expected result: output = 2\n");
    {
        
        vector<int> coins{1,2147483647};
        int amount = 2;

        Solution solution;
        auto res = solution.coinChange(coins, amount);
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
