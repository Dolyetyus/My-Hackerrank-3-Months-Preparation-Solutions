#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*The function underneath is the naive solution but
its time complexity makes it stuck at 85%, 
so it does not pass all tests

string gamingArray(vector<int> arr) {
    vector<string> wins{"BOB", "ANDY"};
    bool idx = 1;
    unsigned int max;
    
    while (!arr.empty()) {
        max = max_element(arr.begin(), arr.end()) - arr.begin();
        arr.erase(arr.begin() + max, arr.end());
        idx = !idx;
    }

    return wins.at(idx);
}*/

string gamingArray(vector<int> arr) {
    int max_val = -2000000000;
    int max = 0;

    for (int num : arr) {
        if (num > max_val) {
            max_val = num;
            max++;
        }
    }

    if (max % 2 == 0) {
        return "ANDY";
    }

    return "BOB";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_temp;
    getline(cin, g_temp);

    int g = stoi(ltrim(rtrim(g_temp)));

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string arr_count_temp;
        getline(cin, arr_count_temp);

        int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(arr_count);

        for (int i = 0; i < arr_count; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        string result = gamingArray(arr);

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
