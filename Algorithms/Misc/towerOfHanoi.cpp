// C++ recursive function to
// solve tower of hanoi 
// time complexity O(2^n)
#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char from_rod,
					char to_rod, char aux_rod)
{
    // base case if we have one rod left we simply put it 
    // in the destination rod
    // ans return from the fuction call
	if (n == 1)
	{
		cout << "Move disk 1 from rod " << from_rod <<
							" to rod " << to_rod<<endl;
		return;
	}
    // this recurcive will move our n-1 disc in auxilliary from source
	towerOfHanoi(n - 1, from_rod, aux_rod, to_rod); 
    // will print out answer
	cout << "Move disk " << n << " from rod " << from_rod <<
								" to rod " << to_rod << endl;
// this recurcive call will move our n-1 disc from auxilliary to destination
	towerOfHanoi(n - 1, aux_rod, to_rod, from_rod); 
}

// Driver code
int main()
{
	int n; // Number of disks
    cin>>n;
	towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
	return 0;
}

