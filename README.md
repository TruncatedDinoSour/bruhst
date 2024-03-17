# bruhst

```
benching c
timing ./build.sh
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main

benching cc
timing ./build.sh
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main

benching rs
timing ./build.sh
getting number from ./deps.sh
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main

>>> leaderboard <<<

1. c ( 0.2478773593902588 s to compile, 0 dependencies, 1.002959704399109 runtime on average, syntax noise 0.17436770428015563 and bin file size of 11328 bytes )
2. cc ( 0.44028162956237793 s to compile, 0 dependencies, 0.8922557950019836 runtime on average, syntax noise 0.17442143727162 and bin file size of 12616 bytes )
3. rs ( 10.378186225891113 s to compile, 2 dependencies, 0.925703251361847 runtime on average, syntax noise 0.18710388536786993 and bin file size of 5334400 bytes )
```

-   c for life overall ( weirdly enough c++ is faster than c in runtime )
-   c++ > rust in compile time, dependencies, runtime, syntax noise and size
-   rust loses like,,, fully

## runs

- 2023/06/04 ( older hw, 2 cores 4 threads, intel i3 8 th gen, 4 gig ram )
- 2023/09/02 ( new hw, 6 cores 12 threads, amd ryzen 5 7530u, 8 gig ram )

# running bruhst urself

```sh
python3 bench.py
```

# what does it test

-   threading iteration ( threading, iteration, math, cast )
-   file io ( buffering )
-   fib ( recursion and conditions )
-   sort ( iteration, conditions, memory )
-   n-body simulation ( math, structures, iteration )

# requirements

-   cargo
-   python3
-   clang ( both clang and clang++ )
-   lld
