#include<bits/stdc++.h>
using namespace std;

string single_word(std::vector<string> v)
{
    size_t size = accumulate(v.begin(), v.end(), 0, [](size_t cur, const string &s) { return max(cur, s.size()); });
    string result(size, '\0');

    for (const string &s : v)
    {
        for (int i = 0; i < s.size(); ++i)
        {
            result[i] ^= s[i];
        }
    }

    return result.c_str();
}

int main()
{
    string s;

    vector<string> words;
    while (cin)
    {
        getline(cin,s);
        words.push_back(s);
    }

    cout << single_word(words) << endl;

    return 0;
}
