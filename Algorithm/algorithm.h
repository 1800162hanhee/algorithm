#ifndef ALGORITHM_H
#define ALGORITHM_H
#pragma once

typedef struct {
    int V;
    int** graph;
} Graph;

void sortAlgorithmMenu();
void graphicAlgorithmMenu();
void heapify(int arr[], int n, int i);
void primAlgorithm(Graph* graph);
void kruskalAlgorithm(Graph* graph);
int find(int parent[], int i);
void Union(int parent[], int x, int y);
void unionSets(int parent[], int x, int y);
extern Graph graph;

#endif
