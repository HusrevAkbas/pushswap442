#!/bin/bash

# Check if correct number of arguments are provided
if [ "$#" -ne 2 ]; then
		echo "Usage: $0 <file> <max_operations>"
		exit 1
fi

#PATH_CHECKER="../push_swap_v1/checker"
PATH_CHECKER="./checker_linux"
PATH_PUSH_SWAP="../push_swap"
FILE="$1"                     # Filename from command line argument
MAX_OPERATIONS="$2"           # Maximum operations from command line argument

RED='\033[0;31m'
NC='\033[0m'

# Check if the paths exist
if [ ! -f "$PATH_CHECKER" ]; then
		echo "File $PATH_CHECKER not found!"
		exit 1
fi

if [ ! -f "$PATH_PUSH_SWAP" ]; then
		echo "File $PATH_PUSH_SWAP not found!"
		exit 1
fi

# Check if the input file exists
if [ ! -f "$FILE" ]; then
		echo "File $FILE not found!"
		exit 1
fi

# Number of lines in the file
total_lines=$(wc -l < "$FILE")

# Initialize variables to calculate the total operations
max_ops=0
min_ops=0
total_operations=0
line_count=0

# Loop through each line in the file
for (( i=1; i<=total_lines; i++ )); do
	# Capture the output line count from push_swap
	ARG=$(sed -n "${i}p" "$FILE")
	line_output=$("$PATH_PUSH_SWAP" $ARG | wc -l)
	result_checker=$("$PATH_PUSH_SWAP" $ARG | $PATH_CHECKER $ARG)

	# Accumulate the total operations
	total_operations=$((total_operations + line_output))
	line_count=$((line_count + 1))

	if [ "$line_output" -gt "$MAX_OPERATIONS" ] || [ "$result_checker" = "KO" ]; then
			echo -e "${RED}Line $i: checker=$result_checker, $line_output operations${NC}"
	else
			echo -e "Line $i: checker=$result_checker, $line_output operations"
	fi

	if [ "$line_output" -gt "$max_ops" ]; then
			max_ops="$line_output"
	fi

	if [ "$line_output" -lt "$min_ops" ] || [ "$i" = "1" ]; then
			min_ops="$line_output"
	fi
done

# Calculate and display informations
echo -e "\nUsed checker: '$PATH_CHECKER'"
if [ "$line_count" -gt 0 ]; then
		average_operations=$(echo "scale=2; $total_operations / $line_count" | bc)
		echo -e "Average operations: $average_operations"
else
		echo "No lines processed."
fi

echo -e "Min operations: $min_ops"
echo -e "Max operations: $max_ops"
