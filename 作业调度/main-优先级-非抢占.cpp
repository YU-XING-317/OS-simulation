#include"Scheduling.h"
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
//初始化
void init(vector<Scheduling>& sch, int n) {
	Scheduling p;
	for (int i = 0; i < n; i++) {
		cin >> p;
		sch.push_back(p);
	}
}
//按到达时间排序
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
//运行
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
	cout << "名称  优先级  到达时间  运行时间  开始时间  完成时间  周转时间  带权周转时间" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	for (const auto& p : sch) {
		cout << p;
		ave_TRT += p.TRT;
	}
	cout << "平均周转时间为：" << ave_TRT / N;
}

int main() {
	vector<Scheduling> sch;
	int n;
	cout << "请输入进程总个数：";
	cin >> n;
	init(sch, n);
	TOAsort(sch);
	run(sch, n);
	display(sch, n);
}