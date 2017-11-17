#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* January - 01     Воскресение - 0
 * February - 02    Понедельник - 1
 * March - 03       Вторник - 2
 * April - 04       Среда - 3
 * May - 05         Четверг - 4
 * June - 06        Пятница - 5
 * July - 07        Суббота - 6
 * August - 08
 * September - 09
 * October - 10
 * November - 11
 * December - 12*/

int main()
{
    int d, m, g, w, c, y, a, b, y1, c1, c2, n;

    printf("Enter the date in the format dd mm yyyy");
    scanf("%d %d %d", &d, &m, &g);

    c= g;
    g= g/100;
    y= g;   //Столетие
    c= c-100*g; //Год в столетие

    switch(m){
    case 1:
        a= 0;
        c= c-1;
        m= 11;
        break;
    case 2:
        a= 3;
        c= c-1;
        break;
    case 3:
        a= 2;
        break;
    case 4:
        a= 5;
        break;
    case 5:
        a= 0;
        break;
    case 6:
        a= 3;
        break;
    case 7:
        a= 5;
        break;
    case 8:
        a= 1;
        break;
    case 9:
        a= 4;
        break;
    case 10:
        a= 6;
        break;
    case 11:
        a= 2;
        break;
    case 12:
        a= 4;
        break;
    default:
        printf("Month does not exist");
        break;
    }

    y1= y/4;
    c1= c/4;
    c2= 2*c;

    b=(y+y1+c1-c2);

    w= (d + a + b);

    n= (int)(modf(((float)w/7), NULL)*10);
    if (n == 7 | n == 8 | n == 9){
        printf("Sunday");
    }

    else {
    switch(n){
    case 0:
        printf("Sunday");
        break;
    case 1:
        printf("Monday");
        break;
    case 2:
        printf("Tuesday");
        break;
    case 3:
        printf("Wednesday");
        break;
    case 4:
        printf("Thursday");
        break;
    case 5:
        printf("Friday");
        break;
    case 6:
        printf("Saturday");
        break;
    default:
        printf("The error calculation. Try again");
        break;
    }
}
    return 0;
}
