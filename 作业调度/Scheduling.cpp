#include "Scheduling.h"
//重载输入，输入名、到达时间、服务时间
istream& operator>>(istream& is, Scheduling& p){
	cout << "请输入该进程的名称、到达时间、运行时间、优先级： ";
	is >> p.name >> p.TOA >> p.ST >> p.P;
	if (is)
		return is;
	else
		exit(0);
}
//重载输出，输出任务名、到达时间、服务时间、开始时间、周转时间、带权周转时间
ostream& operator<<(ostream& os, const Scheduling& p){
	os << p.name << "     "
		<<p.P<<"      "
		<< p.TOA << "         "
		<< p.ST << "         "
		<< p.TMOFST << "         "
		<< p.TOC<<"         "
		<< p.TRT << "         "
		<< p.TRT_W << "         "
		<< endl;
	return os;
}
double Scheduling::getTOA(){
	return TOA;
}
double Scheduling::getST(){
	return ST;
}
double Scheduling::getTMOFST(){
	return TMOFST;
}
double Scheduling::getTOC(){
	return TOC;
}
double Scheduling::getTRT(){
	return TRT;
}
double Scheduling::getTRT_W(){
	return TRT_W;
}
void Scheduling::setTime(double tt){
	this->TMOFST = tt;
	this->TOC = this->ST+ tt;
	this->TRT = this->TOC - this->TOA;
	this->TRT_W = this->TRT / this->ST;
}
void Scheduling::setTMOFST(double tt){
	this->TMOFST = tt;
}
void Scheduling::setTOC(double toc){
	this->TOC = toc;
}
void Scheduling::setTRT(double trt){
	this->TRT = trt;
}
void Scheduling::setTRTW(double trtw){
	this->TRT_W = trtw;
}
