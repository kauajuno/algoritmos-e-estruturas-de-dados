#include<bits/stdc++.h>

using namespace std;

enum Color{RED, BLACK};

class TreeNode{
    public:
    int data;
    TreeNode* lchild;
    TreeNode* rchild;
    TreeNode* parent;
    Color color;
    TreeNode(int val): data(val), parent(nullptr), color(Color::RED){}
};

class RBTree{
    private:

        TreeNode* root;
        TreeNode* nil;

        void arrange(TreeNode* child){
            TreeNode* uncle;
            while(child->parent->color == Color::RED){
                if(child->parent == child->parent->parent->rchild){
                    uncle = child->parent->parent->lchild;
                    if(uncle->color == Color::RED){
                        uncle->color = Color::BLACK;
                        child->parent->color = Color::BLACK;
                        child->parent->parent->color = Color::RED;
                        child = child->parent->parent;
                    }else{
                        // TODO: treat rotation case
                    }
                }else{
                    uncle = child->parent->parent->rchild;
                    if(uncle->color == Color::RED){
                        uncle->color = Color::BLACK;
                        child->parent->color = Color::BLACK;
                        child->parent->parent->color = Color::RED;
                        child = child->parent->parent;
                    }else{
                        // TODO: treat rotation case
                    }
                }
                if(child == root)
                    break;
            }
            root->color = Color::BLACK;
        }

        void inOrderHelper(TreeNode* node){
            if(node == nullptr) return;
            inOrderHelper(node->lchild);
            cout << node->data << ' ';
            inOrderHelper(node->rchild);
        }

        void preOrderHelper(TreeNode* node){
            if(node == nullptr) return;
            cout << node->data << ' ';
            preOrderHelper(node->lchild);
            preOrderHelper(node->rchild);
        }

        void postOrderHelper(TreeNode* node){
            if(node == nullptr) return;
            postOrderHelper(node->lchild);
            postOrderHelper(node->rchild);
            cout << node->data << ' ';
        }

    public:

        RBTree(){
            nil->color = Color::BLACK;
            root = nil;
        }

        void inOrderDFS(){
            inOrderHelper(root);
        }

        void preOrderDFS(){
            preOrderHelper(root);
        }

        void postOrderDFS(){
            postOrderHelper(root);
        }

        void insert(int val){
            TreeNode* newNode = new TreeNode(val);
            newNode->lchild = newNode->rchild = nil;
            
            TreeNode* prev = nullptr;
            TreeNode* curr = root;

            while(curr != nil){
                prev = curr;
                if(newNode->data < curr->data)
                    curr = curr->lchild;
                else
                    curr = curr->rchild;
            }

            newNode->parent = prev;

            if(prev == nullptr){
                newNode->color = Color::BLACK;
                root = newNode;
                return;
            }
            else if(newNode->data < prev->data)
                prev->lchild = newNode;
            else
                prev->rchild = newNode;

            if(newNode->parent->parent == nullptr)
                return;

            arrange(newNode);
            
        }
};

int main(){
    
    return 0;
}