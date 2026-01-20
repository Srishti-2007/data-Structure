#include<iostream>
#include<algorithm>
using namespace std;
 int candystore(int candy_rates[], int size, int k){
    sort(candy_rates,candy_rates+size);
    int i=0,j=size-1;
    int sum_store=0;
    while(i<=j){
        sum_store=sum_store+candy_rates[i];
        i++;
        j--;
    }
    return sum_store;
}
int main() {
    int candy_rates[]={3,2,1,4};
    int size=4;
    int k=2;
   cout<<candystore(candy_rates,size,k);
}