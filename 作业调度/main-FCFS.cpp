#include"Scheduling.h"
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
//��ʼ��
void init(vector<Scheduling>& sch, int n) {
	Scheduling p;
	for (int i = 0; i < n; i++) {
		cin >> p;
		sch.push_back(p);
	}
}
//������ʱ������
void TOAsort(vector<Scheduling>& sch) {
	sort(sch.begin(), sch.end(),
		[](Scheduling& p1, Scheduling& p2)
		{return p1.getTOA() < p2.getTOA(); });
}
//����
void run(vector<Scheduling>& sch, int N) {
	for (int k = 0; k < N; k++) {
		if (k == 0) {
			sch[k].setTMOFST(sch[k].getTOA());
		}
		else {
			sch[k].setTMOFST(sch[k - 1].getTOC());
		}
		sch[k].setTOC(sch[k].getTMOFST() + sch[k].getST());
		sch[k].setTRT(sch[k].getTOC()-sch[k].getTOA());
		sch[k].setTRTW(sch[k].getTRT() / sch[k].getST());
	}
}
void display(vector<Scheduling>& sch, int N) {
	double ave_TRT = 0;
	cout << "_________________________________________________________________________" << endl;
	cout << "����  ���ȼ�  ����ʱ��  ����ʱ��  ��ʼʱ��  ���ʱ��  ��תʱ��  ��Ȩ��תʱ��" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	for (const auto& p : sch) {
		cout << p;
		ave_TRT += p.TRT;
	}
	cout <<"ƽ����תʱ��Ϊ��"<< ave_TRT / N;
}
int main() {
	vector<Scheduling> sch;
	int n;
	cout << "����������ܸ�����";
	cin >> n;
	init(sch, n);
	TOAsort(sch);
	run(sch, n);
	display(sch, n);
}