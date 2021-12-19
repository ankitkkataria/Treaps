#include <iostream>
#include <stack>
#include <string>
#include <cstdio>
#include <ctime>
# include <iomanip>
#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
using namespace std; 
int comparisons_bst=0, comparisons_bst_delete=0, comparisons_avl=0, comparisons_avl_delete=0, comparisons_treap=0,comparisons_treap_delete=0;
int  rotations_avl=0,rotations_treap=0;
class AVL_Node
{
	AVL_Node *left;
	int b; // balance factor = height(left subtree) - height(right subtree)
	int value;
	AVL_Node *right;
public:
	 AVL_Node(){

	 }
	 AVL_Node(int x){
	 	value = x;
	 	left = NULL;
	 	right = NULL;
	 	b = 0;
	 }
	~AVL_Node(){
		delete left;
		delete right;
	}
	friend class AVL_Tree;
    
};

class BstNode {
public :
	int data;
	BstNode *left;
	BstNode*right;

    BstNode()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
BstNode(int value)
    {
        data = value;
        left = right = NULL;
    }
    
};

class BST
 {
          public:
            BstNode* rootbst;
           BST()
                 {
                    rootbst = NULL;
                  }
          bool isTreeEmpty() 
          {
            if (rootbst == NULL) 
            {
              return true;
            } 
        else 
            {
              return false;
            }
          }
          
       void insert(int x);
        BstNode * iterativeSearch(BstNode*rootbst,int v);
       void  deleteNode(int key);
           int heightBst(BstNode* node);
        void avgheightBst();
       int totalheightBst(BstNode*node);
    
};

class AVL_Tree
{
    public:
	AVL_Node *rootavl;

	AVL_Tree()
    {
		rootavl = new AVL_Node();
		rootavl->left = NULL;

	}
	AVL_Tree(const AVL_Tree &T); 
 	AVL_Tree &operator=(const AVL_Tree &T);
	void AVL_Insert(int key);
	bool AVL_Search(int key);
	void AVL_Delete(int key);
    int heightAVL(AVL_Node* node);
    void avgheightAVL();
    int totalheightAVL(AVL_Node*node);  
	~AVL_Tree()
    {
		delete rootavl;
	}
};

int BST :: heightBst(BstNode* node)
{
     queue<BstNode*> nodesInLevel;
    int height = 0;
    int nodeCount = 0; // Calculate  number of nodes in a level.
    BstNode* currentNode; // Pointer to store the address of a
                       // node in the current level.
    if (node == NULL) {
        return 0;
    }
    nodesInLevel.push(node);
    while (!nodesInLevel.empty()) {
        // This while loop runs for every level and
        // increases the height by 1 in each iteration. If
        // the queue is empty then it implies that the last
        // level of tree has been parsed.
        height++;
         
        // Create another while loop which will insert all
        // the child nodes of the current level in the
        // queue.
  
        nodeCount = nodesInLevel.size();
        while (nodeCount--) {
            currentNode = nodesInLevel.front();
  
            // Check if the current nodes has left child and
            // insert it in the queue.
  
            if (currentNode->left != NULL) {
                nodesInLevel.push(currentNode->left);
               }
  
            // Check if the current nodes has right child
            // and insert it in the queue.
            if (currentNode->right != NULL) {
                nodesInLevel.push(currentNode->right);
            }
  
            // Once the children of the current node are
            // inserted. Delete the current node.
  
            nodesInLevel.pop();
        }
    }
return height;
}

class TreapNode // Declaring a class for the Nodes used used in our treap
{
   private :
	int data;  // This will contain the key values 
	int priority;  // This will contain the priority of that node 
	TreapNode* left; 
	TreapNode* right;

public: 
   TreapNode()
   {
   }
  
  	TreapNode (int key,int tempPriority) // making a two arg constructor for the Treapnode
    {
        data = key ; 
        priority = tempPriority;
        left = NULL;
        right = NULL;
    }  
    
    ~TreapNode ()
    {
        delete left;
        delete right;
    }
    
    friend class Treap;
 

};
 
 void  BST :: avgheightBst()
 {
     BstNode *node=rootbst;
    int totalnode=0;
    int totalheight=0;
    float avgheight=0.0;
    stack<BstNode*>walk;
    while(!walk.empty()||node!=NULL)
    {
        while(node!=NULL)
        {
            totalnode++;
            walk.push(node);
            node=node->left;
        }
      // now we start poping from stack
         node=walk.top();
         walk.pop();
        
          totalheight+=totalheightBst(node);
           node=node->right;
       }
     cout<<"Total no of nodes in Final bst\t"<<totalnode<<endl;  
     avgheight=(float)totalheight/totalnode;
     cout<<"Average height of Final bst is \t"<< avgheight<<endl;
 }

class Treap 
 {
public :
    TreapNode* roottreap;
   
    Treap()
    {  
        roottreap = new TreapNode(0,999999999);
    }
    
    void insert (int key, int priority);
    bool search (int key);
    void deleteNode(int key);
    int heightTreap(TreapNode*node);
    void averageheightTreap();
    int totalheightTreap(TreapNode*node);
    ~Treap ()
    {
        delete roottreap;
    }

 };
 
 int AVL_Tree::heightAVL(AVL_Node* node)
{
    
    queue<AVL_Node*> nodesInLevel;
    int height = 0;
    int nodeCount = 0; // Calculate  number of nodes in a level.
    AVL_Node* currentNode; // Pointer to store the address of a
                       // node in the current level.
    if (node == NULL) {
        return 0;
    }
    nodesInLevel.push(node);
    while (!nodesInLevel.empty()) {
        // This while loop runs for every level and
        // increases the height by 1 in each iteration. If
        // the queue is empty then it implies that the last
        // level of tree has been parsed.
        height++;
        // Create another while loop which will insert all
        // the child nodes of the current level in the
        // queue.
  
        nodeCount = nodesInLevel.size();
        while (nodeCount--) {
            currentNode = nodesInLevel.front();
  
            // Check if the current nodes has left child and
            // insert it in the queue.
  
            if (currentNode->left != NULL) {
                nodesInLevel.push(currentNode->left);
            }
  
            // Check if the current nodes has right child
            // and insert it in the queue.
            if (currentNode->right != NULL) {
                nodesInLevel.push(currentNode->right);
            }
  
            // Once the children of the current node are
            // inserted. Delete the current node.
  
            nodesInLevel.pop();
        }
    }
  return height;
}

void AVL_Tree::AVL_Insert(int key)
{
     
        AVL_Node *temp=new AVL_Node(key);
        AVL_Node *parImBal=rootavl;//here parImBal points to parent of ImBal
       //ImBal points to node that can have imbalance and and ImBaleft is child of ImBal which help in rotation 
       AVL_Node* ImBal=rootavl->right;
       AVL_Node* iterator=rootavl->right; 
       AVL_Node* ImBaleft;
         AVL_Node*q; 
     if(iterator==NULL)//if tree has no element then we insert the first element and return
      {
        rootavl->right=temp;   
           comparisons_avl=1;
          return;
        }   
   
        
        
    //this loop runs until we find the position to insert new node 
    while(true)
     {    
        if(key<iterator->value)
          {
             comparisons_avl++;    
            q=iterator->left;
          }
        else if(key>iterator->value)
          {
            comparisons_avl++;
            q=iterator->right;
           }
        else {
            return;
            } 
          
        if(q==NULL)  // iterator has reached the leaf 
        { 
            
            break;
        }
        else if(q->b!=0)   // here we will shift parImBal and ImBal
             {  
                  parImBal=iterator;
                  ImBal=q;
                  
                }
        
           iterator=q;   //iterator points to q
    }//end while
     
   // we have inserted new node at its correct position
    if(key<iterator->value)
       {
         iterator->left=temp;
         q=iterator->left;
       }
       
    else if(key>iterator->value)
        {
          iterator->right=temp;
          q=iterator->right;
        }

// now we will make a int variable a which will be -1 if insertion is done on right side of ImBal else it will be +1 if done  on left side of s
 int a;
 if(key<ImBal->value)
   a=1;
   else a=(-1);

    //now we will set the balance factor between ImBal and q
  
  if(a==1)
     {
        ImBaleft=ImBal->left;
        iterator=ImBal->left;
     }
     
    else if(a==(-1)) {
        ImBaleft=ImBal->right;
         iterator=ImBal->right;
    }

    
    // we will keep updating the balance factor of node from path q to ImBal and all those node has balance factor as 0 so we will either make them -1 or +1 
    while(iterator!=q) 
    {
       if(key< iterator->value)
        {  iterator->b=1;
           iterator=iterator->left;
          }  
          else if(key> iterator->value) {
            iterator->b=-1;
            iterator=iterator->right;
          }
          
    }
    // now we will balance the tree by checking if balancing is required or not
     if(ImBal->b==0) // if the balance factor of ImBal is 0 that means the height is increased by one depending on a value but there is no need of balancing 
     {
        //set the new balance factor of ImBal= a
        ImBal->b=a;
        return;
     }
     
     else if(ImBal->b==(-1*a))// means ImBalhas balance factor opposite to a means insertion will make ImBalbalance factor to 0
      {
        ImBal->b=0;
        return;
      }
      else 
       {//here we will see two cases one is single rotation and one is double rotation
          // for single rotatio we will use balance factor of r to check
           if(ImBaleft->b==a)
           {
            // now to check if it is LL or RR we will use value of a, if it is -1 then RR else LL
            if(a==1)//LL rotation
               {
                rotations_avl++;
                iterator=ImBaleft;
                ImBal->left=ImBaleft->right;
                ImBaleft->right=ImBal;
                ImBal->b=0;
                ImBaleft->b=0;
               }
               else if(a==-1)
               {//RR rotation
                   rotations_avl++;    
                    iterator=ImBaleft;
                    ImBal->right=ImBaleft->left;
                    ImBaleft->left=ImBal;
                    ImBal->b=0;
                    ImBaleft->b=0;
               }
           }
           //double rotation
           else{
                 if(a==1)//LR rotation
                 { 
                    rotations_avl++;
                    rotations_avl++;
                    iterator=ImBaleft->right;
                    ImBaleft->right=iterator->left;
                        iterator->left=ImBaleft;
                        ImBal->left=iterator->right;
                        iterator->right=ImBal;
                   
                   if(iterator->b==0)
                   { 
                         ImBal->b=0;
                          ImBaleft->b=0;
                      }
                     else if(iterator->b==1)
                     {
                        ImBal->b=-1;
                        ImBaleft->b=0;
                        iterator->b=0;
                      } 
                      else{
                        ImBal->b=0;
                        ImBaleft->b=1;
                         iterator->b=0;
                      }
                    }//LR end
            
                else if(a==-1) //RL rotation
                {
                    rotations_avl+=2;
                    iterator=ImBaleft->left;
                    ImBaleft->left=iterator->right;
                    iterator->right=ImBaleft;
                    ImBal->right=iterator->left;
                    iterator->left=ImBal;
                   if(iterator->b==0)
                   { 
                     ImBal->b=0;
                           ImBaleft->b=0;
                      }
                     else if(iterator->b==1)
                     {
                        ImBal->b=0;
                        ImBaleft->b=-1;
                        iterator->b=0;
                      } 
                      else{
                        ImBal->b=1;
                        ImBaleft->b=0;
                        iterator->b=0;
                      }
                   }//RL end
                   
           }//end of inner else
      }//end of else
        //after rotation set left and rhild of parent of s
    if(ImBal == parImBal->right) 
       parImBal->right = iterator;
    else parImBal->left = iterator;
    
}
void AVL_Tree :: avgheightAVL()
{
    AVL_Node *node=rootavl->right;
    int totalnode=0;
    int totalheight=0;
    float avgheight=0.0;
    stack<AVL_Node*>walk;
    while(!walk.empty()||node!=NULL)
    {
        while(node!=NULL)
        {
            totalnode++;
            walk.push(node);
            node=node->left;
        }
      // now we start poping from stack
         node=walk.top();
         totalheight+=totalheightAVL(node);
         walk.pop();
      node=node->right;
       }
     cout<<"Total nodes in Avl after insertion \t"<<totalnode<<endl;
      avgheight=(float)totalheight/totalnode;
     cout<<"Average height of Avl is\t "<<avgheight<<endl;
}
 
 int BST :: totalheightBst(BstNode*node)
 {
      
    int height=0;
    BstNode* search=rootbst;
    if(node==rootbst)//height of root is 1
         return 1;
    while(node!=search)
    {
        height++;
        if(node->data<search->data)
           search=search->left;
        else search=search->right;
    }
    height++;
    return height;
 }

void AVL_Tree::AVL_Delete(int key){

    AVL_Node *itrPoint = rootavl->right; 
    
    // ImBal -> AVL_Node to be balanced
    // parImBal -> parent of the AVL_Node to be balanced
    // ImBaleft -> left/right child of the AVL_Node to be balanced
    AVL_Node *ImBal, *parImBal, *ImBaleft;
    
    stack<AVL_Node*> walkStack; // saves the path to the AVL_Node
    walkStack.push(rootavl); //pushing the head (dummy) AVL_Node

    while(itrPoint!=NULL && key!=itrPoint->value)
    {
        if(key < itrPoint->value)
        {
            comparisons_avl_delete++;
            walkStack.push(itrPoint);
            itrPoint = itrPoint->left;
        }
        else if(key > itrPoint->value)
        {
            comparisons_avl_delete++;
            walkStack.push(itrPoint);
            itrPoint = itrPoint->right;
        }
     }
    if(itrPoint==NULL)//key not present
    {
         return;
      }
    
    // if itrPoint is leaf 
      if(itrPoint->left==NULL && itrPoint->right==NULL)
        {
           AVL_Node*par=walkStack.top();
           if(itrPoint==par->left)
               { par->left=NULL;}
        else 
            {      
                 par->right=NULL;
                 delete itrPoint;
                 
            }
        }
       

        // if itrPoint has a single child 
       else if(!itrPoint->left || !itrPoint->right)
       {
            AVL_Node *temp = itrPoint->left ? itrPoint->left : itrPoint->right;
           

            
                itrPoint->value = temp->value;
                itrPoint->b = temp->b;
                itrPoint->left = temp->left;
                itrPoint->right = temp->right;
                delete temp;
        }

        // AVL_Node to be deleted has both the children
        else{
            walkStack.push(itrPoint);
            AVL_Node *succ = itrPoint->right; //finding the successor of itrPoint
            while(succ->left){
                walkStack.push(succ);
                succ = succ->left;
            }
            
            itrPoint->value = succ->value;
            key = succ->value; // because the AVL_Node that is being deleted is the successor
            AVL_Node *temp = succ->left ? succ->left : succ->right;
            AVL_Node *par = walkStack.top();

            if(!temp){
                temp = succ;
                if(succ == par->left)
                    par->left = NULL;
                else par->right = NULL;
                succ = NULL;
            }
            else{
                succ->value = temp->value;
                succ->b = temp->b;
                succ->left = temp->left;
                succ->right = temp->right;
            }
            delete temp;
        }
    


   
    while(walkStack.top() != rootavl)
    {
        
        ImBal = walkStack.top();
        int a = key < ImBal->value ? 1 : -1;
        walkStack.pop();
        parImBal = walkStack.top();
    
        if(ImBal->b == a)
        {  // here the node balanced had one more height on same side on which deletion happend so it got balanced
            ImBal->b = 0;
            continue;
        }
        else if(ImBal->b == 0)
        {
            //here node to be balanced was previously balanced to 0 but now its balance factor will be negative to the side the deletion occured
            ImBal->b = -1*a;
            return;//no further balancing required
        }
        else{
             //here node to be balanced was having a imbalance of 1 but now we deleted element on the side where it was already tilted so we made an 
             //imbalance of 2 and now we will do rotations
            if(ImBal->b==1)
              ImBaleft=ImBal->left;
              else 
              ImBaleft=ImBal->right;
            //single rotation
            if(ImBaleft->b == -1*a)
            {
                if(a == -1)
                {
                     rotations_avl++;
                    itrPoint = ImBaleft;
                    ImBal->left = ImBaleft->right;
                    ImBaleft->right = ImBal;
                    ImBal->b = 0;
                    ImBaleft->b = 0; 
                }
                else if(a == 1)
                {
                    rotations_avl++;
                    itrPoint = ImBaleft;
                    ImBal->right = ImBaleft->left;
                    ImBaleft->left = ImBal;
                    ImBal->b = 0;
                    ImBaleft->b = 0;
                }
            }
            //single rotation
            else if(ImBaleft->b == 0)
            {
                if(a == -1)
                {  
                    rotations_avl++;
                    itrPoint = ImBaleft;
                    ImBal->left = ImBaleft->right;
                    ImBaleft->right = ImBal;
                    ImBaleft->b = a; 
                }
                else if(a == 1)
                {
                    rotations_avl++;
                    itrPoint = ImBaleft;
                    ImBal->right = ImBaleft->left;
                    ImBaleft->left = ImBal;
                    ImBaleft->b = a;
                }
            
            }
            //double rotation
            else if(ImBaleft->b == a)
            {
                if(a == -1)
                {
                    rotations_avl+=2;
                    itrPoint = ImBaleft->right;
                    ImBaleft->right = itrPoint->left;
                    itrPoint->left = ImBaleft;
                    ImBal->left = itrPoint->right;
                    itrPoint->right = ImBal;
                    
            
                    
                        if(itrPoint->b==0)
                                {
                                ImBal->b=0;
                                     ImBaleft->b=0;  
                                    }
                            else if(itrPoint->b==1)
                                {
                                    ImBal->b=-1;
                                        ImBaleft->b=0;   
                
                                }
                            else                
                                    {
                                        ImBal->b=0;
                                        ImBaleft->b=1;   
                                    }
                                    itrPoint->b=0;      
                    
                 }
                else if(a == 1)
                {
                    rotations_avl+=2;
                    itrPoint = ImBaleft->left;
                    ImBaleft->left = itrPoint->right;
                    itrPoint->right = ImBaleft;
                    ImBal->right = itrPoint->left;
                    itrPoint->left = ImBal;
                  
                  if(itrPoint->b==0)
                     {
                            ImBal->b=0;
                                    ImBaleft->b=0;   
                                }
                        else if(itrPoint->b==1)
                        {
                            ImBal->b=0;
                                ImBaleft->b=-1;  
                
                           }
                     else
                            {
                            ImBal->b=1;
                            ImBaleft->b=0;   
                        }
                    itrPoint->b=0;
                    
                }
            }
            if(itrPoint->b==1||itrPoint->b==-1)
            {
                if(ImBal==parImBal->right)
                  parImBal->right=itrPoint;
                  else parImBal->left=itrPoint;
                  return;
            }
      }
        if(ImBal == parImBal->right) parImBal->right = itrPoint;
        else parImBal->left = itrPoint;       
      
    }

}

int AVL_Tree:: totalheightAVL(AVL_Node*node)
{
    int height=0;
    AVL_Node* search=rootavl->right;
    if(node==rootavl->right)//height of root is 1
         return 1;
    while(node!=search)
    {
        height++;
        if(node->value<search->value)
           search=search->left;
        else search=search->right;
    }
    height++;

    return height;
}
void BST :: deleteNode(int key)
{
  //first check whether key is present or not
  BstNode *current= rootbst;
  BstNode* previous=NULL;
  while(current!=NULL&&current->data!=key)
  {
    previous=current;
    if(key<current->data)
       {
          comparisons_bst_delete++;
          current=current->left;
         }
     else{
        comparisons_bst_delete++;
        current=current->right;
     }
  }
 if(current==NULL)// key not present 
   {
    return;
    }  
    
 //check if node to be deleted has atmost one child that is either leaf or node with one child
 if(current->left==NULL||current->right==NULL)
  {
    //set the new child pointer to replace current
    BstNode * newCurrent;
    //set the newCurrent to either left or right or null
    if(current->left==NULL)
       newCurrent=current->right;
    else newCurrent=current->left;
 //if the node to be deleted is root ,then new root will be newCurrent node
    if(previous==NULL)
       {
         rootbst=newCurrent;
          return;
       }
    //replace current node
    if(current==previous->left)
          previous->left=newCurrent;
    else previous->right=newCurrent;       
         delete current;
        
 }
 // node has two child
 else if(current->left!=NULL && current->right!=NULL){
       //find inorder successor of current
         BstNode * succ=current->right;
         BstNode *parentsucc=NULL;// it is parent of successor
         while(succ->left!=NULL)
         {
            parentsucc=succ;
            succ=succ->left;
         }
        //if parentsucc is null means parent of successor is current node itself
        //set the right child of current = right child of successor
        if(parentsucc==NULL)
            current->right=succ->right;
        //else set the left child of parent of successor as right child of successor
        else    
          parentsucc->left=succ->right;
        // now delete successor and copy data of successor in current
        current->data=succ->data;
        delete succ;
   }
 
}//end delete

void BST::insert(int x)
{
		BstNode*p = rootbst;
	    BstNode*r;
	
	
	if (rootbst == NULL)
	{
        comparisons_bst=1;
		rootbst = new BstNode;
		rootbst->data = x;
		rootbst->left = NULL; 
		rootbst->right = NULL;
		
	}
    
	else if ( rootbst != NULL)
    {
		while(p)
		{
				r=p;
				if (x<(p->data))
				{
					p = p->left;
                    comparisons_bst++;
				}
			else if (x>(p->data))
				{
					p= p->right;
                    comparisons_bst++;
				}
			else if (x==(p->data))
				 {
				     return;
				 }
					
	   }
	
        BstNode *new_BstNode = new BstNode;
        new_BstNode->data= x;
        new_BstNode->left = new_BstNode->right = NULL;
	     if(r->data < x)
            {
                  r->right= new_BstNode;
            }
	      else 
              r->left = new_BstNode;
		
	}
		
}

BstNode * BST :: iterativeSearch(BstNode*root,int v) {
    if (root == NULL) {
      return root;
    } else {
      BstNode * temp = root;
      while (temp != NULL) {
        if (v == temp -> data) {
          return temp;
        } else if (v < temp -> data) {
          temp = temp -> left;
        } else {
          temp = temp -> right;
        }
      }
      return NULL;
    }
  }
 
 BstNode * minValueNode(BstNode * node) {
    BstNode * current = node;
    /* loop down to find the leftmost leaf */
    while (current -> left != NULL) {
      current = current -> left;
    }
    return current;
  }



void Treap :: insert(int key , int priority)
    {
        TreapNode*temp = new TreapNode (key,priority);
        if(roottreap->right == NULL)
        {    comparisons_treap++;
            roottreap->right = temp;
            return;
        }
        
        TreapNode* itr; // will be used to find the leaf where we need to insert
        TreapNode*parent;
        stack <TreapNode*> Path; // will be used to store the path
        Path.push(roottreap); 
        itr = roottreap->right;
       // Here we are finding the place where we have to insert our new node okay and on the way we are storing the entire path in our stack so we can do the neccessary rotaions later       
     while (itr)   
         { 
            if (itr->data < key )
            {
              comparisons_treap++;
                parent = itr;
                Path.push(itr);
                itr = itr->right;
            }
            else if (itr->data > key )
            {
                comparisons_treap++;     
                parent = itr;
                Path.push(itr);
                itr = itr->left;
            }
            else
            {
                return;
            }
         }  
          // Now let's insert the node in our Treap  
         (parent->data < key ) ? (parent->right = temp ) : (parent->left = temp );
         
         // Now let's check if the priorities are right after this particular insertion 
      while (Path.empty() == false)
                 { 
                             parent = Path.top();
                             Path.pop();
                      /*   if (parent == root )
                             {
                                 return;
                             }*/
                             if (parent->priority < temp->priority) // Checking if rotations are actually needed or not 
                             {
                                     TreapNode*grandParent = Path.top();
                                     if (temp->data < parent->data )
                                     {    rotations_treap++;
                                         parent->left = temp->right;
                                         temp->right = parent;
                                     }
                                     
                                     else 
                                     {
                                         rotations_treap++;
                                         parent->right = temp->left;
                                         temp->left = parent;
                                     }
                                     
                                     // Now let's take care of the grand parent node 
                                     
                                     if (grandParent == roottreap )
                                     {
                                         grandParent->right = temp;
                                         Path.pop();
                                         break;
                                     }
                                     
                                     else if (parent == grandParent->left)
                                     {
                                         grandParent->left = temp;
                                     }
                                     
                                     else 
                                     {
                                         grandParent->right = temp;
                                     }
                             }
                }
 
    }        
                    
bool Treap :: search (int key)
{
    TreapNode*searchTempPointer = roottreap->right;
    if (!searchTempPointer )
    {
        cout << "The treap is empty " << endl;
        return false;
    }
    
    while (searchTempPointer)
    {
        if (searchTempPointer->data > key )
        {
            searchTempPointer = searchTempPointer->left;
        }
        
        else if (searchTempPointer->data < key )
        {
            searchTempPointer = searchTempPointer->right;
        }
        
        else 
        {
            return true;
        }
    }
    return false;
}

void Treap::deleteNode(int key)
{
    // If the element you're trying to delete if it is not even present in the treap then we will give the user an error
    bool searchResult = search(key);
    if (searchResult == false)
    {
        return;
    }
    
// otherwise we will try to go to the node which is to be deleted and also maintain a parent pointer to make the deletion easier
TreapNode* deleteNodePtr = roottreap -> right; // initializing the deleteNodePtr to the orignal root of the treap
TreapNode* parent = roottreap;
while (deleteNodePtr->data != key)
            {

                if (deleteNodePtr->data > key )
                    {   
                        comparisons_treap_delete++;
                        parent = deleteNodePtr;
                        deleteNodePtr = deleteNodePtr->left;
                    }

                else
                    {
                        comparisons_treap_delete++;
                        parent = deleteNodePtr;
                        deleteNodePtr = deleteNodePtr->right;
                    }
                    
            }
            
  while (true)          
      {
              // FIrst check if the node that you have to delete is  a leaf if it is a leaf then the deletion is pretty straight forward
              
              if ((deleteNodePtr->left == NULL) && (deleteNodePtr -> right == NULL))
              {
                  if (deleteNodePtr == parent->left)
                  {
                      parent->left = NULL;
                   
                  }
                else
                  {
                      parent->right = NULL;                   
                  }
                  return;
              }
              
              // Now let's check the case where the node to be deleted only has one child
              
      else if ((deleteNodePtr->left == NULL) || (deleteNodePtr -> right == NULL))
            {
                    
                    if (deleteNodePtr -> left != NULL )
                    {
                        if (parent->left == deleteNodePtr)
                            {
                                parent->left = deleteNodePtr->left;
                             
                            }
                            
                    else 
                            {
                                parent->right = deleteNodePtr->left;
                              //  delete deleteNodePtr;
                            }
                    }
                    
                else 
                        
                {
                        if (parent->left == deleteNodePtr)
                                {
                                    parent->left = deleteNodePtr->right;
                                    //delete deleteNodePtr;
                                }
                                
                              else 
                                    {
                                        parent->right = deleteNodePtr->right;
                                        //delete deleteNodePtr;
                                    } 
                  
                }
                
                return;

            }
    // or the node has two children this is also a case we will have to take care of.
          else
           {
                          // checking due to the fact that we have to delete a node which has two children let's see which one of the kids will become the new parent ( the one with more priority)
                          TreapNode*newParent ;
                          if (deleteNodePtr ->right -> priority > deleteNodePtr->left->priority)
                              {
                                  newParent = deleteNodePtr -> right;
                              }
                              
                          else 
                              {
                                  newParent = deleteNodePtr->left;
                              }
                              
                          int rotation ; // this will check which way we have to rotate
                          if (newParent== deleteNodePtr->left)
                              {
                                  rotation = 1; // right rotation
                              }
                          else 
                              {
                                  rotation = 0; // left rotation
                              }
                              
                          // now we will delete the node and try to modify all the pointers
                        
                        if (deleteNodePtr == parent->left)
                        {
                                parent->left = newParent; // this is cause parent points to delete node which inturn points new parent
                                // now since we will delete the node pointed by deleteNodePtr we should try to make sure that the parent->left points to new parent
                                
                            if (rotation == 1)
                                {
                                    rotations_treap++;
                                    deleteNodePtr->left = newParent->right;
                                    newParent->right = deleteNodePtr;
                                }
                            else
                                {
                                    rotations_treap++;  
                                    deleteNodePtr->right = newParent->left;
                                    newParent->left = deleteNodePtr;
                                }
                            // set new parent now
                            parent = newParent;
                            
                        }
                          
                  else 
                          {
                                  parent->right = newParent;
                                  if (rotation == 1)
                                  {
                                      deleteNodePtr->left = newParent->right;
                                      newParent->right = deleteNodePtr;
                                  }
                                  else 
                                  {
                                     deleteNodePtr->right = newParent->left;
                                      newParent->left = deleteNodePtr; 
                                  }
                                  // set new parent now
                          }        
           }
          
      }
    
}

int Treap:: heightTreap(TreapNode*node)
{
    queue<TreapNode*> nodesInLevel;
    int height = 0;
    int nodeCount = 0; // Calculate  number of nodes in a level.
    TreapNode* currentNode; // Pointer to store the address of a
                       // node in the current level.
    if (node == NULL) {
        return 0;
    }
    nodesInLevel.push(node);
    while (!nodesInLevel.empty()) {
        // This while loop runs for every level and
        // increases the height by 1 in each iteration. If
        // the queue is empty then it implies that the last
        // level of tree has been parsed.
        height++;
        // Create another while loop which will insert all
        // the child nodes of the current level in the
        // queue.
  
        nodeCount = nodesInLevel.size();
        while (nodeCount--) {
            currentNode = nodesInLevel.front();
  
            // Check if the current nodes has left child and
            // insert it in the queue.
  
            if (currentNode->left != NULL) {
                nodesInLevel.push(currentNode->left);
            }
  
            // Check if the current nodes has right child
            // and insert it in the queue.
            if (currentNode->right != NULL) {
                nodesInLevel.push(currentNode->right);
            }
  
            // Once the children of the current node are
            // inserted. Delete the current node.
  
            nodesInLevel.pop();
        }
    }
  return height;
}//height treap

void Treap :: averageheightTreap()
{
    
    TreapNode *node=roottreap->right;
    int totalnode=0;
    int totalheight=0;
    float avgheight=0.0;
    stack<TreapNode*>walk;
    while(!walk.empty()||node!=NULL)
    {
        while(node!=NULL)
        {
            totalnode++;
            walk.push(node);
            node=node->left;
        }
      // now we start poping from stack
         node=walk.top();
         totalheight+=totalheightTreap(node);
         walk.pop();
      node=node->right;
       }
     cout<<"Total nodes in Final Treap \t"<<totalnode<<endl;
      avgheight=(float)totalheight/totalnode;
     cout<<"Average height of Treap is\t "<<avgheight<<endl;
}
 
 int Treap :: totalheightTreap(TreapNode*node)
 {
     
    int height=0;
    TreapNode* search=roottreap->right;
    if(node==roottreap->right)//height of root is 1
         return 1;
    while(node!=search)
    {
        height++;
        if(node->data<search->data)
           search=search->left;
        else search=search->right;
    }
    height++;

    return height;
 }

int main ()
  {
    srand(time(NULL));
    BST bstobject;
    AVL_Tree avlobject;
    Treap treapobject;
    int key;
    string operation;
    ifstream filepointer;
    filepointer.open("testcasefiles\\testcase16.txt");
    if (!filepointer)
    {
        cout << "File can't be accessed " << endl;
        return 0;
    }
    filepointer>>operation>>key;
    cout << "No. of operations in this testcase file are : " << key << endl;
    filepointer>>operation >>key;
    cout << "Percentage of deletion among the operations in this testcase file is : " << key << endl << endl;
    while (!filepointer.eof())
    {
        filepointer>>operation>>key;
        if (operation=="Insert")
        {
            avlobject.AVL_Insert(key);
            int randomPriorityTemp = rand()%100000;
           treapobject.insert(key,randomPriorityTemp);
          bstobject.insert(key);
        }
        
        else if (operation == "Delete")
        {
           bstobject.deleteNode(key);
          avlobject.AVL_Delete(key);
          treapobject.deleteNode(key);
        }
        
    }
    
    filepointer.close();
  
       // Now printing  the values of all parameters for all three trees
    cout<<"The No of Comparisons While Inserting  in  bst is \t"<< comparisons_bst<<endl;
    cout<<"The no of comparisons while deleting in  bst is \t"<< comparisons_bst_delete<<endl;
    cout<<"Total no of rotations while inserting and deleting in bst is \t"<<0<<endl;
    cout<<"Final height of bst \t"<<bstobject.heightBst(bstobject.rootbst)<<endl;
    bstobject.avgheightBst();
    
    cout<<endl<<endl;
    
   cout<<  "The No of Comparisons While Inserting  in avl is \t"<< comparisons_avl<<endl;
   cout<<"The No of Comparisons While Performing Delete in avl is\t"<< comparisons_avl_delete<<endl;
   cout<<"Total rotations in avl tree while inserting and deleting is is \t"<< rotations_avl<<endl;
    cout<<"Final height of avl \t"<<avlobject.heightAVL(avlobject.rootavl)<<endl;
    avlobject.avgheightAVL();
 
  cout<<"\n\nThe No of Comparisons While Insertinh in treap is \t"<< comparisons_treap<<endl;
   cout<<"The No of Comparisons While Performing Delete in treap is\t"<< comparisons_treap_delete<<endl;
   cout<<"Total rotations in treap  while inserting and deleting is  \t"<< rotations_treap<<endl;
   cout<<"Final height of treap \t"<<treapobject.heightTreap(treapobject.roottreap)<<endl;
  
 treapobject.averageheightTreap();
 return 0;
   
}
      

        
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
  
 
