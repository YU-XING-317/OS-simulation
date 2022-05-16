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

void Psort(vector<Scheduling>& sch, int a, int b) {
	sort(sch.begin() + a, sch.begin() + b,
		[](Scheduling& p1, Scheduling& p2)
		{return p1.P < p2.P; });
}
//����
void run(vector<Scheduling>& sch, int N) {
	int k;
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			sch[0].setTime(sch[0].getTOA());
		}
		else {
			for (k = i; k < N; k++) {
				if (sch[k].getTOA() > sch[i - 1].getTOC()) {
					break;
				}
			}
			Psort(sch, i, k);
			sch[i].setTime(sch[i - 1].getTOC());
		}
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
	cout << "ƽ����תʱ��Ϊ��" << ave_TRT / N;
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