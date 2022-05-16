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
//运行
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
	cout << "名称  优先级  到达时间  运行时间  开始时间  完成时间  周转时间  带权周转时间" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	for (const auto& p : sch) {
		cout << p;
		ave_TRT += p.TRT;
	}
	cout <<"平均周转时间为："<< ave_TRT / N;
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