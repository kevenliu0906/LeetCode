// Console_SortCharByFrequency.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
// #include <vector>
// #include <set>

using namespace std;

class Solution{
private:
    enum CHAR_FORMAT{
        CHAR_FORMS_NUMCASE = 1,
        CHAR_FORMS_UPPERCASE,
        CHAR_FORMS_LOWERCASE,
    };

    char GetCharFromNum(int Num, CHAR_FORMAT format){

        char CharSymbol = '\0';

        if( format == CHAR_FORMAT::CHAR_FORMS_UPPERCASE ){
            CharSymbol = (char)(Num + 'A');
        }
        else if( format == CHAR_FORMAT::CHAR_FORMS_LOWERCASE ){
            CharSymbol = (char)(Num + 'a');
        }
        else if( format == CHAR_FORMAT::CHAR_FORMS_NUMCASE ){
            CharSymbol = (char)(Num + '0');
        }

        return CharSymbol;
    }

public:

    string frequencySort(string s){

        string result;

        // solution 1 (keven, best)
        int CharCount_ForNumCase[10] = {0};      // CharCount_ForNumCase[0]~CharCount_ForNumCase[9]: store '0'~'9'
        int CharCount_ForLowerCase[26] = {0};    // CharCount_ForLowerCase[0]~CharCount_ForLowerCase[25]: store 'a'~'z', 
        int CharCount_ForUpperCase[26] = {0};    // CharCount_ForUpperCase[0]~CharCount_ForUpperCase[25]: store 'A'~'Z'
        multimap<int, char> CharCount_Char_MultiMap;    // key: char-count, value: char

        // STEP1: encounter for each char 
        for (size_t i = 0; i < s.size(); i++)
        {
            auto Gap = s[i] - '0';
            // printf("Gap:%d from s[%d]:%c to '0'\n", Gap, i, s[i]);
            if( Gap <= 9 ){      // means s[i] is '0'~'9'
                CharCount_ForNumCase[Gap]++;
            }else{
                Gap = s[i] - 'A';
                // printf("Gap:%d from s[%d]:%c to 'A'\n", Gap, i, s[i]);
                if( Gap < 26 ){  // means s[i] is 'A'~'Z'
                    CharCount_ForUpperCase[Gap]++;
                }else{           // means s[i] is 'a'~'z'
                    Gap = s[i] - 'a';
                    // printf("Gap:%d from s[%d]:%c to 'a'\n", Gap, i, s[i]);
                    CharCount_ForLowerCase[Gap]++;
                }
            }
            // 
            // auto Gap = s[i] - 'A';
            // // printf("Gap:%d from s[%d]=%c\n", Gap, i, s[i]);
            // if( Gap >= 26 ){   // means s[i] is a~z
            //     Gap = s[i] - 'a';
            //     CharCount_ForLowerCase[Gap + 1]++;
            // }else{             // means s[i] is A~Z
            //     CharCount_ForUpperCase[Gap + 1]++;
            // }
        }
        
        // // debug the elements for CharCount_ForNumCase & CharCount_ForUpperCase & CharCount_ForLowerCase
        // printf("NumCase:\n");
        // for (size_t i = 0; i < 10; i++)
        // {
        //     printf("%d, ", CharCount_ForNumCase[i]);
        // }
        // printf("\n\n");

        // printf("UpperCase:\n");
        // for (size_t i = 0; i < 26; i++)
        // {
        //     printf("%d, ", CharCount_ForUpperCase[i]);
        // }
        // printf("\n\n");

        // printf("LowerCase:\n");
        // for (size_t i = 0; i < 26; i++)
        // {
        //     printf("%d, ", CharCount_ForLowerCase[i]);
        // }
        // printf("\n\n");
        
        // STEP2: insert data into multimap from UpperCase array & LowerCase array
        for (size_t i = 0; i < 26; i++)
        {
            char charName = '\0';
            if( (i < sizeof(CharCount_ForNumCase)/sizeof(CharCount_ForNumCase[0])) && CharCount_ForNumCase[i] != 0 ){
                charName = GetCharFromNum(i, CHAR_FORMS_NUMCASE);
                CharCount_Char_MultiMap.insert(pair<int, char>(CharCount_ForNumCase[i], charName));
            }
            if( CharCount_ForLowerCase[i] != 0 ){
                charName = GetCharFromNum(i, CHAR_FORMS_LOWERCASE);
                CharCount_Char_MultiMap.insert(pair<int, char>(CharCount_ForLowerCase[i], charName));
            }
            if( CharCount_ForUpperCase[i] != 0 ){
                charName = GetCharFromNum(i, CHAR_FORMS_UPPERCASE);
                CharCount_Char_MultiMap.insert(pair<int, char>(CharCount_ForUpperCase[i], charName));
            }
        }
        // // debug the element for CharCount_Char_MultiMap
        // for (auto CharCount_Char_MultiMap_each : CharCount_Char_MultiMap)
        // {
        //     printf("key:%d - value:%c\n", CharCount_Char_MultiMap_each.first, CharCount_Char_MultiMap_each.second);
        // }

        // STEP3: append each char with counts (increasing order)
        for (auto CharCount_Char_MultiMap_each : CharCount_Char_MultiMap)
        {
            string single_str = "";
            auto char_count = CharCount_Char_MultiMap_each.first;
            for (size_t i = 0; i < char_count; i++)
            {
                auto char_symbol = CharCount_Char_MultiMap_each.second;
                single_str.append(1, char_symbol);
            }
            result.append(single_str);
        }
        // // debug the result content
        // printf("after STEP3, result:%s\n", result.c_str());
        
        
        // STEP4: Reverse to decreasing order
        auto ReverseResult = result;
        result = "";
        result.append(ReverseResult.rbegin(), ReverseResult.rend());
        
        
        return result;
    }
};

int main()
{
    std::cout << "Hello LeetCode - Sort Character By Frequency, DataStructure (HASH TABLE, String)!\n";

    printf("LeetCode - 451. Sort Character By Frequency\n");
    cout << "https://leetcode.com/problems/sort-characters-by-frequency/" << endl << endl;
    // cout << "solution: https://medium.com/@zero.ling/c-sort-a-map-by-value-601a60ec0e01" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: s = \"tree\"\n");
    printf("expected result: \"eert\"\n");
    {
        string s = "tree";

        Solution Solution_cs;
        auto Result = Solution_cs.frequencySort(s);

        printf("Result value size is %s, true=%d, false=%d\n", Result.c_str(), true, false);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: s = \"cccaaa\"\n");
    printf("expected result: \"aaaccc\"\n");
    {
        string s = "cccaaa";

        Solution Solution_cs;
        auto Result = Solution_cs.frequencySort(s);

        printf("Result value size is %s, true=%d, false=%d\n", Result.c_str(), true, false);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: s = \"Aabb\"\n");
    printf("expected result: \"bbAa\"\n");
    {
        string s = "Aabb";

        Solution Solution_cs;
        auto Result = Solution_cs.frequencySort(s);

        printf("Result value size is %s, true=%d, false=%d\n", Result.c_str(), true, false);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: s = \"2a554442f544asfasssffffasss\"\n");
    printf("expected result: \"sssssssffffff44444aaaa55522\"\n");
    {
        string s = "2a554442f544asfasssffffasss";

        Solution Solution_cs;
        auto Result = Solution_cs.frequencySort(s);

        printf("Result value size is %s, true=%d, false=%d\n", Result.c_str(), true, false);
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
