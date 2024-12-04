// ConsoleApp_Remove_Duplicate_Letters.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
private:
    
    unordered_set<char> store_char_set;    // the char already stored in database

    string removeDupChar(string s){
        // reference: https://mocowcow.github.io/leetcode-316-remove-duplicate-letters/
        string res = "0";  // this could easily to judge if last-char is smaller than cur-char
        int char_counter[26] = {0};     // record appear counter for each char
        int curIdx = 0;

        for (int i = 0; i < s.size(); i++)
            char_counter[s[i] - 'a']++;

        while (curIdx < s.size())
        {
            char_counter[s[curIdx] - 'a']--;
            // auto cur_char = s[curIdx];
            // printf("cur_ch:%c >>>\n", cur_char);
            if (store_char_set.count(s[curIdx]) == 0){
                // printf(" appear ONLY once,\n");

                auto prev_char = res.back();
                // current char is smaller than previous char
                // and previous char will appear later
                while (prev_char > s[curIdx])
                {
                    // printf("<while> prev_char:%c, curIdx:%d, s[curIdx]:%c\n", prev_char, curIdx, s[curIdx]);
                    if (char_counter[prev_char - 'a']){
                        // previous char will appear again later
                        // STEP1: remove the previous char
                        res.pop_back();
                        store_char_set.erase(prev_char);
                    }else{
                        // previous char WON'T appear again later
                        break;
                    }
                    prev_char = res.back();
                    // printf("<while> check again, prev_char:%c\n", prev_char);
                    if (prev_char == '0'){
                        // res is EMPTY, exit
                        break;
                    }
                }

                // current char is bigger than previous char
                // STEP2: insert the current char
                res.push_back(s[curIdx]);
                store_char_set.insert(s[curIdx]);
                
            }else{
                // printf(" appear twice.\n");
            }
            
            curIdx++;
        }

        return res.erase(0, 1);  // filter the first char for the final result
        
    }

public:
    string removeDuplicateLetters(string s) {
        // solution 1 (keven, using hash and array to solve)
        {
            return removeDupChar(s);
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Remove Duplicate Letters, Algorithm(Monotonic Stack)!\n";
    cout << "https://leetcode.com/problems/remove-duplicate-letters/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: s = \"bcabc\"\n");
    printf("expected result: output = \"abc\"\n");
    {
        string s = "bcabc";
        Solution solution;
        auto res = solution.removeDuplicateLetters(s);
        printf("res size is %d\n", res.size());
        if (res.size()) printf("res is %s\n", res.c_str());
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: s = \"cbacdcbc\"\n");
    printf("expected result: output = \"acdb\"\n");
    {
        string s = "cbacdcbc";
        Solution solution;
        auto res = solution.removeDuplicateLetters(s);
        printf("res size is %d\n", res.size());
        if (res.size()) printf("res is %s\n", res.c_str());
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: s = \"ccacbaba\"\n");
    printf("expected result: output = \"acb\"\n");
    {
        string s = "ccacbaba";
        Solution solution;
        auto res = solution.removeDuplicateLetters(s);
        printf("res size is %d\n", res.size());
        if (res.size()) printf("res is %s\n", res.c_str());
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: s = \"leetcode\"\n");
    printf("expected result: output = \"letcod\"\n");
    {
        string s = "leetcode";
        Solution solution;
        auto res = solution.removeDuplicateLetters(s);
        printf("res size is %d\n", res.size());
        if (res.size()) printf("res is %s\n", res.c_str());
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 5 ****************************\n");
    printf("input: s = \"acbac\"\n");
    printf("expected result: output = \"abc\"\n");
    {
        string s = "acbac";
        Solution solution;
        auto res = solution.removeDuplicateLetters(s);
        printf("res size is %d\n", res.size());
        if (res.size()) printf("res is %s\n", res.c_str());
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
