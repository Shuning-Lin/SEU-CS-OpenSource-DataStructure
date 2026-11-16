#include <cstdio>

long long recursion(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return 2 * recursion(n / 2) + n;
}

int main() {
    int m;
    if (std::scanf("%d", &m) != 1) {
        return 0;
    }
    for (int i = 0; i < m; ++i) {
        int n;
        if (std::scanf("%d", &n) != 1) {
            return 0;
        }
        std::printf("%lld\n", recursion(n));
    }
    return 0;
}
