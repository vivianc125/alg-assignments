#include <iostream>
#include <string>
using namespace std;

int dnc(int A[], int left, int right) {
    int diff;

    if (left >= right) {
        return 0;
    }

    int mid = left + (right - left) / 2;
    int lefty = dnc(A, left, mid);
    int righty = dnc(A, mid + 1, right);
  
    int minLeft = A[left];  
    for (int i = left; i <= mid; ++i) {
      
        minLeft = min(minLeft, A[i]);
    }
    int maxRight = A[mid+1];
    for (int i = mid + 1; i <= right; ++i) {
        maxRight = max(maxRight, A[i]);
    }

    diff = maxRight - minLeft;

    return max(max(lefty, righty), diff); 
}

int main() {
  int size, in;
  
  cin >> size;
  int A[size];
  
  for (int i = 0; i < size; i++){
    cin >> in;
    A[i] = in;
  }
  int final = dnc(A, 0, size-1);
  if (final < 0){
    cout << 0;
  }
  else{
  cout << final;
  }
}