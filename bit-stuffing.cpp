#include<bits/stdc++.h>
using namespace std;

string server(string data)
{
  cout<<"\nReceived: "<<data;
  for(int i=0;i<data.size();i++)
  {
    if(data.size()-i>=5 && data[i]=='1' && data[i+1]=='1' && data[i+2]=='1' && data[i+3]=='1' && data[i+4]=='1' && data[i+5] != '0')
    {
      return "Error";
    }
    if(data.size()-i>=5 && data[i]=='1' && data[i+1]=='1' && data[i+2]=='1' && data[i+3]=='1' && data[i+4]=='1' && data[i+5] == '0')
    {
      data.erase(i+5,1);
      i+=4;
    }
  }
  return "\nAccepted: " + data;
}

string client()
{
  string data;
  cout<<"Enter binary data: ";
  getline(cin, data);
  for(int i=0;i<data.size();i++)
  {
    if(data.size()-i>=4 && data[i]=='1' && data[i+1]=='1' && data[i+2]=='1' && data[i+3]=='1' && data[i+4]=='1')
    {
      data.insert(i+5, "0");
      i+=4;
    }
  }
  return data;
}

int main()
{
  string message = client();
  cout<<server(message);
}