# carg-parse

Basic dependency free C library to easily parse arguments

# Usage

for a full example of usage look at test.c

Call
`carg_parse(int argc, char** argv)`
it will return `carg_parse_data*` containing:
```c
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
```

Values is an array of all of the free standing arguments passed in

LV is a dictionary, labels in lv_labels and values in lv_values, it contains any labeled arguments '-a b', if a value is not provided lv_value will point to NULL

values, lv_values and flags all point to argv, lv_labels points to argv + 1, as to ignore the dash ('-'), and flags does the same except + 2 as to ignore the double dash ('--')

when done with the data, call
`carg_parse_free(carg_parse_data* data)`
to free the data, it does not free the individual values and labels, as these just point to the values in argv, so if you have moved / modified these pointers, you will have to free them yourself. this has the benifit as well, of allowing you to free carg, even if you have values pointing to strings passed in.
