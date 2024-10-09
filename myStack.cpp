#include <iostream>
#include <vector>  
#include <stdexcept>  // For standard exception handling
using namespace std;

template<typename T>
class Node {
public:
    T* val;            // Pointer to T for val
    Node* next;
    
    Node() : val(nullptr), next(nullptr) {}
    
    // Allocate memory for val with new
    Node(T newVal) : val(new T(newVal)), next(nullptr) {}
    
    // Destructor to free the allocated memory
    ~Node() {
        delete val;
    }
};

template<typename T>
class myStack {
private:
    Node<T>* root;
    int length;

public:
    myStack() : root(nullptr), length(0) {}

    ~myStack() {
        while (!empty()) {
            pop();
        }
    }

    void push(T val) {
        Node<T>* tmp = new Node<T>(val);
        tmp->next = root;
        root = tmp;
        length++;
    }

    void pop() {
        if (empty()) throw runtime_error("Stack is empty!");
        
        Node<T>* next = root->next;
        delete root;  // This calls the destructor of Node, freeing the memory for val
        root = next;
        length--;
    }

    T top() const {
        if (!empty()) return *(root->val);  // Dereference val
        throw runtime_error("Stack is empty!");
    }

    bool empty() const {
        return length == 0;
    }

    int size() const {
        return length;
    }
};

int main() {
    myStack<vector<int> > stack;  // Add space between angle brackets
    vector<int> first({10});          // Use vector constructor to initialize
    vector<int> second({20, 30});     // Use vector constructor
    vector<int> third({40, 50, 60});  // Use vector constructor
    stack.push(first);       // Push a vector with one element
    stack.push(second);   // Push a vector with two elements
    stack.push(third); // Push a vector with three elements
    
    cout << "Stack size: " << stack.size() << endl;
    
    // Access the top element, which is a vector, and print its contents
    for (int i : stack.top()) {
        cout << i << " ";
    }
    cout << endl;

    stack.pop();

    // Access the new top element after pop and print its contents
    for (int i : stack.top()) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Stack size after pop: " << stack.size() << endl;

    return 0;
}
