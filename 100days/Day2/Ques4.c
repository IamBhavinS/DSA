int maxProfit(int* prices, int pricesSize) {
 if (pricesSize == 0) return 0;

 int min_p = prices[0];
 int max_p = 0;

 for (int i = 1; i < pricesSize; i++) {
    if (prices[i] < min_p) {
        min_p = prices[i];
    } else {
        int cur_p = prices[i] - min_p;
        if (cur_p > max_p) {
            max_p = cur_p;
        }
    }
 }   
 return max_p;
}