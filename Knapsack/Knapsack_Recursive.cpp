#include<bits/stdc++.h>
using namespace std;
int knapsackrecurssive(vector<vector<int> >dp, vector<int> profit , vector<int> weight , int capacity, int current);
int knapsack (vector<int> &profit , vector<int> &weight , int capacity){
    vector<vector<int> >dp(profit.size(), vector<int>(capacity+1, -1));
    return knapsackrecurssive(dp,profit, weight, capacity, 0);
}
int knapsackrecurssive(vector<vector<int> > dp, vector<int> profit , vector<int> weight , int capacity, int current){
    if(capacity<=0 || current>=profit.size()){
        return 0;
    }
    if(dp[current][capacity]!=-1){
        return dp[current][capacity];
    }
    int profit1 = 0;
    if(weight[current]<=capacity){
        profit1=profit[current]+knapsackrecurssive(dp,profit,weight,capacity-weight[current],current+1);
    }
    int profit2 = knapsackrecurssive(dp,profit,weight,capacity,current+1);
    dp[current][capacity]=max(profit1,profit2);
    return dp[current][capacity];
}
int main() {
//   Knapsack ks;
  vector<int> profits;
  profits.push_back(1);
  profits.push_back(6);
  profits.push_back(10);
  profits.push_back(16);
  vector<int> weights;
  weights.push_back(1);
  weights.push_back(2);
  weights.push_back(3);
  weights.push_back(5);
  int maxProfit = knapsack(profits, weights, 7);
  cout << "Total knapsack profit ---> " << maxProfit << endl;
  maxProfit = knapsack(profits, weights, 6);
  cout << "Total knapsack profit ---> " << maxProfit << endl;
  return 0;
}
