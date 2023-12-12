#include <stdio.h>
#include <stdlib.h>
#include "algorithm.h"

Graph graph;

int main() {   
    
    // �׷��� �ʱ�ȭ
    graph.V = 5;
    graph.graph = (int**)malloc(graph.V * sizeof(int*));
    for (int i = 0; i < graph.V; i++) {
        graph.graph[i] = (int*)malloc(graph.V * sizeof(int));
        for (int j = 0; j < graph.V; j++) {
            graph.graph[i][j] = 0;
        }
    }

    // ���� ���� �Է�
    graph.graph[0][1] = 2;
    graph.graph[0][2] = 3;
    graph.graph[1][2] = 1;
    graph.graph[1][3] = 4;
    graph.graph[2][3] = 5;
    graph.graph[3][4] = 6;
    graph.graph[2][4] = 7;

    

    int choice;
    do {
        printf("0. ����\n");
        printf("1. ���� �˰���\n");
        printf("2. �׷��� �˰���\n");
        printf("�޴��� �����ϼ���: ");
        scanf_s("%d", &choice);

        switch (choice) {
            case 0:
                printf("���α׷� ����\n");
                break;
            case 1:
                sortAlgorithmMenu();               
              
                break;
            case 2:
                graphicAlgorithmMenu();
                
                break;
            default:
                printf("�߸��� �����Դϴ�. �ٽ� �õ��ϼ���.\n");
        }

    } while (choice != 0);

    return 0;
}


