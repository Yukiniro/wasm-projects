/*
 * Copyright 2011 The Emscripten Authors.  All rights reserved.
 * Emscripten is available under two separate licenses, the MIT license and the
 * University of Illinois/NCSA Open Source License.  Both these licenses can be
 * found in the LICENSE file.
 */

#include <stdio.h>


// 实现斐波那契函数
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
#include <time.h>

// 计算斐波那契函数的耗时并打印
void print_fibonacci_time(int n) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    int result = fibonacci(n);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("计算斐波那契数列第 %d 个数的耗时: %f 秒\n", n, cpu_time_used);
    printf("结果: %d\n", result);
}

// 在主函数中调用斐波那契函数并打印结果
int main() {
    printf("hello, world!\n");
    
    int n = 42;
    // printf("斐波那契数列的第 %d 个数是: %d\n", n, fibonacci(n));
    print_fibonacci_time(n);
    
    return 0;
}
