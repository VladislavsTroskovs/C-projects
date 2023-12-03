// http://cppstudio.com/cat/285/  (Level: Easy)
// test git repository

#include <iostream>
#include<cmath>

using namespace std;
void Task_1_Easy();
void Task_2_Easy();
void Task_3_Easy();
void Task_5_Easy();

int main()
{
    //Task_1_Easy();
    //Task_2_Easy();
    //Task_3_Easy();
    //Task_5_Easy();
    return 0;
}
void Task_1_Easy() {
    int X_number;
    float Z, B, A, Betta, Y=0;
    cout << "Enter number of X: "; cin >> X_number;
    float* arr = new float[X_number];
    for (int i = 0; i < X_number; i++) {
        cout << "Enter value Z, B, A, Betta for X" << i + 1 << ": " << endl;
        cout << "Z = "; cin >> Z;
        cout << "B = "; cin >> B;
        cout << "A = "; cin >> A;
        cout << "Betta = "; cin >> Betta;
        arr[i] = pow(Z, 3) - B + pow(A, 2) / pow(tan(Betta), 2);
        //cout << arr[i];
        Y = Y + arr[i];
    }
    cout << "\nY = " << Y << endl;
    delete[] arr;
}
 void Task_2_Easy() {
     int N, k, Sum = 0;
     cout << "Enter N: "; cin >> N;
     cout << "Enter degree k: "; cin >> k;
     int* arr = new int[N];
     for (int i = 1; i <= N; i++) {
         arr[i - 1] = pow(i, k);
         Sum += arr[i - 1];
         cout << arr[i - 1]<<" + ";
     }
     cout << "\nSum: " << Sum << endl;
     delete[] arr;
 }
 void Task_3_Easy() {
     short unsigned int Value  = 12;
     do {
         cout << "Enter value 10 - 99: "; cin >> Value;
         if (Value > 99 || Value < 10) { cout << "Not correct input!..."; 
         system("pause>null");
         system("cls");
         }
         
     } while (Value < 10 || Value >99);
     short first, second;
     second = Value % 10;
     first = Value / 10;
     if (first > second) {
         cout << "\n" << first << " - number, which is larger." << endl;
         cout << second << " - number, which is smaller." << endl;
     }
     else if (first < second) {
         cout << endl << second << " - number, which is larger." << endl;
         cout << first << " - number, which is smaller." << endl;
     }
     else cout << "\nNumbers are equal." << endl;
 }
 void Task_5_Easy() {
     int number, power, result = 0;
     cout << "Enter number: "; cin >> number;
     cout << "Enter power: "; cin >> power;
     if (power == 0) result = 1;
     else if (power > 0) {
         result = number;
         for (int i = 1; i < power; i++) {
             result = result * number;
         }
     }
     cout << "\nResult: " << result;
 }
