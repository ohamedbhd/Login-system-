#include <iostream>
#include <cmath>
#include <unistd.h>
using namespace std;

// لاخذ سطر جديد
void Design()
{
  cout <<"\n";
}

      // ######## Login => نظام تسجيل الدخول ########

// الكود ده بيطلب من المستخدم يدخل اليوزر والباسورده
bool login ()
{
  string UserName, Passw;
  string my_Name= "mohamed", my_passw= "1234";
  cout <<"   ■■■■■■■■■■■■■■■■■■■■ login ■■■■■■■■■■■■■■■■■■■■\n \n";
  cout << "enter your name: ";
  cin >> UserName;
  
  cout << "enter your password: ";
  cin >> Passw;
  Design();
  return (UserName==my_Name&&Passw==my_passw);
}

         // ######## Calculator => نظام الة حاسبة ########

// الكود ده الة حاسبة بيطلب من المستخدم يدخل الرقم لاول وبعدين العملية الحسابية وبعدين يدخل الرقم التانى وينفذ العملية الحسابية كلها

void Calculator ()
{
  double num1, num2;
  char op;
  
  cout <<"   ■■■■■■■■■■■■■■■ slot calculator ■■■■■■■■■■■■■■■\n\n";
  
  cout << "enter Number ( 1 ): ";
  cin >> num1;
  
  cout << "enter your [ + , - , * , / , % , ^ ]: ";
  cin >> op;
  
  cout << "enter Number ( 2 ): ";
  cin >> num2;
  Design();
  
  switch (op)
  {
    case '+' :
    cout << num1 << " + " << num2<<" = "<< num1 + num2 << endl;
    break;
    case '-' :
    cout << num1 << " - " << num2 << " = " << num1 - num2 << endl ;
    break;
    case '*' :
    cout << num1 << " * " << num2 << " = " << num1 * num2 << endl ;
    break;
    case '/' :
    if (num2 ==0)
    {
      cout << "The number you entered is not divisible by zero\n";
    }
    else
    {
      cout << num1 << " / " << num2 << " = " << num1 / num2 << endl ; 
    }
    break;
    case '%' :
    cout << num1 << " % " << num2 << " = " << int(num1) % int(num2) << endl ;
    break;
    case '^' :
    cout << num1 << " ^ " << num2 << " = " << pow(num1 , num2) << endl ;
    break;
    default:
    cout <<"Eerro";
  }
}
 
              // ######## positive or negative => نظام الموجب والسالب ########
 
//الكود ده بيطلب من المستخدم يدخل رقم ويشوف الرقم ده موجب ولا سالب
void checkSign ()
{
  int num;
  cout <<"enter your number: ";
  cin >> num;
  Design();
  
  if (num >=0)
  {
    cout <<"The number is positive \n";
    Design();
  }
  else
  {
    cout <<"The number is negative \n";
    Design();
  }
}

             // ######## Even or Odd => نظام الفردى والزوجى  ########

// الكود ده بيطلب من المستخدم يدخل رقم ويشوف الرقم ده زوجى ولا فردى
void checkEvenOdd()
{
  int num;
  cout <<"enter your number: ";
  cin >> num;
  Design();
  if(num % 2 == 0)
  {
    cout <<"Even number\n";
    Design();
  }
  else
  {
    cout <<"Odd number\n";
    Design();
  }
}

          // ######## Student management system => نظام اداه الطلاب ########

// عندك اربع متغيرات لاسم والعمر ولايدى ولمتغير الرابع ده بيحفظ بيانات كل طالب لوحده بحيث ان البيانات كل طالب متتلغبش فى بعضstring
string name[100];
int age[100];
int ids[100];
int countStudent = 0;

//الكود ده بيطلب من المستخدم يدخل لاسم والعمر ولايدى بتاعة 

void addStudent()
{
  cout <<"enter your name: ";
  cin >>name[countStudent];
  cout <<"enter your age: ";
  cin >>age[countStudent];
  
  cout <<"enter your ID: ";
  cin >>ids[countStudent];
  
  countStudent++;
}

// الكود ده لما المستخدم يكون عايز يعرض الطلاب ال فى النظام

void showStudent ()
{
  for (int i=0; i < countStudent; i++)
  {
    cout << "nam: " << name[i];
    cout << "  age: " << age[i];
    cout << "  ID: " << ids[i] << endl;
  }
}

// الكود ده لما المستخدم يكون عايز يبحث عن طالب موجود فى النظام بى لايدى بتاعة

void searchStudent()
{
  int id;
  
  cout <<"enter my student ID: ";
  cin >>id;
  Design();
  for (int i=0; i < countStudent; i++)
  {
    if (ids[i] == id)
    {
      cout << "Found: " << name[i];
      return;
    }
    else
    {
      cout <<"No found";
    }
  }
}

// الكود ده هيظهر لى المستخدم اربع اختيارات كل اختيار منهم لية كود والكود موجود فى الدول ال احنا عملنها فوق وعملنا استدعاء ليهم عشان الكود يشتغل مضبوط

void StudentMenu()
{
  int che;
  do 
  {
    
    Design();
    cout <<"1- add\n";
    cout <<"2- Show\n";
    cout <<"3- Search\n";
    cout <<"4- Back\n";
    cout <<"enter your choice: " ;    
    cin >>che;
    switch (che)
    {
      case 1:
      addStudent();
      break;
      case 2:    
      showStudent();    
      break;   
      case 3: 
      searchStudent(); 
      break;    
    }
  } while (che !=4);
}

                     // ********** نظام ATM **********
//الكود ده بيظهر للمستخدم الرصيد الخاص بية 

double Balance=0;
void checkBalance()
{
    cout <<"your is Balance: " << Balance <<" EGP\n\n";
}

// الكود ده لى لايداع بيطلب من المستخدم المبلغ ويضيف على الرصيد بتاعة  

double deposit()
{
    double amountMoney;
    cout <<"enter your amount to Deposit: ";
    cin>>amountMoney;

    Balance += amountMoney;  // Balance = Balance + amountMoney 

    cout <<"Successfully deposited\n\n";
    return Balance;
}

// الكود ده لى عملية السحب بيطلب من المستخدم المبلغ ال عايز يسحبة ويخصمة من المبلغ لاساسى

double Withdraw()
{
    double amountMoney;
    cout <<"enter your amount to Withdraw: ";
    cin>>amountMoney;

    if (amountMoney > Balance )
    {
        cout <<"The money is not enough";
        return Balance;
    }
    else
    {
        Balance -= amountMoney;  // Balance = Balance - amountMoney
        cout <<"The money has been withdrawn successfully\n\n";
        return Balance;
    }
}

// الكود ده بيجمع كل الدوال المكينة وينفذ كل لاكودا والمستخدم يدخل رقم العملية ويقدر يستخدم البرنامج

void ATM_Operations ()
{
    int choice;
    do
    {
        cout <<"       ■■■■■■■■■■■■■■■■■ ATM ■■■■■■■■■■■■■■■■■\n\n";
        cout << "1- Check Balance\n";
        cout << "2- Deposit Money\n";
        cout << "3- Withdraw Money\n";
        cout << "4- Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            checkBalance();
            break;

        case 2:
            cout << deposit();
            break;

        case 3:
            cout << Withdraw();
            break;

        case 4:
            cout << "Thank you for using ATM!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);
}

          // ############# Digital Clock => ساعة رقمية #############
void input_time()
{
    int hour , min , sec , choice;
    cout <<"***************** time *****************\n";
    cout <<"enter hour: ";
    cin >> hour;
    cout <<"enter min: ";
    cin >> min;
    cout <<"enter sec: ";
    cin >> sec;
    
    while(true)
    {
        system ("clear");
        sec++;
        
        if (sec > 59)
        {
            sec = 0;
            min++;
        }
        if (min > 59)
        {
            min = 0;
            hour++;
        }
        if (hour > 23)
        {
            hour = 0;
        }
        
        cout <<"***************** time *****************\n";
        cout << hour << ":" << min << ":" << sec<< endl;

        sleep (1);
           
    }
}

               // ######## مكان تنفيذ كل لاكواد ########
 //الكود ده فية القائمة الرائسية ال رح تظهر لى مستخدم بعد مايدخل اليوزر والباسورد رح يظهر لية تسع اختيارات والمستخدم يدخل رقم العملية ال محتاجها وفى هذا القائمة الرئسية مجمع كل الدول فيها بحيث العملية تكون سهلة على المستخدم

void Show_Menu()
{
  int choice;
  while (true)
  {
    Design();
    cout << "   ■■■■■■■■■■■■■■■■■■ Main Menu ■■■■■■■■■■■■■■■■■■ \n \n";
    cout << "1- Python\n";
    cout << "2- C++\n";
    cout << "3- java\n";
    cout << "4- java Script\n";
    cout << "5- Calculator\n"; 
    cout << "6- Positive or negative\n";
    cout << "7- Even or Odd\n";
    cout << "8- student system\n";
    cout << "9- ATM\n";
    cout << "10- Digital Clock\n";
    cout << "11- Exit\n";
    Design();
    cout << "                  ■■■■■■■■■■■■■■■■■■ \n";    
    cout << "enter your choice: ";    
    cin >> choice;    
    Design();
    switch(choice)
    {
      case 1:
      cout<<"Python is used in Cyber Security and AI\n";
      break;
      case 2:
      cout<<"C++ is used in systems and performance applications\n";
      break;
      case 3:
      cout<<"Java is used in large systems and Android apps\n";
      break;
      case 4:
      cout<<"JavaScript is used for web development\n";    
      break;
      case 5:
      Calculator();
      break;
      case 6 :
      checkSign();
      break;
      case 7 :
      checkEvenOdd();
      break;
      case 8 :
      StudentMenu();
      break;
      case 9:
      ATM_Operations();
      break;
      case 10:
      input_time();
      break;
      case 11:
      cout<<"Goodbye\n";
      return;
      default:
      cout <<"Invalid choice\n";
    }
  }
}

                  // ######## ده الدالة لأساسية لتنفيذ لاكواد ########

// فى هذا الدلة هيا الدلة الرائسية ال رح تشغل الكود بلكامل وموجود فيعا عملية المحاولة لما المتسخدم يدخل اليوزر والباسورد المستخدم لية ثلات محاولات فقط ان عمل اكثر من ثلاث محاولات رح يخرجو من النظام بلكامل 

int main()
{
  int attempts = 3;
  bool TheSuccess = false;

  while (attempts > 0 )
  {
    if (login() == 1)
    {
      cout << "Signed in successfully\n";    
      TheSuccess= true;
      break;
    }
    else
    {
      attempts--;
      cout <<"Wrong data please try again: " << attempts <<endl;
      Design();
    }
  }
  if (TheSuccess)
  {
    Show_Menu();
  }
  else
  {
    cout <<"\nAccount locked \n\n";
  }
  return 0;
}