# carg-parse

Basic C library to easily parse arguments

# Usage

for a full example of usage look at test.c

Call
`carg_parse(int argc, char** argv)`
it will return a struct containing:
```
typedef struct 
{
    char* exec_name;

    uint32_t values_len;
    char** values;

    uint32_t lv_len;
    char** lv_labels;
    char** lv_values;
} carg_parse_data;
```

Values is an array of all of the free standing arguments passed in

LV is a dictionary, labels in lv_labels and values in lv_values, it contains any labeled arguments '-a b', if a value is not provided lv_value will point to NULL

values and lv_values both point to argv, and lv_labels points to argv + 1, as to ignore the dash('-')

when done with the data, call
`carg_parse_free(data)`
to free the data
