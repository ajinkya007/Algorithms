/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 8, 2014, 3:56 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
struct node {
    int data;
    struct node *right, *left;
};
void insert (struct node **root,int val){
    if(*root==NULL){
        struct node *newnode;
        newnode =(struct node *)malloc (sizeof(struct node));
        newnode->data=val;
        newnode->right=NULL;
        newnode->left=NULL;
        *root=newnode;
    }
    else {
        if((*root)->data > val)
            insert(&(*root)->left,val);
        else if((*root)->data <val)
            insert(&(*root)->right,val);
        else printf("Duplicate Element");
        
    }
}
void inorder(struct node *root){
    if(root==NULL)
        return;
    else {
        inorder(root->left);
        printf("%d \n",root->data);
        inorder(root->right);
    }
}
void preorder(struct node *root){
    if (root==NULL)
        return;
    else {
        printf("%d\t" , root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder (struct node * root){
    if (root ==NULL)
        return;
    else {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}
int max (struct node *root){
    while (root->right!=NULL)
        root =root->right;
    return root->data;
}
int min (struct node *root){
    while (root->left!=NULL)
        root = root->left;
    return root->data;
}
int maxRecur(struct node *root){
    if (root ->right == NULL)
        return root->data;
    else maxRecur(root->right);
}
int search (struct node *root ,int val){
    if (root == NULL)
        return 0;
    else if (root->data > val)
        return search(root->left,val);
    else if (root->data < val)
        return search(root->right,val);
    return 1;
}
int numberNodes(struct node *root){
    if (root == NULL)
        return 0;
    else return (1 + numberNodes(root->left) + numberNodes(root->right));
}
int height (struct node *root){
    if (root == NULL || root->left == NULL && root->right == NULL)
        return 0;
    else {
        int x = height(root->left);
        int y = height(root->right);
        return x>y?x+1:y+1;
    }
}


/*
 * for deleting a node there are 5 possibilities.
 * 1.Node has no children.
 * set the parent to null and free the memory
 * 2.node to be deleted has a right subtree.
 * attach the right subtree to the parent and free its memory.
 * 3.Node to be deleted has a left subtree.
 * attach the left subtree to the parent and free its memory.
 * 4.the node to be deleted has both the subtrees
 * can be done in two ways.
 *  a.find largest node in the deleted nodes left subtree and move its data to replace the deleted nodes data.
 *  b.find smallest node on the deleted nodes right subtree and move its data to replace the deleted nodes data.
 * 
 * 5.the node to be deleted is linked with the header.
 * find the non empty subtree and place it in the header node.
 */
void delete (struct node **root ,int val ){
    struct node *temp,*prev,*succ;
    temp=*root;
    if (*root==NULL)
        printf("Binary Tree is Empty");
    else {
        //Search the value 
        while (temp->data !=NULL && temp!=NULL){
            prev = temp;
            if(temp->data > val)
                temp=temp->left;
            else temp=temp->right;
        }
        //4th possibility
        if(temp->left!=NULL && temp->right!=NULL){
            succ=temp->right;
            while (succ->left!=NULL){
                prev=succ;
                succ= succ->left;
            }
            temp->data =succ->data;
            temp=succ;
        }
        //3rd possibility
        if(temp->left!=NULL && temp ->right ==NULL){
            if (prev->left==temp)
                prev->left=temp->left;
            else prev->right =temp->left;
        }
        //2nd Possibility 
        if(temp->left==NULL && temp->right !=NULL){
            if(prev->left==temp)
                prev->left=temp->left;
            else prev->right=temp->left;
        }
        //1st possibility 
        if(temp->left==NULL && temp ->right ==NULL){
            if(prev->left==temp)
                prev->left=NULL;
            else prev->right=NULL;
        }
        //5th possibility
        if(temp==*root){
            if(temp->left!=NULL)
                *root = temp->left;
            else *root=temp->right;
            
        }
        
    }
    free(temp);
}
int main(int argc, char** argv) {
    struct node *root=NULL;
    insert(&root,2);
    insert(&root,3);
    insert(&root,4);
    insert(&root,1);
    insert(&root,26);
    insert(&root,22);
    inorder(root);
    preorder(root);
    postorder(root);
    int c= search(root,1);
    printf("\n%d",c);
    return (EXIT_SUCCESS);
}

