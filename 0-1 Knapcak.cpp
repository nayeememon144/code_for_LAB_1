#include<bits/stdc++.h>
using namespace std;
int knapsack(int W,int wt[],int val[],int n){
    int dp[n + 1][W + 1];
    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= W; w++){
            if(i == 0 || w == 0){
                dp[i][w] = 0;
            }
            else if(wt[i - 1] <= w){
                int take = val[i - 1] + dp[i - 1][w - wt[i - 1]];
                int nottake = dp[i - 1][w];
                dp[i][w] = max(take,nottake);
            }
            else{
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}
int main(){
    int n,W;
    cout << "Please enter the number of the items : ";
    cin >> n;
    int val[n];
    int wt[n];
    cout << "Please enter the values of the items : \n";
    for(int i = 0; i < n; i++){
        cin >> val[i];
    }
    cout << "Please enter the weights of the items : \n";
    for(int i = 0; i < n; i++){
        cin >> wt[i];
    }
    cout << "Enter the capacity of the knapsack : ";
    cin >> W;
    int res = knapsack(W,wt,val,n);
    cout << "The maximum profit gain through knapsack is : ";
    cout << res << endl;
    return 0;
}
