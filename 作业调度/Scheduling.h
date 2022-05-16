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

	//设置时间(除FCFS，均使用改函数)
	void setTime(double tt);
	//设置开始时间
	void setTMOFST(double tt);
	//设置完成时间
	void setTOC(double toc);
	//计算周转时间
	void setTRT(double trt);
	//计算带权周转时间
	void setTRTW(double trtw);


	char name;		//进程名称
	double TOA;		//到达时间
	double ST;		//运行时间
	double TMOFST;	//开始时间
	double TOC;		//完成时间
	double TRT;		//周转时间
	double TRT_W;	//带权周转时间
	int P;			//优先级
};