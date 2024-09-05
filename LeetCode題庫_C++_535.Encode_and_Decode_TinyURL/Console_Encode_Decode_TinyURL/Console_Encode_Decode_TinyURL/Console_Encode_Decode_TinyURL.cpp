// Console_Encode_Decode_TinyURL.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// solution 1 (keven, best, using HASH TABLE, Hash Function to solve)
class Solution {
public:

    unordered_map<string, string> url_encode_map;   // key: normal-url, value: tiny-url
    unordered_map<string, string> url_decode_map;   // key: tiny-url, value: normal-url
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        
        string enc_res;

        // STEP1: check in url_encode_map
        auto encode_iter = url_encode_map.find(longUrl);
        if (encode_iter == url_encode_map.end()){
            auto hash_fn = url_encode_map.hash_function();
            auto encode_val = hash_fn(longUrl);
            auto encode_str = std::to_string(encode_val);
            url_encode_map.insert(pair<string, string>(longUrl, encode_str));
            enc_res = encode_str;
        }else{
            enc_res = encode_iter->second;
        }

        // STEP2: update the url_decode_map
        url_decode_map.insert(pair<string, string>(enc_res, longUrl));

        return enc_res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {

        string dec_res;
        auto decode_iter = url_decode_map.find(shortUrl);

        if (decode_iter == url_decode_map.end()){
            printf("decode is ERR, NOT found value, key:%s\n", shortUrl.c_str());
            return dec_res;
        }
        dec_res = decode_iter->second;

        return dec_res;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main()
{
    std::cout << "Hello LeetCode - Encode and Decode TinyURL, DataStructure(HASH TABLE, Hash Function)!\n";
    cout << "https://leetcode.com/problems/encode-and-decode-tinyurl/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input:  url = \"https://leetcode.com/problems/design-tinyurl\" \n");
    printf("expected result: output = \"https://leetcode.com/problems/design-tinyurl\" \n");
    {
        string url = "https://leetcode.com/problems/design-tinyurl";
        
        Solution solution;

        auto en_res = solution.encode(url);
        printf("origin url:%s, en_res:%s\n", url.c_str(), en_res.c_str());

        auto dec_res = solution.decode(/*solution.encode(url)*/en_res);
        printf("url:%s, dec_res is %s\n", url.c_str(), dec_res.c_str());
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
