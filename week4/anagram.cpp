int anagram(string s) {
    
    int len = s.size();
    if (len % 2 == 1) {
        return -1;
    }

    string str_a = s.substr(0, len/2);
    string str_b = s.substr(len/2);

    map <char, int> mapA;
    map <char, int> mapB;
    
    int min = 0;
        
    for (auto chr : str_a){
        mapA[chr]++;
    }
    for (auto chr : str_b){
        mapB[chr]++;
    }
    
    for (auto& enrty : mapA) {
        char chr = entry.first;
        int freq_a = entry.second;
        int freq_b = mapB[chr];
        min_changes += max(0, freq_a - freq_b);
    }

    if (s.size() % 2 == 1){
        return -1;
    }
    
    return min;
}
