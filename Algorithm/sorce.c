
#define SORCE_H
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "algorithm.h"
#include <stdbool.h>


// ���İ����� ����ϴ� �Լ�
void printSortStep(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ���� ���� �˰���
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                // ���� ���� ���
                printf("���İ���: ", i * (n - 1) + j + 1);
                for (int k = 0; k < n; k++) {
                    printf("%d ", arr[k]);
                }
                printf("\n");
            }
        }
    }
}

// ���� ���� �˰���
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

        // ���� ���� ���
        printf("���İ���: ", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

// ���� ���� �˰���
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

        // ���� ���� ���
        printf("Step %d: ", i);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

// ���� ���� �˰���
void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // �ӽ� �迭 ���� �Ҵ�
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    // ���� �Ҵ��� �����ߴ��� Ȯ��
    if (L == NULL || R == NULL) {
        // ���� �Ҵ� ���� �� ó��
        printf("���� �Ҵ� ����\n");
        // ������ ��� ������ ó���� �ؾ� �մϴ�.
        return;
    }

    // ������ ����
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    // ���� ����
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

        // ���� ���� ���
        printf("���İ���: ");
        for (int m = left; m <= k; m++) {
            printf("%d ", arr[m]);
        }
        for (int m = k + 1; m <= right; m++) {
            printf("| %d ", arr[m]);
        }
        printf("\n");
    }

    // ���� ��ҵ� ����
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

    // ���� �Ҵ�� �迭 ����
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


// �� ���Ŀ��� ���Ǵ� ��Ƽ�� �Լ�
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

// �� ���� �˰���
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // ���� �� �� �κ� ����
        quickSort(arr, low, pi - 1);

        // ���� ���� ���
        printf("���İ���: ");
        printSortStep(arr, high + 1);

        quickSort(arr, pi + 1, high);
    }
}

// �� ���� �˰���
void heapSort(int arr[], int n) {
    // �ʱ� �� ����
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);

        // ���� ���� ���
        printf("���İ���: ");
        printSortStep(arr, n);
    }

    // ���� �ϳ��� ������ �����Ͽ� ����
    for (int i = n - 1; i > 0; i--) {
        // �ִ� ���ҿ� ������ ���� ��ȯ
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // �� �ٽ� ����
        heapify(arr, i, 0);

        // ���� ���� ���
        printf("���İ���: ");
        printSortStep(arr, n);
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;  // ��Ʈ ���
    int left = 2 * i + 1;  // ���� �ڽ� ���
    int right = 2 * i + 2;  // ������ �ڽ� ���

    // ���� �ڽ��� ��Ʈ���� ũ�� largest ����
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // ������ �ڽ��� ��Ʈ���� ũ�� largest ����
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // largest�� ��Ʈ�� �ƴ϶�� ��ȯ �� ��� ȣ��
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // ��� ȣ��
        heapify(arr, n, largest);
    }
}

// �׷��� ����ü ����
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;

    // ���� ��� ���� �Ҵ�
    graph->graph = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->graph[i] = (int*)malloc(V * sizeof(int));
        // �ʱ�ȭ: ��� �� 0���� ����
        for (int j = 0; j < V; j++) {
            graph->graph[i][j] = 0;
        }
    }

    return graph;
}

// �׷����� ���� �߰�
void addEdge(Graph* graph, int src, int dest, int weight) {
    graph->graph[src][dest] = weight;
    graph->graph[dest][src] = weight;
}

// ����ڷκ��� ���� ���� �Է� �ޱ�
void inputEdges(Graph* graph) {
    int E;
    printf("������ ���� �Է��ϼ���: ");
    scanf_s("%d", &E);

    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        printf("���� %d ������ �Է��ϼ��� (����1 ����2 ����ġ): ", i + 1);
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

// ���� �˰��� �Լ� ����
void primAlgorithm() {
    int* parent = (int*)malloc(graph.V * sizeof(int)); // ���õ� ������ �θ� ������ �����ϱ� ���� �迭
    int* key = (int*)malloc(graph.V * sizeof(int));    // ���� ������ ����� ������ �ּ� ����ġ�� �����ϱ� ���� �迭
    int* inMST = (int*)malloc(graph.V * sizeof(int));  // �ּ� ���� Ʈ���� ���Ե� �������� ���θ� ��Ÿ���� �迭

    // �ʱ�ȭ
    for (int i = 0; i < graph.V; i++) {
        key[i] = INT_MAX;    // ���Ѵ�� �ʱ�ȭ
        inMST[i] = 0;        // �ּ� ���� Ʈ���� ���Ե��� ���� ���·� �ʱ�ȭ
    }

    key[0] = 0;  // ���� ������ Ű ���� 0���� ����
    parent[0] = -1;  // ���� ������ �θ� ����

    for (int count = 0; count < graph.V - 1; count++) {
        int u = minKey(key, inMST, graph.V); // �ּ� Ű ���� ���� ���� ã��
        inMST[u] = 1;  // �ּ� ���� Ʈ���� ����

        // ���õ� ���� ���
        printf("���� %d: %d - %d\n", count + 1, parent[u], u);

        // u�� ����� �������� Ű �� ����
        for (int v = 0; v < graph.V; v++) {
            if (graph.graph[u][v] && inMST[v] == 0 && graph.graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph.graph[u][v];
            }
        }
    }

    // �޸� ����
    free(parent);
    free(key);
    free(inMST);
}


// �׷��� �޸� ���� �Լ�
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        free(graph->graph[i]);
    }
    free(graph->graph);
    free(graph);
}

// Union-Find �ڷᱸ�� �Լ�
int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

Graph initializeGraph() {
    Graph graph;
    int vertices, edges;

    // ������ �� �Է�
    printf("������ ���� �Է��ϼ���: ");
    scanf_s("%d", &vertices);

    // ������ �� �Է�
    printf("������ ���� �Է��ϼ���: ");
    scanf_s("%d", &edges);

    // �׷��� �ʱ�ȭ
    graph.V = vertices;
    graph.graph = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph.graph[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            graph.graph[i][j] = 0;
        }
    }

    // ���� ���� �Է�
    for (int i = 0; i < edges; i++) {
        int v1, v2, weight;
        printf("���� %d ������ �Է��ϼ��� (����1 ����2 ����ġ): ", i + 1);
        scanf_s("%d %d %d", &v1, &v2, &weight);
        graph.graph[v1][v2] = weight;
        graph.graph[v2][v1] = weight;  // ������ �׷������ ����
    }

    return graph;
}


void unionSets(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

//ũ�罺ų �˰���
void kruskalAlgorithm(Graph* graph) {
    int V = graph->V;
    int** edges = graph->graph;

    // ���ĵ� ������ ������ �迭
    int** sortedEdges = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        sortedEdges[i] = (int*)malloc(3 * sizeof(int));
    }

    int edgeCount = 0;

    // ��� ������ sortedEdges �迭�� ����
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

    // ����ġ�� ���� ������ ����
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

    // �ּ� ���� Ʈ���� ������ �迭
    int* parent = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        parent[i] = -1;  // �� ������ �θ� �ʱ�ȭ
    }

    printf("ũ�罺Į �˰��� ��� (���� ���):\n");

    for (int i = 0; i < edgeCount; i++) {
        int x = find(parent, sortedEdges[i][0]);
        int y = find(parent, sortedEdges[i][1]);

        if (x != y) {
            // ����Ŭ�� �������� ������ ����
            printf("���� %d: %d - %d\n", i + 1, sortedEdges[i][0], sortedEdges[i][1]);
            unionSets(parent, x, y);
        }
    }

    // �޸� ����
    for (int i = 0; i < V; i++) {
        free(sortedEdges[i]);
    }
    free(sortedEdges);
    free(parent);
}

void clearScreen() {
    system("cls");
}

//���� �˰���
void sortAlgorithmMenu() {
    int choice;
    printf("1. ���� ����\n");
    printf("2. ���� ����\n");
    printf("3. ���� ����\n");
    printf("4. ���� ����\n");
    printf("5. �� ����\n");
    printf("6. �� ����\n");
    printf("�˰����� �����ϼ���: ");
    scanf_s("%d", &choice);


    int n;
    printf("�迭�� ũ�⸦ �Է��ϼ���: ");
    scanf_s("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    printf("�迭�� ��Ҹ� �Է��ϼ���:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf_s("%d", &arr[i]);
    }

    // ���� �޴� ��� ���� �����
    clearScreen();

    switch (choice) {
    case 1:
        printf("���� ������ �����߽��ϴ�.\n");
        printf("���� �� �迭: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        // ���� ���� ����
        bubbleSort(arr, n);

        printf("���� �� �迭: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        break;
    case 2:
        printf("���� ������ �����߽��ϴ�.\n");
        printf("���� �� �迭: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        // ���� ���� ����
        selectionSort(arr, n);

        printf("���� �� �迭: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        break;
    case 3:
        printf("���� ������ �����߽��ϴ�.\n");
        printf("���� �� �迭: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        // ���� ���� ����
        insertionSort(arr, n);

        printf("���� �� �迭: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        break;
    case 4:
        printf("���� ������ �����߽��ϴ�.\n");
        printf("���� �� �迭: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        // ���� ���� ����
        mergeSort(arr, 0, n - 1);

        printf("���� �� �迭: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        break;
    case 5:
        // �� ���� ȣ��
        printf("�� ������ �����߽��ϴ�.\n");
        printf("���� �� �迭: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        quickSort(arr, 0, n - 1);

        // ���� ��� ���
        printf("���� �� �迭: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        break;
    case 6:
        printf("�� ������ �����߽��ϴ�.\n");
        printf("���� �� �迭: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        // �� ���� ����
        heapSort(arr, n);

        printf("���� �� �迭: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        
        break;
    default:
        printf("�߸��� �����Դϴ�.\n");
    }
    

    free(arr); // ���� �Ҵ��� �迭�� �����մϴ�.
}

//�׷��� �˰���
void graphicAlgorithmMenu() {
    int choice;
    printf("1. ���� �˰���\n");
    printf("2. ũ�罺Į �˰���\n");   
    printf("�˰����� �����ϼ���: ");
    scanf_s("%d", &choice);

    switch (choice) {
    case 1:
        printf("���� �˰����� �����߽��ϴ�.\n");
        primAlgorithm(&graph);
        break;
    case 2:
        printf("ũ�罺Į �˰����� �����߽��ϴ�.\n");
        kruskalAlgorithm(&graph);
        break;   
    default:
        printf("�߸��� �����Դϴ�.\n");
    }
}