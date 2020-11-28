/** 
 * 
 * November 25th, 2020
 * LV_Embedded
 * nguyenlamvien0110@gmail.com 
 * https://github.com/vien20010
 * 
 **/

#include <stdio.h>
//#include "Debug.h"
#include <stdint.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

//#define	DEBUG

#ifdef DEBUG
    #define DBG(fmt, ...) printf("%s:  %s:  %d: " fmt, __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
    #define DBG(fmt, args...)
#endif



int Check_Prime(int n);
int gcd(int a, int b);
int Coprime(int a, int b);
int Square_Number(int n);
void Journey(int r, int n, int id, int m, int array[], int size);
int Find_Continious_Element(int *array, int size);
void BubbleSort(int *array, int size);
void swap(int *num1, int *num2);
void copy_array(int *src, int *dest, int size);
int Fibonacci(int n);
int Check_Fibonacci(int n);



int main()
{
    int list8[] = {0,108,0,234,235,0,666,0,0,0,0,0,106,107,0};
    Journey(0,5,4,711, list8 ,15);
    return 0;
}

void Journey(int r, int n, int id, int m, int array[], int size)
{
    int HP, HPmax, h1, h2, P = 1, Q = 1, i, j;
    int Horcrux = 0;
    char Flag_Case = 0, Flag_Prime = 0, FLag_Ignore = -1, Flag_Invisible = 0, Elder_Wand = 0;

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
                if (Check_Prime(i))
                {
                    P = i;
                    break;
                }
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
        DBG("Su kien %d dang dien ra\n", i);
        if (i == FLag_Ignore)
        {
            DBG("Ignore su kien: %d\n", i);
            continue;
        }
        if (Horcrux == n)
        {
            Flag_Case = 1;
            break;
        }
        if ((HP <= 0) || (Flag_Case == 2))
        {
            Flag_Case = 2;
            break;
        }
        if (*(array + i) == 0)
        {
            Horcrux++;
            DBG("%d %d %d %d\n", Horcrux, HP, m, i);
            continue;
        }
        if ((*(array + i) / 100) == 1)
        {
            //Dau tu than thuc tu
            h1 = (i + 1) % (100 + r);
            h2 = *(array + i) % (100 + r);
            DBG("%d %d \n", h1, h2);

            if ((h1 < h2) && (((id == 1) && (h2 > m) && (Check_Prime(h2))) || (id != 1)))
            {
                if (Flag_Invisible)
                {
                    continue;
                }
                //Nhan vat thua
                HP -= *(array + i);
                DBG("%d %d %d %d\n", Horcrux, HP, m, i);
                continue;
            }
            else
            {
                //Nhat vat thang
                m += *(array + i);
                if (m > 999)
                {
                    m = 999;
                }
                DBG("%d %d %d %d\n", Horcrux, HP, m, i);
                continue;
            }
        }
        if (*(array + i) == 1)
        {
            DBG("Tim duoc noi tru an\n");
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
                DBG("%d %d %d %d\n", Horcrux, HP, m, i);

                continue;
            }
        }
        //Gap muggle
        if ((*(array + i) / 100) == 2)
        {
            DBG("Gap may thang Muggle phe vat\n");
            if (Flag_Invisible)
            {
                continue;
            }
            if (FLag_Ignore == -1)
            {
                if ((m - *(array + i) % 100) > 4)
                {

                    m = Square_Number(m - *(array + i) % 100);
                    DBG("%d %d %d %d\n", Horcrux, HP, m, i);
                    continue;
                    //m = pow((int)sqrt(m - *(array + i) % 100), 2.0);
                }
                else
                {
                    if (i < 2)
                    {
                        DBG("Break\n");
                        break;
                    }
                    else
                    {

                        FLag_Ignore = i;
                        i -= 3;
                        DBG("Ignore %d\n", i);
                        continue;
                    }
                }
            }
            else
            {
                /* code */
                m = Square_Number(m - *(array + i) % 100);
                DBG("%d %d %d %d\n", Horcrux, HP, m, i);
                continue;
            }
        }
        //Gap nhan su
        if ((*(array + i) / 100) == 3)
        {
            DBG("Gap may lol nhan su cao thuong");
            if (Flag_Invisible)
            {
                continue;
            }
            //Dau tu than thuc tu
            h1 = (i + 1) % (100 + r);
            h2 = *(array + i) % (100 + r);
            DBG("%d %d \n", h1, h2);

            if ((h1 < h2) && (((id == 1) && (h2 > m) && (Check_Prime(h2))) || (id != 1)))
            {
                //Nhan vat thua
                //HP -= *(array + i);
                Horcrux = 0;
                DBG("%d %d %d %d\n", Horcrux, HP, m, i);
                continue;
            }
            else
            {
                //Nhat vat thang
                Flag_Invisible = 1;
                /*                 m += *(array + i);
                if (m > 999)
                {
                    m = 999;
                } */
                DBG("%d %d %d %d\n", Horcrux, HP, m, i);
                continue;
            }
        }
        if ((*(array + i) / 100) == 5)
        {
            DBG("Gap nguoi khong lo\n");
            //Nguoi khong lo
            if ((Flag_Invisible) || (((id % 2) == 0) && (Coprime(HP, *(array + i) % 100))))
            {
                continue;
            }
            //Dau tu nguoi khong lo
            h1 = (i + 1) % (100 + r);
            h2 = *(array + i) % (100 + r);
            DBG("%d %d \n", h1, h2);

            if ((h1 < h2) && (((id == 1) && (h2 > m) && (Check_Prime(h2))) || (id != 1)))
            {
                //Nhan vat thua
                HP -= *(array + i);
                //Tinh Q
                for (j = (int)sqrt(*(array + i) % 100); j > 1; j--)
                {
                    if (Check_Prime(j) && (((*(array + i) % 100) % j) != 0))
                    {
                        Q = j;
                        break;
                    }
                }
                if (Q > m)
                {
                    m = 0;
                }
                else
                {
                    m -= Q;
                }

                DBG("%d %d %d %d\n", Horcrux, HP, m, i);
                continue;
            }
            else
            {
                //Nhat vat thang
                Flag_Invisible = 1;
                DBG("%d %d %d %d\n", Horcrux, HP, m, i);
                continue;
            }
        }
        if (*(array + i) == 666)
        {
            DBG("Gap Bllatrix Lestrange\n");
            //Gap Bellatrix Lestrange
            //Dau tu than thuc tu
            h1 = (i + 1) % (100 + r);
            h2 = *(array + i) % (100 + r);
            DBG("%d %d \n", h1, h2);

            if ((h1 < h2) && (((id == 1) && (h2 > m) && (Check_Prime(h2))) || (id != 1)))
            {
                if (Flag_Invisible)
                {
                    continue;
                }
                //Nhan vat thua
                Q = Find_Continious_Element(array, size);
                DBG("%d\n", Q);
                if (Q > Horcrux)
                {
                    Horcrux = 0;
                }
                else
                {
                    Horcrux -= Q;
                }

                HP -= *(array + i);
                DBG("%d %d %d %d\n", Horcrux, HP, m, i);
                continue;
            }
            else
            {
                //Nhat vat thang
                if ((!Flag_Invisible) && (Horcrux > 0))
                {
                    Horcrux--;
                }
                m += *(array + i);
                if (m > 999)
                {
                    m = 999;
                }
                DBG("%d %d %d %d\n", Horcrux, HP, m, i);
                continue;
            }
        }
        if (*(array + i) == 777)
        {
            DBG("Gap Snape\n");
            if (Flag_Invisible)
            {
                continue;
            }
            switch (id)
            {
            case 1:
                HP = 999;
                m = 999;
                Elder_Wand = 1;
                break;
            case 2:
            case 3:
                j = 1;
                while (Fibonacci(j) < HP)
                {
                    j++;
                }
                HP = Fibonacci(j - 1);
                break;
            case 4:
                Flag_Case = 2;
                break;
            default:
                break;
            }
            continue;
        }
        if (*(array + i) == 999)
        {
            DBG("Danh Voldemort\n");
            if (Elder_Wand)
            {
                HP = 999;
                m = 999;
                DBG("Harry vs com nguoi\n");
                continue;
            }
            if (Check_Fibonacci(i + 1))
            {
                DBG("Su kien Fibonacci\n");
                h1 = (i + 1) % (100 + r);
                h2 = *(array + i) % (100 + r);
                DBG("%d %d \n", h1, h2);

                if ((h1 < h2) && (((id == 1) && (h2 > m) && (Check_Prime(h2))) || (id != 1)))
                {
                    if (Flag_Invisible)
                    {
                        continue;
                    }
                    //Nhan vat thua
                    Flag_Case = 2;
                    DBG("Thua Voldemort\n");
                    break;
                }
                else
                {
                    //Nhat vat thang
                    DBG("Thang Voldemort\n");
                    m = 999;
                    HP = HPmax;
                    DBG("%d %d %d %d\n", Horcrux, HP, m, i);
                    continue;
                }
            }
            DBG("Thua Vol\n");
            Flag_Case = 2;
        }
    }
    if (Horcrux == n)
    {
        Flag_Case = 1;
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
 * @return uoc chung lon nhat cua a va b su dung de quy
  */
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
/**
 * 
 * @return 1 Neu a vs b la 2 so nguyen to cung nhau
  */
int Coprime(int a, int b)
{
    if (gcd(a, b) == 1)
        return 1;
    else

        return 0;
}
/**
 * 
 * @return so chinh phuong nho hon gan nhat voi n
  */
int Square_Number(int n)
{
    return pow((int)sqrt(n), 2);
}

void copy_array(int *src, int *dest, int size)
{
    for (int k = 0; k < size; k++)
    {
        *(dest + k) = *(src + k);
    }
}

void swap(int *num1, int *num2)
{
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
void BubbleSort(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (*(array + i) > *(array + j))
            {
                swap(array + i, array + j);
            }
        }
    }
}

int Find_Continious_Element(int *array, int size)
{
    int Count_Continious = 1, max = 0;
    int *ArrayCount = (int *)malloc(size * sizeof(int));
    copy_array(array, ArrayCount, size);
    BubbleSort(ArrayCount, size);
    for (int k = 1; k < size; k++)
    {
        if ((*(array + k) - *(array + k - 1)) == 1)
        {
            Count_Continious++;
        }
        else
        {
            if (Count_Continious > max)
            {
                max = Count_Continious;
            }
            Count_Continious = 1;
        }
    }
    free(ArrayCount);
    return max;
}

int Fibonacci(int n)
{
    if ((n == 0) || (n == 1))
        return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int Check_Fibonacci(int n)
{
    int k = 1;
    while (Fibonacci(k) < n)
    {
        k++;
    }
    //DBG("Fibonacci k: %d\n", Fibonacci(k));
    if (Fibonacci(k) == n)
    {
        return 1;
    }
    return 0;
}
