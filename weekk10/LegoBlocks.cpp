#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


//I have no idea how to solve this
//This is someone else's solution

constexpr uint64_t MODULO = 1'000'000'007;
static_assert(numeric_limits<uint64_t>::max() / MODULO >= MODULO, "");

uint64_t modulopow(uint64_t x, uint64_t c) {
    x = x % MODULO;
    uint64_t out = 1;
    for (uint64_t i = 0; i < c; ++i) {
        out *= x;
        out %= MODULO;
    }
    return out;
}

uint64_t legoBlocks(int height, int width) {
    vector<uint64_t> row = { 1, 1, 2, 4 };
    for (int i = 4; i <= width; ++i) {
        uint64_t sum = row[i - 1]
                 + row[i - 2]
                 + row[i - 3]
                 + row[i - 4];
        row.push_back(sum % MODULO);
    }

    vector<uint64_t> total;
    for (int i = 0; i <= width; ++i) {
        total.push_back(modulopow(row[i], height));
    }

    vector<uint64_t> stable = {1};
    for (int i = 1; i <= width; ++i) {
        uint64_t unstable = 0;
        for (int j = 1; j < i; ++j) {
            unstable += (stable[j] * total[i - j]) % MODULO;
            unstable %= MODULO;
        }
        stable.push_back((total[i] - unstable + MODULO) % MODULO);
    }
    return stable[width];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int result = legoBlocks(n, m);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
