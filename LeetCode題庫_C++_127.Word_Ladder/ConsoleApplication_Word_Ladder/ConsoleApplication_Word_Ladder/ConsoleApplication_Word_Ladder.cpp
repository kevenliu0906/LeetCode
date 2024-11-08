// ConsoleApplication_Word_Ladder.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
private:

    // use pointer to save time
    bool check_change_onebit(string *str1, string *str2){

        int checkIdx = 0;
        int change_bit_count = 0;
        
        while (checkIdx < str1->size() && checkIdx < str2->size())
        {
            if (str1->at(checkIdx) != str2->at(checkIdx))
                change_bit_count++;

            if (change_bit_count > 1)
                return false;
            
            checkIdx++;
        }
        
        return true;
    }

    // use pointer to save time
    int min_move_step_BFS(string* s_str, string* e_str, vector<string*> wordList){

        unordered_set<string*> word_check_done_set;  // use pointer to save time
        
        queue<string*> tmp_word_que;  // use pointer to save time
        queue<string*> cur_word_que;  // use pointer to save time
        int min_move_count = 0;

        tmp_word_que.push(s_str);
        word_check_done_set.insert(s_str);
        
        while (tmp_word_que.size())
        {
            cur_word_que.swap(tmp_word_que);
            while (cur_word_que.size())
            {
                std::string* cur_word = cur_word_que.front();
                
                // printf("Loop:%d, cur_word:%s\n", min_move_count, cur_word.c_str());
                // printf("cur_word:%s, e_str:%s\n", cur_word->c_str(), e_str->c_str());
                // compare HERE!!!
                if(strcmp(cur_word->c_str(), e_str->c_str()) == 0)
                {
                    // BIOGO~~ found it!!!!!
                    min_move_count++;
                    return min_move_count;
                }
                
                for (size_t i = 0; i < wordList.size(); i++)                                
                {
                    if (word_check_done_set.count(wordList[i]) == 0)
                    {
                        // printf("----- cur_word:%s << compare with >> wordbase:%s -----\n", cur_word.c_str(), wordList[i]->c_str());
                        if (check_change_onebit(cur_word, wordList[i]))
                        {
                            // only 'one-bit' change between cur_word & wordbase
                            // printf("cur_word:%s, push wordbase:%s into tmp_word_que\n", cur_word->c_str(), wordList[i]->c_str());
                            tmp_word_que.push(wordList[i]);
                            word_check_done_set.insert(wordList[i]);
                        }
                    }
                }

                cur_word_que.pop();
            }

            if (tmp_word_que.size()){
                min_move_count++;
            }
        }
        
        return 0;   // after BFS, no cur_word is the same as e_str, so return 0
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // solution 1 (using BFS to solve)
        {
            auto res = 0;
            vector<string*> word_ptr_List;
            for (size_t i = 0; i < wordList.size(); i++)
                word_ptr_List.push_back(&wordList[i]);
            
            res = min_move_step_BFS(&beginWord, &endWord, word_ptr_List);
            return res;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Word Ladder, Algorithm(Breadth-First Search)!\n";
    cout << "https://leetcode.com/problems/word-ladder/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: beginWord = \"hit\", endWord = \"cog\", wordList = [\"hot\",\"dot\",\"dog\",\"lot\",\"log\",\"cog\"]\n");
    printf("output: 5\n");
    printf("Explanation: One shortest transformation sequence is \"hit\" -> \"hot\" -> \"dot\" -> \"dog\" -> \"cog\", which is 5 words long.\n");
    {
        string beginWord = "hit";
        string endWord = "cog";
        vector<string> wordList{"hot","dot","dog","lot","log","cog"};
        Solution solution;
        
        auto res = solution.ladderLength(beginWord, endWord, wordList);
        printf("res is %d\n", res);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: beginWord = \"hit\", endWord = \"cog\", wordList = [\"hot\",\"dot\",\"dog\",\"lot\",\"log\"]\n");
    printf("output: 0\n");
    printf("Explanation: The endWord \"cog\" is not in wordList, therefore there is no valid transformation sequence.\n");
    {
        string beginWord = "hit";
        string endWord = "cog";
        vector<string> wordList{"hot","dot","dog","lot","log"};
        Solution solution;
        
        auto res = solution.ladderLength(beginWord, endWord, wordList);
        printf("res is %d\n", res);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: beginWord = \"hot\", endWord = \"dog\", wordList = [\"hot\",\"dog\"]\n");
    printf("output: 0\n");
    {
        string beginWord = "hot";
        string endWord = "dog";
        vector<string> wordList{"hot","dog"};
        Solution solution;
        
        auto res = solution.ladderLength(beginWord, endWord, wordList);
        printf("res is %d\n", res);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: beginWord = \"hit\", endWord = \"cog\", wordList = [\"hot\",\"dot\",\"tog\",\"cog\"]\n");
    printf("output: 0\n");
    {
        string beginWord = "hit";
        string endWord = "cog";
        vector<string> wordList{"hot","dot","tog","cog"};
        Solution solution;
        
        auto res = solution.ladderLength(beginWord, endWord, wordList);
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
