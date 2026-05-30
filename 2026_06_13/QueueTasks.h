#ifndef QUEUE_TASKS_H
#define QUEUE_TASKS_H

#include <iostream>
#include <queue>
#include <vector>
#include <random>
#include <ctime>

template <typename T>
class LinkedQueue {
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    int count;
public:
    LinkedQueue() : head(nullptr), tail(nullptr), count(0) {}
    ~LinkedQueue() {
        while (!IsEmpty()) Dequeue();
    }

    void Enqueue(T val) {
        Node* newNode = new Node(val);
        if (IsEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    T Dequeue() {
        if (IsEmpty()) return T();
        Node* temp = head;
        T data = temp->data;
        head = head->next;
        if (head == nullptr) tail = nullptr;
        delete temp;
        count--;
        return data;
    }

    bool IsEmpty() const { return head == nullptr; }
    int Size() const { return count; }
    T& Front() { return head->data; }
};

struct Passenger {
    int arrivalTime;
};

class BusStopSimulation {
public:
    static void Run() {
        int avgPassengerInterval;
        int avgBusInterval;
        bool isTerminal;
        int maxPeopleInQueue;
        
        std::cout << "Enter average time between passenger arrivals (min): ";
        std::cin >> avgPassengerInterval;
        std::cout << "Enter average time between bus arrivals (min): ";
        std::cin >> avgBusInterval;
        std::cout << "Is this a terminal stop? (1 for Yes, 0 for No): ";
        std::cin >> isTerminal;
        std::cout << "Enter max desired queue size (N): ";
        std::cin >> maxPeopleInQueue;

        std::cout << "\n--- Simulation Results ---" << std::endl;
        Simulate(avgPassengerInterval, avgBusInterval, isTerminal, maxPeopleInQueue);
    }

private:
    static void Simulate(int pInterval, int bInterval, bool isTerminal, int N) {
        std::mt19937 rng(static_cast<unsigned>(time(nullptr)));
        std::exponential_distribution<double> pDist(1.0 / pInterval);
        std::exponential_distribution<double> bDist(1.0 / bInterval);
        std::uniform_int_distribution<int> seatDist(1, 20); // Random free seats

        LinkedQueue<Passenger> stopQueue;
        int totalTime = 1440; // 24 hours
        int currentTime = 0;
        int nextPassengerTime = static_cast<int>(pDist(rng));
        int nextBusTime = static_cast<int>(bDist(rng));

        long long totalWaitTime = 0;
        int passengersServed = 0;
        int maxQueueObserved = 0;

        while (currentTime < totalTime) {
            // Passenger arrives
            if (currentTime >= nextPassengerTime) {
                stopQueue.Enqueue({currentTime});
                nextPassengerTime += std::max(1, static_cast<int>(pDist(rng)));
            }

            // Bus arrives
            if (currentTime >= nextBusTime) {
                int freeSeats = isTerminal ? 50 : seatDist(rng);
                while (freeSeats > 0 && !stopQueue.IsEmpty()) {
                    Passenger p = stopQueue.Dequeue();
                    totalWaitTime += (currentTime - p.arrivalTime);
                    passengersServed++;
                    freeSeats--;
                }
                nextBusTime += std::max(1, static_cast<int>(bDist(rng)));
            }

            if (stopQueue.Size() > maxQueueObserved) maxQueueObserved = stopQueue.Size();
            currentTime++;
        }

        double avgWait = (passengersServed > 0) ? (double)totalWaitTime / passengersServed : 0;
        std::cout << "Average wait time: " << avgWait << " minutes" << std::endl;
        std::cout << "Max queue size observed: " << maxQueueObserved << std::endl;

        if (maxQueueObserved > N) {
            std::cout << "Bus interval " << bInterval << " is NOT sufficient to keep queue <= " << N << std::endl;
            // Rough estimation for sufficient interval
            int suggestedInterval = static_cast<int>(bInterval * ((double)N / maxQueueObserved));
            if (suggestedInterval < 1) suggestedInterval = 1;
            std::cout << "Suggested max interval: ~" << suggestedInterval << " minutes" << std::endl;
        } else {
            std::cout << "Bus interval " << bInterval << " is sufficient." << std::endl;
        }
    }
};

#endif // QUEUE_TASKS_H
