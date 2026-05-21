#include <iostream>
#include <cmath>
#include <unistd.h>
#include <fstream>
using namespace std;

void ATM_Operations ();
// ######## Login => نظام تسجيل الدخول ########

// الكود ده بيطلب من المستخدم يدخل اليوزر والباسورده
bool Login()
{
  string UserName, Password;
  string FileUserName, FilePassword;
  
  cout << "enter your name: ";
  cin >> UserName;
  
  cout << "enter your password: ";
  cin >> Password;
  
  ifstream file("Users.txt"); // رح يفتح الملف عشان يشوف ايش الموجود فى الملف 
  while (file >> FileUserName >> FilePassword)
  {
    if (UserName == FileUserName && Password == FilePassword) // رح يقارن اليوزر المستخدم دخلة بى اليوزر الموجود فى الملف والبساورد كذلك
    {
      file.close(); // بعد مايخلص رح يقفل الملف 
      return true;
    }
  }
  file.close();
  return false; // رح يخرج من الدالة ده ويدخل على الدالة القائمة الكببره
}


void Register()
{
  string UserName, Password;
  
  cout << "enter your name: ";
  cin >> UserName;
  
  cout << "enter your password: ";
  cin >> Password; cout<<"\n";
  
  ofstream file("Users.txt", ios::app); // هنا رح يفتح الملف ويحفظ اليوزر والباسورد الجديد المسنخدم دخلو
  
  file << UserName << " " << Password <<endl; // رح يحفظ الباسورد واليوزر بى الشكل ده عشان يبقا مرتب فى الملفfile 
  
  file.close(); // قفل الملف بعد الانتهاء 
  cout << "Account created successfully\n";
}

bool Start_Menu()
{
  int choice;
  
  cout << "   ■■■■■■■■■■■■■■■■■■ welcome ■■■■■■■■■■■■■■■■■■ \n \n";
  cout << "1- Login\n";
  cout << "2- Register\n";
  cout << "3- Exit\n";
  
  cout << "enter your choice: ";
  cin >> choice;
  
  if(choice == 1) // رح يقارن بى الرقم المستخدم دخلو
  {
    if (Login() == 1)
    {
      cout<<"\nLogin successfully\n";
      return true;
    }
    else
    {
      cout<<"\nWrong username or password\n\n";
      return false;
    }
  }
  else if(choice == 2)
  {
  Register();
  return Start_Menu();
  }
  else // رح يخرجو لو دخل رقم ثلاثة
  {
    if(choice==3)
    {
      cout<<"Goodbye\n\n";
      return false;
    }
    else
    {
      cout<<"Please enter the correct number\n";
    }
    return false;
  }
  return false;
}

// ######## Calculator => نظام الة حاسبة ########

// الكود ده الة حاسبة بيطلب من المستخدم يدخل الرقم لاول وبعدين العملية الحسابية وبعدين يدخل الرقم التانى وينفذ العملية الحسابية كلها

void Process()
{
  double num1, num2;
  char op;
  
  cout <<"\n   ■■■■■■■■■■■■ slot calculator ■■■■■■■■■■■■\n\n";
  
  cout << "enter Number ( 1 ): ";
  cin >> num1;
  
  cout << "enter your [ + , - , * , / , % , ^ ]: ";
  cin >> op;
  
  cout << "enter Number ( 2 ): ";
  cin >> num2;
  
  switch (op)
  {
    case '+' :
    cout << num1 << " + " << num2<<" = "<< num1 + num2 << endl << endl;
    break;
    case '-' :
    cout << num1 << " - " << num2 << " = " << num1 - num2 << endl << endl;
    break;
    case '*' :
    cout << num1 << " * " << num2 << " = " << num1 * num2 << endl << endl;
    break;
    case '/' :
    if (num2 ==0)
    {
      cout << "The number you entered is not divisible by zero  \n";
    }
    else
    {
      cout << num1 << " / " << num2 << " = " << num1 / num2 << endl << endl;
    }
    break;
    case '%' :
    if (num2 == 0)
    {
      cout <<"Cannot divide by zero";
      break;
    }
    else
    {
      cout << num1 << " % " << num2 << " = " << int(num1) % int(num2) << endl << endl;
      break;
    }
    case '^' :
    cout << num1 << " ^ " << num2 << " = " << pow(num1, num2) << endl << endl;
    break;
    default:
    cout <<"There is an error in the calculation check the operation";
  }
}

void corners()
{
  double num;
  char op;
  
  cout <<"\n   ■■■■■■■■■■ Calculation of angles ■■■■■■■■■■\n\n";
  
  cout << "enter Number : ";
  cin >> num;
  
  cout << "enter your [ sin => s , cos => c , tan => t, sqrt => q ]: ";
  cin >> op;
  
  switch (op)
  {
    case 's' :
    cout << "sin" << "(" << num << ")" << " = " << sin(num) << endl << endl;
    break;
    case 'c' :
    cout << "cos" << "(" << num << ")" << " = " << cos(num) << endl << endl;
    break;
    case 't' :
    cout << "tan" << "(" << num << ")" << " = " << tan(num) << endl << endl;
    break;
    case 'q':
    if (num < 0)
    {
      cout <<"The number cannot be negative\n";
      break;
    }
    else
    {
      cout << "√" << num << " = " << sqrt(num) << endl << endl;
      break;
    }
    default:
    cout <<"There is an error in the calculation check the operation";
  }
}

void calculator_list()
{
  int choice;
  do
  {
    cout << "\n      ■■■■■■■■■■■ welcome ■■■■■■■■■■■\n\n";
    cout <<"1- Account to set up \n";
    cout <<"2- Zoya account \n";
    cout <<"3- Exit \n";
    
    cout << "enter your number: ";
    cin >> choice;
    
    switch (choice)
    {
      case 1:
      Process();
      break;
      case 2:
      corners();
      break;
      case 3 :
      return;
      default:
      cout << "\n==========================\n";
      cout << "Enter the correct number\n";
      cout << "==========================\n";
    }
  } while(choice!=3);
}

// ######## positive or negative => نظام الموجب والسالب ########

//الكود ده بيطلب من المستخدم يدخل رقم ويشوف الرقم ده موجب ولا سالب
void checkSign ()
{
  int num;
  
  cout <<"enter your number: ";
  cin >> num; cout<<"\n";
  
  if (num >=0)
  {
    cout <<"The number is positive \n\n";
  }
  else
  {
    cout <<"The number is negative \n\n";
  }
}

// ######## Even or Odd => نظام الفردى والزوجى  ########

// الكود ده بيطلب من المستخدم يدخل رقم ويشوف الرقم ده زوجى ولا فردى
void checkEvenOdd()
{
  int num;
  
  cout <<"enter your number: ";
  cin >> num; cout<<"\n";
  
  if(num % 2 == 0)
  {
    cout <<"Even number\n\n";
  }
  else
  {
    cout <<"Odd number\n\n";
  }
}

// ######## Student management system => نظام اداه الطلاب ########

bool teacher_Login()
{
 string User_Teacher="Mohamed";
 string Password_Teacher="1234";
 
 string userTeacher , passwordTeacher;
 
 cout<<"enter name the teacher: ";
 cin >> userTeacher;
 cout<<"enter password the teacher: ";
 cin >>passwordTeacher;
 
 while (true)
 {
   if (User_Teacher == userTeacher && Password_Teacher == passwordTeacher )
   {
     cout <<"Signed in successfully\n";
     cout <<"\nHello teacher "<< User_Teacher<<endl;
     return true;
   }
   else
   {
     return false;
   }
 }
}

bool students_login()
{
  string user_studeant , ID_studeant;
  string file_user_studeant , file_ID_studeant ;
  
  cout <<"enter your username: ";
  cin >>user_studeant;
  
  cout <<"enter your ID: ";
  cin >>ID_studeant;
  
  ifstream file("Data_Studeant.txt");
  while (file >> file_user_studeant >> file_ID_studeant)
  {
    if(user_studeant == file_user_studeant && ID_studeant== file_ID_studeant)
    {
     file.close();
     return true;
    }
  }
  file.close();
  return false;
}

void students_Register()
{
  string userstudeant,IDstudeant;
  
  cout <<"enter your username: ";
  cin >>userstudeant;
  
  cout <<"enter your ID: ";
  cin >>IDstudeant;
  
  ofstream file("Data_Studeant.txt" , ios::app);
  
  file << userstudeant << " " << IDstudeant << endl;
  
  file.close();
  cout << "Account created successfully\n";
}

bool list()
{
  int choice;
  cout <<"\n     ■■■■■■■■■■■■■■■■ welcome ■■■■■■■■■■■■■■■■\n\n";
  cout << "1- Login\n";
  cout << "2- Register\n";
  cout << "3- Exit\n";
  
  cout << "enter your choice: ";
  cin >> choice;
  
  if(choice == 1 )
  {
    if(students_login() == 1)
    {
      cout<<"\nLogin successfully\n";
      return true;
    }
    else 
    {
      cout<<"\nPlease check the student's name or ID\n";
      return false;
    }
  }
  else if (choice == 2)
  {
    students_Register();
    return list();
  }
  else
  {
    return false;
  }
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

string name[100];
int age[100];
int ids[100];
int countStudent = 0;

void addStudent()
{
  cout <<"enter your name: ";
  cin >>name[countStudent];
  
  cout <<"enter your age: ";
  cin >>age[countStudent];
  
  cout <<"enter your ID: ";
  cin >>ids[countStudent];
  
  ofstream file ("studeants.txt" , ios::app);
  file << name[countStudent] << " " << age[countStudent] << " " <<  ids[countStudent] << endl;
  file.close();
  countStudent++;
}

void Students_read()
{
  countStudent = 0;
  ifstream file ("studeants.txt");
  while (file >> name[countStudent] >> age[countStudent] >> ids[countStudent])
  {
    countStudent++;
  }
  file.close();
}

void showStudent ()
{
  for (int i=0; i < countStudent; i++)
  {
    cout << "nam: " << name[i];
    cout << "  age: " << age[i];
    cout << "  ID: " << ids[i] << endl;
  }
}

void searchStudent()
{
  int id;
  bool found = false;
  
  cout <<"enter my student ID: ";
  cin >> id;
  
  for (int i = 0; i < countStudent; i++)
  {
    if (ids[i] == id)
    {
      cout << "Found: " << name[i] << endl;
      found = true;
      break;
    }
  }
  if (!found)
  {
    cout << "Not Found\n";
  }
}

void teacher_Choice_List()
{
  int che;
  do 
  {
    cout <<"\n     ■■■■■■■■■■■■ View menu ■■■■■■■■■■■■\n\n";
    cout <<"1- Add students\n";
    cout <<"2- Show students\n";
    cout <<"3- Searching students\n";
    cout <<"4- Exit\n";
    
    cout <<"enter your choice: " ;
    cin >>che;
    switch (che)
    {
      case 1:
      addStudent();
      break;
      case 2:
      Students_read();
      showStudent();
      break;
      case 3:
      Students_read();
      searchStudent(); 
      break;
    }
  } while (che !=4);
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void Computer_Science()
{
  int choice;
  do 
  {
    cout <<"\n     ■■■■■■■■■■■ List of chapters study ■■■■■■■■■■■\n\n";
    cout <<"1- first payment\n";
    cout <<"2- second batch\n";
    cout <<"3- third batch\n";
    cout <<"4- Fourth batch\n";
    cout <<"5- Fifth batch\n";
    cout <<"6- Exit\n";
    
    cout <<"Choose your current study payment: ";
    cin >>choice;
    
    switch(choice)
    {
      case 1:
      cout <<"________________________________\n\n";
      cout <<"Study subjects your first batch:\n";
      cout <<"________________________________\n\n";
      cout <<"▪︎ Math 1\n";
      cout <<"▪︎ English 1\n";
      cout <<"▪︎ computer basics\n";
      cout <<"▪︎ programming basics c++\n";
      cout <<"▪︎ Basics of algorithms\n";
      cout <<"▪︎ Logical thinking\n";
      cout <<"▪︎ aProblem Solving\n";
      break;
      case 2:
      cout <<"________________________________\n\n";
      cout <<"Your second batch study materials:\n";
      cout <<"________________________________\n\n";
      cout <<"▪︎ Math 2\n";
      cout <<"▪︎ English 1\n";
      cout <<"▪︎ computer maintenance\n";
      cout <<"▪︎ advanced programming c++\n";
      cout <<"▪︎ Advanced algorithms\n";
      cout <<"▪︎ programming\n";
      cout <<"▪︎ Problem Solving\n";
      break;
      case 3:
      cout <<"________________________________\n\n";
      cout <<"Your third batch study materials:\n";
      cout <<"________________________________\n\n";
      cout <<"▪︎ Math \n";
      cout <<"▪︎ English 2\n";
      cout <<"▪︎ computer maintenance\n";
      cout <<"▪︎ advanced programming c++\n";
      cout <<"▪︎ Advanced algorithms\n";
      cout <<"▪︎ programming\n";
      cout <<"▪︎ Problem Solving\n";
      break;
      case 4:
      cout <<"________________________________\n\n";
      cout <<"Your fourth batch study materials:\n";
      cout <<"________________________________\n\n";
      cout <<"▪︎ Math 2\n";
      cout <<"▪︎ Englch 1\n";
      cout <<"▪︎ computer maintenance\n";
      cout <<"▪︎ advanced programming c++\n";
      cout <<"▪︎ Advanced algorithms\n";
      cout <<"▪︎ programming\n";
      cout <<"▪︎ Problem Solving\n";
      break;
      case 5:
      cout <<"________________________________\n\n";
      cout <<"Your Fifth Batch Study Materials:\n";
      cout <<"________________________________\n\n";
      cout <<"▪︎ Math 2\n";
      cout <<"▪︎ English 1\n";
      cout <<"▪︎ computer maintenance\n";
      cout <<"▪︎ advanced programming c++\n";
      cout <<"▪︎ Advanced algorithms\n";
      cout <<"▪︎ programming\n";
      cout <<"▪︎ Problem Solving\n";
      break;
      case 6:
      return;
      default:
      cout <<"\nPlease choose a correct number\n";
    }
  }while(choice != 6);
}

void Specializations()
{
  int choice;
  do
  {
    cout <<"\n     ■■■■■■■■■■■ List of specialties ■■■■■■■■■■■\n\n";
    cout <<"1- Cyber Security\n";
    cout <<"2- Information Security\n";
    cout <<"3- Computer Science\n";
    cout <<"4- networks\n";
    cout <<"5- AI\n";
    cout <<"6- data science\n";
    cout <<"7- Exit\n";
    
    cout <<"Choose your major: ";
    cin >>choice;
    
    switch(choice)
    {
      case 1:
      cout <<"\nSpecialization materials are uploaded Cyber Security\n";
      break;
      case 2:
      cout <<"\nSpecialization materials are uploaded Information Security\n";
      break;
      case 3:
      Computer_Science();
      break;
      case 4:
      cout <<"\nSpecialization materials are uploaded networks\n";
      break;
      case 5:
      cout <<"\nSpecialization materials are uploaded AI\n";
      break;
      case 6:
      cout <<"\nSpecialization materials are uploaded data science\n";
      break;
      case 7:
      return;
      default:
      cout <<"\nPlease choose a correct number\n";
    }
    
  }while(choice != 7);
}

void Student_Choice_List()
{
  int choice;
  do
  {
    cout <<"\n     ■■■■■■■■■■■■ Specializations ■■■■■■■■■■■■\n\n";
    cout <<"1- Specializations\n";
    cout <<"2- Exit\n";
    
    cout <<"enter your choice: ";
    cin >>choice;
  
    switch(choice)
    {
      case 1 :
      Specializations();
      break;
      case 2 :
      return;
      default:
      cout <<"\nPlease choose a correct number\n";
    }
  }while (choice != 2);
}

void User_Select_List()
{
  int choice;
  do
  {
    cout <<"\n     ■■■■■■■■■■■■■■■■ welcome ■■■■■■■■■■■■■■■■\n\n";
    cout <<"1- teacher\n";
    cout <<"2- Student\n";
    cout <<"3- Exit\n";
    
    cout <<"enter your choice: ";
    cin >>choice;
    
    switch(choice)
    {
      case 1 :
      if(teacher_Login()==1)
      {
        teacher_Choice_List();
        break;
      }
      else
      {
        cout<<"\nPlease check you teacher's name or password\n";
        break;
      }
      break;
      case 2 :
      if (list()==1)
      {
        Student_Choice_List();
        break;
      }
      else
      {
        break;
      }
      break;
      case 3 :
      return;
      default:
      cout <<"\nPlease choose a correct number\n";
    }
  }while (choice != 3);
}

// ********** نظام ATM **********
//الكود ده بيظهر للمستخدم الرصيد الخاص بية


bool User_name()
{
  string UserName, ID;
  string file_user_name, file_ID;
  
  cout <<"enter your username: ";
  cin >>UserName;
  
  cout <<"enter your ID: ";
  cin >>ID;
  
  ifstream File("UserATM.txt");
  
  while(File >> file_user_name >> file_ID)
  {
    if (UserName == file_user_name && ID == file_ID)
    {
      File.close();
      return true;
    }
  }
  File.close();
  return false;
}

void Create_user()
{
  string user , ID;
  string UserName , id;
  
  cout <<"enter your username: ";
  cin >>user;
  
  cout <<"enter your ID: ";
  cin >>ID;
  
  cout <<"\nRe enter your username and id to validate the data:\n\n";
  
  cout <<"enter your username: ";
  cin >>UserName;
  
  cout <<"enter your ID: ";
  cin >>id;
  
  if (user == UserName && ID == id)
  {
    ofstream File("UserATM.txt", ios::app);
    File << user << "  " << ID << endl;
    
    File.close();
    cout <<"\nAccount created successfully\n\n";
    ATM_Operations();
  }
  else
  {
    cout << "\nData does not match\n\n";
  }
}

bool Str_Menu()
{
  int choice;
  
  cout << "\n   ■■■■■■■■■■■■■■■■■■■ welcome ■■■■■■■■■■■■■■■■■■■ \n \n";
  
  cout << "1- Login\n";
  cout << "2- Register\n";
  cout << "3- Exit\n";
  
  cout << "enter your choice: ";
  cin >> choice;
  
  if(choice == 1)
  {
    if (User_name() == 1)
    {
      cout<<"Login successfully\n";
      return true;
    }
    else
    {
      cout<<"\nWrong username or password\n";
      return false;
    }
  }
  else if(choice == 2)
  {
    Create_user();
    return Str_Menu();
  }
  else if(choice == 3)
  {
  return false;
  }
  else
  {
   cout<<"Invalid choice\n";
   return false;
  }
  return false;
}

double Balance=0;

void checkBalance()
{
  cout <<"your is Balance: " << Balance <<" EGP\n\n";
}

double deposit()
{
  double amountMoney;
  cout <<"enter your amount to Deposit: ";
  cin>>amountMoney;
  
  Balance += amountMoney;  // Balance = Balance + amountMoney 
  
  cout <<"Successfully deposited\n\n";
  return Balance;

}

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
      deposit();
      break;
      case 3:
      Withdraw();
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
  int hour, min, sec, choice;
  
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

void programming_languages()
{
  int choice;
  do 
  {
    cout <<"\n  ■■■■■■■■■■■■■■ programming ■■■■■■■■■■■■■■\n\n";
    cout << "1- Python\n";
    cout << "2- C++\n";
    cout << "3- java\n";
    cout << "4- java Script\n";
    cout << "5- Exit\n";
    
    cout << "enter your choice: ";
    cin >> choice;
    
    switch(choice)
    {
      case 1:
      cout <<"\nPython is used in Cyber Security and AI\n\n";
      break;
      case 2:
      cout<<"\nC++ is used in systems and performance applications\n\n";
      break;
      case 3:
      cout<<"\nJava is used in large systems and Android apps\n\n";
      break;
      case 4:
      cout<<"\nJavaScript is used for web development\n\n";
      break;
      case 5:
      return;
      default:
      cout<<"\nPlease enter the correct number\n\n";
    }
  }while(choice != 5);
}

// ######## مكان تنفيذ كل لاكواد ########
//الكود ده فية القائمة الرائسية ال رح تظهر لى مستخدم بعد مايدخل اليوزر والباسورد رح يظهر لية تسع اختيارات والمستخدم يدخل رقم العملية ال محتاجها وفى هذا القائمة الرئسية مجمع كل الدول فيها بحيث العملية تكون سهلة على المستخدم

void Show_Menu()
{
  int choice;
  do 
  {
    cout << "\n\n   ■■■■■■■■■■■■■■■■■ Main Menu ■■■■■■■■■■■■■■■■■ \n \n";
    
    cout << "1- programming languages\n";
    cout << "2- Calculator\n";
    cout << "3- Positive or negative\n";
    cout << "4- Even or Odd\n";
    cout << "5- student system\n";
    cout << "6- ATM\n";
    cout << "7- Digital Clock\n";
    cout << "8- Exit\n";
    
    cout << "\n                 ■■■■■■■■■■■■■■■■■■ \n\n";
    
    cout << "enter your choice: ";
    cin >> choice;
    
    switch(choice)
    {
      case 1:
      programming_languages();
      break;
      case 2:
      calculator_list();
      break;
      case 3:
      checkSign();
      break;
      case 4:
      checkEvenOdd();
      break;
      case 5:
      User_Select_List();
      break;
      case 6:
      if (Str_Menu()==1)
      {
        ATM_Operations();
        break;
      }
      break;
      case 7:
      input_time();
      break;
      case 8:
      cout<<"Goodbye\n\n";
      return;
      default:
      cout <<"Invalid choice\n";
    }
  }while(choice != 8);
}
// ######## ده الدالة لأساسية لتنفيذ لاكواد ########

// فى هذا الدلة هيا الدلة الرائسية ال رح تشغل الكود بلكامل وموجود فيعا عملية المحاولة لما المتسخدم يدخل اليوزر والباسورد المستخدم لية ثلات محاولات فقط ان عمل اكثر من ثلاث محاولات رح يخرجو من النظام بلكامل

int main()
{
  int attempts = 3;
  
  while (attempts > 0 )
  {
    if (Start_Menu() == 1)
    {
      Show_Menu();
      break;
    }
    else
    {
      attempts--;
      cout <<"Wrong data please try again: " << attempts <<endl << endl;
    }
  }
  return 0;
}