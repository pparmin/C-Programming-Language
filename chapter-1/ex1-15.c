#include <stdio.h>   

int f_to_c(int fahr)
{
    int celsius = 5 * (fahr-32) / 9;
    return celsius;
}

int main(void)   
{     
    int fahr, celsius;     
    int lower, upper, step;     
    lower = 0;      /* lower limit of temperature scale */    
    upper = 300;    /* upper limit */     
    step = 20;      /* step size */     
    fahr = lower;     
    while (fahr <= upper) 
    {         
        celsius = f_to_c(fahr);       
        printf("%d\t%d\n", fahr, celsius);         
        fahr = fahr + step;     
    } 

    return 0;  
}