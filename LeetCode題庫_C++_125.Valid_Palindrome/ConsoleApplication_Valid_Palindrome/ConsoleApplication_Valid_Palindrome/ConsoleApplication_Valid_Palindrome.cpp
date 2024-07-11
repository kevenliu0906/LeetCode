// ConsoleApplication_Valid_Palindrome.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

using namespace std;

class Solution{
public:
    bool isPalindrome(string s) {

        // solution 1 (keven)
        {
            // erase element that does NOT Alphanumeric
            string s_new;
            for (size_t i = 0; i < s.size(); i++)
            {
                
                if ( s[i] - 'a' >= 0 && s[i] - 'a' < 26 )
                {
                    // lower alphabet case
                    s_new.append(1, s[i]);
                }
                if( s[i] - 'A' >= 0 && s[i] - 'A' < 26 )
                {
                    // upper alphabet case, then transfer to lower alphabet
                    s_new.append(1, tolower(s[i]));
                }
                if( s[i] - '0' >= 0 && s[i] - '0' <= 9 )
                {
                    // numeric case
                    s_new.append(1, s[i]);
                }
            }

            // printf("s_new:%s\n", s_new.c_str());

            int left_index = 0;
            int right_index = s_new.size() - 1;

            while( left_index < right_index ){
                if (s_new[left_index] != s_new[right_index]) {
                    // printf("s_new_left[%d]:%c, s_new_right[%d]:%c\n", left_index, s_new[left_index], right_index, s_new[right_index]);
                    return false;
                }
                left_index++;
                right_index--;
            }

            return true;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Valid Palindrom, Algorithm(Two Pointers)!\n";
    printf("LeetCode - 125. Valid Palindrome\n");
    cout << "https://leetcode.com/problems/valid-palindrome" << endl << endl;
    // cout << "solution: https://mocowcow.github.io/leetcode-222-count-complete-tree-nodes/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: s = \"A man, a plan, a canal: Panama\"\n");
    printf("expected result: output = true\n");
    {
       string s = "A man, a plan, a canal: Panama";

        Solution solution;
        auto result = solution.isPalindrome(s);
        printf("result:%d, ture:%d, false:%d\n", result, true, false);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: s = \"race a car\"\n");
    printf("expected result: output = false\n");
    {
       string s = "race a car";

        Solution solution;
        auto result = solution.isPalindrome(s);
        printf("result:%d, ture:%d, false:%d\n", result, true, false);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: s = \" \"\n");
    printf("expected result: output = true\n");
    {
       string s = " ";

        Solution solution;
        auto result = solution.isPalindrome(s);
        printf("result:%d, ture:%d, false:%d\n", result, true, false);
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
