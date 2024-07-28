// Console_LetterCombine_of_PhoneNum.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string map_letter(char digit){
        
        string mapstring = "";
        
        switch(digit)
        {
            case '2':
                mapstring = "abc";
            break;
            case '3':
                mapstring = "def";
            break;
            case '4':
                mapstring = "ghi";
            break;
            case '5':
                mapstring = "jkl";
            break;
            case '6':
                mapstring = "mno";
            break;
            case '7':
                mapstring = "pqrs";
            break;
            case '8':
                mapstring = "tuv";
            break;
            case '9':
                mapstring = "wxyz";
            break;
        }

        return mapstring;
    }

    vector<string> letterCombinations(string digits) {

        // solution 1 (keven, using force directly)
        {
            vector<string> result;

            for (size_t i = 0; i < digits.size(); i++)
            {
                auto current_ch = *(digits.c_str() + i);
                // printf("i:%d, current_ch:%c\n", i, current_ch);
                auto current_string = map_letter(current_ch);
                // printf("i:%d, current_string:%s\n", i, current_string.c_str());
                if (result.size() == 0){
                    for (size_t j = 0; j < current_string.size(); j++)
                    {
                        auto current_string_sub = current_string.substr(j, 1);
                        // printf("i:%d, j:%d, current_string_sub:%s\n", i, j, current_string_sub.c_str());
                        result.push_back(current_string_sub);
                    }
                    
                }else{
                    // pop element from origin result to tmp
                    vector<string> tmp(result.begin(), result.end());
                    result.clear();

                    for (size_t j = 0; j < tmp.size(); j++)
                    {
                        for (size_t k = 0; k < current_string.size(); k++)                    
                        {
                            auto base = tmp[j];
                            auto current_string_sub = current_string.substr(k,1);
                            // printf("(before) i:%d, j:%d, base:%s, current_string_sub:%s\n", i, j, base.c_str(), current_string_sub.c_str());
                            base.append(current_string_sub);
                            // printf("(after) i:%d, j:%d, base:%s, current_string_sub:%s\n", i, j, base.c_str(), current_string_sub.c_str());
                            result.push_back(base);
                        }
                    }
                    
                }
                
            }
            
            return result;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Letter Combinations of a Phone Number, DataStructure(HASH TABLE)!\n";
    cout << "https://leetcode.com/problems/letter-combinations-of-a-phone-number/" << endl << endl;
    // cout << "solution: https://hackmd.io/@PeterLei/leetcode374?utm_source=preview-mode&utm_medium=rec/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: digits = \"23\"\n");
    printf("expected result: output = [\"ad\",\"ae\",\"af\",\"bd\",\"be\",\"bf\",\"cd\",\"ce\",\"cf\"]\n");
    {
        string digits = "23";
        
        Solution solution;
        auto result = solution.letterCombinations(digits);
        printf("result size:%d\n", result.size());
        for (size_t i = 0; i < result.size(); i++)
        {
            printf("result[%d]:%s\n", i, result[i].c_str());
        }
        
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
