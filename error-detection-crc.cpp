#include <bits/stdc++.h>
using namespace std;


int main()
{
  int i, j, k, l;

  //Get Frame
  int fs;
  cout << "\n Enter Frame size: ";
  cin >> fs;

  vector<int> f;

  cout << "\n Enter Frame:";
  for (i = 0; i < fs; i++)
  {
    int temp;
    cin >> temp;
    f.push_back(temp);
  }

  //Get Generator
  int gs;
  cout << "\n Enter Generator size: ";
  cin >> gs;

  vector<int> g;

  cout << "\n Enter Generator:";
  for (i = 0; i < gs; i++)
  {
    int temp;
    cin >> temp;
    g.push_back(temp);
  }

  cout << "\n Sender Side:";
  cout << "\n Frame: ";
  for (i = 0; i < fs; i++)
  {
    cout << f[i];
  }
  cout << "\n Generator :";
  for (i = 0; i < gs; i++)
  {
    cout << g[i];
  }

  //Append 0's
  int rs = gs - 1;
  cout << "\n Number of 0's to be appended: " << rs;
  for (i = 0; i < rs; i++)
  {
    f.push_back(0);
  }

  int temp[fs + rs];
  for (i = 0; i < fs + rs; i++)
  {
    temp[i] = f[i];
  }

  cout << "\n Message after appending 0's :";
  for (i = 0; i < fs + rs; i++)
  {
    cout << temp[i];
  }

  //Division
  for (i = 0; i < fs; i++)
  {
    j = 0;
    k = i;
    //check whether it is divisible or not
    if (temp[k] >= g[j])
    {
      for (j = 0, k = i; j < gs; j++, k++)
      {
        temp[k] = temp[k] ^ g[j]; // modulo 2 subtraction
      }
    }
  }

  //CRC
  int crc[rs];
  for (i = 0, j = fs; i < rs; i++, j++)
  {
    crc[i] = temp[j];
  }

  cout << "\n CRC bits: ";
  for (i = 0; i < rs; i++)
  {
    cout << crc[i];
  }

  cout << "\n Transmitted Frame: ";
  int tf[fs + rs];
  for (i = 0; i < fs; i++)
  {
    tf[i] = f[i];
  }
  for (i = fs, j = 0; i < fs + rs; i++, j++)
  {
    tf[i] = crc[j];
  }
  for (i = 0; i < fs + rs; i++)
  {
    cout << tf[i];
  }

  cout << "\n Receiver side : ";
  cout << "\n Received Frame: ";
  for (i = 0; i < fs + rs; i++)
  {
    cout << tf[i];
  }

  for (i = 0; i < fs + rs; i++)
  {
    temp[i] = tf[i];
  }

  //Division
  for (i = 0; i < fs + rs; i++)
  {
    j = 0;
    k = i;
    if (temp[k] >= g[j])
    {
      for (j = 0, k = i; j < gs; j++, k++)
      {
        temp[k] = temp[k]^g[j];
      }
    }
  }

  cout << "\n Remainder: ";
  int rrem[rs];
  for (i = fs, j = 0; i < fs + rs; i++, j++)
  {
    rrem[j] = temp[i];
  }
  for (i = 0; i < rs; i++)
  {
    cout << rrem[i];
  }

  int flag = 0;
  for (i = 0; i < rs; i++)
  {
    if (rrem[i] != 0)
    {
      flag = 1;
    }
  }

  if (flag == 0)
  {
    cout << "\nAccepted";
  }
  else
  {
    cout << "\nError detected";
  }
  return 0;
}