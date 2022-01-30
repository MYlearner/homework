struct Listnode
{
    int val;
    struct Listnode *next;
    Listnode() : val(0), next(nullptr) {}
    Listnode(int v) : val(v), next(nullptr) {}
    Listnode(int v, struct Listnode *x) : val(v), next(x) {}
};
class MyLinkedList
{
    struct Listnode *head;
    int size;

public:
    /** Initialize your data structure here. */
    MyLinkedList()
    {
        head = new Listnode();
        size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if (index < 0 || index >= size)
            return -1;
        struct Listnode *trav = head;
        for (int i = 0; i < index + 1; ++i)
            trav = trav->next;
        return trav->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        struct Listnode *newNode = new struct Listnode(val);
        newNode->next = head->next;
        head->next = newNode;
        size += 1;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        struct Listnode *trav = head;
        for (int i = 0; i < size; ++i)
            trav = trav->next;
        trav->next = new struct Listnode(val);
        size += 1;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index < 0)
            addAtHead(val);
        else if (index == size)
            addAtTail(val);
        else if (index > size)
            return;
        else
        {
            struct Listnode *trav = head;
            for (int i = 0; i < index; ++i)
                trav = trav->next;
            struct Listnode *newNode = new struct Listnode(val);
            newNode->next = trav->next;
            trav->next = newNode;
            size += 1;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size || size == 0)
            return;
        struct Listnode *trav = head;
        struct Listnode *del = nullptr;
        for (int i = 0; i < index; i++)
            trav = trav->next;
        del = trav->next;
        trav->next = del->next;
        delete del;
        size -= 1;
    }
};
