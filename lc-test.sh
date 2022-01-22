#! /bin/bash

BASENAME="$(basename "${PWD}")"
TOP_DIR="$(dirname "$(realpath "${BASH_SOURCE[0]}")")"

UTILS_SH="${TOP_DIR}/utils.sh"
if [[ -f "${UTILS_SH}" ]]; then
    # shellcheck source=/dev/null
    source "${UTILS_SH}"
fi

filename="${BASENAME}"

set -x
g++ -o "${filename}.out" "main.cpp" -std=c++17 -O2 -W -Wall -DLOCAL -I"${TOP_DIR}" -I"${TOP_DIR}/template"
set +x

if [[ -f "${filename}.out" ]]; then
    ./"${filename}.out"
    rm "${filename}.out"
fi
