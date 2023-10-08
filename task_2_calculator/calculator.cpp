#include<iostream>
using namespace std;
int ADD(int a, int b)
{
	return a+b;
}
int SUBTRACT(int c, int d)
{

	return c-d;
}
int MULTIPLY(int a, int b)
{

	return a*b;
}
int DIVIDE(int a,int b)
{
	if(b!=0){
	return a/b;
	}
	else{
		cout<<"invalid number! "<<endl;
		return 0;
	}

}
int main()
{
	int a,b;
	int choice;
	cout<<"ENTER THE FIRST ELEMENT: "<<endl;
	cin>>a;
	cout<<"ENTER THE FIRST ELEMENT: "<<endl;
    cin>>b;
	cout<<"-------------MENU----------------"<<endl;
		cout<<"1- ADDITION"<<endl;
		cout<<"2- SUBTRACT"<<endl;
		cout<<"3- MULTIPLICATION"<<endl;
		cout<<"4- DIVISION"<<endl;
	
	cin>>choice;
	switch(choice)
	{
		cout<<"-------------MENU----------------"<<endl;
		cout<<"1- ADDITION"<<endl;
		cout<<"2- SUBTRACT"<<endl;
		cout<<"3- MULTIPLICATION"<<endl;
		cout<<"4- DIVISION"<<endl;
	
		case 1:
		{
		cout<<"THE ANSWER BY DOING THIS TECHNIQUE IS: "<< ADD( a, b)<<endl;
		break;		
		}
		case 2:
		{
		cout<<"THE ANSWER BY DOING THIS TECHNIQUE IS: "<< SUBTRACT( a, b)<<endl;
		break;		
		}
		case 3:
		{
		cout<<"THE ANSWER BY DOING THIS TECHNIQUE IS: "<< MULTIPLY( a, b)<<endl;
		break;		
		}
		case 4:
		{
	cout<<"THE ANSWER BY DOING THIS TECHNIQUE IS: "<< DIVIDE( a, b)<<endl;
			break;		
		}
		default:
			cout<<"INVALID OUTPUT"<<endl;
		}
			return 0;
	}
	
	
	
	

