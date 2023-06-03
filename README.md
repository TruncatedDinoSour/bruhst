# bruhst

```
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

>>> leaderboard <<<

1. c ( 0.32715678215026855 s to compile, 0 dependencies, 1.1410829305648803 runtime on average, syntax noise 0.17436770428015563 and bin file size of 6120 bytes )
2. cc ( 0.7837331295013428 s to compile, 0 dependencies, 1.2440528988838195 runtime on average, syntax noise 0.17442143727162 and bin file size of 7872 bytes )
3. rs ( 19.951916217803955 s to compile, 2 dependencies, 1.320226514339447 runtime on average, syntax noise 0.18710388536786993 and bin file size of 408792 bytes )
```

-   c for life
-   c++ > rust
-   rust < c++

# running bruhst urself

```sh
python3 bench.py
```

# what does it test

-   threading iteration sum ( threading, iteration, math )
-   file io ( buffering )
-   fib ( recursion and conditions )
-   sort ( iteration, conditions, memory )
-   n-body simulation ( math, structures, iteration )

# requirements

-   cargo
-   python3
-   clang ( both clang and clang++ )
-   lld
