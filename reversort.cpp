#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

int reversort(vi &L) {
    int cost = 0;
    
    for (int i = 0; i < L.size() - 1; i++) {
        auto x = min_element(L.begin() + i, L.end());
        
        reverse(L.begin() + i, x + 1);
        
        cost += distance(L.begin(), x) - i + 1;
    }
    
    return cost;
}

int main() {
    cout << "Enter the number of test cases: ";
    int T;
    cin >> T;
    
    for (int c = 1; c <= T; c++) {
        cout << "Enter the number of elements in the array for case #" << c << ": ";
        int N;
        cin >> N;
        
        vi L(N);
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < N; i++) {
            cin >> L[i];
        }
        
        int cost = reversort(L);
        cout << "Case #" << c << ": " << cost << endl;
    }
    
    return 0;
}
