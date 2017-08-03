#include<iostream>
using namespace std;
typedef struct Node{
	struct Node *zero = NULL, *one = NULL, *two = NULL, *three = NULL;
	char data[4];
}node;

node *ROOT;


void NULLDATA(node *p)
{
	p->data[0] = 'Z';
	p->data[1] = 'Z';
	p->data[2] = 'Z';
	p->data[3] = 'Z';
}




void initialise ()
{
	ROOT = NULL;
	ROOT = new node;
	ROOT->data[0] = 'A';
	ROOT->data[1] = 'B';
	ROOT->data[2] = 'C';
	ROOT->data[3] = 'D';
}

void add (string s, char r)
{
	node *ptr;
	ptr = ROOT;
	for (int i = 0 ; i + 1 < s.length() ; i+= 2)
	{
		if (s[i] == '0' && s[i+1] == '0')
		{
			if (ptr->zero == NULL)	
			{
				ptr->zero = new node;
				ptr = ptr->zero;
				NULLDATA(ptr);
			}
			else
				ptr = ptr->zero;
			
		}
		else if (s[i] == '0' && s[i+1] == '1')
		{
			if (ptr->one == NULL)	
			{
				ptr->one = new node;
				ptr = ptr->one;
				NULLDATA(ptr);
			}
			else
				ptr = ptr->one;
		}
		else if (s[i] == '1' && s[i+1] == '0')
		{
			if (ptr->two == NULL)	
			{
				ptr->two = new node;
				ptr = ptr->two;
				NULLDATA(ptr);
			}
			else
				ptr = ptr->two;
		}
		else
		{
			if (ptr->three == NULL)	
			{
				ptr->three = new node;
				ptr = ptr->three;
				NULLDATA(ptr);
			}
			else
				ptr = ptr->three;
		}
	}
	
	if (s[s.length() -2] == '0' && s[s.length() - 1] == '0')
	{
		if(ptr->data[0] != 'Z')
			return;
			ptr->data[0] = r;
	}
	else if (s[s.length() -2] == '0' && s[s.length() - 1] == '1')
	{
		if(ptr->data[1] != 'Z')
			return;
		ptr->data[1] = r;
	}
	else if (s[s.length() -2] == '1' && s[s.length() - 1] == '0')
	{
		if(ptr->data[2] != 'Z')
			return;
		ptr->data[2] = r;
	}
	else
	{
		if(ptr->data[3] != 'Z')
			return;
		ptr->data[3] = r;
	}
}


char Router(string s)
{
	node *ptr;
	ptr = ROOT;
	char r;
	for (int i = 0 ; i + 1 < s.length() ; i+= 2)
	{	
		if (s[i] == '0' && s[i+1] == '0')
			{ 
				if (ptr->zero == NULL)	
				{
					return r;
				}
				else
				{
					ptr = ptr->zero;
					r = ptr->data[0];
				}
			
			}
			else if (s[i] == '0' && s[i+1] == '1')
			{
				if (ptr->one == NULL)	
				{
					return r;
				}
				else
				{
					ptr = ptr->one;
					r = ptr->data[1];
				}
			}
			else if (s[i] == '1' && s[i+1] == '0')
			{
				if (ptr->two == NULL)	
				{
					return r;
				}
				else
				{
					ptr = ptr->two;
					r = ptr->data[2];
				}
			}
			else
			{
				if (ptr->three == NULL)	
				{
					return r;
				}
				else
				{
					ptr = ptr->three;
					r = ptr->data[3];
				}
			}
	
	}

	if (s[s.length() -2] == '0' && s[s.length() - 1] == '0')
	{
		return ptr->data[0];
	}
	else if (s[s.length() -2] == '0' && s[s.length() - 1] == '1')
	{
		return ptr->data[1];
	}
	else if (s[s.length() -2] == '1' && s[s.length() - 1] == '0')
	{
		return ptr->data[2];
	}
	else
	{
		return ptr->data[3];
	}


}

