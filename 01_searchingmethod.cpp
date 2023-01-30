#include<bits/stdc++.h>

using namespace std;

class searchingmethod{
    public:
        void Linearsearch(vector<int> &arr, int key,int n){
            bool found = false;
            for(int i = 0;i < n;i++){
                if(arr[i] == key){
                    found = true;
                    cout<<"value found at location : "<<i;
                    break;
                }
            }
            if(found == false) cout<<"value not found";
        }
        void Binarysearch(vector<int> &arr, int key,int n){
            int high = n - 1,low = 0;
            bool found = false;
            while(high >= low){
                int mid = (high + low) / 2;
                if(arr[mid] == key){ 
                    found = true;
                    cout<<"value found at location : "<<mid;
                    break;
                }
                else if(arr[mid] > key){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            if(found == false) cout<<"value not found";
        }
};

int main(){
    char dec = 'y';
    int n = 0,key = 0,val;
    searchingmethod s;
    cout<<"enter the size of array:";
    cin>>n;
    vector<int> arr(n);
    cout<<"enter the array:\n";
    for(int i = 0;i < n;i++){
        cout<<"arr["<<i<<"]: ";
        cin>>arr[i];
    }
    do{
        cout<<"select the search method\n";
        cout<<"1.Linear search\n";
        cout<<"2.Binary search\n";
        cout<<"\n\nenter your choice:";
        cin>>val;
        cout<<"\nenter the value that you want to search:";
        cin>>key;
        switch(val){
            case 1: s.Linearsearch(arr,key,n);
                break;
            case 2: s.Binarysearch(arr,key,n);
                break;
            default: cout<<"enter a valid choice";
        }
        cout<<"\ndo you want to continue(y/n)\n";
        cin>>dec;
        dec = tolower(dec);
        cout<<endl<<endl;
    }while(dec != 'n');
    return 0;
}