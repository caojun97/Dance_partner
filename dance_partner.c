#include <stdio.h>
#include "sq_queue.h"

int dancer_match(SqQueue_T *m_dancer_pt, SqQueue_T *f_dancer_pt)
{
	while (!queue_empty(m_dancer_pt) && !queue_empty(f_dancer_pt))
	{
		QElemType m_elem, f_elem;
		queue_pop(m_dancer_pt, &m_elem);
		queue_pop(f_dancer_pt, &f_elem);
		printf("%s(M) %s(F)\n", m_elem.name, f_elem.name);
	}
	return OK;
}

int main()
{
	SqQueue_T m_dancer_t; //�����������߶���
	SqQueue_T f_dancer_t; //����Ů�����߶���
	Person_T person_t[MAX_Q_SIZE]; // ������������
	int num_of_person;

	queue_init(&m_dancer_t);
	queue_init(&f_dancer_t);

	printf("��������������:");
	scanf("%d", &num_of_person);
	printf("\n");
	for (int i = 0; i < num_of_person; i++)
	{
		printf("�������%d�����ߵ��������Ա�(M or F):", i + 1);
		scanf("%s %c", person_t[i].name, &person_t[i].sex);
	}
	for (int i = 0; i < num_of_person; i++)
	{
		if (person_t[i].sex == 'M')
			queue_push(&m_dancer_t, person_t[i]);
		else
			queue_push(&f_dancer_t, person_t[i]);
	}
	printf("\n");
	dancer_match(&m_dancer_t, &f_dancer_t);
	
	printf("������Ժ�ʣ����������������%d\n", queue_length(&m_dancer_t));
	printf("������Ժ�ʣ��Ů������������%d\n", queue_length(&f_dancer_t));
	
	queue_destory(&m_dancer_t);
	queue_destory(&f_dancer_t);
	return 0;
}