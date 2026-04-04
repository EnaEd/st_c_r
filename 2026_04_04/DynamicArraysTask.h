//
// Created by Junie on 04.04.2026.
//

#ifndef ST_C_R_DYNAMICARRAYSTASK_H
#define ST_C_R_DYNAMICARRAYSTASK_H
#pragma once
#include "../Base.h"
#include "../Shared/Helpers.h"
#include <iostream>
#include <string>
#include <limits>

class DynamicArraysTask : public Base {
public:
    DynamicArraysTask() {}
    void Run() override {
        const Helpers helpers;
        int choice;
        do {
            cout << "\n--- Dynamic Arrays & Pointers Tasks ---\n";
            cout << "1. Merge unique elements of A not in B\n";
            cout << "2. Sum and Product via pointers\n";
            cout << "3. Count negative, positive, and zero elements\n";
            cout << "0. Exit\n";
            choice = helpers.GetDataFromUser<int>("Select task: ");

            switch (choice) {
                case 1: Task1Run(); break;
                case 2: Task2Run(); break;
                case 3: Task3Run(); break;
                case 0: break;
                default: cout << "Invalid choice.\n";
            }
        } while (choice != 0);
    }

private:
    //region Task 1
    bool contains(int* arr, int size, int val) {
        for (int i = 0; i < size; ++i) {
            if (*(arr + i) == val) return true;
        }
        return false;
    }

    void Task1Run() {
        const Helpers helpers;
        int M = helpers.GetDataFromUser<int>("Enter size of array A (M): ");
        int N = helpers.GetDataFromUser<int>("Enter size of array B (N): ");

        int* A = new int[M];
        int* B = new int[N];

        cout << "Enter elements for array A:\n";
        for (int i = 0; i < M; ++i) {
            A[i] = helpers.GetDataFromUser<int>("A[" + std::to_string(i) + "]: ");
        }

        cout << "Enter elements for array B:\n";
        for (int i = 0; i < N; ++i) {
            B[i] = helpers.GetDataFromUser<int>("B[" + std::to_string(i) + "]: ");
        }

        // Count unique elements in A that are not in B
        int count = 0;
        for (int i = 0; i < M; ++i) {
            bool inB = contains(B, N, A[i]);
            bool seenInA = contains(A, i, A[i]); // Check if seen before in A to avoid duplicates
            if (!inB && !seenInA) {
                count++;
            }
        }

        int* C = new int[count];
        int cIndex = 0;
        for (int i = 0; i < M; ++i) {
            if (!contains(B, N, A[i]) && !contains(A, i, A[i])) {
                C[cIndex++] = A[i];
            }
        }

        cout << "Array A: ";
        for (int i = 0; i < M; ++i) cout << A[i] << " ";
        cout << "\nArray B: ";
        for (int i = 0; i < N; ++i) cout << B[i] << " ";
        cout << "\nResulting Array C (A elements not in B, unique): ";
        for (int i = 0; i < count; ++i) cout << C[i] << " ";
        cout << endl;

        delete[] A;
        delete[] B;
        delete[] C;
    }
    //endregion

    //region Task 2
    void calcSumProduct(int* arr, int size, int* sum, long long* product) {
        *sum = 0;
        *product = 1;
        for (int i = 0; i < size; ++i) {
            *sum += *(arr + i);
            *product *= *(arr + i);
        }
    }

    void Task2Run() {
        const Helpers helpers;
        int size = helpers.GetDataFromUser<int>("Enter array size: ");
        if (size <= 0) return;

        int* arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = helpers.GetDataFromUser<int>("Element " + std::to_string(i) + ": ");
        }

        int sum;
        long long product;
        calcSumProduct(arr, size, &sum, &product);

        cout << "Sum: " << sum << "\nProduct: " << product << endl;

        delete[] arr;
    }
    //endregion

    //region Task 3
    void countElements(int* arr, int size, int* neg, int* pos, int* zero) {
        *neg = *pos = *zero = 0;
        for (int i = 0; i < size; ++i) {
            int val = *(arr + i);
            if (val < 0) (*neg)++;
            else if (val > 0) (*pos)++;
            else (*zero)++;
        }
    }

    void Task3Run() {
        const Helpers helpers;
        int size = helpers.GetDataFromUser<int>("Enter array size: ");
        if (size <= 0) return;

        int* arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = helpers.GetDataFromUser<int>("Element " + std::to_string(i) + ": ");
        }

        int neg, pos, zero;
        countElements(arr, size, &neg, &pos, &zero);

        cout << "Negative: " << neg << "\nPositive: " << pos << "\nZero: " << zero << endl;

        delete[] arr;
    }
    //endregion
};

#endif //ST_C_R_DYNAMICARRAYSTASK_H
