#include<iostream>
#include<stdlib.h>
#include<string>
#include<time.h>
#include<fstream>
#include<algorithm>
#define DATANUM 150000
using namespace std;


void quicksort_leftlong(int arr[], int left, int right);
void quicksort_leftshort(int arr[], int left, int right);
void quicksort_leftori(int arr[], int left, int right);
void quicksort_medlong(int arr[], int left, int right);
void quicksort_medshort(int arr[], int left, int right);
void quicksort_medori(int arr[], int left, int right);

int main(){

    clock_t t_start, t_end;
    double cpu_time_used;

    int oridata[DATANUM];
    int data[DATANUM];

    //read file
    ifstream inFile("test_data.txt");
    string datain;
    int datacount = 0;

    while(inFile >> datain){
        oridata[datacount] = data[datacount] = atoi(datain.c_str());
        datacount++;
    }

    //start counting
    for(int i=0; i<6; i++){
        t_start = clock();

        if(i==0) quicksort_leftlong(data, 0, DATANUM-1);
        else if(i==1) quicksort_leftshort(data, 0, DATANUM-1);
        else if(i==2) quicksort_leftori(data, 0, DATANUM-1);
        else if(i==3) quicksort_medlong(data, 0, DATANUM-1);
        else if(i==4) quicksort_medshort(data, 0, DATANUM-1);
        else if(i==5) quicksort_medori(data, 0, DATANUM-1);

        t_end = clock();
        cpu_time_used = ((double)(t_end - t_start))/CLOCKS_PER_SEC;

        if(i==0) cout<<"leftmost and longer first:\t\t";
        else if(i==1) cout<<"leftmost and shorter first:\t\t";
        else if(i==2) cout<<"leftmost and original:\t\t\t";
        else if(i==3) cout<<"median of three and longer first:\t";
        else if(i==4) cout<<"median of three and shorter first:\t";
        else if(i==5) cout<<"median of three and original:\t\t";

        cout<<cpu_time_used<<endl;

        for(int i=0; i<DATANUM; i++){
            data[i] = oridata[i];
        }
    }

    return 0;
}

void quicksort_leftlong(int arr[], int left, int right){
    int temp;
    if(left < right){
        //pivot is here
        int pivot = arr[left]; //first position
        //
        int l = left;
        int r = right+1;

        while(1){
            while(l < right && arr[++l] < pivot);
            while (r > 0 && arr[--r] > pivot);
            if(l>=r) break;
            swap(arr[l], arr[r]);
        }

        swap(arr[left], arr[r]);

        if(r-1-left >= right-r-1){ //long first
            quicksort_leftlong(arr, left, r-1); //left list
            quicksort_leftlong(arr, r+1, right); //right list
        }
        else{
            quicksort_leftlong(arr, r+1, right); //right list
            quicksort_leftlong(arr, left, r-1); //left list
        }

    }
}

void quicksort_leftshort(int arr[], int left, int right){
    int temp;
    if(left < right){
        //pivot is here
        int pivot = arr[left]; //first position
        //
        int l = left;
        int r = right+1;

        while(1){
            while(l < right && arr[++l] < pivot);
            while (r > 0 && arr[--r] > pivot);
            if(l>=r) break;
            swap(arr[l], arr[r]);
        }

        swap(arr[left], arr[r]);

        if(r-1-left<=right-r-1){ //short first
            quicksort_leftshort(arr, left, r-1); //left list
            quicksort_leftshort(arr, r+1, right); //right list
        }
        else{
            quicksort_leftshort(arr, r+1, right); //right list
            quicksort_leftshort(arr, left, r-1); //left list
        }
    }
}

void quicksort_leftori(int arr[], int left, int right){
    int temp;
    if(left < right){
        //pivot is here
        int pivot = arr[left]; //first position
        //
        int l = left;
        int r = right+1;

        while(1){
            while(l < right && arr[++l] < pivot);
            while (r > 0 && arr[--r] > pivot);
            if(l>=r) break;
            swap(arr[l], arr[r]);
        }

        swap(arr[left], arr[r]);

        quicksort_leftori(arr, left, r-1); //left list
        quicksort_leftori(arr, r+1, right); //right list
    }
}

void quicksort_medlong(int arr[], int left, int right){
    int temp;
    if(left < right){
        //pivot is here
        int m[3];
        m[0] = arr[left];
        m[1] = arr[right];
        m[2] = arr[(left+right)/2];
        sort(m, m+3);
        int pivot = m[1]; //median
        //
        int l = left;
        int r = right+1;

        while(1){
            while(l < right && arr[++l] < pivot);
            while (r > 0 && arr[--r] > pivot);
            if(l>=r) break;
            swap(arr[l], arr[r]);
        }

        swap(arr[left], arr[r]);

        if(r-1-left >= right-r-1){ //long first
            quicksort_medlong(arr, left, r-1); //left list
            quicksort_medlong(arr, r+1, right); //right list
        }
        else{
            quicksort_medlong(arr, r+1, right); //right list
            quicksort_medlong(arr, left, r-1); //left list
        }
    }
}

void quicksort_medshort(int arr[], int left, int right){
    int temp;
    if(left < right){
        //pivot is here
        int m[3];
        m[0] = arr[left];
        m[1] = arr[right];
        m[2] = arr[(left+right)/2];
        sort(m, m+3);
        int pivot = m[1]; //median
        //
        int l = left;
        int r = right+1;

        while(1){
            while(l < right && arr[++l] < pivot);
            while (r > 0 && arr[--r] > pivot);
            if(l>=r) break;
            swap(arr[l], arr[r]);
        }

        swap(arr[left], arr[r]);

        if(r-1-left<=right-r-1){ //short first
            quicksort_medshort(arr, left, r-1); //left list
            quicksort_medshort(arr, r+1, right); //right list
        }
        else{
            quicksort_medshort(arr, r+1, right); //right list
            quicksort_medshort(arr, left, r-1); //left list
        }
    }
}

void quicksort_medori(int arr[], int left, int right){
    int temp;
    if(left < right){
        //pivot is here
        int m[3];
        m[0] = arr[left];
        m[1] = arr[right];
        m[2] = arr[(left+right)/2];
        sort(m, m+3);
        int pivot = m[1]; //median
        //
        int l = left;
        int r = right+1;

        while(1){
            while(l < right && arr[++l] < pivot);
            while (r > 0 && arr[--r] > pivot);
            if(l>=r) break;
            swap(arr[l], arr[r]);
        }

        swap(arr[left], arr[r]);

        quicksort_medori(arr, left, r-1); //left list
        quicksort_medori(arr, r+1, right); //right list
    }
}
