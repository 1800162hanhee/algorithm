
#define SORCE_H
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "algorithm.h"
#include <stdbool.h>


// 정렬과정을 출력하는 함수
void printSortStep(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 버블 정렬 알고리즘
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                // 정렬 과정 출력
                printf("정렬과정: ", i * (n - 1) + j + 1);
                for (int k = 0; k < n; k++) {
                    printf("%d ", arr[k]);
                }
                printf("\n");
            }
        }
    }
}

// 선택 정렬 알고리즘
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap arr[i] and arr[minIndex]
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

        // 정렬 과정 출력
        printf("정렬과정: ", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

// 삽입 정렬 알고리즘
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        // 정렬 과정 출력
        printf("Step %d: ", i);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

// 병합 정렬 알고리즘
void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // 임시 배열 동적 할당
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    // 동적 할당이 성공했는지 확인
    if (L == NULL || R == NULL) {
        // 동적 할당 실패 시 처리
        printf("동적 할당 실패\n");
        // 실패한 경우 적절한 처리를 해야 합니다.
        return;
    }

    // 데이터 복사
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    // 병합 과정
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;

        // 정렬 과정 출력
        printf("정렬과정: ");
        for (int m = left; m <= k; m++) {
            printf("%d ", arr[m]);
        }
        for (int m = k + 1; m <= right; m++) {
            printf("| %d ", arr[m]);
        }
        printf("\n");
    }

    // 남은 요소들 복사
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // 동적 할당된 배열 해제
    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}


// 퀵 정렬에서 사용되는 파티션 함수
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            // swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // swap arr[i + 1] and arr[high] (pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// 퀵 정렬 알고리즘
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // 분할 후 각 부분 정렬
        quickSort(arr, low, pi - 1);

        // 정렬 과정 출력
        printf("정렬과정: ");
        printSortStep(arr, high + 1);

        quickSort(arr, pi + 1, high);
    }
}

// 힙 정렬 알고리즘
void heapSort(int arr[], int n) {
    // 초기 힙 구성
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);

        // 정렬 과정 출력
        printf("정렬과정: ");
        printSortStep(arr, n);
    }

    // 원소 하나씩 힙에서 추출하여 정렬
    for (int i = n - 1; i > 0; i--) {
        // 최대 원소와 마지막 원소 교환
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // 힙 다시 구성
        heapify(arr, i, 0);

        // 정렬 과정 출력
        printf("정렬과정: ");
        printSortStep(arr, n);
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;  // 루트 노드
    int left = 2 * i + 1;  // 왼쪽 자식 노드
    int right = 2 * i + 2;  // 오른쪽 자식 노드

    // 왼쪽 자식이 루트보다 크면 largest 갱신
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 오른쪽 자식이 루트보다 크면 largest 갱신
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // largest가 루트가 아니라면 교환 후 재귀 호출
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // 재귀 호출
        heapify(arr, n, largest);
    }
}

// 그래프 구조체 선언
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;

    // 인접 행렬 동적 할당
    graph->graph = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->graph[i] = (int*)malloc(V * sizeof(int));
        // 초기화: 모든 값 0으로 설정
        for (int j = 0; j < V; j++) {
            graph->graph[i][j] = 0;
        }
    }

    return graph;
}

// 그래프에 간선 추가
void addEdge(Graph* graph, int src, int dest, int weight) {
    graph->graph[src][dest] = weight;
    graph->graph[dest][src] = weight;
}

// 사용자로부터 간선 정보 입력 받기
void inputEdges(Graph* graph) {
    int E;
    printf("간선의 수를 입력하세요: ");
    scanf_s("%d", &E);

    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        printf("간선 %d 정보를 입력하세요 (정점1 정점2 가중치): ", i + 1);
        scanf_s("%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }
}


int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

// 프림 알고리즘 함수 구현
void primAlgorithm() {
    int* parent = (int*)malloc(graph.V * sizeof(int)); // 선택된 간선의 부모 정점을 저장하기 위한 배열
    int* key = (int*)malloc(graph.V * sizeof(int));    // 현재 정점과 연결된 간선의 최소 가중치를 저장하기 위한 배열
    int* inMST = (int*)malloc(graph.V * sizeof(int));  // 최소 신장 트리에 포함된 정점인지 여부를 나타내는 배열

    // 초기화
    for (int i = 0; i < graph.V; i++) {
        key[i] = INT_MAX;    // 무한대로 초기화
        inMST[i] = 0;        // 최소 신장 트리에 포함되지 않은 상태로 초기화
    }

    key[0] = 0;  // 시작 정점의 키 값을 0으로 설정
    parent[0] = -1;  // 시작 정점은 부모가 없음

    for (int count = 0; count < graph.V - 1; count++) {
        int u = minKey(key, inMST, graph.V); // 최소 키 값을 가진 정점 찾기
        inMST[u] = 1;  // 최소 신장 트리에 포함

        // 선택된 간선 출력
        printf("간선 %d: %d - %d\n", count + 1, parent[u], u);

        // u와 연결된 정점들의 키 값 갱신
        for (int v = 0; v < graph.V; v++) {
            if (graph.graph[u][v] && inMST[v] == 0 && graph.graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph.graph[u][v];
            }
        }
    }

    // 메모리 해제
    free(parent);
    free(key);
    free(inMST);
}


// 그래프 메모리 해제 함수
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        free(graph->graph[i]);
    }
    free(graph->graph);
    free(graph);
}

// Union-Find 자료구조 함수
int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

Graph initializeGraph() {
    Graph graph;
    int vertices, edges;

    // 정점의 수 입력
    printf("정점의 수를 입력하세요: ");
    scanf_s("%d", &vertices);

    // 간선의 수 입력
    printf("간선의 수를 입력하세요: ");
    scanf_s("%d", &edges);

    // 그래프 초기화
    graph.V = vertices;
    graph.graph = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph.graph[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            graph.graph[i][j] = 0;
        }
    }

    // 간선 정보 입력
    for (int i = 0; i < edges; i++) {
        int v1, v2, weight;
        printf("간선 %d 정보를 입력하세요 (정점1 정점2 가중치): ", i + 1);
        scanf_s("%d %d %d", &v1, &v2, &weight);
        graph.graph[v1][v2] = weight;
        graph.graph[v2][v1] = weight;  // 무방향 그래프라고 가정
    }

    return graph;
}


void unionSets(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

//크루스킬 알고리즘
void kruskalAlgorithm(Graph* graph) {
    int V = graph->V;
    int** edges = graph->graph;

    // 정렬된 간선을 저장할 배열
    int** sortedEdges = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        sortedEdges[i] = (int*)malloc(3 * sizeof(int));
    }

    int edgeCount = 0;

    // 모든 간선을 sortedEdges 배열에 복사
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (edges[i][j] != 0) {
                sortedEdges[edgeCount][0] = i;
                sortedEdges[edgeCount][1] = j;
                sortedEdges[edgeCount][2] = edges[i][j];
                edgeCount++;
            }
        }
    }

    // 가중치에 따라 간선을 정렬
    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = 0; j < edgeCount - i - 1; j++) {
            if (sortedEdges[j][2] > sortedEdges[j + 1][2]) {
                // Swap
                int* temp = sortedEdges[j];
                sortedEdges[j] = sortedEdges[j + 1];
                sortedEdges[j + 1] = temp;
            }
        }
    }

    // 최소 신장 트리를 저장할 배열
    int* parent = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        parent[i] = -1;  // 각 정점의 부모를 초기화
    }

    printf("크루스칼 알고리즘 결과 (간선 출력):\n");

    for (int i = 0; i < edgeCount; i++) {
        int x = find(parent, sortedEdges[i][0]);
        int y = find(parent, sortedEdges[i][1]);

        if (x != y) {
            // 사이클이 형성되지 않으면 선택
            printf("간선 %d: %d - %d\n", i + 1, sortedEdges[i][0], sortedEdges[i][1]);
            unionSets(parent, x, y);
        }
    }

    // 메모리 해제
    for (int i = 0; i < V; i++) {
        free(sortedEdges[i]);
    }
    free(sortedEdges);
    free(parent);
}

void clearScreen() {
    system("cls");
}

//정렬 알고리즘
void sortAlgorithmMenu() {
    int choice;
    printf("1. 버블 정렬\n");
    printf("2. 선택 정렬\n");
    printf("3. 삽입 정렬\n");
    printf("4. 병합 정렬\n");
    printf("5. 퀵 정렬\n");
    printf("6. 힙 정렬\n");
    printf("알고리즘을 선택하세요: ");
    scanf_s("%d", &choice);


    int n;
    printf("배열의 크기를 입력하세요: ");
    scanf_s("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    printf("배열의 요소를 입력하세요:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf_s("%d", &arr[i]);
    }

    // 이전 메뉴 출력 내용 덮어쓰기
    clearScreen();

    switch (choice) {
    case 1:
        printf("버블 정렬을 선택했습니다.\n");
        printf("정렬 전 배열: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        // 버블 정렬 수행
        bubbleSort(arr, n);

        printf("정렬 후 배열: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        break;
    case 2:
        printf("선택 정렬을 선택했습니다.\n");
        printf("정렬 전 배열: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        // 선택 정렬 수행
        selectionSort(arr, n);

        printf("정렬 후 배열: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        break;
    case 3:
        printf("삽입 정렬을 선택했습니다.\n");
        printf("정렬 전 배열: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        // 삽입 정렬 수행
        insertionSort(arr, n);

        printf("정렬 후 배열: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        break;
    case 4:
        printf("병합 정렬을 선택했습니다.\n");
        printf("정렬 전 배열: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        // 병합 정렬 수행
        mergeSort(arr, 0, n - 1);

        printf("정렬 후 배열: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        break;
    case 5:
        // 퀵 정렬 호출
        printf("퀵 정렬을 선택했습니다.\n");
        printf("정렬 전 배열: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        quickSort(arr, 0, n - 1);

        // 정렬 결과 출력
        printf("정렬 후 배열: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        break;
    case 6:
        printf("힙 정렬을 선택했습니다.\n");
        printf("정렬 전 배열: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        // 힙 정렬 수행
        heapSort(arr, n);

        printf("정렬 후 배열: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        
        break;
    default:
        printf("잘못된 선택입니다.\n");
    }
    

    free(arr); // 동적 할당한 배열을 해제합니다.
}

//그래픽 알고리즘
void graphicAlgorithmMenu() {
    int choice;
    printf("1. 프림 알고리즘\n");
    printf("2. 크루스칼 알고리즘\n");   
    printf("알고리즘을 선택하세요: ");
    scanf_s("%d", &choice);

    switch (choice) {
    case 1:
        printf("프림 알고리즘을 선택했습니다.\n");
        primAlgorithm(&graph);
        break;
    case 2:
        printf("크루스칼 알고리즘을 선택했습니다.\n");
        kruskalAlgorithm(&graph);
        break;   
    default:
        printf("잘못된 선택입니다.\n");
    }
}