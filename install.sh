#! /bin/bash

TOP_DIR="$(dirname "$(realpath "${BASH_SOURCE[0]}")")"
INSTALL_PATH="/usr/local/bin"

UTILS_SH="${TOP_DIR}/utils.sh"
if [[ -f "${UTILS_SH}" ]]; then
    # shellcheck source=/dev/null
    source "${UTILS_SH}"
fi

file_list="
lc-gen \
lc-test \
"

for file in ${file_list}; do
    if [[ -f "${INSTALL_PATH}/${file}" ]]; then
        rm "${INSTALL_PATH}/${file}"
    fi

    ln -s "${TOP_DIR}/${file}.sh" "${INSTALL_PATH}/${file}"
    INFO "Install Successfully. [binary=${file}]"
done
