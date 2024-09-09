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

// 빠른 입력 함수
int fast_input() {
    int n = 0;
    int c = getchar_unlocked();
    while (c < '0' || c > '9') c = getchar_unlocked();  // 숫자 입력 대기
    while (c >= '0' && c <= '9') {  // 숫자 범위일 때만 처리
        n = n * 10 + (c - '0');
        c = getchar_unlocked();
    }
    return n;
}

// 빠른 출력 함수
void fast_output(long long n) {
    char buffer[20];
    int index = 0;
    
    // 숫자를 문자열로 변환
    if (n == 0) {
        putchar_unlocked('0');
        putchar_unlocked('\n');
        return;
    }
    
    while (n > 0) {
        buffer[index++] = (n % 10) + '0';
        n /= 10;
    }
    
    // 역순으로 출력
    while (index > 0) {
        putchar_unlocked(buffer[--index]);
    }
    putchar_unlocked('\n');
}

int main() {
    int T, N;

    // 약수 합을 미리 계산
    precompute();

    // 입력 처리
    T = fast_input();

    // 각 테스트 케이스 처리
    for (int t = 0; t < T; t++) {
        N = fast_input();
        fast_output(g[N]);  // g(N) 값을 출력
    }

    return 0;
}
