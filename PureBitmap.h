#include<iostream>
using namespace std;


void AddPure(string s, char c);

typedef struct BigNode{
	
	bool data[7];					//to chcek whether there is dataa or not
	struct BigNode *EBM[8] ;		//External bit map pointers 
	char router[7];					//characters for storing the data about routers	
		
		
	// function to null the data values in new nodes	
	void NULLDATA()
	{
		for (int i = 0 ; i < 7 ; i++)
		{
			data[i] = 0;
			router[i] = '*';
		}
		for (int i = 0 ; i < 8 ; i++)
		{
			EBM[i] = NULL;
		}
	}

	
	char NodeSearch(string s)
	{		
		int len = s.length();
		char r = router[0];
		if (len == 0)
		{
			if (router[0] != '*')
				r = router[0] ;
		}
		else if (len == 1)
		{
			if (s == "0")
			{
				if (router[1] != '*')
				return router[1];
			}
			if (s == "1")
			{
				if (router[2] != '*')
				return router[2];
			}
		}
		else
		{
			if (s == "00")
			{
				if (router[3] != '*')
				return router[3];
			}
			else if (s == "01")
			{
				if (router[4] != '*')
				return router[4];
			}
			else if (s == "10")
			{
				if (router[5] != '*')
				return router[5];
			}
			else
			{
				if (router[6] != '*')
				return router[6];
			}
		}
		return r;
	}


	// function to kow the possible next hop routers
	string NextHop()
	{
		string NextHopRouter = "";
		/*for (int i = 0 ; i < 7 ; i++)
		{
			if (router[i] != '_')
			{
				 NextHopRouter += router[i];
				 NextHopRouter	+= " ";
			}
		}*/
		
		for (int i = 0 ; i < 8 ; i++)
			NextHopRouter += router[i];
		return NextHopRouter;
	}


	//function to return the internal bitmap of the particular node
	string Internal()
	{
		string InternalBitMap = "";
		for (int i = 0 ; i < 7 ; i++)
		{
			if (data[i] == false)
			{
				InternalBitMap += "0";
			}
			else
			{
				InternalBitMap += "1";
			}			
		}
		return InternalBitMap;
	}
	
	//function to return the external bitmap of the particular node
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
	
	//function to addd a node within a bigger node
	void add(string s, char c)
	{
		int len = s.length();
		
		if (len == 0)
		{
			data[0] = 1;
			router[0] = c; 
		}
		else if (len == 1)
		{
			if (s == "0")
			{
				data[1] = 1;
				router[1] = c;
			}
			if (s == "1")
			{
				data[2] = 1;
				router[2] = c;
			}
		}
		else
		{
			if (s == "00")
			{
				data[3] = 1;
				router[3] = c;
			}
			else if (s == "01")
			{
				data[4] = 1;
				router[4] = c;
			}
			else if (s == "10")
			{
				data[5] = 1;
				router[5] = c;
			}
			else
			{
				data[6] = 1;
				router[6] = c;
			}
		}
	}
	
}node;	


node *ROOT;

//funtion to initialise the root node
void initialise ()
{
	ROOT = NULL;
	ROOT = new node;
	ROOT->NULLDATA();
	ROOT->data[0] = 1;
	ROOT->router[0] = 'A';
	
}

//funtion to convert the string into decimel
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

//function to add prfix in the tree
void ADDPREFIX(string s, char c)
{
		AddPure(s, c);
}


void AddPure(string s, char c)	
{
	node *ptr;
	ptr = ROOT;
	string convert = "";
	char s1, s2, s3;
	int len = s.length();
	if (len % 3 == 0)
	{
		string blank = "";
		for (int i = 0 ; i + 2 < len ; i+= 3)
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
		ptr->add(blank, c);
		
	}
	else
	{	int i;
		for ( i = 0 ; i + 2 < len ; i+= 3)
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
		int elem = (len - i);
		if (elem == 1)
		{
			s1 = s[i];
			string pass = "";
 			pass += s1;
			ptr->add(pass, c);
		}
		else if (elem == 2)
		{
			s1 = s[i];
			s2 = s[i + 1];
			string pass = "";
			pass += s1;
			pass += s2;
			ptr->add(pass, c);
		}
	}	
}


char Search(string s)
{
	
	node *ptr;
	ptr = ROOT;
	char route = ptr->router[0];
	int i;
	int len = s.length();
	string convert = "";
	char s1, s2, s3;
	for (i = 0 ; i + 2 < len ; i += 3)
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
			route = ptr->NodeSearch(convert);	
			return route;	
		}
		
		
	}
	int elem = (len - i);
	if (elem == 1)
	{
		s1 = s[i];
		string pass = "";
 		pass += s1;
		ptr->NodeSearch(pass);
	}
	else if (elem == 2)
	{
		s1 = s[i];
		s2 = s[i + 1];
		string pass = "";
		pass += s1;
		pass += s2;
		return ptr->NodeSearch(pass);
	}
		return route;
	
}









