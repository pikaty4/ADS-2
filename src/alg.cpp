// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
        if (n == 0) { return 1.; }
        if (n == 1) { return value; }
        double k = value;
        for (uint64_t i = 1; i < n; i++) {
                value *= k;
        }
        return value;
}

uint64_t fact(uint16_t n) {
        uint64_t a = 1;
        for (uint64_t i = 2; i <= n; i++) {
               a *= i;
        }
        return a;
}

double calcItem(double x, uint16_t n) {
        if (n == 0 || x == 0) return 0;
        return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
        double a = 1.;
        for (uint64_t i = 1; i <= count; i++) {
                a += pown(x, i) / fact(i);
        }
        return a;
}

double sinn(double x, uint16_t count) {
        double a = x;
        for (uint64_t i = 2; i <= count; i++) {
                a += pown(-1, i - 1) * (pown(x, i * 2 - 1) / fact(i * 2 - 1));
        }
        return a;
}

double cosn(double x, uint16_t count) {
        double a = 1;
        for (uint64_t i = 2; i <= count; i++) {
                 a += pown(-1, i - 1) * (pown(x, i * 2 - 2) / fact(i * 2 - 2));
        }
        return a;
}
