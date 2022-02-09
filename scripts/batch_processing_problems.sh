#! /bin/bash

TOP_DIR="$(dirname "$(realpath "${BASH_SOURCE[0]}")")"

for dir in "${TOP_DIR}/../leetcode/problems"/*; do
    cd "${dir}" || echo "error. [dir=${dir}]"

    "${@:1}"

    echo "successfully done. [dir=${dir}]"
done
