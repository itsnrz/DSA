#include<iostream>
#include<vector>
using namespace std;

bool canMultiply(vector<pair<int,int>> &dim){
    int size=dim.size();
    bool can=true;
    for(int i=0;i<size-1;i++){
        if(dim[i].second!=dim[i+1].first){
            can=false; break;
        }
    }
    return can;
}

int findMinimumCost(vector<pair<int,int>>& dim,  vector<vector<int>>&cost,vector<vector<int>> &kVal){
    int size=dim.size();
    vector<int>p;
    p.push_back(dim[0].first);
    for(int i=0;i<size;i++)p.push_back(dim[i].second);
    for(int i=0;i<=size;i++) cost[i][i]=0;
    for(int len=2;len<=size;len++){
        for(int i=1;i<=size-len+1;i++){
            int j=i+len-1;
            cost[i][j]=1e9;
            int indx=-1;
            for (int k=i;k<j;k++) {
                int find = cost[i][k] + cost[k+1][j]  + p[i-1] * p[k] * p[j];
                if(cost[i][j]>find){
                    cost[i][j]=find;
                    indx=k;
                }
            }
            kVal[i][j]=indx;
        }
    }
    return cost[1][size];
}
void display(vector<vector<int>>&k,int i,int j){
    if(i==j){
        cout<<"A"<<i<<" ";
        return;
    }
    cout<<"(";
    int kval=k[i][j];
    display(k,i,kval);
    display(k,kval+1,j);
    cout<<")";
}
int main(){
    int n;
    cout<<"Enter the number of matrixes : ";
    cin>>n;
    vector<pair<int,int>>dim;
    cout<<endl;
    cout<<"Enter dimension of each matrix "<<endl;
    for(int count=0;count<n;count++){
        cout<<"Matrix "<<count+1<<" (i,j): ";
        int i,j;
        cin>>i>>j;
        dim.push_back({i,j});
    }
    cout<<endl;
    cout<<"checking if matrices can be multiplied "<<endl;
    if(canMultiply(dim)){
        cout<<"Matrices can be multiplied"<<endl;
    }else{
        cout<<"Matrices cant be multiplied"<<endl;
    }
    // -1 denotes invalid values
    vector<vector<int>>cost(n+1,vector<int>(n+1,-1));
    vector<vector<int>>k(n+1,vector<int>(n+1,-1));
    int minOperation=findMinimumCost(dim,cost,k);
    cout<<"min operation are  "<<minOperation<<endl;
    display(k,1,n);
    return 0;
}

