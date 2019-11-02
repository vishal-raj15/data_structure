#include <iostream>

using namespace std;

class min_binary_heap 
{
	public:
		int heap_size;
		int len;
		int * element;

	min_binary_heap(int cap) {
		heap_size = 0;
		len = cap;
		element = new int[cap];
	}
	// ~min_binary_heap()
	// {
	// 	delete [] element;
	// 	cout<<"object deleted "<<endl;
	// }

	int parent(int i) {
		return (i - 1) / 2;
	}

	int left_child(int i) {
		return 2 * i + 1;
	}

	int right_child(int i) {
		return 2 * i + 2;
	}

	void min_heapify(int i) 
    {
		int lc = left_child(i);
		int rc = right_child(i);
		int small = i;
		if (lc < heap_size && element[lc] < element[i]) {
			small = lc;
		}
		if (rc < heap_size && element[rc] < element[small]) {
			small = rc;
		}
		if (small != i) {
			swap( & element[small], & element[i]);
			min_heapify(small);
		}

	}

	// void build_heap(int a[] , int n)
	// {
	// 	int last = (n/2) - 1;
	// 	for(int i = last ; i>=0 ;i-- )
	// 	{
	// 		min_heapify(i);
	// 	}

	// }

	void swap(int * x, int * y) {
		int temp = * x;
		* x = * y;
		* y = temp;
	}

	void insert(int key) {
		if (heap_size >= 100) {
			cout << " overflow ";
			exit(1423);
		}

		heap_size++;
		int i = heap_size - 1;
		element[i] = key;

		while (i != 0) {
			if (element[i] < element[parent(i)]) {
				swap( & element[i], & element[parent(i)]);
			}
			i = parent(i);
		}
	}

	int extract_min() {
		return element[0];
	}

	void decreaseKey(int i, int new_val) {
		element[i] = new_val;
		while (i != 0 && element[parent(i)] > element[i]) {
			swap( & element[i], & element[parent(i)]);
			i = parent(i);
		}
	}

	int print(int i) {
		if (i >= len){
			cout << "index out of bound" << endl;
			exit(4234);
		}
		
		return element[i];
	}

 	void merge(min_binary_heap & obj1 , min_binary_heap & obj2,int n,int m)
    {
		
		int N;
		N=n+m;
		min_binary_heap merge_arr(N);
		

		for(int i=0 ; i<n ;i++)
		{
			merge_arr.insert(obj1.element[i]);
		}
		for(int j=0 ; j<m ; j++)
		{
			merge_arr.insert(obj2.element[j]);
		}

		for(int i=0 ; i<N ;i++)
		{
			cout<<merge_arr.element[i]<< " ";
		}
		cout<<endl;
		cout<< "min value of merged arr :"<<merge_arr.extract_min()<<endl;
	}

	void remove()
    {
        if(heap_size == 0)
        {
            cout<<" empty heap"<<endl;
            return;
        }
        swap(& element[0] , & element[len-1]);
        heap_size--;
        min_heapify(0);
    }
};


int main() 
{

    ////////////          Q3            ///////////////////////////////
	/////////////////////////////////////////////////////////////////////
	cout<<"\n"<<"enter no of bags"<<endl;
	int bags,k;
	cin>>bags;
    cin>>k;
    min_binary_heap chocolates(bags);
	for(int i=0 ; i<bags ; i++)
	{
        int nos;
		cin>>nos;
        chocolates.insert(-1*nos);
	}
    int ans=0;
    for(int i=0 ; i<k ; i++)
    {
        int temp = chocolates.element[0];
        chocolates.remove();
        chocolates.insert(temp/2);
        ans = ans + temp;
    }

    cout<<(-1*ans)%(1000000000)<<endl;
	/////////////////////////////////////////////////////////////////////

	return 0;
}
