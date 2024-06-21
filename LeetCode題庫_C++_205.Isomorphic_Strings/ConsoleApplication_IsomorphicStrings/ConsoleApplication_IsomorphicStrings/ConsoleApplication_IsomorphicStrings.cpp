// ConsoleApplication_IsomorphicStrings.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <vector>


using namespace std;

class Solution{
public:
    bool isIsomorphic(string s, string t){

        unordered_map<string, int> source_map_content_index;
        unordered_map<string, int> target_map_content_index;

        for (size_t i = 0; i < s.size(); i++)
        {
            bool source_current_findindex_ = false;
            bool target_current_find_index_ = false;
            string source_content = s.substr(i, 1);
            string target_content = t.substr(i, 1);
            auto source_content_iter = source_map_content_index.find(source_content);
            if( source_content_iter != source_map_content_index.end() ){
                // source_content is exist on source_map
                source_current_findindex_ = true;
            }else{
                source_map_content_index.insert(pair<string, int>(source_content, i));
            }
            auto target_content_iter = target_map_content_index.find(target_content);
            if( target_content_iter != target_map_content_index.end() ){
                // target_content is exist on source_map
                target_current_find_index_ = true;
            }else{
                target_map_content_index.insert(pair<string, int>(target_content, i));
            }

            // (source: found BUT target: NOT found ) or (source: NOT found BUT target found it)
            if( (source_current_findindex_ && !target_current_find_index_) ||
                (!source_current_findindex_ && target_current_find_index_) )
                return false;
            
            // althrough both source & target found, but source found index is DIFFERENT from target found index
            if( source_current_findindex_ && target_current_find_index_ ){
                if( source_content_iter->second != target_content_iter->second )
                    return false;
            }
        }
        
        return true;
    }
};

int main()
{
    std::cout << "Hello LeetCode - Isomorphic Strings, DataStructure (HASH TABLE) !\n";

    printf("LeetCode - 205. Isomorphic Strings\n");
    cout << "https://leetcode.com/problems/isomorphic-strings" << endl << endl;
    // cout << "solution: https://blog.techbridge.cc/2017/01/21/simple-hash-table-intro/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: s = \"egg\", t = \"add\" \n");
    printf("expected result: true\n");
    {
        string s = "egg";
        string t = "add";

        Solution Solution_cs;
        auto Result = Solution_cs.isIsomorphic(s, t);
        printf("Result value is %d, true(%d), false(%d)\n", Result, true, false);

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: s = \"foo\", t = \"bar\" \n");
    printf("expected result: false\n");
    {
        string s = "foo";
        string t = "bar";

        Solution Solution_cs;
        auto Result = Solution_cs.isIsomorphic(s, t);
        printf("Result value is %d, true(%d), false(%d)\n", Result, true, false);

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: s = \"paper\", t = \"title\" \n");
    printf("expected result: true\n");
    {
        string s = "paper";
        string t = "title";

        Solution Solution_cs;
        auto Result = Solution_cs.isIsomorphic(s, t);
        printf("Result value is %d, true(%d), false(%d)\n", Result, true, false);

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: s = \"bbbaaaba\", t = \"aaabbbba\" \n");
    printf("expected result: false\n");
    {
        string s = "bbbaaaba";
        string t = "aaabbbba";

        Solution Solution_cs;
        auto Result = Solution_cs.isIsomorphic(s, t);
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
