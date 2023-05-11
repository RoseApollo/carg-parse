// c argument parser - Rose (github.com/AUnicornWithNoLife)

#include "carg-parse.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

carg_parse_data* carg_parse(int argc, char** argv)
{
    carg_parse_data *data = (carg_parse_data*)malloc(sizeof(carg_parse_data));

    char **values = (char**)malloc(sizeof(char*) * argc);
    uint32_t values_cp = 0;

    char **lv_labels = (char**)malloc(sizeof(char*) * argc);
    char **lv_values = (char**)malloc(sizeof(char*) * argc);
    uint32_t lv_cp = 0;

    data->exec_name = argv[0];

    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-') // label
        {
            lv_labels[lv_cp] = argv[i] + 1;

            if (argc >= i + 1 && argv[i + 1][0] != '-')
            {
                i++;

                lv_values[lv_cp] = argv[i];
            }
            else
            {
                lv_values[lv_cp] = NULL;
            }

            lv_cp++;
        }
        else // not labelled
        {
            values[values_cp] = argv[i];

            values_cp++;
        }
    }

    data->values_len = values_cp;
    if (values_cp > 0)
    {
        data->values = realloc(values, sizeof(char*) * values_cp);
    }
    else
    {
        data->values = NULL;
    }

    data->lv_len = lv_cp;
    if (lv_cp > 0)
    {
        data->lv_labels = realloc(lv_labels, sizeof(char*) * lv_cp);
        data->lv_values = realloc(lv_values, sizeof(char*) * lv_cp);
    }
    else
    {
        data->lv_labels = NULL;
        data->lv_values = NULL;
    }

    return data;
}

void carg_parse_free(carg_parse_data* data)
{
    if (data->values != NULL)
    {
        free(data->values);
    }
    
    if (data->lv_labels != NULL)
    {
        free(data->lv_labels);
    }
    if (data->lv_values != NULL)
    {
        free(data->lv_values);
    }

    free(data);
}