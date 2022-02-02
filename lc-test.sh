#! /bin/bash

# shellcheck disable=SC2034
BASENAME="$(basename "${PWD}")"
TOP_DIR="$(dirname "$(realpath "${BASH_SOURCE[0]}")")"

UTILS_SH="${TOP_DIR}/utils.sh"
if [[ -f "${UTILS_SH}" ]]; then
    # shellcheck source=/dev/null
    source "${UTILS_SH}"
fi

filename="solution"
cpp_suffix="cpp"
cpp_out_suffix="cpp.out"

set -x
g++ -o "${filename}.${cpp_out_suffix}" "${filename}.${cpp_suffix}" -std=c++17 -O2 -W -Wall -DLOCAL -I"${TOP_DIR}/template"
set +x

if [[ -f "${filename}.${cpp_out_suffix}" ]]; then
    ./"${filename}.${cpp_out_suffix}"
    rm "${filename}.${cpp_out_suffix}"
fi
