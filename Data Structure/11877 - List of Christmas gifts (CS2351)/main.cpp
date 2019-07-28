// Problem: http://140.114.86.238/problem/11877/
#include <iostream>

class listItem {
    friend class myList;
public:
    listItem(std::string name, int money, listItem* link = NULL)
    {
        item = name;
        price = money;
        next = link;
    }
private:
    std::string item;
    int price;
    listItem *next;
};

class myList {
public:
    void create();
    void insertBack(std::string item, int price);
    void deleteAt(int price);
    void insertAfter(std::string item, int price, int priceAfter);
    void reverse();
    void show();
    bool empty();
    bool find(int price);
private:
    listItem *first;
};

bool myList::find(int price) {
    listItem *cur = first;
    
    while (cur != NULL) {
        if (cur->price == price)
            return true;
        
        cur = cur->next;
    }
    
    return false;
}

void myList::create(){
    first = NULL;
}

void myList::insertBack(std::string item, int price) {
    if (first != NULL) {
        listItem *cur = first;
        
        listItem *newNode = new listItem(item, price);
        while (cur != NULL) {
            if (cur->next == NULL) {
                cur->next = newNode;
                break;
            } else {
                cur = cur->next;
            }
        }
    } else {
        listItem *newNode = new listItem(item, price);
        first = newNode;
    }
}

void myList::insertAfter(std::string item, int price, int priceAfter) {
    listItem *cur = first;
    listItem *newNode = new listItem(item, price), *temp = NULL;
    
    while (cur != NULL) {
        if (cur->next == NULL) {
            if (cur->price == priceAfter) {
                cur->next = newNode;
            }
        } else if (cur->price == priceAfter) {
            temp = cur->next;
            cur->next = newNode;
            newNode->next = temp;
            break;
        }
        cur = cur->next;
    }
    
}

void myList::deleteAt(int price) {
    listItem *cur = first;
    listItem *prev = NULL;
    
    while (cur != NULL) {
        if (cur->price == price) {
            if (cur == first) {
                first = first->next;
                break;
            } else {
                listItem *r = cur;
                prev->next = cur->next;
                delete r;
                break;
            }
        }
        
        prev = cur;
        cur = cur->next;
    }
}

void myList::reverse() {
    listItem *cur = NULL, *prev = NULL, *next = NULL;
   
    next = first;
    
    while (next != NULL)
    {
        cur = next;
        next = next->next;
        cur->next = prev;
        prev = cur;
    }
    first = cur;
    
    return;
}

bool myList::empty() {
    return first == NULL;
}

void myList::show() {
    listItem *index = first;
    
    while (index != NULL)
    {
        std::cout << "(" << (index->item) << "," << (index->price) << ")" ;
        if (index->next != NULL)
        {
            std::cout << "->";
        }
        index = index->next;
    }
    
    std::cout << std::endl;
}

int main(int argc, const char * argv[]) {
    std::string command;
    std::string gift;
    int price, priceAfter;
    myList myGiftList;
    
    myGiftList.create();
    
    while (std::cin >> command && command != "End") {
        if (command == "InsertBack") {
            std::cin >> gift;
            std::cin >> price;
            if (!myGiftList.find(price))
                myGiftList.insertBack(gift, price);
        } else if (command == "InsertAfter") {
            std::cin >> gift;
            std::cin >> price;
            std::cin >> priceAfter;
            if (!myGiftList.find(price))
                myGiftList.insertAfter(gift, price, priceAfter);
        } else if (command == "Delete") {
            std::cin >> price;
            myGiftList.deleteAt(price);
        } else if (command == "Reverse") {
            myGiftList.reverse();
        }
    }
    
    if (myGiftList.empty()) {
        std::cout << "Empty" << std::endl;
    } else {
        std::cout << "List" << std::endl;
        myGiftList.show();
    }
    
    return 0;
}