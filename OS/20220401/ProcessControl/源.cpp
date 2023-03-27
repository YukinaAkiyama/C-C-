#include <iostream>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <list>
using namespace std;

class Queue
{
public:
	Queue() :pro_counter(1) {}
	void put(int val)
	{
		// lock_guard<mutex> lock(mtx);
		unique_lock<mutex> lck(mtx);
		while (!que.empty())
		{
			// que不为空，生产者应该通知消费之去消费，
			// 使用条件变量，当不为空，就将锁释放掉，

			cv_no_full.wait(lck);
		}
		que.push(val);
		cv_no_empty.notify_all(); // 通知所有的消费线程去消费
		// cv.notify_one(); // 通知一个线程
		// 其他线程得到该通知，就从等待状态，编程
		// 阻塞状态，然后在获取互斥锁继续执行。
	}

	int get()
	{
		int val = 0;
		{
			unique_lock<mutex> lck(mtx);
			while (que.empty())
			{
				// 通知生产者生产，
				// 进入等待状态，释放互斥锁
				cv_no_empty.wait(lck);
			}
			val = que.front();
			que.pop();
			cv_no_full.notify_all(); // 通知消费线程，我消费完了，赶紧生产吧
		}
		return val;
	}


	mutex producer_mtx; // 互斥生产者之间获取队列
	mutex comsumer_mtx; // 互斥消费者之间获取队列
	int pro_counter;  // 记录生产者已生产物品的个数
	int con_counter;  // 记录消费者已消费物品的个数
	const int MAX_PRODUCER = 10; // 最多生产的个数
private:
	queue<int> que;  // 共享队列
	mutex mtx;       // 互斥生产者和消费者获取队列
	condition_variable cv_no_full; // 用于共享队列不满
	condition_variable cv_no_empty; // 用于共享队列不空
};

Queue que;


void consumer(Queue* que)
{
	int flag = false;
	for (;;)
	{
		this_thread::sleep_for(chrono::milliseconds(100));
		{
			lock_guard<mutex> lck(que->comsumer_mtx);
			if (que->con_counter < que->MAX_PRODUCER)
			{
				int data = que->get();
				++que->con_counter;
				cout << this_thread::get_id() << "消费 : " << data << "商品" << endl;
			}
			else
				flag = true;
		}
		if (flag)
			break;
	}
}

void producer(Queue* que)
{
	int flag(false);
	for (;;)
	{
		{
			lock_guard<mutex> lck(que->producer_mtx);
			if (que->pro_counter <= que->MAX_PRODUCER)
			{
				que->put(que->pro_counter);
				cout << this_thread::get_id() << "生产 : " << que->pro_counter << "商品" << endl;
				++que->pro_counter;
			}
			else
				flag = true;
		}
		if (flag)
			break;
		this_thread::sleep_for(chrono::milliseconds(100));
	}
}


int main()
{
	list<thread> pro_lst; // 生产者线程
	for (int i = 0; i < 3; ++i)
		pro_lst.push_back(thread(producer, &que));
	list<thread> con_lst; // 消费者线程
	for (int i = 0; i < 3; ++i)
		pro_lst.push_back(thread(consumer, &que));

	for (auto& it : pro_lst) // 注意这里只能使用引用&it，因为thread是没有左值的提供拷贝构造和赋值
		it.join();
	for (auto& it : con_lst)
		it.join();
	return 0;
}
