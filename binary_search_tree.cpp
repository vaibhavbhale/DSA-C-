#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

class BST{
   public:
   Node* data;
   Node* root;
   BST():root(nullptr){}

   void create(){
    int n,value;
    cout<<"Enter no. of nodes:";
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        cout<<"Enter the keys:";
        cin>>value;
        Node* newNode=newNode;
        newNode->data=value;
        newNode->left=nullptr;
        newNode->right=nullptr;

        if(root==nullptr)
        {
            root=newNode;  
        }
         else
        {
            Node* temp=root;
            while(true)
            {
                if(value < temp->data)
                {
                    if(temp->left==nullptr)
                    {
                        temp->left=newNode;
                        break;
                    }
                    else
                    {
                        temp=temp->left;
                    }
                }
                else
                {
                     if(temp->right=nullptr)
                    {
                        temp->right=newNode;
                        break;
                    }
                    else
                    {
                        temp=temp->right;
                    }
                }
            }
        }
    }
      cout<<"tree created";  
  }
     void inorder(Node* root)
    {
        if(root==nullptr){
            return;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

     void display()
     {
        if(root==nullptr){
            return;
        }
        else{
            cout<<"inorder traversal";
            inorder(root);
        }
     }

     void smallest()
     {
         if(root==nullptr){
            cout<<"Tree is empty";
            return;
         }
         Node* temp=root;
         while(temp->left!=nullptr){
            temp=temp->left;
         }
         cout<<"smallest value of the tree"<<temp->data;
     }

     bool search(Node* root,int value)
     {
         if(root==nullptr){
            return false;
         }
         if(root->data==value){
            return true;
         }
         if(value < root->data){
            search(root->left,value);
         }
         else{
            search(root->right,value);
         }
     }
      
     void swap(Node* root)
     {
          if(root==nullptr){
            return;
          }
          Node* temp;
          temp=root->left;
          root->left=root->right;
          root->right=temp;

          swap(root->left);
          swap(root->right);
    }
    
    void level(){
        Node* temp;
        queue<Node*>que;
        que.push(root);
        while(!que.empty()){
            temp=que.front();
            cout<<temp->data<<"";
            que.pop();
            
            if(temp->left!=nullptr){
                que.push(temp->left);
            }
             if(temp->right!=nullptr){
                 que.push(temp->right);
             }
          }
        
    }

    int height(Node* root)
    {
       if(root==nullptr){
        return 0;
       }
      int lheight=height(root->left);
      int rheight=height(root->right);
      return max(lheight,rheight)+1;
    }
};

 int main()
 {
    BST b;
    int ch,value;
   do{
    cout<<"Menu";
    cout<<"1.create binary search tree";
    cout<<"\n2.display tree";
    cout<<"\n3.minimum value in tree";
    cout<<"\n4.search value in tree";
    cout<<"\n5.swap value in tree";
    cout<<"\n6.height of tree";
    
    cout<<"\nEnter your choice:";
    cin>>ch;

    switch(ch)
  {
    case 1:b.create();
           break;
    
    case 2:b.display();
           break;

    case 3:b.smallest();
           break;
          
    case 4: cout<<"Enter the value to search";
            cin>>value;
            b.search(b.root,value);
            if(b.search(b.root,value))
            {
                cout<<"value:"<<value<<"found in a tree"<<endl;
            }
            else{
                cout<<"value:"<<value<<" not found in tree"<<endl;
            }
            break;
    
    case 5:cout<<"height of the tree:"<<b.height(b.root);
           break;
           
    case 6:b.swap(b.root);
            cout<<"tree nodes after swapped:";
            cout<<"level order traversal:";
            b.level();
            break;
    
    case 7:exit(0);
    default:cout<<"invalid choice"<<endl;
  }
 }while(ch!=7);
    return 0;
}