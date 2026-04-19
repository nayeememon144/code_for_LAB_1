#include<bits/stdc++.h>
using namespace std;
double fractionalknapsack(int W,int wt[],int val[],int n){
    double ratio[100];
    for(int i = 0; i < n; i++){
        ratio[i] = (double)val[i] / wt[i];
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(ratio[i] < ratio[j]){
                double tempR = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = tempR;

                double tempV = val[i];
                val[i] = val[j];
                val[j] = tempV;

                double tempW = wt[i];
                wt[i] = wt[j];
                wt[j] = tempW;
            }
        }
    }

    double totalvalue = 0.0;
    int remaining = W;
    for(int i = 0; i < n; i++){
        if(wt[i] <= remaining){
            remaining = remaining - wt[i];
            totalvalue = totalvalue + val[i];
        }
        else{
            totalvalue = totalvalue + val[i] * ((double)remaining / wt[i]);
            break;
        }
    }
    return totalvalue;
}
int main(){
    int n,W;
    cout << "Enter the number of items : ";
    cin >> n;
    int val[n];
    int wt[n];
    cout << "Please enter the values of the items : \n";
    for(int i = 0; i < n; i++){
        cin >> val[i];
    }
    cout << "Please enter the weight of the items : \n";
    for(int i = 0; i < n; i++){
        cin >> wt[i];
    }
    cout << "Enter the capacity of the knapsack : ";
    cin >> W;
    double res = fractionalknapsack(W,wt,val,n);
    cout << "The maximum values through fractional knapsack is : " << res << endl;
    return 0;
}
