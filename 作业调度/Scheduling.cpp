#include "Scheduling.h"
//�������룬������������ʱ�䡢����ʱ��
istream& operator>>(istream& is, Scheduling& p){
	cout << "������ý��̵����ơ�����ʱ�䡢����ʱ�䡢���ȼ��� ";
	is >> p.name >> p.TOA >> p.ST >> p.P;
	if (is)
		return is;
	else
		exit(0);
}
//������������������������ʱ�䡢����ʱ�䡢��ʼʱ�䡢��תʱ�䡢��Ȩ��תʱ��
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
