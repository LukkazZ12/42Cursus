#!/bin/bash

subfolders=("ex00" "ex01" "ex02")

for folder in "${subfolders[@]}"; do
	(cd "$folder" && make fclean)
done