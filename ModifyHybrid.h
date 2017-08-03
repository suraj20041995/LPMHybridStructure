#include<iostream>
using namespace std;


//Structure Smallnode is for binary trie

typedef struct SmallNode{
	
	char hop;												//Character "hop" stores data of next router
	bool f;													//"f" defines presence of the router info in any smaller node
	struct SmallNode *left, *right;							//"left", "right" are two pointers for the next node
	
	
	
	//function to make pointers Null at initial point
	void NULLDATA()
	{
		right = left = NULL;
		f = 0;
	}

}small;


typedef struct BigNode
{
	
	struct BigNode *EBM[8] ;		//External bit map pointers 
	small *smallptr[8];				//pointers for binary trie;
	
	//function to make all pointers null
	void NULLDATA()
	{
		for (int i = 0 ; i < 8 ; i++)
			{
				EBM[i] = NULL;
				smallptr[i] = NULL;
			}
	}
	
	
	//function to provide External bit map of supernodes
	string External()
	{
		string ExternalBitMap = "";
		for (int i  = 0 ; i <  8 ; i++)
		{
			if (EBM[i] == NULL)
			{
				ExternalBitMap += "0";
			}
			else
			{
				ExternalBitMap += "1";
			}
		}
		return ExternalBitMap;	
	}	
	
}node;



//Intial node Root
node *ROOT;

//funtion to initialise the root node
void initialise ()
{
	ROOT = NULL;
	ROOT = new node;
	ROOT->NULLDATA();
}


//function to convert 3 bit directly to decimals
int toDec(string s)
{
	if (s == "000")
		return 0;
	else if (s == "001")
		return 1;
	else if (s == "010")
		return 2;
	else if (s == "011")
		return 3;
	else if (s == "100")
		return 4;
	else if (s == "101")
		return 5;
	else if (s == "110")
		return 6;
	else
		return 7;
		
}


//function to addprefix to structure
void ADDPREFIX(string s, char c)
{
	node *ptr;
	small *smallpointer;
	ptr = ROOT;
	string convert = "";
	char s1, s2, s3;
	int i;
	int len = s.length();
	if(len <= 14)
		return;
		 
	//traversing till 14 bits
	for ( i = 0 ; i + 2 < 12  ; i+= 3)
	{
		s1 = s[i]; s2 = s[i + 1]; s3 = s[i + 2];
		convert = "";
		convert += s1; convert += s2; convert += s3;
		if (ptr->EBM[toDec(convert)] == NULL)
		{
	
			ptr->EBM[toDec(convert)] = new node;
			ptr = ptr->EBM[toDec(convert)] ;
			ptr->NULLDATA();
		}
		else
		{
			ptr = ptr->EBM[toDec(convert)] ;	
		}
	}
	s1 = s[i]; s2 = s[i + 1]; s3 = s[i + 2];
	i += 3;
	convert = "";
	convert += s1; convert += s2; convert += s3;
	
	
	//starting of binary trie so changing pointers
	if (ptr->smallptr[toDec(convert)] == NULL) 
	{
		ptr->smallptr[toDec(convert)] = new small;
		smallpointer = ptr->smallptr[toDec(convert)] ;
		smallpointer->NULLDATA();
	}
	else
	{
		smallpointer = ptr->smallptr[toDec(convert)];
	}
	
	if (len - i == 0)
	{
		smallpointer->f = true;
		smallpointer->hop = c;
		return;
	}
	else
	{
		//traversing in binary trie
		while (i < len)
		{
			if (s[i] == '0')
			{
				if(smallpointer->left == NULL)
				{
					smallpointer->left = new small;
					smallpointer = smallpointer->left;
					smallpointer->NULLDATA();
				}
				else
				{
					smallpointer = smallpointer->left;
				}
			}
			else
			{
				if(smallpointer->right == NULL)
				{
					smallpointer->right = new small;
					smallpointer = smallpointer->right;
					smallpointer->NULLDATA();
				}
				else
				{
					smallpointer = smallpointer->right;
				}
				
			}
			i++;
		}
		smallpointer->f = 1;
		smallpointer->hop = c;
	}	
}

//finction to search prefix
char Search(string s)
{
	
	node *ptr;
	small *smallpointer;
	ptr = ROOT;
	char route = 'A';
	int i;
	int len = s.length();
	string convert = "";
	char s1, s2, s3;
	
	//traversing till 14 bits
	for (i = 0 ; i + 2 < 12 ; i += 3)
	{
		
		s1 = s[i]; s2 = s[i + 1]; s3 = s[i + 2];
		convert = "";
		convert += s1; convert += s2; convert += s3;
		if (ptr->EBM[toDec(convert)] != NULL)
		{
			ptr = ptr->EBM[toDec(convert)];
		}
		else
		{
			return route;	
		}
	}
		s1 = s[i]; s2 = s[i + 1]; s3 = s[i + 2];  //i = 12
		convert = "";
		convert += s1; convert += s2; convert += s3;
		i += 2;
		
		// traversing to binary trie so changing pointers
		if( ptr->smallptr[toDec(convert)] == NULL)
		{
			return route;
		}
		else
		{
			smallpointer = ptr->smallptr[toDec(convert)];
			if(smallpointer->f == 1)
			{
				route = smallpointer->hop;
			}
			while(1)
			{
				i++;
				if(s[i] == '0')
				{
					if (smallpointer->left == NULL)
					{
						if(smallpointer->f == 1)
						{
							route = smallpointer->hop;
							return route;
						}
						else
						{
							return route;
						}
					}
					else
					{
						if(smallpointer->f == 1)
						{
							route = smallpointer->hop;
						}
						smallpointer = smallpointer->left;
					}
				}
				else
				{
					if (smallpointer->right == NULL)
					{
						if(smallpointer->f == 1)
						{
							route = smallpointer->hop;
							return route;
						}
						else
						{
							return route;
						}
					}
					else
					{
						if(smallpointer->f == 1)
						{
							route = smallpointer->hop;
						}
						smallpointer = smallpointer->right;
					}
				}
			}
		}
		return route;
}

//Function to delete prefix
void Delete(string s)
{

	node *ptr;
	small *smallpointer1, *smallpointer2;
	ptr = ROOT;
	string convert = "";
	char s1, s2, s3;
	int i;
	int len = s.length();
	if (len < 14)
		return;
		
	for ( i = 0 ; i + 2 < 12  ; i+= 3)
	{
		s1 = s[i]; s2 = s[i + 1]; s3 = s[i + 2];
		convert = "";
		convert += s1; convert += s2; convert += s3;
		if (ptr->EBM[toDec(convert)] == NULL)
		{
			cout<<endl<<"Error 404 The Node doesn't exist'"<<endl;
			return;
		}
		else
		{
			ptr = ptr->EBM[toDec(convert)] ;	
		}
	}
	s1 = s[i]; s2 = s[i + 1]; s3 = s[i + 2];
	i += 3;
	convert = "";
	convert += s1; convert += s2; convert += s3;
	if (ptr->smallptr[toDec(convert)] == NULL) 
	{
		cout<<endl<<"Error 404 The Node doesn't exist'"<<endl;
		return;
	}
	else
	{
		smallpointer1 = ptr->smallptr[toDec(convert)];	
	}
	if (len - i == 0)
	{
		smallpointer1->f = false;
		smallpointer1->hop = '*';
		if(smallpointer1->left == NULL)
		{
			if (smallpointer1->right == NULL)
			{
				ptr->smallptr[toDec(convert)] = NULL;
				return;
			}
		}
	}
	else
	{
		while (i < len)
		{
			if (s[i] == '0')
			{
				if(smallpointer1->left == NULL)
				{
					cout<<endl<<"Error 404 The Node doesn't exist'"<<endl;
					return;
				}
				else
				{
					smallpointer2 = smallpointer1;
					smallpointer1 = smallpointer1->left;
				}
			}
			else
			{
				if(smallpointer1->right == NULL)
				{
					cout<<endl<<"Error 404 The Node doesn't exist'"<<endl;
					return;
				}
				else
				{
					smallpointer2 = smallpointer1;
					smallpointer1 = smallpointer1->right;
				}
				
			}
			i++;
		}
		smallpointer1->f = 0;
		smallpointer1->hop = '*';
		if((smallpointer1->left == NULL) && (smallpointer1->right == NULL))
		{
				if(smallpointer2->left == smallpointer1)
				{
					smallpointer2->left = NULL;
				}
				if(smallpointer2->right == smallpointer1)
				{
					smallpointer2->right = NULL;
				}
		}
		
	}
}

