#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'bigSorting' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY unsorted as parameter.
 */

bool sortlength(const string& a, const string& b){
    if (a.size() == b.size()) {
        return a < b;
    }
    return a.size() < b.size();
}

vector<string> bigSorting(vector<string> unsorted) {
    vector<string> sorted(unsorted.size());
    
    sort(unsorted.begin(), unsorted.end(), sortlength);
    
    for (unsigned int i = 0; i<unsorted.size()-1; i++){
        if(unsorted.at(i).size()==unsorted.at(i+1).size() && unsorted.at(i)>unsorted.at(i+1)){
            swap(unsorted.at(i), unsorted.at(i+1));
        }
    }
    
    return unsorted;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> unsorted(n);

    for (int i = 0; i < n; i++) {
        string unsorted_item;
        getline(cin, unsorted_item);

        unsorted[i] = unsorted_item;
    }

    vector<string> result = bigSorting(unsorted);

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
