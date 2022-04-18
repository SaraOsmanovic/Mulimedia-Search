#ifndef MULTIMEDIA_SEARCH_AVLTREE_H
#define MULTIMEDIA_SEARCH_AVLTREE_H

/*** Reference: Gator AVL Project by Sara Osmanovic ***/

#include <set>
#include <vector>

using namespace std;
template<class T>
class AVLTree {
    struct Node {
        T* node_object = nullptr;
        Node* left = nullptr;
        Node* right = nullptr;
        unsigned int node_height = 1;
        short balance_factor = 0;

        Node(T* obj) {
            node_object = obj;
        }
        void printData() {
            node_object->print();
        }
    };

    Node* root = nullptr;
    int height = 0;

public:
    AVLTree(set<T*> data) {
        for (auto i = data.begin(); i != data.end() ; ++i) {
            root = insertNode(*i, root);
        }
        vector<Node*> orderedData;
        inorderTraversal(root, orderedData);
        /*** This is an access point. The data is sorted to be printed at this point. However, I can't implement
         * printing yet. This is a front end part.***/
        for (int i = 0; i < orderedData.size(); ++i) {
            orderedData.at(i)->printData();
        }
    }

    Node* insertNode(T* object, Node* curr){
        if (curr == nullptr){
            // Base case, creates a node with the specified student info
            curr = new Node(object);
            return curr;
        } else {
            // Recursively adds node in the right subtree
            if (*curr->node_object > *object){
                curr->left = (insertNode(object, curr->left));
            } else {
                curr->right = (insertNode(object, curr->right));
            }
        }
        // Re-calculates the current node's balance factor
        int l;
        int r;
        if (curr->left == nullptr) {
            l = 0;
        } else {
            l = curr->left->node_height;
        }
        if (curr->right == nullptr) {
            r = 0;
        } else {
            r = curr->right->node_height;
        }
        curr->balance_factor = ((short)(l-r));
        // Rotates the subtree if the balance factor is greater than 1 or less than -1
        if (curr->balance_factor > 1 ){
            curr = rightRotation(curr);
        } else if(curr->balance_factor < -1){
            curr = leftRotation(curr);
        }
        height = maxNodeHeight();
        return curr;
    }

    unsigned int getHeight (Node* curr, unsigned int& height) {
        // Calculates the height of a node by counting the longest path from curr to leaf node
        if (curr == nullptr){
            return 0;
        }
        unsigned int leftSubtreeHeight = heightCalculator(curr->left, height);
        unsigned int rightSubtreeHeight = heightCalculator(curr->right, height);

        height = max(leftSubtreeHeight, rightSubtreeHeight) + 1;
        return height;
    }

    unsigned int maxNodeHeight(){
        vector<Node*> tree;
        inorderTraversal(this->root, tree);
        unsigned int maxHeight = 0;
        for (auto & i : tree) {
            maxHeight = max(maxHeight, i->node_height);
        }
        return maxHeight;
    }

    Node* rightRotation(Node* curr){
        // Performs the right rotation on the subtree
        Node* temp = curr;
        // Assigns the current node's (subtree root's) left to current node pointer
        curr = curr->left;
        // Sets temp pointers left to nullptr because of the way it rotates function
        // Possible only because the rotation is performed at every node insertion necessary
        // and because the tree is a binary tree
        temp->left = (nullptr);
        // Sets the new current's right to the temporary node (i.e. the previous subtree root)
        curr->right = (temp);
        return curr;
    }

    Node* leftRotation(Node* curr){
        // Performs left rotation on the subtree with root being the curr node
        Node* temp = curr;
        // Sets the current pointer to the previous curr's right node
        curr = curr->right;
        // Assigns the temp's right node to nullptr
        temp->right = (nullptr);
        // Possible only because the rotation is performed at every node insertion necessary
        // and because the tree is a binary tree
        // Sets the new curr's left to the temp
        curr->left = temp;
        return curr;
    }

    void inorderTraversal(Node* curr, vector<Node*>& data){
        // Helper function for inorder traversal of the tree
        if (curr == nullptr){
            // Base case
            return;
        }
        // Recursively calls the function on the left subtree until null is reached
        inorderTraversal(curr->left, data);
        // Adds current node to the vector
        data.push_back(curr);
        // Recursively calls the function on the right subtree until null is reached
        inorderTraversal(curr->right, data);
    }
};


#endif //MULTIMEDIA_SEARCH_AVLTREE_H
