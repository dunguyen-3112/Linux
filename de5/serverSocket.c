#include <stdio.h>
#include <math.h>

int isAmstrong(int value)
{
    char str[100];
    sprintf(str, "%d", value);
    int c = 0;
    double S = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        c = (double)str[i] - 48.0;
        S += pow(c, 3);

        // printf("%d, %lf\n", c, );
    }
    // printf("%lf", S);
    if (S == value)
        return 1;
    return 0;
}
int main()
{

    printf("*********************************************************************\n\
* Bai thi ket thuc mon: Lap trình tren Linux.                       *\n\  
* Ho va ten: NGUYEN HUU DU                                          *\n\
* Nhom: Nh19??                                                      *\n\
* Masv: 102190157                                                   *\n\
* De so: 04.                                                        *\n\
*********************************************************************\n\n");
    int s = isAmstrong(153);
    printf("%d", s);
    return 0;
}