// Console_MinAdd_Parenthese_Valid.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {

        // solution 1 (keven, best, using stack to solve it)
        {
            int no_valid_result = 0;
            stack<char> need_check_stack;   // store the ')' in stack 
            char last_ch = '\0';
            int result = 0;

            for (int i = s.size()-1; i >=0; i--)
            {
                auto ch = s[i];
                // printf("i:%d, ch:%c\n", i, ch);
                switch(ch)
                {
                    case '(':
                        if (need_check_stack.empty()){
                            // represent no ')' in stack 
                            no_valid_result++;  // not illegal case, so need remove it
                        }else{
                            need_check_stack.pop();
                        }
                        
                    break;
                    case ')':
                        need_check_stack.push(ch);
                    break;
                }

                last_ch = ch;
            }

            if (need_check_stack.size() || no_valid_result)
            {
                result += need_check_stack.size();
                result += no_valid_result;
            }

            // printf("result:%d\n", result);
            
            return result;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Minimum Add to Make Parentheses Valid, DataStructure(stack)!\n";
    cout << "https://leetcode.com/problems/linked-list-random-node/description/" << endl << endl;
    // cout << "solution: https://https://hackmd.io/@Zero871015/LeetCode-237/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: s = \"())\"\n");
    printf("expected result: output = 1\n");
    {
        Solution solution;
        auto result = solution.minAddToMakeValid("())");
        printf("min add to make valid:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: s = \"(((\"\n");
    printf("expected result: output = 3\n");
    {
        Solution solution;
        auto result = solution.minAddToMakeValid("(((");
        printf("min add to make valid:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: s = \"(\"\n");
    printf("expected result: output = 1\n");
    {
        Solution solution;
        auto result = solution.minAddToMakeValid("(");
        printf("min add to make valid:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: s = \")\"\n");
    printf("expected result: output = 1\n");
    {
        Solution solution;
        auto result = solution.minAddToMakeValid(")");
        printf("min add to make valid:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 5 ****************************\n");
    printf("input: s = \"))(\"\n");
    printf("expected result: output = 3\n");
    {
        Solution solution;
        auto result = solution.minAddToMakeValid("))(");
        printf("min add to make valid:%d\n", result);
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
