#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int swap(const unordered_map<int, int>& dictArr, const vector<int>& sortArr, bool rev = false) {
    unordered_map<int, int> swaps;
    int n = sortArr.size();

    for (int i = 0; i < n; i++) {
        int index = rev ? n - 1 - i : i;
        int a = sortArr[index];
        int b = dictArr.at(a);

        while (true) {
            try {
                b = swaps.at(b);
            } 
            catch (const out_of_range&) {
                break;
            }
        }

        if (b != index) {
            swaps[index] = b;
        }
    }

    return swaps.size();
}

int lilysHomework(vector<int> arr) {
    vector<int> sortArr = arr;
    sort(sortArr.begin(), sortArr.end());

    unordered_map<int, int> dictArr;
    for (int i = 0; i < arr.size(); i++) {
        dictArr[arr[i]] = i;
    }

    int swapsOriginal = swap(dictArr, sortArr);
    reverse(sortArr.begin(), sortArr.end());
    int swapsReversed = swap(dictArr, sortArr, true);

    return min(swapsOriginal, swapsReversed);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

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
