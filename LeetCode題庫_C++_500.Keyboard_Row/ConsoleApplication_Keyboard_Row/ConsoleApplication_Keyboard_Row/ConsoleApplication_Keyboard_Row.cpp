// ConsoleApplication_Keyboard_Row.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
    int KBRow_index(char tmp_c){
        int Index = -1;
        switch(tmp_c)
        {
            case 'q':
            case 'Q':
            case 'w':
            case 'W':
            case 'e':
            case 'E':
            case 'r':
            case 'R':
            case 't':
            case 'T':
            case 'y':
            case 'Y':
            case 'u':
            case 'U':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'p':
            case 'P':
                Index = 1;
            break;
            case 'a':
            case 'A':
            case 's':
            case 'S':
            case 'd':
            case 'D':
            case 'f':
            case 'F':
            case 'g':
            case 'G':
            case 'h':
            case 'H':
            case 'j':
            case 'J':
            case 'k':
            case 'K':
            case 'l':
            case 'L':
                Index = 2;
            break;
            case 'z':
            case 'Z':
            case 'x':
            case 'X':
            case 'c':
            case 'C':
            case 'v':
            case 'V':
            case 'b':
            case 'B':
            case 'n':
            case 'N':
            case 'm':
            case 'M':
                Index = 3;
            break;
        }

        return Index;
    }
    vector<string> findWords(vector<string> &words){

        vector<string> result;

        // solution 1 (keven, best)
        for (size_t i = 0; i < words.size(); i++)
        {
            auto each_word = words[i];
            int recordRowIndex = 0;
            bool OneRow = true;
            for (size_t j = 0; j < each_word.size(); j++)
            {
                auto currentRowIndex = KBRow_index(each_word[j]);
                if(recordRowIndex == 0)
                    recordRowIndex = currentRowIndex;
                else{
                    if(currentRowIndex != recordRowIndex){
                        OneRow = false;
                        break;
                    }
                }
            }
            if( OneRow )
                result.push_back(each_word);
        }

        return result;
    }
};

int main()
{
    std::cout << "Hello LeetCde - Keyboard Row, DataStructure (HASH TABLE, Array)!\n";

    printf("LeetCode - 496. Next Greater Element I\n");
    cout << "https://leetcode.com/problems/keyboard-row/" << endl << endl;
    // cout << "solution: https://medium.com/@zero.ling/c-sort-a-map-by-value-601a60ec0e01" << endl;
    

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: words = [\"Hello\", \"Alaska\", \"Dad\", \"Peace\"]\n");
    printf("expected result: [\"Alaska\", \"Dad\"]\n");
    {
        vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};

        Solution Solution_cs;
        auto Result = Solution_cs.findWords(words);
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
    printf("input: words = [\"omk\"]\n");
    printf("expected result: [\"\"]\n");
    {
        vector<string> words = {"omk"};

        Solution Solution_cs;
        auto Result = Solution_cs.findWords(words);
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
    printf("input: words = [\"adsdf\", \"sfd\"]\n");
    printf("expected result: [\"adsdf\", \"sfd\"]\n");
    {
        vector<string> words = {"adsdf", "sfd"};

        Solution Solution_cs;
        auto Result = Solution_cs.findWords(words);
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
