// ConsoleApplication_Daily_Temperature.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    void monotonic(vector<int> &temp, vector<int> &next_big_ele){
        next_big_ele.resize(temp.size(), 0);   // reset
        stack<int> monotonic_idx_st;   // store idx

        for (int i = temp.size() - 1; i >= 0; i--)
        {
            while (!monotonic_idx_st.empty() && temp[monotonic_idx_st.top()] <= temp[i])
            {
                monotonic_idx_st.pop();
            }
            next_big_ele[i] = monotonic_idx_st.empty() ? 0 : monotonic_idx_st.top() - i;
            monotonic_idx_st.push(i);
        }
    }
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        // solution 0 (best solution, use monotonic stack to solve)
        {
            vector<int> res(temperatures.size());
            monotonic(temperatures, res);

            return res;
        }

        // solution 1 (reference others, using stack to solve it)
        //            a. https://ithelp.ithome.com.tw/m/articles/10237395
        //            b. https://anj910.medium.com/leetcode-739-daily-temperatures-%E4%B8%AD%E6%96%87-c906617d1810
        {
            stack<int> uncheck_temp_index_stack;
            int total_temp_size = temperatures.size();
            vector<int> result(total_temp_size, 0);

            for (size_t i = 0; i < temperatures.size(); i++)
            {
                while (uncheck_temp_index_stack.size())
                {
                    if (temperatures[i] > temperatures[uncheck_temp_index_stack.top()])
                    {
                        result[uncheck_temp_index_stack.top()] = i - uncheck_temp_index_stack.top();
                        uncheck_temp_index_stack.pop();
                    }else{
                        break;
                    }
                }
                
                uncheck_temp_index_stack.push(i);  // push the index of un-checked temperature into stack
            }
            
            return result;
        }

        // // solution 2 (keven, force directly, time limit exceed)
        // {
        //     vector<int> result;
        //     result.resize(temperatures.size(), 0);    // assign the default value into result array

        //     for (int i = 0; i < temperatures.size() - 1; i++)
        //     {
        //         auto current_Meet_result = 0;
        //         for (int j = i+1; j < temperatures.size(); j++)
        //         {
        //             if (temperatures[j] > temperatures[i])
        //             {
        //                 current_Meet_result = j - i;
        //                 break;
        //             }
        //         }
        //         result[i] = current_Meet_result;
        //     }

        //     return result;
        // }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Daily Temperature, DataStructure(stack)!\n";
    cout << "https://leetcode.com/problems/daily-temperatures" << endl << endl;
    // cout << "solution: https://https://hackmd.io/@Zero871015/LeetCode-237/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: temperatures = [73,74,75,71,69,72,76,73]\n");
    printf("expected result: output = [1,1,4,2,1,1,0,0]\n");
    {
        vector<int> temperatures = {73,74,75,71,69,72,76,73};
        Solution solution;
        auto result = solution.dailyTemperatures(temperatures);
        if (result.size())
        {
            printf("days:");
            for (size_t i = 0; i < result.size(); i++)
            {
                printf("%d,", result[i]);
            }
            printf("\n");
        }else{
            printf("daily temperatures result is NULL\n");
        }
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: temperatures = [30,40,50,60]\n");
    printf("expected result: output = [1,1,1,0]\n");
    {
        vector<int> temperatures = {30,40,50,60};
        Solution solution;
        auto result = solution.dailyTemperatures(temperatures);
        if (result.size())
        {
            printf("days:");
            for (size_t i = 0; i < result.size(); i++)
            {
                printf("%d,", result[i]);
            }
            printf("\n");
            
        }else{
            printf("daily temperatures result is NULL\n");
        }
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: temperatures = [30,60,90]\n");
    printf("expected result: output = [1,1,0]\n");
    {
        vector<int> temperatures = {30,60,90};
        Solution solution;
        auto result = solution.dailyTemperatures(temperatures);
        if (result.size())
        {
            printf("days:");
            for (size_t i = 0; i < result.size(); i++)
            {
                printf("%d,", result[i]);
            }
            printf("\n");
            
        }else{
            printf("daily temperatures result is NULL\n");
        }
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: temperatures = [80,30,10]\n");
    printf("expected result: output = [0,0,0]\n");
    {
        vector<int> temperatures = {80,30,10};
        Solution solution;
        auto result = solution.dailyTemperatures(temperatures);
        if (result.size())
        {
            printf("days:");
            for (size_t i = 0; i < result.size(); i++)
            {
                printf("%d,", result[i]);
            }
            printf("\n");
            
        }else{
            printf("daily temperatures result is NULL\n");
        }
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 5 ****************************\n");
    printf("input: temperatures = [30]\n");
    printf("expected result: output = [0]\n");
    {
        vector<int> temperatures = {30};
        Solution solution;
        auto result = solution.dailyTemperatures(temperatures);
        if (result.size())
        {
            printf("days:");
            for (size_t i = 0; i < result.size(); i++)
            {
                printf("%d,", result[i]);
            }
            printf("\n");
            
        }else{
            printf("daily temperatures result is NULL\n");
        }
        
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
