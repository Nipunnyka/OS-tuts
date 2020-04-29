
#include<bits/stdc++.h>
using namespace std;


int pgFaults(int p[], int n, int c)
{

	unordered_set<int> s;


	queue<int> ind;


	int ans = 0;
	for (int i=0; i<n; i++)
	{

		if (s.size() < c)
		{

			if (s.find(p[i])==s.end())
			{

				s.insert(p[i]);


				ans++;


				ind.push(p[i]);
			}
		}


		else
		{

			if (s.find(p[i]) == s.end())
			{

				int val = ind.front();


				ind.pop();


				s.erase(val);


				s.insert(p[i]);


				ind.push(p[i]);


				ans++;
			}
		}
	}

	return ans;
}


int main()
{
	int pag[] = {7, 0, 1, 2, 0, 3, 0, 4,
				2, 3, 0, 3, 2};
	int siz = sizeof(pag)/sizeof(pag[0]);
	int cap = 4;
	cout << pgFaults(pag, siz, cap);
	return 0;
}

