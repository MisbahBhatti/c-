#include<iostream>
#include<fstream>//for file streaming.....
#include<string.h>
#include<stdio.h>


using namespace std;

void addemployee();
void showemployee();
void updateSalary();

class employee 
{

	int employee_Code;
	string employee_Name;
	int employee_Salary;
	
	public:
	employee()
	{

	}
		void setCode(int Code)
		{
			employee_Code=Code;
		}
		void setName(string Name)
		{
			employee_Name=Name;
		}
		void setSalary(int Salary)
		{
			employee_Salary=Salary;
		}
		int getCode()
		{
			return this->employee_Code;
		}
		string getName()
		{
			return this->employee_Name;
		}
		int getSalary()
		{
			return this->employee_Salary;
		}
		
};

employee Employee;
void addemployee()
{
	int Code;
	cout<<"Enter Employee Code: ";
	cin>>Code;
	Employee.setCode(Code);
	cout<<"Enter Employee Name: ";
	string Name;
	cin>>Name;
	Employee.setName(Name);
	int Salary;
	cout<<"Enter Employee Salary: ";
	cin>>Salary;
	Employee.setSalary(Salary);
	ofstream empfile("EMPLOYEE.TXT",ios::binary|ios::app);

	if(!empfile) 
	{
		cout << "Cannot Open File!" << endl;
		return ;
	}
	empfile.write((char*)&Employee, sizeof(employee));
	empfile.close();
	if(!empfile.good()) 
	{
		cout << "ERROR IN CREATING FILE!\n" << endl;
		return ;
	}
	cout << "Employee Recored Added Sucessfully!" << endl;
}

void displayRecord()
{
	ifstream file("EMPLOYEE.TXT",ios::binary);
	if(!file) 
	{
	cout<<"Error In Opening File.\n";
	return;
	} else
	 {
		cout<<"Code"<<"  "<<"Name"<<"\t"<<"Salary"<<endl;
		cout<<"============================================"<<endl;
		while(file.read((char*)&Employee,sizeof(employee)))
		{
			cout<<Employee.getCode()<<"  "<<Employee.getName()<<"\t"<<Employee.getSalary();
			cout<<endl;
		}
		file.close();
	}
}

void updateSalary()
{
    //read employee Code
    employee  Emp;
    int c;
    int Found=0;
    float sal;
 
    cout<<"Enter Employee Code: ";
    cin>>c;
 
 
	ifstream file("EMPLOYEE.TXT",ios::binary|ios::in|ios::out);
    if(!file)
	{
        cout<<"ERROR IN OPENING FILE \n";
        return;
    }
    while(file)
	{
        if(file.read((char*)&Emp,sizeof(Emp)))
		{	
           	if(Emp.getCode()==c)
			{
                cout<<"Salary hike? ";
                cin>>sal;
                Emp.setSalary(Emp.getSalary()+sal);
                Found=1;
                break;
            }
        }
    }
    if(Found==0)
	{
        cout<<"Record not found!!!\n";
    }
    file.close();
    cout<<"Salary updated successfully."<<endl;
   
    
}





int main()
{
	ifstream file("EMPLOYEE.TXT");
	if(file)
	{
		file.close();
		remove("EMPLOYEE.TXT");
	}	int selectOption;
	while(true)
	{

		cout<<"\n\n";
		cout<<"______________________________________________________________________\n";
		cout<<"|        $$$$$$$$$$Please Select The Option$$$$$$$$$$$$$$$$$$$$      |\n";
		cout<<"|        **********[-1] To ADD AN EMPLOYEE:********************      |\n";
		cout<<"|        **********[-2] To DISPLAY FILE DATA:******************      |\n";
		cout<<"|        **********[-3] To INCREASE EMPLOYEE SALARY:***********      |\n ";
		cout<<"|       $$$$$$$$$$[-4] To Exit Program:$$$$$$$$$$$$$$$$$$$$$$$      |\n";
		cout<<"|____________________________________________________________________|\n";
			
		cout<<"Please Select From Options :";
		cin>>selectOption;
	
		switch(selectOption)
		{
		case 1 :
		cout<<"ADD AN EMPLOYEE.\n";
		addemployee();
		break;
		case 2 :
		cout<<"DISPLAY FILE DATA.\n";
		displayRecord();
		break;
		case 3 :
		cout<<"INCREASE EMPLOYEE SALARY .\n";
		updateSalary();
		break;
		case 4   :
		cout<<"Exit Program..... .\n";
		exit(4);
		break;
		
		default :
			cout<<"Invalid Choice\n";
	
		}
		
	}

	return 0;
}
