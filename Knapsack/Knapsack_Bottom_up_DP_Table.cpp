/** Given the weights and profits of ‘N’ items, we are asked to put these items in a knapsack which has a capacity ‘C’. 
	The goal is to get the maximum profit from the items in the knapsack. Each item can only be selected once,
	as we don’t have multiple quantities of any item.
	Let’s take the example of Merry, who wants to carry some fruits in the knapsack to get maximum profit. 
	Here are the weights and profits of the fruits:

	Items: { Apple, Orange, Banana, Melon }
	Weights: { 2, 3, 1, 4 }
	Profits: { 4, 5, 3, 7 }
	Knapsack capacity: 5
**/
#include<bits/stdc++.h>
using namespace std;


int knapsack (vector<int> &profit , vector<int> &weight , int capacity){
    //base case
    if(capacity<=0 || profit.size()==0 || profit.size()!=weight.size()){
        return 0;
    }
    int n=profit.size();
    vector<vector<int> >dp(n, vector<int>(capacity+1));
    //when capacity is zero
    for (int i=0; i<n; i++){
        dp[i][0]=0;
    }
    //if we have only one weight, we will take it if it is not more than the capacity.
    for(int c=0; c<=capacity; c++){
        if(weight[0]<=c){
            dp[0][c]= profit[0];
        }
    }
    // process all sub-arrays for all the capacities.
    for(int i=1; i<n; i++){
        for(int c=1; c<=capacity; c++){
            int profit1=0, profit2=0;
            if(weight[i]<=c){
                profit1=profit[i]+dp[i-1][c-weight[i]];
            }
            else{
                profit2=dp[i-1][c];
            }
            dp[i][c]=max(profit1,profit2);
        }
    }
//    printselectedweight(dp,profit,weight,capacity);
	int maxprofit = dp[weight.size()-1][capacity];
    cout << "Selected weights:";
    for(int i=weight.size()-1; i>0; i++){
        if(maxprofit!=dp[i-1][capacity]){
            cout<<weight[i]<<" ";
            capacity-=weight[i];
            maxprofit-=profit[i];
        }
    }
    if(maxprofit!=0){
        cout<<" "<<weight[0];
    }
    cout<<endl;

    return dp[n-1][capacity];
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
