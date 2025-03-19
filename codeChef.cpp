#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int x,y;
	cin>>x>>y;
    cout<<x<<y;
	int count=0;
    if(x<y)
	{
        count+=1;
        y-=x;
	}
    else
    {
        return 0;
    }
}