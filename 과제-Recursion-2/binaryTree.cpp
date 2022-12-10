#include <iostream>
#include <cstring>
using namespace std;
void insert(struct node **root,int data);
void inOrder(struct node *root);
void preOrder(struct node *root);
void postOrder(struct node *root);
int size(struct node *root);
int height(struct node *root);
int sumOfWeight(struct node *root);
int maxPathWeight(struct node *root);
void mirror(struct node **root);
void destruct(struct node **root);
void swap(int* a, int* b);

struct node
{
int data; // 노드에 저장되는 정수 데이터 
struct node* leftSubTree; // 왼쪽 서브트리
struct node* rightSubTree; // 오른쪽 서브트리
};
int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    while (numTestCases--)
    {
        int num, i;
        struct node* root = NULL;

        scanf("%d", &num);
        for (i = 0; i < num; i++)
        {
            int data;

            scanf("%d", &data);
            insert(&root, data);
        }
    printf("%d\n", size(root)); 
    printf("%d\n", height(root)-1); 
    printf("%d\n", sumOfWeight(root)); 
    printf("%d\n", maxPathWeight(root)); 
    mirror(&root);
    preOrder(root); printf("\n");
    inOrder(root); printf("\n");
    postOrder(root); printf("\n");
    destruct(&root); // BST의 모든 노드의 동적 메모리 해제 
    if (root == NULL)
        printf("0\n");
    else
        printf("1\n");
    }
    return 0; 
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *a = tmp; 
}

void insert(struct node **root, int data)
{
    if(*root==NULL){
        *root = new node;
        (*root)->data = data;
    }
    else{
        if ((*root)->data < data){
            insert(&(*root)->rightSubTree,data);
        }
        else
            insert(&(*root)->leftSubTree,data);
    }
}
void inOrder(struct node *root)
{
    if (root == NULL) return;
    else
    {
        inOrder(root->leftSubTree);
        printf("%d",root->data);
        cout << " ";
        inOrder(root->rightSubTree);
    }
}
void preOrder(struct node *root)
{
    if (root == NULL) return;
    else
    {
        printf("%d", root->data);
        cout << " ";
        preOrder(root->leftSubTree);
        preOrder(root->rightSubTree);
    }
}
void postOrder(struct node *root)
{
    if (root == NULL) return;
    else
    {
        postOrder(root->leftSubTree);
        postOrder(root->rightSubTree);
        printf("%d", root->data);
        cout << " ";
    }
}
int size(struct node *root)
{
    if(root==NULL) return 0;
    int result = 1;
    result += size((node*)root->leftSubTree)+size((node*)root->rightSubTree);
    return result;
    // int leftHeight, rightHeight;
    // leftHeight = height(root->leftSubTree);
    // rightHeight = height(root->rightSubTree);
    // return root->data + leftHeight +rightHeight;
}
int height(struct node *root)
{
    int height_val=0;
    if(root!=NULL) 
    {
        height_val = 1 + max(height(root->leftSubTree),height(root->rightSubTree));
    }
    return height_val;
}
int sumOfWeight(struct node *root)
{
    if(root==NULL) return 0;
    else return sumOfWeight(root->leftSubTree)+sumOfWeight(root->rightSubTree)+root->data;
}
int maxPathWeight(struct node *root)
{
    if(root==NULL) return 0;
    else{
        int leftWeight,rightWeight;
        leftWeight = maxPathWeight(root->leftSubTree);
        rightWeight = maxPathWeight(root->rightSubTree);
        return root->data + (leftWeight >= rightWeight ? leftWeight : rightWeight);
    }
}
void mirror(struct node **root)
{
    if(*root==NULL) return;
    else{
    struct node **tmp;
    mirror(&(*root)->leftSubTree);
    mirror(&(*root)->rightSubTree);
    swap((*root)->leftSubTree,(*root)->rightSubTree);
    }
}
void destruct(struct node **root)
{
    *root = NULL;
}
