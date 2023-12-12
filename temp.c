#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char c1 = -1;
char c2 = 3;
char c3 = -1;
char call = 0;

double filter(char a)
{   
    double res = 0;
    if (call > 2)
        call = 0;

    if (call == 0)
        res = (a*c1);
    else if (call == 1)
        res = (a*c2);
    else 
        res = (a*c3);
        
    printf("%i\t %f\n", call, res);
    
    call++;

    return res;
}

int generator()
{
    srand(time(NULL));
    int r = rand() % 5000 + 1; 
    return r;
}

void delay(int sec)
{
    int msec = (1000 * sec);
    clock_t start = clock();
    while (clock() < (start + msec))
    {
        ;
    }    
}

void main()
{
    char a = 0;
    double res = 0; 
    char counter = 0;
    char i = 0;

    while(1)
    {   
        if ((i == 3) || (i == 6) || (i == 9))
        {
            a = generator();
            counter = 1;            
        }
        else if ((i == 10))
        {
            i = 0;
            printf("total:\t%f\n", res);
            res = 0;
        }    
        else 
            counter = 0;

        if (counter == 1)
            res += filter(a);
        
        i++;
        delay(400);
    }
}

