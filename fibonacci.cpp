#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1 || n == 2) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
 	int i;
    printf("10 so dau tien cua day so Fibonacci: \n");
        for (i = 0; i < 10; i++) {
        printf("%d ", fibonacci(i));
    }
}