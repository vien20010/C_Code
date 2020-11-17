#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Debug.h"

int main()
{
    FILE *fptr_in, *fptr_out;
    unsigned int n = 0, k = 0;
    unsigned int i = 0, sum = 0,count=0, *a;

    fptr_in = fopen("ABC.inp", "r");
    fscanf(fptr_in, "%u", &n);
    fscanf(fptr_in, "%u", &k);
    DBG("%u\t%u\n",n,k);
    a = (unsigned int *)malloc(n * sizeof(unsigned int));
    for (i = 0; i < n; i++)
    {
        fscanf(fptr_in,"%u",a+i);
        //DBG("%u\t",*(a+i));
    }
    fclose(fptr_in);
    DBG("\n");
    for (i=0;i<n;i++)
    {
        sum+=*(a+i);
        if (sum>k)
        {
            DBG("%u\n",sum);
            sum=0;
            count++;
            i--;
        }
    }
    if (sum!=0)
        count++;
    DBG("%u",count);
    fptr_out=fopen("ABC.out","w");
    fprintf(fptr_out,"%u",count);
    fclose(fptr_out);
    return 0;
}