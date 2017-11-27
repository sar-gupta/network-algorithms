#include<bits/stdc++.h>
using namespace std;

string server(vector<int> data)
{
  cout<<"\nCode received is: ";
  for(int i=0;i<data.size();i++)
  {
    cout<<data[i];
  }
  int c1 = data[0]^data[2]^data[4]^data[6];
  int c2 = data[1]^data[2]^data[5]^data[6];
  int c3 = data[3]^data[4]^data[5]^data[6];
  int position = 4*c3+2*c2+c1;
  if(position == 0)
  {
    return "\nNo error.";
  }
  data[position+1] = !data[position+1];
  string message = "";
  for(int i=0;i<data.size();i++)
  {
    message += (char)data[i]+48;
  }
  return "\n Error detected.\nCorrect code is: " + message;
}

vector<int> client()
{
  string data;
  string message="";  
  input:
  cout<<"Enter 4-bit binary data: ";
  cin>>data;
  if(data.size()!=4)
  {
    goto input;
  }
  vector<int> s(7);
  s[2] = (int)data[0]-48;
  s[4] = (int)data[1]-48;
  s[5] = (int)data[2]-48;
  s[6] = (int)data[3]-48;

  s[0] = s[2]^s[4]^s[6];
  s[1] = s[2]^s[5]^s[6];
  s[3] = s[4]^s[5]^s[6];

  return s;
}

int main()
{
  vector<int> message = client();
  cout<<server(message);
}