#pragma once

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Scheduling {
	friend istream& operator>>(istream& is, Scheduling& p);
	friend ostream& operator<<(ostream& os, const Scheduling& p);
	
public:
	Scheduling() :name(), TOA(0), ST(0), TMOFST(0), TRT(0), TRT_W(0), P{0} {}


	double getTOA();
	double getST();
	double getTMOFST();
	double getTOC();
	double getTRT();
	double getTRT_W();

	//����ʱ��(��FCFS����ʹ�øĺ���)
	void setTime(double tt);
	//���ÿ�ʼʱ��
	void setTMOFST(double tt);
	//�������ʱ��
	void setTOC(double toc);
	//������תʱ��
	void setTRT(double trt);
	//�����Ȩ��תʱ��
	void setTRTW(double trtw);


	char name;		//��������
	double TOA;		//����ʱ��
	double ST;		//����ʱ��
	double TMOFST;	//��ʼʱ��
	double TOC;		//���ʱ��
	double TRT;		//��תʱ��
	double TRT_W;	//��Ȩ��תʱ��
	int P;			//���ȼ�
};