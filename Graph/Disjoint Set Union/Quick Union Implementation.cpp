#include<bits/stdc++.h>
using namespace std;

//Quick Union

void init_code()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

const int N = 1e5+7;
int n,m;
int root[N];

void make_set(int x) // O(1)
{
	root[x] = x;
}

int find_set(int x)  // O(n)
{
	if(x == root[x])
		return x;
	return find_set(root[x]);
}

void union_set(int x, int y)  // O(n)
{
	int rx = find_set(x);
	int ry = find_set(y);

	if(rx!=ry)
	{
		//rx is the ultimate leader
		root[ry] = rx;
	}
}

void print_roots()
{
	for(int i=1;i<=n;i++)
    {
    	cout << root[i] << " ";
    }
    cout << endl;
}

bool connected(int x, int y) // O(n)
{
	return find_set(x) == find_set(y);
}

int main()
{
    init_code();
    
    cin >> n >> m;

    for(int i=1;i<=n;i++)
    	make_set(i);
    print_roots();
    for(int i=0;i<m;i++)
    {
    	int a,b;
    	cin >> a >> b;
    	union_set(a,b);
    	print_roots();
    }

    cout << connected(1,7) << endl;
    cout << connected(5,3) << endl;

 	return 0;
    
}
