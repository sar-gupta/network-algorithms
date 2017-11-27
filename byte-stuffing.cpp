#include<bits/stdc++.h>
using namespace std;

string server(string data)
{
  cout<<"\nReceived: "<<data;
  if(data[0]=='F' && data[1]=='L' && data[2]=='A' && data[3]=='G')
  {
    data.erase(0, 4);
  }
  else
  {
    return "\nError";
  }
  if(data[data.size()-4]=='F' && data[data.size()-3]=='L' && data[data.size()-2]=='A' && data[data.size()-1]=='G')
  {
    data.erase(data.size()-4);
  }
  else
  {
    return "\nError";
  }
  for(int i=0;i<data.size();i++)
  {
    if(data.size()-i>=4 && data[i]=='E' && data[i+1]=='S' && data[i+2]=='C' && (data[i+3]=='F' || data[i+3]=='E'))
    {
      data.erase(i,3);
    }
  }
  return "\nAccepted: " + data;
}

string client()
{
  string data;
  string flag = "FLAG", escape = "ESC";
  cout<<"Enter data: ";
  getline(cin, data);
  for(int i=0;i<data.size();i++)
  {
    if(data.size()-i>=4 && data[i]=='F' && data[i+1]=='L' && data[i+2]=='A' && data[i+3]=='G')
    {
      data.insert(i,escape);
      i+=4;
    }
    if(data.size()-i>=3 && data[i]=='E' && data[i+1]=='S' && data[i+2]=='C')
    {
      data.insert(i,escape);
      i+=3;
    }
  }
  data.insert(0, flag);
  data.insert(data.size(), flag);
  return data;
}

int main()
{
  string message = client();
  cout<<server(message);
  return 0;
}