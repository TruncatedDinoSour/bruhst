#!/usr/bin/env sh

set -ex

main() {
    cargo clean
    cargo b --release
    cp target/release/rs main
}

main "$@"
