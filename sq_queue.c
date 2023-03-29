//==============================================================================
//
// Title:
// Purpose:
// Author:
// Created on:
// Copyright:
//
//==============================================================================

//==============================================================================
// Include files
#include "sq_queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

//==============================================================================
// Global variables


//==============================================================================
// Static functions

//==============================================================================
// Global functions

/// HIFN  What does your function do?
/// HIPAR x/What inputs does your function expect?
/// HIRET What does your function return?
//int Define_Your_Functions_Here (int x)
//{
//	return x;
//}

// ���г�ʼ��
int queue_init(SqQueue_T *sq_queue_pt)
{
	sq_queue_pt->base = (QElemType *)malloc(MAX_Q_SIZE * sizeof(QElemType));
	if (NULL == sq_queue_pt->base)
		exit(OVERFLOW);
	memset(sq_queue_pt->base, 0, MAX_Q_SIZE * sizeof(QElemType));
	sq_queue_pt->front = 0;
	sq_queue_pt->rear = 0;
	return OK;
}

// ��������
int queue_destory(SqQueue_T *sq_queue_pt)
{
	if (NULL != sq_queue_pt->base)
		free(sq_queue_pt->base);
	sq_queue_pt->front = 0;
	sq_queue_pt->rear = 0;
	return OK;
}

// ����г���
int queue_length(SqQueue_T *sq_queue_pt)
{
	return  (sq_queue_pt->rear - sq_queue_pt->front + MAX_Q_SIZE) % MAX_Q_SIZE;
}

// ���
int queue_push(SqQueue_T *sq_queue_pt, QElemType elem)
{
	// �ж��Ƿ����(ѭ������)��������Ϊ�����򱨴�
	if ((sq_queue_pt->rear + 1) % MAX_Q_SIZE == sq_queue_pt->front)
		return ERROR;
	sq_queue_pt->base[sq_queue_pt->rear] = elem;
	sq_queue_pt->rear = (sq_queue_pt->rear + 1) % MAX_Q_SIZE;
	return OK;
}

// ����
int queue_pop(SqQueue_T *sq_queue_pt, QElemType *elem)
{
	// �ж��Ƿ�Կգ�������Ϊ�գ��򱨴�
	if (sq_queue_pt->front == sq_queue_pt->rear)
		return ERROR;
	*elem = sq_queue_pt->base[sq_queue_pt->front];
	sq_queue_pt->front = (sq_queue_pt->front + 1) % MAX_Q_SIZE;
	return OK;
}

// ȡ��ͷԪ��
QElemType * queue_head_elem_get(SqQueue_T *sq_queue_pt)
{
	//������Ϊ�գ��򷵻ؿ�ָ��NULL
	QElemType *p_elem;
	if (sq_queue_pt->front == sq_queue_pt->rear)
		p_elem = NULL;
	else
		p_elem = &sq_queue_pt->base[sq_queue_pt->front];
	return p_elem;
}

// �ж϶����Ƿ�Ϊ��
int  queue_empty(SqQueue_T *sq_queue_pt)
{
	// ������Ϊ�գ��򷵻�ֵΪ��0ֵ
	return !((sq_queue_pt->rear - sq_queue_pt->front + MAX_Q_SIZE) % MAX_Q_SIZE);
}
