#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include "func1_BackRec9.h"
#include "func2_HomeDyn2.h"
#include "func3_HomeDyn16.h"

void doNum1() {
    int N, B;
    int* weights = nullptr;
    int* volumes = nullptr;
    readInput("1filefor1.txt", N, B, weights, volumes);

    State* dp = new State[B + 1];
    initializeDP(dp, B + 1);
    processArtifacts(N, B, weights, volumes, dp);
    State best = findBestSolution(dp, B);
    printResult(best, weights, volumes);

    delete[] weights;
    delete[] volumes;
    delete[] dp;
}

void doNum2() {
    int N;
    int mass[80][80];
    readF("fileforHD2_1.txt", N, mass);
    long miniSum = findMinFunc(N, mass);
    outFileFunc("outfileforHD2_1.txt", miniSum);
    std::cout << "ответ записан в outfileforHD2_1.txt\n";
}

void doNum3() {
	using namespace std;

	int i, k = 0, n = 0, nz, _nz, oz, _oz, tz, _tz, thz, _thz, change = 0, AllNumbersAmount, answ;

	k = input_k(k);
	n = input_n(n);

	change = checking_usl(n, k, change);

	switch (change) {
	case 1:
		k = input_k(k);
		break;
	case 2:
		n = input_n(n);
		break;
	}

	nz = k - 1;
	oz = 1;
	tz = 0;
	thz = 0;
	for (i = 2; i <= n; i++) {
		_nz = nz;
		_oz = oz;
		_tz = tz;
		_thz = thz;

		nz = (_nz + _oz + _tz + _thz) * (k - 1);
		thz = _tz;
		tz = _oz;
		oz = _nz;
		
	}
	long nums = nz + oz + tz + thz;
	long total = (k - 1) * pow(k, n);

	/*
	nz = k - 1;
	oz = 1;
	tz = 0;

	for (i = 2; i <= n; i++)
	{
		_nz = nz;
		_oz = oz;
		_tz = tz;
		nz = _nz * (k - 1) + _oz * (k - 1);
		oz = _nz;
		tz = _tz * k + _oz;
	}
	*/

	cout << "Количество чисел, в записи которых содержится >3 подряд идущих нулей = " << total - nums << endl;
}
