// ConsoleApplication_RomanToInteger.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>

using namespace std;

class Solution{
public:
    int RomonToInt_Fn(char Roman){
        int result;
        switch(Roman)
        {
            case 'I':
                result = 1;
            break;
            case 'V':
                result = 5;
            break;
            case 'X':
                result = 10;
            break;
            case 'L':
                result = 50;
            break;
            case 'C':
                result = 100;
            break;
            case 'D':
                result = 500;
            break;
            case 'M':
                result = 1000;
            break;
            default:
                result = -1;
            break;
        }

        return result;
    }

    int romanToInt(string s){
        // storage the database for search corresponding value from Roman symbol
        unordered_map<string, int> RomanToInt;

        int result = 0;
        int last_sub_value = 0;
        
        RomanToInt.insert(pair<string, int>{"I", 1});
        RomanToInt.insert(pair<string, int>{"V", 5});
        RomanToInt.insert(pair<string, int>{"X", 10});
        RomanToInt.insert(pair<string, int>{"L", 50});
        RomanToInt.insert(pair<string, int>{"C", 100});
        RomanToInt.insert(pair<string, int>{"D", 500});
        RomanToInt.insert(pair<string, int>{"M", 1000});


        for (size_t i = 0; i < s.size(); i++)
        {
            string current_sub_str = s.substr(i, 1);
            
            // auto current_sub_map = RomanToInt.find(current_sub_str);
            // auto current_sub_value = current_sub_map->second;
            auto current_sub_value = RomonToInt_Fn(*(current_sub_str.c_str()));  //using switch case will faster than map

            // string next_sub_str;
            // int next_sub_value = 0;
            
            // // judgement if the next char is smaller than current char
            // if( i != s.size() - 1 ){
            //     next_sub_str = s.substr(i + 1, 1);
            //     auto next_sub_map = RomanToInt.find(next_sub_str);
            //     next_sub_value = next_sub_map->second;
            // }

            if( i == 0 ){
                // represent the first check sub-string
                result += current_sub_value;
            }else{

                if( (last_sub_value >= current_sub_value) ){
                    result += current_sub_value;
                }else{
                    // 1st. restor the value
                    result -= last_sub_value;

                    // 2nd. add current value 
                    result += current_sub_value;
                    // 3rd. substract last value
                    result -= last_sub_value;
                }
            }

            last_sub_value = current_sub_value;
        }
        
        return result;
    }
};

int main()
{
    std::cout << "Hello LeetCode - Roman to Integer, DataStructure (HASH TABLE) !\n";

    printf("LeetCode - 13. Roman to Integer\n");
    cout << "https://leetcode.com/problems/roman-to-integer/" << endl << endl;
    // cout << "solution: https://blog.techbridge.cc/2017/01/21/simple-hash-table-intro/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: string= \"III\" \n");
    printf("expected result: 3\n");
    {
        string s = "III";
        
        Solution Solution_cs;
        auto Result = Solution_cs.romanToInt(s);
        printf("Result value is %d\n", Result);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: string= \"LVIII\" \n");
    printf("expected result: 58\n");
    {
        string s = "LVIII";
        
        Solution Solution_cs;
        auto Result = Solution_cs.romanToInt(s);
        printf("Result value is %d\n", Result);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: string= \"IV\" \n");
    printf("expected result: 4\n");
    {
        string s = "IV";
        
        Solution Solution_cs;
        auto Result = Solution_cs.romanToInt(s);
        printf("Result value is %d\n", Result);
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: string= \"MCMXCIV\" \n");
    printf("expected result: 1994\n");
    {
        string s = "MCMXCIV";
        
        Solution Solution_cs;
        auto Result = Solution_cs.romanToInt(s);
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
