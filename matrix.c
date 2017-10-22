#include <stdio.h>
#include <stdlib.h>

int **A;
int **B;
int **C;
int **D;

int main(int argc, char *argv[])
{
    int N, M, i, j, t, k, s, min, di, dj, l, p, R, H, Z, g, y;
    N= atoi(argv[1]);   //Количество строк
    M= atoi(argv[2]);   //Количество столбцов

    A = (int **) malloc(sizeof(int)*N);
    for (i=0; i<N; i++){
        A[i]=(int*)malloc(sizeof(int*)*M);
    }
    if(A == NULL) exit(1);

    //Создаем массив
    if (N>3 & M>4){
        for (i=0; i<N; i++){
            for (j=0; j<M; j++){
                A[i][j]= (rand()&(20 - 10 +1));
                printf("\t%d", *(*(A+i)+j));
            }
            puts("\n");
        }
    }
    else{
        printf("Incorrect parameters");
        return -1;
    }

    puts("\n");

    //Меняем первую  строчку с последней
    for (j=0; j<M; j++){
        t= A[0][j];
        A[0][j]= A[N-1][j];
        A[N-1][j]= t;
    }
    //Меняем элементы массива
    for (j=0; j<M; j++){
        k= A[0][j];
        A[0][j]= A[0][M-1];
        A[0][M-1]= k;

        s= A[N-1][j];
        A[N-1][j]= A[N-1][M-1];
        A[N-1][M-1]= s;
        M--;
    }
    M= atoi(argv[2]);
    //Выводим результат
    for (i=0; i<N; i++){
        for (j=0; j<M; j++){
            printf("\t%d", *(*(A+i)+j));
        }
        puts("\n");
    }
    //Находим наименьший элемент массива
    for (i=0; i<N; i++){
        for(j=0; j<M; j++){
            if(A[i][j]<=min){
                min= A[i][j];
                di=i;
                dj=j;
            }
        }
    }

    R=N;    //N-1
    H=M;    //M-1

/*    B = (int **) malloc(sizeof(int)*R);
    for (l=0; l<R; l++){
        B[l]=(int*)malloc(sizeof(int*)*H);
    }
    if(B == NULL) exit(1);

    for(i=0; i<N; i++){
        if (i == di){
            continue;
        }
        for(j=0; j<M; j++){
            if (j == dj){
                continue;
            }
            B[l][p]= A[i][j];
            p++;
        }
        l++;
    }

    for (l=0; l<R; l++){
        for (p=0; p<H; p++){
            printf("\t", *(*(B+l)+p));
        }
        puts("\n");
    }*/

    printf("\tEnter the number of columns =");
    scanf("%d", &Z);

    printf("\n");

    //Вводим вторую матрицу
    C = (int **) malloc(sizeof(int)*H);
    for (i=0; i<H; i++){
        C[i]= (int*) malloc(sizeof(int*)*Z);
    }
    if(C == NULL) exit(1);


    for (i=0; i<H; i++){
        for (j=0; j<Z; j++){
            printf("\tEnter the number [%d][%d] =", i, j);
            scanf("%d", *(C+i)+j);
            /*C[i][j]= (rand()&(20 - 10));
            printf("\t%d", *(*(C+i)+j));*/
        }
        puts("\n");
    }

    /*for (i=0; i<H; i++){
        for (j=0; j<Z; j++){
            printf("\t%d", *(*(C+i)+j));
        }
        puts("\n");
    }*/

    D = (int **) malloc(sizeof(int)*N);
    for (i=0; i<N; i++){
        D[i]= (int*) malloc(sizeof(int*)*Z);
    }
    if (D == NULL) exit(1);

    puts("\n");

    //Перемножаем матрицы B(A) и C
    for(i=0; i<N; i++){
        for (j=0; j<Z; j++){
            D[i][j]=0;
            for (y=0; y<M; y++){
                D[i][j] += A[i][y]*C[y][j];
            }
        }
    }

    printf("Result:");

    //Выводим результат
    for (i=0; i<N; i++){
        for (j=0; j<Z; j++){
            printf("\t%d", *(*(D+i)+j));
        }
        puts("\n");
    }

    for (i=0; i<N; i++){
        free(A[i]);
        free(C[i]);
        free(D[i]);
    }
    free(A);
    free(C);
    free(D);

    return 0;
}
