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
			// que��Ϊ�գ�������Ӧ��֪ͨ����֮ȥ���ѣ�
			// ʹ����������������Ϊ�գ��ͽ����ͷŵ���

			cv_no_full.wait(lck);
		}
		que.push(val);
		cv_no_empty.notify_all(); // ֪ͨ���е������߳�ȥ����
		// cv.notify_one(); // ֪ͨһ���߳�
		// �����̵߳õ���֪ͨ���ʹӵȴ�״̬�����
		// ����״̬��Ȼ���ڻ�ȡ����������ִ�С�
	}

	int get()
	{
		int val = 0;
		{
			unique_lock<mutex> lck(mtx);
			while (que.empty())
			{
				// ֪ͨ������������
				// ����ȴ�״̬���ͷŻ�����
				cv_no_empty.wait(lck);
			}
			val = que.front();
			que.pop();
			cv_no_full.notify_all(); // ֪ͨ�����̣߳����������ˣ��Ͻ�������
		}
		return val;
	}


	mutex producer_mtx; // ����������֮���ȡ����
	mutex comsumer_mtx; // ����������֮���ȡ����
	int pro_counter;  // ��¼��������������Ʒ�ĸ���
	int con_counter;  // ��¼��������������Ʒ�ĸ���
	const int MAX_PRODUCER = 10; // ��������ĸ���
private:
	queue<int> que;  // �������
	mutex mtx;       // ���������ߺ������߻�ȡ����
	condition_variable cv_no_full; // ���ڹ�����в���
	condition_variable cv_no_empty; // ���ڹ�����в���
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
				cout << this_thread::get_id() << "���� : " << data << "��Ʒ" << endl;
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
				cout << this_thread::get_id() << "���� : " << que->pro_counter << "��Ʒ" << endl;
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
	list<thread> pro_lst; // �������߳�
	for (int i = 0; i < 3; ++i)
		pro_lst.push_back(thread(producer, &que));
	list<thread> con_lst; // �������߳�
	for (int i = 0; i < 3; ++i)
		pro_lst.push_back(thread(consumer, &que));

	for (auto& it : pro_lst) // ע������ֻ��ʹ������&it����Ϊthread��û����ֵ���ṩ��������͸�ֵ
		it.join();
	for (auto& it : con_lst)
		it.join();
	return 0;
}
