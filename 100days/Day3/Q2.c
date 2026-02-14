int missingNum(int arr[], int n) {
    int final_n = n + 1;
    long long total = (long long)final_n * (final_n + 1) / 2;
    long long sum = 0;
    
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    
    return (int)(total - sum);
}
