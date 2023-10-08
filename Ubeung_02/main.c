#include <stdio.h>
#include <limits.h>
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
        cmovno eax, edi ; Conditional move if not overflow
        ret
 */
int safeAdd(int a, int b) {
    int res;
    if (!__builtin_add_overflow(a, b, &res)) {
        return res;
    }
    return -1;
}

/*
addSafeNaive:
    lea     eax, [rdi+rsi]   ; Calculate the sum of rdi and rsi and store it in eax
    test    edi, edi         ; Test if rdi (a) is greater than zero
    setg    cl               ; Set cl to 1 if rdi is greater than zero (cl is used as a temporary flag)
    test    esi, esi         ; Test if rsi (b) is greater than zero
    setg    dl               ; Set dl to 1 if rsi is greater than zero (dl is used as a temporary flag)
    test    cl, dl           ; Test if both cl and dl are set (i.e., both a and b are greater than zero)
    je      .L11             ; If not, jump to label .L11 (to handle overflow)
    test    eax, eax         ; Test if the sum in eax is negative
    js      .L9              ; If it's negative, jump to label .L9 (to handle overflow)

.L11:
    test    edi, esi         ; Test if both a and b have the same sign (both positive or both negative)
    jns     .L5              ; If they have the same sign, jump to label .L5 (to handle positive result)
    test    eax, eax         ; Test if the sum in eax is negative
    mov     edx, -1          ; Set edx to -1 (to represent the overflowed case)
    cmovg   eax, edx         ; Conditionally move edx into eax if the sum is greater than zero
    ret

.L9:
    mov     eax, -1          ; Set eax to -1 (to represent the overflowed case)

.L5:
    ret                       ; Return the result in eax

 */
int addSafeNaive(int a, int b) {
    int sum = a + b;
    if ((a > 0 && b > 0 && sum < 0) ||
        (a < 0 && b < 0 && sum > 0)) {
        return -1;
    }
    return sum;

}

int main() {
    printf("%d\n", safeAdd(2, 2));
    printf("%d\n", addSafeNaive(-590, 52));
    return 0;
}