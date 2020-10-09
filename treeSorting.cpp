#include <vector>
#include <iostream>
using namespace std;

struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
};

struct Node *newnode(int key)
{
  struct Node *temp=new Node;
  temp->data=key;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}

Node* insert(Node *node,int key)
{
  if(node==NULL) return newnode(key);

  if(key < node->data)
    node->left=insert(node->left,key);
  else
    node->right=insert(node->right,key);
  return node;
}

void store(Node *root,int a[],int &i)
{
  if(root!=NULL)
  {
    store(root->left,a,i);
    a[i++]=root->data;
    store(root->right,a,i);
  }
}
void TreeSort(vector<int>& a)
{
    struct Node *root = NULL;

    root = insert(root, a[0]);
    for (int i=1; i<a.size(); i++)
    {
        insert(root, a[i]);    }
    int i = 0;
    store(root, a.data() , i);
    
}
int main()
{ 
    vector<int> a{9,16,54,43,10,32,25};
    cout<<"Before Sorting:"<<endl;
    for(int i=0;i<a.size();i++)
    {
        cout << a[i] << " ";
    }
    
    TreeSort(a);
    cout<<endl<<"After Sorting:"<<endl;
    for(int i=0;i<a.size();i++)
    {
        cout << a[i]<< " ";
    }
    return 0;
}