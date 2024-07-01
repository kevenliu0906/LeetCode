// ConsoleApplication_Valid_Parentheses.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
    bool isValid(string s){
        
        bool Result = true;

        // solution 1 (keven, best)
        vector<char> stack_sign;

        for (size_t i = 0; i < s.size(); i++)
        {
            auto current_char = s[i];
            if( current_char == '(' || current_char == '[' || current_char == '{' )
                stack_sign.push_back( current_char );
            else{
                if(!stack_sign.size())
                    return false;
                auto last_char = stack_sign[stack_sign.size() - 1];
                if( current_char == ')' ){
                    if( last_char != '(' )
                        return false;
                    stack_sign.pop_back();   // erase the mapping set
                }
                else if( current_char == ']' ){
                    if( last_char != '[' )
                        return false;
                    stack_sign.pop_back();   // erase the mapping set
                }
                else if( current_char == '}'){
                    if( last_char != '{' )
                        return false;
                    stack_sign.pop_back();   // erase the mapping set
                }
            }
        }

        if (stack_sign.size())
            return false;
        
        return Result;
    }
};

int main()
{
    std::cout << "Hello LeetCode - Valid Parentheses, DataStructure (Stack, String)!\n";

    printf("LeetCode - 20. Valid Parentheses\n");
    cout << "https://leetcode.com/problems/valid-parentheses" << endl << endl;
    // cout << "solution: https://medium.com/@zero.ling/c-sort-a-map-by-value-601a60ec0e01" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: s = \"()\"\n");
    printf("expected result: \"true\"\n");
    {
        string s = "()";

        Solution Solution_cs;
        auto Result = Solution_cs.isValid(s);

        printf("Result value:%d, true=%d, false=%d\n", Result, true, false);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: s = \"()[]{}\"\n");
    printf("expected result: \"true\"\n");
    {
        string s = "()[]{}";

        Solution Solution_cs;
        auto Result = Solution_cs.isValid(s);

        printf("Result value:%d, true=%d, false=%d\n", Result, true, false);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: s = \"(]\"\n");
    printf("expected result: \"false\"\n");
    {
        string s = "(]";

        Solution Solution_cs;
        auto Result = Solution_cs.isValid(s);

        printf("Result value:%d, true=%d, false=%d\n", Result, true, false);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: s = \"]\"\n");
    printf("expected result: \"false\"\n");
    {
        string s = "]";

        Solution Solution_cs;
        auto Result = Solution_cs.isValid(s);

        printf("Result value:%d, true=%d, false=%d\n", Result, true, false);
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
