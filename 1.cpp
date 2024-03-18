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
//创建节点
TreeNode* createNode(int num) {
    //开辟节点空间
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    //左右孩子设置为0
    node->left = nullptr;
    node->right = nullptr;
    //设置该节点的值
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

//创建二叉树
TreeNode* createTree(int arr[],int length,int pos) {
    //如果数组为空则返回
    if (pos >= length) return nullptr;
    
    //构建根节点
    TreeNode* root = createNode(arr[0]);
    //构建队列
    TreeNode** queue = (TreeNode**)malloc(length * sizeof(TreeNode*));
    //定义队列头指针，尾指针
    int front = 0, rear = 1;
    //第一个元素入队
    queue[front] = root;
    //遍历数组每一个元素
    for (int i = 0; i < length; i++)
    {
        //队头元素出队
        TreeNode* temp = queue[front];
        front++;
        //如果数组中存放左孩子的位置没有超过数组边界，则设置左孩子
        if (i * 2+1 < length&& arr[2 * i+1]!=-101) {
            //创建节点
            TreeNode* node = createNode(arr[2 * i+1]);
            //节点入队
            queue[rear] = node;
            rear++;
            //该节点设置为上一个节点的左子节点
            temp->left = node;
        }
        //如果数组中存放右孩子的位置没有超过数组边界，则设置右孩子
        if (i * 2 + 2 < length&& arr[2 * i + 2]!=-101) {
            //创建节点
            TreeNode* node = createNode(arr[2 * i+2]);
            //节点入队
            queue[rear] = node;
            rear++;
            //该节点设置为上一个节点的右子节点
            temp->right = node;
        }
    }
    //释放队列
    free(queue);
    //返回树根
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