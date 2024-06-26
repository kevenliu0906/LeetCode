// ConsoleApplication_FindTheDifference.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

class Solution{
public:
    char findTheDifference(string s, string t){
        
        char result = '\0';

        // solution 1 (keven, best)
        {
            int t_element_count[26] = {0};  // record all the counts for each 26 char in "t" string
            int s_element_count[26] = {0};  // record all the counts for each 26 char in "s" string

            // record t element count
            for (size_t i = 0; i < t.size(); i++)
            {
                t_element_count[t[i] - 'a']++;
            }
            // record s element count
            for (size_t i = 0; i < s.size(); i++)
            {
                s_element_count[s[i] - 'a']++;
            }

            // compare the different in each element count
            for (size_t i = 0; i < 26; i++)
            {
                if( t_element_count[i] != s_element_count[i] ){
                    result = char('a' + i);
                    return result;
                }
            }
        }
        
        return result;
    }
};

int main()
{
    std::cout << "Hello LeetCode - Find the Difference, DataStructure (String, HASH TABLE) !\n";

    printf("LeetCode - 389. Find the Difference\n");
    cout << "https://leetcode.com/problems/find-the-difference/" << endl << endl;
    // cout << "solution: https://medium.com/@zero.ling/c-sort-a-map-by-value-601a60ec0e01" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: s = \"abcd\", t = \"abcde\" \n");
    printf("expected result: \"e\" \n");
    {
        string s = "abcd";
        string t = "abcde";

        Solution Solution_cs;
        auto Result = Solution_cs.findTheDifference(s, t);
        printf("Result is '%c', true=%d, false=%d\n", Result, true, false);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: s = \"\", t = \"y\" \n");
    printf("expected result: \"y\" \n");
    {
        string s = "";
        string t = "y";

        Solution Solution_cs;
        auto Result = Solution_cs.findTheDifference(s, t);
        printf("Result is '%c', true=%d, false=%d\n", Result, true, false);
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
