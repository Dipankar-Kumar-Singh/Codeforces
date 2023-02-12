g = [[]]*10 ;
n : int ;


# n = int(input()) ;
# m = int(input()) ;

# n , m = map(int, input().split()) ;

n = int(input()) 
print() ;

print(g) ;

def takeInput():
    for i in range(n - 1) :
        x , y = map(int,input().split())  
        print("x = " , x , "  y = " , y ) ;
        g[x].append(y) ;
        print("graph g[x] " , g[x] , "\n") ;
        g[y].append(x) ; 
        print("graph g[y] " ,g[y] , "\n") ;
        print("FULL GRAPHG : " ,  g , "\n") 

        print() ;



def dfs(node: int,  par: int):
    print("\nNode : ",  node , end = "   ")
    print("children : " , end = ' ') ;

    for child in g[node]  : 
        if(child == par) :
            continue ;
        else :
            print(child , end = ' ') ;

    print() ;
    
    for child in g[node]  : 
        if(child == par) :
            continue
        else :
            dfs(child,node) ;


takeInput() ;

print() ;

# print(g) ;

# print() ;

# dfs(1,-1) ;







        