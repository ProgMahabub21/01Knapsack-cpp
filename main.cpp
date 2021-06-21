#include <iostream>
using namespace std;
int max(int x, int y) {
   return (x > y) ? x : y;
}
int knapSack(int W, int wi[], int v[], int n) {
   int i, w;
   int B[n + 1][W + 1];
   for (i = 0; i <= n; i++) {
      for (w = 0; w <= W; w++) {
         if (i == 0 || w == 0)
         B[i][w] = 0;
         else if (wi[i - 1] <= w)
            B[i][w] = max(v[i - 1] + B[i - 1][w - wi[i - 1]], B[i - 1][w]);
         else
        B[i][w] = B[i - 1][w];
      }
   }
   return B[n][W];
}
int main() {
   cout << "Number of items in a Knapsack:";
   int n, W;
   cin >> n;
   int v[n], w[n];
   for (int i = 0; i < n; i++) {
      cout << "Value and weight for item respectively" << i << ":";
      cin >> v[i];
      cin >> w[i];
   }
   cout << "knapsack Weight : ";
   cin >> W;
   cout << knapSack(W, w, v, n);
   return 0;
}
