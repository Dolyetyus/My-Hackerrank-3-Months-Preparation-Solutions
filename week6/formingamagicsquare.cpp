#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'formingMagicSquare' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY s as parameter.
 */

int formingMagicSquare(vector<vector<int>> s) {
    int cost = 999999;
    vector<vector<int>> possible_solutions{
        {8,3,4,1,5,9,6,7,2},
        {4,3,8,9,5,1,2,7,6},
        {8,1,6,3,5,7,4,9,2},
        {6,1,8,7,5,3,2,9,4},
        {2,9,4,7,5,3,6,1,8},
        {4,9,2,3,5,7,8,1,6},
        {2,7,6,9,5,1,4,3,8},
        {6,7,2,1,5,9,8,3,4}
    };
    
    vector<int> onedim;
    
    for (int i = 0; i< s.size(); i++){
        for (int ii = 0; ii< s.size(); ii++){
            onedim.push_back(s.at(i).at(ii));
        }
    }
    
    for (int i = 0; i< possible_solutions.size(); i++){
        int temp = 0;
        for (int ii = 0; ii< onedim.size(); ii++){
            int orig = possible_solutions.at(i).at(ii);
            int comp = onedim.at(ii);
            if (orig != comp){
                temp += abs(comp - orig);
            }
        }
        
        if (temp<cost){
            cost = temp;
        }
    }
    
    return cost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);

    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        string s_row_temp_temp;
        getline(cin, s_row_temp_temp);

        vector<string> s_row_temp = split(rtrim(s_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int s_row_item = stoi(s_row_temp[j]);

            s[i][j] = s_row_item;
        }
    }

    int result = formingMagicSquare(s);

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
