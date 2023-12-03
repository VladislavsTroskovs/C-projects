#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;
void game_hard(){
    short number, answer, n;
    cout<<"Chooze diapazon of numbers (The larger it is, the less chance to guess): 1 - "; cin>>n;
    number=1+rand()%n;
    cout<< "\nChance to guess: "<<(1.0/n*1.0)*100<<"%"<<endl;
    cout<< "Computer number: ?"<<endl;
    cout<< "Your answer: ";cin>>answer;
    if (answer==number) cout<<"\n\t\t\t\tYou are lucky! Congratulations!"<<endl<<endl;
    else cout<<"\n\t\t\t\tGAME OVER!!! You lose..."<<endl<<endl;
}
void game_easy(){
    short number, answer, n, chances=0;
    cout<<"Chooze diapazon of numbers (The larger it is, the less chance to guess): 1 - "; cin>>n;
    number=1+rand()%n;
    cout<< "Chance to guess: "<<(1.0/n*1.0)*100<<"%"<<endl;
    cout<< "Computer number: ?"<<endl;
    do{
    cout<< "Your answer: ";cin>>answer;
    if(answer<1 || answer>n) cout<<"Be careful! This number can't be..."<<endl;
    chances++;
    if (answer==number) {cout<<"\n\t\t\t\tCongratulations! You guessed right on the "<<chances<<" try!"<<endl;
                            break;}
    if(chances==n-2) cout<<"\nLast chance to guess!"<<endl;
    }while(answer!=number && chances<n-1);
    if(answer!=number && chances==n-1)cout<<"\n\t\t\t\tGAME OVER!!! You lose..."<<endl<<endl;
}

int main(){
    srand(time(NULL));
    char repeat;
    short mode;
    do{
        system("cls");
        cout<<"Chooze GAME MODE \n(Hard - 1. You have only one opportunity to guess!\nEasy - 2. You will have a lot of chances to guess the number!): ";
        cin>>mode;
        system("cls");
        if (mode==1) game_hard();
        else if (mode==2) game_easy();
        else cout<<"Wrong GAME MODE choise!"<<endl<<endl;
        cout<<"One more time? Yes(y) or No(...)";cin>>repeat;
    }while(repeat=='y');
    

system("pause>nul");
return 0;

      }
