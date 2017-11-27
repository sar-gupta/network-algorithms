#include<bits/stdc++.h>
using namespace std;

string server(string data)
{
  cout<<"\nReceived: "<<data;
  int count=0, i=0;
  for(;i<data.size()-1;i++)
  {
    if(data[i]=='1')
    {
      count++;
    }
  }
  if(count%2==0 && data[i]=='0')
  {
    return "\nAccepted";
  }
  else if(count%2!=0 && data[i]=='1')
  {
    return "\nAccepted";
  }
  return "\nError detected";
}

string client()
{
  string data;
  int count=0;
  cout<<"Enter binary data: ";
  getline(cin, data);
  for(int i=0;i<data.size();i++)
  {
    if(data[i]=='1')
    {
      count++;
    }
  }
  if(count%2==0)
  {
    data.append("0");
  }
  else
  {
    data.append("1");
  }
  return data;
}

int main()
{
  string message = client();
  cout<<server(message);
  return 0;
}