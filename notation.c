#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int get_number(const char *a, double *buffer_p, int sp, int id);
int is_digit(char c)
{
    return c >= '0' && c <= '9';
}

int clc_binary(char * action, int a, int b) {
    action(a, b);
}


double calculate(char *a, double x)
{
    double buffer_p[300];
    int sp = 0;
    int id = 0;

    while (a[id] != '\0')
    {
        if (is_digit(a[id]))
        {
            int count = get_number(a, buffer_p, sp, id);
            id += count;
            sp++;
        }
        else
        {
            switch (a[id])
            {
            case ' ':
                break;
            //. Бинарные
            case '+':
                buffer_p[sp - 2] = buffer_p[sp - 2] + buffer_p[sp - 1];
                sp--;
                break;
            case '-':
                buffer_p[sp - 2] = buffer_p[sp - 2] - buffer_p[sp - 1];
                sp--;
                break;
            case '*':
                buffer_p[sp - 2] = buffer_p[sp - 2] * buffer_p[sp - 1];
                sp--;
                break;
            case '/':
                buffer_p[sp - 2] = buffer_p[sp - 2] / buffer_p[sp - 1];
                sp--;
                break;
                //.  Унарные
            case 's':
                buffer_p[sp - 1] = sin(buffer_p[sp - 1]);
                break;
            case 'c':
                buffer_p[sp - 1] = cos(buffer_p[sp - 1]);
                break;
            case 't':
                buffer_p[sp - 1] = tan(buffer_p[sp - 1]);
                break;
            case 'g':
                buffer_p[sp - 1] = 1.0 / tan(buffer_p[sp - 1]);
                break;
            case 'q':
                buffer_p[sp - 1] = sqrt(buffer_p[sp - 1]);
                break;
            case 'l':
                buffer_p[sp - 1] = log(buffer_p[sp - 1]);
                break;
            case 'x':
                buffer_p[sp] = x;
                sp++;
                break;
            default:
                printf("The operator %c is unkown", a[id]);
            }
        }
        id++;
    }
    return buffer_p[sp - 1];
}

int get_number(const char *a, double *buffer_p, int sp, int id)
{=
    char buf[10];
    int count = 0;
    while (a[id + count] != ' ')
    {
        buf[count] = a[id + count];
        count++;
    }
    buf[count + 1] = '\0';
    buffer_p[sp] = atof(buf);
    return count;
}

int main()
{
    char a[100];
    a[0] = 'x';
    a[1] = ' ';
    a[2] = '2';
    a[3] = '2';
    a[4] = '.';
    a[5] = '2';
    a[6] = ' ';
    a[7] = '*';
    a[8] = '\0';
    double res = calculate(a, 3.0);
    printf("%f", res);
}
