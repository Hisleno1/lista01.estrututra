int f(int n) {
    int s = 0;
    for (int i = 0; i < n * n; i++) {
        s = s + i;
    }
}
int g(int n) {
    f(n / 2) * f(n / 2);
}
int main() {
    int d;
    scanf("%d", &d);
    g(d);
}
