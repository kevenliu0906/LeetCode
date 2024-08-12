// ConsoleApplication_Baseball_Game.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:

    void debug(string lastOper, stack<int> dbg_stack)
    {
        printf("last operation:%s,  ", lastOper.c_str());
        if (dbg_stack.size()){
            printf("current stack:");
        }else{
            printf("current stack is EMPTY\n");
        }
        
        while (dbg_stack.size())
        {
            auto current_top = dbg_stack.top();
            printf("%d,", current_top);
            dbg_stack.pop();
        }
        printf("\n");
    }

    int calPoints(vector<string>& operations) { 

        // solution 1 (keven, best, use stack to solve it)
        //            (Optimize the code to sync the result value without final overall loop to add.)
        stack<int> final_points_stack;
        auto result = 0;

        for (size_t i = 0; i < operations.size(); i++)
        {
            auto current_oper = operations[i];

            if (current_oper == "C"){
                if (final_points_stack.empty()){
                    // before call stack.pop() need check if stack is empty
                    printf("there is no element to pop, checked it!!!!!\n");
                    return -10;
                }

                auto last_num = final_points_stack.top();
                result -= last_num;

                final_points_stack.pop();
                // debug(current_oper, final_points_stack);
            }else if (current_oper == "D")
            {
                if (final_points_stack.empty()){
                    // before call stack.top() need check if stack is empty
                    printf("there is no element on top, checked it!!!!!\n");
                    return -10;
                }
                auto finalvalue = final_points_stack.top();
                finalvalue*= 2;
                
                result += finalvalue;

                final_points_stack.push(finalvalue);   // push the newer value into top 
                // debug(current_oper, final_points_stack);

            }else if (current_oper == "+")
            {
                auto finalvalue_1 = 0;
                auto finalvalue_2 = 0;

                if (final_points_stack.empty()){
                    // before call stack.top() need check if stack is empty
                    printf("there is no element on top, checked it!!!!!\n");
                    return -10;
                }
                finalvalue_1 = final_points_stack.top();     // get the older value_1

                if (final_points_stack.empty()){
                    // before call stack.pop() need check if stack is empty
                    printf("there is no element to pop, checked it!!!!!\n");
                    return -10;
                }
                final_points_stack.pop();                         // pop the older value from top

                if (final_points_stack.empty()){
                    // before call stack.top() need check if stack is empty
                    printf("there is no element on top, checked it!!!!!\n");
                    return -10;
                }
                finalvalue_2 = final_points_stack.top();     // get the older value_2


                final_points_stack.push(finalvalue_1);            // push the older value_1 into top to restore

                auto sum_value = finalvalue_1 + finalvalue_2;

                result += sum_value;

                final_points_stack.push(sum_value);
                // debug(current_oper, final_points_stack);

            }else{
                auto num = atoi(current_oper.c_str());
                // printf("current num:%d\n", num);
                result += num;
                final_points_stack.push(num);
                // debug("ONLY num",final_points_stack);
            }
            
        }

        
        // while (final_points_stack.size())
        // {
        //     result += final_points_stack.top();
        //     final_points_stack.pop();
        // }
        // // printf("result is %d\n", result);
        
        return result;
    }
};

int main()
{
    std::cout << "Hello LeetCode - Baseball Game, DataStruct(stack)!\n";
    cout << "https://leetcode.com/problems/baseball-game/" << endl << endl;
    // cout << "solution: https://https://hackmd.io/@Zero871015/LeetCode-237/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("operations: [\"5\",\"2\",\"C\",\"D\",\"+\"]\n");
    printf("expected result: output = 30\n");
    {
        vector<string> operations{"5","2","C","D","+"};

        Solution solution;
        auto result = solution.calPoints(operations);
        printf("cal Points result:%d\n", result);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("operations: [\"5\",\"-2\",\"4\",\"C\",\"D\",\"9\",\"+\",\"+\"]\n");
    printf("expected result: output = 27\n");
    {
        vector<string> operations{"5","-2","4","C","D","9","+","+"};

        Solution solution;
        auto result = solution.calPoints(operations);
        printf("cal Points result:%d\n", result);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("operations: [\"1\",\"C\"]\n");
    printf("expected result: output = 0\n");
    {
        vector<string> operations{"1","C"};

        Solution solution;
        auto result = solution.calPoints(operations);
        printf("cal Points result:%d\n", result);
        
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
