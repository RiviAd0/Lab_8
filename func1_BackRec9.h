#pragma once
#ifndef FUNC1_BACKREC9_H
#define FUNC1_BACKREC9_H

struct State {
    int maxCount;        //Максимальное число артефактов
    int totalVolume;     //Общий объем выбранных артефактов
    int totalWeight;     //Общий вес выбранных артефактов
    int items[100];      //Массив индексов выбранных артефактов
    int itemCount;       //Количество выбранных артефактов
};
void readInput(const std::string& filename, int& N, int& B, int*& weights, int*& volumes);
void initializeDP(State*& dp, int size);
void processArtifacts(int N, int B, int* weights, int* volumes, State*& dp);
State findBestSolution(State*& dp, int B);
void printResult(const State& best, int* weights, int* volumes);

#endif