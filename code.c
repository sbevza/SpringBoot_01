#include <stdio.h>
#include <stdlib.h>

#define NMAX 100
#define MMAX 100

void output_stat(int arr[MMAX][NMAX], int m, int n);
void output_dynam(int **arr, int m, int n);
int input_type(int *p_type);
int input_size(int *p_size_m, int *p_size_n);
int static_matrix(int arr[MMAX][NMAX], int m, int n);
int dynamic_matrix1(int m, int n);
int dynamic_matrix2(int m, int n);
int dynamic_matrix3(int m, int n);

int main() {
  int result;
  int type;
  int data[MMAX][NMAX];
  int size_m, size_n;

  result = input_type(&type);

  if (result > 0) {
    result = input_size(&size_m, &size_n);

    switch (type) {
      case 1: {
        result = static_matrix(data, size_m, size_n);
        break;
      }
      case 2: {
        result = dynamic_matrix1(size_m, size_n);
        break;
      }
      case 3: {
        result = dynamic_matrix2(size_m, size_n);
        break;
      }
      case 4: {
        result = dynamic_matrix3(size_m, size_n);
        break;
      }
      default: {
        result = 0;
      }
    }
  }

  if (result == 0) {
    printf("n/a");
  }

  return 0;
}



int dynamic_matrix3(int m, int n) {
  int **single_array_matrix = malloc(m * sizeof(int *) + m * n * sizeof(int));
  int *ptr = (int *) (single_array_matrix + m);

  for (int i = 0; i < m; i++) {
    single_array_matrix[i] = ptr + n * i;
  }

  char c;
  int ret = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (scanf("%d%c", &single_array_matrix[i][j], &c) == 2 && (c == '\n' || c == ' ')) {
        ret++;
      } else {
        ret = 0;
        break;
      }
    }
  }

  if (ret != 0) {
    output_dynam(single_array_matrix, m, n);

  }

  free(single_array_matrix);
  return ret;
}

int dynamic_matrix2(int m, int n) {
  int **pointer_array = malloc(m * sizeof(int *));

  for (int i = 0; i < m; i++) {
    pointer_array[i] = malloc(n * sizeof(int));
  }

  char c;
  int ret = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (scanf("%d%c", &pointer_array[i][j], &c) == 2 && (c == '\n' || c == ' ')) {
        ret++;
      } else {
        ret = 0;
        break;
      }
    }
  }

  if (ret != 0) {
    output_dynam(pointer_array, m, n);
  }

  for (int i = 0; i < m; ++i) {
    free(pointer_array[i]);
  }
  free(pointer_array);
  return ret;
}

int dynamic_matrix1(int m, int n) {
  int **pointer_array = malloc(m * sizeof(int *));
  int *values_array = malloc(m * n * sizeof(int));

  for (int i = 0; i < m; i++) {
    pointer_array[i] = values_array + i * n;
  }

  char c;
  int ret = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (scanf("%d%c", &pointer_array[i][j], &c) == 2 && (c == '\n' || c == ' ')) {
        ret++;
      } else {
        ret = 0;
        break;
      }
    }
  }

  if (ret != 0) {
    output_dynam(pointer_array, m, n);
  }

  free(values_array);
  free(pointer_array);
  return ret;
}

int static_matrix(int matrix[MMAX][NMAX], int m, int n) {
  int ret = 0;
  char c;

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (scanf("%d%c", &matrix[i][j], &c) == 2 && (c == '\n' || c == ' ')) {
        ret++;
      } else {
        ret = 0;
        break;
      }
    }
  }
  if (ret != 0) {
    output_stat(matrix, m, n);
  }

  return ret;
}

int input_size(int *p_size_m, int *p_size_n) {
  int ret = 0;
  char c;

  if (scanf("%d%c", p_size_m, &c) == 2 && (c == '\n' || c == ' ') && NMAX >= *p_size_m) {
    ret++;
  }

  if (ret > 0 && scanf("%d%c", p_size_n, &c) == 2 && (c == '\n' || c == ' ') && MMAX >= *p_size_n) {
    ret++;
  } else {
    ret = 0;
  }

  return ret;
}

int input_type(int *p_type) {
  int ret = 0;
  char c;

  if (scanf("%d%c", p_type, &c) == 2 && c == '\n' && 0 < *p_type && *p_type < 5) {
    ret++;
  }

  return ret;
}

void output_stat(int arr[NMAX][MMAX], int m, int n) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; ++j) {
      if (j < n - 1) {
        printf("%d ", arr[i][j]);
      } else {
        printf("%d", arr[i][j]);
      }
    }
    if (i < m - 1) {
      printf("\n");
    }
  }
}

void output_dynam(int **arr, int m, int n) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; ++j) {
      if (j < n - 1) {
        printf("%d ", arr[i][j]);
      } else {
        printf("%d", arr[i][j]);
      }
    }
    if (i < m - 1) {
      printf("\n");
    }
  }
}
