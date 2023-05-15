#include <bits/stdc++.h>

using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* lchild;
    TreeNode* rchild;
    TreeNode(int val):data(val), lchild(nullptr), rchild(nullptr){}
};

class BinaryTree{
    private:
    TreeNode* root;

    void inorder_dfs_traversal_helper(TreeNode* node){
        if(!node) return;
        inorder_dfs_traversal_helper(node->lchild);
        cout << node->data << ' ';
        inorder_dfs_traversal_helper(node->rchild);
    }

    void bfs_traversal_helper(){
        // This traversal is done by queueing up every node available in the tree one after the other.
        // Not many secrets one this one.
        queue<TreeNode*> q;
        TreeNode* aux = root;
        do{
            cout << aux->data << ' ';
            if(aux->lchild)
                q.push(aux->lchild);
            if(aux->rchild)
                q.push(aux->rchild);
            if(q.empty())
                return;
            aux = q.front();
            q.pop();
        }while(true);
    }

    public:
    BinaryTree():root(nullptr){}

    void insert(int val){
        if(!root){
            root = new TreeNode(val);
            return;
        }
        TreeNode* aux = root;
        while(true){
            if(val > aux->data){
                if(!aux->rchild){
                    aux->rchild = new TreeNode(val);
                    break;
                }
                aux = aux->rchild;
            }else{
                if(!aux->lchild){
                    aux->lchild = new TreeNode(val);
                    break;
                }
                aux = aux->lchild;
            }
        }
    }

    void inorder_dfs_traversal(){
        inorder_dfs_traversal_helper(root);
    }

    void bfs_traversal(){
        bfs_traversal_helper();
    }
};

int main(){

    BinaryTree bt;

    bt.insert(5);
    bt.insert(3);
    bt.insert(7);
    bt.insert(2);
    bt.insert(4);
    bt.insert(6);
    bt.insert(8);

    bt.inorder_dfs_traversal();
    cout << '\n';
    bt.bfs_traversal();


    return 0;
}