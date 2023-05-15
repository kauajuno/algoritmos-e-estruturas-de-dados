#include<bits/stdc++.h>

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

    vector<int> inorder_dfs(){
        TreeNode* aux = root;
        stack<TreeNode*> stack;
        vector<int> inorder;
        while(aux != nullptr || !stack.empty()){
            if(aux != nullptr){
                stack.push(aux);
                aux = aux->left_child;
            }else{
                aux = stack.top();
                stack.pop();
                inorder.push_back(aux->data);
                aux = aux->right_child;
            }
        }
        return inorder;
    }

    vector<int> preorder_dfs(){
        TreeNode* aux = root;
        stack<TreeNode*> stack;
        vector<int> preorder;
        while(aux != nullptr || !stack.empty()){
            if(aux != nullptr){
                preorder.push_back(aux->data);
                stack.push(aux);
                aux = aux->left_child;
            }else{
                aux = stack.top();
                stack.pop();
                aux = aux->right_child;
            }
        }
        return preorder;
    }

    vector<int> postorder_dfs(){
        TreeNode* aux = root;
        stack<TreeNode*> stack;
        vector<int> postorder;
        while(aux != nullptr || !stack.empty()){
            if(aux != nullptr){
                stack.push(aux);
                postorder.insert(postorder.begin(), aux->data);
                aux = aux->right_child;
            }else{
                aux = stack.top();
                stack.pop();
                aux = aux->left_child;
            }
        }
        return postorder;
    }
};

int main(){

    vector<int> auxv;
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

    auxv = bt.inorder_dfs();

    for(int i : auxv)
        cout << i << ' ';
    cout << '\n';

    auxv = bt.preorder_dfs();

    for(int i : auxv)
        cout << i << ' ';
    cout << '\n';

    auxv = bt.postorder_dfs();

    for(int i : auxv)
        cout << i << ' ';
    cout << '\n';
    
    return 0;
}