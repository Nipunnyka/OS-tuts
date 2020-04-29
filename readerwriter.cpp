#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>
#include <mutex>

std::atomic_bool finish_reader(false);
std::atomic_bool finish_writer(false);


/* simple mutex option */
std::mutex mutex;
void lock_reader() {
	while (!finish_reader) {
		mutex.lock();	
		std::cout  <<"I am reading" << '\n';
		mutex.unlock();
	}


}
void lock_writer() {
	while(!finish_writer) {
		mutex.lock();
		std::cout << "I am writing" << '\n';
		mutex.unlock();
	}
}

/* solution priority reader starvation writers */
std::mutex mutex_reader;
std::mutex mutex_writer;

int count_readers=0;
void multiple_lock_reader(int num_reader) {
	
	while (!finish_reader) {
		mutex_reader.lock();
		count_readers++;
		if (count_readers==1) {
			mutex_writer.lock();	
		}
		mutex_reader.unlock();	
		
		std::cout  <<"I am reading  reader: "<< num_reader << '\n';
	
		mutex_reader.lock();
		count_readers--;
		if (count_readers==0) {
			mutex_writer.unlock();	
		}
		mutex_reader.unlock();	
	}


}
void multiple_lock_writer() {
	while(!finish_writer) {
		mutex_writer.lock();	
		std::cout << "I am writing" << '\n';
		mutex_writer.unlock();
	}

}


std::mutex x,y,z;
std::mutex rsem, wsem;

int count_readers_readers=0;
int count_readers_writers=0;
void writer_priority_lock_reader(int num_reader) {
	
	while (!finish_reader) {
		//other readers
		z.lock();
		//give writer priority
		rsem.lock();
		//protect counter update
		x.lock();
		count_readers_readers++;
		if (count_readers_readers==1) {
			wsem.lock();	
		}
		x.unlock();	
		rsem.unlock();
		z.unlock();

		std::cout  <<"I am reading  reader: "<< num_reader << '\n';
	
		x.lock();
		count_readers_readers--;
		if (count_readers_readers==0) {
			wsem.unlock();	
		}
		x.unlock();	
	}


}
void writer_priority_lock_writer() {
	while(!finish_writer) {
		y.lock();
		count_readers_writers++;
		if (count_readers_writers==1) {
			rsem.lock();	
		}
		y.unlock();	
		std::cout << "I am writing" << '\n';
		
		y.lock();
		count_readers_writers--;
		if (count_readers_writers==0) {
			rsem.unlock();	
		}
		y.unlock();	
	}

}


void versionLockSync() {
	std::thread tWriter(lock_writer);
	std::thread tReader(lock_reader);
	std::this_thread::sleep_for(std::chrono::seconds(4));
		
	finish_reader = true;
	finish_writer = true;
	tReader.join();
	tWriter.join();
}

void versionMultipleLockSync() {
	std::thread tReader(multiple_lock_reader,1);
	std::thread tReader2(multiple_lock_reader,2);
	std::thread tReader3(multiple_lock_reader,3);
	std::thread tWriter(multiple_lock_writer);
	std::this_thread::sleep_for(std::chrono::seconds(4));
		
	finish_reader = true;
	finish_writer = true;
	tReader.join();
	tReader2.join();
	tReader3.join();
	tWriter.join();
}






int main () {
//	versionLockSync();
	versionMultipleLockSync();
}