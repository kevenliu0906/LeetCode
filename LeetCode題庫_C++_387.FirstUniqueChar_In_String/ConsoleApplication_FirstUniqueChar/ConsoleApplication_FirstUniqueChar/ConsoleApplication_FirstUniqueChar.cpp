// ConsoleApplication_FirstUniqueChar.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <map>
// #include <unordered_set>

using namespace std;

class Solution{
public:

    int firstUniqChar(string s){

        // solution - 1 (best answer)
        int count[26] = {0};  // record each char has how many count
        for (size_t i = 0; i < s.size(); i++)
        {
            count[s[i] - 'a']++;
        }
        for (size_t i = 0; i < s.size(); i++)
        {
            if(count[s[i] - 'a'] == 1)   // judgement the count of char is 1 in s sequentially
                return i;
        }
        return -1;
        
        
        // solution 2 (keven)
        multimap<string, int> substr_multimap_content_index;  // key:sub_string ; value:index

        for (size_t i = 0; i < s.size(); i++)
        {
            auto sub_content = s.substr(i, 1);
            substr_multimap_content_index.insert(pair<string, int>(sub_content, i));
        }
        
        string recordKey = substr_multimap_content_index.begin()->first;
        int recordValue = -1;
        int recordKeyCount = 0;
        map<int, string> NewSubStr_RemoveSameContent_multimap_index_content;   // key:index ; value:sub_string(non-repeat)
        for (auto sub_str_multimap_iter : substr_multimap_content_index)
        {
            // compare each other in different index
            auto currentKey = sub_str_multimap_iter.first;
            auto currentValue = sub_str_multimap_iter.second;
            
            if(currentKey != recordKey){
                if( recordKeyCount == 1 ){
                    NewSubStr_RemoveSameContent_multimap_index_content.insert(pair<int, string>(recordValue, recordKey));
                }
                // reset
                recordKeyCount = 1;
            } else{
                recordKeyCount++;
            }

            recordKey = currentKey;
            recordValue = currentValue;
        }
        // record the last one
        if( recordKeyCount == 1 ){
            NewSubStr_RemoveSameContent_multimap_index_content.insert(pair<int, string>(recordValue, recordKey));
        }

        // // debug stored Newmultimap content
        // for (auto newsubstr_multimap_iter : NewSubStr_RemoveSameContent_multimap_index_content)
        // {
        //     auto index = newsubstr_multimap_iter.first;
        //     auto content = newsubstr_multimap_iter.second;
        //     printf("<kd> newsubstr_multimap_iter[%d]=%s\n", index, content.c_str());
        // }
        // printf("---------------------\n");    

        if( NewSubStr_RemoveSameContent_multimap_index_content.size() )
            return NewSubStr_RemoveSameContent_multimap_index_content.begin()->first;
        
        return -1;
    }
};


int main()
{
    std::cout << "Hello LeetCode - First Unique Char in a String (HASH TABLE) !\n";

    printf("LeetCode - 387. First Unique Char In a String\n");
    cout << "https://leetcode.com/problems/first-unique-character-in-a-string" << endl << endl;
    // cout << "solution: https://medium.com/@zero.ling/c-sort-a-map-by-value-601a60ec0e01" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: s=\"leetcode\"\n");
    printf("expected result: 0\n");
    {
        string s = "leetcode";

        Solution Solution_cs;
        auto Result = Solution_cs.firstUniqChar(s);
        printf("Result value is %d\n", Result);

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: s=\"loveleetcode\"\n");
    printf("expected result: 2\n");
    {
        string s = "loveleetcode";

        Solution Solution_cs;
        auto Result = Solution_cs.firstUniqChar(s);
        printf("Result value is %d\n", Result);

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: s=\"aabb\"\n");
    printf("expected result: -1\n");
    {
        string s = "aabb";

        Solution Solution_cs;
        auto Result = Solution_cs.firstUniqChar(s);
        printf("Result value is %d\n", Result);

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
