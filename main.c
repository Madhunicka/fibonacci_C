#include <stdio.h>

//recursive approach

int fibonacci_memoization(int n, int memo[]) {
    if (n <= 1)
        return n;
    
    if (memo[n] != -1)
        return memo[n];
    
    memo[n] = fibonacci_memoization(n - 1, memo) + fibonacci_memoization(n - 2, memo);
    return memo[n];
}


int fibonacci_bottom_up(int n) {
    if (n <= 1)
        return n;
    
    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    
    for (int i = 2; i <= n; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    
    return fib[n];
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    

    int memo[n + 1];
    for (int i = 0; i <= n; i++)
        memo[i] = -1;
    
    int fib_memo = fibonacci_memoization(n, memo);
    printf("Fibonacci number at position %d using memoization: %d\n", n, fib_memo);
  
    int fib_bottom_up = fibonacci_bottom_up(n);
    printf("Fibonacci number at position %d using bottom-up DP: %d\n", n, fib_bottom_up);
    
    return 0;
}
