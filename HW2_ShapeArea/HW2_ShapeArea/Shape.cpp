#include "Shape.h"

bool comp_area(Shape* s1, Shape* s2) {
    return (s1->area() < s2->area());
}

void sort(Shape** arr, int n, comp_shape cmp) {
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n - i - 1; ++j)
            if (!cmp(arr[j], arr[j + 1])) {
                Shape* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
    }
}
