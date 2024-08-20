#include <stdio.h>
#include <time.h>
#include <emscripten.h>
#include <emscripten/vector.h>

#define VECTOR_SIZE 1000000

// 普通版本的向量加法
void vector_add(float* a, float* b, float* result, int size) {
    for (int i = 0; i < size; i++) {
        result[i] = a[i] + b[i];
    }
}

// SIMD版本的向量加法
void vector_add_simd(float* a, float* b, float* result, int size) {
    for (int i = 0; i < size; i += 4) {
        emscripten_float32x4_t va = emscripten_float32x4_load(a + i);
        emscripten_float32x4_t vb = emscripten_float32x4_load(b + i);
        emscripten_float32x4_t vr = emscripten_float32x4_add(va, vb);
        emscripten_float32x4_store(result + i, vr);
    }
}

// 测量函数执行时间
double measure_time(void (*func)(float*, float*, float*, int), float* a, float* b, float* result, int size) {
    clock_t start = clock();
    func(a, b, result, size);
    clock_t end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

int main() {
    float* a = (float*)malloc(VECTOR_SIZE * sizeof(float));
    float* b = (float*)malloc(VECTOR_SIZE * sizeof(float));
    float* result = (float*)malloc(VECTOR_SIZE * sizeof(float));

    // 初始化向量
    for (int i = 0; i < VECTOR_SIZE; i++) {
        a[i] = (float)i;
        b[i] = (float)(VECTOR_SIZE - i);
    }

    // 测试普通版本
    double time_normal = measure_time(vector_add, a, b, result, VECTOR_SIZE);
    printf("普通版本耗时: %f 秒\n", time_normal);

    // 测试SIMD版本
    double time_simd = measure_time(vector_add_simd, a, b, result, VECTOR_SIZE);
    printf("SIMD版本耗时: %f 秒\n", time_simd);

    // 计算加速比
    double speedup = time_normal / time_simd;
    printf("SIMD加速比: %.2f\n", speedup);

    free(a);
    free(b);
    free(result);

    return 0;
}