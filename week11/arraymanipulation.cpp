#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


/*O(n*m) time complexity, fails some tests due to timeout:

long arrayManipulation(int n, vector<vector<int>> queries) {
    long ret = 0;
    vector<long> results(n);
    
    for (long i = 0; i<queries.size(); i++){
        long first = queries.at(i).at(0)-1;
        long second = queries.at(i).at(1)-1;
        long increment = queries.at(i).at(2);
        
        for (long idx = first; idx<=second; idx++){
            results.at(idx) += increment;
            if (results.at(idx) > ret){
                ret = results.at(idx);
            }
        }
    }
    
    return ret;
}*/

long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> results(n);
    long max = 0;
    long temp = 0;

    for (const auto &query : queries) {
        long first = query.at(0)-1;
        long second = query.at(1);
        long increment = query.at(2);

        results.at(first) += increment;
        if (second < n) {
            results.at(second) -= increment;
        }
    }

    for (int i = 0; i < n; i++) {
        temp += results.at(i);
        max = std::max<long>(max, temp);
    }

    return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> queries(m);

    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    long result = arrayManipulation(n, queries);

    fout << result << "\n";

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
