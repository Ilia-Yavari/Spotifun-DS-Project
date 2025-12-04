#pragma once
#include "../include/Music.h"

#define MAX_ARTIST_ID 100
#define MAX_HEAP_SIZE 10000
#define MAX_STACK_SIZE 500

template <typename T>
class SparseSet {
private:
    T dense[MAX_ARTIST_ID];
    int sparse[MAX_ARTIST_ID];
    int n;

public:
    SparseSet();

    T search();

    bool insert();

    bool remove();

    void reset();

};

template <typename T>
class Heap {
protected:
    T* data[MAX_HEAP_SIZE];
    int size;

    virtual bool compare(T* a, T* b) = 0;

    void swap(int i, int j) {
        T* temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (compare(data[index], data[parent])) {
                swap(index, parent);
                index = parent;
            } else break;
        }
    }

    void heapifyDown(int index) {
        int best = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && compare(data[left], data[best])) best = left;
        if (right < size && compare(data[right], data[best])) best = right;

        if (best != index) {
            swap(index, best);
            heapifyDown(best);
        }
    }

public:
    Heap() : size(0) {}

    void insert(T* element) {
        if (size < MAX_HEAP_SIZE) {
            data[size] = element;
            heapifyUp(size);
            size++;
        }
    }

    T* peek() const {
        return (size > 0) ? data[0] : nullptr;
    }

    T* extract() {
        if (size == 0) return nullptr;
        T* root = data[0];
        size--;
        if (size > 0) {
            data[0] = data[size];
            heapifyDown(0);
        }
        return root;
    }

    void removeById(int id) {
        for (int i = 0; i < size; i++) {
            if (data[i]->id == id) {
                data[i] = data[size - 1];
                size--;
                if (i < size) {
                    heapifyDown(i);
                    heapifyUp(i);
                }
                return;
            }
        }
    }
};

class MaxHeap : public Heap<Music> {
    bool compare(Music* a, Music* b) override {
        return a->rating > b->rating;
    }
};

class MinHeap : public Heap<Music> {
    bool compare(Music* a, Music* b) override {
        return a->rating < b->rating;
    }
};

class HistoryStack {
private:
    Music* stack[MAX_STACK_SIZE];
    int top;

public:
    HistoryStack() : top(-1) {}

    void push(Music* m);

    Music* pop();

    Music* peek() const;

    bool isEmpty() const {
        return top == -1;
    }

    void removeMusic(int musicId);
};