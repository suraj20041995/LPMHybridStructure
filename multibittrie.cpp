#include<fstream>
#include"twobittrie.h"
#include<ctime>
#include<cstdlib>


string toBinary(long dec)
{
	long rem;
	string sum = "", s = "";
    do
    {
        rem=dec%2;
        sum+=rem + '0';
        dec=dec/2;
    }while(dec>0);
    
    for (int i = sum.length() - 1 ;i >= 0 ; i--)
        s += sum[i];
    return s;
}


int main()
{
	srand(time(0));
	initialise();
	ofstream myfile;
	myfile.open ("trie.txt");
	long num;
	add("00", 'M');
	add("0011",'S');
	add("00", 'T');
	add("0011", 'W');
	string in="";
	char rou;
	
	clock_t start,end;
	
	srand(time(0));
	for (int i = 0 ; i < 1024 ; i++)
	{
		 num = 1 + (rand() % 131073);
		 int cha = 1 + (rand() % 20);
		 myfile << toBinary(num) << "        "  << char('A' + cha);
		 myfile << "\n";
		 
		 string save = "";
		 save = toBinary(num);
		 if (save.length() % 2 == 0)
		 {
		 	add(save , char('A' + cha));
		 }
		 else
		 {
		 	string odd = save + "0";
		 	string even = save + "1";
		 	add(odd, char('A' + cha));
		 	add(even, char('A' + cha));
		 }
		 
		 
	}
	
	//string ser = "";
	//cout<<"Enter the prefix to search"<<endl;
	//cin>>ser;
	/*if (ser.length() % 2 == 0)
		cout<<Router(ser);
	else
	{
		string odd = "";
		string even = "";
		odd = ser + "0";
		even = ser + "1";
		if (Router(odd) == 'Z')
			cout << Router(even);
		else
			cout << Router(odd);
	}*/
	
	/*cout<<"Enter the prefix to save"<<endl;
	cin>>in;
	cout<<"Enter the next hop to save (any letter)"<<endl;
	cin>>rou;
	add(in,rou);
	//cout<<Router("0011");
	*/
	
	
	string ser = "";
	cout<<"Enter the prefix to search"<<endl;
	cin>>ser;
	//cout<<Router(ser);
	
	start = clock();    
	if (ser.length() % 2 == 0)
		cout<<Router(ser);
	else
	{
		string odd = "";
		string even = "";
		odd = ser + "0";
		even = ser + "1";
		if (Router(odd) == 'Z')
			cout << Router(even);
		else
			cout << Router(odd);
	}
	
	end = clock();    
    cout<<endl<<start<<endl;
    cout<<endl<<end<<endl;
    cout <<endl << "Time: " << (end - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
	
	
	myfile.close();
	return 0;
}
