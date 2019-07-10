#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> prefix(const string &s)
{
    vector<int> ans(s.size());
    ans[0] = 0;
    int k = 0;
    for (size_t i = 1; i < s.size(); i++){
        while (1){
            if (s[i] == s[k]){
                k++;
                break;
            } else {
                if (k == 0){
                    break;
                }
                k = ans[k - 1];
            }
        }
        ans[i] = k;
    }
    return ans;
}
int main()
{
    string s = "abcdabckla";
    vector<int> x = prefix(s);
    for (auto i : x){
        cout << i << endl ;
    }
    return 0;
}
