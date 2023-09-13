#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Node{
public:
    Node* left;
    Node* right;
    int val;
    Node(int val): val(val), left(nullptr), right(nullptr){}
};

Node* insertBT(Node* root, int val){
    if (!root) {
        return new Node(val);
    }
    
    if (val < root->val){
        root->left = insertBT(root->left, val);
    }
    else if (val > root->val){
        root->right = insertBT(root->right, val);
    }

    return root;
}

int depth(Node* root, int n){
  if (!root || root->val == n)
    return 0;
  
  else if (root->val > n)
    return 1 + depth(root->left,n);
    return 1 + depth(root->right,n);
  
}

int findShortDis(Node* root, int n1, int n2){
  if (!root){
    return 0;
  }
  if (root->val > n1 && root->val > n2){
    return findShortDis(root->left, n1, n2);
  }
    if (root->val < n1 && root->val < n2){
    return findShortDis(root->right, n1, n2);
  }
    else{
      return depth(root, n1) + depth(root,n2);
  }
}

void printBTree(Node* root){
    if (!root){
        return;
    }
    printBTree(root->left);
    cout << root->val << " ";
    printBTree(root->right);
}

int main(){
  string in;
  int temp, n1, n2;
  Node* root = nullptr;

  getline(cin,in);
  stringstream ss(in);
  cin >> n1;
  cin >> n2;

  while (ss >> temp){
    root = insertBT(root,temp);
  }
  cout << findShortDis(root, n1, n2);
}