# service
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cout<<"how many students are present for the program: ";
    cin>>n;
    
    int arr[10];
    int i;
    for(int i=0;i<n;i++)
    {
        cout<<"enter the roll no of the present student : ";
        cin>>arr[i];
        
    }
    
     for(int i=0;i<n;i++)
     {
         cout<< arr[i]<<" ";
     }
     int key1;
     int match;
     char ch;
     do
     {
     	match=0;
     	cout<<"enter roll no of student that we have to find:";
     	cin>>key1;
     	for(int i=0;i<n;i++)
        {
            if(arr[i]==key1)
         {
             match=1;
             break;
         }
         
        }     
     
        if (match==1)
        {
            cout<<"the student is present"<<endl;
        }
        else
        {
         cout<<"the student is absent"<<endl;
        }
     
        cout<<"do you want to continue(y/n):";
        cin>>ch;
     }while(ch=='y');
     cout<<"binary search";
     cout<<"sorted order is:"<<endl;
     sort(arr,arr+n);
	 for(i=0;i<n;i++)
	 {
	 	cout<<arr[i]<<" ";
	 }
	 int key2;
	 int flag;
	 char ans;
	 do
	 {
	 	cout<<"enter roll no of student you want to check:";
	 	cin>>key2;
	 	int start,end,mid;
	 	start=0;
	 	end=n-1;
	 	flag=0;
	 	while(start<=end)
        {
        	mid=(start+end)/2;
            cout<<"middle no is:"<<mid<<endl;
            if(arr[mid]==key2)
            {
            	flag=1;
            	break;
			}
			else if(arr[mid]>key2)
			{
				end=mid-1;
			}
			else
			{
				start=mid +1;
			}
		}
		if(flag==1)
		{
			cout<<"student is present";
		}
		else
		{
			cout<<"student is absent";
		}
		cout<<"do you want to continue(y/n):";
		cin>>ans;
     }while(ans=='y');
	 return 0;
}
