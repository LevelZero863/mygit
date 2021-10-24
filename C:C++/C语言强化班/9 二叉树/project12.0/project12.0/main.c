//
//  main.c
//  project12.0
//
//  Created by EthanLeslie on 2021/9/23.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct BiTree{
    int data;
    struct BiTree* lchild;
    struct BiTree* rchild;
}BiTree,*Tree;
void Insert(Tree root,int data);
void InitTree(Tree root);
void InOrder(Tree root);
void Delete(Tree root,int data);
void Search(Tree root,int data,Tree* ret);
void SearchFather(Tree root,int data,Tree* ret);
void MaxInTree(Tree root,Tree* ret);
int main(int argc, const char * argv[]) {
    // insert code here...
    Tree root = NULL;
    BiTree ROOT;
    root=&ROOT;
    //构造二叉树
    InitTree(root);
    //遍历二叉树
    printf("遍历二叉树结果如下：\n");
    InOrder(root);
    //插入节点
    printf("输入所要插入的数据：\n");
    int insert;
    scanf("%d",&insert);
    Insert(root, insert);
    printf("插入后的二叉树数据如下：\n");
    InOrder(root);
    //删除节点
    printf("输入所要删除的数据：\n");
    int del;
    scanf("%d",&del);
    Delete(root, del);
    printf("删除后的二叉树数据如下：\n");
    InOrder(root);
    return 0;
}
void InitTree(Tree root){
    printf("输入数据个数为：\n");
    int length;
    scanf("%d",&length);
    printf("输入的数据为：\n");
    int d;
    scanf("%d",&d);
    root->data=d;
    root->rchild=NULL;
    root->lchild=NULL;
    int i;
    for (i=0; i<length-1; i++) {
        scanf("%d",&d);
        Tree t = (Tree)malloc(sizeof(BiTree));
        t->data=d;
        t->rchild=NULL;
        t->lchild=NULL;
        Insert(root, d);
    }
}
void Insert(Tree root,int data){
    if(root==NULL)  return ;
    if(root->data>data){
        if(root->lchild==NULL){
            Tree tree1 = (Tree)malloc(sizeof(BiTree));
            tree1->data=data;
            tree1->lchild=NULL;
            tree1->rchild=NULL;
            root->lchild=tree1;
        }else{
            Insert(root->lchild,data);
        }
    }else{
        if(root->rchild==NULL){
            Tree tree2 = (Tree)malloc(sizeof(BiTree));
            tree2->data=data;
            tree2->lchild=NULL;
            tree2->rchild=NULL;
            root->rchild=tree2;
        }else{
            Insert(root->rchild,data);
        }
    }
    
}
void InOrder(Tree root){
    if(root!=NULL){
        InOrder(root->lchild);
        printf("%d ",root->data);
        InOrder(root->rchild);
    }
}
void Search(Tree root,int data,Tree* ret){
    if(root!=NULL){
        Search(root->lchild, data,ret);
        if (root->data==data) {
            (*ret)=root;
        }
        Search(root->rchild, data,ret);
    }
}
void SearchFather(Tree root,int data,Tree* ret){
    if(root->rchild!=NULL||root->lchild!=NULL){
        if (root->lchild!=NULL) {
            SearchFather(root->lchild, data,ret);
        }
        if(root->lchild!=NULL&&root->lchild->data==data){
            (*ret)=root;
        }
        if (root->rchild!=NULL&&root->rchild->data==data) {
            (*ret)=root;
        }
        if (root->rchild!=NULL) {
            SearchFather(root->rchild, data,ret);
        }
    }
}
void MaxInTree(Tree root,Tree *ret){
    Tree node=root;
    while (node->rchild!=NULL) {
        node=node->rchild;
    }
    (*ret)=node;
}
void Delete(Tree root,int data){
    Tree* Des=NULL;
    Tree des=NULL;
    Des=&des;
    Search(root,data,Des);
    
    Tree* Father=NULL;
    Tree father=NULL;
    Father=&father;
    if(des==NULL){
        printf("节点不存在！\n");
    }else{
        SearchFather(root, data, Father);
        //没有孩子节点
        if(des->rchild==NULL&&des->lchild==NULL){
            if(father==NULL){//删除节点为根节点
                root=NULL;
            }else{
                if(father->rchild!=NULL&&father->rchild->data==data){
                    free(father->rchild);
                    father->rchild=NULL;
                }else{
                    free(father->lchild);
                    father->lchild=NULL;
                }
            }
        }else if(des->rchild!=NULL&&des->lchild!=NULL){//有两个孩子节点
            Tree* Max=NULL;
            Tree max=NULL;
            Max=&max;
            MaxInTree(des->lchild,Max);
            Tree temp = (Tree)malloc(sizeof(BiTree));
            temp->data=max->data;
            temp->rchild=des->rchild;
            if(father->rchild!=NULL&&father->rchild->data==des->data){
                father->rchild=temp;
            }else{
                father->lchild=temp;
            }
            Delete(des, max->data);
            temp->lchild=des->lchild;
            free(des);
        }else{//只有一个孩子节点
            if(des->rchild!=NULL){
                if(father->rchild!=NULL&&father->rchild->data==data){
                    father->rchild=des->rchild;
                }else{
                    father->lchild=des->rchild;
                }
            }else{
                if(father->rchild!=NULL&&father->rchild->data==data){
                    father->rchild=des->lchild;
                }else{
                    father->lchild=des->lchild;
                }
            }
        }
    }
}
