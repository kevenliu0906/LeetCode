// ConsoleApplication_Perfect_Squares.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    vector<int> base_num_vec;
    int min_square_sum = 0;
    vector<bool> check_num_status_vec; // record already check num to reduce time

    void calc_base_num(int n){
        // reset
        base_num_vec.clear();
        check_num_status_vec.clear();

        int check_num = 1;
        while(check_num < n)
        {
            if (check_num * check_num <= n){
                base_num_vec.push_back(check_num * check_num);
            }else{
                break;
            }
            
            check_num++;
        }
        check_num_status_vec.resize(n+1, false);  // initial check_num_status array to false
    }

    int calc_numSquares_with_DP(int n){

        // printf("calc_numSquares_with_DP!!!!!\n");

        if (n == 1) return 1;

        // STEP1: find out the base_num and storage it
        calc_base_num(n);

        // STEP2: using DP to find the result
        vector<int> DP(n+1, INT_MAX);
        DP[0] = 0;

        for (size_t i = 1; i < DP.size(); i++)
        {
            for (size_t j = 0; j < base_num_vec.size(); j++)
            {
                if (i < base_num_vec[j]) break;   // represent i-base_num_vec[j] is negative, is illegal case, so not need to consider
                
                DP[i] = min(DP[i], 1 + DP[i-base_num_vec[j]]);
            }
        }
        
        if (DP[n] == INT_MAX) return -1;
        
        return DP[n];
        
    }

    int calc_numSquares_with_BFS(int n){
        
        // printf("calc_numSquares_with_BFS!!!!!\n");

        if ( n == 1) return 1;
        
        // STEP1: find out the base_num and storge it
        calc_base_num(n);

        // STEP2: using BFS to find the result
        queue<int> cur_square_sum_que;
        queue<int> tmp_square_sum_que;

        for (size_t i = 0; i < base_num_vec.size(); i++)
        {
            // printf("i:%d, check_num_status_vec size(%d), base_num_vec size(%d)\n", i, check_num_status_vec.size(), base_num_vec.size());
            if (!check_num_status_vec[base_num_vec[i]])
            {
                check_num_status_vec[base_num_vec[i]] = true;
                tmp_square_sum_que.push(base_num_vec[i]);
            }
        }
        min_square_sum++;

        while (tmp_square_sum_que.size())
        {
            cur_square_sum_que.swap(tmp_square_sum_que);
            while (cur_square_sum_que.size())
            {
                auto cur_square_sum = cur_square_sum_que.front();
                if (cur_square_sum == n)
                {
                    // BINGO~~~ found it!!!
                    return min_square_sum;
                }
                
                if (cur_square_sum <= n)
                {
                    for (size_t i = 0; i < base_num_vec.size(); i++)
                    {
                        if (cur_square_sum + base_num_vec[i] <= n)
                        {
                            if (!check_num_status_vec[cur_square_sum + base_num_vec[i]])
                            {
                                check_num_status_vec[cur_square_sum + base_num_vec[i]] = true;
                                tmp_square_sum_que.push(cur_square_sum + base_num_vec[i]);
                            }
                            
                        }
                    }
                }

                cur_square_sum_que.pop();
            }

            min_square_sum++;
        }
        return -1;
    }

public:
    int numSquares(int n) {
        // solution 0 (keven, using DP to solve, best performance)
        {
            auto res = calc_numSquares_with_DP(n);
            return res;
        }
        // solution 1 (keven, using BFS to solve)
        {
            auto res = calc_numSquares_with_BFS(n);
            return res;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Perfect Squares, Algorithm(Breadth-First Search, Dynamic Programming)!\n";
    cout << "https://leetcode.com/problems/perfect-squares/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: n = 12\n");
    printf("expected result: output = 3\n");
    printf("Explanation: 12 = 4 + 4 + 4\n");
    {
        int n = 12;

        Solution solution;
        auto res = solution.numSquares(n);
        printf("res is %d\n", res);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: n = 13\n");
    printf("expected result: output = 2\n");
    printf("Explanation: 13 = 4 + 9\n");
    {
        int n = 13;

        Solution solution;
        auto res = solution.numSquares(n);
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
