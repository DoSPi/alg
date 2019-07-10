#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> prefix(const string &s)
{
    vector<int> ans(s.size());
    ans[0] = 0;
    int k = 0;
    for (int i = 1; i < s.size(); i++){
        while (1){
            if (s[i] == s[k]){
                k++;
                break;
            } else {
                if (k == 0){
                    break;
                }
                k = ans[k- 1];
            }
        }
        ans[i] = k;
    }
    return ans;
}
bool kmp(const string &input, const string &sample)
{
    string s = sample + "#" +input;
        vector<int> x = prefix(s);
    for (auto i : x){
        if (i){
            return true;
        }
    }
    return false;
}
int main()
{
    cout << kmp("822abcdij228dsadad22", "228") << endl;
    cout << kmp("822abcdij228dsadad22","1337") << endl;
    return 0;
}
