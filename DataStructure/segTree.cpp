#include <bits/stdc++.h>
using namespace std;

typedef struct Node{
    int value;
    Node* lc;
    Node* rc;
}Node;

Node* root;
const int MAXN = 500000;
int num[MAXN + 10];

void buildTree(Node* &T, int l, int r) {
    T = new Node;
    if (l == r) {
        T -> value = num[l];
        return;
    }
    int mid = (l + r) / 2;
    buildTree(T -> lc, l, mid);
    buildTree(T -> rc, mid + 1, r);
    T -> value = max(T -> lc -> value, T -> rc -> value);
}

int query(Node* T, int ql, int qr, int l, int r) {
    if (ql <= l && r <= qr) {   //at the location we want
        return T -> value;
    }
    int mid = (l + r) / 2;
    if (qr <= mid) {            //all we want at the left child
        return query(T -> lc, ql, qr, l, mid);
    }             
    if (ql > mid) {             // all we want at the right child
        return query(T -> rc, ql, qr, mid + 1, r);
    }
    return max(query(T -> lc, ql, mid, l, mid), query(T -> rc, mid + 1, qr, mid + 1, r));
}

void update(Node* T, int l, int r, int index, int val) {
    if (l == r) {
        T -> value = val;
        return;
    }
    int mid = (l + r) / 2;
    if (index <= mid) {
        update(T -> lc, l, mid, index, val);
    } else {
        update(T -> rc, mid + 1, r, index, val);
    }
    T -> value = max(T -> lc -> value, T -> rc -> value);
}

int main() {
    //query(root, a, b, 0, N - 1);
}

/*
typedef struct node{
  int val = 0;
  node *l = nullptr;
  node *r = nullptr;
  node(int num) {
    val = num;
  }
  void pull(void) {
    if (l)
      val = l -> val;
    if (r)
      val = max(val, r -> val);
  }
}node;

node* build(int l, int r, vector<int> &vec, node* &root) {
  if (l == r)
    return new node(vec[l]);
  root = new node(0);
  int mid = (l + r) / 2;
  root -> l = build(l, mid, vec, root -> l);
  root -> r = build(mid + 1, r, vec, root -> r);
  root -> pull();
}

int query(int ql, int qr, int l, int r, node* root) {
  if (ql <= l && qr >= r) 
    return root -> val;
  int mid = (l + r) / 2;
  if (ql > mid)
    return query(ql, qr, mid + 1, r, root -> r);
  if (qr <= mid)
    return query(ql, qr, l, mid, root -> l);
  return max(query(ql, mid, l, mid, root -> l), query(mid + 1, qr, mid + 1, r, root -> r));
}
*/