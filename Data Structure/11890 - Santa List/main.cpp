// Problem: http://140.114.86.238/problem/11890/
#include <iostream>

class listItem {
    friend class SantaList;
public:
    listItem(std::string name, std::string gift, listItem* link = NULL)
    {
        kid = name;
        present = gift;
        next = link;
    }
private:
    std::string kid;
    std::string present;
    listItem *next;
};

class SantaList {
public:
    void create();
    void insertNormal(std::string name, std::string gift);
    void insertAppend(std::string name, std::string gift);
    void naughtyKid(std::string name);
    bool isEmpty();
    void show();
private:
    listItem *first;
};

bool SantaList::isEmpty()
{
    return first==NULL;
}

void SantaList::show()
{
    listItem *temp = NULL;

    temp = first;

    while (temp != NULL)
    {
        std::cout << "(" << temp->kid << "," << temp->present << ")";

        if (temp->next != NULL)
        {
            std::cout << "->";
        }

        temp = temp->next;
    }
}

void SantaList::create()
{
    first = NULL;
}

void SantaList::insertNormal(std::string name, std::string gift)
{
    listItem *newNode = new listItem(name, gift), *temp = NULL;

    if (first == NULL)
    {
        first = newNode;
    } else {
        temp = first;

        while (temp != NULL)
        {
            if (temp->next == NULL)
            {
               temp->next = newNode;
               break;
            }

            temp = temp->next;
        }
    }
}

void SantaList::insertAppend(std::string name, std::string gift)
{
    listItem *newNode = new listItem(name, gift), *last = NULL, *temp = NULL;

    if (first == NULL)
    {
        first = newNode;
    } else {
        temp = first;
        while (temp != NULL)
        {

            if (temp->present == "coal")
            {
                if (last != NULL) {
                    newNode->next = last->next;
                    last->next = newNode;
                    break;
                } else {
                    newNode->next = temp;
                    first = newNode;
                    break;
                }
            } else if (temp->next == NULL)
            {
                temp->next = newNode;
                break;
            }

            last = temp;
            temp = temp->next;
        }
    }
}

void SantaList::naughtyKid(std::string name)
{
    listItem *temp = NULL, *temp2 = NULL, *prev = NULL, *flag = NULL;

    temp = first;
    prev = NULL;

    while (temp != NULL)
    {
        if (temp->kid == name)
        {
            if (temp->present != "coal")
            {
                temp->present = "coal";
                if (prev == NULL)
                {
                    // first item;
                    flag = temp->next;

                    temp2 = flag;

                    while (temp2 != NULL)
                    {
                        if (temp2->present == "coal")
                        {
                            if (temp2->next == NULL)
                            {
                                temp2->next = temp;
                                temp->next = NULL;
                                break;
                            }
                        } else if (temp2->next == NULL)
                        {
                            temp2->next = temp;
                            temp->next = NULL;
                           break;
                        }

                        temp2 = temp2->next;
                    }

                    first = flag;
                    break;
                } else {

                    prev->next = temp->next;

                    temp2 = first;

                    while (temp2 != NULL)
                    {
                        if (temp2->present == "coal")
                        {
                            if (temp2->next == NULL)
                            {
                                temp2->next = temp;
                                temp->next = NULL;
                                break;
                            }
                        } else if (temp2->next == NULL)
                        {
                           temp2->next = temp;
                           temp->next = NULL;
                           break;
                        }
                        temp2 = temp2->next;
                    }

                    break;
                }
            } else {
                if (prev != NULL)
                {
                    prev->next = temp->next;
                    temp2 = first;

                    while (temp2 != NULL)
                    {
                        if (temp2->present == "coal")
                        {
                            if (temp2->next == NULL)
                            {
                                temp2->next = temp;
                                temp->next = NULL;
                                break;
                            }
                        } else if (temp2->next == NULL)
                        {
                           temp2->next = temp;
                           temp->next = NULL;
                           break;
                        }
                        temp2 = temp2->next;
                    }
                } else {
                    flag = temp->next;

                    temp2 = flag;

                    while (temp2 != NULL)
                    {
                        if (temp2->present == "coal")
                        {
                            if (temp2->next == NULL)
                            {
                                temp2->next = temp;
                                temp->next = NULL;
                                break;
                            }
                        } else if (temp2->next == NULL)
                        {
                            temp2->next = temp;
                            temp->next = NULL;
                           break;
                        }

                        temp2 = temp2->next;
                    }

                    first = flag;
                    break;
                }
            }
        }

        prev = temp;
        temp = temp->next;
    }

}

int main(void)
{
    std::string command, name, gift;
    int n;

    SantaList giftList;

    giftList.create();

    while (std::cin >> command && command != "End")
    {

        if (command == "SantaList")
        {
            std::cin >> n;
            while (n--)
            {
                std::cin >> name;
                std::cin >> gift;
                giftList.insertNormal(name, gift);
            }
        } else if (command == "AppendList")
        {
            std::cin >> n;
            while (n--)
            {
                std::cin >> name;
                std::cin >> gift;
                giftList.insertAppend(name, gift);
            }

        } else if (command == "NaughtyKid")
        {
            std::cin >> n;
            while (n--)
            {
                std::cin >> name;
                giftList.naughtyKid(name);
            }
        }
    }

    if (giftList.isEmpty())
    {
        std::cout << "Empty" << std::endl;
    } else {
        std::cout << "SantaFinalList" << std::endl;
        giftList.show();
        std::cout << std::endl;
    }


    return 0;
}
