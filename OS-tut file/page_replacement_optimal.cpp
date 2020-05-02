
#include<bits/stdc++.h>
using namespace std;


int pgFaults(int p[], int n, int c)
{

	set<int> s;




	//queue<int> ind;


	int ans = 0;
	for (int i=0; i<n; i++)
	{

		if (s.size() < c)
		{

			if (s.find(p[i])==s.end())
			{

				s.insert(p[i]);


				ans++;


				//ind.push(p[i]);
			}
		}


		else
		{

			if (s.find(p[i]) == s.end())
			{

				//int val = ind.front();

				set<int> :: iterator itr;

				int val = -1;
				int maxi = 0;

				for(itr = s.begin();itr != s.end();itr++){

                    int temp = *itr;

                    int j ;
                    for ( j = i+1;j<n;j++){

                        if( p[j]==temp)
                            break;
                    }
                    if( j>maxi){

                        maxi = j ;
                        val= temp;
                    }


				}


				//ind.pop();


				s.erase(val);


				s.insert(p[i]);


				//ind.push(p[i]);


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
	cout << pgFaults(pag, siz, cap)<<endl;
	return 0;
}
