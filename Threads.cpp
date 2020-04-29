
#include <iostream>
#include <thread>
using namespace std;


void dummy(int x)
{
	for (int i = 0; i < x; i++) {
		cout << "Thread using function"
			" pointer \n";
	}
}


class t_object {
public:
	void operator()(int x)
	{
		for (int i = 0; i < x; i++)
			cout << "Thread using function"
				" object \n";
	}
};

int main()
{
	cout << "Programme to demonstrate multi-threading by using 3 threads -Threads 1 and 2 and 3 " << endl;


	thread thread1(dummy, 5);


	thread thread2(t_object(), 5);


	auto frie = [](int x) {
		for (int i = 0; i < x; i++)
			cout << "Thread using lambda"
			" expression \n";
	};


	thread thread3(frie, 5);


	thread1.join();


	thread2.join();


	thread3.join();

	return 0;
}
