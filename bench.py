#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""bench script"""

import os
import subprocess
import sys
import time
from dataclasses import dataclass
from glob import glob
from warnings import filterwarnings as filter_warnings

RUNTIME_N: int = 20


@dataclass
class Bench:
    name: str
    compile_time: float
    dependencies: int
    runtime: float
    syntax_noise: float
    file_size: int


def time_file(file: str) -> float:
    print("timing", file)

    start_time: float = time.time()
    subprocess.run((file,), stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    return time.time() - start_time


def num_file(file: str) -> float:
    print("getting number from", file)
    return float(subprocess.check_output((file,)).decode())


def main() -> int:
    """entry / main function"""

    dirs: tuple[str, ...] = tuple(
        d for d in os.listdir() if d[0] != "." and os.path.isdir(d)
    )

    if not dirs:
        print("no dirs", file=sys.stdout)
        return 1

    deps: list[Bench] = []

    for d in dirs:
        print("benching", d)

        os.chdir(d)

        with open(glob("./src/main.*")[0], "r") as f:
            total_nonal: int = sum((not (c.isspace() or c.isalnum())) for c in f.read())
            syntax_noise: float = total_nonal / f.tell()

        deps.append(
            Bench(
                d,
                time_file("./build.sh"),
                int(num_file("./deps.sh")) if os.path.isfile("./deps.sh") else 0,
                sum(time_file("./main") for _ in range(RUNTIME_N)) / RUNTIME_N,
                syntax_noise,
                os.path.getsize("main"),
            )
        )

        os.chdir("..")
        print()

    deps.sort(
        key=lambda b: b.compile_time + b.dependencies + b.runtime + b.syntax_noise
    )

    print(">>> leaderboard <<<\n")

    for idx, dp in enumerate(deps, 1):
        print(
            f"{idx}. {dp.name} ( {dp.compile_time} s to compile, {dp.dependencies} dependencies, {dp.runtime} runtime on average, "
            f"syntax noise {dp.syntax_noise} and bin file size of {dp.file_size} bytes )"
        )

    return 0


if __name__ == "__main__":
    assert main.__annotations__.get("return") is int, "main() should return an integer"

    filter_warnings("error", category=Warning)
    raise SystemExit(main())
