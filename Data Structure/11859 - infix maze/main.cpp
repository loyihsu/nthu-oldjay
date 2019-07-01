// Problem: http://140.114.86.238/problem/11859/
#include <iostream>

template <class T>
class result {
public:
    result(int Capacity = 10);
    ~result();
    
    bool isEmpty() const;
    int size() const;
    
    T *show();
    T last();
    
    void sPush(const T&);
    void Push(const T&,  int px, int py);
    void Pop ();
    
    bool legal();
private:
    T *array;
    int place_x[10000];
    int place_y[10000];
    int top;
    int capacity;
};

template <class T>
result<T>::result(int Capacity): capacity (Capacity)
{
    if (Capacity < 1) throw "Capacity must be > 0";
    array = new T [Capacity];
    top = -1;
}

template <class T>
result<T>::~result()
{
    delete [] array;
}

template <class T>
inline int result<T>::size() const
{
    return top + 1;
}

template <class T>
inline bool result<T>::isEmpty() const
{
    return size() == 0;
}

template <class T>
T result<T>::last()
{
    if (isEmpty()) throw "Nothing in!";
    return array[top];
}

template <class T>
T* result<T>::show()
{
    if (isEmpty()) throw "Nothing in!";
    return array;
}

template <class T>
void expand(T*& t, int oldSize, const int newSize)
{
    if (newSize < 0) throw "New capacity must be > 0";
    T* newer = new T[newSize];
    int num = std::min(oldSize, newSize);
    std::copy (t, t+num, newer);
    delete [] t;
    
    t = newer;
}

template <class T>
void result<T>::Push(const T& x, int px, int py)
{
    if (top == capacity - 1)
    {
        expand(array, capacity, 2*capacity);
        capacity *= 2;
    }
    top = top+1;
    array[top] = x;
    place_x[top] = px;
    place_y[top] = py;
}

template <class T>
void result<T>::sPush(const T& x)
{
    if (top == capacity - 1)
    {
        expand(array, capacity, 2*capacity);
        capacity *= 2;
    }
    top = top+1;
    array[top] = x;
    
}

template <class T>
void result<T>::Pop() {
    if (isEmpty()) throw "Uh-oh! Nothing left!";
    array[top].~T();
    place_x[top] = 0;
    place_y[top] = 0;
    top = top-1;
}

template <class T>
bool result<T>::legal()
{
    for (int i = 0; i < top; i++)
    {
        if (place_x[top] == place_x[i] && place_y[top] == place_y[i]) return false;
    }
    
    if (top == 0)
    {
        if (array[top] >= '1' && array[top] <= '9') return true;
        else if (array[top] == '(') return true;
        else return false;
    }
    
    if (array[top] >= '1' && array[top] <= '9')
    {
        if (array[top-1] == '(') return true;
        else if (array[top-1] >= '1' && array[top-1] <= '9') return true;
        else if (array[top-1] == '+' || array[top-1] == '-' || array[top-1] == '*' || array[top-1] == '/') return true;
        else if (array[top-1] == ')') return false;
    }
    
    if (array[top] == '(')
    {
        if (array[top-1] == '+' || array[top-1] == '-' || array[top-1] == '*' || array[top-1] == '/') return true;
        else if (array[top-1] >= '1' && array[top-1]<='9') return false;
        else if (array[top-1] == '(') return true;
        else if (array[top-1] == ')') return false;
    }
    
    if (array[top] == ')')
    {
        if (array[top-1] == '+' || array[top-1] == '-' || array[top-1] == '*' || array[top-1] == '/')
        {
            return false;
        } else if (array[top-1] == '(')
        {
            return false;
        } else {
            bool t = false;
            for (int i = top-1; i >= 0; i--)
            {
                if (array[i] == ')'){
                    if (t == false)
                        t = true;
                    else return false;
                } else if (array[i] == '(')
                {
                    if (!t) return true;
                    else if (t) t = false;
                }
            }
        }
    }
    
    if (array[top] =='+' || array[top] =='-' || array[top] =='*' || array[top] =='/')
    {
        if (array[top-1] >= '1' && array[top-1] <= '9') return true;
        else if (array[top-1] == '(') return false;
        else if (array[top-1] == ')') return true;
        else if (array[top-1] =='+' || array[top-1] =='-' || array[top-1] =='*' || array[top-1] =='/') return false;
    }
    
    return false;
}

bool findWay(int cur_x, int cur_y,int width, int height, char **temp, result<char> &cur);

result<char> toPostfix(char* infix, int size);
result<char> makeMyInfix(char* infix, int size);

int main(void)
{
    int numOfMatrix, width, height;
    
    std::cin >> numOfMatrix;
    
    int n = numOfMatrix;
    
    std::cout << numOfMatrix << std::endl;
    
    while (n--)
    {
        std::cin >> width;
        std::cin >> height;
        char **temp;
        temp = new char* [height];
        for (int i = 0; i < height; i++)
            temp[i] = new char [width];
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                std::cin >> temp[i][j];
        
        result<char> myInfix;
        bool rst = findWay(-1, 0, width, height, temp, myInfix);
        
        std::cout << width << std::endl;
        std::cout << height << std::endl;

        for(int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
                std::cout << temp[i][j] << " ";
            std::cout << std::endl;
        }
        
        if (!rst)
            std::cout << "No";
        else{
            std::cout << "Yes" << std::endl;
            char *r = myInfix.show();
            
            // infix
            
            result<char> myInfixPresent = makeMyInfix(r, myInfix.size());
            char *ip = myInfixPresent.show();
            
            for (int i = 0; i < myInfixPresent.size(); i++)
            {
                std::cout << ip[i];
            }
            
            std::cout << " " << std::endl;
            
            // make postfix
            result<char> myPostfix = toPostfix(r, myInfix.size());
            char *p = myPostfix.show();
            for (int i = 0; i < myPostfix.size(); i++)
                std::cout << p[i];
        }
        std::cout << std::endl;
        
    }
    
    return 0;
}
result<char> makeMyInfix(char* infix, int size) {
    result<char> myInfixMade;
    
    for (int i = 0; i < size; i++)
    {
        if (myInfixMade.isEmpty())
        {
            myInfixMade.sPush(infix[i]);
        } else {
            if (infix[i] >= '1' && infix[i] <= '9')
                if (!(myInfixMade.last() >= '1' && myInfixMade.last() <= '9'))
                    if (myInfixMade.last() != ' ')
                        myInfixMade.sPush(' ');
            else
                myInfixMade.sPush(' ');
            myInfixMade.sPush(infix[i]);
        }
    }
    
    return myInfixMade;
}


result<char> toPostfix(char* infix, int size) {
    result<char> postfix, temp;
    
    for (int i = 0; i < size; i++)
    {
        if (infix[i] >= '1' && infix[i] <= '9')
        {
            postfix.sPush(infix[i]);
        } else if (infix[i] == '(')
        {
            temp.sPush(infix[i]);
        } else if (infix[i] == ')')
        {
            if (postfix.last() != ' ')
                postfix.sPush(' ');
            while (temp.last() != '(')
            {
                postfix.sPush(temp.last());
                if (postfix.last() != ' ')
                    postfix.sPush(' ');
                temp.Pop();
            }
            temp.Pop();
            
        } else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
            if (infix[i] == '*' || infix[i] == '/')
            {
                temp.sPush(infix[i]);
                if (postfix.last() != ' ')
                    postfix.sPush(' ');
            } else if (infix[i] == '-' || infix[i] == '+')
            {

                while (!temp.isEmpty())
                {
                    if (temp.last() == '*' || temp.last() == '/' || temp.last() == '-' || temp.last() == '+'){
                        if (postfix.last() != ' ')
                            postfix.sPush(' ');
                        postfix.sPush(temp.last());
                        temp.Pop();
                        if (postfix.last() != ' ')
                            postfix.sPush(' ');
                    } else break;
                    
                }
                temp.sPush(infix[i]);
                if (postfix.last() != ' ')
                    postfix.sPush(' ');
            }
        }
    }
    
    while (!temp.isEmpty())
    {
        if (postfix.last() != ' ')
            postfix.sPush(' ');
        postfix.sPush(temp.last());
        if (postfix.last() != ' ')
            postfix.sPush(' ');
        temp.Pop();
    }
    
    if (postfix.last() != ' ')
        postfix.sPush(' ');
    
    return postfix;
}

bool findWay(int cur_x, int cur_y, int width, int height, char **temp, result<char> &cur)
{
    if (cur_x == height - 1 && cur_y == width - 1)
    {
        int c=0,o=0;
        
        char *temp = cur.show();
        bool flag = false;
        
        for (int i = 0; i < cur.size(); i++)
        {
            if (temp[i] == ')') c++;
            if (temp[i] == '(') o++;
        }
        if (c == o)
        {
            if (!(cur.last() == '+' || cur.last() == '-' || cur.last() == '*' || cur.last() == '/'))
            {
                flag = true;
            }
        }
        return flag;
    } else {
        int next_x, next_y;
        
        //down
        next_x = cur_x + 1;
        next_y = cur_y;
        if (next_x >= 0 && next_y >= 0)
        {
            if (next_x < height && next_y < width)
            {
                cur.Push(temp[next_x][next_y],next_x,next_y);
                if (cur.legal()){
                    if (findWay(next_x, next_y, width, height, temp, cur)) {
                        return true;
                    } else {
                        cur.Pop();
                    }
                } else {
                    cur.Pop();
                }
            }
        }
        
        //right
        next_y = cur_y + 1;
        next_x = cur_x;
        if (next_x >= 0 && next_y >= 0)
        {
            if (next_x < height && next_y < width)
            {
                cur.Push(temp[next_x][next_y],next_x,next_y);
                if (cur.legal()){
                    if (findWay(next_x, next_y, width, height, temp, cur)) {
                        return true;
                    } else {
                        cur.Pop();
                    }
                } else {
                    cur.Pop();
                    
                }
            }
        }
        
        //left
        next_y = cur_y - 1;
        next_x = cur_x;
        if (next_x >= 0 && next_y >= 0)
        {
            if (next_x < height && next_y < width)
            {
                cur.Push(temp[next_x][next_y],next_x,next_y);
                if (cur.legal()){
                    if (findWay(next_x, next_y, width, height, temp, cur)){
                        return true;
                    } else {
                        cur.Pop();
                    }
                } else {
                    cur.Pop();
                }
            }
        }
        
        //up
        next_y = cur_y;
        next_x = cur_x - 1;
        if (next_x >= 0 && next_y >= 0)
        {
            if (next_x < height && next_y < width)
            {
                cur.Push(temp[next_x][next_y],next_x, next_y);
                if (cur.legal()){
                    if (findWay(next_x, next_y, width, height, temp, cur)){
                        return true;
                    } else {
                        cur.Pop();
                    }
                } else {
                    cur.Pop();
                }
            }
        }
    }
    
    return false;
}



