#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'waiter' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY number
 *  2. INTEGER q
 */

/*#define MAX_SIZE 1000005
 
void SieveOfEratosthenes(vector<int>& primes){
    bool IsPrime[MAX_SIZE];
    memset(IsPrime, true, sizeof(IsPrime));
 
    for (int p = 2; p * p < MAX_SIZE; p++) {
        if (IsPrime[p] == true) {
            for (int i = p * p; i < MAX_SIZE; i += p)
                IsPrime[i] = false;
        }
    }
 
    for (int p = 2; p < MAX_SIZE; p++){
        if (IsPrime[p]){
            primes.push_back(p);
        }
    }
}

vector<int> waiter(vector<int> number, int q) {
    vector<int> answers;
    vector<int> primes;
    vector<int> B;
    int idx = 0;
    reverse(number.begin(), number.end());

    SieveOfEratosthenes(primes);
    
    while (q>0){
        int prime = primes.at(idx);
        
        for (int i = 0; i < number.size(); i++){
            cout<<"Num: "<<number.at(i)<<endl;
        }
        
        for (int i = 0; i < number.size(); i++){
            if (number.at(i) % prime == 0){
                B.push_back(number.at(i));
                number.erase(number.begin()+i);
                i--;
            }
        }
        
        cout<<endl;
        
        for (int i = B.size()-1; i>=0; i--){
            cout<<"B: "<<B.at(i)<<endl;
        }
        
        for (int i = B.size()-1; i>=0; i--){
            answers.push_back(B.at(i));
        }
        
        B.clear();
        idx++;
        q--;
    }
    
    for (int i = number.size()-1; i>=0; i--){
        answers.push_back(number.at(i));
    }
    
    return answers;
}*/

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

vector<int> generatePrimes(int n) {
    vector<int> primes;
    int num = 2, count = 0;
    
    while (count < n) {
        if (isPrime(num)) {
            primes.push_back(num);
            count++;
        }
        num++;
    }
    return primes;
}

vector<int> waiter(vector<int>& number, int q) {
    vector<int> answers;
    vector<int> stack = number;

    auto primes = generatePrimes(q);

    for (int prime : primes) {
        vector<int> a, b;
        
        while (!stack.empty()) {
            int num = stack.back();
            stack.pop_back();
            
            if (num % prime == 0) {
                b.push_back(num);
            } 
            else {
                a.push_back(num);
            }
        }
        
        while (!b.empty()) {
            answers.push_back(b.back());
            b.pop_back();
        }
        stack = a;
    }

    while (!stack.empty()) {
        answers.push_back(stack.back());
        stack.pop_back();
    }

    return answers;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    string number_temp_temp;
    getline(cin, number_temp_temp);

    vector<string> number_temp = split(rtrim(number_temp_temp));

    vector<int> number(n);

    for (int i = 0; i < n; i++) {
        int number_item = stoi(number_temp[i]);

        number[i] = number_item;
    }

    vector<int> result = waiter(number, q);

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
