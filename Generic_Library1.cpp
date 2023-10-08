#include<iostream>
using namespace std;


///////////////////////////////////////////////////////

//Structure for singly linear and singly circular

/////////////////////////////////////////////////////////
template <class T>
struct NodeS               //use both singly linear and singly circular
{
    T data;
    struct NodeS *next;
};

///////////////////////////////////////////////////////

//Structure for singly linear and singly circular

///////////////////////////////////////////////////////
template <class T>
struct NodeD              
{
    T data;
    struct NodeD *next;
    struct NodeD *prev;
};

///////////////////////////////////////////////////////

//Class of singly linear linked list

///////////////////////////////////////////////////////

template <class T>
class SinglyLL
{
    public:
        struct NodeS<T> *first;
        int iCount;

    SinglyLL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    T Summation();
    T Maximum();
    T Minimum();
    int SearchFirstOcc(T);
    int SearchLastOcc(T);
    int CountFreq(T);


};

template <class T>
SinglyLL<T> :: SinglyLL()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T> :: Display()
{
    cout<<"Elements of Singly Linear Linked List are: "<<"\n";

    NodeS<T> *temp = first;

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|-> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<"\n";
}

template <class T>
int SinglyLL<T> :: Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T> ::  InsertFirst(T no)
{
    NodeS<T> *newn = new NodeS<T>;

    newn -> data = no;
    newn -> next = NULL;

    if(first==NULL)        //LL is empty
    {
        first = newn;
    }

    else
    {
        newn -> next = first;
        first = newn;
    }

    iCount++;
}

template <class T>
void SinglyLL<T> ::  InsertLast(T no)
{
    NodeS<T> *newn = new NodeS<T>;

    newn -> data = no;
    newn -> next = NULL;

    if(first==NULL)             //LL is empty
    {
        first = newn;
    }

    else
    {
        NodeS<T> *temp = first;

        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T> ::  DeleteFirst()
{
    if(first == NULL)           //LL is empty
    {
        return;
    }

    else if(first -> next == NULL)        //LL contain one node
    {
        delete first;
        first = NULL;
    }

    else
    {
        NodeS<T> *temp = first;          

        first = first -> next;
        delete temp;
    }
    iCount--;

}

template <class T>
void SinglyLL<T> ::  DeleteLast()
{
    if(first == NULL)           //LL is empty
    {
        return;
    }

    else if(first -> next == NULL)        //LL contain one node
    {
        delete first;
        first = NULL;
    }

    else
    {
        NodeS<T> *temp = first;          

        while( temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        delete temp -> next;
        temp -> next = NULL;
    }
    iCount--;

}

template <class T>
void SinglyLL<T> ::  InsertAtPos(T no, int iPos)
{
    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }

    else if(iPos == iCount+1)
    {
        InsertLast(no);
    }

    else
    {
        NodeS<T> *temp = first;
        NodeS<T> *newn = new NodeS<T>;

        newn -> data = no;
        newn -> next = NULL;

        for(int iCnt=0; iCnt < iPos-1; iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next = newn;

        iCount++;
    }
}

template <class T>
void SinglyLL<T> ::  DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }

    else if(iPos == iCount)
    {
        DeleteLast();
    }

    else
    {
        NodeS<T> *temp = first;
        NodeS<T> *tempX = first;

        for(int iCnt=0; iCnt < iPos-1; iCnt++)
        {
            temp = temp -> next;
        }

        tempX = temp -> next -> next;
        delete temp -> next;
        temp -> next = tempX;

        iCount--;
    }
}

template <class T>
T SinglyLL<T> :: Summation()
{
    T iSum = 0;

    while(first != NULL)
    {
        iSum = iSum + (first -> data);
        first = first -> next;
    }
    return iSum;
    
}

template <class T>
T SinglyLL<T> :: Maximum()
{
    T iMax= 0;

    if(first == NULL)
    {
        return -1;
    }

    iMax = first -> data;

    while(first != NULL)
    {
        if((first -> data) > iMax)
        {
            iMax = first -> data;
        }

        first = first -> next;
    }
    return iMax;
}

template <class T>
int SinglyLL<T> :: SearchFirstOcc(T no)
{
    int iCnt=1;
    while(first != NULL)
    {
        if((first->data) == no)
        {
            break;
        }
        first = first->next;

        iCnt++;
    }

    return iCnt;

}

template <class T>
int SinglyLL<T> :: SearchLastOcc(T no)
{
    int iCnt=1;
    int iPos = -1;
    while(first != NULL)
    {
        if((first->data) == no)
        {
            iPos = iCnt;
        }
        first = first->next;

        iCnt++;
    }

    return iPos;

}

template <class T>
int SinglyLL<T> :: CountFreq(T no)
{
    int iCnt=1, iCount=0;
    while(first != NULL)
    {
        if((first->data) == no)
        {
            iCount++;
        }
        first = first->next;

        iCnt++;
    }

    return iCount;

}

///////////////////////////////////////////////////////

//Class of doubly linear linked list

///////////////////////////////////////////////////////

template <class T>
class DoublyLL
{
    public:
        struct NodeD<T> *first;
        struct NodeD<T> *last;
        int iCount;

    DoublyLL();

    void Display();
    int Count();

    void Insertfirst(T);
    void Insertlast(T);
    void InsertAtPos(T, int);

    void Deletefirst();
    void Deletelast();
    void DeleteAtPos(int);

    T Summation();
    T Maximum();
    T Minimum();
    int SearchFirstOcc(T);
    int SearchLastOcc(T);
    int CountFreq(T);
};

template <class T>
DoublyLL<T> :: DoublyLL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T> :: Display()
{
    cout<<"Elements of Doubly Linear Linked List are: "<<"\n";

    NodeD<T> *temp = first;

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|<=> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<"\n";

}

template <class T>
int DoublyLL<T> :: Count()
{
    return iCount;

}

template <class T>
void DoublyLL<T> ::  Insertfirst(T no)
{
    NodeD<T> *newn = new NodeD<T>;
    
    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }

    else
    {
        first -> prev = newn;
        newn -> next = first;
        first = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T> ::  Insertlast(T no)
{
    NodeD<T> *newn = new NodeD<T>;
    NodeD<T> *temp = first;
    
    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }

    else
    {
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
        newn -> prev = temp;   
    }
    iCount++;
}

template <class T>
void DoublyLL<T> ::  Deletefirst()
{
    if(first == NULL)
    {
        return;
    }

    else if((first) -> next == NULL)      
    {
        delete first;
        first = NULL;
    }

    else                               
    {
        first = first -> next;
        delete((first)->prev);           
        (first) -> prev = NULL;        
    }
    iCount--;
}

template <class T>
void DoublyLL<T> ::  Deletelast()
{
    NodeD<T> *temp = first;

    if(first == NULL)
    {
        return;
    }

    else if((first) -> next == NULL)      
    {
        delete first;
        first = NULL;
    }

    else                               
    {
        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }       

        delete (temp->next);
        temp -> next = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T> ::  InsertAtPos(T no, int iPos)
{
    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        Insertfirst(no);
    }

    else if(iPos == iCount+1)
    {
        Insertlast(no);
    }

    else
    {
        NodeD<T> *temp = first;
        NodeD<T> *newn = new NodeD<T>;

        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;

        for(int iCnt=1; iCnt < iPos-1; iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next -> prev = newn;

        temp -> next = newn;
        newn -> prev = temp;

        iCount++;
    }

}

template <class T>
void DoublyLL<T> ::  DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        Deletefirst();
    }

    else if(iPos == iCount)
    {
        Deletelast();
    }

    else
    {
        NodeD<T> *temp = first;

        for(int iCnt=1; iCnt < iPos-1; iCnt++)
        {
            temp = temp -> next;
        }

        temp -> next = temp -> next -> next;
        delete (temp -> next -> prev);
        temp -> next -> prev = temp;

        iCount--;
    }

}

template <class T>
T DoublyLL<T> :: Summation()
{
    T iSum = 0;

    while(first != NULL)
    {
        iSum = iSum + (first -> data);
        first = first -> next;
    }
    return iSum;
    
}

template <class T>
T DoublyLL<T> :: Maximum()
{
    T iMax= 0;

    if(first == NULL)
    {
        return -1;
    }

    iMax = first -> data;

    while(first != NULL)
    {
        if((first -> data) > iMax)
        {
            iMax = first -> data;
        }

        first = first -> next;
    }
    return iMax;
}

template <class T>
T DoublyLL<T> :: Minimum()
{
    T iMin= 0;

    if(first == NULL)
    {
        return -1;
    }

    iMin = first -> data;

    while(first != NULL)
    {
        if((first -> data) < iMin)
        {
            iMax = first -> data;
        }

        first = first -> next;
    }
    return iMin;
}

template <class T>
int DoublyLL<T> :: SearchFirstOcc(T no)
{
    int iCnt=1;
    while(first != NULL)
    {
        if((first->data) == no)
        {
            break;
        }
        first = first->next;

        iCnt++;
    }

    return iCnt;

}

template <class T>
int DoublyLL<T> :: SearchLastOcc(T no)
{
    int iCnt=1;
    int iPos = -1;
    while(first != NULL)
    {
        if((first->data) == no)
        {
            iPos = iCnt;
        }
        first = first->next;

        iCnt++;
    }

    return iPos;

}

template <class T>
int DoublyLL<T> :: CountFreq(T no)
{
    int iCnt=1, iCount=0;
    while(first != NULL)
    {
        if((first->data) == no)
        {
            iCount++;
        }
        first = first->next;

        iCnt++;
    }

    return iCount;

}

///////////////////////////////////////////////////////

//Class of doubly lineacircular linked list

///////////////////////////////////////////////////////

template <class T>
class DoublyCL
{
    public:
        struct NodeD<T> * first;
        struct NodeD<T> * last;
        int iCount;

    DoublyCL();

    void Display();
    int Count();
    
    void Insertfirst(T);
    void Insertlast(T);
    void InsertAtPos(T, int);
    
    void Deletefirst();
    void Deletelast();
    void DeleteAtPos(int);

    T Summation();
    T Maximum();
    T Minimum();
    int SearchFirstOcc(T);
    int SearchLastOcc(T);
    int CountFreq(T);
};

template <class T>
DoublyCL <T>::DoublyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
    cout<<"Elements of Doubly Circular Linked List are : "<<"\n";

    NodeD<T> *temp = first;

    if((first != NULL) && (last != NULL))
    {
        cout<<"<=> ";
        do
        {
            cout<<"|"<<temp->data<<"| <=>";
            temp=temp->next;
        } while (temp != last->next);

        cout<<"\n";
    }
    else
    {
        cout<<"LinkedList is empty";
    }
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::Insertfirst(T No)
{
    NodeD<T> *newn = new NodeD<T>;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    last->next = first;
    first->prev = last;
    iCount++;
}

template <class T>
void DoublyCL<T>::Insertlast(T No)
{
    NodeD<T> *newn = new NodeD<T>;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;
        last = newn;
    }
    last->next = first;
    first->prev = last;
    iCount++;
}

template <class T>
void DoublyCL<T>::Deletefirst()
{
    if(iCount == 0)
    {
        return;
    }
    else if(iCount == 1)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;

        first->prev = last;
        last->next = first;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::Deletelast()
{
    if(iCount == 0)
    {
        return;
    }
    else if(iCount == 1)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->prev;
        delete last->next;
        
        first->prev = last;
        last->next = first;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::InsertAtPos(T No, int iPos)
{
    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        Insertfirst(No);
    }
    else if(iPos == iCount+1)
    {
        Insertlast(No);
    }
    else
    {
        NodeD<T> *temp = first;

        NodeD<T> *newn = new NodeD<T>;
        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        Deletefirst();
    }
    else if(iPos == iCount)
    {
        Deletelast();
    }
    else
    {
        NodeD<T> *temp = first;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

template <class T>
T DoublyCL<T> :: Minimum()
{
    T iMin=0;
    NodeD<T> *temp = First;
    if(temp == NULL)
    {
        return -1;
    }
    iMin = temp->data;
    
    for(int iCnt=1;iCnt <= iCount;iCnt++)
    {
        if((temp->data) < iMin)
        {
            iMin=temp->data;
        }
        temp=temp->next;
    }
    return iMin;
}

template <class T>
T DoublyCL<T> :: Maximum()
{
    T iMax=0;
    NodeD<T> *temp =First;
    if(temp == NULL)
    {
        return -1;
    }
    iMax = temp->data;
    
    for(int iCnt=1;iCnt <= iCount;iCnt++)
    {
        if((temp->data) > iMax)
        {
            iMax=temp->data;
        }
        temp=temp->next;
    }
    return iMax;
}

template <class T>
T DoublyCL<T> :: Summation()
{
    T iSum=0;
    NodeD<T> *temp =First;
    for(int iCnt=1;iCnt <= iCount;iCnt++)
    {
        iSum=iSum + (temp->data);
        temp=temp->next;
    }
    return iSum;
}

template <class T>
int DoublyCL<T> :: SearchFirstOcc(T No)
{
    int iCnt = 1;
    NodeD<T> *temp = First;
    for(int iCnt=1;iCnt <= iCount;iCnt++)
    {
        if(temp->data == No)
        {
            break;
        }
        iCnt++;
        temp=temp->next;
    }
    return iCnt;
}
template <class T>
int DoublyCL<T> :: SearchLastOcc(T No)
{
    int iCnt = 1;
    int index = 0;
    NodeD<T> *temp = First;
    for(int iCnt=1;iCnt <= iCount;iCnt++)
    {
        if(temp->data == No)
        {
            index = iCnt;
        }
        iCnt++;
        temp=temp->next;
    }
    return index;
}
template <class T>
int DoublyCL<T> :: CountFreq(T No)
{
    int Freq = 0;

    NodeD<T> *temp = First;
    for(int iCnt=1;iCnt <= iCount;iCnt++)
    {
        if(temp->data == No)
        {
            Freq++;
        }
        temp=temp->next;
    }
    return Freq;
}


///////////////////////////////////////////////////////

//Class of singly circular linked list

///////////////////////////////////////////////////////
template <class T>
class SinglyCL
{
    public:
        struct NodeS<T> * first;
        struct NodeS<T> * last;
        int iCount;

    SinglyCL();

    void Display();
    int Count();
    
    void Insertfirst(T);
    void Insertlast(T);
    void InsertAtPos(T, int);
    
    void Deletefirst();
    void Deletelast();
    void DeleteAtPos(int);

    T Summation();
    T Maximum();
    T Minimum();
    int SearchFirstOcc(T);
    int SearchLastOcc(T);
    int CountFreq(T);
};

template <class T>
SinglyCL <T>::SinglyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

template <class T>
void SinglyCL<T>::Display()
{
    cout<<"Elements of Singly Circular Linked List are : "<<"\n";

    NodeS<T> *temp = first;

    if((first != NULL) && (last != NULL))
    {
        cout<<"-> ";
        do
        {
            cout<<"|"<<temp->data<<"| -> ";
            temp = temp->next;
        }while(temp != last->next);

        cout<<"\n";
    }
    else
    {
        cout<<"Linked List is empty\n";
    }
}

template <class T>
int SinglyCL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyCL<T>::Insertfirst(T No)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    last->next = first;
    iCount++;
}

template <class T>
void SinglyCL<T>::Insertlast(T No)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        last = newn;
    }
    last->next = first;
    iCount++;
}

template <class T>
void SinglyCL<T>::Deletefirst()
{
    if(iCount == 0)
    {
        return;
    }
    else if(iCount == 1)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;

        last->next = first;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>::Deletelast()
{
    if(iCount == 0)
    {
        return;
    }
    else if(iCount == 1)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        while(temp->next != last)
        {
            temp = temp->next;
        }
        last = temp;
        delete (temp->next);
        
        last->next = first;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T no, int iPos)
{
    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        Insertfirst(no);
    }
    else if(iPos == iCount+1)
    {
        Insertlast(no);
    }
    else
    {
        NodeS<T> *temp = first;
        NodeS<T> *newn = new NodeS<T>;

        newn->data = no;
        newn->next = NULL;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        Deletefirst();
    }
    else if(iPos == iCount)
    {
        Deletelast();
    }
    else
    {
        NodeS<T> *temp = first;
        NodeS<T> *tempX = NULL;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        tempX = temp->next;
        temp->next = temp->next->next;
        delete tempX;
        
        iCount--;
    }
}

template <class T>
T SinglyCL<T> :: Minimum()
{
    T iMin=0;
    NodeS<T> *temp = first;
    if(temp == NULL)
    {
        return -1;
    }

    iMin = temp->data;

    do{
        if((temp->data) < iMin)
        {
            iMin=temp->data;
        }
        temp=temp->next;
    }while(temp != last->next);

    return iMin;
}

template <class T>
T SinglyCL<T> :: Maximum()
{
    T iMax=0;
    NodeS<T> *temp = first;
    if(temp == NULL)
    {
        return -1;
    }

    iMax = temp->data;

    do{
        if((temp->data) < iMax)
        {
            iMax=temp->data;
        }
        temp=temp->next;
    }while(temp != last->next);

    return iMax;
}

template <class T>
T SinglyCL<T> :: Summation()
{
    T iSum=0;
    NodeS<T> *temp =first;
    do{
        iSum=iSum + (temp->data);
        temp=temp->next;
    }while(temp != last->next);
   
    return iSum;
}

template <class T>
int SinglyCL<T> :: SearchFirstOcc(T No)
{
    int iCnt = 1;
    NodeS<T> *temp = first;
    do{
        if(temp->data == No)
        {
            break;
        }
        iCnt++;
        temp=temp->next;
    }while(temp != last->next);
    return iCnt;
}

template <class T>
int SinglyCL<T> :: SearchLastOcc(T No)
{
    int iCnt = 1;
    int index = 0;
    NodeS<T> *temp = first;
    do{
        if(temp->data == No)
        {
            index = iCnt;
        }
        iCnt++;
        temp=temp->next;
    }while(temp != last->next);

    return index;
}

template <class T>
int SinglyCL<T> :: CountFreq(T No)
{
    int iCnt = 0;

    NodeS<T> *temp = first;
    do
    {
        if(temp->data == No)
        {
            iCnt++;
        }
        temp=temp->next;
    }while(temp != last->next);

    return iCnt;
}


////////////////////////////////////
// class for stack
////////////////////////////////////

template <class T>
class Stack
{
    public:
        struct NodeS<T> *first;
        int iCount;

    Stack();

    void Push(T);
    int Pop();

    void Display();
    int Count();
};

////////////////////////////
// functions of satck
///////////////////////////

template <class T>
Stack<T> :: Stack()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void Stack<T> :: Push(T no)   
{
    NodeS<T> *newn = new NodeS<T>;

    newn -> data = no;
    newn -> next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeS<T>  *temp = first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iCount++;
}

template <class T>
int Stack<T> :: Pop()            //Deletelast
{
    int Value = 0;

    if(iCount == 0)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    else if(iCount == 1)
    {
        Value = first -> data;
        delete first;
        first = NULL;
    }

    else
    {
        NodeS<T> *temp = first;
        
        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        Value = temp-> next -> data;
        delete temp -> next;
        temp -> next = NULL;
    }

    iCount--;

    return Value;

}          

template <class T>
void Stack<T> ::  Display()
{
    if(first == NULL)
    {
        cout<<"Nothing to display as stack is empty\n";
        return;
    }

    cout<<"Elements of stack are: \n";

    NodeS<T> *temp = first;

    for(int iCnt =1; iCnt <= iCount ;iCnt++)
    {
        cout<<temp->data<<"\n";
        temp = temp -> next;
    }
}

template <class T>
int Stack<T> :: Count()
{
    return iCount;
}

///////////////////////////
// class of Queue
///////////////////////////

template <class T>
class Queue
{
    public:
        struct NodeS<T> *first;
        int iCount;

    Queue();

    void Enqueue(T);
    int Dequeue();

    void Display();
    int Count();
};

////////////////////////////////
// function for queue
///////////////////////////////

template <class T>
Queue<T> :: Queue()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void Queue<T> :: Enqueue(T no)   
{
    NodeS<T> *newn = new NodeS<T>;

    newn -> data = no;
    newn -> next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeS<T>  *temp = first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iCount++;
}

template <class T>
int Queue<T> :: Dequeue()            //Deletelast
{
    int Value = 0;

    if(iCount == 0)
    {
        cout<<"Queue is empty\n";
        return -1;
    }

    else if(iCount == 1)
    {
        Value = first -> data;
        delete first;
        first = NULL;
    }

    else
    {
        Value = first -> data;
        NodeS<T> *temp = first;
        first = first -> next;
        delete temp;
    }

    iCount--;

    return Value;

}          

template <class T>
void Queue<T> ::  Display()
{
    if(first == NULL)
    {
        cout<<"Nothing to display as queue is empty\n";
        return;
    }

    cout<<"Elements of queue are: \n";

    NodeS<T> *temp = first;

    for(int iCnt =1; iCnt <= iCount ;iCnt++)
    {
        cout<<temp->data<<"\n";
        temp = temp -> next;
    }
}

template <class T>
int Queue<T> :: Count()
{
    return iCount;
}

///////////////////////////////////
// class for array 
///////////////////////////////////

template <class T>
class ArrayX
{
    public:
        T *Arr;
        int  iSize;

        ArrayX(int);
        ~ArrayX();
        void Accept();
        void Display();
        bool LinearSearch(T);
        bool BiDirectionalSearch(T);
        bool BinarySearch(T);
        bool CheckSorted();
        void BubbleSort();
        void BubbleSortEfficient();
        void SelectionSort();
        void InsertionSort();
};

template <class T>
ArrayX<T> :: ArrayX(int iNo)
{
    this->iSize = iNo;
    this->Arr = new T[iSize];
}

template <class T>
ArrayX<T> :: ~ArrayX()
{
    delete []Arr;
}

template <class T>
void ArrayX<T> :: Accept()
{
    cout<<"Enter the elements of array: "<<"\n";

    for(int i=0; i<iSize; i++)
    {
        cin>>Arr[i];
    }
}

template <class T>
void ArrayX<T> :: Display()
{
    cout<<"The elements of array: "<<"\n";

    for(int i=0; i<iSize; i++)
    {
        cout<<Arr[i]<<"\t";
    }
    cout<<"\n";
}

//////////////////////////////////////////////
// function for linear search 
///////////////////////////////////////////////

template <class T>
bool ArrayX<T> :: LinearSearch(T No)
{
    bool flag = false;

    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        if(Arr[iCnt]==No)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

//////////////////////////////////////////////
// function for bidirectional search 
///////////////////////////////////////////////

template <class T>
bool ArrayX<T> :: BiDirectionalSearch(T No)
{
    bool flag = false;
    int iStart=0;
    int iEnd= iSize-1;

    while(iStart<=iEnd)
    {
        if((Arr[iStart]==No) || (Arr[iEnd] == No))
        {
            flag = true;
            break;
        }
        iStart++;
        iEnd--;
    }
    return flag;
}

//////////////////////////////////////////////
// function for binary search 
///////////////////////////////////////////////

template <class T>
bool ArrayX<T> :: BinarySearch(T No)
{
    bool flag = false;

    int iStart = 0, iEnd=0, iMid=0;

    iStart=0;
    iEnd=iSize-1;

    while(iStart <= iEnd)
    {
        iMid = iStart + (iEnd - iStart) / 2;
        if((Arr[iMid] == No) || (Arr[iStart] == No) || (Arr[iEnd] == No))
        {
            flag = true;
            break;
        }
        else if(Arr[iMid] < No)
        {
            iStart = iMid + 1;
        }

        else if(Arr[iMid] > No)
        {
            iEnd = iMid - 1;
        }
    }
    return flag;
    
}

//////////////////////////////////////////////
// function for check sorted 
///////////////////////////////////////////////

template <class T>
bool ArrayX<T> :: CheckSorted()
{
    bool flag = true;

    for(int iCnt = 0; iCnt<iSize-1; iCnt++)
    {
        if(Arr[iCnt] <= Arr[iCnt+1])
        {
            continue;
        }
        else
        {
            flag = false;
            break;
        }
    }
    return flag;
}

//////////////////////////////////////////////
// function for bubble sort 
///////////////////////////////////////////////

template <class T>
void ArrayX<T> :: BubbleSort()
{
    T temp;

    for(int i=0; i < iSize; i++) //outer
    {
        for(int j=0; j < iSize-i-1; j++)   //inner
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }
    }

}

//////////////////////////////////////////////
// function for bubble efficient sort 
///////////////////////////////////////////////

template <class T>
void ArrayX<T> :: BubbleSortEfficient()
{
    T temp;
    bool flag = false;

    for(int i=0; i < iSize; i++) //outer
    {
        flag = false;

        for(int j=0; j < iSize-i-1; j++)   //inner
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                flag = true;
            }
        }

        if(flag == false)
        {
            break;
        }
    }
}

//////////////////////////////////////////////
// function for selection sort 
///////////////////////////////////////////////

template <class T>
void ArrayX<T> :: SelectionSort()
{
    int i = 0, j=0, min_index=0;
    T temp;

    for(i=0; i < iSize-1; i++)
    {
        min_index = i;
        
        for(j= i+1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }
        temp = Arr[i];
        Arr[i] = Arr[min_index];
        Arr[min_index] = temp;
    }
}

//////////////////////////////////////////////
// function for insertion sort 
///////////////////////////////////////////////

template <class T>
void ArrayX<T> :: InsertionSort()
{
    int i = 0, j=0;
    T selected;

    for(i=1; i < iSize; i++)
    {
        for(j = i-1, selected = Arr[i]; ((j >= 0) && (Arr[j] > selected)); j--)
        {
            Arr[j + 1] = Arr[j];
        }
        Arr[j + 1] = selected;
    }
}

int main()
{
    
    return 0;
}