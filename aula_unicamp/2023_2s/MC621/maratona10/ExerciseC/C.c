#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int N, M;
    // N: number of words in the dictionary
    // M: number of plates
    scanf("%d %d", &N, &M);
    char dict[N][100]; // Assumindo que o tamanho máximo da palavra seja 30 caracteres

    for (int i = 0; i < N; i++) {
        scanf("%s", dict[i]);
    }

    int aux1 = 0, aux2 = 0, aux3 = 0;
    char plate[3]; // Assumindo que o tamanho máximo da placa seja 30 caracteres

    for (int i = 0; i < M; i++) {
        scanf("%s", plate);
        for (int j = 0; plate[j] != '\0'; j++) {
            plate[j] = tolower(plate[j]);
        }

        for (int j = 0; j < N; j++) {
            aux1 = aux2 = aux3 = 0;
            for (int k = 0; dict[j][k] != '\0'; k++) {
                if (aux2 && plate[2] == dict[j][k]) {
                    aux3 = 1;
                    break;
                } else if (aux1 && plate[1] == dict[j][k]) {
                    aux2 = 1;
                } else if (plate[0] == dict[j][k]) {
                    aux1 = 1;
                }
            }
            if (aux3) {
                printf("%s\n", dict[j]);
                break;
            }
        }

        if (!aux3) {
            printf("No valid word\n");
        }
    }

    return 0;
}
