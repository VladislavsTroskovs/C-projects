#include<string>
#include<iostream>
#include<ctime>
#include<algorithm>

using namespace std;

template <typename T>
void CreateArr(T* arr, int& length);
template <typename T1>
void Print(T1* arr, int length);

void SearchInText();
void SearchNumber(int* arr, int length);
void LinearAlgorithm(int* arr, int length);
void BinaryAlgorithm(int* arr, int length);
void InterpolationAlgorithm(int* arr, int length);
void Algorithms(int* arr, int length);
void BubbleSort(int* arr, int length);
void ShakerSort(int* arr, int length);
void SelectSort(int* arr, int length);
void InsertSort(int* arr, int length);
void ShellSort(int* arr, int length);
void QuickSort(int* arr, int length);
void NaiveSearch();


int main()
{
    int action1, length; //action1 - Sort, Search or Exit... length - array size
    do {
        cout << "\nEnter what would you like to do\n\t1 - Sort array\n\t2 - Search pattern in text\n\t3 - Search number in array\n\t0 - Exit\n"; cin >> action1;
        if (action1 == 1) {
            cout << "Enter array size: "; cin >> length;
            int* arr = new int[length];

            CreateArr<int>(arr, length);
            cout << "\nArray: "; Print<int>(arr, length);
            cout << endl;
            Algorithms(arr, length);
            delete[] arr;
        }
        else if (action1 == 2) {
            SearchInText();
        }
        else if (action1 == 0) cout << "Good by!...See you next time...";
        else if (action1 == 3) {
            cout << "Enter array size: "; cin >> length;
            int* arr = new int[length];

            CreateArr<int>(arr, length);
            cout << "\nArray: "; Print<int>(arr, length);
            cout << endl;
            SearchNumber(arr, length);
            delete[] arr;
        }
            else cout << "This action doesn't exist!";
        system("pause>null");
        system("cls");
    } while (action1 != 0);

    return 0;
}

template <typename T>
void CreateArr(T* arr, int& length) {
    int min, max, chooze;
    cout << "Chooze function to create array ..." << endl;
    cout << "\t\t\t1 - Create manually\n\t\t\t2 - Create random number array" << endl;
    cin >> chooze;
    switch (chooze) {
    case 1: 
        for (int i = 0; i < length; i++) {
        cout << "arr[" << i << "] = "; cin >> *(arr + i);
        }
          break;
    case 2: do {
            cout << "Input array value diapazon: " << endl;
            cout << "Min: "; cin >> min;
            cout << "Max: "; cin >> max;
            if (min >= max) {
                cout << "Minimal value can't be lagrer than maximal" << endl;
                cout << "Try again..." << endl;
                system("pause>null");
                system("cls");
            }
        } while (min >= max);
        srand(time(NULL));
        for (int i = 0; i < length; i++)
            *(arr + i) = min + rand() % (max - min + 1);
        break;
    default: cout << "This action doesn't exist" << endl;
    }
}

template <typename T1>
void Print(T1* arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}
//-------------------------------------------------Sort Algorithms-------------------------------------------
void BubbleSort(int* arr, int length) {
    int C = 0, A = 0; //C - comparisons. A - swaps
    cout << "\t\t\t\t\tBubbleSort Algorithm!" << endl << endl;

        for (int i = 0; i < length - 1; i++) {
                cout << endl << i + 1 << " step: " << endl;
                    for (int j = 0; j < length - i - 1; j++) {
                        if (*(arr + j) > *(arr + j + 1)) {
                            swap(*(arr + j), *(arr + j + 1));
                            C++; A++;
                        }
                        else C++;
                        Print<int>(arr, length);
                    }
        }
    cout << "\nTotal Comparisons: " << C << endl;
    cout << "Total Swaps: " << A << endl;
}
void ShakerSort(int* arr, int length) {
    bool swapped = true;
    int start = 0, end = length - 1, C = 0, A = 0, step = 1;
    //C - comparisons. A - swaps, k - steps
    cout << "\t\t\t\t\tShakerSort Algorithm!" << endl << endl;
    while (swapped) {
        swapped = false;
        cout << endl << step << ". step (From left to right): " << endl;
        for (int i = start; i < end; i++) {
            if (*(arr + i) > *(arr + i + 1)) {
                swap(*(arr + i), *(arr + i + 1));
                A++; C++;
                swapped = true;
            }
            else C++;
            Print<int>(arr, length);
        }
        if (!swapped) {
            break;
        }
        end--;
        swapped = false;
        cout << endl << step << ". step (From right to left): " << endl;
        for (int i = end; i >= start; i--) {
            if (*(arr + i) < *(arr + i - 1)) {
                swap(*(arr + i), *(arr + i - 1));
                A++; C++;
                swapped = true;
            }
            else C++;
            Print<int>(arr, length);
        }
        step++;
        start++;
    }
    cout << "\nTotal Comparisons: " << C << endl;
    cout << "Total Swaps: " << A << endl;
}
void SelectSort(int* arr, int length) {
    int C = 0, A = 0; //C - comparisons. A - swaps
    int min, index;
    cout << "\t\t\t\t\tSelectSort Algorithm!" << endl << endl;
    for (int i = 0; i < length; i++) {
        min = *(arr + i);
        cout << endl << i + 1 << " step: " << endl;
        for (int j = i+1; j < length; j++) {
            if (*(arr + j) < min) {
                min = *(arr + j);
                index = j;
                C++;
            }
            else C++;
        }
        if (*(arr + i) > min) {
            *(arr + index) = *(arr + i);
            *(arr + i) = min;
            C++; A++;
        }
        Print<int>(arr, length);
    }
    cout << "\nTotal Comparisons: " << C << endl;
    cout << "Total Swaps: " << A << endl;
}
void InsertSort(int* arr, int length) {
    int C = 0, A = 0, temp; //C - comparisons. A - swaps
    cout << "\t\t\t\t\tInsertSort Algorithm!" << endl << endl;

    for (int i = 1; i < length; i++) {
        cout << endl << i << ". step: " << endl;
        temp = *(arr + i);
        for (int j = i; j >= 0 && *(arr+j-1)>temp; j--) {
            swap(*(arr + j), *(arr + j - 1));
            Print<int>(arr, length);
            A++;
        }
    }
    cout << "\n\nTotal Swaps: " << A << endl;
}
void ShellSort(int* arr, int length) {
    int C = 0, A = 0, step; //C - comparisons. A - swaps
    bool Swapped = false;
    cout << "\t\t\t\t\tShellSort Algorithm!" << endl << endl;

    for (step = length / 2; step >= 1; step = step / 2) {
        if(step!=1)cout << "\nStep = " << step << endl;
        else cout<< "\nStep = " << step << ". (InsertSort Algorithm)" << endl;
        for (int i = step; i < length; i++) {
            cout << "\ti = " << i << endl;
            for (int j = i-step; j >= 0; j -= step) {
                Swapped = false;
                if (*(arr + j) > *(arr + j + step)) {
                    swap(*(arr + j), *(arr + j + step));
                    C++; A++;
                    Swapped = true;
                }
                else C++;
                if(Swapped) Print<int>(arr, length);
            }
        }
    }

    cout << "\nTotal Comparisons: " << C << endl;
    cout << "Total Swaps: " << A << endl;
}
void QuickSort(int* arr, int length) {
    int C = 0, A = 0, step; //C - comparisons. A - swaps
    cout << "\t\t\t\t\tQuickSort Algorithm!" << endl << endl;

    

    cout << "\nTotal Comparisons: " << C << endl;
    cout << "Total Swaps: " << A << endl;
}//---------------NOT COMPLETE--------------------
//-------------------------------------------------Search Algorithms in Text----------------------------------------
void NaiveSearch() {
    string text, pattern;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter text where you would like to search...\n";
    getline(cin, text);
    cout << "\nEnter text which need to find...\n";
    getline(cin, pattern);
    if (text.size() > pattern.size()) {
        int quantity = 0;
        for (int i = 0; i <= text.size() - pattern.size(); i++) {
            int j;
            for (j = 0; j < pattern.size() && text[i + j] == pattern[j]; j++);
            if (j == pattern.size()) {
                cout << "Pattern found at index: " << i << endl;
                quantity++;
            }
        }
        if (quantity == 0)cout << "Pattern isn't find it the text!" << endl;
        else cout << "Total finding: " << quantity << endl;
    }
    else cout << "Pattern can't be larger than text!" << endl;
    //Память от переменной STRING освобождается сама (после области её видимости срабатывает деструктор)
}
//-------------------------------------------------Sort Algorithms Function--------------------------------------
void Algorithms(int* arr, int length) {
    int chooze;
    cout << "Chooze algorithm to sort the array: " << endl;
    cout << "\t1 - BubleSort\n\t2 - ShakerSort\n\t3 - SelectSort\n\t4 - InsertSort\n\t5 - ShellSort\n\t6 - QuickSort(-)\n";
    cin >> chooze;
    switch (chooze)
    {
    case 1: BubbleSort(arr, length);
        break;
    case 2: ShakerSort(arr, length);
        break;
    case 3: SelectSort(arr, length);
        break;
    case 4: InsertSort(arr, length);
        break;
    case 5: ShellSort(arr, length);
        break;
    default:
        cout << "This action doesn't exist!" << endl;
        break;
    }
}
//-------------------------------------------------Search In Text Function------------------------------------
void SearchInText() {
    int chooze_search;
    cout << "Enter which Search algorithm you would like to use\n\t1 - NaiveSearch\n";
    cin >> chooze_search;
    switch (chooze_search) {
    case 1: NaiveSearch();
        break;
    }
}
//-------------------------------------------------Search Number in Array----------------------------------------
void SearchNumber(int* arr, int length) {
    cout << "Which algorithm will use?\n\t1 - Linear algorithm\n\t2 - Binary algorithm\n\t3 - Interpolation Algorithm\n";
    int action2;
    cin >> action2;
    switch (action2) {
    case 1: LinearAlgorithm(arr, length);
        break;
    case 2: BinaryAlgorithm(arr, length);
        break;
    case 3: InterpolationAlgorithm(arr, length);
        break;
    }
}
void LinearAlgorithm(int* arr, int length) {
    int i, number;
    cout << "What number will search?"; cin >> number;
    cout << "\nResult: ";
    for (i = 0; i < length && *(arr+i) != number; i++);
    if (i < length) cout << "Is in array. Position: " << i << endl;
    else cout <<"Isn't in array";
}
void BinaryAlgorithm(int* arr, int length) {
    int i, L = 0, R = length - 1, number;
    int check = 0;
    for (int k = 0; k < length-1; k++) {
        if (*(arr + k) < *(arr + k + 1)) check++;
    }
    if (check != length - 1) {
        cout << "Array has to be sorted, so this array wiil be sorted automatically!\n";
        sort(arr, arr + length);
    }
    Print<int>(arr, length);
    cout << "What number will search?\n"; cin >> number;
    cout << "\nResult: ";
    i = (L + R) / 2;
    while (L <= R && *(arr+i) != number) {
        if (*(arr+i) < number) L = i + 1;
        else R = i - 1;
        i = (L + R) / 2;
    }
    if (*(arr+i) == number) cout << "Is in array. Position: " << i << endl;
    else cout << "Isn't in array\n";
}
void InterpolationAlgorithm(int* arr, int length) {
    int i, L = 0, R = length - 1, number;
    int check = 0;
    for (int k = 0; k < length - 1; k++) {
        if (*(arr + k) < *(arr + k + 1)) check++;
    }
    if (check != length - 1) {
        cout << "Array has to be sorted, so this array wiil be sorted automatically!\n";
        sort(arr, arr + length);
    }
    Print<int>(arr, length);
    cout << "What number will search?\n"; cin >> number;
    cout << "\nResult: ";
    i = L + (R - L) * (number - *(arr+L)) / (*(arr+R) - *(arr+L));
    while (L <= R && *(arr+i) != number) {
        if (*(arr+i) > number) R = i - 1;
        else L = i + 1;
        i = L + (R - L) * (number - *(arr+L)) / (*(arr+R) - *(arr + L));
    }
    if (*(arr+i) == number) cout << "Is in array. Position: " << i << endl;
    else cout << "Isn't in array\n";
}
