#include"queue.h"

void test()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueueShow(&q);
	QueuePop(&q);
	QueueShow(&q);
	int k = QueueBack(&q);
	printf("���һ��Ԫ����%d\n", k);
	k = QueueFrount(&q);
	printf("��һ��Ԫ����%d\n", k);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueueShow(&q);
	k = QueueSize(&q);
	printf("���д�С=%d\n", k);


}

int main()
{
	test();
	system("pause");
	return 0;
}