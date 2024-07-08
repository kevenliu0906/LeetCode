// ConsoleApplication_Is_Subsequence.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <map>


using namespace std;

class Solution{
public:
    bool isSubsequence(string s, string t) {

        // solution 1 (keven, best)
        {
            for (int i = 0;  i < s.size(); i++){
                auto found_pos = t.find(s[i]);
                // printf("(found)t:%s, s[%d]:%c, found_pos:%d\n", t.c_str(), i, s[i], found_pos);
                if( found_pos == string::npos )
                    return false;
                t.erase(0, found_pos + 1);
                // printf("(erase)t:%s, size(t):%d\n", t.c_str(), t.size());
            }
            return true;
        }

        // solution 2 (keven)
        {
            // auto t_start = t.begin();
            // auto t_end = t.end() - 1;
            // int s_start_index = 0;
            // int s_end_index = s.size() - 1;

            int s_start_index = 0;
            auto t_start = t.begin();

            while( t.begin() <= (t.end() - 1) ){

                printf("s[0]:%c, s:%s, t:%s\n", s[0], s.c_str(), t.c_str());
                // for start_index(judge if element of s exist on t or not)                
                if ( t.find(s[0]) == string::npos )
                    return false;
                while ( *(t.begin()) != s[0] ) {
                    if(t.size() < 1){
                        printf("(start element) there is no element to erase\n");
                        return false;
                    }
                    printf("erase element (start) >>> t:%c\n", *(t.begin()));
                    t.erase(0, 1);
                    // t_start = t.begin();
                }
                printf("after erase (start) >>> t:%s\n", t.c_str());

                // s_end_index = s.size() - 1;
                // t_end = t.end() - 1;
                printf("s[%d]:%c, s:%s, t:%s\n", s.size() - 1, s[s.size() - 1], s.c_str(), t.c_str());
                // for end_index(judge if element of s exist on t or not)
                if( t.find(s[s.size() - 1]) == string::npos )
                    return false;
                while ( *(t.end() - 1) != s[s.size() - 1] ) {
                    if(t.size() < 1){
                        printf("(end element) there is no element to erase\n");
                        return false;
                    }
                    printf("erase element (end) >>> t:%c\n", *(t.end() - 1));
                    t.erase(t.size() - 1, 1);
                    // t_end = t.end() - 1;
                }
                printf("after erase (end) >>> t:%s\n", t.c_str());

                if( t.begin() > t.end() )
                    break;

                printf("<kd> found string:%s\n", t.c_str());
                break;

                // t_start++;
                // t_end--;

                // s_start_index++;
                // s_end_index--;
            }

            return false;
        }

        // // solution 3 (keven, have bug, when s:ab, t:baab)
        // {

        //     unordered_map<char, int> t_char_index_unorderedmap;
        //     for(int i = 0; i < t.size(); i++){
        //         t_char_index_unorderedmap.insert(pair<char, int>(t[i], i));
        //     }

        //     // // for debug the element in unordered_map for t
        //     // for(auto t_char_index_unorderedmap_each : t_char_index_unorderedmap){
        //     //     printf("t_char_index_unorderedmap[%c]=%d\n", t_char_index_unorderedmap_each.first, t_char_index_unorderedmap_each.second);
        //     // }

        //     int beforeFoundIndex = -1;
        //     for (size_t i = 0; i < s.size(); i++)
        //     {
        //         if ( !t_char_index_unorderedmap.count(s[i]) )
        //             return false;
        //         auto currentFoundIndex = t_char_index_unorderedmap[s[i]];
        //         // printf("i:%d, beforeFoundIndex:%d, currentFoundIndex:%d\n", i, beforeFoundIndex, currentFoundIndex);
        //         if (beforeFoundIndex > currentFoundIndex)
        //             return false;
        //         t_char_index_unorderedmap.erase(s[i]);
        //         beforeFoundIndex = currentFoundIndex;
        //     }
            

        //     return true;
        // }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Is Subsequence, Algorithm (Two Pointer, Dynamic Programming)!\n";

    printf("LeetCode - 392. Is Subsequence\n");
    cout << "https://leetcode.com/problems/is-subsequence" << endl << endl;
    // cout << "solution: https://medium.com/@zero.ling/c-sort-a-map-by-value-601a60ec0e01" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: s = \"abc\", t = \"ahbgdc\"\n");
    printf("expected result: true\n");
    {

        Solution solution;
        string s = "abc";
        string t = "ahbgdc";
        
        auto IsSubsequency = solution.isSubsequence(s, t);
        printf("Result:%d, true:%d, false:%d\n", IsSubsequency, true, false);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: s = \"axc\", t = \"ahbgdc\"\n");
    printf("expected result: false\n");
    {

        Solution solution;
        string s = "axc";
        string t = "ahbgdc";
        
        auto IsSubsequency = solution.isSubsequence(s, t);
        printf("Result:%d, true:%d, false:%d\n", IsSubsequency, true, false);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: s = \"acb\", t = \"ahbgdc\"\n");
    printf("expected result: false\n");
    {

        Solution solution;
        string s = "acb";
        string t = "ahbgdc";
        
        auto IsSubsequency = solution.isSubsequence(s, t);
        printf("Result:%d, true:%d, false:%d\n", IsSubsequency, true, false);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: s = \"aaaaaa\", t = \"bbaaaa\"\n");
    printf("expected result: false\n");
    {

        Solution solution;
        string s = "aaaaaa";
        string t = "bbaaaa";
        
        auto IsSubsequency = solution.isSubsequence(s, t);
        printf("Result:%d, true:%d, false:%d\n", IsSubsequency, true, false);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 5 ****************************\n");
    printf("input: s = \"ab\", t = \"baab\"\n");
    printf("expected result: true\n");
    {

        Solution solution;
        string s = "ab";
        string t = "baab";

        auto IsSubsequency = solution.isSubsequence(s, t);
        printf("Result:%d, true:%d, false:%d\n", IsSubsequency, true, false);
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
