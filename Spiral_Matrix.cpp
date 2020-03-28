// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int findK(int [MAX][MAX],int ,int ,int );
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        cout<<findK(a,n,m,k)<<endl;
        
       
    }
}// } Driver Code Ends
/*You are required to complete this method*/
int findK(int A[MAX][MAX], int n, int m, int k)
{
  
    int rowStart=0,rowEnd=n;
    int colStart=0,colEnd=m;
    int ansRow=0,ansCol=0;
    int count=0;
    int i;
    bool flagReach=0;
    while((rowStart<rowEnd)&&(colStart<colEnd)&&count>=k)
    {
        //Traverse left to right
        for(i=colStart;i<colEnd;i++)
        {
            count++;
            if(count==k)
            {
                flagReach=1;
                ansRow=rowStart; ansCol=i;
                break;
            }
        }
        rowStart++; //So that we will not come to this row again
        if(flagReach)
            break;        

        //Traverse up to down
        for(i=rowEnd;i>=rowStart;i--)
        {
            count++;
            if(count==k)
            {
                flagReach=1;
                ansRow=i; ansCol=colEnd-1;
                break;
            }
        }
        colEnd--;
        if(flagReach)
            break;
        
        //Traverse right to left
        if(rowStart<rowEnd)
        {
            for(i=colEnd-1;i>=colStart;i--)
            {
                count++;
                if(count==k)
                {
                    flagReach=1;
                    ansRow=rowEnd-1; ansCol=i;
                    break;
                }
            }
            rowEnd--;
        }
        if(flagReach)
            break;
         
        //Traverse down to up
        if(colStart<colEnd)
        {
            for(i=rowEnd-1;i>=rowStart;i--)
            {
                count++;
                if(count==k)
                {
                    flagReach=1;
                    ansRow=i; ansCol=colStart;
                    break;
                }
            }
            rowStart++;
        }
        if(flagReach)
            break;
    }
    
    // return A[ansRow][ansCol]   ; 
 
}

