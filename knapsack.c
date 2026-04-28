#include <stdio.h>

struct item {
    int value, weight;
};

void sort(struct item a[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if ((float)a[i].value / a[i].weight < (float)a[j].value / a[j].weight) {
                struct item t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
}

int main() {
    int n, W;
    printf("Enter no. of items: ");
    scanf("%d", &n);

    struct item a[n];
    printf("Enter value & weight:\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d", &a[i].value, &a[i].weight);

    printf("Enter capacity: ");
    scanf("%d", &W);

    sort(a, n);

    float maxvalue = 0.0;
    for (int i = 0; i < n && W > 0; i++) {
        if (a[i].weight <= W) {
            maxvalue += a[i].value;
            W -= a[i].weight;
        } else {
            maxvalue += a[i].value * ((float)W / a[i].weight);
            break;
        }
    }

    printf("Maximum value = %.2f\n", maxvalue);
    return 0;
}
