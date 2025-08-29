#include<iostream>
#include<vector>
using namespace std;

void primsMST(int n,vector<vector<int>>cost){
 int s,mincost=0;
 cout<<"Enter start vertex:";
 cin>>s;

 vector<int>visit(n,0);
 visit[s]=1;

for(int k=0; k<n-1;k++){
    int min=999,row=-1,col=-1;

    for(int i=0;i<n;i++){
        if(visit[i]==1){
            for(int j=0;j<n;j++){
                if(visit[j]==0 && cost[i][j]!=-1 && cost[i][j]< min){
                    min=cost[i][j];
                    row=i;
                    col=j;
                }
            }
        }
         if(row==-1 || col==-1){
            cout<<"graph is connected"<<endl;
            return;
        }
         
        cout<<"selected edge:"<<row<<"-"<<col<<"cost"<<min<<endl;
        mincost+=min;
        visit[col]=1;
        cost[row][col]=-1;
        cost[col][row]=-1;
    }
     cout<<"Minimum cost"<<mincost<<endl;
     cout<<"Adjacency Matrix representation:";

     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
            cout<<cost[i][j]<<"";
         }
     }
 }
}
 int main(){
   int n;
   cout<<"Enter the number of cities";
   cin>>n;

   vector<string>cities(n);
   for(int i=0;i<n;i++){
     cout<<"Enter city"<<i+1<<":";
     cin>>cities[i];
   }
 
   vector<vector<int>>cost(n,vector<int>(n,-1));
   char op;
   
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cout<<"Is there is a path between"<<cities[i]<<"and"<<cities[j]<<"?(Y/N)";
        cin>>op;
        if(op=='Y' || op=='y'){
            cout<<"Enteer your cost:";
            cin>>cost[i][j];
            cost[j][i]=cost[i][j];

        }
      }
   }
    primsMST(n,cost);
    return 0;
}