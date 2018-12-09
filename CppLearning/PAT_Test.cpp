///*
//** @Brief:No.1026 of PAT advanced level.
//** @Author:Jason.Lee
//** @Date:2018-11-27
//** @status:
//*/
//
//#include<iostream>
//#include<string>
//#include<cstring>
//#include<algorithm>
//#include<vector> 
//
//using namespace std;
//
//struct member {
//	int arrivingTime;
//	int playingTime;
//	int vip;
//	int waitingTime;
//	int servingTime;
//};
//
//struct table {
//	int lastTime;
//	int totalPeople;
//};
//
//bool cmp(member a, member b) {
//	return a.arrivingTime < b.arrivingTime;
//}
//
//bool cmp2(member a, member b) {
//	return a.servingTime < b.servingTime;
//}
//
//int main() {
//	int N, M, K, V;
//	while (scanf("%d", &N) != EOF) {
//		member temp;
//		bool noVIP = true;
//		vector<member> normalQueue;
//		vector<member> vipQueue;
//		table tables[101];
//		int vipNumbers[101];
//		for (int i = 0; i < N; i++) {
//			// 输入数据 
//			int hh;
//			int mm;
//			int ss;
//			scanf("%d:%d:%d%d%d", &hh, &mm, &ss, &temp.playingTime, &temp.vip);
//			temp.arrivingTime = hh * 3600 + mm * 60 + ss;
//			temp.playingTime = (temp.playingTime > 120 ? 120 * 60 : temp.playingTime * 60);
//			temp.vip ? vipQueue.push_back(temp) : normalQueue.push_back(temp);
//			if (temp.vip) {
//				noVIP = false;
//			}
//		}
//		scanf("%d%d", &M, &K);
//		for (int i = 0; i < K; i++) {
//			scanf("%d", &vipNumbers[i]);
//		}
//		sort(normalQueue.begin(), normalQueue.end(), cmp);
//		sort(vipQueue.begin(), vipQueue.end(), cmp);
//		// 分配策略
//		table zeroTable{ 8 * 3600,0 };
//		fill(tables, tables + 101, zeroTable);
//		int firstOutput = 0;
//		int minWaitTime = 13 * 3600;// 假设最长等待时间：从8点等到21点
//		if (noVIP || K == 0) {
//			for (auto normal : normalQueue) {
//				for (int i = 0; i < M; i++) {
//					// 如果有空位，等待时间为0，直接入队 
//					if (normal.arrivingTime >= tables[i].lastTime) {
//						minWaitTime = 0;
//						firstOutput = i;
//						tables[i].lastTime = normal.arrivingTime;
//						break;
//					}
//					// 没有空位，遍历每一个位置，查找最小的等待时间 
//					else {
//						if (minWaitTime > tables[i].lastTime - normal.arrivingTime) {
//							firstOutput = i;
//							minWaitTime = tables[i].lastTime - normal.arrivingTime;
//						}
//					}
//				}
//				// 更新 
//				normal.waitingTime = minWaitTime;
//				normal.servingTime = tables[firstOutput].lastTime;
//				tables[firstOutput].lastTime = normal.servingTime + normal.playingTime;
//				(normal.servingTime >= 21 * 3600) ? tables[firstOutput].totalPeople : tables[firstOutput].totalPeople++;
//			}
//		}
//		// 如果既有VIP也有VIP的桌子，优先服务VIP 
//		else {
//			// VIP
//			for (auto vip : vipQueue) {
//				for (int i = 0; i < K; i++) {
//					if (vip.arrivingTime >= tables[vipNumbers[i] - 1].lastTime) {
//						minWaitTime = 0;
//						firstOutput = i;
//						tables[vipNumbers[i] - 1].lastTime = vip.arrivingTime;
//						break;
//					}
//					else {
//						if (minWaitTime > tables[vipNumbers[i] - 1].lastTime - vip.arrivingTime) {
//							firstOutput = i;
//							minWaitTime = tables[vipNumbers[i] - 1].lastTime - vip.arrivingTime;
//						}
//					}
//				}
//				vip.waitingTime = minWaitTime;
//				vip.servingTime = tables[vipNumbers[firstOutput] - 1].lastTime;
//				tables[vipNumbers[firstOutput] - 1].lastTime = vip.servingTime + vip.playingTime;
//				cout << "vip serving time = " << vip.servingTime / 3600 << endl;
//				vip.servingTime >= 21 * 3600 ? tables[vipNumbers[firstOutput] - 1].totalPeople : tables[vipNumbers[firstOutput] - 1].totalPeople++;
//			}
//			firstOutput = 0;
//			minWaitTime = 13 * 3600;
//			// normal
//			for (auto normal : normalQueue) {
//				for (int i = 0; i < M; i++) {
//					if (normal.arrivingTime >= tables[i].lastTime) {
//						minWaitTime = 0;
//						firstOutput = i;
//						tables[i].lastTime = normal.arrivingTime;
//						break;
//					}
//					else {
//						if (minWaitTime > tables[i].lastTime - normal.arrivingTime) {
//							firstOutput = i;
//							minWaitTime = tables[i].lastTime - normal.arrivingTime;
//						}
//					}
//				}
//				// 问题 
//				normal.waitingTime = minWaitTime;
//				normal.servingTime = tables[firstOutput].lastTime;
//				cout << "serving time = " << normal.servingTime / 3600 << endl;
//				tables[firstOutput].lastTime = normal.servingTime + normal.playingTime;
//				normal.servingTime >= 21 * 3600 ? tables[firstOutput].totalPeople : tables[firstOutput].totalPeople++;
//			}
//		}
//		normalQueue.insert(normalQueue.end(), vipQueue.begin(), vipQueue.end());
//		for (auto elem : vipQueue) {
//			cout << "serving time:" << elem.servingTime / 3600 << endl;
//		}
//		sort(normalQueue.begin(), normalQueue.end(), cmp2);
//
//		// 输出
//		for (auto player : normalQueue) {
//			int hh2 = player.servingTime / 3600;
//			int mm2 = (player.servingTime - hh2 * 3600) / 60;
//			int ss2 = player.servingTime - mm2 * 60 - hh2 * 3600;
//
//			int hh1 = player.arrivingTime / 3600;
//			int mm1 = (player.arrivingTime - hh1 * 3600) / 60;
//			int ss1 = player.arrivingTime - mm1 * 60 - hh1 * 3600;
//
//			int waitingTime = (player.waitingTime % 60) ? (player.waitingTime / 60 + 1) : player.waitingTime / 60;
//			printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", hh1, mm1, ss1, hh2, mm2, ss2, waitingTime);
//		}
//		printf("%d", tables[0].totalPeople);
//		for (int i = 1; i < M; i++) {
//			printf(" %d", tables[i].totalPeople);
//		}
//	}
//	return 0;
//}
