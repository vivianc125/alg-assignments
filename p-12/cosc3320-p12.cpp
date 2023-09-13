#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

vector<int> nums;
int numsSize = 0;
int count = 0;

int parent(int i){
  return (i - 1) / 2;
}

void checkNums(int i){
  while (i > 0 && nums[parent(i)] > nums[i]){
    swap(nums[parent(i)],nums[i]);
    i = parent(i);
  }
}

bool checkDivisible(vector<int>& nums, int start, int k){
  if (numsSize%start != 0){
    return false;
  }
    if (start < numsSize){
      for (int i = start; i < k - 1; i++){
        if (nums[i + 1] != nums[i] + 1){
          return false;
        }
      }
      if ((start +k) < numsSize){
        checkDivisible(nums, start + k, k + k);
      }
    }
  return true;
}

int main() {
  string in;
  int temp, k, div;

  getline(cin,in);
  cin >> k;

  stringstream ss(in);

  while (ss >> temp){
    numsSize++;
    nums.push_back(temp);
    checkNums(numsSize - 1);
  }
  if (numsSize % k == 0){
    if(checkDivisible(nums,0,k)){
      cout << "true";
    }
    else{
      cout << "false";
    }
  }
  else{
    cout << "false";
  }
}