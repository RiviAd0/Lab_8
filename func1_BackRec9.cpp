#include <iostream>
#include <fstream>
#include <string>
#include "func1_BackRec9.h"

void readInput(const std::string& filename, int& N, int& B, int*& weights, int*& volumes) {
    std::ifstream fin(filename);
    if (!fin) {
        std::cerr << "dont open file" << filename << "\n";
        exit(1);
    }
    fin >> N >> B;
    weights = new int[N];
    volumes = new int[N];

    for (int i = 0; i < N; i++) {
        fin >> weights[i];
    }
    for (int i = 0; i < N; i++) {
        fin >> volumes[i];
    }
    fin.close();
}

void initializeDP(State*& m, int size) {
    for (int w = 0; w < size; w++) {
        m[w].maxCount = 0;
        m[w].totalVolume = 0;
        m[w].totalWeight = 0;
        m[w].itemCount = 0;
    }
}

void processArtifacts(int N, int B, int* weights, int* volumes, State*& m) {
    for (int i = 0; i < N; i++) {
        for (int w = B; w >= weights[i]; w--) {
            const State& prev = m[w - weights[i]];
            State& curr = m[w];

            int newCount = prev.maxCount + 1;
            int newVolume = prev.totalVolume + volumes[i];
            int newWeight = prev.totalWeight + weights[i];

            if (newWeight <= B) {
                if (newCount > curr.maxCount ||
                    (newCount == curr.maxCount && newVolume > curr.totalVolume)) {
                    curr.maxCount = newCount;
                    curr.totalVolume = newVolume;
                    curr.totalWeight = newWeight;
                    for (int k = 0; k < prev.itemCount; k++) {
                        curr.items[k] = prev.items[k];
                    }
                    curr.items[prev.itemCount] = i + 1;
                    curr.itemCount = prev.itemCount + 1;
                }
            }
        }
    }
}

State findBestSolution(State*& m, int B) {
    State best = m[0];
    for (int w = 1; w <= B; w++) {
        if (m[w].maxCount > best.maxCount ||
            (m[w].maxCount == best.maxCount && m[w].totalVolume > best.totalVolume)) {
            best = m[w];
        }
    }
    return best;
}

void printResult(const State& best, int* weights, int* volumes) {
    using namespace std;
    int sum_weight = 0;
    int sum_volume = 0;
    cout << "Выбранные артефакты: ";
    for (int i = 0; i < best.itemCount; i++) {
        int indx = best.items[i];
        sum_weight += weights[indx - 1];
        sum_volume += volumes[indx - 1];
        cout << indx << " ";
    }
    cout << "\nСуммарный вес: " << sum_weight << "\n";
    cout << "Суммарный объем: " << sum_volume << "\n";
}