#include<iostream>
#include <vector>
using namespace std;
vector<string>nameVec;
vector<int>idVec;
vector<string>pwVec;
vector<int>balanceVec;

void openAc(){
	string name,pw; int id;
	cout<<"Enter User Name: ";
	cin>>name;
	cout<<"Enter User ID: ";
	cin>>id;
	cout<<"Enter User Password: ";
	cin>>pw;
	
	nameVec.push_back(name);
	idVec.push_back(id);
	pwVec.push_back(pw);
	cout<<"Your Account Opened Successfuly!"<<endl;
	cout<<" "<<endl;
}

void depFun(){
	int id,amount;
	cout<<"Enter Your ID: ";
	cin>>id;
	cout<<"Enter Depositing Cash: ";
	cin>>amount;
	 bool found=false;
		
	for(int i=0;i<idVec.size();i++){
		if(id==idVec[i]){
			found=true;
			balanceVec.push_back(amount);
			cout<<"Cash Deposited Successfuly!"<<endl;
			cout<<" "<<endl;
			break;	
	}
	if(!found){
		cout<<"Invalid User ID"<<endl;
		cout<<" "<<endl;
	}
}
}

void wdFun(){
	int id,amount; string pw;
	cout<<"Enter Your ID: ";
	cin>>id;
	cout<<"Enter Your Password: ";
	cin>>pw;
	
	bool idFound=false;
	bool pwFound=false;
	bool balAvail=false;
	
	for(int i=0;i<idVec.size();i++){
		if(id==idVec[i]){
			idFound=true;
		  if(pw==pwVec[i]){
		  	pwFound=true;
		  	cout<<"Enter Amount: ";
		  	cin>>amount;
		  	
		  	if(amount<=balanceVec[i]){
		  		balAvail=true;
		  		balanceVec[i] = balanceVec[i] - amount;
		  		cout<<"Operation was Successful!"<<endl;
		  		cout<<" "<<endl;
			  }
		  }
		}
	}//for loop
	if(!idFound){
		cout<<"Invalid user ID!"<<endl;
		cout<<" "<<endl;
	}
	else if(!pwFound){
		cout<<"Incorrect user Password!"<<endl;
		cout<<" "<<endl;
	}
	else if(!balAvail){
		cout<<"Insufficient Balance!"<<endl;
		cout<<" "<<endl;
	}
}

void balInq(){
	string pw; int id;
	cout<<"Enter user ID: ";
	cin>>id;
	cout<<"Enter user Password: ";
	cin>>pw;
	
	bool idFound=false;
	bool pwFound=false;
	
	for(int i=0;i<idVec.size(); i++){
		if(id==idVec[i]){
			idFound=true;
			if(pw==pwVec[i]){
			 pwFound=true;
			 cout<<"Mr/Mrs. "<<nameVec[i]<<"! Your Available Balance is: "<<
			 balanceVec[i]<<endl;
			 cout<<" "<<endl;
			 break;	
			}
		}
	}
	if(!idFound){
		cout<<"Invalid user ID!"<<endl;
		cout<<" "<<endl;
		
	}
	else if(!pwFound){
		cout<<"Incorrect Password!"<<endl;
		cout<<" "<<endl;
	}
}

int main(){
	while(true){
		cout<<"Bank Account Management"<<endl;
		cout<<"======================="<<endl;
		cout<<"1.Open Account."<<endl;
		cout<<"2.Deposit Cash."<<endl;
		cout<<"3.Withdraw Cash."<<endl;
		cout<<"4.Balance Inquiry."<<endl;
		cout<<"5.Exit."<<endl;
		int choice;
		cout<<"Enter choice: ";
		cin>>choice;
		
		if(choice==1){
			//open account
			system("cls");
			openAc();
		}
		else if(choice==2){
			//deposit cash
			system("cls");
			depFun();
		}
		else if(choice==3){
			//withdraw cash
			system("cls");
			wdFun();
		}
		else if(choice==4){
			//balance inquiry
			system("cls");
			balInq();
		}
		else if(choice==5){
			system("cls");
			cout<<"Best of Luck!"<<endl;
			break;
		}
		else{
			cout<<"Invalid Input!"<<endl;
		}
	}	
}
