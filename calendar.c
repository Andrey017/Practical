#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int d, m, g, w, c, y, a, b;

    printf("Enter the date in the format dd mm yyyy");
    scanf("%d %d %d", &d, &m, &g);

    y= g;
    g= g/100;
    c= g;
    y= y-100*g;

    switch(m){
    case 1:
        a= 0;
        break;
    case 2:
        a= 3;
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

    b=(y+(y/4)+(c/4)-2*c)%7;

    w = ( d+ a + b ) % 7;

    switch(w){
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

    return 0;
}
