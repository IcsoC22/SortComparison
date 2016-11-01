#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

class Integer 
{
	int value;
	int count;

public:
	// Creates a new Integer with value and count 0
	Integer()
	{
		value = 0;
		count = 0;
	}

	// Creates a new Integer with value x and count 0
	Integer(int x)
	{
		value = x;
		count = 0;
	}
	
	// Sets the value to x and the count to 0
	void set_value(int x)
	{
		value = x;
		count = 0;
	}

	// Returns the value
	int get_value()
	{
		return value;
	}

	// Returns the count
	int get_count()
	{
		return count;
	}

	// Reutrns the result of the current value < a different Integer value
	// increments count
	bool operator<(Integer i)
	{
		count++;
		return value < i.get_value();
	}
};

// Insertion Sort of a vactor<T>, A
// Starting at the 2nd to last element, moves elements, e, to the right until e+1 is greater than e
// Does this process down to the first element 
template <typename T>
vector<T> Insertion_Sort(vector<T> A)
{
for(int j=A.size()-2; j >= 0; j--)
	{
		T key = A[j];
		int i = j + 1;
		while((i < A.size()) && (A[i] < key))
			{
				A[i-1] = A[i];
				i = i + 1;
			} 
		A[i-1] = key;
	}

	return A; 
}

// Last Element Quicksort of a vector<T>, A, from p to r
// if p < r, perfroms a Last Partition with pivot q
// Quicksorts on A from p to q-1 and q+1 to r 
template <typename T>
void Last_Element_Quicksort(vector<T> & A, int p, int r)
{
	if(p < r)
	{
		int q = Last_Partition(A, p, r);
		Last_Element_Quicksort(A, p, q-1);
		Last_Element_Quicksort(A, q+1, r);		
	}
}

// Last Partition on a vector<T>, A, from p to r
// sorts A into two subarrays, where A[p] to A[q-1] is less than q
// and A[q+1] to A[r] is greater than pivot A[q], where A[q] is the original last element 
template <typename T>
int Last_Partition(vector<T> & A, int p, int r)
{
	int x = A[r].get_value();
	int i = p - 1;
	for(int j = p; j <= r - 1; j++)
	{
		if (A[j] < x)
		{
			i = i + 1;
			T temp1 = A[i];
		        A[i] = A[j];
			A[j] = temp1;			
		}
	}
	T temp2 = A[i+1];
	A[i+1] = A[r];
	A[r] = temp2;	
	return i+1;	
}

// Random Element Quicksort of a vector<T>, A, from p to r
// if p < r, performs a Random Partition with pivot q
// Quicksorts on A from p to q-1 and from q+1 to r
template <typename T>
void Random_Element_Quicksort(vector<T> & A, int p, int r)
{
	if(p < r)
	{
		int q = Random_Partition(A, p, r);
		Random_Element_Quicksort(A, p, q-1);
		Random_Element_Quicksort(A, q+1, r);
	}
}

// Random Partion of a vector<T>, A,  from p to r
// selects a random pivot in the range from p to r
// exchanges that pivot with A[r]
// perform Last Partition on A from p to r
template <typename T>
int Random_Partition(vector<T> & A, int p, int r)
{
	int random;
	srand (time(NULL));
	random = rand() % (r-p) + p;
	T temp = A[random];
	A[random] = A[r];
	A[r] = temp;
	return Last_Partition(A, p, r);
}



// Function that just prints out the 6 Integer vectors passed in from 0 to n-1
// Used to check the contents of the vectors and make sure they are actaully sorting
void print_arrays(int n, vector<Integer> v1, vector<Integer> v2, vector<Integer> v3, vector<Integer> v4, vector<Integer> v5, vector<Integer> v6)
{
	for(int i = 0; i < n; i++)
		cout << v1[i].get_value() << " ";
	cout << '\n';


	for(int i = 0; i < n; i++)
		cout << v2[i].get_value() << " ";

	cout << '\n';


	for(int i = 0; i < n; i++)
		cout << v3[i].get_value() << " ";

	cout << '\n';


	for(int i = 0; i < n; i++)
		cout << v4[i].get_value() << " ";

	cout << '\n';


	for(int i = 0; i < n; i++)
		cout << v5[i].get_value() << " ";

	cout << '\n';


	for(int i = 0; i < n; i++)
		cout << v6[i].get_value() << " ";

	cout << '\n';
}


int main()
{
vector<Integer> v1;
vector<Integer> v2;
vector<Integer> v3;
vector<Integer> v4;
vector<Integer> v5;
vector<Integer> v6;

srand (time(NULL));
int sum1 = 0;
int sum2 = 0;
int sum3 = 0;
int sum4 = 0;
int sum5 = 0;
int sum6 = 0;
int avg = 0;

// Number of elements in each array
int n = 50;

// What the random element will be % with in order to control the size of the numbers
int mod = 2000;

// Putting the values in the arrays
for (int i = 0; i < n; i++)
	{
	v1.push_back(Integer(i+1));
	v2.push_back(Integer(n-i));
	v3.push_back(Integer(rand()%mod));
	v4.push_back(Integer(rand()%mod));
	v5.push_back(Integer(rand()%mod));
	v6.push_back(Integer(rand()%mod));
	}
// Printint out the contents of the array, they will be commented out by default to make viewing the counts easier
//print_arrays(n, v1, v2, v3, v4, v5, v6);

// Running Insertion Sort on all of the arrays
v1 = Insertion_Sort(v1);
v2 = Insertion_Sort(v2);
v3 = Insertion_Sort(v3);
v4 = Insertion_Sort(v4);
v5 = Insertion_Sort(v5);
v6 = Insertion_Sort(v6);

//print_arrays(n, v1, v2, v3, v4, v5, v6);

// Collecting the counts of each array
for (int i = 0; i < n; i++)
	{
	sum1 = sum1 + v1[i].get_count();
	sum2 = sum2 + v2[i].get_count();
	sum3 = sum3 + v3[i].get_count();
	sum4 = sum4 + v4[i].get_count();
	sum5 = sum5 + v5[i].get_count();
	sum6 = sum6 + v6[i].get_count();
	}

// Averaging the random counts
avg = (sum3+sum4+sum5+sum6)/4;

cout<< "Insertion Sort Array1 Count: " << sum1 << "\nInsertion Sort Array2 Count: " << sum2 << "\nInsertion Sort Average on Random Arrays: " << avg <<'\n';

// Resetting the arrays
for (int i = 0; i < n; i++)
	{
	v1[i].set_value(i+1);
	v2[i].set_value(n-i);
	v3[i].set_value(rand()%mod);
	v4[i].set_value(rand()%mod);
	v5[i].set_value(rand()%mod);
	v6[i].set_value(rand()%mod);
	}

//print_arrays(n, v1, v2, v3, v4, v5, v6);

//Performing Last Element Quicksort on each array
Last_Element_Quicksort(v1, 0, v1.size() - 1);
Last_Element_Quicksort(v2, 0, v2.size() - 1); 
Last_Element_Quicksort(v3, 0, v3.size() - 1);
Last_Element_Quicksort(v4, 0, v4.size() - 1); 
Last_Element_Quicksort(v5, 0, v5.size() - 1);
Last_Element_Quicksort(v6, 0, v6.size() - 1); 

//print_arrays(n, v1, v2, v3, v4, v5, v6);

// Resetting the sums to 0
sum1 = 0;
sum2 = 0;
sum3 = 0;
sum4 = 0;
sum5 = 0;
sum6 = 0;

// Collecting the counts of the arrays
for (int i = 0; i < n; i++)
	{
	sum1 = sum1 + v1[i].get_count();
	sum2 = sum2 + v2[i].get_count();
	sum3 = sum3 + v3[i].get_count();
	sum4 = sum4 + v4[i].get_count();
	sum5 = sum5 + v5[i].get_count();
	sum6 = sum6 + v6[i].get_count();
	}

// Averaging the random counts
avg = (sum3+sum4+sum5+sum6)/4;

cout<< "Last Element Quicksort Array1 Count: " << sum1 << "\nLast Element Quicksort Array2 Count: " << sum2 << "\nLast Element Quicksort Average on Random Arrays: " << avg <<'\n';

// Resetting the arrays
for (int i = 0; i < n; i++)
	{
	v1[i].set_value(i+1);
	v2[i].set_value(n-i);
	v3[i].set_value(rand()%mod);
	v4[i].set_value(rand()%mod);
	v5[i].set_value(rand()%mod);
	v6[i].set_value(rand()%mod);
	}

//print_arrays(n, v1, v2, v3, v4, v5, v6);

// Performing Random Element Quicksort on the arrays
Random_Element_Quicksort(v1, 0, v1.size() - 1);
Random_Element_Quicksort(v2, 0, v2.size() - 1); 
Random_Element_Quicksort(v3, 0, v3.size() - 1);
Random_Element_Quicksort(v4, 0, v4.size() - 1); 
Random_Element_Quicksort(v5, 0, v5.size() - 1);
Random_Element_Quicksort(v6, 0, v6.size() - 1); 

//print_arrays(n, v1, v2, v3, v4, v5, v6);

// Resetting the sums to 0
sum1 = 0;
sum2 = 0;
sum3 = 0;
sum3 = 0;
sum4 = 0;
sum5 = 0;
sum6 = 0;

// Collecting the counts of the arrays
for (int i = 0; i < n; i++)
	{
	sum1 = sum1 + v1[i].get_count();
	sum2 = sum2 + v2[i].get_count();
	sum3 = sum3 + v3[i].get_count();
	sum4 = sum4 + v4[i].get_count();
	sum5 = sum5 + v5[i].get_count();
	sum6 = sum6 + v6[i].get_count();
	}

// Averaging the random counts
avg = (sum3+sum4+sum5+sum6)/4;

cout<< "Random Element Quicksort Array1 Count: " << sum1 << "\nRandom Element Quicksort Array2 Count: " << sum2 << "\nRandom Element Quicksort Average on Random Arrays: " << avg << '\n';

return 0;
}
