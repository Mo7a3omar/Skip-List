#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#define MAX_LEVEL 5
const float P = 0.5;
using namespace std;

struct Node
{
    int value;
    Node **ptr;
    Node(int level, int &value)
    {
        ptr = new Node * [level + 1];
        memset(ptr, 0, sizeof(Node*) * (level + 1));
        this->value = value; 
    }
    ~Node()
    {
        delete [] ptr;        
    } 
};

struct skipList
{
    Node *header;
    int value;
    int level;
    skipList() 
    {
        header = new Node(MAX_LEVEL, value);
        level = 0;
    }
    ~skipList() 
    {
        delete header;
    }
    void display();
    bool search(int &);
    void insert(int &);
    void delete_node(int &);        
};


float fraction() 
{
    return (float) rand() / RAND_MAX;
}
 

int random() 
{
    static bool first = true;
    if (first) 
    {
        srand((unsigned)time(NULL));
        first = false;
    }
    int lvl = (int)(log(fraction()) / log(1.-P));
    return lvl < MAX_LEVEL ? lvl : MAX_LEVEL;
}
 
void skipList::insert(int &value) 
{
    Node *x = header;	
    Node *update[MAX_LEVEL + 1];
    memset(update, 0, sizeof(Node*) * (MAX_LEVEL + 1));
    for (int i = level;i >= 0;i--) 
    {
        while (x->ptr[i] != NULL && x->ptr[i]->value < value) 
        {
            x = x->ptr[i];
        }
        update[i] = x; 
    }
    x = x->ptr[0];
    if (x == NULL || x->value != value) 
    {        
        int lvl = random();
        if (lvl > level) 
        {
            for (int i = level + 1;i <= lvl;i++) 
            {
                update[i] = header;
            }
            level = lvl;
        }
        x = new Node(lvl, value);
        for (int i = 0;i <= lvl;i++) 
        {
            x->ptr[i] = update[i]->ptr[i];
            update[i]->ptr[i] = x;
        }
    }
}

void skipList::delete_node(int &value) 
{
    Node *x = header;	
    Node *update[MAX_LEVEL + 1];
    memset (update, 0, sizeof(Node*) * (MAX_LEVEL + 1));
    for (int i = level;i >= 0;i--) 
    {
        while (x->ptr[i] != NULL && x->ptr[i]->value < value)
        {
            x = x->ptr[i];
        }
        update[i] = x; 
    }
    x = x->ptr[0];
    if (x->value == value) 
    {
        for (int i = 0;i <= level;i++) 
        {
            if (update[i]->ptr[i] != x)
                break;
            update[i]->ptr[i] = x->ptr[i];
        }
        delete x;
        while (level > 0 && header->ptr[level] == NULL) 
        {
            level--;
        }
    }
}
 
void skipList::display() 
{
    const Node *x = header->ptr[0];
    while (x != NULL) 
    {
        cout << x->value;
        x = x->ptr[0];
        if (x != NULL)
            cout << " - ";
    }
    cout <<endl;
}
 

bool skipList::search(int &s_value) 
{
    Node *x = header;
    for (int i = level;i >= 0;i--) 
    {
        while (x->ptr[i] != NULL && x->ptr[i]->value < s_value)
        {
            x = x->ptr[i];
        }
    }
    x = x->ptr[0];
    return x != NULL && x->value == s_value;
}


int main() 
{
    skipList skiplist1;
    int n;
    skiplist1.insert(n = 55);
    skiplist1.insert(n = 3);
    skiplist1.insert(n = 66);
    skiplist1.insert(n = 2);
    skiplist1.insert(n = 99);
    skiplist1.insert(n = 2);
    skiplist1.insert(n = 6);
    skiplist1.insert(n = 11);
    skiplist1.insert(n = 23);
    skiplist1.insert(n = 97);
    skiplist1.display();
    skiplist1.delete_node(n = 66);
    skiplist1.display();
    return 0;
}