#include <iostream>

using namespace std;

struct Node{
    int val;
    Node *left, *right;
};

void add(Node* &root, int x){
    /*
        Hàm thêm một số vào cây
        Hàm này đã được viết đầy đủ và đảm bảo đúng
        Sinh viên không cần phải viết hàm này
    */
    if (root == NULL){
        root = new Node;
        root->val = x;
        root->left = root->right= NULL;
    } else {
        if (x < root->val) add(root->left, x);
        else if (x > root->val) add(root->right, x);
    }
}

int count = 0;
void coutunnalance(Node* t){
    if (t == NULL) return;
    if (t->right != NULL && t->left != NULL){
        if (t->right - t->left >= 2) count ++;    
    }
    if (t->right != NULL) coutunnalance(t->right);
    if (t->left != NULL) coutunnalance(t->left);
}

int unbalance(Node* t){
    coutunnalance(t);
    return count;
}


int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    Node *root = NULL;

    int x;
    while (cin >> x){
        add(root, x);
    }
    
    cout << "So node bi mat can bang la " << unbalance(root);
    return 0;
}
