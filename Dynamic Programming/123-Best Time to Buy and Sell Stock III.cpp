int maxProfit1(vector<int>& prices) {
    if(prices.empty())
        return 0;
    vector<int> cost(prices.size()-1, 0);
    for(int i=1; i<prices.size(); i++){
        cost[i-1] = prices[i] - prices[i-1];
    }
    vector<int> dp_left(prices.size(), 0);
    vector<int> dp_right(prices.size(), 0);
    for(int i=1; i<=cost.size(); i++){
        dp_left[i] = dp_left[i-1]>0 ? dp_left[i-1]+cost[i-1] : cost[i-1];
    }
    for(int i=cost.size(); i>0; i--){
        dp_right[i] = dp_right[i-1]>0 ? dp_right[i-1]+cost[i-1] : cost[i-1];
    }
    int left(INT_MIN), right(INT_MIN);
    while(left<=right){

    }
    for(int i=0; i<prices.size(); i++){
        //if(res<)
    }
    return 0;
}
int maxProfit(vector<int>& prices) {
    int sum = 0;
    int len = prices.size();
    if(len == 0) return 0; //空会触发 runtime error []
    vector<int> f(len,0);
    int i,low = prices[0],max_p = prices[len-1];
    for(i = 1;i < len; i++){
         if(prices[i] > prices[i-1]){ // increase
            f[i] = max(f[i-1],prices[i] - low);
          }else f[i] = f[i-1];
        if(prices[i] < low) low = prices[i];
     }
    for( i = len-1 ; i >0 ;i--){//buy in ith day and sell in max_p
         max_p = max(max_p,prices[i]);
         if((max_p - prices[i]) > 0){
            sum = max(sum, max_p - prices[i] + f[i-1]);
        }
    }
    if((max_p - prices[i]) > 0){
        sum = max(sum, max_p - prices[i]);
      }
    return sum;
}
