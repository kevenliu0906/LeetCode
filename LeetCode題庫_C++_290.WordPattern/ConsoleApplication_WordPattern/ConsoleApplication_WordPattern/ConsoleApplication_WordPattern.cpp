// ConsoleApplication_WordPattern.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution{
public:
    bool wordPattern(string pattern, string s){

        // step1: check the length of pattern is equal to the total count of sub-string in s
        string tmp_s = s;
        int size_tmp_s = 0;
        do
        {
            int space_index = tmp_s.find(" ", 0);
            if( space_index > 0 ){

            }else{
                // only has a string without space
                space_index = tmp_s.length() - 1;
            }
            size_tmp_s++;
            tmp_s = tmp_s.erase(0, space_index + 1);
        }while(tmp_s.size());

        if( pattern.size() != size_tmp_s ){
            // means the pattern count does NOT equal to total count of sub-string in s
            return false;
        }

        unordered_map<string, string> pattern_to_string;  // in order to check each sub-pattern is unique
        unordered_map<string, string> string_to_pattern;  // in order to check each sub-string is unique
        
        bool Result = true;
        for (size_t i = 0; i < pattern.size(); i++)
        {
            // get each pattern & sub-string to check
            auto current_pattern = pattern.substr(i, 1);
            auto space_index = s.find(" ", 0); 
            auto current_value = s.substr(0, space_index);
            // printf("<kd> loop:%d, current_pattern:%s, space_index:%d, current_value:%s\n", 
            //     i, current_pattern.c_str(), space_index, current_value.c_str());

            s = s.erase(0, space_index + 1);

            // step1: check if the current_pattern exist or not
            auto pattern_iter = pattern_to_string.find(current_pattern);
            if( pattern_iter == pattern_to_string.end() ){
                // current_pattern does NOT existed on map
                
                // step2: then, check if the value exist or not
                auto value_iter = string_to_pattern.find(current_value);

                if( value_iter != string_to_pattern.end() ){
                    // pattern NOT exist BUT value exist
                    Result = false;
                    return Result;
                }

                pattern_to_string.insert(pair<string, string>(current_pattern, current_value));
                string_to_pattern.insert(pair<string, string>(current_value, current_pattern));

            }else{
                // current_pattern existed existed on map
                // step2: then, check if the current_value equal to the value of current_pattern
                if( pattern_iter->second != current_value ){
                    Result = false;
                    return Result;
                }
            }
        }
        
        return Result;
    }
};

int main()
{
    std::cout << "Hello LeetCode - Word Pattern, DataStructure (HASH TABLE)!\n";

    printf("LeetCode - 290. Word Pattern\n");
    cout << "https://leetcode.com/problems/word-pattern" << endl << endl;
    // cout << "solution: https://blog.techbridge.cc/2017/01/21/simple-hash-table-intro/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: pattern = \"abba\", s = \"dog cat cat dog\" \n");
    printf("expected result: true\n");
    {
        string pattern = "abba";
        string s = "dog cat cat dog";

        Solution Solution_cs;
        auto Result = Solution_cs.wordPattern(pattern, s);
        printf("Result value is %d, true(%d), false(%d)\n", Result, true, false);

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: pattern = \"abba\", s = \"dog cat cat fish\" \n");
    printf("expected result: false\n");
    {
        string pattern = "abba";
        string s = "dog cat cat fish";

        Solution Solution_cs;
        auto Result = Solution_cs.wordPattern(pattern, s);
        printf("Result value is %d, true(%d), false(%d)\n", Result, true, false);

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: pattern = \"aaaa\", s = \"dog cat cat dog\" \n");
    printf("expected result: false\n");
    {
        string pattern = "aaaa";
        string s = "dog cat cat dog";

        Solution Solution_cs;
        auto Result = Solution_cs.wordPattern(pattern, s);
        printf("Result value is %d, true(%d), false(%d)\n", Result, true, false);

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: pattern = \"abba\", s = \"dog dog dog dog\" \n");
    printf("expected result: false\n");
    {
        string pattern = "abba";
        string s = "dog dog dog dog";

        Solution Solution_cs;
        auto Result = Solution_cs.wordPattern(pattern, s);
        printf("Result value is %d, true(%d), false(%d)\n", Result, true, false);

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 5 ****************************\n");
    printf("input: pattern = \"aba\", s = \"dog cat cat\" \n");
    printf("expected result: false\n");
    {
        string pattern = "aba";
        string s = "dog cat cat";

        Solution Solution_cs;
        auto Result = Solution_cs.wordPattern(pattern, s);
        printf("Result value is %d, true(%d), false(%d)\n", Result, true, false);

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 6 ****************************\n");
    printf("input: pattern = \"aaa\", s = \"aa aa aa aa\" \n");
    printf("expected result: false\n");
    {
        string pattern = "aaa";
        string s = "aa aa aa aa";

        Solution Solution_cs;
        auto Result = Solution_cs.wordPattern(pattern, s);
        printf("Result value is %d, true(%d), false(%d)\n", Result, true, false);

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
