// MinHeap.h

#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <vector>
#include <iostream>
#include <climits>

class MinHeap {
private:
    std::vector<std::pair<int, int>> heap;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < heap.size() && heap[l] < heap[i])
            smallest = l;

        if (r < heap.size() && heap[r] < heap[smallest])
            smallest = r;

        if (smallest != i) {
            std::swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

public:
    MinHeap() {}

    void insert(std::pair<int, int> key) {
        bool found = false;
        for (size_t i = 0; i < heap.size(); ++i) {
            if (heap[i].second == key.second) {
                found = true;
                if (heap[i].first > key.first) {
                    heap[i] = key;
                    while (i != 0 && heap[parent(i)] > heap[i]) {
                        std::swap(heap[i], heap[parent(i)]);
                        i = parent(i);
                    }
                }
                break;
            }
        }
        if (!found) {
            heap.push_back(key);
            int i = heap.size() - 1;
            while (i != 0 && heap[parent(i)] > heap[i]) {
                std::swap(heap[i], heap[parent(i)]);
                i = parent(i);
            }
        }
    }


    std::pair<int, int> extractMin() {
        if (heap.empty())
            return { INT_MAX, INT_MAX };

        std::pair<int, int> root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);

        return root;
    }

    std::pair<int, int> getMin() {
        if (heap.empty())
            return { INT_MAX, INT_MAX };
        return heap[0];
    }

    bool isEmpty() {
        return heap.empty();
    }
};

#endif
