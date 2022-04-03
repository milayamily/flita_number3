#include <stdio.h>
#include <stdlib.h>
#define ARR_MAX 1001

int main()
{
    FILE *file = fopen("matrix_of_incendence18.txt", "r");
    char arr[ARR_MAX][ARR_MAX], s, conn = '"';
    int line = 1, ver = 0, reb = 0, max_len = 0;
    // -----------------------------------------
    while (!feof(file)) // запись матрицы из файла в двумерный массив
    {
        fscanf(file, "%c", &s);
        if (s != ' ' && s != '\n' && s != '\0')
        {
            arr[line][ver] = s;
            ver++;
        }
        else if (s == '\n')
        {
            line++;
            max_len = ver;
            ver = 0;
        }
    }
    arr[line][max_len] = '\0';
    fclose(file);
    file = fopen("graph.gv", "w");
    fprintf(file, "graph Grah {\n");
    printf("------------------\n");
    printf("Your matrix:\n");
    for (int a = 0; a <= line; a++)
    {
        int c = a + 1;
        for (int b = 0; b <= ver; b++)
        {
            printf("%c ", arr[a][b]);
            if (arr[a][b] == '1' && arr[c][b] == '1')
            {
                reb++;
            }
        }
        printf("\n");
    }
    printf("------------------\n");
    printf("Adjacency list:\n");
    for (int d = 1; d <= line; d++)
    {
        fprintf(file, "%d\n", d);
        printf("%d\n", d);
    }
    for (int j = 0; j <= line; j++)
    {
        for (int k = 0; k <= ver; k++)
        {
            if (arr[j][k] == '1')
            {
                for (int f = j; f <= line; f++)
                {
                    if (arr[f][k] == '1' && f != j)
                    {
                        printf("%d -- %d\n", j, f);
                        fprintf(file, "%d -- %d\n", j, f);
                    }
                }
            }
        }
    }
    printf("------------------\n");
    if (reb >= ((line - 1) * (line - 2) / 2)) // graph connectivity theorem
    {
        printf("graph - connected\n");
        fprintf(file, "0 [label = %c connected %c]\n", conn, conn);
    }
    else
    {
        printf("graph -  not connected\n");
        fprintf(file, "0 [label = %c not connected %c]\n", conn, conn);
    }
    printf("------------------\n");
    fprintf(file, "}");
    fclose(file);
    system("dot graph.gv -Tpng -o graph.png");
    system("graph.png");
    return 0;
}
