#!/usr/bin/env sh

set -xe

main() {
    clang++ src/main.cc -Wpedantic -flto=full -Wl,--no-allow-shlib-undefined -fno-trapping-math -fstrict-aliasing -fno-math-errno -fno-stack-check -fno-strict-overflow -Wl,--gc-sections -fno-rtti -funroll-loops -Wl,--no-whole-archive -fno-stack-protector -fvisibility-inlines-hidden -mfancy-math-387 -Wl,--sort-section=alignment -fomit-frame-pointer -Wl,--strip-all -Wl,--strip-debug -fstrict-overflow -Wshadow -fuse-ld=lld -s -fno-exceptions -D_FORTIFY_SOURCE=0 -Wall -Wl,--no-as-needed -Wl,--discard-all -Wextra -fno-signed-zeros -fno-strict-aliasing -pedantic -O3 -fvisibility=hidden -ffast-math -funsafe-math-optimizations -Wl,--icf=all -std=c++98 -fno-asynchronous-unwind-tables -Werror -Wl,--build-id=none -fdiscard-value-names -femit-all-decls -fmerge-all-constants -fno-use-cxa-atexit -fno-use-init-array -march=native -mtune=native -o main
    llvm-strip --strip-debug --strip-sections --strip-unneeded -T --remove-section=.note.gnu.gold-version --remove-section=.note --strip-all --discard-locals --remove-section=.gnu.version --remove-section=.eh_frame --remove-section=.note.gnu.build-id --remove-section=.note.ABI-tag --strip-symbol=__gmon_start__ --strip-all-gnu --remove-section=.comment --remove-section=.eh_frame_ptr --discard-all main
}

main "$@"
