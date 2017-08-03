#include"ModifyHybrid.h"
#include<fstream>

int main()
{
	initialise();
	string str = "";
	char ch;
	int cou;
	string word;
	
	
	//take input prefix from the file
	ifstream file;
    file.open ("E:\\dev coding\\tree.txt");
    if (!file.is_open()) 
	{
		cout<<"File load error";
		return 100;
	}
	
	 while (file >> word)
    {
        file >> ch;
        ADDPREFIX(word , ch);
    }
    
    file.close();
    ofstream myfile;
    myfile.open("E:\\dev coding\\tree.txt", std::ios::out | std::ios::app);
    
    
    
    //asking user to choose the perform action from that
    while(1)
	{
		int choice;
		cout<<endl<<"Press 1 to search"<<endl<<"Press 2 to ADD"<<endl<<"Press 3 to Update"<<endl<<"Press 4 to delete"<<endl<<"Press 5 to Exit"<<endl<<"Enter your Choice :";

		cin>>choice;
		if(choice == 1)
		{
			cout<<"enter the dest address"<<endl;
			cin>>str;
			cout<<"The Address is "<<Search(str);
		}
		else if(choice == 2)
		{
			cout<< endl << "enter the prefix then the router name :";
			cin>>str;
			cin>>ch;
			ADDPREFIX(str , ch);
			myfile<<endl<<str<<"  "<<ch;
		}
		else if (choice == 3)
		{
			cout<< endl << "enter the prefix then the router name :";
			cin>>str;
			cin>>ch;
			ADDPREFIX(str , ch);
		}
		else if(choice == 4)
		{
			cout<< endl << "enter the prefix to delete :";
			cin>>str;
			Delete(str);
		}
		else
		{
			break;
		}
	}
	myfile.close();
	
	return 0;
}
