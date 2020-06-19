#include <iostream>
using namespace std;

int deno[] = { 1, 2, 5, 10, 20};
int n = sizeof(deno) / sizeof(deno[0]);

void findMin(int V)
{
{
for (int i= 0; i < n-1; i++) {
for (int j= 0; j < n-i-1; j++){
if (deno[j] > deno[j+1])
swap(&deno[j], &deno[j+1]);
}
int ans[V];
for (int i = 0; i <n; i++) {
while (V >= deno[i]) {
V -= deno[i];
ans[i]=deno[i];
}
}

for (int i = 0; i < ans.size(); i++)
cout << ans[i] << “ “;
}

// Main Program
int main()
{
int a;
cout<<”Enter you amount “;
cin>>a;
cout << “Following is minimal number of change for “ << a<< “ is “;
findMin(a);
return 0;
}