//
// Created by Amos on 2020/03/21.
//
#include <iostream>
#include <cmath>

const int MAX_N = 7;

int n;
unsigned char sieve[(MAX_N + 7) / 8];

// k가 소수인지 확인
inline bool isPrime(int k) {
    // k를 8로 나누고, 8로 나눈 나머지에 해당하는 수가 1인지 확인한다.
    return sieve[k >> 3] & (1 << (k & 7));
}

// k가 소수가 아니라고 표시한다.
inline void setComposite(int k) {
    sieve[k >> 3] &= ~(1 << (k & 7));
}

void eratosthenes() {
    memset(sieve, 255, sizeof(sieve));
    setComposite(0);
    setComposite(1);

    int sqrtn = sqrt(n);
    for (int i = 2; i <= sqrtn; ++i) {
        // 이 수가 아직 지워지지 않았다면
        if (isPrime(i)) {
            // i의 배수들 j들에 대해 isPrime[i] = false로 둔다.
            // i * i 미만의 배수는 이미 지워졌으므로 신경쓰지 않는다.
            for (int j = i * i; j <= n; j += i) {
                setComposite(j);
            }
        }
    }
}


int main () {
    return 0;
}
