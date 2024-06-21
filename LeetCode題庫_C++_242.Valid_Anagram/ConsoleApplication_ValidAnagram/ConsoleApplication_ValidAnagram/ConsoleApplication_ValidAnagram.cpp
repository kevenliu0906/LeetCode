// ConsoleApplication_ValidAnagram.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        string source = s;
        string target = t;

        // solution 1
        // sort source and target, then compare source and target, if source == target, return true, else return false
        {
            sort(source.begin(), source.end());
            sort(target.begin(), target.end());

            if( source == target )
                return true;
            return false;
        }

        // solution 2
        sort(source.begin(), source.end());
        sort(target.begin(), target.end());

        map<string, int> source_map_content_count;  // key: content, value: content count
        map<string, int> target_map_content_count;  // key: content, value: content count

        int RecordCharCount;
        string RecordString;
        string CurrentString;

        // ------ for source
        RecordCharCount = 0;
        RecordString = source.substr(0, 1);  // record is source[0]
        for (size_t i = 0; i < source.size(); i++)
        {
            CurrentString = source.substr(i, 1);  // start from source[0]
            if(CurrentString == RecordString){
                RecordCharCount++;
                // the last one case
                if( i == source.size() - 1){
                    source_map_content_count.insert(pair<string, int>(RecordString, RecordCharCount));
                }
            }else{
                // record it before change to the next
                source_map_content_count.insert(pair<string, int>(RecordString, RecordCharCount));

                // change to the next
                RecordString = CurrentString;
                RecordCharCount = 1;

                // the last one case
                if( i == source.size() - 1){
                    source_map_content_count.insert(pair<string, int>(RecordString, RecordCharCount));
                }
            }
        }
        // debug 
        for ( auto source_map_iter : source_map_content_count )
        {
            printf("<kd> source_map_iter[%s]:%d\n", source_map_iter.first.c_str(), source_map_iter.second);
        }
        // -----------------------------------------------------------------------

        // ------ for target
        RecordCharCount = 0;
        RecordString = target.substr(0, 1);  // record is target[0]
        for (size_t i = 0; i < target.size(); i++)
        {
            CurrentString = target.substr(i, 1);  // start from target[0]
            if(CurrentString == RecordString){
                RecordCharCount++;
                // the last one case
                if( i == target.size() - 1){
                    target_map_content_count.insert(pair<string, int>(RecordString, RecordCharCount));
                }
            }else{
                // record it before change to the next
                target_map_content_count.insert(pair<string, int>(RecordString, RecordCharCount));

                // change to the next
                RecordString = CurrentString;
                RecordCharCount = 1;

                // the last one case
                if( i == target.size() - 1){
                    target_map_content_count.insert(pair<string, int>(RecordString, RecordCharCount));
                }
            }
        }
        // debug 
        for ( auto target_map_iter : target_map_content_count )
        {
            printf("<kd> target_map_iter[%s]:%d\n", target_map_iter.first.c_str(), target_map_iter.second);
        }
        // -----------------------------------------------------------------------

        // compare each value of the key for source to target
        for (auto source_map_iter : source_map_content_count)
        {
            auto source_content = source_map_iter.first;

            // printf("<kd> compare-loop, source_content:%s, source_count:%d, target_map_content_count:%d, target_map_content_count[%s]:%d\n", 
            //           source_content.c_str(),
            //           source_map_iter.second,
            //           target_map_content_count.count(source_content),
            //           source_content.c_str(),
            //           target_map_content_count[source_content]);

            // current source content does NOT exist in target map
            if( !target_map_content_count.count(source_content) )
                return false;

            if(source_map_iter.second != target_map_content_count[source_content])
                return false;
        }
        // compare each value of the key for target to source
        for (auto target_map_iter : target_map_content_count)
        {
            auto targt_content = target_map_iter.first;

            // printf("<kd> compare-loop, targt_content:%s, target_count:%d, source_map_content_count:%d, source_map_content_count[%s]:%d\n", 
            //           targt_content.c_str(),
            //           target_map_iter.second,
            //           source_map_content_count.count(targt_content),
            //           targt_content.c_str(),
            //           source_map_content_count[targt_content]);

            // current source content does NOT exist in target map
            if( !source_map_content_count.count(targt_content) )
                return false;

            if(target_map_iter.second != source_map_content_count[targt_content])
                return false;
        }

        return true;       
    }
};

int main()
{
    std::cout << "Hello LeetCode - Valid Anagram, DataStructure (HASH TABLE)!\n";

    printf("LeetCode - 242. Valid Anagram\n");
    cout << "https://leetcode.com/problems/valid-anagram" << endl << endl;
    cout << "solution: https://medium.com/roywannago-%E6%97%85%E8%A1%8C%E4%B8%8D%E9%9C%80%E7%90%86%E7%94%B1/leetcode-%E5%88%B7%E9%A1%8C%E7%B4%80%E9%8C%84-242-valid-anagram-easy-1371a24af1c9/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: s = \"anagram\", t = \"nagaram\" \n");
    printf("expected result: true\n");
    {
        string s = "anagram";
        string t = "nagaram";

        Solution Solution_cs;
        auto Result = Solution_cs.isAnagram(s, t);
        printf("Result value is %d, true(%d), false(%d)\n", Result, true, false);

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: s = \"rat\", t = \"car\" \n");
    printf("expected result: false\n");
    {
        string s = "rat";
        string t = "car";

        Solution Solution_cs;
        auto Result = Solution_cs.isAnagram(s, t);
        printf("Result value is %d, true(%d), false(%d)\n", Result, true, false);

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: s = \"a\", t = \"a\" \n");
    printf("expected result: true\n");
    {
        string s = "a";
        string t = "a";

        Solution Solution_cs;
        auto Result = Solution_cs.isAnagram(s, t);
        printf("Result value is %d, true(%d), false(%d)\n", Result, true, false);

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: s = \"ab\", t = \"a\" \n");
    printf("expected result: false\n");
    {
        string s = "ab";
        string t = "a";

        Solution Solution_cs;
        auto Result = Solution_cs.isAnagram(s, t);
        printf("Result value is %d, true(%d), false(%d)\n", Result, true, false);

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 5 ****************************\n");
    printf("input: s = \"a\", t = \"b\" \n");
    printf("expected result: false\n");
    {
        string s = "a";
        string t = "b";

        Solution Solution_cs;
        auto Result = Solution_cs.isAnagram(s, t);
        printf("Result value is %d, true(%d), false(%d)\n", Result, true, false);

    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 6 ****************************\n");
    printf("input: s = \"a\", t = \"ab\" \n");
    printf("expected result: false\n");
    {
        string s = "a";
        string t = "ab";

        Solution Solution_cs;
        auto Result = Solution_cs.isAnagram(s, t);
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
