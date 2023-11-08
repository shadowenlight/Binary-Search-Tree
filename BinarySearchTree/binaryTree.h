//Header File Binary Search Tree
#ifndef H_binaryTree
#define H_binaryTree

#include <iostream>

using namespace std;

//Definition of the Node
template <class elemType>
struct nodeType
{
    elemType info;
    nodeType<elemType>* lLink;
    nodeType<elemType>* rLink;
};

//Definition of the class
template <class elemType>
class binaryTreeType
{
public:
    const binaryTreeType<elemType>& operator=(const binaryTreeType<elemType>&);
    bool isEmpty() const;
    void inorderTraversal() const;
    void preorderTraversal() const;
    void postorderTraversal() const;
    int treeHeight() const;
    int treeNodeCount() const;
    void destroyTree();
    //For Questions:
    int treeLeavesCount() const;
    void treeSwapSubtrees();
    void treeSwapSubtreesOfNode(nodeType<elemType>* node);
    int treeSingleParent() const;
    int treeSingleP() const;
    int treeLargest() const;
    //end
    virtual bool search(const elemType& searchItem) const = 0;
    virtual void insert(const elemType& insertItem) = 0;
    virtual void deleteNode(const elemType& deleteItem) = 0;
    binaryTreeType(const binaryTreeType<elemType>& otherTree);
    binaryTreeType();
    ~binaryTreeType();

protected:
    nodeType<elemType>* root;

private:
    void copyTree(nodeType<elemType>*& copiedTreeRoot, nodeType<elemType>* otherTreeRoot);

    void destroy(nodeType<elemType>*& p);
    void inorder(nodeType<elemType>* p) const;
    void preorder(nodeType<elemType>* p) const;
    void postorder(nodeType<elemType>* p) const;
    int height(nodeType<elemType>* p) const;
    int max(int x, int y) const;
    int nodeCount(nodeType<elemType>* p) const;
    //For Questions:
    int leavesCount(nodeType<elemType>* p) const;
    void swapSubtrees(nodeType<elemType>* p);
    void swapSubtreesOfNode(nodeType<elemType>* p);
    int singleParent(nodeType<elemType>* p) const;
    int singleP(nodeType<elemType>* p) const;
    int largest(nodeType<elemType>* p) const;
    //end
};

//Definition of member functions

template <class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
    root = NULL;
}

template <class elemType>
bool binaryTreeType<elemType>::isEmpty() const
{
    return (root == NULL);
}

template <class elemType>
void binaryTreeType<elemType>::inorderTraversal() const
{
    inorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::preorderTraversal() const
{
    preorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::postorderTraversal() const
{
    postorder(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeHeight() const
{
    return height(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeNodeCount() const
{
    return nodeCount(root);
}

//For Questions:

template <class elemType>
int binaryTreeType<elemType>::treeLeavesCount() const
{
    return leavesCount(root);
}
template <class elemType>
void binaryTreeType<elemType>::treeSwapSubtrees()
{
    return swapSubtrees(root);
}
template <class elemType>
void binaryTreeType<elemType>::treeSwapSubtreesOfNode(nodeType<elemType> *node)
{
    return swapSubtreesOfNode(node);
}
template <class elemType>
int binaryTreeType<elemType>::treeSingleParent() const
{
    return singleParent(root);
}
template <class elemType>
int binaryTreeType<elemType>::treeSingleP() const
{
    return singleP(root);
}
template <class elemType>
int binaryTreeType<elemType>::treeLargest() const
{
    return largest(root);
}
//end


template <class elemType>
void  binaryTreeType<elemType>::copyTree
(nodeType<elemType>*& copiedTreeRoot,
    nodeType<elemType>* otherTreeRoot)
{
    if (otherTreeRoot == NULL)
        copiedTreeRoot = NULL;
    else
    {
        copiedTreeRoot = new nodeType<elemType>;
        copiedTreeRoot->info = otherTreeRoot->info;
        copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
        copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
    }
} //end copyTree

template <class elemType>
void binaryTreeType<elemType>::inorder
(nodeType<elemType>* p) const
{
    if (p != NULL)
    {
        inorder(p->lLink);
        cout << p->info << " ";
        inorder(p->rLink);
    }
}

template <class elemType>
void binaryTreeType<elemType>::preorder
(nodeType<elemType>* p) const
{
    if (p != NULL)
    {
        cout << p->info << " ";
        preorder(p->lLink);
        preorder(p->rLink);
    }
}

template <class elemType>
void binaryTreeType<elemType>::postorder
(nodeType<elemType>* p) const
{
    if (p != NULL)
    {
        postorder(p->lLink);
        postorder(p->rLink);
        cout << p->info << " ";
    }
}

//Overload the assignment operator
template <class elemType>
const binaryTreeType<elemType>& binaryTreeType<elemType>::
operator=(const binaryTreeType<elemType>& otherTree)
{
    if (this != &otherTree) //avoid self-copy
    {
        if (root != NULL)   //if the binary tree is not empty,
            //destroy the binary tree
            destroy(root);

        if (otherTree.root == NULL) //otherTree is empty
            root = NULL;
        else
            copyTree(root, otherTree.root);
    }//end else

    return *this;
}

template <class elemType>
void  binaryTreeType<elemType>::destroy(nodeType<elemType>*& p)
{
    if (p != NULL)
    {
        destroy(p->lLink);
        destroy(p->rLink);
        delete p;
        p = NULL;
    }
}

template <class elemType>
void  binaryTreeType<elemType>::destroyTree()
{
    destroy(root);
}

//copy constructor
template <class elemType>
binaryTreeType<elemType>::binaryTreeType
(const binaryTreeType<elemType>& otherTree)
{
    if (otherTree.root == NULL) //otherTree is empty
        root = NULL;
    else
        copyTree(root, otherTree.root);
}

//Destructor
template <class elemType>
binaryTreeType<elemType>::~binaryTreeType()
{
    destroy(root);
}

template<class elemType>
int binaryTreeType<elemType>::height
(nodeType<elemType>* p) const
{
    if (p == NULL)
        return 0;
    else
        return 1 + max(height(p->lLink), height(p->rLink));
}

template <class elemType>
int binaryTreeType<elemType>::max(int x, int y) const
{
    if (x >= y)
        return x;
    else
        return y;
}

template<class elemType>
int binaryTreeType<elemType>::nodeCount(nodeType<elemType>* p) const
{
    if (p == NULL)
        return 0;
    else
        return 1 + nodeCount(p->lLink) + nodeCount(p->rLink);
}

template<class elemType>
int binaryTreeType<elemType>::leavesCount(nodeType<elemType>* p) const {
    int leaf = 0;
    if (p == nullptr)
        return 0;

    
    if ((p->lLink == nullptr) && (p->rLink == nullptr))
        leaf = 1;
    return leaf + leavesCount(p->lLink) + leavesCount(p->rLink);
}

template<class elemType>
void binaryTreeType<elemType>::swapSubtrees(nodeType<elemType>* p) {
    if (root == NULL)
        exit (0);
    
    nodeType<elemType>* nodeTemp = nullptr;

    if (p->lLink != NULL)
        swapSubtrees(p->lLink);
    if (p->rLink != NULL)
        swapSubtrees(p->rLink);

    nodeTemp = p->lLink;
    p->lLink = p->rLink;
    p->rLink = nodeTemp;    
}

template<class elemType>
void binaryTreeType<elemType>::swapSubtreesOfNode(nodeType<elemType>* p) {
    if (p == NULL)
        exit(0);

    nodeType<elemType>* nodeTemp = nullptr;

    if (p->lLink != NULL)
        swapSubtrees(p->lLink);
    if (p->rLink != NULL)
        swapSubtrees(p->rLink);

    nodeTemp = p->lLink;
    p->lLink = p->rLink;
    p->rLink = nodeTemp;
}

template<class elemType>
int binaryTreeType<elemType>::singleParent(nodeType<elemType>* p) const {
    int Sparent = 0;
    if (p == nullptr)
        return 0;
    
    if ((p->lLink != nullptr && p->rLink == nullptr) || (p->lLink == nullptr && p->rLink != nullptr))
        Sparent = 1;

    return Sparent + singleParent(p->lLink) + singleParent(p->rLink);
}

template<class elemType>
int binaryTreeType<elemType>::largest(nodeType<elemType>* p) const {

    while (p->lLink != nullptr || p->rLink != nullptr)
        p = p->rLink;

    return p->info;
}


#endif