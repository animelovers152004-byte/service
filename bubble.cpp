 #include<iostream>
using namespace std;

int main()
{
	int n,p,A[20],i,temp,swap,comp;
	
	
	
    char ch;
    
    cout<<"enter total of no";
	cin>>n;
	
	for(i=0;i<n;i++)
	{
	  cout<<"enter numbers";
	  cin>>A[i];
    }
    
    cout<<"**Bubble Sort**"<<endl;
    cout<<"n="<<n<<endl;
    cout<<"given nos are:"<<endl;
    for(i=0;i<n;i++)
    {
    	cout<<A[i]<<" ";
	}
	for(p=1;p<n;p++)
	{   cout<<"\nPass:"<<p<<endl;
	    comp=0;
		swap=0;
		for(i=0;i<=n-1-p;i++)
		{   comp=i+1;
			if(A[i]>A[i+1])
			{
				temp=A[i];
				A[i]=A[i+1];
				A[i+1]=temp;
				swap=1;
			}
			
		}
		cout<<"comparison:"<<comp<<endl;
		for(i=0;i<n;i++)
		{
			cout<<A[i]<<" ";
		}
	    if(swap==0)
	    {
	    	break;
		}
	}
	
	
	
	cout<<"\n**Selection sort**"<<endl;
  
    int j,t,min,minI;
	
	cout<<"enter total of no"<<endl;
	cin>>n;
	
	for(i=0;i<n;i++)
	{
	  cout<<"enter numbers";
	  cin>>A[i];
    }
    cout<<"n="<<n<<endl;
    cout<<"given nos are:"<<endl;
    for(i=0;i<n;i++)
    {
    	cout<<A[i]<<" ";
	}
	
	for(i=0;i<n-1;i++)
	{   
		comp=0;
		cout<<"Pass:"<<i+1<<endl;
		min=A[i];
		minI=i;
		
		for(j=i+1;j<n;j++)
		{
			comp=comp+1;
			if(min>A[j])
			{
				min=A[j];
				minI=j;
				
			}
			
		}
		t=A[i]; 
		A[i]=A[minI];
		A[minI]=t;
		cout<<"No of comp:"<<comp<<endl;
		
		
	    for(i=0;i<n;i++)
	    {
	    	cout<<A[i]<<" ";
		}
		
	}
	
}