#include <stdio.h>
#include <stdlib.h>
#define ARR_MAX 1001

int main()
{
  FILE *file;
  char m[ARR_MAX];
  char s = ' ';
  int edge = 0, a = 0, vertice = 1;
  int k, j, rez1, kol, d;
  file = fopen("matrix_of_incendence198.txt", "r");
  while (!feof(file))
  {
    if (a == 0 && s == '\n')
    {
      a = edge; // number of edges
    }
    if (s == '\n')
    {
      vertice++; // number of vertices
    }
    if (s == '1' || s == '0')
    {
      m[edge] = s;
      edge++;
    }
    fscanf(file, "%c", &s);
  }
  printf("------------------\n");
  if (a > ((vertice - 1) * (vertice - 2) / 2)) // graph connectivity theorem
  {
    printf("graph - SVYAZNYI\n");
  }
  else
  {
    printf("graph - NESVYAZNYI\n");
  }
  printf("------------------\n");
  fclose(file);
  file = fopen("graf.gv", "w");
  fprintf(file, "graph Grah {\n");
  for (j = 1; j <= a; j++)
  {
    kol = 0;
    for (k = j; k <= edge; k++)
    {
      if (m[k - 1] == '1')
      {
        if (kol > 0)
        {
          printf("%d\n", k / (a + 1) + 1);
          fprintf(file, "%d;\n", k / (a + 1) + 1);
          break;
        }
        if (kol == 0)
        {
          kol++;
          printf("%d -- ", k / (a + 1) + 1);
          fprintf(file, "%d -- ", k / (a + 1) + 1);
        }
      }
      k += a - 1;
    }
  }
  for (d = 1; d <= vertice; d++)
  {
    fprintf(file, "%d;\n", d);
  }

  fprintf(file, "}");
  fclose(file);
  system("dot graf.gv -Tpng -o graf.png");
  system("graf.png");
}