#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    /*vector<int> value1;
    vector<int> value2;
    void findPath(Node *root, int value, vector<int> val){
        findPath(root, v1, value1);
        findPath(root, v2, value2);
    }*/
    
    Node *lca(Node *root, int v1, int v2) {
        if (root == nullptr) {
            return nullptr;
        }
        Node *left = nullptr;
        Node *right = nullptr;

        if (root->data == v1 || root->data == v2){
            return root;
        }
        else if (root->data > v1 && root->data > v2){
            left = lca(root->left, v1, v2);
        }
        else if (root->data < v1 && root->data < v2){
            right = lca(root->right, v1, v2);
        }
        else{
            return root;
        }
        return (left != nullptr) ? left: right;
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  	
  	int v1, v2;
  	std::cin >> v1 >> v2;
  
    Node *ans = myTree.lca(root, v1, v2);
    
  	std::cout << ans->data;

    return 0;
}
