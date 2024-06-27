// ConsoleApplication_GroupAnagrams.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs){
        
        vector<vector<string>> result;
        result.clear();

        // solution 1(keven) 
        {
            
            multimap<vector<int>, string> char_count_str;  // key: 26-char-count array, value: string_content

            // STEP1:
            for (size_t i = 0; i < strs.size(); i++)
            {
                // --> step1-1, announce 26-char-count array to store the count of char within str
                vector<int> single_element_char_count(26, 0);

                // --> step1-2, calc each char count for single str
                auto each_str = strs[i];
                for (size_t j = 0; j < each_str.size(); j++)
                {
                    single_element_char_count[ each_str[j] - 'a' ]++;
                }

                // --> step1-3, assign corresponding "26-char-count array" and "string_content" into map
                char_count_str.insert(pair<vector<int>, string>(single_element_char_count, each_str));
            }

            // {
            //     // Debug total_element_char_count
            //     printf("*********************  DEBUG MESSAGE  ***************************\n");
            //     printf("size char_count_str:%d\n", char_count_str.size());
            //     for (auto each_char_count_str : char_count_str)
            //     {
            //         // key:
            //         printf("\tkey size:%d\n", each_char_count_str.first.size());
            //         string key;
            //         for (size_t i = 0; i < each_char_count_str.first.size(); i++)
            //         {
            //             auto each_bit_num = each_char_count_str.first.at(i);
            //             char num[100];
            //             _itoa_s(each_bit_num, num, 10);
            //             key.append(num);
            //         }
            //         printf("\tkey:%s; ", key.c_str());
            //         // value:
            //         printf("value:%s\n", each_char_count_str.second.c_str());
            //     }
            //     printf("*****************************************************************\n");
            // }

            // STEP2:
            while(char_count_str.size()>0){

                // --> step2-1, find the match string in groups
                vector<string> total_match_str;
                int match_str_count = 0;
                auto record_each_char_count = char_count_str.begin()->first;
                for (auto each_char_count_str : char_count_str)
                {
                    string single_match_str;
                    auto current_char_count = each_char_count_str.first;
                    if(record_each_char_count == current_char_count){
                        single_match_str = each_char_count_str.second;
                        total_match_str.push_back(single_match_str);
                        match_str_count++;
                    }else{
                        break;
                    }
                }
                // for (size_t i = 0; i < total_match_str.size(); i++)
                // {
                //     printf("total_match_str[%d]=%s\n", i, total_match_str[i].c_str());
                // }

                // {
                //     // Debug total_element_char_count
                //     printf("*********************  DEBUG MESSAGE  ***************************\n");
                //     printf("size char_count_str:%d\n", char_count_str.size());
                //     for (auto each_char_count_str : char_count_str)
                //     {
                //         // key:
                //         printf("\tkey size:%d\n", each_char_count_str.first.size());
                //         string key;
                //         for (size_t i = 0; i < each_char_count_str.first.size(); i++)
                //         {
                //             auto each_bit_num = each_char_count_str.first.at(i);
                //             char num[100];
                //             _itoa_s(each_bit_num, num, 10);
                //             key.append(num);
                //         }
                //         printf("\tkey:%s; ", key.c_str());
                //         // value:
                //         printf("value:%s\n", each_char_count_str.second.c_str());
                //     }
                //     printf("*****************************************************************\n");
                // }

                // --> step2-2, erase the match string to reduce searching time
                for (size_t i = 0; i < match_str_count; i++)
                {
                    // erase the beginning element in each iteration
                    char_count_str.erase(char_count_str.begin());
                }
                
                // {
                //     // Debug total_element_char_count
                //     printf("*********************  DEBUG MESSAGE  ***************************\n");
                //     printf("size char_count_str:%d\n", char_count_str.size());
                //     for (auto each_char_count_str : char_count_str)
                //     {
                //         // key:
                //         printf("\tkey size:%d\n", each_char_count_str.first.size());
                //         string key;
                //         for (size_t i = 0; i < each_char_count_str.first.size(); i++)
                //         {
                //             auto each_bit_num = each_char_count_str.first.at(i);
                //             char num[100];
                //             _itoa_s(each_bit_num, num, 10);
                //             key.append(num);
                //         }
                //         printf("\tkey:%s; ", key.c_str());
                //         // value:
                //         printf("value:%s\n", each_char_count_str.second.c_str());
                //     }
                //     printf("*****************************************************************\n");
                // }
                
                result.push_back(total_match_str);
            }
        }

        return result;
    }
};

int main()
{
    std::cout << "Hello LeetCode - Group Anagrams, DataStructure (Array, HASH TABLE, String)!\n";

    printf("LeetCode - 49. Group Anagrams\n");
    cout << "https://leetcode.com/problems/group-anagrams/" << endl << endl;
    // cout << "solution: https://medium.com/@zero.ling/c-sort-a-map-by-value-601a60ec0e01" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: nums = [\"eat\", \"tea\", \"tan\", \"ate\", \"nat\", \"bat\"] \n");
    printf("expected result: [ [\"bat\"], [\"nat\", \"tan\"], [\"ate\", \"eat\", \"tea\"] ]\n");
    {
        vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

        Solution Solution_cs;
        auto Result = Solution_cs.groupAnagrams(strs);
        printf("Result value size is %d, true=%d, false=%d\n", Result.size(), true, false);
        for (size_t i = 0; i < Result.size(); i++)
        {
            printf("size of Result[%d]=%d\n", i, Result[i].size());
            for (size_t j = 0; j < Result[i].size(); j++)
            {
                printf("Result[%d][%d] = %s\n", i, j, Result[i][j].c_str());
            }
            
        }
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: nums = [\"\"] \n");
    printf("expected result: [ [\"\"] ]\n");
    {
        vector<string> strs = {""};

        Solution Solution_cs;
        auto Result = Solution_cs.groupAnagrams(strs);
        printf("Result value size is %d, true=%d, false=%d\n", Result.size(), true, false);
        for (size_t i = 0; i < Result.size(); i++)
        {
            printf("size of Result[%d]=%d\n", i, Result[i].size());
            for (size_t j = 0; j < Result[i].size(); j++)
            {
                printf("Result[%d][%d] = %s\n", i, j, Result[i][j].c_str());
            }
            
        }
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: nums = [\"a\"] \n");
    printf("expected result: [ [\"a\"] ]\n");
    {
        vector<string> strs = {"a"};

        Solution Solution_cs;
        auto Result = Solution_cs.groupAnagrams(strs);
        printf("Result value size is %d, true=%d, false=%d\n", Result.size(), true, false);
        for (size_t i = 0; i < Result.size(); i++)
        {
            printf("size of Result[%d]=%d\n", i, Result[i].size());
            for (size_t j = 0; j < Result[i].size(); j++)
            {
                printf("Result[%d][%d] = %s\n", i, j, Result[i][j].c_str());
            }
            
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
