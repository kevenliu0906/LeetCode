// Console_FindAndReplacePattern.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {

        vector<string> result;

        // solution 1 (keven, best)
        {
            for (size_t i = 0; i < words.size(); i++)
            {
                auto each_word = words[i];
                // printf("<kd> i:%d, each_word:%s\n", i, each_word.c_str());

                // the length of word is NOT match with pattern
                if( each_word.size() != pattern.size() )
                    continue;

                bool TotalMatch = true;
                for (size_t i = 0; i < pattern.size(); i++)
                {
                    auto pattern_each = pattern[i];
                    auto each_word_each = each_word[i];
                    // check if the same char appear in the same position
                    if( pattern.find(pattern_each, i + 1) != each_word.find(each_word_each, i + 1) ){
                        TotalMatch = false;
                        break;
                    }
                }

                if( TotalMatch )
                    result.push_back(each_word);
            }
        }

        return result;
    }
};


int main()
{
    std::cout << "Hello LeetCode - Find and Replace Pattern, DataStructure (HASH TABLE) !\n";

    printf("LeetCode - 890. Find and Replace pattern.\n");
    cout << "https://https://leetcode.com/problems/find-and-replace-pattern" << endl << endl;
    // cout << "solution: https://medium.com/@zero.ling/c-sort-a-map-by-value-601a60ec0e01" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: words = {\"abc\", \"deq\", \"mee\", \"aqq\", \"dkd\", \"ccc\"}, pattern = \"abb\" \n");
    printf("expected result: {[mee], [aqq]}\n");
    {
        vector<string> words = {"abc", "deq", "mee", "aqq", "dkd", "ccc"};
        string pattern = "abb";

        Solution Solution_cs;
        auto Result = Solution_cs.findAndReplacePattern(words, pattern);
        printf("Result value size is %d, true=%d, false=%d\n", Result.size(), true, false);
        for (size_t i = 0; i < Result.size(); i++)
        {
            printf("Result[%d]=%s\n", i, Result[i].c_str());
        }
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: words = {\"a\", \"b\", \"c\"}, pattern = \"a\" \n");
    printf("expected result: {[a], [b], [c]}\n");
    {
        vector<string> words = {"a", "b", "c"};
        string pattern = "a";

        Solution Solution_cs;
        auto Result = Solution_cs.findAndReplacePattern(words, pattern);
        printf("Result value size is %d, true=%d, false=%d\n", Result.size(), true, false);
        for (size_t i = 0; i < Result.size(); i++)
        {
            printf("Result[%d]=%s\n", i, Result[i].c_str());
        }
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: words = {\"abc\", \"cba\", \"xyx\", \"yxx\", \"yyx\"}, pattern = \"abc\" \n");
    printf("expected result: {[abc], [cba]}\n");
    {
        vector<string> words = {"abc", "cba", "xyx", "yxx", "yyx"};
        string pattern = "abc";

        Solution Solution_cs;
        auto Result = Solution_cs.findAndReplacePattern(words, pattern);
        printf("Result value size is %d, true=%d, false=%d\n", Result.size(), true, false);
        for (size_t i = 0; i < Result.size(); i++)
        {
            printf("Result[%d]=%s\n", i, Result[i].c_str());
        }
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: words = {\"ktittgzawn\", \"dgphvfjniv\", \"gceqobzmis\", \"alrztxdlah\", \"jijuevoioe\", \"mawiizpkub\", \"onwpmnujos\", \"zszkptjgzj\", \"zwfvzhrucv\", \"isyaphcszn\"}\n");
    printf("input: pattern = pattern = \"zdqmjnczma\"\n");
    printf("expected result: {[]}\n");
    {
        vector<string> words = {"ktittgzawn", "dgphvfjniv", "gceqobzmis", "alrztxdlah", "jijuevoioe", "mawiizpkub", "onwpmnujos", "zszkptjgzj", "zwfvzhrucv", "isyaphcszn"};
        string pattern = "zdqmjnczma";

        Solution Solution_cs;
        auto Result = Solution_cs.findAndReplacePattern(words, pattern);
        printf("Result value size is %d, true=%d, false=%d\n", Result.size(), true, false);
        for (size_t i = 0; i < Result.size(); i++)
        {
            printf("Result[%d]=%s\n", i, Result[i].c_str());
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
