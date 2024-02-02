#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
This question is horrible, in both explanation and test cases. 
I can't understand the second example with "aab aac aacghgh aabghgh"

Why it should print aacghgh? aab is encountered first and we check 
if any of the other strings have it as prefix, and aabghgh have it already.

For me, there is no clear explanation or the correct explanation of the problem.

My solution:

void noPrefix(vector<string> words) {
    bool isgood = true;
    string print;
    
    for (int i = 0; i<words.size(); i++){
        string check = words.at(i);
        int n = check.length();
        
        for (int ii = i+1; ii<words.size(); ii++){
            string current = words.at(ii).substr(0, n);
            
            if (check==current||words.at(ii).find(check)==0) {
                isgood = false;
                print = words.at(ii);
                break;
            }
        }
        
        if (!isgood) {
            break;
        }
    }
    
    if (isgood) {cout<<"GOOD SET"<<endl;}
    else {cout<<"BAD SET"<<endl<<print<<endl;}
}*/

/*
Quoting from the user dqlynch: "Honestly horribly composed question. 
The actual problem "determine whether any of the strings are prefixes of another", 
or even "find all prefixes and all words they are a prefix of" is trivially easy. 
You can just lexicographically sort and compare each word with its next neighbors. 
However, the expected output is extremely vague: "Here 'abcd' is a prefix of 'abcde' 
and 'bcd' is a prefix of 'bcde'. Since 'abcde' is tested first, print 'abcde'."

Looking at the test cases, this isn't consistent with either the first prefix that matches any word, 
the first word that has a matching prefix, or the first prefix OR word. 
It must only be consistent with an inefficient implementation. 
EDIT: figured it out, and no it doesn't make a lot of sense. 
It's the first MATCH for EITHER the first prefix or encapsulating word. 
Horrible. Hackerrank should delete this question or clean up/disambiguate the output requirements.
Reverse engineering the answer key should not be part of a question. 
Here's an answer so you can just skip this crap: "
*/
bool is_prefix(string prefix, string word) {
     return prefix == word.substr(0, prefix.size());
 }

void noPrefix(vector<string> words) {
    vector<pair<size_t, string>> sorted;
    for (size_t i = 0; i < words.size(); ++i) {
        sorted.push_back(make_pair(i, words[i]));
    }
    
    sort(sorted.begin(), sorted.end(), 
        [](pair<int, string> lhs, pair<int, string> rhs) {
            return lhs.second < rhs.second;
        });
    
    size_t first_second = words.size();
    for (size_t i = 0; i < sorted.size() - 1; ++i) {
        string prefix = sorted[i].second;
        for (size_t j = 1; i+j < sorted.size(); ++j) {
            if (!is_prefix(prefix, sorted[i+j].second)) {
                break;
            }
            first_second = min(first_second, max(sorted[i].first, sorted[i+j].first));
        }
    }
    
    if (first_second == words.size()) {
        cout << "GOOD SET" << endl;
        return;
    }
    cout << "BAD SET\n";
    cout << words[first_second] << endl;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> words(n);

    for (int i = 0; i < n; i++) {
        string words_item;
        getline(cin, words_item);

        words[i] = words_item;
    }

    noPrefix(words);

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
