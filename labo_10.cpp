#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <vector>
#include <math.h>

using namespace std;

struct node{
    int key;
    struct node *left, *right;
};

struct node *newNode(int item){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node *root){
    vector <int> vec1;
    if (root != NULL){
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

void preorder(struct node *root){
    if (root != NULL){
        printf("%d \n", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}


struct node* insert(struct node* node, int key){
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}

void meterEnVec(struct node *root, vector<int> &vec1){
    if (root != NULL){
        meterEnVec(root->left, vec1);
        vec1.push_back(root->key);
        meterEnVec(root->right, vec1);
    }
}
struct node* balancear(vector<int> &vec1, int inicio, int final){
    if(inicio > final){
        return NULL;
    }
    else{
        int mid = (final+inicio)/2;
        struct node* root = newNode(vec1.at(mid));
        root->left = balancear(vec1, inicio, mid-1);
        root->right = balancear(vec1, mid+1, final);
        return root;
    }
}
int main(){
    struct node *root = NULL;
    root = insert(root, 10);
    insert(root, 3);
    insert(root, 6);
    insert(root, 7);
    insert(root, 8);
    insert(root, 9);
    insert(root, 12);
    insert(root, 15);
    vector <int> vec1;
    meterEnVec(root, vec1);
    int tamanio = vec1.size();
    int ini = 0;
    int fin = tamanio-1;
    inorder(balancear(vec1, ini, fin));
    return 0;
}
