#include <stdio.h>
#include <stdlib.h>
#include "algorithm.h"

Graph graph;

int main() {   
    
    // 그래프 초기화
    graph.V = 5;
    graph.graph = (int**)malloc(graph.V * sizeof(int*));
    for (int i = 0; i < graph.V; i++) {
        graph.graph[i] = (int*)malloc(graph.V * sizeof(int));
        for (int j = 0; j < graph.V; j++) {
            graph.graph[i][j] = 0;
        }
    }

    // 간선 정보 입력
    graph.graph[0][1] = 2;
    graph.graph[0][2] = 3;
    graph.graph[1][2] = 1;
    graph.graph[1][3] = 4;
    graph.graph[2][3] = 5;
    graph.graph[3][4] = 6;
    graph.graph[2][4] = 7;

    

    int choice;
    do {
        printf("0. 종료\n");
        printf("1. 정렬 알고리즘\n");
        printf("2. 그래픽 알고리즘\n");
        printf("메뉴를 선택하세요: ");
        scanf_s("%d", &choice);

        switch (choice) {
            case 0:
                printf("프로그램 종료\n");
                break;
            case 1:
                sortAlgorithmMenu();               
              
                break;
            case 2:
                graphicAlgorithmMenu();
                
                break;
            default:
                printf("잘못된 선택입니다. 다시 시도하세요.\n");
        }

    } while (choice != 0);

    return 0;
}


