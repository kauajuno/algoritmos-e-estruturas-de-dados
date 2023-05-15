#include <bits/stdc++.h>

using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* right_child;
    TreeNode* left_child;
    TreeNode(int val): data(val), right_child(nullptr), left_child(nullptr){}
};

class BinaryTree{
    private:
    TreeNode* root;

    void inorder_dfs_helper(TreeNode* node){
        if(!node) return;
        inorder_dfs_helper(node->left_child);
        cout << node->data << ' ';
        inorder_dfs_helper(node->right_child);
    }

    void preorder_dfs_helper(TreeNode* node){
        if(!node) return;
        preorder_dfs_helper(node->left_child);
        preorder_dfs_helper(node->right_child);
        cout << node->data << ' ';
    }

    void postorder_dfs_helper(TreeNode* node){
        if(!node) return;
        cout << node->data << ' ';
        postorder_dfs_helper(node->left_child);
        postorder_dfs_helper(node->right_child);
    }

    public:
    BinaryTree(): root(nullptr){}

    void insert(int val){
        if(!root){
            root = new TreeNode(val);
            return;
        }else{
            TreeNode* aux = root;
            while(aux){
                if(val < aux->data){
                    if(aux->left_child){
                        aux = aux->left_child;
                    }else{
                        aux->left_child = new TreeNode(val);
                        break;
                    }
                }else{
                    if(aux->right_child){
                        aux = aux->right_child;
                    }else{
                        aux->right_child = new TreeNode(val);
                        break;
                    }
                }
            }
        }
    }

    void inorder_dfs(){
        inorder_dfs_helper(root);
    }

    void preorder_dfs(){
        preorder_dfs_helper(root);
    }

    void postorder_dfs(){
        postorder_dfs_helper(root);
    }
};

int main(){

    BinaryTree bt;
    bt.insert(5);
    bt.insert(3);
    bt.insert(2);
    bt.insert(4);
    bt.insert(7);
    bt.insert(6);
    bt.insert(9);
    bt.insert(8);
    bt.insert(10);

    bt.inorder_dfs();
    cout << '\n';
    bt.preorder_dfs();
    cout << '\n';
    bt.postorder_dfs();
    cout << '\n';

    return 0;
}