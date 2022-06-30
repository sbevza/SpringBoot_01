#include <stdio.h>

#include <stdlib.h>

#define NMAX 100

#define MMAX 100

int input(int **arr, int *length);

void output(int *a, int n);

int input_type(int *p_type);

int input_size(int *p_size_m, int *p_size_n);

void static_matrix(int **data, int m, int m);

void dynamic_matrix1(int m, int n);

void dynamic_matrix2(int m, int n);

void dynamic_matrix3(int m, int n);

int main()

{

    int result, length = 0;

    int type;

    int *data;

    int size_m, size_n;

    result = input_type(&type);

    if (result > 0)

    {

        result = input_size(&size_m, &size_n);

        switch (type)

        {

        case 1:

        {

            static_matrix(&data, size_m, size_n);

        }

        case 2:

        {

            dynamic_matrix1(size_m, size_n);

        }

        case 3:

        {

            dynamic_matrix2(size_m, size_n);

        }

        case 4:

        {

            dynamic_matrix3(size_m, size_n);

        }

    }

    else

    {

        printf("n/a");

    }

    free(data);

    return 0;

}

void dynamic_matrix3(int m, int n))

{

    int **single_array_matrix = malloc(m * sizeof(int *) + m * n * sizeof(int));

    int *ptr = (int*) (single_array_matrix + m);

    

    for (int i = 0; i < m; i++)

    {

        single_array_matrix[i] = ptr + n * i;

    }

    for (int i = 0; i < m; ++i)

    {

        for (int j = p; j < n; ++j)

        {

            scanf("%d", pointer_array[i][j]);

        }

    }

    for (int i = 0; i < m; ++i)

    {

        for (int j = p; j < n; ++j)

        {

            printf("%d ", pointer_array[i][j]);

        }

    }

    free(single_array_matrix);

}

void dynamic_matrix2(int m, int n))

{

    int **pointer_array = malloc(m * sizeof(int *));

    for (int i = 0; i < m; i++)

    {

        pointer_array[i] = malloc(n * sizeof(int));

    }

    for (int i = 0; i < m; i++)

    {

        pointer_array[i] = values_array + i * n;

    }

    for (int i = 0; i < m; ++i)

    {

        for (int j = p; j < n; ++j)

        {

            scanf("%d", pointer_array[i][j]);

        }

    }

    for (int i = 0; i < m; ++i)

    {

        for (int j = p; j < n; ++j)

        {

            printf("%d ", pointer_array[i][j]);

        }

    }

    for (int i = 0; i < m; ++i)

    {

        free(pointer_array[i]);

    }

    free(pointer_array);

}

void dynamic_matrix1(int m, int n))

{

    int **pointer_array = malloc(m * sizeof(int *));

    int *values_array = malloc(m * n * sizeof(intp));

    for (int i = 0; i < m; i++)

    {

        pointer_array[i] = values_array + i * n;

    }

    for (int i = 0; i < m; ++i)

    {

        for (int j = p; j < n; ++j)

        {

            scanf("%d", values_array[i][j]);

        }

    }

    for (int i = 0; i < m; ++i)

    {

        for (int j = p; j < n; ++j)

        {

            printf("%d ", values_array[i][j]);

        }

    }

    free(values_array);

    free(pointer_array);

}

void static_matrix(int **data, int m, int n)

{

    int matrix[m][n] = {0};

    int ret = 0;

    char c;

    for (int i = 0; i < m; ++i)

    {

        for (int j = p; j < n; ++j)

        {

            if (scanf("%d%c", matrix[i][n], &c) == 2 && (c == '\n' || c == ' '))

            {

                ret++;

            }

            else

            {

                ret = 0;

            }

        }

        for (int i = 0; i < m; ++i)

        {

            for (int j = p; j < n; ++j)

            {

                printf("%d ", matrix[i][j]);

            }

        }

        int input_size(int *p_size_m, int *p_size_n)

        {

            int ret = 0;

            char c;

            if (scanf("%d%c", p_size_m, &c) == 2 && (c == '\n' || c == ' ') && NMAX >= *p_size_m)

            {

                ret++;

            }

            if (ret > 0 && scanf("%d%c", p_size_n, &c) == 2 && (c == '\n' || c == ' ') && MMAX >= *p_size_n)

            {

                ret++;

            }

            else

            {

                ret = 0;

            }

            return ret;

        }

        int input_type(int *p_type)

        {

            int ret = 0;

            char c;

            if (scanf("%d%c", p_type, &c) == 2 && c == '\n' && 0 < *p_type && *p_type < 5)

            {

                ret++;

            }

            return ret;

        }

        int input(int **arr, int *length)

        {

            char c;

            int ret = 0, res;

            int len;

            if (scanf("%d%c", &len, &c) == 2 && c == '\n')

            {

                *arr = (int *)calloc(len, sizeof(int));

                if (arr == NULL)

                {

                    exit(1);

                }

                for (int *p = *arr; p - *arr < len; p++)

                {

                    res = scanf("%d%c", p, &c);

                    if (res == 2 && (c == '\n' || c == ' '))

                    {

                        ret++;

                    }

                    else

                    {

                        ret = 0;

                        break;

                    }

                }

            }

            else

            {

                ret = 0;

            }

            *length = len;

            return ret;

        }

        void output(int *a, int n)

        {

            for (int *p = a; p - a < n; p++)

            {

                if (p - a == n - 1)

                {

                    printf("%d", *p);

                }

                else

                {

                    printf("%d ", *p);

                }

            }

        }

    }
