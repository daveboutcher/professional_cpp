void foo() {
    int a[10][11];
    int (*b)[10][11];

    b = &a;
}
