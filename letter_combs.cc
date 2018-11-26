#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int res_len = digits.length();
        std::map<char, string> n2s = {
            {'1',""},
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
        std::vector<string> res;
        string avail_words;

        std::function<void(int i)> iterf = [&](int i){
            if (res_len > 0 && i == res_len) {
                res.push_back(avail_words);
                return;
            }
            std::string ss = n2s[digits[i]];
            for(char& a: ss) {
                avail_words.push_back(a);
                iterf(i+1);
                avail_words.pop_back();
            }
        };
        iterf(0);
        return res;
    }
};

int main() {
   std::string input("23");
   Solution s;
   auto o = s.letterCombinations(input);
   for(auto& s : o) {
      std::cout<<s<<",";
   }
   std::cout<<std::endl;
}
