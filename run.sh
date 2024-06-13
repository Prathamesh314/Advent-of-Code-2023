#!/bin/bash

filename="$1"
input_file="input.txt"
output_file="output.txt"

if [[ "$filename" == *.cpp ]]; then
	g++ -o "${filename%.*}" "$filename" && ./${filename%.*} <"$input_file" >"$output_file"
elif [[ "$filename" == *.py ]]; then
	python3 "$filename" <"$input_file" >"$output_file"
else
	echo "Unsupported file format"
fi
