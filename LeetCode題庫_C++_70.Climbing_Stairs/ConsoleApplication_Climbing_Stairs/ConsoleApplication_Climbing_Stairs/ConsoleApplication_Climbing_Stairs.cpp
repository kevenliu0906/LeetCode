// ConsoleApplication_Climbing_Stairs.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    
    vector<vector<int>> climbing_step_to_Stair;

    int climbStairs(int n) {

        // solution 1 (best, using DP(Dynamic Programming - Tabulation) )
        // reference: https://www.geeksforgeeks.org/count-ways-reach-nth-stair/
        {
            vector<int> dp(n+1, 0);
            dp[0] = dp[1] = 1;

            for (size_t i = 2; i < dp.size(); i++)
            {
                dp[i] = dp[i-1] + dp[i-2];
            }

            return dp[n];
            
        }
        
        // solution 2 (using recursive, n=45 will cause time limit exceed)
        {
            if ( n == 1)
            {
                return 1;
            }
            else if ( n == 2 )
            {
                return 2;
            }
            else{
                return climbStairs( n-1 ) + climbStairs( n-2 );
            }
            
        }
        
        // solution 1 (keven, n=35 will cause time limit exceed)
        {
            if( climbing_step_to_Stair.size() == 0 ){
                // represent the first create climbing step
                vector<int> each_step{n};
                climbing_step_to_Stair.push_back(each_step);
            }

            // printf("************** List EACH DETAIL STEPS (BEFORE) ************************\n");
            // for (auto each_step_iter = climbing_step_to_Stair.begin(); each_step_iter != climbing_step_to_Stair.end(); each_step_iter++)
            // {
            //     printf("each_step_count:%d\n", each_step_iter->size());
            //     printf("-------------\n");
            //     for (size_t i = 0; i < each_step_iter->size(); i++)
            //     {
            //         auto bb = each_step_iter->at(i);
            //         printf("detail-step[%d]:%d\n", i, each_step_iter->at(i));
            //     }
            //     printf("-------------\n\n");
            // }
            // printf("*********************************************************************\n\n");

            //---------- Process HERE ----------
            auto step_iter = climbing_step_to_Stair.begin();
            int ResultCount = 0;
            while( step_iter != climbing_step_to_Stair.end() )
            {
                
                // check the first element in climbing array
                int original_each_first_step = step_iter->at(0);

                // if ( original_each_first_step == 0 )
                if ( original_each_first_step < 2 )
                {
                    printf("$$$$$$$$$$$ BINGO $$$$$$$$$$\n");
                    printf("Match-STEP:\n");
                    for (size_t i = 0; i < step_iter->size(); i++)
                    {
                        printf("%d, ", step_iter->at(i));
                    }
                    printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\n");
                    ResultCount++;
                    climbing_step_to_Stair.erase(step_iter);

                }
                // else if (original_each_first_step == 1)
                // {
                //     // climbing 1 level
                //     step_iter->at(0) = original_each_first_step - 1;
                //     step_iter->push_back(1);
                // }
                else
                {
                    
                    // copy the new array(vector<int>) to insert into last element
                    vector<int> new_step(step_iter->begin(), step_iter->end());

                    // climbing 1 level
                    step_iter->at(0) = original_each_first_step - 1;
                    step_iter->push_back(1);

                    // climbing 2 level(need put on the last because the climbing_step_to_Stair will affect)
                    new_step[0] = original_each_first_step - 2;
                    new_step.push_back(2);
                    climbing_step_to_Stair.push_back(new_step);
                }

                if (climbing_step_to_Stair.size() == 0)
                {
                    break;
                }
                
                step_iter = climbing_step_to_Stair.begin();

            }

            
            // printf("************** List EACH DETAIL STEPS (AFTER) ************************\n");
            // int step_count = 0;
            // for (auto each_step : climbing_step_to_Stair)
            // {
            //     step_count++;
            //     printf("step_%d\n", step_count);
            //     printf("-------------\n");
            //     for (size_t i = 0; i < each_step.size(); i++)
            //     {
            //         printf("detail-step[%d]:%d\n", i, each_step[i]);
            //     }
            //     printf("-------------\n\n");
                
                
            // }
            // printf("**********************************************************************\n");
            
            return ResultCount;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Climbing Stairs, Algorithm (Math, Dynamic Programming)!\n";
    printf("LeetCode - 70. Climbing Stairs\n");
    cout << "https://leetcode.com/problems/climbing-stairs" << endl << endl;
    cout << "solution: https://www.geeksforgeeks.org/count-ways-reach-nth-stair/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: n = 2\n");
    printf("expected result: output = 2\n");
    {
        int n = 2;
        Solution solution;
        auto result = solution.climbStairs(n);
        printf("result:%d\n", result);
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
        auto result = solution.climbStairs(n);
        printf("result:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: n = 3\n");
    printf("expected result: output = 3\n");
    {
        int n = 3;
        Solution solution;
        auto result = solution.climbStairs(n);
        printf("result:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: n = 4\n");
    printf("expected result: output = 5\n");
    {
        int n = 4;
        Solution solution;
        auto result = solution.climbStairs(n);
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
