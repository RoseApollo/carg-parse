// c argument parser - Rose (github.com/AUnicornWithNoLife)

#ifndef CARG_PARSE
#define CARG_PARSE

#include <stdint.h>

typedef struct 
{
    char* exec_name;

    uint32_t values_len;
    char** values;

    uint32_t lv_len;
    char** lv_labels;
    char** lv_values;

	uint32_t flags_len;
	char** flags;
} carg_parse_data;

carg_parse_data* carg_parse(int argc, char** argv);
void carg_parse_free(carg_parse_data* data);

#endif
