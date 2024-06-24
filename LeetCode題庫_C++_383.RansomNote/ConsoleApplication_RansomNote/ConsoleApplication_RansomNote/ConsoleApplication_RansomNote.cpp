// ConsoleApplication_RansomNote.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

class Solution{
public:
    bool canConstruct(string ransomNote, string magazine){
        
        int Count_RansomNote[26] = {0};  // store all the char(a~z) within ransomNote into int array
        int Count_Magazine[26] = {0};    // store all the char(a~z) within magazine into int array

        for (size_t i = 0; i < ransomNote.size(); i++)
        {
            Count_RansomNote[ransomNote[i] - 'a']++;
        }

        for (size_t i = 0; i < magazine.size(); i++)
        {
            Count_Magazine[magazine[i] - 'a']++;
        }

        // compare HERE
        for (size_t i = 0; i < 26; i++)
        {
            if( Count_RansomNote[i] ) {
                if( Count_RansomNote[i] > Count_Magazine[i] )
                    return false;
            }
        }
        
        return true;
    }
};

int main()
{
    std::cout << "Hello LeetCode - Ransom Note, (HASH TABLE) !\n";

    printf("LeetCode - 383. Ransom Note\n");
    cout << "https://leetcode.com/problems/ransom-note/" << endl << endl;
    // cout << "solution: https://medium.com/@zero.ling/c-sort-a-map-by-value-601a60ec0e01" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: ransomNote=\"a\", magazine=\"b\"\n");
    printf("expected result: false\n");
    {
        string ransomNote = "a";
        string magazine = "b";

        Solution Solution_cs;
        auto Result = Solution_cs.canConstruct(ransomNote, magazine);
        printf("Result value is %d, true=%d, false=%d\n", Result, true, false);

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: ransomNote=\"aa\", magazine=\"ab\"\n");
    printf("expected result: false\n");
    {
        string ransomNote = "aa";
        string magazine = "ab";

        Solution Solution_cs;
        auto Result = Solution_cs.canConstruct(ransomNote, magazine);
        printf("Result value is %d, true=%d, false=%d\n", Result, true, false);

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: ransomNote=\"aa\", magazine=\"aab\"\n");
    printf("expected result: true\n");
    {
        string ransomNote = "aa";
        string magazine = "aab";

        Solution Solution_cs;
        auto Result = Solution_cs.canConstruct(ransomNote, magazine);
        printf("Result value is %d, true=%d, false=%d\n", Result, true, false);

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
