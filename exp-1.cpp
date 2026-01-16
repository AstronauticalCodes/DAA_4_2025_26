#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

long long complexRec(int n) {
    long long ops = 0;
 
    if (n <= 2) {
        return 1;
    }

    int p = n;
    while (p > 0) {
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = i ^ p;
            ops++;
        }
        p >>= 1;
    }

    vector<int> small(n);
    for (int i = 0; i < n; i++) {
        small[i] = i * i;
        ops++;
    }

    if (n % 3 == 0) {
        reverse(small.begin(), small.end());
        ops += n;
    } else {
        reverse(small.begin(), small.end());
        ops += n;
    }

    ops += complexRec(n / 2);
    ops += complexRec(n / 2);
    ops += complexRec(n / 2);

    return ops;
}

int main() {
    cout << "Complexity Analysis of complexRec: " << endl;
    cout << endl;
    
    vector<int> testSizes = {8, 16, 32, 64, 128, 256, 512, 1024};
    
    cout << left << setw(10) << "n" 
         << setw(20) << "Operations" 
         << setw(20) << "Time (microsec)"
         << setw(20) << "n^1.585 (approx)" << endl;
    cout << string(70, '-') << endl;
    
    for (int n : testSizes) {
        auto start = high_resolution_clock::now();
        long long operations = complexRec(n);
        auto end = high_resolution_clock::now();
        
        auto duration = duration_cast<microseconds>(end - start);
        
        double theoretical = pow(n, log2(3));
        
        cout << left << setw(10) << n 
             << setw(20) << operations 
             << setw(20) << duration.count()
             << setw(20) << fixed << setprecision(2) << theoretical << endl;
    }
    
    cout << endl;
    cout << "Recurrence Relation: " << endl;
    cout << "T(n) = 3T(n/2) + O(n·log n)" << endl;
    cout << endl;
    cout << "Master's Theorem Solution: " << endl;
    cout << "a = 3, b = 2, f(n) = n·log(n)" << endl;
    cout << "log_b(a) = log_2(3) = " << log2(3) << endl;
    cout << "Case 1 applies: f(n) = O(n^(log_2(3) - epsilon))" << endl;
    cout << "Time Complexity: Theta(n^log_2(3)) = Theta(n^" << log2(3) << ")" << endl;
    
    return 0;
}