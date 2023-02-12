l = [1,1,1,5,2,2,3] # 1->3 , 5 ->1

x = l[0] 
for i in range(1,len(l)):
    x^=l[i]

print("xor of list " , x)

for A in l: 
    B = (x ^ A) ;
    if((A^B) == x):
        print("A :" , A , " B : " , B) 
        