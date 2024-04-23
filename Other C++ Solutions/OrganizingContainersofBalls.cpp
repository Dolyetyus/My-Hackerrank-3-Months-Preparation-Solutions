string organizingContainers(vector<vector<int>> container) {
    int n = container.size();
    
    vector<long long> boxTotals(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            boxTotals[i] += container[i][j];
        }
    }
    
    vector<long long> ballTotals(n, 0);
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            ballTotals[j] += container[i][j];
        }
    }

    sort(boxTotals.begin(), boxTotals.end());
    sort(ballTotals.begin(), ballTotals.end());


    if (boxTotals == ballTotals) return "Possible"; 
    else return "Impossible";
}
