#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    // Creation
    unordered_map<string,int>m;

    //insertion
    pair<string,int> p=make_pair("fuggi",3);
    m.insert(p);

    pair<string,int>p2("ammna",7);
    m.insert(p2);

    m["Srishti"]=1;

    //access
    cout<<m.at("fuggi")<<endl;
    // cout<<m.at("Ammna")<<endl;
    cout<<m["Srishti"]<<endl;

    //search
    cout<<m.count("fuggi")<<endl;
    if(m.find("fuggi")!=m.end()){
        cout<<"found"<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }

    //size
    cout<<m.size()<<endl;
    cout<<m["hummer"]<<endl;
    cout<<m.size()<<endl;

    //printing
    cout<<"printing all values"<<endl;
    for(auto i:m){
        cout<<i.first<<"->"<<i.second<<endl;
    }
}