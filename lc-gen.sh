#! /bin/bash

set -e

BASENAME="$(basename "${PWD}")"
TOP_DIR="$(dirname "$(realpath "${BASH_SOURCE[0]}")")"

UTILS_SH="${TOP_DIR}/utils.sh"
if [[ -f "${UTILS_SH}" ]]; then
    # shellcheck source=/dev/null
    source "${UTILS_SH}"
fi

template_name="template.cpp"

template_path="${TOP_DIR}"/template/"${template_name}"
template_suffix=$(echo "$template_path" | awk -F "." '{print $NF}')

function generate_template() {
    local current_template_path="${1}"

    cp "${template_path}" "${current_template_path}"
    INFO "Template created successfully. [path=${PWD}/${current_template_path}]"
}

if [[ -z "${1}" ]]; then
    generate_template "${PWD}/${BASENAME}.${template_suffix}"
    exit 0
fi

contest_id="${1}"
problem_num="4"

if [[ -n "${2}" ]]; then
    problem_num="${2}"
fi

if [[ ! -d "${contest_id}" ]]; then
    mkdir "${contest_id}"
else
    ERROR "The corresponding directory already exists. [path=${PWD}/${contest_id}]"
    exit 0
fi

cd "${contest_id}"

i=1
for c in {a..z}; do
    if [[ $i -gt $problem_num ]]; then
        break
    fi

    current_template_path="${c}/${c}.${template_suffix}"

    mkdir "${c}"

    generate_template "${current_template_path}"

    ((i++))
done
