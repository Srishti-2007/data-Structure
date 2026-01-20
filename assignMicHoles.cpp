#include<iostream>
#include<algorithm>
using namespace std;
 int assignMicHoles(int m[] , int h[], int n){
    sort(m,m+n);
    sort(h,h+n);
    return abs(m[0]-h[n-1]);
 }
int main(){
    int m[]={4,-4,2};
    int h[]={4,0,5};
    int n=3;
    cout<<assignMicHoles(m,h,n);
}