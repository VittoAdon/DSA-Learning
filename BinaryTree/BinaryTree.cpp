#include <iostream>
#include <queue>
#include <algorithm>

struct TreeNode{
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data){
        value = data;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree{
    public:
        TreeNode *root;
        BinaryTree(){
            root = nullptr;
        }
        
        TreeNode *BuildTree(){
            int val;
            std::cin>> val;
            if(val == -1){return nullptr;}

            TreeNode *node = new TreeNode(val);
            node->left = BuildTree();
            node->right = BuildTree();

            return node;
        }
        
        void preorder(TreeNode *node) const{
            if(node == nullptr){
                return;
            }
            std::cout<<node->value<<" ";
            preorder(node->left);
            preorder(node->right);
        }

        void inorder(TreeNode *node) const{
            if(node == nullptr){
                return;
            }

            inorder(node->left);
            std::cout<<node->value<<" ";
            inorder(node->right);
        }

        void postorder(TreeNode *node)const{ 
            if(node == nullptr){
                return;
            }
            postorder(node->left);
            postorder(node->right);
            std::cout<<node->value<<" ";
        }

        void levelOrder(TreeNode *node) const{
            if(node == nullptr){return; }

            std::queue<TreeNode*> q;
            q.push(node);
            while(!q.empty()){
                TreeNode *curr = q.front();
                q.pop();
                std::cout<<curr->value<<" ";

                if(curr->left != nullptr){q.push(curr->left);}
                if(curr->right != nullptr){ q.push(curr->right);}
            }
        }

    
};