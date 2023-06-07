#include <iostream>
using namespace std;

typedef struct Tree
{
    int data;
    Tree *left, *right;
} Tree;

int isEmpty(Tree *pohon)
{
    if (pohon == NULL)
        return 1;
    else
        return 0;
}

void preOrder(Tree *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Tree *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(Tree *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

Tree *findMin(Tree *root)
{
    if (root == NULL)
        return NULL;
    else if (root->left == NULL)
        return root;
    else
        return findMin(root->left);
}

void tambah(Tree **root, int databaru)
{
    if ((*root) == NULL)
    {
        Tree *baru = new Tree;
        baru->data = databaru;
        baru->left = NULL;
        baru->right = NULL;
        (*root) = baru;
    }
    else if (databaru < (*root)->data)
        tambah(&(*root)->left, databaru);
    else if (databaru > (*root)->data)
        tambah(&(*root)->right, databaru);
    else if (databaru == (*root)->data)
        printf("Data sudah ada!");
}

Tree *hapus(Tree *root, int value)
{
    if (root == NULL)
        return NULL;

    if (value < root->data)
        root->left = hapus(root->left, value);
    else if (value > root->data)
        root->right = hapus(root->right, value);
    else
    {
        if (root->left == NULL)
        {
            Tree *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Tree *temp = root->left;
            delete root;
            return temp;
        }

        // Case 2: 2 children
        Tree *minNode = findMin(root->right);
        root->data = minNode->data;
        root->right = hapus(root->right, minNode->data);
    }
    return root;
}


Tree *cari(Tree *root, int data)
{
    if (root == NULL)
        return NULL;
    else if (data < root->data)
        return cari(root->left, data);
    else if (data > root->data)
        return cari(root->right, data);
    else if (data == root->data)
        return root;
}

int count(Tree *root)
{
    if (root == NULL)
        return 0;
    return count(root->left) + count(root->right) + 1;
}

int height(Tree *root)
{
    if (root == NULL)
        return -1;
    int u = height(root->left), v = height(root->right);
    if (u > v)
        return u + 1;
    else
        return v + 1;
}

void printLeaf(Tree *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        printf("%d ", root->data);
    printLeaf(root->left);
    printLeaf(root->right);
}

int main()
{
    Tree *pohon = NULL;

    tambah(&pohon, 5);
    tambah(&pohon, 12);
    tambah(&pohon, 11);
    tambah(&pohon, 7);
    tambah(&pohon, 6);

    pohon = hapus(pohon, 6);
    cout << count(pohon) << endl;
    cout << height(pohon) << endl;

    printLeaf(pohon); cout << "\n";

    inOrder(pohon);
    cout << "\n";
    postOrder(pohon);
    cout << "\n";
    preOrder(pohon);

    return 0;
}
