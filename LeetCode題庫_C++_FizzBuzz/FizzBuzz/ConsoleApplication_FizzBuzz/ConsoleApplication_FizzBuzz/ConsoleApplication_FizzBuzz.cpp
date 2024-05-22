// ConsoleApplication_FizzBuzz.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        string sub_str = "";

        for (size_t i = 1; i <= n; i++)
        {
            if (i % 15 == 0)
                sub_str = "FizzBuzz";
            else if (i % 3 == 0)
                sub_str = "Fizz";
            else if (i % 5 == 0)
                sub_str = "Buzz";
            else
                sub_str = std::to_string(i);

            result.push_back(sub_str);
        }

        return result;
    }
};


int main()
{
    std::cout << "Hello LeetCode - FizzBuzz !\n";
    Solution _Solution;

    printf("****************************************\n");
    // Input: n = 3
    // Output: ["1", "2", "Fizz"]
    printf("test case 1, input 3\n");
    auto res = _Solution.fizzBuzz(3);
    for (size_t i = 0; i < res.size(); i++)
    {
        printf("%s\n", res[i].c_str());
    }
    printf("****************************************\n");

    printf("\n\n");

    printf("****************************************\n");
    // Input: n = 5
    // Output: ["1", "2", "Fizz", "4", "Buzz"]
    printf("test case 2, input 5\n");
    res = _Solution.fizzBuzz(5);
    for (size_t i = 0; i < res.size(); i++)
    {
        printf("%s\n", res[i].c_str());
    }
    printf("****************************************\n");

    printf("\n\n");

    printf("****************************************\n");
    // Input: n = 15
    // Output: ["1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz"]
    printf("test case 3, input 15\n");
    res = _Solution.fizzBuzz(15);
    for (size_t i = 0; i < res.size(); i++)
    {
        printf("%s\n", res[i].c_str());
    }
    printf("****************************************\n");
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
