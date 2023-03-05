#include <iostream>
#include<limits>
#include<cstring>
using namespace std;
//this function check if the number leading zero for example(01 , 00)
bool enterDigit(int& num) {
    char strNum;

    cin >> strNum;
    if (!(strNum >= 48 && strNum <= 57) || cin.peek() != ' ' && cin.peek() != '\n' && cin.peek() != '\t') {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }

    num = strNum - 48;
    return true;
}
//this function checks the card number entered by user
void get_array(int arr[]) {
    bool ok;
    int buffer_check;
    while (true) {
        ok = true;
read_card2:
        for (int i = 0; i < 10; i++) {
            bool noNext = enterDigit(arr[i]);
if (!noNext){cout<<"Invalid Card Number please Enter ten numbers separated by space : ";
goto read_card2;
}

            if (!cin||arr[i]>9||arr[i]<0 ) {
                cout << "Invalid Card Number please Enter ten numbers separated by space : " ;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                ok = false;
                break;
            }
        }
        if (ok){
            buffer_check=cin.peek()!='\n';
            if(buffer_check){
                cout << "Invalid Card Number please Enter ten numbers separated by space : " ;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                ok = false;
            }
            else break;
        }}}
//this function checks the amount of money entered by user
void get_amount (float&num) {

    while (true) {
        cin >> num;
        if (num<0||cin.peek()!='\n') {
            cout <<"invalid input"<<endl;
            cout <<"enter valid amount "<<endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        }
        else break;
    }
}

int num_account = 0 ;
class ATM
{
private :
    int CardNo[10];
    float amount = 0;
    char name[100];
public:
    void create_new_acc();
    void Deposit(float);
    int Withdrawal(float);
    int Transfer(int,float);
    void Print_acc_data();
    int check(ATM acc);          //when the user creates new account this function
    int search(int cd[]);        //this function search for the account which the user entered its card number
    void enter_card(int arr[]);  //this function check if the user entered a letter of numbers less than 0 or greater than 9 in the card number in creating the new account
};
void ATM::create_new_acc()
{ cout<<"Please Enter Your Name : ";
    cin.ignore();
read_name:
gets(name);
int length_name=strlen(name);
if (length_name>100){
cout <<"invalid name has more than 100 char "<<endl<<"enter valid name : ";
goto read_name;
}
else{
for (int i=0;i<length_name;i++){
    if(!((int(name[i])>=65&&int(name[i])<=90)||(int(name[i])>=97&&int(name[i])<=122)|| int(name[i])==32 ))
        {cout <<"invalid name "<<endl;
    cout <<"please enter valid name : ";
    goto read_name;}
}
    if (int(name[0])==32){
        cout<<"invalid name with space in the beginning "<<endl<<"please enter valid name : ";
        goto read_name;
    }
    if (int (name[0])==0){
        cout <<"invalid name is empty name "<<endl<<"enter valid name : ";
        goto read_name;
    }
}

    enter_card(CardNo);
}
void ATM::Deposit(float deposit_amount)
{   amount = amount + deposit_amount*(1+0.01);
}
int ATM ::search(int cd[])
{
    for(int i=0; i<10; i++)
    {   if(cd[i]!=CardNo[i])
            return 0;
    }
    return 1;
}
int ATM::check(ATM acc)
{
    for (int i=0; i<10; i++)
    {
        if(CardNo[i]!=acc.CardNo[i])
            return 0;
    }
    return 1;

}
int ATM::Withdrawal(float with_amount)
{   if (amount< 1.03*with_amount)
    {   cout<<"There is no enough Money ,Your current balance is "<<amount<<"$"<<endl;
    cout<<"The maximum amount to withdraw is : "<<amount-amount*0.03<<"$"<<endl;
        return 0;
    }
    else
    {   amount = amount - 1.03*with_amount;
        Print_acc_data();
        return 1;

    }
}
//select_opeartor that determined the account send(2) and receiver(1)
int ATM::Transfer(int select_operator,float transfer_amount)
{   if(select_operator== 1) {
        amount = amount + 0.985*transfer_amount;
        Print_acc_data();
    }
    else
    {   if(amount < 1.015*transfer_amount)
        {   cout<<"There Is No Enough Money to Transfer ,Your current balance is "<<amount<<"$"<<endl;
        cout<<"The maximum amount to Transfer is : "<<amount-amount*0.015<<"$"<<endl;
            return 0;
        }
        else
        {   amount = amount - 1.015*transfer_amount;
            Print_acc_data();
            return 1 ;
        }
    }
}

void ATM::Print_acc_data()
{   cout<<endl<<endl<<"Your Account Name : "<<name<<endl;
    cout<<"your card number is :";
    for(int i=0; i<10; i++)
        cout<<CardNo[i]<<" ";
    cout <<endl;
    cout<<"Your Amount Is : "<<amount<<"$"<<endl<<endl;
}

//this function check if the entered card number more than 10 number and if it has invalid input like {5a(instead of 5) or 01(instead of 1) or 20(>9 or <0)}
void ATM::enter_card(int arr[]) {
    bool ok;
    int buffer_check2;
cout << "Enter card number (ten numbers separated by spaces) : ";
    while (true){
           int count_easy;
           ok=true;
                     read_card:
                         count_easy=1;
            for (int i = 0; i < 10; i++) {
            bool noNext = enterDigit(CardNo[i]);
            if (!noNext){cout<<"Invalid card number Please Enter TEN Numbers Separated By Space : ";
            goto read_card;
}
            if (!cin||arr[i]>9||arr[i]<0 ) {
                cout <<"Invalid Card Please Enter TEN Numbers Separated By Space : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                ok = false;
                break;
            }
            if (i>0&&i<10) {
                if (arr[i]==arr[0])
                    count_easy++;
            }
            if (count_easy==10) {
                cout <<"this is very easy account please enter harder card number : ";
                ok=false;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        if (ok) {
            buffer_check2=cin.peek()!='\n';
            if (buffer_check2) {
 cout <<"Invalid Card Please Enter TEN Numbers Separated By Space : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else break;
        }
    }
}
int main()
{   ATM acc[100];
    int check_amount,select;
    int search_acc = -1;
    int search_reciver = -1;
    int s_CardNo[10],r_CardNo[10];
    float amount;
jump2:
    cout<<"1----Create new account"<<endl<<"2----Deposit"<<endl;
    cout<<"3----Transfer to another account"<<endl<<"4----withdrawal"<<endl;
    cout<<"5----Exit"<<endl<<"Please enter the number of the operation : ";
jump :
    while (true) {
        cin>>select;
        if (cin.peek()!='\n'||!cin) {
            cout <<"invalid choice please use choices in the screen"<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else break;
    }

    switch(select)
    {
    case 1 :
    {   if(num_account <100)
        {   acc[num_account].create_new_acc();
            for(int i=0; i<num_account; i++)
            {
                if(acc[i].check(acc[num_account]))
                {
                    cout<<"the account is already selected  "<<endl<<endl;
                    goto jump2;

                }
            }
            acc[num_account].Print_acc_data();
            num_account++;
        }
        else
            cout<<"The maximum number of account was reached";
        break;
    }
    case 2 :
        {
        if (num_account==0){
            cout <<"there are no accounts""\n";
            break;
        }
        cout<<"Please enter your card number : ";
        get_array(s_CardNo);
        for(int i=0; i<num_account; i++)
        {
            search_acc=acc[i].search(s_CardNo);
            if(search_acc!=0)
            {
                search_acc=i;
                break;
            }
            search_acc = -1;
        }
        if(search_acc!= -1)
        {   cout<<"Please enter the amount of money : ";
            get_amount(amount);
            acc[ search_acc ].Deposit(amount);
            cout<<endl<<endl;
            acc[search_acc].Print_acc_data();

        }
        else cout<<"The account not found "<<endl<<endl;
        break;
    }
    case 3 :
    {   if (num_account<2){
    cout <<"no enough accounts to transfer "<<endl;
    break;
    }
        cout<<"Please enter sender's card number : ";
        get_array(s_CardNo);
        for(int i=0; i<num_account; i++)
        {
            search_acc=acc[i].search(s_CardNo);
            if(search_acc!=0)
            {
                search_acc=i;
                break;
            }
            search_acc = -1;
        }
        if (search_acc == -1)
        {   cout<<"This account not found "<<endl<<endl;
            break;
        }
        cout<<"Please enter the receiver's card number : ";
        get_array(r_CardNo);
        for(int i=0; i<num_account; i++)
        {
            search_reciver=acc[i].search(r_CardNo);
            if(search_reciver!=0)
            {
                search_reciver=i;
                break;
            }
            search_reciver = -1;
        }
        if (search_reciver == -1)
        {   cout<<"This account not found "<<endl<<endl;
            break;
        }
        int check_trans=0;
        for (int i=0;i<10;i++){
            if (s_CardNo[i]==r_CardNo[i])
                check_trans++;
        }
        if (check_trans==10){
            cout <<"You Cannot Transfer To Same Account "<<endl<<endl;
            break;
        }

        cout<<"Please enter the the amount : ";
        do {
            get_amount(amount);
            cout<<endl;
            check_amount = acc[search_acc].Transfer(2,amount); //2 means this is sender account
            if(check_amount == 0)
                cout<<"please enter less amount : ";
        } while(!check_amount);
        acc[search_reciver].Transfer(1,amount);  //1 means this is receiver i do condition in function transfer do know sender and receiver
        break;
    }
    case 4 :

    {  if (num_account==0){
            cout <<"there are no accounts""\n";
            break;
        }

         cout<<"Please enter your card number : ";
        get_array(s_CardNo);
        for(int i=0; i<num_account; i++)
        {
            search_acc=acc[i].search(s_CardNo);
            if(search_acc!=0)
            {
                search_acc=i;
                break;
            }
            search_acc= -1 ;
        }
        if(search_acc!= -1)
        {   cout<<"Please enter the amount of money : ";
            do {
                get_amount(amount);
                check_amount= acc[search_acc].Withdrawal(amount);
                if(check_amount== 0)
                    cout<<"please enter less amount : ";
            }
            while(!check_amount);
        }
        else cout<<"The account not found please enter right account"<<endl<<endl;
        break;
    }
    case 5 :
    {   cout<<"Take your card"<<endl;
       goto ATM_end;
        break ;
    }
    default :
    {   cout<<"Please enter a valid choice : ";
        goto jump;
    }
    }
    goto jump2 ;
ATM_end:
    return 0;

}
