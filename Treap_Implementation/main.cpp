#include <iostream>
#include <stack>
#include <string>
#include <cstdio>
#include <ctime>
# include <iomanip>
#include <bits/stdc++.h>
#define nullptr NULL
using namespace std; 


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
        left = nullptr;
        right = nullptr;
    }  
    
    ~TreapNode ()
    {
        delete left;
        delete right;
    }
    
    friend class Treap;

};

class Treap 
 {
    private :
    TreapNode* root;
public :
    Treap()
    {  
        root = new TreapNode(0,999999999);
    }
    
    void insert (int key, int priority);
    bool search (int key);
    void deleteNode(int key);
    void printTreap(const char *filename);
    void write_in_file(TreapNode *root, ofstream &myfile);
    ~Treap ()
    {
        delete root;
    }

 };

void Treap :: insert (int key , int priority)
    {
        TreapNode*temp = new TreapNode (key,priority);
        if(root->right == nullptr)
        {
            root->right = temp;
            return;
        }
        
        TreapNode* itr; // will be used to find the leaf where we need to insert
        TreapNode*parent;
        stack <TreapNode*> Path; // will be used to store the path
        Path.push(root); 
        itr = root->right;
       // Here we are finding the place where we have to insert our new node okay and on the way we are storing the entire path in our stack so we can do the neccessary rotaions later       
     while (itr)   
         { 
            if (itr->data < key )
            {
                parent = itr;
                Path.push(itr);
                itr = itr->right;
            }
            else if (itr->data > key )
            {
                parent = itr;
                Path.push(itr);
                itr = itr->left;
            }
            else
            {
                cout << endl;
                cout << "The node with key value " << key << " is already present in the treap please try entering a different key " << endl;
                cout << endl;
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
                                     {
                                         parent->left = temp->right;
                                         temp->right = parent;
                                     }
                                     
                                     else 
                                     {
                                         parent->right = temp->left;
                                         temp->left = parent;
                                     }
                                     
                                     // Now let's take care of the grand parent node 
                                     
                                     if (grandParent == root )
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
    TreapNode*searchTempPointer = root->right;
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


void Treap ::  printTreap(const char *filename)
{
ofstream myfile;
myfile.open ("graph_dot_file.dot");
myfile << "digraph { " << endl;
myfile << " node [shape = record , height = .1,color = skyblue ]; ";
myfile << "edge[color = hotpink2];" <<endl;

TreapNode*ptr = root->right;
if(!(root->right))
	cout << "This Tree has no Nodes yet so nothing to print " << endl;
write_in_file(ptr,myfile);
myfile << "} " << endl;
myfile.close ();

string cmd = "dot -Tpng graph_dot_file.dot -o " + string(filename);
system((const char * )cmd.c_str());

}
void Treap::write_in_file(TreapNode *root, ofstream &myfile) {

    if(root == NULL) return;
    myfile << root->data << " [label = \"<f0>  | <f1> " << root->data << " | <f2> " << root->priority << " | <f3>  \"];\n";
    if(root->left) {
        write_in_file(root->left, myfile);
        myfile << "\"" << root->data << "\":f0 -> \"" << root->left->data << "\":f1;\n";
    }
    if(root->right) {
        write_in_file(root->right, myfile);
        myfile << "\"" << root->data << "\":f3 -> \"" << root->right->data << "\":f1;\n";
    }       
}

void Treap::deleteNode(int key)
{
    // If the element you're trying to delete if it is not even present in the treap then we will give the user an error
    bool searchResult = search(key);
    if (searchResult == false)
    {
        cout << endl;
        cout << "Node with value " << key << " is not present in treap! " << endl;
        cout << "Try deleting something else!!" << endl;
        return;
    }
    
// otherwise we will try to go to the node which is to be deleted and also maintain a parent pointer to make the deletion easier
TreapNode* deleteNodePtr = root -> right; // initializing the deleteNodePtr to the orignal root of the treap
TreapNode* parent = root;
while (deleteNodePtr->data != key)
            {

                if (deleteNodePtr->data > key )
                    {
                        parent = deleteNodePtr;
                        deleteNodePtr = deleteNodePtr->left;
                    }

                else
                    {
                        parent = deleteNodePtr;
                        deleteNodePtr = deleteNodePtr->right;
                    }
                    
            }
            
  while (true)          
      {
              // FIrst check if the node that you have to delete is  a leaf if it is a leaf then the deletion is pretty straight forward
              
              if ((deleteNodePtr->left == nullptr) && (deleteNodePtr -> right == nullptr))
              {
                  if (deleteNodePtr == parent->left)
                  {
                      parent->left = nullptr;
                   
                  }
                else
                  {
                      parent->right = nullptr;                   
                  }
                  return;
              }
              
              // Now let's check the case where the node to be deleted only has one child
              
      else if ((deleteNodePtr->left == nullptr) || (deleteNodePtr -> right == nullptr))
            {
                    
                    if (deleteNodePtr -> left != nullptr )
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
                                    deleteNodePtr->left = newParent->right;
                                    newParent->right = deleteNodePtr;
                                }
                            else
                                {
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


int main ()
  {
    srand(time(NULL));
    Treap object;
    int choice;
    int key; 
    int randomPriority;

    while (true)
        {   cout << endl;   
            cout << "Choose Among The Following Operations On Treap:- " << endl;
            cout << "1.Insert Element " << endl;
            cout << "2.Search Element " << endl;
            cout << "3.Delete Element " << endl;
            cout << "4.Print Current Treap " << endl;
            cout << "5.Exit" << endl;
            cout << endl;
            cout << "Enter Your Choice No. :  ";
            cin >> choice;

            if (choice == 1 ) // insert element
                {
                        cout << endl;
                        cout << "Please enter the number of elements you're planning to insert  :  " ;
                        int numberOfElements;
                        cin >> numberOfElements;
                       cout << endl;
                       cout << "Make sure you enter distinct numbers " << endl;
                       cout << endl;
                        for (int i = 0 ; i < numberOfElements ; i++)
                                {
                                    cout << "Enter element no. " << i+1 << " :   " ;
                                    cin >> key;
                                    randomPriority = rand()%1000000;
                                    object.insert(key,randomPriority);
                                    cout << endl;
                                    
                                }
                    cout << "You've entered " << numberOfElements << " elements successfully " << endl;
                }
                
                else if (choice == 2) // search element
                        {
                            cout << "Enter the element you want to search :  " ;
                            cin >> key;
                            bool temp;
                           temp =  object.search(key);
                           if (temp)
                               cout << endl << "Yes,The node with value " << key << " is present in the treap "<< endl ;
                               else 
                                   cout << endl <<  "No,The node with value " << key << " is NOT present in the treap " << endl ;
                        }
                else if (choice == 3) // Delete element 
                        {
                            cout << "Enter the element you'd like to delete :  ";
                            cin >> key;
                            object.deleteNode(key);
             
                        }
                else if (choice == 4) // Print Treap
                        { 
                            string filename;
                            cout << endl;
                            cout << "Enter a file name which will store the pictoral representation of this treap (with a .png extension) : ";
                            cin >> filename; 
                            object.printTreap(filename.c_str());
                            cout << endl;
                            cout << "Please Check the same directory it will now have a file named " << filename << endl;
                            cout << "It will contain the pictoral representation of your current treap. " << endl;
                            cout << endl;
                        }
                
                else if (choice == 5 )
                        {
                            return 0; // simply exit.
                        }
                        
            else 
                    {  
                        
                        cout << endl;
                        cout << "Please Enter A Correct Choice Number!!!!" << endl;
                        continue; // If the user enters something other then 1,2,3,4 or 5 we will just keep on asking the user again and again to enter something right
                    }
                    
                
          }
           return 0;     
}
      

        
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
  
 
