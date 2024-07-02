// Console_Unique_Morse_Code_Words.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <set>

using namespace std;

class Solution{
public:
    string MorseEncode(char letter){
        
        string EncodeStr;

        switch(letter)
        {
            case 'a':
                EncodeStr = ".-";
            break;
            case 'b':
                EncodeStr = "-...";
            break;
            case 'c':
                EncodeStr = "-.-.";
            break;
            case 'd':
                EncodeStr = "-..";
            break;
            case 'e':
                EncodeStr = ".";
            break;
            case 'f':
                EncodeStr = "..-.";
            break;
            case 'g':
                EncodeStr = "--.";
            break;
            case 'h':
                EncodeStr = "....";
            break;
            case 'i':
                EncodeStr = "..";
            break;
            case 'j':
                EncodeStr = ".---";
            break;
            case 'k':
                EncodeStr = "-.-";
            break;
            case 'l':
                EncodeStr = ".-..";
            break;
            case 'm':
                EncodeStr = "--";
            break;
            case 'n':
                EncodeStr = "-.";
            break;
            case 'o':
                EncodeStr = "---";
            break;
            case 'p':
                EncodeStr = ".--.";
            break;
            case 'q':
                EncodeStr = "--.-";
            break;
            case 'r':
                EncodeStr = ".-.";
            break;
            case 's':
                EncodeStr = "...";
            break;
            case 't':
                EncodeStr = "-";
            break;
            case 'u':
                EncodeStr = "..-";
            break;
            case 'v':
                EncodeStr = "...-";
            break;
            case 'w':
                EncodeStr = ".--";
            break;
            case 'x':
                EncodeStr = "-..-";
            break;
            case 'y':
                EncodeStr = "-.--";
            break;
            case 'z':
                EncodeStr = "--..";
            break;
        }

        return EncodeStr;
    }

    int uniqueMorseRepresentations(vector<string> &words){

        int Result = 0;
        // vector<string> words_morses;
        set<string> words_morses_set;

        // solution 1 (keven)
        for (size_t i = 0; i < words.size(); i++)
        {
            // printf("***********************************************\n");
            auto current_word = words[i];
            string current_word_morse;
            for (size_t j = 0; j < current_word.size(); j++)
            {
                auto morse = MorseEncode(current_word[j]);
                current_word_morse += morse;
            }
            // printf("Loop:%d, current word:%s, current word morse:%s\n", i, current_word.c_str(), current_word_morse.c_str());
            // words_morses.push_back(current_word_morse);
            words_morses_set.insert(current_word_morse);
            // printf("***********************************************\n\n");
        }

        Result = words_morses_set.size();

        return Result;
    }
};

int main()
{
    std::cout << "Hello LeetCode - Unique Morse Code Words, DataStructure (HASH TABLE, Array, String)!\n";

    printf("LeetCode - 804. Unique Morsoinf\n");
    cout << "https://leetcode.com/problems/unique-morse-code-words" << endl << endl;
    // cout << "solution: https://medium.com/@zero.ling/c-sort-a-map-by-value-601a60ec0e01" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: words = [\"gin\", \"zen\", \"gig\", \"msg\"]\n");
    printf("expected result: 2\n");
    {
        vector<string> words = {"gin", "zen", "gig", "msg"};

        Solution Solution_cs;
        auto Result = Solution_cs.uniqueMorseRepresentations(words);

        printf("Result value size is %d, true=%d, false=%d\n", Result, true, false);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: words = [\"a\"]\n");
    printf("expected result: 1\n");
    {
        vector<string> words = {"a"};

        Solution Solution_cs;
        auto Result = Solution_cs.uniqueMorseRepresentations(words);

        printf("Result value size is %d, true=%d, false=%d\n", Result, true, false);
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
