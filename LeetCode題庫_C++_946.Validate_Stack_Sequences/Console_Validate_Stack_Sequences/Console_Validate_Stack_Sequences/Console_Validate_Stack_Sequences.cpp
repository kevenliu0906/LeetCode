// Console_Validate_Stack_Sequences.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
   
        // solution 1 (keven, force directly)
        {
            stack<int> current_num_stock;

            // STEP1. align the pushed array with popped array
            if (current_num_stock.empty())
            {
                auto popped_value = *popped.begin();
                auto push_value = 0;
                do{
                    push_value = *pushed.begin();
                    current_num_stock.push(push_value);
                    pushed.erase(pushed.begin());
                }while (push_value != popped_value);
            }

            // // debug the current_num_stock
            // while (current_num_stock.size())
            // {
            //     printf("stock val:%d\n", current_num_stock.top());
            //     current_num_stock.pop();
            // }
            // return false;

            // STEP2. check if could pop value from "num_stock or pushed array" to correspond to popped array
            int count = 0;
            while( popped.size() ){
                count++;
                auto current_popped_value = *popped.begin();
                // printf("count:%d, current_popped_value:%d\n", count, current_popped_value);

                // STEP2-1, check if the popped_value is existed on num_stock
                if ( current_num_stock.size() && (current_num_stock.top() == current_popped_value) )
                {
                    // printf("case: current_num_stock.top:%d\n", current_num_stock.top());
                    current_num_stock.pop();
                    popped.erase(popped.begin());
                    continue;
                }else{
                    if (pushed.empty()){
                        return false;
                    }
                    
                    // STEP2-2, check if the popped_value is existed on pushed array
                    auto next_push_value = *pushed.begin();
                    // if (next_push_value == current_popped_value)
                    {
                        // printf("case: next_push_value:%d\n", next_push_value);
                        current_num_stock.push(next_push_value);
                        pushed.erase(pushed.begin());
                        continue;
                    }              
                }
            }
            
            return true;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Validate Stack Sequences, DataStructure(stack)!\n";
    cout << "https://leetcode.com/problems/validate-stack-sequences/" << endl << endl;
    // cout << "solution: https://https://hackmd.io/@Zero871015/LeetCode-237/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]\n");
    printf("expected result: output = true\n");
    {
        vector<int> pushed{1,2,3,4,5};
        vector<int> popped{4,5,3,2,1};
        Solution solution;

        auto result = solution.validateStackSequences(pushed, popped);
        printf("validate stack sequences result:%d, true(%d), false(%d)\n", result, true, false);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: pushed = [1,2,3,4,5,6], popped = [4,6,5,3,2,1]\n");
    printf("expected result: output = true\n");
    {
        vector<int> pushed{1,2,3,4,5,6};
        vector<int> popped{4,6,5,3,2,1};
        Solution solution;

        auto result = solution.validateStackSequences(pushed, popped);
        printf("validate stack sequences result:%d, true(%d), false(%d)\n", result, true, false);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]\n");
    printf("expected result: output = false\n");
    printf("Explanation: 1 cannot be popped before 2.\n");
    {
        vector<int> pushed{1,2,3,4,5};
        vector<int> popped{4,3,5,1,2};
        Solution solution;

        auto result = solution.validateStackSequences(pushed, popped);
        printf("validate stack sequences result:%d, true(%d), false(%d)\n", result, true, false);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: pushed = [1,0], popped = [1,0]\n");
    printf("expected result: output = true\n");
    {
        vector<int> pushed{1,0};
        vector<int> popped{1,0};
        Solution solution;

        auto result = solution.validateStackSequences(pushed, popped);
        printf("validate stack sequences result:%d, true(%d), false(%d)\n", result, true, false);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 5 ****************************\n");
    printf("input: pushed = [0,2,1], popped = [0,1,2]\n");
    printf("expected result: output = true\n");
    {
        vector<int> pushed{0,2,1};
        vector<int> popped{0,1,2};
        Solution solution;

        auto result = solution.validateStackSequences(pushed, popped);
        printf("validate stack sequences result:%d, true(%d), false(%d)\n", result, true, false);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 6 ****************************\n");
    printf("input: pushed = [1,2,3,4,5,6], popped = [4,6,2,3,5,1]\n");
    printf("expected result: output = false\n");
    printf("Explanation: 2 cannot be popped before 3.\n");
    {
        vector<int> pushed{1,2,3,4,5,6};
        vector<int> popped{4,6,2,3,5,1};
        Solution solution;

        auto result = solution.validateStackSequences(pushed, popped);
        printf("validate stack sequences result:%d, true(%d), false(%d)\n", result, true, false);
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
