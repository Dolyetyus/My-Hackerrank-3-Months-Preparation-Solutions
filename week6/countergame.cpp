#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/* This is the most straightforward solution I found but
the time complexity is too high so there is another
solution

string counterGame(long n) {
    vector<string> wins{"Richard", "Louise"};
    bool idx = 0;
    
    long numb = 2;
    
    while (numb < n){
        int temp = numb * 2;
        if (temp > n){
            break;
        }
        else { numb = temp; }
    }
    
    if (numb < n){
        n = n - numb;
        idx = !idx;
    }
    
    int position = 0;
    while (!(n & (1L << position))) {
        position++;
    }
    
    for (int i = position; i > 0; i--){
        idx = !idx;
    }

    return wins.at(idx);
}*/

string counterGame(long n) {
    vector<string> wins{"Richard", "Louise"};
    bool idx = 0;
    
    int count = 1;
    
    while (n > 1) {
        int log_res = log2(n - 1);
        n -= pow(2, log_res);
        count++;
    }
    
    if (count % 2 == 0) {
        idx = 1;
    }
    
    return wins.at(idx);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        long n = stol(ltrim(rtrim(n_temp)));

        string result = counterGame(n);

        fout << result << "\n";
    }

    fout.close();

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
