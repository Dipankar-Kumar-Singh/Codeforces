// #include <xc.h>
#include<stdio.h>
#include<stdlib.h>
// #include<pic18f4550.h>

int main(void) {
    
    int num[] = {10, 2, 5, 1, 6};


    for (int i = 0; i < 5; i++) 
    {
        for (int j = i + 1; j < 5; j++) 
        {
            if (num[i] > num[j]) 
            {
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }

    for(auto x : num)
    {
        printf("%d",x) ;
        printf(" ") ;
    }
}

