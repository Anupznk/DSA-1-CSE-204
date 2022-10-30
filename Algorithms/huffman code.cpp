#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    char data;
    unsigned freq;
    Node left, right;

    Node(char ch, unsigned f){
        data = ch;
        freq = f;
        left = right = NULL;
    }

    Node (Node *n){
        left = n->left;
        right = n->right;
        data = n->data;
        freq = n->freq;
    }

    Node() {
        left = right = NULL;
    }

    void setLeft(Node l){
        left = l;
    }

    void setRight(Node r){
        right = r;
    }

};

class MinHeap {
private:

    Node *chars;
    int length;
    int arraySize;
    int DEFAULT_SIZE = 1000;

public:

    MinHeap() {
        chars = new Node[DEFAULT_SIZE];
        arraySize = DEFAULT_SIZE;
        length = 0;
    }

    MinHeap(int size) {
        chars = new Node[size];
        arraySize = size;
        length = 0;
    }

    int getParentIndex(int index) {
        return (index-1)/2;
    }

    void swapNodes(int firstIndex, int secondIndex) {
        Node temp;
        temp = chars[firstIndex];
        chars[firstIndex] = chars[secondIndex];
        chars[secondIndex] = temp;
    }

    void bubbleUp(int index) {
        int parent;
        if (index == 0)
            return;
        else {
            parent = getParentIndex(index);
            if (chars[parent].freq > chars[index].freq) {
                //  THIS VIOLATES THE PROPERTY OF MAX HEAP
                swapNodes(parent, index);
                bubbleUp(parent);
            }
        }
    }

    void insert(char ch, unsigned f) {
        if (length == arraySize) {
            try{
                throw length;
            }
            catch(int ex) {
                cout<<"Exception: The Heap is Full"<<endl;
            }
        } else {
            chars[length].data = ch;
            chars[length].freq = f;
            //  INSERTING AT THE END OF THE ARRAY
            length++;
            bubbleUp(length-1);
        }
    }

    Node getMinNode() {
        if (length > 0)
            return chars[0];
        else {
            try{
                throw length;
            }
            catch(int ex) {
                cout<<"Exception: The Heap is empty. Garbage value alert"<<endl;
            }
        }
    }

    int getLeftChild(int index) {
        return (index + 1) * 2 - 1;
    }

    int getRightChild(int index) {
        return (index + 1) * 2;
    }

    void heapify(int index) {
        int minValIndex = index;

        int leftChildIndex = getLeftChild(index);
        int rightChildIndex = getRightChild(index);



        if (leftChildIndex < length && chars[leftChildIndex].freq < chars[minValIndex].freq) {
            minValIndex = leftChildIndex;
        }
        if (rightChildIndex < length && chars[rightChildIndex].freq < chars[minValIndex].freq) {
            minValIndex = rightChildIndex;
        }

        if (minValIndex != index) {
            swapNodes(minValIndex, index);

            heapify(minValIndex);
        }
    }

    void deleteKey() {
        if (length == 0) {
            try{
                throw length;
            }
            catch(int ex) {
                cout<<"Exception: The Heap is empty. Cannot delete"<<endl;
            }
        } else{
            Node lastNode = chars[length - 1];
            chars[0] = lastNode;
            length--;

            heapify(0);
        }
    }

    int size() {
        return length;
    }

    Node * getHeap() {
        return chars;
    }

    void setHeap(Node * chars) {
        this->chars = chars;
    }

    ~MinHeap() {
        delete [] chars;
    }
};

void printCodes(Node *root, char ch){

    if (root == NULL)
        return;

    if (root->data != '$')
        cout << root->data << ": " << ch << "\n";

    printCodes(root->left, '0');
    printCodes(root->right, '1');
}

void huffmanCode(char arr[], unsigned freq[], int n){
    MinHeap h;
    for (int i = 0; i<n; i++){
        h.insert(arr[i], freq[i]);
    }

    while(h.size() != 1){

        Node left (h.getMinNode());
        h.deleteKey();
        Node right (h.getMinNode());
        h.deleteKey();

        Node parent ('$', left.freq + right.freq);    // '$' is dummy char for intermediate nodes

        parent.setLeft(left);
        parent.setRight(right);


        h.insert(parent);
    }

    printCodes(h.getMinNode(), "");
}

int main() {

    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    unsigned freq[] = { 5, 9, 12, 13, 16, 45 };

    int n = sizeof(arr) / sizeof(arr[0]);

    huffmanCode(arr, freq, n);
}
