#include <stdio.h>
#include <math.h>

long long int DC_DUMB_MULTIPLICATION(long long int a, long long int b) {
    if (a < 10 || b < 10) {
        return a * b;
    } else {
        int n = fmax(log10(a) + 1, log10(b) + 1);
        long long int power = pow(10, n / 2);

        long long int a1 = a / power;
        long long int a0 = a % power;
        long long int b1 = b / power;
        long long int b0 = b % power;

        long long int c2 = DC_DUMB_MULTIPLICATION(a1, b1);
        long long int c0 = DC_DUMB_MULTIPLICATION(a0, b0);
        long long int x = DC_DUMB_MULTIPLICATION(a1, b0);
        long long int y = DC_DUMB_MULTIPLICATION(a0, b1);
        long long int c1 = x + y;

        return c2 * pow(10, n) + c1 * power + c0;
    }
}

int main() {
    long long int num1, num2;

    printf("Enter the first number: ");
    scanf("%lld", &num1);

    printf("Enter the second number: ");
    scanf("%lld", &num2);

    long long int result = DC_DUMB_MULTIPLICATION(num1, num2);

    printf("Product: %lld\n", result);

    return 0;
}

output:
Enter the first number: 12345 
Enter the second number: 12345   
Product: 14482649025

TIME COMPLEXITY:
T(n) = O(n^2 * log(n))
