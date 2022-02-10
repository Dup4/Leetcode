#! /bin/bash

TOP_DIR="$(dirname "$(realpath "${BASH_SOURCE[0]}")")"

contest="${1}"

for dir in "${TOP_DIR}/../leetcode/${contest}"/*; do
    cd "${dir}" || echo "error. [dir=${dir}]"

    "${@:2}"

    echo "successfully done. [dir=${dir}]"
done
