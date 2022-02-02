#! /bin/bash

TOP_DIR="$(dirname "$(realpath "${BASH_SOURCE[0]}")")"
INSTALL_PATH="/usr/local/bin"

UTILS_SH="${TOP_DIR}/utils.sh"
# shellcheck source=/dev/null
source "${UTILS_SH}"

INSTALL_LIST_SH="${TOP_DIR}/install_list.sh"
# shellcheck source=/dev/null
source "${INSTALL_LIST_SH}"

# shellcheck disable=SC2154
for file in ${install_list}; do
    if [[ -f "${INSTALL_PATH}/${file}" ]]; then
        rm "${INSTALL_PATH}/${file}"
    fi

    ln -s "${TOP_DIR}/${file}.sh" "${INSTALL_PATH}/${file}"
    INFO "Install Successfully. [binary=${file}]"
done
