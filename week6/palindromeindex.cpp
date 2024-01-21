#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'palindromeIndex' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
 
int palindromeIndex(string s) {
    int ret = -1;
    bool is_palin = false;
    
    cout<<s<<endl;
    
    while (s.size()>1){
        if (s.size() % 2 == 1){
            s.erase(s.begin() + (s.size()/2));
        }
        cout<<s<<endl;
        
        string first = s.substr(0, s.size()/2);
        string second = s.substr(s.size()/2, s.size()-1);
        reverse(second.begin(), second.end());
        
        if (first==second){
            break;
        }
        
        cout<<"F:"<<first<<endl<<"S:"<<second<<endl;
        
        for (int i = 0; i<first.size(); i++){
            if (first[i] != second[i]){
                s.erase(i);
                ret = i;
                cout<<"removal happened"<<endl;
                return i;
            }
        }
    }
    
    return ret;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

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
