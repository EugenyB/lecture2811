#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

double f(double x) {
    return pow(abs(x), 1.0/7.0);
}

int nMax(double arr[], int size) {
    int result = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] > arr[result]) {
            result = i;
        }
    }
    return result;
}

int nMin(double arr[], int size) {
    int result = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] < arr[result]) {
            result = i;
        }
    }
    return result;
}

void tabulation(double start, double finish, double h) {
    int n = (int)round((finish-start)/h+1);
    double X[n], Y[n];
    for (int i = 0; i < n; i++) {
        float x = start + i * h;
        float y = f(x);
        printf("%5.16lf %8.16lf\n", x, y);
        X[i] = x;
        Y[i] = y;
    }
    printf("-----------------------\n");
    int nMaxElementa = nMax(Y, n);
    printf("xMax = %4.2lf yMax = %5.3lf\n", X[nMaxElementa], Y[nMaxElementa]);
    int nMinElementa = nMin(Y, n);
    printf("xMin = %4.2lf yMin = %5.3lf\n", X[nMinElementa], Y[nMinElementa]);
    char str[200];
    sprintf(str, "xMin = %4.2lf yMin = %5.3lf", X[nMinElementa], Y[nMinElementa]);
    int len = strlen(str);
    printf("Длина = %d\n", len);
}

int main() {
    double start, finish, h;
    scanf("%lf %lf %lf", &start, &finish, &h);
    printf("\n");
    printf("start = %10.2lf\nfinish = %4.2lf\nh = %3.1lf\n", start, finish, h);
//    int k = round(h);
//    printf("%d\n", k);
    tabulation(start, finish, h);
    return 0;
}