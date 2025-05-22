#include <stdio.h>
#include <stdlib.h>

// ���� Ʈ�� ��带 �����ϴ� ����ü
typedef struct TreeNode {
    int data;                      // ��忡 ������ ������
    struct TreeNode* left;        // ���� �ڽ� ��带 ����Ű�� ������
    struct TreeNode* right;       // ������ �ڽ� ��带 ����Ű�� ������
} TreeNode;

// ��带 �����ϰ� �ʱ�ȭ�ϴ� �Լ�
TreeNode* createNode(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node == NULL) {
        printf("�޸� �Ҵ� ����\n");
        exit(1);
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preorder(TreeNode* node) {
    if (node == NULL) return;

    printf("%d ", node->data);      // 1. ��Ʈ �湮
    preorder(node->left);           // 2. ���� ����Ʈ�� ��ȸ
    preorder(node->right);          // 3. ������ ����Ʈ�� ��ȸ
}

void inorder(TreeNode* node) {
    if (node == NULL) return;

    inorder(node->left);            // 1. ���� ����Ʈ�� ��ȸ
    printf("%d ", node->data);     // 2. ��Ʈ �湮
    inorder(node->right);          // 3. ������ ����Ʈ�� ��ȸ
}

void postorder(TreeNode* node) {
    if (node == NULL) return;

    postorder(node->left);         // 1. ���� ����Ʈ�� ��ȸ
    postorder(node->right);        // 2. ������ ����Ʈ�� ��ȸ
    printf("%d ", node->data);     // 3. ��Ʈ �湮
}

void freeTree(TreeNode* node) {
    if (node == NULL) return;

    freeTree(node->left);   // ���� ����Ʈ�� ���� ����
    freeTree(node->right);  // ������ ����Ʈ�� ����
    free(node);             // ���� ��� ����
}

int getHeight(TreeNode* node) {
    if (node == NULL) return -1;  // NULL �ڽ��� ���� ���� �� ���� -1

    int leftHeight = getHeight(node->left);   // ���� ����Ʈ���� ����
    int rightHeight = getHeight(node->right); // ������ ����Ʈ���� ����

    if (leftHeight > rightHeight) return leftHeight + 1;
    else return rightHeight + 1;
}

int countNodes(TreeNode* node) {
    if (node == NULL) return 0;

    return 1 + countNodes(node->left) + countNodes(node->right);
}

int countLeaves(TreeNode* node) {
    if (node == NULL) return 0;

    if (node->left == NULL && node->right == NULL)
        return 1;  // ���� ����� ���

    return countLeaves(node->left) + countLeaves(node->right);
}

int getSum(TreeNode* node) {
    if (node == NULL) return 0;
    return node->data + getSum(node->left) + getSum(node->right);
}

int getMax(TreeNode* node) {
    if (node == NULL) return -1;
    int max = node->data;
    int leftMax = getMax(node->left);
    int rightMax = getMax(node->right);
    if (leftMax > max) max = leftMax;
    if (rightMax > max) max = rightMax;
    return max;
}

void searchRange(TreeNode* node, int min, int max) {
    if (node == NULL) return;
    if (node->data >= min && node->data <= max) {
        printf("%d ", node->data);
    }
    if (node->data > min) {
        searchRange(node->left, min, max);
    }
    if (node->data < max) {
        searchRange(node->right, min, max);
    }
}



int main() {
    // Ʈ�� ����
    TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(15);
    root->right->right = createNode(25);

    // ��ȸ ���
    printf("���� ��ȸ: ");
    preorder(root);
    printf("\n");

    printf("���� ��ȸ: ");
    inorder(root);
    printf("\n");

    printf("���� ��ȸ: ");
    postorder(root);
    printf("\n");

    // �м� ���
    printf("Ʈ�� ����: %d\n", getHeight(root));
    printf("��ü ��� ��: %d\n", countNodes(root));
    printf("���� ��� ��: %d\n", countLeaves(root));

    printf("��� �� ����: %d\n", getSum(root));  // �Լ� �ۼ�
    printf("�ִ�: %d\n", getMax(root));       // �Լ� �ۼ�

    // ���� Ž��
    printf("���� 6 �̻� 20 ������ ���: ");
    searchRange(root, 6, 20);                 // �Լ� �ۼ�
    printf("\n");

    freeTree(root);
    return 0;
}