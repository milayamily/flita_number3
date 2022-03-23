#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *files;
  char m[100];
  char s = ' ';
  int a = 0, b = 0, c = 1;
  int e, j, kol, d;
  files = fopen("matrix_of_incendence18.txt", "r"); // открываем файл с матрицей
  while (!feof(files)) // цикл записи матрицы в массив
  {
    if (a == 0 && s == '\n')
    {
      a = b; // определяем число строк
    }
    if (s == '\n')
    {
      c++; // определяем число столбцов
    }
    if (s == '1' || s == '0')
    {
      m[b] = s;
      b++;
    }
    fscanf(files, "%c", &s);
  }
  if (a > ((c - 1) * (c - 2) / 2)) // проверяем связность графа по теореме о связности графа
  {
    printf("connected graph\n");
  }
  else
  {
    printf("non connected graph\n\n");
  }
  fclose(files); // закрываем файл
  files = fopen("graf.gv", "w"); // создаем новый файл куда будет записывать список смежности
  fprintf(files, "graph Grah {\n");
  for (j = 1; j <= a; j++) // двойной цикл для вывода списка смежности
  {
    kol = 0;
    for (e = j; e <= b; e++)
    {
      if (m[e - 1] == '1')
      {
        if (kol > 0)
        {
          printf("%d\n", e / (a + 1) + 1);
          fprintf(files, "%d;\n", e / (a + 1) + 1);
          break;
        }
        if (kol == 0)
        {
          kol++;
          printf("%d -- ", e / (a + 1) + 1);
          fprintf(files, "%d -- ", e / (a + 1) + 1);
        }
      }
      e += a - 1;
    }
  }
  for (d = 1; d <= c; d++)
  {
    fprintf(files, "%d;\n", d);
  }

  fprintf(files, "}");
  fclose(files);
  system("dot graf.gv -Tpng -o graph.png"); // через систему вызываем graphviz которые преобразует наш список смежности в граф в формате картинки
  system("graph.png"); // открываем картинку с графом
}
