#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        std::stack<int> s;
        int j = 0;
        for (int i = 0; i < pushed.size(); ++i) {
            int cur = pushed[i];
            if (cur == popped[j]) {
                j++;
                continue;
            }
            if (!s.empty()) {
                while(!s.empty() && s.top() == popped[j]) {
                    j++;
                    s.pop();
                }
            } 
            s.push(cur);
        }
        while (!s.empty() && s.top() == popped[j]) {
            s.pop();
            j++;
        }
        return j == popped.size();
    }
};

int main() {
    Solution s;
    vector<int> pushed {1,2,3,5,4};
    vector<int> popped {5,4,3,2,1};
    bool ret = s.validateStackSequences(pushed,popped);
    cout<<endl<<"pushed:";
    for(auto it : pushed) {
      cout<<it<<",";
    }
    cout<<endl<<"popped:";
    for(auto it : popped) {
      cout<<it<<",";
    }
    cout<<endl;
    cout<<"validate:" << ret<<endl;
}
