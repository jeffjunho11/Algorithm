#include <stdio.h>

#define MAX_N 1000000

long long f[MAX_N + 1];  // 각 수의 약수 합을 저장하는 배열
long long g[MAX_N + 1];  // g(N)을 저장하는 배열

void precompute() {
    // f(y) 값을 계산 (약수의 합을 구하는 과정)
    for (int i = 1; i <= MAX_N; i++) {
        for (int j = i; j <= MAX_N; j += i) {
            f[j] += i;  // j의 약수에 i를 더함
        }
    }

    // g(N) 값을 계산 (1부터 N까지 f(y) 합산)
    for (int i = 1; i <= MAX_N; i++) {
        g[i] = g[i - 1] + f[i];  // g(i)는 f(1)부터 f(i)까지의 합
    }
}

int main() {
    int T, N;

    // 약수 합을 미리 계산
    precompute();

    // 입력 처리
    scanf("%d", &T);

    // 각 테스트 케이스 처리
    for (int t = 0; t < T; t++) {
        scanf("%d", &N);
        printf("%lld\n", g[N]);  // g(N) 값을 출력
    }

    return 0;
}
