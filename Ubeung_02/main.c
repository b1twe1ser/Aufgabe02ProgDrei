#include <stdio.h>
//#include <limits.h>
double PI = 3.14159;

// -----------------------
// AUFGABE 1
// -----------------------

// 1. Circle
double circleSurface(double radius) {
    return (radius * radius) * PI;
}
double sphereVolume(double radius) {
    return 4 / 3 * PI * (radius * radius * radius);
}

// 2. Square
double squareSurface(double width, double length) {
    return width * length;
}
double cubeVolume(double width, double height, double length) {
    return width * height * length;
}

// 3. Rectangle
double rectangleSurface(double width, double height) {
    return width * height;
}
double cubiodVolume(double width, double height, double length) {
    return width * height * length;
}

// 4. Triangle
double triangleSurface(double width, double height) {
    return (width * height) / 2;
}
double pyramidVolume(double width, double height, double length) {
    return (width * height * length) / 3;
}

// ------------------
// AUFGABE 2
// -----------------

// messing with floats
void floatingMistakes() {
    float a = 1.0;
    float b = 1e-6;
    float sum = 0.0;

    for (int i = 0; i < 1000000; i++) {
        sum += b;
    }

    printf("Ergebnis: %f\n", a - sum);
}

// ---------------------
// AUFGABE 3
// ---------------------

/*
 * safeAdd:
        add edi, esi
        mov eax, -1
        cmovno eax, edi
        ret

        only four instructions!
 */
int safeAdd(int a, int b) {
    int result;
    if (!__builtin_add_overflow(a, b, &result)) {
        return result;
    } else {
        return -1;
    }
}

/*
 * safeAddNaive:
        cmp     edi, esi
        lea     eax, [rdi+rsi]
        cmovg   edi, esi
        cmp     eax, edi
        jl      .L4
        ret
.L4:
        mov     eax, -1
        ret
 */
//int addSafeNaive(int a, int b) {
//    int result = a + b;
//
//    if (result < a && result < b) {
//        return -1;
//    } else {
//        return result;
//    }
//}

int main() {
    printf("%d\n", safeAdd(2, 2));
    return 0;
}