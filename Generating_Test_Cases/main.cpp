#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;
int main ()
        {   
            
            srand(time(NULL));
            int numTestFiles;
            cout << endl;
            cout << "How many test files do you wish to create : " ;
            cin >> numTestFiles;
            for (int i = 0 ; i < numTestFiles; i++)
                {
                    string filename;
                    ostringstream os;
                    os << "testcase" << i+1 <<".txt";
                    filename = os.str();
                    
                    ofstream filepointer;
                    filepointer.open(filename);
                    if (!filepointer)
                    {
                        cout << "FIle with " << filename << "could not be found " << endl;
                    }
                    
                    int key; //  will be used as a random key data value 
                    int index;
                    int noOfOperations;
                    int percentage;
                    int temp;
                    
                    vector <int> insertarray;
                    cout << endl;
                    cout << "Number of operations you'd like in your testfile" << i+1 << ": " ;
                    cin >> noOfOperations;
                    cout << endl;
                    cout << "Enter the percentage of deletion you'd like to have among your " << noOfOperations << " operations : ";
                    cin >> percentage;
                    if (percentage>100)
                    { 
                      cout << endl;
                      cout << "You've entered percentage greater then 100 please make this testcase file again ";
                        i--;
                        continue;
                    }
                    filepointer<< "operations" << "\t" << noOfOperations << endl;
                    filepointer <<"deletion_percentage" << "\t" << percentage << endl;
                    for (int j = 1 ; j <= noOfOperations; j++)
                    {
                        key= rand()%100000;
                        temp = key%20;
                        
                        if (temp > (20*percentage/100)) 
                        {
                            
                            filepointer << "Insert" << "\t" << key << endl;
                            insertarray.push_back(key);
                        }

                        else 
                        {
                            if(insertarray.size())
                            {
                                if(percentage==0)
                                {
                                    j--;
                                    continue;
                                }
                                index = rand()%insertarray.size();
                                key=insertarray[index];
                               filepointer<<"Delete"<<"\t"<<key<<endl; 
                            }
                        }

                    }
                    
                    
                  filepointer.close();  
                
                }
            return 0;
        }