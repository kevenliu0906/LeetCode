// Console_Excel_Sheet_Column_Number.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    int ch_to_num(char &ch){
        int num = 0;
        num = ch - 'A' + 1;
        return num;
    }
    int calc_num_from_str(string &str){
        int res = 0;
        int idx = 0;
        while (idx < str.size())
        {
            auto ch = str[idx];
            res =  (res*26) + ch_to_num(ch);
            // printf("idx:%d, ch:%c, ch_to_num:%d, res:%d\n", idx, ch, ch_to_num(ch), res);
            idx++;
        }

        return res;
    }
public:
    int titleToNumber(string columnTitle) {
        // solution 1 (keven, using substr to solve it)
        {
            auto res = calc_num_from_str(columnTitle);
            return res;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Excel Sheet Column Number, DataStructure(String)!\n";
    cout << "https://leetcode.com/problems/excel-sheet-column-number/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: columnTitle = \"A\"\n");
    printf("expected result: output = 1\n");
    {
        Solution solution;
        string columnTitle = "A";
        auto res = solution.titleToNumber(columnTitle);
        printf("res is %d\n", res);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: columnTitle = \"AB\"\n");
    printf("expected result: output = 28\n");
    {
        Solution solution;
        string columnTitle = "AB";
        auto res = solution.titleToNumber(columnTitle);
        printf("res is %d\n", res);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: columnTitle = \"ZY\"\n");
    printf("expected result: output = 701\n");
    {
        Solution solution;
        string columnTitle = "ZY";
        auto res = solution.titleToNumber(columnTitle);
        printf("res is %d\n", res);
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
