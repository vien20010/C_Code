/** 
 * 
 * November 25th, 2020
 * LV_Embedded
 * nguyenlamvien0110@gmail.com 
 * https://github.com/vien20010
 * 
 **/

#include <stdio.h>
#include "Debug.h"
#include <stdint.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
int R, HP;
uint16_t N, M;
uint8_t ID;

int main()
{
    char *str_E = (char *)malloc(sizeof(char));
    int *E=(int *)malloc(sizeof(int));
    int space_count = 0,j=0;
    printf("Nhap R N ID M Ei\n");
    scanf("%d", &R);
    scanf("%u", &N);
    scanf("%u", &ID);
    scanf("%u", &M);
    DBG("Cac thong so da nhap %d \t %d\t%d\t%d\n", R, N, ID, M);
    scanf("\n");
    scanf("%[^\n]%*c", E);
    DBG("%d\n",strlen(str_E));
    DBG("%s\n", str_E);
/*             sscanf(str_E,"%d %d",E+0,E+1);
        DBG("%d\t%d\n",*(E+0),*(E+1)); */
    for (int i = 0; i<strlen(str_E); i++)
    {
        if (*(str_E+i)==' ')
        {
            space_count++;
/*             j++;
            sscanf(str_E+i+1,"%d",E+j);
            DBG("%d\t",*(E+j)); */
        }
    }
    str_E=(char *)malloc(strlen(str_E)*sizeof(char));
    DBG("%s\n", str_E);
    DBG("%d\n",strlen(str_E));
/*     DBG("\n"); */
    DBG("%d\n",space_count);
        sscanf(str_E,"%d",E);
    DBG("%d\n",*E);
/*     E=(int *)malloc((space_count+1)*sizeof(int));
    for (int i=0;i<=space_count;i++)
    {
        sscanf(str_E,"%d",E+i);
        DBG("%d\n",*(E+i));
    } */
    return 0;
}