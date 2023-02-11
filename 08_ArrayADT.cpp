#include <iostream>
using namespace std;

class MyArray
{
	int total_size, used_size;
	int *ptr;
	
	public:
		MyArray(int tSize, int uSize)
		{
			total_size = tSize;
			used_size = uSize;
			ptr = (int*)malloc(tSize*sizeof(int));
		}
		
		void show()
		{
			for (int i=0; i< used_size; i++)
			{
				cout << ptr[i] << endl;
			}
		}
		
		void set()
		{
			for (int i=0; i< used_size; i++)
			{
				cout << "Enter element " << i << endl;
				cin >> ptr[i];
			}
		}
};

int main()
{
	MyArray marks(100, 5);
	marks.set();
	marks.show();
	return 0;
}