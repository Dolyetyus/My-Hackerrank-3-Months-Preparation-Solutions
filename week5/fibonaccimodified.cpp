#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
/*
Expected Output:
84266613096281243382112
Debug output:
290287121823
(Overflow)
0
*/

int fibonacciModified(int t1, int t2, int n) {
    unsigned long long int sum = 0;
    unsigned long long int a = t1;
    unsigned long long int b = t2;
    
    while (n > 2){
        sum = 0;
        sum = a + pow(b,2);
        cout<<sum<<endl;
        a = b;
        b = sum;
        n--;
    }
    
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int t1 = stoi(first_multiple_input[0]);

    int t2 = stoi(first_multiple_input[1]);

    int n = stoi(first_multiple_input[2]);

    int result = fibonacciModified(t1, t2, n);

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
