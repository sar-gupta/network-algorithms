#include<iostream>
using namespace std;
int max(int a,int b){
    if(a>=b)
        return a;
    return b;
}
int main() {
	int t;
	cin>>t;
	for(int q=0;q<t;q++){
	    int n;
	    cin>>n;
	    int a[n],lisValue[n];

	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        lisValue[i]=1;
	    }
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(a[j]<a[i])
	                lisValue[i]=max(lisValue[i],lisValue[j]+1);
	        }
	    }
	    int max=lisValue[0];
	    for(int i=1;i<n;i++){
	        if(max<lisValue[i])
	            max=lisValue[i];
	    }
	    cout<<max<<endl;
	}
	return 0;
}
