#User function Template for python3
def listReverse(list,start,end):
    while(start<end):
        temp = list[start]
        list[start] = list[end] #Swaping
        list[end]=temp
        start+=1
        end-=1
    return list
    
def can_sort(arr,n):
    # code here
    flag=0
    retFlag=1
    for i in range(1,n-1,1):
        if (arr[i-1]!=i):
            lower = i-1
            value=i
            #higher = arr.index(i)
            flag=1
            break
        
    for i in range (0,n,1): 
        if(arr[i]==value):
            higher = i
        
    if(flag):
        listReverse(arr,lower,higher)
        
    for i in range(0,n,1):
        if(arr[i]!=i+1):
            retFlag=0
    if(retFlag==1):
        return 1
    elif (retFlag==0):
        return 0

#{ 
#  Driver Code Starts
#Initial Template for Python 3

t=int(input())
for _ in range(t):
    line=input().strip().split()
    n=int(line[0])
    arr=[]
    for i in range(n):
        arr.append(int(line[i+1]))
    if(can_sort(arr,n)):
        print('Yes')
    else:
        print('No')
# } Driver Code Ends
