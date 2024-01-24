#!/bin/bash

subfolders=("ex00" "ex01" "ex02" "ex03")

for folder in "${subfolders[@]}"; do
	(cd "$folder" && make fclean)
done