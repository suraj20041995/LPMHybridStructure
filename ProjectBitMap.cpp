#include"BITMAPTRIE.h"
void BFS();
int main()
{
	node *ptr;
	initialise();
	ptr = ROOT;
	//ADDPREFIX("100000");
	//ADDPREFIX("100001");
	/*cout<< "Internal Bit Mat :" << ptr->Internal();
	cout<<endl << "External Bit Map :" << ptr->External(); 
	ptr = ptr->EBM[4];
	cout<<endl;
	cout<< "Internal Bit Mat :" << ptr->Internal();
	cout<<endl << "External Bit Map :" << ptr->External(); 
	*/
	string str = "";
	int cou;
	cout<<"enter how many number of prefix you want to add :";
	cin>>cou;
	for (int i = 0 ; i < cou ; i++)
	{
		cout<< endl << "enter the prefix :";
		cin>>str;
		ADDPREFIX(str);
		
	}
	BFS();
/*	cout<< endl << "enter the prefix :";
	cin>>str;
	ADDPREFIX(str);
	BFS();
*/		
	return 0;
}



void BFS()
{
	char c = 'A';
	int ch = 0;
	node *Q[100];
	node *ptr;
	int front, end;
	Q[0] = ROOT;
	front = 0 ; end = 1;
	while(front != end)
	{
		ptr = Q[front];
		front ++;
		front %= 100;
		
		cout<<endl;
		cout << (char)(c + ch) ;
		ch++;
		cout<<endl << "Internal Bit Mat :" << ptr->Internal();
		cout<<endl << "External Bit Map :" << ptr->External(); 
		
		for (int i = 0 ; i < 8 ; i++)
		{
			if (ptr->EBM[i] != NULL)
			{
				Q[end] = ptr->EBM[i];
				end += 1;
				end %= 100;
			}
		}
	}
	
	
}
