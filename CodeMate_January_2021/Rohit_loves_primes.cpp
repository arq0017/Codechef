#include <bits/stdc++.h>
#define ll long long
using namespace std;

void sieve(ll L, ll R)
{
	ll i, j, d;

	d = R-L+1;		//from range L to R, we have d=R-L+1 numbers.
	
	bool flag[d]; 	//use flag[i] to mark whether (L+i) is a prime number or not.

	/* default: mark all to be true */
	for (i = 0; i < d; i++)
		flag[i] = true;

	/* mark even numbers as false */
	for (i = (L%2!=0); i<d; i+=2)
		flag[i] = false;

	/* sieve by prime factors staring from 3 till sqrt(U) */
	for (i = 3; i <= sqrt(R); i+=2)
	{
		if (i > L && !flag[i-L]) continue;

		/* choose the first number to be sieved -- >= L,
		divisible by i, and not i itself! */

		j = L/i*i;

		if (j < L)  j+=i;
		if (j == i) j+=i; 	//if j is a prime number, have to start form next one

		//now start sieving

		j -= L; // change j to the index representing j

		for (; j < d; j+=i)
			flag[j]=false;
	}

	//mark 1 as false, 2 as true
	if (L <= 1) flag[1-L] = false;
	if (L <= 2) flag[2-L] = true;

	//output the result
	for (i = 0; i < d; i++)
		if (flag[i])
			cout << (L+i) << " ";
}

ll l, r;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        sieve(l,r);
        cout<<"\n";
    }
}