// Problem: http://140.114.86.238/problem/11917/
#include <iostream>
#include <queue>

int **matrix;
bool **matrix_visited;

class node {
    friend class mTree;
public:
    node (int num) {
        number = num;
        left = NULL;
        down = NULL;
        right = NULL;
        up = NULL;
    }
    void insert(node* parent, int num, std::string dir);

    int number;
    node *left, *down, *right, *up;
};

class mTree {
public:
    void create(int num);
    node *root;

    void coinTraverse(int steps);
};

void mTree::coinTraverse(int steps) {
    std::queue<node*> q, qol;
    std::queue<int> l;
    node *cur = root;
    int level = 0;
    int max = 0;

    while (cur) {
        if (level == steps)
        {
            qol.push(cur);
        } else if (level > steps) break;
        //left
        if (cur -> left) {
            q.push(cur->left);
            l.push(level+1);
        }
        //down
        if (cur -> down){
            q.push(cur->down);
            l.push(level+1);
        }
        //right
        if (cur -> right) {
            q.push(cur->right);
            l.push(level+1);
        }
        //up
        if (cur -> up)
        {
            q.push(cur->up);
            l.push(level+1);
        }

        if (q.empty()) break;

        cur = q.front();
        level = l.front();

        q.pop();
        l.pop();
    }

    while (!qol.empty())
    {
        node *cur = qol.front();
        max = (cur->number > max)? cur->number: max;
        qol.pop();
    }
    std::cout << max << std::endl;
}

void mTree::create(int num)
{
    node* newNode = new node(num);
    root = newNode;
}

void node::insert(node* parent, int num, std::string dir)
{
    node* newNode = new node(num);
    if (dir == "l")
    {
        parent->left = newNode;
    } else if (dir == "d")
    {
        parent->down = newNode;
    } else if (dir == "r")
    {
        parent->right = newNode;
    } else if (dir == "u")
    {
        parent->up = newNode;
    }
}

void grow(node *parent, int x, int y, int width, int height)
{
    int new_x, new_y;


    //left
    new_x = x-1;
    new_y = y;

    if ((new_x < width)&&(new_x >= 0)&&(new_y < height)&&(new_y >= 0))
    {
        if (matrix[new_y][new_x] != 0)
        {
            if (!matrix_visited[new_y][new_x])
            {
                parent->insert(parent, matrix[new_y][new_x], "l");
                matrix_visited[new_y][new_x] = true;
                grow(parent->left, new_x, new_y, width, height);
            }
        }
    }

    //down
    new_x = x;
    new_y = y+1;

    if ((new_x < width)&&(new_x >= 0)&&(new_y < height)&&(new_y >= 0))
    {
        if (matrix[new_y][new_x] != 0)
        {
            if (!matrix_visited[new_y][new_x])
            {
                parent->insert(parent, matrix[new_y][new_x], "d");
                matrix_visited[new_y][new_x] = true;
                grow(parent->down, new_x, new_y, width, height);
            }
        }
    }

    //right
    new_x = x+1;
    new_y = y;

    if ((new_x < width)&&(new_x >= 0)&&(new_y < height)&&(new_y >= 0))
    {
        if (matrix[new_y][new_x] != 0)
        {
            if (!matrix_visited[new_y][new_x])
            {
                parent->insert(parent, matrix[new_y][new_x], "r");
                matrix_visited[new_y][new_x] = true;
                grow(parent->right, new_x, new_y, width, height);
            }
        }
    }

    //up
    new_x = x;
    new_y = y-1;
    if ((new_x < width)&&(new_x >= 0)&&(new_y < height)&&(new_y >= 0))
    {
        if (matrix[new_y][new_x] != 0)
        {
            if (!matrix_visited[new_y][new_x])
            {
                parent->insert(parent, matrix[new_y][new_x], "u");
                matrix_visited[new_y][new_x] = true;
                grow(parent->up, new_x, new_y, width, height);
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int numOfMatrices, width, height, starting_x, starting_y, steps;
    int i, j;
    mTree tree;

    std::cin >> numOfMatrices;

    while (numOfMatrices--)
    {
        std::cin >> width;
        std::cin >> height;
        std::cin >> starting_x;
        std::cin >> starting_y;

        //alloc
        matrix = new int*[height];
        matrix_visited = new bool*[height];

        for (i = 0; i < height; i++)
        {
            matrix[i] = new int[width];
            matrix_visited[i] = new bool[width];
        }

        //init
        for (i = 0; i < height; i++)
        {
            for (j = 0; j < width; j++)
            {
                std::cin >> matrix[i][j];
                matrix_visited[i][j] = false;
            }
        }

        std::cin >> steps;

        tree.create(matrix[starting_y][starting_x]);
        matrix_visited[starting_y][starting_x] = true;

        grow(tree.root, starting_x, starting_y, width, height);

        tree.coinTraverse(steps);

        //dealloc
        for (i = 0; i < height; i++)
        {
            delete[] matrix[i];
            delete[] matrix_visited[i];
        }

        delete[] matrix;
        delete[] matrix_visited;
    }

    return 0;
}

