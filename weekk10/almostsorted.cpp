#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'almostSorted' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void almostSorted(vector<int> arr) {
    if (is_sorted(arr.begin(), arr.end())){
        cout<<"yes"<<endl;
        return;
    }
    
    int i = 0;
    int ii = arr.size() - 1;

    while (i < arr.size() - 1 && arr.at(i) < arr.at(i+1)) {
        i++;
    }

    while (ii > 0 && arr.at(ii) > arr.at(ii-1)) {
        ii--;
    }

    swap(arr.at(i), arr.at(ii));

    if (is_sorted(arr.begin(), arr.end())) {
        cout << "yes"<<endl<<"swap "<< i + 1 <<" "<< ii + 1 <<endl;
        return;
    }
    
    swap(arr.at(i), arr.at(ii));

    reverse(arr.begin() + i, arr.begin() + ii + 1);

    if (is_sorted(arr.begin(), arr.end())) {
        cout << "yes"<<endl<<"reverse "<<i + 1<<" "<<ii + 1<<endl;
        return;
    }

    cout <<"no"<< endl;
    
}

int main()
{
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

    almostSorted(arr);

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
