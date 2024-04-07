#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
std::mutex m;

class Counter { 
    private: 
        int n; 
    
    public: 
        Counter(int num) {
            n = num; 
        }; 

        void countUp() {
            while (n < 20) {
                m.lock();
                n++;
                cout << n << endl;
                m.unlock();
            }
        }
        void countDown() {
            while (n > 0) { 
                m.lock();
                n--;
                cout << n << endl;
                m.unlock();
            }
        }
}; 

int main() {

    Counter count(0); 

	thread t1(&Counter::countUp, &count);
	t1.join();

	thread t2(&Counter::countDown, &count);
    t2.join();

	return 0;
}