#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;
void info(){
    cout<<"It is simple calculator on C++"<<endl;
    cout<<"Author: Vladislav Troskov"<<endl<<endl;
    cout<<"Actions: addition(*), subtraction(-), multiplication(*), division(/)..."<<endl<<endl;
}
float multiplication(float first, float second){
    return first*second;
}
float division(float first, float second){
    if(second == 0) throw 0;
    else return first/second;
}
float addition(float first, float second){
    return first+second;
}
float subtraction(float first, float second){
    return first-second;
}
float calculate(float &first, float &second, char &sign, float &result){
    switch(sign){
        case '*': result=multiplication(first, second);
                break;
        case '/':  try{
                    result=division(first, second);}
                    catch(int err){
                        if(err == 0)cout<<"Can't divide by 0"<<endl;
                        }
                break;
        case '+': result=addition(first, second);
                break;
        case '-': result=subtraction(first, second);
                break;
        default: cout<<"ERROR! Unknown sign."<<endl;
        }
    return result;
}
void input(float &first, float &second, char &sign){
    //cout<<"Input first number: "; 
    cin>>first;
    //cout<<"Input action: "; 
    cin>>sign;
    //cout<<"Input second number: "; 
    cin>>second;
}

int main(){
    float first, second, result;
    char sign, repeat;
    do{
    system("cls");
    info();
    input(first, second, sign);
    calculate(first, second, sign, result);
    cout<<endl<<first<<" "<<sign<<" "<<second<<" = "<<result<<endl<<endl;
    cout<<"One more time? Yes(y) or No(...)"; cin>>repeat;
    system("cls");
    }while(repeat=='y');
    
    

system("pause>nul");
return 0;

      }
