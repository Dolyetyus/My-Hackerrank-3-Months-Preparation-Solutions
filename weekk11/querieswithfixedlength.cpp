#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/* 
Apparently the most straightforward 
solution is too slow lmao

vector<int> solve(vector<int> arr, vector<int> queries) {
    vector<int> ret;
    
    for (int query: queries){
        vector<int> max;
        
        for (int i = 0; i<=arr.size()-query; i++){
            vector<int> window;
            
            for (int ii = i; ii<query+i; ii++){
                window.push_back(arr.at(ii));
            }
            
            int m = *max_element(window.begin(), window.end());
            max.push_back(m);
        }
        
        int min = *min_element(max.begin(), max.end());
        ret.push_back(min);
    }

    return ret;
}*/

vector<int> solve(vector<int> arr, vector<int> queries) {
    vector<int> ret;

    for (int query: queries) {
        int max = *max_element(arr.begin(), arr.begin()+query);
        int min = max;

        for (int i = 1; i <= arr.size() - query; ++i) {
            if (arr[i + query - 1] > max) {
                max = arr[i + query - 1];
            } 
            else if (arr[i - 1] == max) {
                max = *max_element(arr.begin() + i, arr.begin() + i + query);
            }

            if (max < min) {
                min = max;
            }
        }

        ret.push_back(min);
    }

    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> queries(q);

    for (int i = 0; i < q; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<int> result = solve(arr, queries);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
