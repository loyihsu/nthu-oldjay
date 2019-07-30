// Problem: http://140.114.86.238/problem/11902/
#include <iostream>

template <class T>
class myQueue {
public:
    myQueue(int queueCapacity=1000) {
        queue = new T[queueCapacity];
        front = -1;
        rear = -1;
        capacity = queueCapacity;
    }
    bool empty();
    T& Front();
    T& Rear();
    void Push(T& item);
    void Pop();
    
private:
    T* queue;
    int front, rear;
    int capacity;
};


template<class T>
bool myQueue<T>::empty() {
    return front == rear;
}

template<class T>
T& myQueue<T>::Front() {
        return queue[(front+1)%capacity];
}

template<class T>
T& myQueue<T>::Rear() {
        return queue[rear];
}

template<class T>
void myQueue<T>::Push(T &item) {
    rear = (rear+1)%capacity;
    queue[rear] = item;
}

template<class T>
void myQueue<T>::Pop() {
    if (!empty()) {
        front = (front+1)%capacity;
        queue[front].~T();
    }
}

int **matrix;
bool **matrix_visited;

class node {
    friend class myTree;
public:
    node(int num) {
        number = num; left = NULL; right = NULL; up = NULL; down = NULL;
    }
    void insert(node* parent, int num, std::string dir);

    int number;
    node *left, *down, *right, *up;
};

class myTree {
public:
    void create(int num);
    void levelorder();
    void preorder(node* cur);
    void postorder(node* cur);
    node *root;
};

void myTree::levelorder() {
    myQueue<node*> q;
    node *cur = root;
    
    while (cur) {
        std::cout << cur->number;
        if (cur->left) q.Push(cur->left);
        if (cur->down) q.Push(cur->down);
        if (cur->right) q.Push(cur->right);
        if (cur->up)  q.Push(cur->up);
        if (q.empty()) return;
        else std::cout << " ";
        cur = q.Front();
        q.Pop();
    }
}



void myTree::preorder(node* cur) {
    if (cur) {
        if (cur != root) std::cout << " ";
        std::cout << cur->number;
        preorder(cur->left);
        preorder(cur->down);
        preorder(cur->right);
        preorder(cur->up);
    }
}

void myTree::postorder(node *cur) {
    if (cur) {
        postorder(cur->left);
        postorder(cur->down);
        postorder(cur->right);
        postorder(cur->up);
        std::cout << cur->number;
        if (cur != root) std::cout << " ";
    }
}

void myTree::create(int num) {
    node *newNode = new node(num);
    root = newNode;
}

void node::insert(node *parent, int num, std::string dir) {
    node *newnode = new node(num);
    if (dir == "r")
        parent->right = newnode;
    else if (dir == "l")
        parent->left = newnode;
    else if (dir == "u")
        parent->up = newnode;
    else if (dir == "d")
        parent->down = newnode;
}

void growTree(node *parent, int x, int y, int width, int height) {
    int new_x, new_y;
    
    new_x = x+1;        //right
    new_y = y;
    
    if ((new_x < width) && (new_x >= 0) && (new_y < height) && (new_y >= 0)) {
        if (matrix[new_y][new_x] != 0) {
            if (!matrix_visited[new_y][new_x]) {
                parent->insert(parent,matrix[new_y][new_x],"r");
                matrix_visited[new_y][new_x] = true;
                growTree(parent->right, new_x, new_y, width, height);
            }
        }
    }

    new_x = x-1;        //left
    new_y = y;
    
    if ((new_x < width) && (new_x >= 0) && (new_y < height) && (new_y >= 0)) {
        if (matrix[new_y][new_x] != 0) {
            if (!matrix_visited[new_y][new_x]) {
                parent->insert(parent,matrix[new_y][new_x], "l");
                matrix_visited[new_y][new_x] = true;
                growTree(parent->left, new_x, new_y, width, height);
            }
        }
    }
    
    new_x = x;      //up
    new_y = y-1;
    
    if ((new_x < width) && (new_x >= 0) && (new_y < height) && (new_y >= 0)) {
        if (matrix[new_y][new_x] != 0) {
            if (!matrix_visited[new_y][new_x]) {
                parent->insert(parent,matrix[new_y][new_x], "u");
                matrix_visited[new_y][new_x] = true;
                growTree(parent->up, new_x, new_y, width, height);
            }
        }
    }
    
    new_x = x;      //down
    new_y = y+1;
    
    if ((new_x < width) && (new_x >= 0) && (new_y < height) && (new_y >= 0)) {
        if (matrix[new_y][new_x] != 0) {
            if (!matrix_visited[new_y][new_x]) {
                parent->insert(parent,matrix[new_y][new_x],"d");
                matrix_visited[new_y][new_x] = true;
                growTree(parent->down, new_x, new_y, width, height);

            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int i, j, width, height, numOfMatrice, starting_x, starting_y;
    std::string traverseMode;
    
    std::cin >> numOfMatrice;
    
    while (numOfMatrice--) {
        myTree tree;
        std::cin >> width;
        std::cin >> height;
        
        std::cin >> starting_x;
        std::cin >> starting_y;
        
        matrix = new int*[height];        //alloc
        matrix_visited = new bool*[height];
        
        for (i = 0; i < height; i++) {
            matrix[i] = new int[width];
            matrix_visited[i] = new bool[width];
        }
        
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++) {
                std::cin >> matrix[i][j];
                matrix_visited[i][j] = false;
            }
        }
        
        std::cin >> traverseMode;
        
        tree.create(matrix[starting_y][starting_x]);        //root
        matrix_visited[starting_y][starting_x] = true;
        
        growTree(tree.root, starting_x, starting_y, width, height);
        
        if (traverseMode == "Level-order-traversal") {
            tree.levelorder();
        } else if (traverseMode == "Pre-order-traversal") {
            tree.preorder(tree.root);
        } else if (traverseMode == "Post-order-traversal") {
            tree.postorder(tree.root);
        }
        
        std::cout << std::endl;
        
        for (i = 0; i < height; i++) {      //de_alloc
            delete[] matrix[i];
            delete[] matrix_visited[i];
        }
        delete[] matrix;
        delete[] matrix_visited;
    }
    
    return 0;
}