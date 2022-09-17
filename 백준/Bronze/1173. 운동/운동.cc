#include<iostream>

using namespace std;

int N, m, M, T, R;

int main()

{

	cin >> N >> m >> M >> T >> R;

	//N운동 m 최소 맥박 M 맥박 한계치 T 맥박증가률 R맥박 감소률



	int n = 0; //운동횟수

	int time = 0;//시간

	int Cur = m; //현재맥박상태

	if (m+T>M)

	{

		cout << -1 << endl;

		return 0;

	}

	while (n<N)

	{

		if (Cur+T <= M) //운동가능 

		{

			Cur += T;

			n++;

		}

		else //휴식 해야됨

		{

			Cur -= R;

			if (Cur < m)

				Cur = m;

		}	

		time++;

	}

	cout << time << endl;

}