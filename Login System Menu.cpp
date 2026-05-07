#include <iostream>
using namespace std;
int main()
{
    string my_name, use_pasw;
      // متغيرين من نوع String لاستقبال لاسم والباسورد
    string thesName = "mohamed", thesPassword = "1234";
            // متغيرين من النوع String فية لاسم والباسورد ال المستخدم رح يدخلهم
    string str ="________________________________________\n"; // هذا الكود اختصار لى المساحة فى الكود
    int num;
      // متغيرين من النوع integer
    cout << "===================Login system===================\n";
    cout << endl;

    cout <<"enter your name: "; // لاستقبال لاسم
    cin >> my_name;
                // لتخزين لاسم
    cout << str << endl;
                // فاصل
    cout <<"enter your password: "; // لاستقبال الباسورد
    cin >> use_pasw ;
                // لتخزين الباسورد
    cout << str << endl;
                //فاصل
    if (my_name == thesName && use_pasw == thesPassword )  // عملية مقارنة بين لاسم والباسورد ال المستخدم دخلها
    {
        cout <<"Signed in successfully ☑️\n"; // لون الباسورد ولاسم صح هيطبع لامر ده
        cout << str << endl;

        // هنا بقا لما يسجل الدخول بنجاح رح يظهر لية ارربع خيارات ويختار واحد منهم
        cout << "Please choose the right number 🔎\n"<<endl;
        cout <<"1- python ";
        cout <<"2- c++ \n";
        cout <<"3- java \n";
        cout <<"4- java script \n";
        cout << str << endl;

        cout <<"enter your number: "; // هنا بيقولك ادخل الرقم ال جنب الخيار ال اختارته
        cin >> num;
           // رح يخزن الرقم فى المتغير ده
        cout << str << endl;// هنا بقا رح يجيب الرقم ال تخزن فى المتغير ويقارنة ويطلع الناتج الصح
        switch (num)
        {
        case 1:
            cout <<"Python Lee Cyber Security Tools \n";
              // لو دخل الرقم
            break;
        case 2:
            cout <<"C++ is used in operating systems \n";
               // لون دخل الرقم اتنين
            break;
        case 3:
            cout <<"Use Java to develop games and handle huge data \n";
              // لو دخل الرقم تلاتة
            break;
        case 4:
            cout <<"Java Script is used to interact with websites \n"; // لو دخل الرقم
            break;
        default:
              // لو مدخلش اى رقم من لاربع ارقام ال فوق رح ينفذ لأمر ده
            cout << "no sorry : enter num";
        }
    }
    else // هنا لو مدخلش السم والباسورد صح رح ينفذ لأمر ده
    {
        cout << "Please enter the correct name or password ❎️ \n";
    }
    return 0;
}