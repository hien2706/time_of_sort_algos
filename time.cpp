#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;
//merge sort
void merge(int a[], int low, int mid, int high)
{
    int i = low,
        j = mid + 1,
        k = low;
    int* b = new int[high+1];
    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    }
    while (i <= mid)
        b[k++] = a[i++];
    while (j <= high)
        b[k++] = a[j++];
    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
    delete[] b;
}
void merge_sort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
/////////////////////////////////////
void interchange_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                swap(a[i], a[j]);
        }
    }
}
/////////////////////////////////////
void quick_sort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2, // choosing pivot in the middle
            pivot = a[mid],
            i = left,
            j = right;
        while (i < j)
        {
            while (a[i] < pivot) i++;
            while (a[j] > pivot) j--;
            if (i <= j)
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                i++; j--;
            }
        }
        quick_sort(a, left, j);
        quick_sort(a, i, right);

    }
}
/////////////////////////////////////
void heapify(int a[], int n, int i)
{
    int largest = i,
        left = 2 * i + 1,
        right = 2 * i + 2;
    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}
void build_max_heap(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
}
void heap_sort(int a[], int n)
{
    build_max_heap(a, n);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}
/////////////////////////////////////
void bubble_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}
/////////////////////////////////////
int getInteger()
{
    cout << "Please enter a number in range 1 to 100 million: ";
    int n;
    do {
        cin >> n;

    } while (n <= 0 && cout << "nhap dang hoang di pan." << endl);
    return n;
}
void generateArray(int* a, int n)
{
    
    for (int i = 0; i < n; i++)
    {
        a[i] = 1+rand()%n;
    }
}
void outputArray(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
void Menu()
{
    cout << "------------------MENU------------------" << endl;
    cout << "0. EXIT" << endl;
    cout << "1. Quick Sort" << endl;
    cout << "2. Merge Sort" << endl;
    cout << "3. Heap Sort" << endl;
    cout << "4. Interchange Sort" << endl;
    cout << "5. Bubble Sort" << endl;

}

void count_time_merge_sort(int* a, int n, int& flag)
{
    clock_t start = clock();
    merge_sort(a, 0, n - 1);
    clock_t end = clock();
    if(flag == 0){
        outputArray(a, n);
        flag = 1;
    }
    cout <<endl <<"time: " << (double)(end - start)/CLOCKS_PER_SEC << "s" << endl;
}
void count_time_interchange_sort(int* a, int n, int& flag)
{
    clock_t start = clock();
    interchange_sort(a, n);
    clock_t end = clock();
    if (flag == 0) {
        outputArray(a, n);
        flag = 1;
    }
    cout << endl << "time: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;
}
void count_time_quick_sort(int* a, int n, int& flag)
{
    clock_t start = clock();
    quick_sort(a,0 ,n-1);
    clock_t end = clock();
    if (flag == 0) {
        outputArray(a, n);
        flag = 1;
    }
    cout << endl << "time: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;
}
void count_time_heap_sort(int* a, int n, int& flag)
{
    clock_t start = clock();
    heap_sort(a, n);
    clock_t end = clock();
    if (flag == 0) {
        outputArray(a, n);
        flag = 1;
    }
    cout << endl << "time: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;
}
void count_time_bubble_sort(int* a, int n, int& flag)
{
    clock_t start = clock();
    bubble_sort(a, n);
    clock_t end = clock();
    if (flag == 0) {
        outputArray(a, n);
        flag = 1;
    }
    cout << endl << "time: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;
}





int main()
{
    int n = getInteger();
    int* a = new int[n];
    generateArray(a, n);
    char select;
    int choose;
    int flag = 1; // change to 0 if you want to print the array after sorted
    do{
        Menu();
        cout << "Please choose an algorithm: ";
        cin >> choose;

        switch (choose)
        {
            case 0:
            {
                exit(0);
            }
            case 1:
            {
                count_time_quick_sort(a, n, flag);
                break;
            }
            case 2:
            {
                count_time_merge_sort(a, n, flag);
                break;
            }
            case 3:
            {
                count_time_heap_sort(a, n, flag);
                break;
            }
            case 4:
            {
                count_time_interchange_sort(a, n, flag);
                break;
            }
            case 5:
            {
                count_time_bubble_sort(a, n, flag);
                break;
            }
            default:
                cout << "The number you've just chosen is not available on the menu. Try again.";
        }
        do{
            cout << "try another sorting algo ? (y/n): "; cin >> select;
            
        } while ((select != 'Y' && select != 'y' && select != 'N' && select != 'n') && cout << "Please type 'y' or 'n'." << endl);
        
    }while (select == 'y' || select == 'Y');
    
    cout << " bye :)";

    return 0;

}
