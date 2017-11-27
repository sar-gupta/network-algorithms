// #include <bits/stdc++.h>
// using namespace std;

// vector<int> add(vector<vector<int>> data, int m, int n)
// {
//   vector<int> sum(m, 0), transferCarry(m, 0), toBeAdded(m);
//   int carry = 0, flag = 0, last = 0;
//   for (int i = 0; i < n / m; i++)
//   {
//     if (transferCarry[m - 1] == 1)
//     {
//       toBeAdded.assign(transferCarry.begin(), transferCarry.end());
//       flag = 1;
//     }
//     else
//     {
//       toBeAdded.assign(data[i].begin(), data[i].end());
//       flag = 0;
//       last = 0;
//     }
//     transferCarry[m - 1] = 0;
//     int carry = 0;
//     for (int j = m - 1; j >= 0; j--)
//     {
//       if (sum[j] == 0 && toBeAdded[j] == 0)
//       {
//         sum[j] = carry;
//         carry = 0;
//       }
//       else if (sum[j] == 1 && toBeAdded[j] == 1)
//       {
//         sum[j] = carry;
//         carry = 1;
//       }
//       else
//       {
//         if (carry == 1)
//         {
//           sum[j] = 0;
//           carry = 1;
//         }
//         else
//         {
//           sum[j] = 1;
//           carry = 0;
//         }
//       }
//     }
//     cout << i << " : ";
//     if (carry == 1)
//     {
//       transferCarry[m - 1] = 1;
//       if (i == (n / m) - 1)
//       {
//         last = 1;
//         i--;
//       }
//     }
//     cout << carry << " : ";
//     for (int k = 0; k < m; k++)
//     {
//       cout << sum[k];
//     }
//     cout << " : " << flag << endl;
//     if (flag && !last)
//     {
//       i--;
//     }
//   }
//   return sum;
// }

// vector<vector<int>> sender(vector<vector<int>> data, int m, int n)
// {
//   string stringData;
//   vector<int> sum(m), checksum(m);
//   while (1)
//   {
//     cin >> stringData;
//     if (stringData.length() != n)
//     {
//       cout << "Please enter " << n << " bits: ";
//       continue;
//     }
//     break;
//   }
//   int k = 0;
//   for (int i = 0; i < n / m; i++)
//   {
//     for (int j = 0; j < m; j++)
//     {
//       data[i][j] = stringData[k] - 48;
//       k++;
//     }
//   }
//   sum = add(data, m, n);
//   for (int i = 0; i < m; i++)
//   {
//     checksum[i] = !sum[i];
//   }
//   data[n].assign(checksum.begin(), checksum.end());
//   for (int i = 0; i < m; i++)
//   {
//     cout << data[n][i];
//   }
//   cout << endl;
//   return data;
// }

// bool receiver(vector<vector<int>> data, int m, int n)
// {
//   vector<int> result = add(data, m, n + 1);
//   for (int i = 0; i < m; i++)
//   {
//     result[i] ^= 1;
//     if (result[i] != 0)
//     {
//       return false;
//     }
//   }
//   return true;
// }

// int main()
// {
//   int n, m;
//   cout << "Enter number of bits to be sent";
//   cin >> n;
//   cout << "Enter size of each segment";
//   while (1)
//   {
//     cin >> m;
//     if (n % m != 0)
//     {
//       cout << "Number of bits should be a multiple of segment size, enter again: ";
//       continue;
//     }
//     break;
//   }
//   vector<vector<int>> data(n + 1);
//   for (int i = 0; i < n + 1; i++)
//   {
//     data[i].resize(m);
//   }
//   data = sender(data, m, n);
//   bool check = receiver(data, m, n);
//   if (check)
//   {
//     cout << "Transmission was error free";
//   }
//   else
//   {
//     cout << "Error detected";
//   }
//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int convert(string s)
{
  int num = 0;
  int i = 0;
  int l = s.length();
  while (l)
  {
    l--;
    num += (s[i] - 48) * pow(2, l);
    i++;
  }
  return num;
}
string convert_back(int num)
{
  string s = "";
  while (num)
  {
    if (num % 2 == 0)
      s = s + '0';
    else
      s = s + '1';
    num /= 2;
  }
  return s;
}

void receiver(int a[], int n)
{
  int sum = 0;
  for (int i = 0; i < n + 1; i++)
    sum += a[i];
  string cs = convert_back(sum);
  reverse(cs.begin(), cs.end());
  for (int i = 0; i < cs.length(); i++)
  {
    if (cs[i] == '0')
      cs[i] = '1';
    else
      cs[i] = '0';
  }
  cout << "Checksum at receiver's end" << endl;
  cout << cs;
  int valcs = convert(cs);
  cout << endl;

  if (valcs == 0)
    cout << "No error!";
  else
    cout << "Error";
  return;
}

void sender()
{
  int n;
  cout << "Enter the number of strings";
  cin >> n;
  int a[n + 1];
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    string s;
    cout << "enter string";
    cin >> s;
    int num = convert(s);
    cout << num << endl;
    a[i] = num;
    sum += a[i];
  }
  string cs = convert_back(sum);
  reverse(cs.begin(), cs.end());
  for (int i = 0; i < cs.length(); i++)
  {
    if (cs[i] == '0')
      cs[i] = '1';
    else
      cs[i] = '0';
  }
  cout << "Checksum" << endl;
  cout << cs;
  int valcs = convert(cs);
  cout << endl;

  a[n] = valcs;
  receiver(a, n);
}

int main()
{
  sender();
  return 0;
}