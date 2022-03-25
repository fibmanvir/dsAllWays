// This file has various methods to obtain specific result, choose wisely
#include<iostream>
using namespace std;

struct Array {
    int *arr;
    int size;
    int len;
};

void append(struct Array *arr){
    if(arr->len<arr->size){
        cout<<"enter the number to add in Array"<<endl;
        
        int n;
        
        cin>>n;
        arr->arr[arr->len] = n;
        arr->len++;
    }
    else{
        cout<<"No space available in the array";
    }
}

void insert(struct Array *arr){
    int index, number;
    
    cout<< "Enter the index and number respectively to add into the Array: "<< endl;
    cin>> index >> number;
    if(index<arr->len && arr->len<arr->size){
        for(int i=arr->len; i>index; i--){
            arr->arr[i] = arr->arr[i-1];
        }
        arr->arr[index] = number;
        arr->len++;
    }else{
        cout<< "Not possible to insert at specified index bro ;("<< endl;
    }
}

void deleteIndex(struct Array *arr){
    int index;
    
    cout<< "Enter the index of Array to delete: "<< endl;
    cin>> index;
    
    if(index>=0 && arr->len>index){
        for(int i=index; i<arr->len; i++){
            arr->arr[i] = arr->arr[i+1];
        }
        arr->arr[arr->len-1] = 0;
        arr->len--;
    }else{
        cout<< "Not possible to delete at specified index bro ;("<< endl;
    }
    
}

void display(struct Array arr){
    if(arr.len == 0){
        cout<< "there are no elements in the array"<< endl;
    }
    else{
        for(int i=0; i<arr.len; i++){
            cout<< arr.arr[i] << " ";
        }
        cout<<endl;
    }
}

int linearSearch(struct Array *arr){
    int num;
    cout <<"Enter the number to search on the Array: " <<endl;
    cin >>num;
    
    for(int i=0; i<arr->len; i++){
        if(arr->arr[i] == num)
            return i;
    }
    return -1;
}

int binarySearch(struct Array *arr){
    int num, i=0;
    int end = arr->len-1;
    cout<< "Enter the number to be searched in the Array: " <<endl;
    cin>>num;
    for(int k=0; k<arr->len-1; k++){
        for(int j=k+1; j<arr->len-1; j++){
            if(arr->arr[k] > arr->arr[j]){
                int temp = arr->arr[j];
                arr->arr[j] = arr->arr[k];
                arr->arr[k] = temp;
            }
        }
    }
    
    for(i=0; i<end; i++){
        if(arr->arr[(i+end)/2] > num){
            end = (i+end)/2;
        }
        else if(arr->arr[(i+end)/2] < num){
            i = (i+end)/2;
        }
        else{
            return (i+end)/2;
        }
    }
    return -1;
}

int rBSplit(int arr[], int low, int high, int num){
    int mid = (low+high)/2;
    
    if(arr[mid] == num){
        return mid;
    }
    else if(arr[mid] > num){
        return rBSplit(arr, low, mid-1, num);
    }
    else{
        return rBSplit(arr, mid+1, high, num);
    }
    
    return -1;
}

int rBinarySearch(struct Array *arr){
    int num;
    cout<< "Enter the number to be searched in the array: " <<endl;
    cin>> num;
    
    for(int k=0; k<arr->len-1; k++){
        for(int j=k+1; j<arr->len; j++){
            if(arr->arr[k] > arr->arr[j]){
                int temp = arr->arr[j];
                arr->arr[j] = arr->arr[k];
                arr->arr[k] = temp;
            }
        }
    }
    
    cout<< "Sorted Array: " <<endl;
    
    for(int i=0; i<arr->len; i++){
        cout<< arr->arr[i] << " ";
    }
    
    cout<<endl;
    
    int low = 0, high = arr->len-1;
    
    return rBSplit(arr->arr, low, high, num);
}

int main(){
    struct Array arr;
    
    cout<< "Enter the size of the array: length>=1 pls"<<endl;
    cin>>arr.size;
    
    int a[arr.size];
    arr.len = 0;
    arr.arr = a;
    arr.arr[0] = 0;
    
    int flag = true;
    do{
        cout<< "-------------------------------------------------------------" <<endl;
        cout<< "Enter your selection: " <<endl;
        cout<< "Press 1 for adding the element to the end of Array: " <<endl;
        cout<< "Press 2 for display: " <<endl;
        cout<< "Press 3 for insertion at particular index of Array: " <<endl;
        cout<< "Press 4 to delete at specified index of an Array: " <<endl;
        cout<< "Press 5 to search an element using linear search: " << endl;
        cout<< "Press 6 to search an element using binary search: " <<endl;
        cout<< "Press 7 to search an element using recursive binary search :" <<endl;
        cout<< "Press 8 for exit" <<endl;
        cout<< "-------------------------------------------------------------" <<endl;
        
        int num;
        cin>> num;
        
        switch (num) {
            case 1:
                append(&arr);
                break;
                
            case 2:
                display(arr);
                break;
                
            case 3:
                insert(&arr);
                break;
                
            case 4:
                deleteIndex(&arr);
                break;
                
            case 5:
            {
                int res = linearSearch(&arr);
                if(res>=0)
                    cout<< "Given number is available at index: " <<res<<endl;
                else
                    cout<< "Number not found in the Array" <<endl;
                break;
            }
                
            case 6:
            {
                int res = binarySearch(&arr);
                if(res>=0)
                    cout<< "Given number is available at index: " <<res<< endl;
                else
                    cout<< "Number not found in the Array" <<endl;
                break;
            }
                
            case 7:
            {
                int res = rBinarySearch(&arr);
                if(res>=0)
                    cout<< "Given number is available at index: " <<res<< endl;
                else
                    cout<< "Number not found in the Array" <<endl;
                break;
            }
                
            case 8:
                flag = false;
                break;
                
            default:
                break;
        }
    }while(flag);
    
    return 0;
}
