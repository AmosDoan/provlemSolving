#include <iostream>

using namespace std;

template<typename T>
T getMax(T a, T b)
{
    return (a > b? a : b);
}

template<typename T>
class Node
{
    public :
        Node(T value) : value_(value), left_(nullptr), right_(nullptr)
        {
        }

        ~Node()
        {
            cout << "Destructor : " << value_ << endl;
            delete left_;
            delete right_;
        }

        T& getValue() 
        {
            return value_;
        }

        Node *getLeft() const
        {
            return left_;
        }

        Node *getRight() const
        {
            return right_;
        }

        void setLeft(Node *ptr)
        {
            this->left_ = ptr;
        }
        
        void setRight(Node *ptr)
        {
            this->right_ = ptr;
        }

    private :
        T value_;
        Node<T> *left_, *right_;
};

template<typename T>
class Tree 
{
    public :
        Tree(T root) : root_(root)
        {
        }

        ~Tree()
        {
        }

        void addNode(T value);
        void preOrderTraversal();
        void postOrderTraversal();
        void inOrderTraversal();
        void getTreeHeight();
        void searchTree(T value);

    private :
        bool isEmpty();
        void searchTree(T value, Node<T> *node);
        int getTreeHeight(Node<T> *node);
        void preOrderTraversal(Node<T> *node);
        void postOrderTraversal(Node<T> *node);
        void inOrderTraversal(Node<T> *node);
        Node<T> root_;
};

template<typename T>
void Tree<T>::addNode(T value)
{
    Node<T> *tmp = &root_;

    while(tmp)
    {
        T tmp_value = tmp->getValue();
        if(value < tmp_value)
        {
            if(tmp->getLeft())
                tmp = tmp->getLeft();
            else
            {
                Node<T> *new_node = new Node<T>(value);
                tmp->setLeft(new_node);
                break;
            }
        }
        else
        {
           if(tmp->getRight())
               tmp = tmp->getRight();
           else
           {
                Node<T> *new_node = new Node<T>(value);
                tmp->setRight(new_node);
                break;
           }
        }
    }
}

template<typename T>
void Tree<T>::getTreeHeight()
{
    cout << "Height : " << getTreeHeight(&root_) << endl;
}

template<typename T>
int Tree<T>::getTreeHeight(Node<T> *node)
{
    if(!node)
        return 0;

    return 1 + getMax(getTreeHeight(node->getLeft()),
                  getTreeHeight(node->getRight()));
}

// Pre-Order Traversal
template<typename T>
void Tree<T>::preOrderTraversal()
{
    Node<T> *ptr = &root_;
    preOrderTraversal(ptr);
}

template<typename T>
void Tree<T>::preOrderTraversal(Node<T> *node)
{
    if(!node)
        return;

    cout << node->getValue() << endl;
    preOrderTraversal(node->getLeft());
    preOrderTraversal(node->getRight());
}

// Post-Order Traversal
template<typename T>
void Tree<T>::postOrderTraversal()
{
    Node<T> *ptr = &root_;
    postOrderTraversal(ptr);
}

template<typename T>
void Tree<T>::postOrderTraversal(Node<T> *node)
{
    if(!node)
        return;

    postOrderTraversal(node->getLeft());
    postOrderTraversal(node->getRight());
    cout << node->getValue() << endl;
}

// In-Order Traversal
template<typename T>
void Tree<T>::inOrderTraversal()
{
    Node<T> *ptr = &root_;
    inOrderTraversal(ptr);
}

template<typename T>
void Tree<T>::inOrderTraversal(Node<T> *node)
{
    if(!node)
        return;

    inOrderTraversal(node->getLeft());
    cout << node->getValue() << endl;
    inOrderTraversal(node->getRight());
}

template<typename T>
bool Tree<T>::isEmpty()
{
    Node<T>* ptr = &root_;

    if(!ptr)
        return false;
    else
        return true;
}

template<typename T>
void Tree<T>::searchTree(T value)
{
    Node<T> *ptr = &root_;
    if(!isEmpty())
    {
        cout << "Tree is Empty!" << endl;
        return;
    }

    searchTree(value, ptr);
}

template<typename T>
void Tree<T>::searchTree(T value, Node<T> *node)
{
    if(!node)
    {
        cout << "value is not found" << endl;
        return;
    }

    if(value == node->getValue())
        cout << "value is exist!" << endl;
    else if(value < node->getValue())
        searchTree(value, node->getLeft());
    else
        searchTree(value, node->getRight());
}

int main()
{
    Tree<int> t(100);
    t.addNode(50);
    t.addNode(25);
    t.addNode(75);
    t.addNode(150);
    t.addNode(125);
    t.addNode(175);
    t.addNode(110);

    cout << "PreOrder ! " << endl;
    t.preOrderTraversal();
    
    cout << "PostOrder ! " << endl;
    t.postOrderTraversal();

    cout << "InOrder ! " << endl;
    t.inOrderTraversal();

    cout << "Height ! " << endl;
    t.getTreeHeight();

    t.searchTree(50);
    t.searchTree(26);

    return 0;
}
