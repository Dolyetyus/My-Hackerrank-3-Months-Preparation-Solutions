#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

//There is no way that this problem is "easy"

void separateNumbers(string s) {
    for (int i = 1; i <= s.size() / 2; ++i) {
        long first_num = stol(s.substr(0, i));
        long current_num = first_num;
        string current_str = to_string(first_num);

        while (current_str.size() < s.size()) {
            ++current_num;
            current_str += to_string(current_num);
        }

        if (current_str == s) {
            cout << "YES " << first_num << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
