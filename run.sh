#!/bin/bash

filename="$1"
input_file="input.txt"
output_file="output.txt"

echo "Running script with file: $filename"
echo "Input file: $input_file"
echo "Output file: $output_file"

if [[ "$filename" == *.cpp ]]; then
    g++ -o "${filename%.*}" "$filename" && echo "Compilation successful" || { echo "Compilation failed"; exit 1; }
    echo "Running executable..."
    ./${filename%.*} <"$input_file" >"$output_file"
    echo "Execution finished."
elif [[ "$filename" == *.py ]]; then
    echo "Running Python script..."
    python3 "$filename" <"$input_file" >"$output_file"
    echo "Execution finished."
else
    echo "Unsupported file format"
fi
