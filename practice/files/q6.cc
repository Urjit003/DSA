#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class cust{
	int acc_no;
	string acc_type;
	string cust_name;
	int old_bal;
	int new_bal;
	int last_pay;
	string dt_last_pay;
public:
	void input_cust(){
		cout << "Enter Customer Account Number : " << endl;
		cin >> acc_no;
		cout << "Enter Customer Account Type : " << endl;
		cin >> acc_type;
		cout << "Enter Custumer Name : " << endl;
		cin >> cust_name;
		cout << "Enter Old Balance : " << endl;
		cin >> old_bal;
		cout << "Enter New Balance : " << endl;
		cin >> new_bal;
		cout << "Enter Last Payment : " << endl;
		cin >> last_pay;
		cout << "Enter Date of last payment : " << endl;
		cin >> dt_last_pay;
	}

	void output_cust(){
		 double currentBalance = old_bal - last_pay;
	     cout << "Account No: " << acc_no << endl;
		 cout << "Account Type: " << acc_type << endl;
		 cout << "Name: " << cust_name << endl;
         cout << "Old Balance: " << old_bal << endl;
         cout << "New Balance: " << new_bal << endl;
         cout << "Last Payment: " << last_pay <<endl;
         cout << "Date of Last Payment: " << dt_last_pay << endl;
		 cout << "Current Balance: " << currentBalance << endl;
		 cout << "Account Status : " << endl;
		 if (new_bal < currentBalance) {
			cout << "Account is in arrears." << endl;
		 } else {
	     cout << "Account is up to date." << endl;
		 }
	     cout << "------------------------" << endl;
	}

};

int main(){
	int opt;
	cust c1;
	ofstream out1;
	do{
	cout << "1.To Insert a Record." << endl;
	cout << "2.To Display all the Record. "<< endl;
	cout << "3.Exit" << endl;
	cout << "ENter OPtion : " << endl;
	cin >> opt;
	switch(opt){
		case 1:
			out1.open("customer_records.txt", ios::out | ios::binary | ios::app);				
			if(!out1.is_open()){
				cout << "Error Openinng File " << endl ;
				return 1;
			}
			c1.input_cust();
			out1.write(reinterpret_cast<char *>(&c1), sizeof(c1));
			out1.close();
			break;
		case 2:
			cust c2;
			ifstream in1("customer_records.txt", ios::in | ios::binary);
			if(!in1.is_open()){
				cout << "Error OPening File." << endl;
				return 1;
			}
				while(in1.read(reinterpret_cast<char *>(&c2), sizeof(c2))){
				cout << endl << " Data Read Fro File " << endl;
				c2.output_cust();
			}
			in1.close();
			break;
	}
	}while(opt!=3);
return 0;
}

