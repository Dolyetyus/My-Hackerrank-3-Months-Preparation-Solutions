#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);




/* Too slow O(n^2)
int pairs(int k, vector<int> arr) {
    int ret = 0;
    sort(arr.begin(), arr.end(), greater<int>());
    
    for (int i = 0; i<arr.size(); i++){
        int comp = arr.at(i);
        for (int ii = arr.size()-1; ii>=i; ii--){
            if (comp - arr.at(ii) == k){
                ret++;
                break;
            }
        }
    }
    
    return ret;
}*/

/*O(n+logn) with binary search*/
int pairs(int k, vector<int> arr) {
    int ret = 0;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++) {
        int target = arr[i] + k;

        if (binary_search(arr.begin() + i + 1, arr.end(), target)) {
            ret++;
        }
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

    int k = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = pairs(k, arr);

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
