#include <iostream>
int main()
{
    double x[] = {0.101, 0.106, 0.111, 0.116, 0.121, 0.126, 0.131, 0.136, 0.141, 0.146, 0.151};
    double y[] = {1.26, 1.28, 1.29, 1.31, 1.32, 1.34, 1.35, 1.37, 1.38, 1.40, 1.42};
    double xtest[] = {0.1074, 0.1485, 0.1006, 0.1560};
    const int N = 11, M = 4;
    printf("x\t");
    for (int k = 0; k < N; k++)
    {
        printf("%.3f\t", x[k]);
    }
    printf("\ny\t");
    for (int k = 0; k < N; k++)
    {
        printf("%.3f\t", y[k]);
    }
    printf("\n==================\n");
    double a[N], b[N];
    for (int k = 0; k < N; k++)
    {
        a[k] = y[k];
        b[k] = y[N-k-1];
    }
    for (int k = 1; k < 4; k++)
    {
        for (int i = N-1; i >= k; i--)
        {
            a[i] -= a[i-1];
            b[i] = b[i-1] - b[i];
        }
    }
    printf("x\t");
    for (int k = 0; k < M; k++)
    {
        printf("%.4f\t", xtest[k]);
    }
    printf("\ny\t");
    for (int i = 0; i < M; i++)
    {
        double t, sum = 0, coef = 1;
        if (std::abs(xtest[i] - x[0]) < std::abs(xtest[i] - x[N-1]))
        {  
            t = (xtest[i] - x[0]) / (x[1] - x[0]);
            for (int j = 0; j < 4; j++)
            {
                sum += coef * a[j];
                coef *= (t - j) / (j + 1);
            }
        } else {
            t = (xtest[i] - x[N-1]) / (x[1] - x[0]);
            for (int j = 0; j < 4; j++)
            {
                sum += coef * b[j];
                coef *= (t + j) / (j + 1);
            }
        }
        printf("%.4f\t", sum);
    }
    printf("\n");
    return 0;
}