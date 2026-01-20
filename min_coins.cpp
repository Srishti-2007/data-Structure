#include<iostream>
#include<vector>
using namespace std;
int main(){
    int coins[]={2000,500,100,50,20,10,5,2,1};
    int count_notes=0, i=0;
    vector<int>ans;
    int N=143;
    while(N){
        count_notes=N/coins[i];
        while(count_notes--){
            ans.push_back(coins[i]);
         }
         N=N%coins[i];
         i++;
    }
    // return ans     {if i create a finction in like online coding platform}
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}