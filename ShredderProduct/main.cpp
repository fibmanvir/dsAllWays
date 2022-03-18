//
//  main.cpp
//  ShredderProduct
//
//  Created by Manvir Singh on 18/03/22.
//

#include <iostream>
using namespace std;

int func(int m, int n){
    if(n==1)
        return m;
    if(n%2==0){
        return func(m*m, n/2);
    }
    else{
        return m*func(m*m, (n-1)/2);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int m,n;
    cout<<"Enter values of m amd n, \n";
    cin>>m>>n;
    
    

    cout << "Hello, World!\n"<<func(m, n)<<endl;
    
    return 0;
}
