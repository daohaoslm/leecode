#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cmath>
#include<algorithm>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};
//�����ڵ�
TreeNode* createNode(int num) {
    //���ٽڵ�ռ�
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    //���Һ�������Ϊ0
    node->left = nullptr;
    node->right = nullptr;
    //���øýڵ��ֵ
    node->val = num;
    return node;
}

TreeNode* target;
TreeNode* dfs(TreeNode* root, TreeNode* temp) {
    if (root != nullptr) {
        temp = createNode(root->val);
        temp->right = dfs(root->left, temp->right);
        temp->left = dfs(root->right, temp->left);
        target = temp;
    }
    else {
        return nullptr;
    }
    return target;
}
TreeNode* invertTree(TreeNode* root) {
    
    if (root != nullptr) {
        dfs(root,nullptr);
    }
    return target;
}

//����������
TreeNode* createTree(int arr[],int length,int pos) {
    //�������Ϊ���򷵻�
    if (pos >= length) return nullptr;
    
    //�������ڵ�
    TreeNode* root = createNode(arr[0]);
    //��������
    TreeNode** queue = (TreeNode**)malloc(length * sizeof(TreeNode*));
    //�������ͷָ�룬βָ��
    int front = 0, rear = 1;
    //��һ��Ԫ�����
    queue[front] = root;
    //��������ÿһ��Ԫ��
    for (int i = 0; i < length; i++)
    {
        //��ͷԪ�س���
        TreeNode* temp = queue[front];
        front++;
        //��������д�����ӵ�λ��û�г�������߽磬����������
        if (i * 2+1 < length&& arr[2 * i+1]!=-101) {
            //�����ڵ�
            TreeNode* node = createNode(arr[2 * i+1]);
            //�ڵ����
            queue[rear] = node;
            rear++;
            //�ýڵ�����Ϊ��һ���ڵ�����ӽڵ�
            temp->left = node;
        }
        //��������д���Һ��ӵ�λ��û�г�������߽磬�������Һ���
        if (i * 2 + 2 < length&& arr[2 * i + 2]!=-101) {
            //�����ڵ�
            TreeNode* node = createNode(arr[2 * i+2]);
            //�ڵ����
            queue[rear] = node;
            rear++;
            //�ýڵ�����Ϊ��һ���ڵ�����ӽڵ�
            temp->right = node;
        }
    }
    //�ͷŶ���
    free(queue);
    //��������
    return root;
}

int getNumber() {
    string str = "4271369";
    return str.size();
}

int main() {
    string str = "4271369";
    
    int length = getNumber();
    int* arr = (int*)malloc(length * sizeof(int));
    
    for (int i = 0; i < length*2; i++)
    {
        if (i >= length) {
            arr[i] = -101;
        }
        else {
            arr[i] = str[i]-'0';
        }
    }
    for (int i = 0; i < length * 2; i++)
    {
        cout << arr[i] << endl;
    }
    TreeNode* root=createTree(arr,length,0);
    root = invertTree(root);
    cout << root->val << endl;
	return 0;
}