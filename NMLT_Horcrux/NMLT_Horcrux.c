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
int list[] = {109, 1, 0, 999};
int Check_Prime(int n);
int Square_Number(int n);
void Journey(int r, int n, int id, int m, int array[], int size);
int main()
{
    Journey(3, 1, 3, 5, list, 4);
    return 0;
}
void Journey(int r, int n, int id, int m, int array[], int size)
{
    int HP, HPmax, h1, h2, P = 1, i, j;
    int Horcrux = 0;
    char Flag_Case, Flag_Prime = 0;
    switch (id)
    {
    case 1: //Harry
        HP = 999;
        HPmax = 999;
        break;
    case 2: //Hermione
        HP = 900;
        HPmax = 900;
        break;
    case 3: //Ron
        HP = 888;
        HPmax = 888;
        if (r < 3)
        {
            P = 0;
        }
        else
        {
            for (i = r - 1; i >= 2; i--)
            {
                //Kiem tra xem i co phai so nguyen to
                /*                 for (j = 2; j <= sqrt(i); j++)
                {
                    if ((i % j) == 0)
                    {
                        Flag_Prime = 1;
                        break;
                    }
                } */
                if (Check_Prime(i))
                {
                    P = i;
                    break;
                }
                //Flag_Prime = 0;
            }
        }

        break;
    case 4: //Ginny
        HP = 777;
        HPmax = 777;
        break;
    default:
        break;
    }
    DBG("%d\n", P);

    for (i = 0; i < size; i++)
    {
        if (Horcrux == n)
        {
            Flag_Case = 1;
            break;
        }
        if (HP <= 0)
        {

            Flag_Case = 2;
            break;
        }
        if (*(array + i) == 0)
        {
            Horcrux++;
            DBG("%d %d %d\n", Horcrux, HP, m);
            continue;
        }
        if ((*(array + i) / 100) == 1)
        {
            //Dau tu than thuc tu
            h1 = i % (100 + r);
            h2 = *(array + i) % (100 + r);
            DBG("%d %d %d\n", h1, h2, 2 < sqrt(5));

            //Kiem tra so nguyen to
            for (j = 2; j <= sqrt(h2); j++)
            {
                if (h2 % j == 0)
                {
                    Flag_Prime = 1;
                    break;
                }
            }

            if (h1 < h2)
            {
                if (id == 1)
                {
                    if ((h2 > m) && (Check_Prime(h2)))
                    {
                        //Harry thua
                        HP -= *(array + i);
                        DBG("%d %d %d\n", Horcrux, HP, m);
                        continue;
                    }
                    else
                    {
                        //Harry  thang
                        m += *(array + i);
                        if (m > 999)
                        {
                            m = 999;
                        }
                        DBG("%d %d %d\n", Horcrux, HP, m);

                        continue;
                    }
                }
                else
                {
                    //Harry thua
                    HP -= *(array + i);
                    DBG("%d %d %d\n", Horcrux, HP, m);
                    continue;
                }
            }
            else
            {
                //Nhan vat thang
                m += *(array + i);
                if (m > 999)
                {
                    m = 999;
                }
                DBG("%d %d %d\n", Horcrux, HP, m);

                continue;
            }
        }
        if (*(array + i) == 1)
        {
            //Tim duoc noi tru an tang mau
            if (P > 0)
            {
                if (((HPmax - HP) * P) < m)
                {
                    HP = HPmax;
                    m = m - (HPmax - HP) * P;
                }
                else
                {
                    HP = HP + m / P;
                    m = m % P;
                }
                DBG("%d %d %d\n", Horcrux, HP, m);

                continue;
            }
        }
        if ((*(array + i) / 100) == 2)
        {
            m = Square_Number(m - *(array + i) % 100);
            //m = pow((int)sqrt(m - *(array + i) % 100), 2.0);
        }
    }

    switch (Flag_Case)
    {
    case 1: //Du Horcrux
        printf("%d", HP + m);
        break;
    case 2: //Het mau
        printf("-1");
        break;
    default: //Chua du
        printf("0");
        break;
    }
}

/**
 * 
 * @return 1 Neu la so nguyen to
  */
int Check_Prime(int n)
{
    int check = 0;
    if (n < 2)
    {
        return 0;
    }
    for (int k = 2; k <= sqrt(n); k++)
    {
        if (n % k == 0)
        {
            check = 1;
            break;
        }
    }
    if (check)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
/**
 * 
 * @return so chinh phuong nho hon gan nhat voi n
  */
int Square_Number(int n)
{
    return pow((int)sqrt(n), 2);
}