#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_PATH 256

void writeFile(const char *filename, const char *content) {

    FILE *file = fopen(filename, "wb");

    if (file == NULL) {

        perror("deu ruim ao abrir o arquivo");
        exit(EXIT_FAILURE);

    }

    fwrite(content, sizeof(char), strlen(content), file);
    fclose(file);

}

int main() {

    const char *bftContent = "{\n    \"bootstrap\": {\n        \"enabled\": true\n    },\n    \"game\": {\n        \"divergenceModifier\": 0.5\n    }\n}";
    const char *cbfContent = "{\n    \"bootstrap\": {\n        \"enabled\": true\n    },\n    \"game\": {\n        \"available\": true\n    }\n}";
    const char *boatsContent = "{\n    \"bootstrap\": {\n        \"enabled\": true\n    },\n    \"main\": {\n        \"isFurnaceBoatOn\": false,\n        \"isTNTBoatOn\": true,\n        \"isJukeboxBoatOn\": false,\n        \"isHopperBoatOn\": false\n    }\n}";
    const char *PATH_APP_DATA = getenv("APPDATA");

    char PATH_MINECRAFT[MAX_SIZE_PATH];
    char PATH_ANDROMEDA[MAX_SIZE_PATH];
    char PATH_CBF[MAX_SIZE_PATH];
    char PATH_BFT[MAX_SIZE_PATH];
    char PATH_BOATS[MAX_SIZE_PATH];

    if (PATH_APP_DATA == NULL) {

        fprintf(stderr, "ocorreu um erro no caminho do APPDATA\n");
        return EXIT_FAILURE;

    }

    snprintf(PATH_MINECRAFT, sizeof(PATH_MINECRAFT), "%s\\.minecraft", PATH_APP_DATA);
    snprintf(PATH_ANDROMEDA, sizeof(PATH_ANDROMEDA), "%s\\config\\andromeda", PATH_MINECRAFT);
    snprintf(PATH_BFT, sizeof(PATH_BFT), "%s\\blocks\\better_fletching_table.json", PATH_ANDROMEDA);
    snprintf(PATH_CBF, sizeof(PATH_CBF), "%s\\blocks\\cactus_bottle_filling.json", PATH_ANDROMEDA);
    snprintf(PATH_BOATS, sizeof(PATH_BOATS), "%s\\entities\\boats.json", PATH_ANDROMEDA);

    writeFile(PATH_BFT, bftContent);
    writeFile(PATH_CBF, cbfContent);
    writeFile(PATH_BOATS, boatsContent);

    return EXIT_SUCCESS;

}
