#include <stdio.h>
#include <stdlib.h>
/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int **matrix, int n, int m, int **result_matrix);

/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);


int input(int **matrix, int n, int m);
void output(int **matrix, int n, int m);
int input_size(int *n, int *m);

int main()
{
    int **matrix, **result;
    int n,m;
    int err = 0;
    err = input_size(&n, &m);
    if (err > 0) {
        err = input(matrix, n, m);
    }
    
    if (err > 0){
        sort_vertical(matrix, n, m, result);
        output(result, n, m);
    
        sort_horizontal(matrix, n, m, result);
        output(result, n, m);
    }
    
    if (err == 0) {
        printf("n/a");
    }
    
    free(matrix);
    free(result);
}

void sort_vertical(int **matrix, int n, int m, int **result_matrix){
    int * arr = malloc(n * m * sizeof(int));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
                arr[i + j] = matrix[i][j];
        }
    }
    sort_arr(arr, n * m);
    
    int **result_matrix = malloc(m * sizeof(int *) + m * n * sizeof(int));
    int *ptr = (int *) (result_matrix + m);

    for (int i = 0; i < m; i++) {
        result_matrix[i] = ptr + n * i;
    }
    
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; i++) {
              if (j % 2 == 0){
                  matrix[i][j] = arr[i + j] ;
              } else {
                  matrix[n - i][j] = arr[i + j];
              }
        }
    }
    free(arr);
}

void sort_horizontal(int **matrix, int n, int m, int **result_matrix){
    int * arr = malloc(n * m * sizeof(int));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
                arr[i + j] = matrix[i][j];
        }
    }
    
    sort_arr(arr, n * m);
    
    int **result_matrix = malloc(m * sizeof(int *) + m * n * sizeof(int));
    int *ptr = (int *) (resul_matrix + m);

    for (int i = 0; i < m; i++) {
        resul_matrix[i] = ptr + n * i;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
              if (i % 2 == 0){
                  result_matrix[i][j] = arr[i + j] ;
              } else {
                  result_matrix[i][m - j] = arr[i + j];
              }
        }
    }
    free(arr);
}

void sort_arr(int* arr, int n) {
    int tmp = 0;
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j + 1 < n - i; ++j) {
          if (a[j + 1] < a[j]) {
            tmp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = tmp;
          }
        }
    }
}

void output (int **matrix, int n, int m){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
          if (j < m - 1) {
            printf("%d ", matrix[i][j]);
          } else {
            printf("%d", matrix[i][j]);
          }
        }
    }
}

int input (int **matrix, int n, int m) {
  char c;
  int ret = 0;
  
  int **single_array_matrix = malloc(m * sizeof(int *) + m * n * sizeof(int));
  int *ptr = (int *) (single_array_matrix + m);

  for (int i = 0; i < m; i++) {
    single_array_matrix[i] = ptr + n * i;
  }
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (scanf("%d%c", &single_array_matrix[i][j], &c) == 2 && (c == '\n' || c == ' ')) {
        ret++;
      } else {
        ret = 0;
        break;
      }
    }
  }
}

int input_size(int *p_size_n, int *p_size_m) {
  int ret = 0;
  char c;

  if (scanf("%d%c", *p_size_n, &c) == 2 && (c == '\n' || c == ' ') && *p_size_n > 0) {
    ret++;
  }

  if (ret > 0 && scanf("%d%c", *p_size_m, &c) == 2 && (c == '\n' || c == ' ') && *p_size_m > 0) {
    ret++;
  } else {
    ret = 0;
  }

  return ret;
}










