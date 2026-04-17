#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <cmath>

using namespace std;

// ====== kiểm tra số nguyên tố ======
bool isPrime(long long x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;

    for (long long i = 3; i <= sqrt(x); i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

// ====== biến dùng chung ======
vector<long long> primes;
mutex mtx;

// ====== hàm cho mỗi thread ======
void findPrimes(long long start, long long end) {
    vector<long long> local;

    for (long long i = start; i <= end; i++) {
        if (isPrime(i)) {
            local.push_back(i);
        }
    }

    // gộp vào vector chung
    lock_guard<mutex> lock(mtx);
    primes.insert(primes.end(), local.begin(), local.end());
}

int main() {
    long long a, b;
    int n;

    cout << "Nhap a, b, n: ";
    cin >> a >> b >> n;

    vector<thread> threads;

    long long range = (b - a + 1) / n;
    long long start = a;

    auto t1 = chrono::high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        long long end;

        if (i == n - 1) {
            end = b;
        } else {
            end = start + range - 1;
        }

        threads.emplace_back(findPrimes, start, end);
        start = end + 1;
    }

    // join
    for (auto& t : threads) {
        t.join();
    }

    auto t2 = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(t2 - t1);

    // ===== output =====
    cout << "So luong so nguyen to: " << primes.size() << endl;

    cout << "Thoi gian: " << duration.count() << " ms" << endl;

    return 0;
}