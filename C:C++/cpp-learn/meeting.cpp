#include<iostream>
#include<vector>

using namespace std;

typedef struct node {
    size_t data;
    struct node* lchild;
    struct node* rchild;
}Tree,*treeNode;

int main () {
    
    treeNode root;
    
    root->data = 1;
    root->lchild = NULL;
    //treeNode n;
    root->rchild = NULL;
    vector<treeNode> vec{root};

    int top = 0;
    int height = 0;
    int curLen = 1;
    int nextLen = 0;
    while (top!=vec.size()) {
        treeNode cur = vec[top];
        if (cur->lchild != NULL) {
            vec.push_back(cur->lchild);
            nextLen++;
        }
        if (cur->rchild != NULL) {
            vec.push_back(cur->rchild);
            nextLen++;
        }
        if (--curLen == 0) {
            height++;
            curLen = nextLen;
            nextLen = 0;
        }
        top++;
        
    }
    cout<<height<<endl;
    return 0;
}