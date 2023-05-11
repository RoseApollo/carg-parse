#!/bin/bash

# Number of iterations for the stress test
ITERATIONS=100

# Executable name
EXECUTABLE="./test"

# Log file name
LOG_FILE="stress.log"

# List of possible arguments
ARGUMENTS=(
  "-option1"
  "-option2"
  "-option3"
  "-option4"
  "-"
)

# Function to generate a random number within a range
generate_random_number() {
  local min=$1
  local max=$2
  echo $((RANDOM % (max - min + 1) + min))
}

# Function to generate a random argument combination
generate_random_arguments() {
  local arg_count=$(generate_random_number 1 ${#ARGUMENTS[@]})
  local args=()
  local used_indexes=()
  for (( i = 0; i < arg_count; i++ )); do
    local index
    while true; do
      index=$(generate_random_number 0 $((${#ARGUMENTS[@]} - 1)))
      if [[ ! " ${used_indexes[@]} " =~ " ${index} " ]]; then
        used_indexes+=($index)
        break
      fi
    done
    args+=("${ARGUMENTS[$index]}")
  done
  echo "${args[@]}"
}

# Clear the log file
> "$LOG_FILE"

# Main stress test loop
for (( i = 0; i < ITERATIONS; i++ )); do
  arguments=$(generate_random_arguments)
  echo "Running test iteration $((i+1)) with arguments: $arguments"
  # Add extra quotes to preserve trailing dashes
  $EXECUTABLE $arguments
  exit_code=$?
  if [[ $exit_code -eq 139 ]]; then
    echo "Segfault detected!"
    echo "Arguments: $arguments" >> "$LOG_FILE"
    exit 1  # Exit the script with an error
  fi
  echo "-----------------------------------------"
done
