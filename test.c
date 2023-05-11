// c argument parser (TESTER) - Rose (github.com/AUnicornWithNoLife)

#include <stdio.h>
#include "carg-parse.h"

int main(int argc, char** argv)
{
    carg_parse_data *data = carg_parse(argc, argv);

    printf("EXEC: %s\n", data->exec_name);

    printf("\nVALUES:\n");

    for (uint32_t i = 0; i < data->values_len; i++)
    {
        printf("%d ::: %s\n", i, data->values[i]);
    }

    printf("\nLABELED VALUES:\n");

    for (uint32_t i = 0; i < data->lv_len; i++)
    {
        if (data->lv_values[i] == NULL)
        {
            printf("%s ::: NULL\n", data->lv_labels[i]);
        }
        else
        {
            printf("%s ::: %s\n", data->lv_labels[i], data->lv_values[i]);
        }
    }

    carg_parse_free(data);

    return 0;
}
