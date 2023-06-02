#!/usr/bin/env sh

set -e

main() {
    cargo tree --depth 1 | wc -l
}

main "$@"
